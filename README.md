# Data-Structures
All Interesting Stuff Here!

## QuickSort

This is a simple C program implementing quicksort using iterative approach. We are simply sorting integers stored in an array. Detailed comments are added with the code to give most clarity to the algorithm.

## GoodNode

#### 1448. Count Good Nodes in Binary Tree - LeetCode Problem

*Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.*

![Tree](https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png)

**Input**: root = [3,1,4,3,null,1,5]
**Output**: 4
**Explanation**: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
