#ifndef DATASTRUCTS_BINARY_TREE_H_
#define DATASTRUCTS_BINARY_TREE_H_

#include "../Util/default.h"

typedef struct _binary_tree Binary_Tree;

struct _binary_tree;

void* BinaryTree_getValue(Binary_Tree *bt);
Binary_Tree* BinaryTree_getLeft(Binary_Tree *bt);
Binary_Tree* BinaryTree_getRight(Binary_Tree *bt);

bool BinaryTree_setValue(Binary_Tree *bt, void* value);
bool BinaryTree_setLeft(Binary_Tree *bt, Binary_Tree *new_left);
bool BinaryTree_setRight(Binary_Tree *bt, Binary_Tree *new_right);

Binary_Tree* BinaryTree_create();
Binary_Tree* BinaryTree_new(void *value, Binary_Tree *left, Binary_Tree *right);
bool BinaryTree_destruct(Binary_Tree *bt);
bool is_Leaf(Binary_Tree *bt);


#endif /* DATASTRUCTS_BINARY_TREE_H_ */
