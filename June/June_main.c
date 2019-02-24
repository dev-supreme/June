#include <stdio.h>
#include <stdlib.h>
#include "June_Tree.h"

int main() {
	Node * root = NULL;
	Insert(&root, 10);
	Insert(&root, 3);
	Insert(&root, 5);
	Insert(&root, 14);
	Insert(&root, 12);
	Insert(&root, 13);
	Insert(&root, 15);
	Insert(&root, 2);
	Insert(&root, 17);
	Insert(&root, 4);
	Insert(&root, 9);
	TreeLelvelOrder(root);
	Delete(&root, 2);
	Delete(&root, 12);
	Delete(&root, 15);
	Delete(&root, 5);
	Delete(&root, 17);
	Delete(&root, 4);
	Delete(&root, 9);
	printf("\n\nAfter Delete\n");
	TreeLelvelOrder(root);

	return 0;
}