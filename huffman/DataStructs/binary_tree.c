#include "../Util/default.h"

typedef struct _binary_tree Binary_Tree;

struct _binary_tree
{
	void *value;
	Binary_Tree *left;
	Binary_Tree *right;
};

void* BinaryTree_getValue(Binary_Tree *bt);
Binary_Tree* BinaryTree_getLeft(Binary_Tree *bt);
Binary_Tree* BinaryTree_getRight(Binary_Tree *bt);

int BinaryTree_setValue(Binary_Tree *bt, void* value);
int BinaryTree_setLeft(Binary_Tree *bt, Binary_Tree *new_left);
int BinaryTree_setRight(Binary_Tree *bt, Binary_Tree *new_right);

Binary_Tree* BinaryTree_create();
Binary_Tree* BinaryTree_new(void *value, Binary_Tree *left, Binary_Tree *right);
int BinaryTree_destruct(Binary_Tree *bt);




