# Mining Profit Maximization Algorithm

This C program aims to optimize a miner's earnings by choosing the excavation area with the maximum profit. It employs both brute-force and divide-and-conquer algorithms to find the solution.

## Overview

The miner wants to maximize their earnings while excavating blocks in a 1-dimensional plane. Each block has an associated profit value, which can be positive or negative. The goal is to find the optimal sequence of blocks to excavate that results in the highest profit.

## Maximum Gain

The program uses a global variable `gMax` to keep track of the maximum gain achieved during the calculations. This variable is updated as the algorithms progress and is used to determine the highest profit.

## Algorithms

1. **Divide-and-Conquer Algorithm**: This algorithm efficiently finds the maximum profit by dividing the problem into smaller subproblems. It identifies the optimal sequence of blocks within a given range.

2. **Brute-Force Algorithm**: The brute-force approach exhaustively computes the profit for all possible sequences of blocks within the range. It provides a baseline comparison for the efficiency of the divide-and-conquer algorithm.

## Usage

Compile and run the program, providing the number of elements and the profit values for each block as input. The program will output the largest gain and the corresponding sequence of blocks for both algorithms.

## Functions

- `maxSubarraySum`: Recursive function implementing the divide-and-conquer algorithm.
- `findMaxC`: Finds the maximum sum of subarrays that cross the median and contain both left and right elements.
- `maxOfThree`: Finds the maximum of three numbers.
- `bruteForce`: Implements the brute-force approach to find the maximum profit.

## Results

The program will display the largest gain (`gMax`) and the sequence of blocks that result in the maximum profit for both the divide-and-conquer and brute-force algorithms.

Feel free to experiment with different inputs to test the algorithms' performance.

## Credits

This project was developed as part of the "Design and Analysis of Algorithms" course.
