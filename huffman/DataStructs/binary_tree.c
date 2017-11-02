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
		return NULL;
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
	if(BinaryTree_setValue(new_bt,value) && BinaryTree_setLeft(new_bt,left) && BinaryTree_setRight(new_bt,right))
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

bool BinaryTree_isLeaf(Binary_Tree *bt)
{
	if(!isNull(bt))
		if(isNull(BinaryTree_getLeft(bt)) && isNull(BinaryTree_getRight(bt)))
			return true;
	return false;
}

void BinaryTree_printPreOrder(Binary_Tree *bt, void(*print)(void *value))
{
	if(!isNull(bt))
	{
		print(BinaryTree_getValue(bt));

		BinaryTree_printPreOrder(
				BinaryTree_getLeft(bt),
				print
				);

		BinaryTree_printPreOrder(
						BinaryTree_getRight(bt),
						print
						);
	}
}



