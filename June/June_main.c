#include <stdio.h>
#include <stdlib.h>
#include "June_BTree.h"

int main() {
	Node * root = NULL;
	InsertNode(&root, 5);
	InsertNode(&root, 11);
	InsertNode(&root, 13);
	InsertNode(&root, 8);
	InsertNode(&root, 1);
	InsertNode(&root, 7);
	return 0;
}