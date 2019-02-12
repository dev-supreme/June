#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 5
int count = 0;
typedef struct _node {
	int nData;
	struct _node* pNext;
}NODE;
NODE* head = NULL;
NODE* tail = NULL;

void push_Ordered(int nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	pNewNode->nData = nData;
	pNewNode->pNext = NULL;

	if (count >= STACK_SIZE) {
		printf("STACK OVERFLOW\n");
		return;
	}

	if (NULL == head) {
		head = pNewNode;
		tail = pNewNode;
		count++;
	}
	else {
		NODE* pNode = head;
		if (pNewNode->nData >= pNode->nData) {
			pNewNode->pNext = pNode;
			head = pNewNode;
		}
		else {
			while (NULL != pNode->pNext) {
				if (pNewNode->nData >= pNode->pNext->nData) {
					pNewNode->pNext = pNode->pNext;
					pNode->pNext = pNewNode;
					break;
				}
				pNode = pNode->pNext;
			}
			if (NULL == pNode->pNext) {
				pNode->pNext = pNewNode;
				tail = pNewNode;
			}
		}
		count++;
	}
}

int pop() {
	if (NULL == head) {
		printf("STACK UNDERFLOW!\n");
		return -1;
	}
	NODE* pNode = head;
	int nData = head->nData;
	printf("Pop : %d\n", pNode->nData);
	head = head->pNext;
	free(pNode);
	pNode = NULL;
	count--;
	return nData;
}

int main() {
	push_Ordered(7);
	push_Ordered(10);
	push_Ordered(8);
	push_Ordered(42);
	push_Ordered(15);

	pop();
	pop();
	pop();
	pop();
	pop();
	return 0;
}