#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
}BTreeNode;
BTreeNode * root;

void * Insert(BTData nData) {
	BTreeNode * newBt = (BTreeNode*)malloc(sizeof(BTreeNode));
	newBt->data = nData;
	newBt->left = NULL;
	newBt->right = NULL;

	if (NULL == root) {
		root = newBt;
	}
	else {
		BTreeNode * pNode = root;
		while (1) {
			if (nData < pNode->data) {
				if (NULL == pNode->left) {
					pNode->left = newBt;
					break;
				}
				else {
					pNode = pNode->left;
				}
			}
			else if (nData > pNode->data){
				if (NULL == pNode->right) {
					pNode->right = newBt;
					break;
				}
				else {
					pNode = pNode->right;
				}
			}
		}
	}
}

int main() {
	Insert(7);
	Insert(10);
	Insert(3);
	Insert(5);
	Insert(14);
	Insert(12);
	Insert(2);
	Insert(17);
	Insert(4);
	Insert(9);
	return 0;
}