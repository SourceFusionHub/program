import numpy as np
import tensorflow as tf
from tensorflow import keras

# Simulated user-item interaction data (state)
# In a real system, this would come from user behavior data.
user_state = np.array([0.2, 0.4, 0.6, 0.8])  # User's current state
item_embeddings = np.random.rand(10, 4)      # Embeddings for 10 items

# Define a simple neural network for the recommendation model
model = keras.Sequential([
    keras.layers.Dense(16, activation='relu', input_shape=(4,)),
    keras.layers.Dense(16, activation='relu'),
    keras.layers.Dense(10, activation='softmax')  # 10 items, softmax for probability distribution
])

# Compile the model
model.compile(optimizer='adam', loss='categorical_crossentropy')

# Define the RL agent's exploration policy (e.g., epsilon-greedy)
def epsilon_greedy_policy(q_values, epsilon=0.1):
    if np.random.rand() < epsilon:
        return np.random.randint(len(q_values))  # Random action
    else:
        return np.argmax(q_values)  # Greedy action

# Simulate RL training
num_episodes = 1000
epsilon = 0.1
gamma = 0.9

for episode in range(num_episodes):
    user_action = epsilon_greedy_policy(model.predict(user_state.reshape(1, -1)), epsilon)
    reward = user_state.dot(item_embeddings[user_action])  # Simulated reward based on dot product
    next_user_state = np.random.rand(4)  # Simulated next user state
    
    target = reward + gamma * np.max(model.predict(next_user_state.reshape(1, -1)))
    target_f = model.predict(user_state.reshape(1, -1))
    target_f[0][user_action] = target
    
    model.fit(user_state.reshape(1, -1), target_f, epochs=1, verbose=0)

    user_state = next_user_state

# Real-time recommendation
def recommend(user_state):
    q_values = model.predict(user_state.reshape(1, -1))
    recommended_item = np.argmax(q_values)
    return recommended_item

# Example: Get a recommendation for a user's current state
user_state = np.array([0.8, 0.6, 0.4, 0.2])
recommended_item = recommend(user_state)
print(f"Recommended item: {recommended_item}")
