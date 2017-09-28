#include "binary_tree.h"

struct _binary_tree
{
	void *value;
	Binary_Tree *left;
	Binary_Tree *right;
};

void* BinaryTree_getValue(Binary_Tree *bt)
{
	//TODO method getValue
}
Binary_Tree* BinaryTree_getLeft(Binary_Tree *bt)
{
	//TODO method getLeft
}
Binary_Tree* BinaryTree_getRight(Binary_Tree *bt)
{
	//TODO method getRight
}

bool BinaryTree_setValue(Binary_Tree *bt, void* value)
{
	//TODO method setValue
}
bool BinaryTree_setLeft(Binary_Tree *bt, Binary_Tree *new_left)
{
	//TODO method setLeft
}
bool BinaryTree_setRight(Binary_Tree *bt, Binary_Tree *new_right)
{
	//TODO method setRight
}

Binary_Tree* BinaryTree_create()
{
	//TODO method create a binary tree
}
Binary_Tree* BinaryTree_new(void *value, Binary_Tree *left, Binary_Tree *right)
{
	//TODO method create a binary's tree new node
}
int BinaryTree_destruct(Binary_Tree *bt)
{
	//TODO method destruct a binary tree
}




