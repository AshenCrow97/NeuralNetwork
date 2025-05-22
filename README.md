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

### File Requirements

You should convert the Fashion MNIST dataset into CSV format:

* `train.csv`: Training data (each row: label + 784 pixel values)
* `test.csv`: Test data (same format as training data)
* `test_labels.txt`: Test labels (one label per line)

---

## Accuracy

This network reaches **85% accuracy** on the Fashion MNIST test set after training.

---

## File Overview

* `main.cpp`: Entry point, loads data, trains and evaluates the network
* `matrix.hpp` / `matrix.cpp`: Matrix and vector operations (e.g., matMul, vecAddElem)
* `layer.hpp` / `layer.cpp`: Neural network layer implementation
* `network.hpp`: Full network implementation with forward, backward, and training loop
* `parse.hpp` / `parse.cpp`: CSV reading, one-hot encoding, and normalization
* `test_*.cpp`: Unit tests for all modules

---

## Notes

* This project is for educational purposes only.
* It focuses on building intuition and understanding of how neural networks operate under the hood.
* Not optimized for performance or scalability.

---
