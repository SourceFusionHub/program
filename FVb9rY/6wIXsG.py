import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
from tensorflow.keras.applications import VGG19
from tensorflow.keras.preprocessing import image
from tensorflow.keras.applications.vgg19 import preprocess_input, decode_predictions
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Concatenate
from scipy.optimize import minimize

content_image_path = 'content.jpg'
style_image_path = 'style.jpg'

def load_and_preprocess_image(image_path):
    img = image.load_img(image_path, target_size=(224, 224))
    img = image.img_to_array(img)
    img = np.expand_dims(img, axis=0)
    img = preprocess_input(img)
    return img

content_image = load_and_preprocess_image(content_image_path)
style_image = load_and_preprocess_image(style_image_path)

def get_content_loss(base_content, target):
    return tf.reduce_mean(tf.square(base_content - target))

def get_style_loss(base_style, gram_target):
    return tf.reduce_mean(tf.square(gram_matrix(base_style) - gram_target))

def gram_matrix(input_tensor):
    result = tf.linalg.einsum('bijc,bijd->bcd', input_tensor, input_tensor)
    input_shape = tf.shape(input_tensor)
    num_locations = tf.cast(input_shape[1]*input_shape[2], tf.float32)
    return result / (num_locations)

base_model = VGG19(include_top=False, weights='imagenet')
base_model.trainable = False

content_layers = ['block5_conv2']
style_layers = ['block1_conv1', 'block2_conv1', 'block3_conv1', 'block4_conv1', 'block5_conv1']
num_content_layers = len(content_layers)
num_style_layers = len(style_layers)

style_extractor = [base_model.get_layer(layer).output for layer in style_layers]
content_extractor = [base_model.get_layer(layer).output for layer in content_layers]

model = Model(inputs=base_model.input, outputs=style_extractor + content_extractor)

style_features = model(style_image)
content_features = model(content_image)

style_target = [gram_matrix(feature) for feature in style_features[:num_style_layers]]
content_target = content_features[num_style_layers:]

generated_image = tf.Variable(content_image)

alpha = 1e4
beta = 1e-2
total_variation_weight = 30

optimizer = tf.optimizers.Adam(learning_rate=2.0)

def total_loss(generated_image):
    style_gen, content_gen = model(generated_image)
    
    style_loss = 0
    content_loss = 0
    
    for i in range(num_style_layers):
        style_loss += get_style_loss(style_gen[i], style_target[i])
    
    for i in range(num_content_layers):
        content_loss += get_content_loss(content_gen[i], content_target[i])
    
    style_loss *= beta / num_style_layers
    content_loss *= alpha / num_content_layers
    
    total_variation_loss = tf.image.total_variation(generated_image)
    
    return style_loss + content_loss + total_variation_weight * total_variation_loss

@tf.function()
def train_step(image):
    with tf.GradientTape() as tape:
        loss = total_loss(image)
    gradient = tape.gradient(loss, image)
    optimizer.apply_gradients([(gradient, image)])
    image.assign(tf.clip_by_value(image, clip_value_min=0.0, clip_value_max=255.0))

num_iterations = 1000
for i in range(num_iterations):
    train_step(generated_image)
    if i % 100 == 0:
        print(f"Iteration {i+1}/{num_iterations}, Loss: {total_loss(generated_image)}")

result_image = generated_image[0]

plt.imshow(result_image)
plt.axis('off')
plt.show()

result_image = tf.image.convert_image_dtype(result_image, tf.uint8)
image.save_img('output.jpg', result_image)
