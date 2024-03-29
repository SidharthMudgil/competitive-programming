## Data Structures
A data structure is a specialized format for organizing, processing, retrieving and storing data. There are several basic and advanced types of data structures, all designed to arrange data to suit a specific purpose. Data structures make it easy for users to access and work with the data they need in appropriate ways. Most importantly, data structures frame the organization of information so that machines and humans can better understand it.

In computer science and computer programming, a data structure may be selected or designed to store data for the purpose of using it with various algorithms. In some cases, the algorithm's basic operations are tightly coupled to the data structure's design. Each data structure contains information about the data values, relationships between the data and -- in some cases -- functions that can be applied to the data.

- [Array](#array)
- [Linked List](#linked-list)
- [Stack](#stack)
- [Queue](#queue)
- [Tree](#tree)
- [Graph](#graph)

### Array
An array stores a collection of items at adjoining memory locations. Items that are the same type are stored together so the position of each element can be calculated or retrieved easily by an index. Arrays can be fixed or flexible in length. An array can hold a collection of integers, floating-point numbers, stings or even other arrays.

##### Basic Operations:
- **Insertion -** Adds an element at the given index.
- **Deletion -** Removes an element at the given index.
- **Update -** Updates an element at the given index.
- **Search -** Searches an element using the value.
- **Traverse -** Print all the elements.

##### Type:
- **1D Array -** Store a single list of the element of a similar data type.
- **2D Array -** Store a ‘list of lists’ of the element of a similar data type.

##### Implementation:
- [1D Array](./array/array.cpp)
- [2D Array](./array/array2d.cpp)

### Linked List
A linked list stores a collection of items in a linear order. Each element, or node, in a linked list contains a data item, as well as a reference, or link, to the next item in the list. Linked list data structures are a set of nodes that contain data and the address or a pointer to the next node.

##### Basic Operations:
- Insertion
    - **Insert After -** Adds an element after an item of the list.
    - **Insert Start -** Adds an element at the beginning of the list.
    - **Insert End -** Adds an element at the end of the list.
- Deletion
    - **Delete Node -** Removes an element from the list using key.
    - **Delete Start -** Removes an element from the start of the list.
    - **Delete End -** Removes an element from the end of the list.
- **Searching -** Searches an element in the list using key.
- **Traversal -** Prints all the elements of the list.

##### Type:
- **Singly Linked List -** Linked List in which each node contains a key and a pointer to the next node of same data type. It allows traversal in only one way. 
- **Doubly Linked List -** Linked List in which each node contains a key and a pointer to the next node as well as a pointer to the previous node both of same data types. It allows traversal in two ways.
- **Circular Linked List -** Singly Linked List in which the last node contains a pointer to the first node i.e. head.
- **Circular Doubly Linked List -** Doubly linked list in which the first node contains a pointer to the last node and the last node contains a pointer to the first node.

##### Implementation:
- Singly Linked List
    - [Insertion](./linked-list/singly-linked-list/insertion.cpp)
    - [Deletion](./linked-list/singly-linked-list/deletion.cpp)
    - [Searching](./linked-list/singly-linked-list/searching.cpp)
    - [Traversal](./linked-list/singly-linked-list/traversal.cpp)
- Doubly Linked List
    - [Insertion](./linked-list/doubly-linked-list/insertion.cpp)
    - [Deletion](./linked-list/doubly-linked-list/deletion.cpp)
    - [Searching](./linked-list/doubly-linked-list/searching.cpp)
    - [Traversal](./linked-list/doubly-linked-list/traversal.cpp)
- Circular Linked List
    - [Insertion](./linked-list/circular-linked-list/insertion.cpp)
    - [Deletion](./linked-list/circular-linked-list/deletion.cpp)
    - [Searching](./linked-list/circular-linked-list/searching.cpp)
    - [Traversal](./linked-list/circular-linked-list/traversal.cpp)
- Circular Doubly Linked List
    - [Insertion](./linked-list/circular-doubly-linked-list/insertion.cpp)
    - [Deletion](./linked-list/circular-doubly-linked-list/deletion.cpp)
    - [Searching](./linked-list/circular-doubly-linked-list/searching.cpp)
    - [Traversal](./linked-list/circular-doubly-linked-list/traversal.cpp)


### Stack
A stack is a linear data structure that follows the principle of Last In First Out (LIFO). This means the last element inserted inside the stack is removed first. You can think of the stack data structure as the pile of plates on top of another.
##### Basic Operations:
- **push -** Adds an iteme in the stack.
- **pop -** Removes an item from the stack.
- **peek -** Gets the item at the top of the stack without removing it.
##### Implementation:
- [Using array](./stack/stack-using-array.cpp)
- [Using linked list](./stack/stack-using-linked-list.cpp)

### Queue
A Queue is a linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO). A good example of a queue is any queue of consumers for a resource where the consumer that came first is served first.

##### Basic Operations:
- **enqueue -** Adds an iteme in the queue.
- **dequeue -** Removes an item from the queue.
- **peek -** Gets the item at the front of the queue without removing it.

##### Type:
- **Linear Queue -** Operations are performed based on FIFO principle.
- **Circular Queue -** Linear Queue in which the last position is connected to the first position to make a circle.
- **Deque -** Operations can be performed from either ends of the queue.
- **Priority Queue -** Queue where each item has a priority and the item with highest priority will always be retrieved first.

##### Implementation:
- Using Array
    - [Linear Queue](./queue/linear-queue/queue-using-array.cpp)
    - [Circular Queue](./queue/circular-queue/cq-using-array.cpp)
    - [Deque](./queue/deque/deque-using-array.cpp)
    - [Priority Queue](./queue/priority-queue/pq-using-array.cpp)
- Using Linked List
    - [Linear Queue](./queue/linear-queue/queue-using-linked-list.cpp) 
    - [Circular Queue](./queue/circular-queue/cq-using-linked-list.cpp)
    - [Deque](./queue/deque/deque-using-linked-list.cpp)
    - [Priority Queue](./queue/priority-queue/pq-using-linked-list.cpp)

### Tree
A tree is non-linear and a hierarchical data structure consisting of a collection of nodes such that each node of the tree stores a value and a list of references to other nodes (the “children”). This data structure is a specialized method to organize and store data in the computer to be used more effectively.

##### Basic Operations:
- **Insertion -** Adds a node in the tree.
- **Deletion -** Removes a node from the tree using key.
- **Searching -** Searches a node in the tree using key.
- **Traversal -** Prints all the keys present in the tree.

##### Type:
- **Binary Tree -** Tree in which a node can have maximum of 2 childs.
- **Binary Search Tree -** Binary tree in which the left child value of a node should be less than or equal to the parent value, and the right child value should always be greater than or equal to the parent's value.
- **AVL Tree -** It is a self balancing binary search tree, In which the correct balance factor are -1, 0 and 1.
- **BTree -** A specialized m-way tree in which a node can have at most m-1 keys and m children.

##### Implementation:
- Binary Tree
    - [Using array](./tree/binary/binary-tree-using-array.cpp)
    - [Using linked list](./tree/binary/binary-tree-using-linked-list.cpp)
- Binary Search Tree
    - [Using array](./tree/bst/bstree-using-array.cpp)
    - [Using linked list](./tree/bst/bstree-using-linked-list.cpp)
- [AVL Tree](./tree/avl/avl-tree.cpp)
- [BTree](./tree/btree/btree.cpp)


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
- [Using adjacency matrix](./graph/graph-using-adjacency-matrix.cpp)
- [Using adjacency list](./graph/graph-using-adjacency-list.cpp)
