#include <stdio.h>
#include <stdlib.h>
/*
링크드 리스트 ordered insert / find / delete 구현
*/
typedef struct _node {
	int nData;
	struct _node* pNext;
}NODE;

NODE* head = NULL;

int FindNode(int _nData) {
	//if found, print Node index, data
	//if not, print "Not Found"
	NODE* pNode = head;
	int nIndex = 1;
	while (NULL != pNode) {
		if (_nData == pNode->nData) {
			printf("Node Index: %d, Data: %d\n", nIndex, _nData);
			return 1;
		}
		else {
			pNode = pNode->pNext;
			++nIndex;
		}
	}
	printf("Not Found!\n");
	return 0;
}

void DeleteNode(int _nData) {
	//FindNode first,
	//case: Found / not Found
	//if found, delete node, link the rest
	//if not found, return;
	NODE* pNode = head;
	NODE* tmpNode = head;
	if (_nData == head->nData) {
		head = head->pNext;
		free(tmpNode);
		tmpNode = NULL;
	}
	//always make tmpNode previous pNode?
	while (NULL != pNode) {
		if (_nData == pNode->nData) {
			//Delete and Link
			printf("Delete %d!\n", pNode->nData);
			tmpNode->pNext = pNode->pNext;
			free(pNode);
			pNode = NULL;
			break;
		}
		else {
			tmpNode = pNode; //save the  pNode into tmpNode
			pNode = pNode->pNext; //move pNode to next
		}
	}
}
//Insert a Node(Ordered)
void InsertNode_Ordered(int _nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE)); //Allocation memory to New Node
	pNewNode->nData = _nData; //Initialization
	pNewNode->pNext = NULL;

	//4가지 경우
	//
	if (NULL == head) {
		head = pNewNode;
	}
	else {
		NODE* pNode = head;
		while (NULL != pNode->pNext) {
			pNode = pNode->pNext;
		}
		pNode->pNext = pNewNode;
	}
}


//Insert a Node
void InsertNode(int _nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE)); //Allocation memory to New Node
	pNewNode->nData = _nData; //Initialization
	pNewNode->pNext = NULL;

	if (NULL == head) {
		head = pNewNode;
	}
	else {
		NODE* pNode = head;
		while (NULL != pNode->pNext) {
			pNode = pNode->pNext;
		}
		pNode->pNext = pNewNode;
	}
}

void PrintList() {
	NODE* pNode = head;
	while (NULL != pNode) {
		printf("%d -> ", pNode->nData);
		pNode = pNode->pNext;
	}
	printf("NULL\n");
}

void ClearList() {
	NODE* pNode = head;
	while (NULL != pNode) {
		NODE* tmpNode = pNode;
		pNode = pNode->pNext;
		free(tmpNode);
		tmpNode = NULL;
	}
}
int main(void) {
	InsertNode(10);
	InsertNode(7);
	InsertNode(5);
	PrintList();
	FindNode(5);
	DeleteNode(10);
	PrintList();
	ClearList();
	return 0;
}