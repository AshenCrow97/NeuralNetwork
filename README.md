# Neural Network from Scratch in C++

This is a school homework project implementing a feedforward neural network from scratch in C++, designed to work specifically with the [Fashion MNIST](https://github.com/zalandoresearch/fashion-mnist) dataset. No external libraries (such as TensorFlow, PyTorch, or Eigen) were used. All matrix operations, activation functions, forward and backward propagation, and optimization algorithms (including Adam) are implemented manually.

---

## Features

* Fully connected feedforward neural network
* ReLU, Leaky ReLU, and Softmax activation functions
* Softmax + Cross-Entropy loss
* Adam optimizer
* Accuracy evaluation
* Support for CSV input and output
* One-hot encoding and data normalization

---

## Dataset

This project is designed for the Fashion MNIST dataset, which consists of 28x28 grayscale images (flattened to 784 features) across 10 fashion categories.

---

## Accuracy

This network reaches **85% accuracy** on the Fashion MNIST test set after training.

---

## Notes

* This project is for educational purposes only.
* It focuses on building intuition and understanding of how neural networks operate under the hood.
* Not optimized for performance or scalability.

---
