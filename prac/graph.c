#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
  int data;
  struct TreeNode** childrens;
  int child_capacity;
  int child_count;
} TreeNode;

typedef struct Tree {
  TreeNode* root;
} Tree;

TreeNode* create_node(int data) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  if (!node) {
    return NULL;
  }

  node->data = data;
  node->childrens = NULL;
  node->child_capacity = 0;
  node->child_count = 0;

  return node;
}

Tree* create_tree(int root_data) {
  Tree* t = (Tree*)malloc(sizeof(Tree));
  if (!t) {
    return NULL;
  }

  t->root = create_node(root_data);
  return t;
}

TreeNode* find_node(TreeNode* root, int data) {
  if (!root) {
    return NULL;
  }

  if(root->data == data) return root;

  TreeNode* node;
  for (int i = 0; i < root->child_count; i++) {
    TreeNode* found = find_node(root->childrens[i], data);
    if (found) return found;
  }

  return NULL;
}

int add_child(TreeNode* parent, int child_data) {
  if (!parent) return 0;

  TreeNode* child_node = create_node(child_data);
  if(!child_node) return 0;

  if (parent->child_count >= parent->child_capacity) {
    int new_capacity = parent->child_capacity == 0 ? 2 : parent->child_capacity * 2;
    TreeNode** new_childrens = (TreeNode**)realloc(parent->childrens, new_capacity * sizeof(TreeNode*));

    if (!new_childrens) {
      return 0;
    }

    parent->child_capacity = new_capacity;
    parent->childrens = new_childrens;
  }

  parent->childrens[parent->child_count] = child_node;
  parent->child_count++;
  
  return 1;
}

int add_child_to_parent(Tree* tree, int parent_data, int child_data) {
  if (!tree || !tree->root) {
    return 0;
  }

  TreeNode* parent = find_node(tree->root, parent_data);
  if (!parent) {
    return 0;
  }

  add_child(parent, child_data);

  return 1;
}

void preorder_traversal(TreeNode* root, int depth) {
  if (!root) return;

  for (int i = 0; i < depth; i++) {
    printf(" ");
  }
  printf("%d\n", root->data);

  for (int i = 0; i < root->child_count; i++) {
    preorder_traversal(root->childrens[i], depth+1);
  }
}

void print_tree(Tree* tree) {
  if (!tree) {
    return;
  }

  printf("Tree Structure:\n");
  preorder_traversal(tree->root, 0);
}

void free_tree(TreeNode* root) {
  if (!root) {
    return;
  }

  for (int i = 0; i < root->child_count; i++) {
    free_tree(root->childrens[i]);
  }

  free(root->childrens);
  free(root);
}

void destroy_tree(Tree* tree) {
  if (!tree) {
    return;
  }

  free_tree(tree->root);
  free(tree);
}

int main() {
  // Create a tree with root value 1
  Tree* tree = create_tree(1);
  if (!tree) {
    printf("Failed to create tree\n");
    return 1;
  }
  
  // Add children to root (1)
  add_child_to_parent(tree, 1, 2);
  add_child_to_parent(tree, 1, 3);
  add_child_to_parent(tree, 1, 4);
  
  // Add children to node 2
  add_child_to_parent(tree, 2, 5);
  add_child_to_parent(tree, 2, 6);
  
  // Add children to node 3
  add_child_to_parent(tree, 3, 7);
  
  // Add children to node 4
  add_child_to_parent(tree, 4, 8);
  add_child_to_parent(tree, 4, 9);
  add_child_to_parent(tree, 4, 10);
  
  // Print tree structure
  print_tree(tree);
  
  // // Demonstrate different traversals
  // printf("\nPre-order traversal:\n");
  // preorder_traversal(tree->root, 0);
  
  // printf("\nPost-order traversal: ");
  // postorder_traversal(tree->root);
  // printf("\n");
  
  // printf("\nLevel-order traversal: ");
  // level_order_traversal(tree->root);
  // printf("\n");
  
  // // Print tree statistics
  // printf("\nTree Statistics:\n");
  // printf("Height: %d\n", tree_height(tree->root));
  // printf("Total nodes: %d\n", count_nodes(tree->root));
  // printf("Leaf nodes: %d\n", count_leaves(tree->root));
  
  // // Test search functionality
  // TreeNode* found = find_node(tree->root, 7);
  // if (found) {
  //     printf("Node with value 7 found. Children count: %d\n", found->child_count);
  // }
  
  // Clean up
  destroy_tree(tree);
  // print_tree(tree); // error segmentation fault
  
  return 0;
}
