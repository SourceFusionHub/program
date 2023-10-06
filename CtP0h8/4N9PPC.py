import numpy as np
import cv2

def deblur_image(image, kernel, noise_variance):
    image_fft = np.fft.fft2(image)
    kernel_fft = np.fft.fft2(kernel, s=image.shape)

    wiener_filter = np.conj(kernel_fft) / (np.abs(kernel_fft) ** 2 + noise_variance)
    restored_image_fft = image_fft * wiener_filter
    restored_image = np.fft.ifft2(restored_image_fft).real

    return np.uint8(np.clip(restored_image, 0, 255))

if __name__ == "__main__":
    blurred_image = cv2.imread("blurred_image.png", cv2.IMREAD_GRAYSCALE)
    kernel = np.array([[0.04, 0.12, 0.04],
                       [0.12, 0.36, 0.12],
                       [0.04, 0.12, 0.04]])

    noise_variance = 1.0
    noisy_image = blurred_image + np.random.normal(0, noise_variance, blurred_image.shape).astype(np.uint8)

    deblurred_image = deblur_image(noisy_image, kernel, noise_variance)

    cv2.imshow("Original Image", blurred_image)
    cv2.imshow("Noisy Image", noisy_image)
    cv2.imshow("Deblurred Image", deblurred_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
