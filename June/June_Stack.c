#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 5
int count = 0;
typedef struct _node {
	int nData;
	struct _node* pNext;
}NODE;
NODE* top = NULL;
void push(int nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	pNewNode->nData = nData;
	pNewNode->pNext = NULL;

	if (count > STACK_SIZE) {
		printf("STACK OVERFLOW\n");
		return;
	}
	if (NULL == top) {
		top = pNewNode;
		count++;
	}
	else {
		NODE* pNode = top;
		pNewNode->pNext = pNode;
		top = pNewNode;
		count++;
	}
}

int pop() {
	NODE* pNode = top;
	printf("Pop : %d\n", pNode->nData);
	top = pNode->pNext;
	count--;
}

int main() {
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(5);
	push(5);
	pop();
	pop();
	pop();
	pop();
	pop();
	return 0;
}