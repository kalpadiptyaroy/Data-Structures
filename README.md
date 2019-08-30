# Data-Structures
All Interesting Stuff Here!

Here, we mainly have two important things. 
1. The Binary Search Tree, which I have implemented using java. And it has a corresponding Node class defines a node completely.
2. DetectCircullar.c is a C program that detects whether the last node is accidentally pointing to any particular node of the same given list.
    Now, for detecting this circullar anomaly, I have used the concept of no. of nodes traversed to identify the circullar linked node.
    But, some other possible ways are: we can keep a variable length, that keeps record of no. of insertions, so that we can detect the anomally by
    using the idea that no. of traversals can never be greater than no. of insertions.
    Another, way is to point the last node by an external pointer. Say 'end' 
