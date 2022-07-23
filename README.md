# Competitive Programming
_🤔🤔_
## Table of Contents
- [Data Structures](#data-structures)
    - [Array](#array)
    - [Linked List](#linked-list)
    - [Stack](#stack)
    - [Queue](#queue)
    - [Tree](#tree)
    - [Graph](#graph)
- [Algorithms](#algorithms)
    - [Fast Exponentiation Method](#fast-exponentiation-method)
    - [2k-ary Method](#2k-ary-method)
    - [Euclidean GCD](#euclidean-gcd)

## Data Structures
A data structure is a specialized format for organizing, processing, retrieving and storing data. There are several basic and advanced types of data structures, all designed to arrange data to suit a specific purpose. Data structures make it easy for users to access and work with the data they need in appropriate ways. Most importantly, data structures frame the organization of information so that machines and humans can better understand it.

In computer science and computer programming, a data structure may be selected or designed to store data for the purpose of using it with various algorithms. In some cases, the algorithm's basic operations are tightly coupled to the data structure's design. Each data structure contains information about the data values, relationships between the data and -- in some cases -- functions that can be applied to the data.

### Array
An array stores a collection of items at adjoining memory locations. Items that are the same type are stored together so the position of each element can be calculated or retrieved easily by an index. Arrays can be fixed or flexible in length. An array can hold a collection of integers, floating-point numbers, stings or even other arrays.

##### Basic Operations:
- **Insertion -** Adds an element at the given index.
- **Deletion -** Removes an element at the given index.
- **Update -** Updates an element at the given index.
- **Search -** Searches an element using the value.
- **Traverse -** Print all the elements.

##### Type:
- [**1D Array**](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/array/array.cpp) **-** Store a single list of the element of a similar data type.
- [**2D Array**](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/array/array2d.cpp) **-** Store a ‘list of lists’ of the element of a similar data type.

### Linked List
A linked list stores a collection of items in a linear order. Each element, or node, in a linked list contains a data item, as well as a reference, or link, to the next item in the list. Linked list data structures are a set of nodes that contain data and the address or a pointer to the next node.

##### Basic Operations:
- Insertion:
    - **Insert After -** Adds an element after an item of the list.
    - **Insert Start** Adds an element at the beginning of the list.
    - **Insert End-** Adds an element at the end of the list.
- Deletion:
    - **Delete Node -** Removes an element from the list using key.
    - **Delete Start -** Removes an element from the start of the list.
    - **Delete End -** Removes an element from the end of the list.
- **Searching -** Searches an element in the list using key.
- **Traversal -** Prints all the elements of the list.

##### Type:
- **Singly Linked List -** Linked List in which each node contains a key and a pointer to the next node of same data type. It allows traversal in only one way. 
    - [Insertion](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/singly%20linked%20list/insertion.cpp)
    - [Deletion](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/singly%20linked%20list/deletion.cpp)
    - [Searching](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/singly%20linked%20list/searching.cpp)
    - [Traversal](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/singly%20linked%20list/traversal.cpp)
- **Doubly Linked List -** Linked List in which each node contains a key and a pointer to the next node as well as a pointer to the previous node both of same data types. It allows traversal in two ways. 
    - [Insertion](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/doubly%20linked%20list/insertion.cpp)
    - [Deletion](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/doubly%20linked%20list/deletion.cpp)
    - [Searching](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/doubly%20linked%20list/searching.cpp)
    - [Traversal](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/doubly%20linked%20list/traversal.cpp)
- **Circular Linked List -** Singly Linked List in which the last node contains a pointer to the first node i.e. head.
    - [Insertion](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/circular%20linked%20list/insertion.cpp)
    - [Deletion](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/circular%20linked%20list/deletion.cpp)
    - [Searching](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/circular%20linked%20list/searching.cpp)
    - [Traversal](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/circular%20linked%20list/traversal.cpp)
- **Circular Doubly Linked List -** Doubly linked list in which the first node contains a pointer to the last node and the last node contains a pointer to the first node.
    - [Insertion](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/circular%20doubly%20linked%20list/insertion.cpp)
    - [Deletion](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/circular%20doubly%20linked%20list/deletion.cpp)
    - [Searching](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/circular%20doubly%20linked%20list/searching.cpp)
    - [Traversal](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/linked%20list/circular%20doubly%20linked%20list/traversal.cpp)

### Stack
A stack is a linear data structure that follows the principle of Last In First Out (LIFO). This means the last element inserted inside the stack is removed first. You can think of the stack data structure as the pile of plates on top of another.
##### Basic Operations:
- **push -** Adds an iteme in the stack.
- **pop -** Removes an item from the stack.
- **peek -** Gets the item at the top of the stack without removing it.
##### Implementation:
- [Implementation using Array](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/stack/stack-using-array.cpp)
- [Implementation using Linked List](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/stack/stack-using-linked-list.cpp)

### Queue
A Queue is a linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO). A good example of a queue is any queue of consumers for a resource where the consumer that came first is served first.
##### Basic Operations:
- **enqueue -** Adds an iteme in the queue.
- **dequeue -** Removes an item from the queue.
- **peek -** Gets the item at the front of the queue without removing it.
##### Type:
- **Linear Queue -** Operations are performed based on FIFO principle.
    - [Implementation using Array](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/queue/linear%20queue/queue-using-array.cpp)
    - [Implementation using Linked List](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/queue/linear%20queue/queue-using-linked-list.cpp)
- **Circular Queue -** Linear Queue in which the last position is connected to the first position to make a circle.
    - [Implementation using Array](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/queue/circular%20queue/cq-using-array.cpp)
    - [Implementation using Linked List](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/queue/circular%20queue/cq-using-linked-list.cpp)
- **Deque -** Operations can be performed from either ends of the queue.
    - [Implementation using Array](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/queue/deque/deque-using-array.cpp)
    - [Implementation using Linked List](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/queue/deque/deque-using-linked-list.cpp)
- **Priority Queue -** Queue where each item has a priority and the item with highest priority will always be retrieved first.
    - [Implementation using Array](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/queue/priority%20queue/pq-using-array.cpp)
    - [Implementation using Linked List](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/queue/priority%20queue/pq-using-linked-list.cpp)

### Tree
A tree is non-linear and a hierarchical data structure consisting of a collection of nodes such that each node of the tree stores a value and a list of references to other nodes (the “children”). This data structure is a specialized method to organize and store data in the computer to be used more effectively.
##### Basic Operations:
- **Insertion -** Adds a node in the tree.
- **Deletion -** Removes a node from the tree using key.
- **Searching -** Searches a node in the tree using key.
- **Traversal -** Prints all the keys present in the tree.
##### Type:
- **Binary Tree -** Tree in which a node can have maximum of 2 childs.
    - [Implementation using Array](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/tree/binary%20tree/binary-tree-using-array.cpp)
    - [Implementation using Linked List](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/tree/binary%20tree/binary-tree-using-linked-list.cpp)
- **Binary Search Tree -** Binary tree in which the left child value of a node should be less than or equal to the parent value, and the right child value should always be greater than or equal to the parent's value.
    - [Implementation using Array](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/tree/binary%20search%20tree/bstree-using-array.cpp)
    - [List Implementation using Linked List](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/tree/binary%20search%20tree/bstree-using-linked-list.cpp)
- [**AVL Tree**](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/tree/avl%20tree/avl-tree.cpp) **-** It is a self balancing binary search tree, In which the correct balance factor are -1, 0 and 1.
- [**BTree**](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/tree/btree/btree.cpp) **-** A specialized m-way tree in which a node can have at most m-1 keys and m children.

### Graph
A Graph is a non-linear data structure consisting of nodes and edges. The nodes are sometimes also referred to as vertices and the edges are lines or arcs that connect any two nodes in the graph. A Graph consists of a finite set of vertices(or nodes) and set of Edges which connect a pair of nodes.

##### Basic Operations:
- **Add Edge −** Adds an edge between 2 vertices.
- **Traverse −** Prints all the vertices and edges of the graph.

##### Type:
- **Undirected Graph -** Graph in which edges are not associated with any directions, It is bi-directional.
- **Directed Graph -** Graph in which edges represents are associated with a direction, It is uni-directional.
- **Weighted Graph -** Graph in which each edges have some weight.

##### Implementation:
- [Implementation using Adjacency Matrix](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/graph/graph-using-adjacency-matrix.cpp)
- [Implementation using Adjacency List](https://github.com/SidharthMudgil/competitive-programming/blob/main/data%20structure/graph/graph-using-adjacency-list.cpp)


## Algorithms
coming soon...
