# 2023 Answer sheet

## Semaphore
- A semaphore is a program used to implement process synchroniation like mutual exclusion to prevent situations like race condition.
- It is initialized with a intial value which denotes no of process can access critical section at a time.
- It provides two operations:
  - wait: When a process enters a critical section it decrements semaphore value.
  - signal: When a provcess leaves critical section it increments semaphore value.
- When semaphore value is zero, any process that performs wait operation will be blocked until the another process increments semaphore value with signal operation.
- Types of semaphores:
  - Binary semaphores: It is also known as mutex lock, used to implement mutual exclusion. It is initialized with 1 and can have only two values 0 and 1.
  - Counting Semaphore: It can be used to control access to a given resource consisting of a finite number of instances. The semaphore is initialized to the number of resources available.

## Binary Tree
- A binary tree has at most two children per node.
- Inserting data without order can cause problems during searching.
- Data structures should organize data for easy search, insertion, and deletion.

## Binary Search Tree (BST)
- BSTs are binary trees with restriction of having smaller elements on the left and larger elements on the right of the root.
- BSTs facilitate easier searching, insertion, and deletion compared to Binary Tree.
- **Worst-case scenario:** If data is skewed (right or left), the tree behaves like a linked list, leading to O(n) complexity.

### Binary Search Tree Traversals

- Inorder Traversal: Traverse left subtree then visit the root and then traverse the right subtree.
```c++
void printInorder(Node* node) {
    if (node == NULL) return;

    // Traverse left subtree
    printInorder(node->left);

    // Visit node
    cout << node->data << " ";

    // Traverse right subtree
    printInorder(node->right);
}
```

- Preorder Traversal: Visit the root then traverse left subtree and then traverse the right subtree.
```c++
void printPreOrder(Node* node)
{
    if (node == NULL) return;

    // Visit Node
    cout << node->data << " ";

    // Traverse left subtree
    printPreOrder(node->left);

    // Traverse right subtree
    printPreOrder(node->right);
}
```

- Postorder Traversal: Traverse left subtree then traverse the right subtree and then visit the root.
```c++
void printPostOrder(Node* node)
{
    if (node == NULL) return;

    // Traverse left subtree
    printPostOrder(node->left);

    // Traverse right subtree
    printPostOrder(node->right);

    // Visit node
    cout << node->data << " ";
}
```

## AVL Tree
- AVL trees are balanced BSTs with restriction of tree's height to log n, where n = number of nodes.
- These trees is used for efficient search operations with guarantee of O(log n) time complexity.
- The goal is to prevent the height from exceeding log n to avoid increased time complexity.
- AVL trees must have Balance Factor values between -1, 0 and +1 for each node.
- **Balance Factor** is calculated as the height of the left subtree minus the height of the right subtree.

## Create AVL Tree

### Unbalanced BST Cases
- Case 1: RR (Right Right) Unbalance
  - Example: Inserting 8, 9, 10 sequentially.
  - The balance factor of node 8 becomes -2 after inserting 10, indicating an RR unbalance.
  - Solution: Perform a single anticlockwise rotation at node 9.
  - After rotation, the tree is rebalanced with 9 as the root, and 8 and 10 as its left and right children, respectively.

- Case 2: LL (Left Left) Unbalance
  - Example: Inserting 10, 9, 8 sequentially.
  - The balance factor of node 10 becomes 2 after inserting 8, indicating an LL unbalance.
  - Solution: Perform a single clockwise rotation at node 9.
  - After rotation, the tree is rebalanced with 9 as the root, and 8 and 10 as its left and right children.

- Case 3: RL (Right Left) Unbalance
  - Example: Inserting 10, 12, 11 sequentially.
  - The balance factor of node 10 becomes -2 after inserting 11, indicating an RL unbalance.
  - Solution: Requires two rotations.
    - First, convert RL into RR by rotating nodes 12 and 11, making 11 the parent of 12.
    - Second, perform a single anticlockwise rotation at node 11.
  - After rotations, the tree is balanced with 11 as the root, and 10 and 12 as its left and right children.

- Case 4: LR (Left Right) Unbalance
  - Example: Inserting 10, 8, 9 sequentially.
  - The balance factor of node 10 becomes 2 after inserting 9, indicating an LR unbalance.
  - Solution: Requires two rotations.
    - First, convert LR into LL by rotating nodes 8 and 9, making 9 the parent of 8.
    - Second, perform a single clockwise rotation at node 9.
  - After rotations, the tree is balanced with 9 as the root, and 8 and 10 as its left and right children.
