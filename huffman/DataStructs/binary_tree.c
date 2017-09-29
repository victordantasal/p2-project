#include "binary_tree.h"

struct _binary_tree
{
	void *value;
	Binary_Tree *left;
	Binary_Tree *right;
};

void* BinaryTree_getValue(Binary_Tree *bt)
{
	if(isNull(bt))
		return ERROR;
	return bt->value;
}
Binary_Tree* BinaryTree_getLeft(Binary_Tree *bt)
{
	if(isNull(bt))
		return NULL;
	return bt->left;
}
Binary_Tree* BinaryTree_getRight(Binary_Tree *bt)
{
	if(isNull(bt))
		return NULL;
	return bt->right;
}

bool BinaryTree_setValue(Binary_Tree *bt, void* value)
{
	if(isNull(bt))
		return false;
	bt->value = value;
	return true;
}
bool BinaryTree_setLeft(Binary_Tree *bt, Binary_Tree *new_left)
{
	if(isNull(bt))
		return false;
	bt->left = new_left;
	return true;
}
bool BinaryTree_setRight(Binary_Tree *bt, Binary_Tree *new_right)
{
	if(isNull(bt))
		return false;
	bt->right = new_right;
	return true;
}

Binary_Tree* BinaryTree_create()
{
	return NULL;
}
Binary_Tree* BinaryTree_new(void *value, Binary_Tree *left, Binary_Tree *right)
{
	Binary_Tree *new_bt = (Binary_Tree*) malloc(sizeof(Binary_Tree));
	if(Binary_Tree_setValue(new_bt,value) && Binary_Tree_setLeft(new_bt,left) && Binary_Tree_setRight(new_bt,right))
		return new_bt;
	DEBUG printf("ERROR, IT'S NOT POSSIBLE TO ALOCATE MEMORY");
	return NULL;


}
bool BinaryTree_destruct(Binary_Tree *bt)
{
	if(!isNull(bt))
	{
		BinaryTree_destruct(bt->left);
		BinaryTree_destruct(bt->right);
		free(bt);
		bt = NULL;
	}
	else if(isNull(bt))
		return true;
	return false;
}




