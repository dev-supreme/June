#include <stdio.h>
#include <stdlib.h>
/*
과제: 더블링크드리스트 탐색 최적화
평균값을 구해서, Head부터 탐색할지, Tail부터 탐색할지 판단하기
//1.현재 리스트의 평균을 구한 후,
2.삽입하려는 값이 평균보다 작거나 같으면, 헤드부터 탐색 후 삽입 //Comp Func CallBack??
3.삽입하려는 값이 평균보다 크면, 테일부터 탐색 후 삽입
*/
typedef struct _node {
	int nData;
	struct _node* pPrev;
	struct _node* pNext;
}NODE;
NODE* head = NULL;
NODE* tail = NULL;
int avg = 0;

int GetAverage() {
	int sum = 0;
	int count = 0;
	NODE* pNode = head;
	while (NULL != pNode) {
		sum += pNode->nData;
		pNode = pNode->pNext;
		count++;
	}
	if (count != 0)
		avg = sum / count;
	else
		return 0;
	return avg;
}

NODE* FindNode(int _nData) {
	//if found, print Node index, data
	//if not, print "Not Found"
	NODE* pNode = head;
	int nIndex = 1;
	while (NULL != pNode) {
		if (_nData == pNode->nData) {
			printf("Node Index: %d, Data: %d\n", nIndex, _nData);
			return pNode;
		}
		else {
			pNode = pNode->pNext;
			++nIndex;
		}
	}
	printf("Not Found!\n");
	return NULL;
}

NODE* R_FindNode(int _nData) {
	//if found, print Node index, data
	//if not, print "Not Found"
	NODE* pNode = tail;
	//int nIndex = 1;
	while (NULL != pNode) {
		if (_nData == pNode->nData) {
			printf("Node Data: %d\n",  _nData);
			return pNode;
		}
		else {
			pNode = pNode->pPrev;
			//++nIndex;
		}
	}
	printf("Not Found!\n");
	return NULL;
}

void DeleteNode(int _nData) {
	if (_nData >= GetAverage()) {
		NODE* pNode = R_FindNode(_nData);
		if (NULL == pNode) {
			printf("\nDelete Failed\n");
			return;
		}
		pNode->pPrev->pNext = pNode->pNext;
		pNode->pNext->pPrev = pNode->pPrev;
		free(pNode);
		pNode = NULL;
	}
	else {
		NODE* pNode = FindNode(_nData);
		if (NULL == pNode) {
			printf("\nDelete Failed\n");
			return;
		}
		pNode->pPrev->pNext = pNode->pNext;
		pNode->pNext->pPrev = pNode->pPrev;
		free(pNode);
		pNode = NULL;
	}	
}
void InsertNodeFromTail(int _nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;
	pNewNode->nData = _nData;

	if (NULL == tail) {
		head = pNewNode;
		tail = pNewNode;
	}
	else {
		NODE* pNode = tail;
		//Case by Case
		if (pNewNode->nData >= pNode->nData) {
			pNewNode->pNext = NULL;
			pNewNode->pPrev = pNode;
			pNode->pNext = pNewNode;
			tail = pNewNode;
		}
		else {
			//Mid
			while (NULL != pNode->pPrev) {
				if (pNewNode->nData >= pNode->pPrev->nData) {
					pNewNode->pNext = pNode;
					pNewNode->pPrev = pNode->pPrev;
					pNode->pPrev->pNext = pNewNode;
					pNode->pPrev = pNewNode;
					break;
				}
				pNode = pNode->pPrev;
			}
			if (pNode->pPrev == NULL) {
				pNewNode->pNext = pNode;
				pNode->pPrev = pNewNode;
				head = pNewNode;
			}
		}
	}
}

void InsertNodeFromHead(int _nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;
	pNewNode->nData = _nData;

	if (NULL == head) {
		head = pNewNode;
		tail = pNewNode;
	}
	else {
		NODE* pNode = head;
		//Case by Case
		if (pNewNode->nData <= pNode->nData) {
			pNewNode->pNext = pNode;
			pNode->pPrev = pNewNode;
			head = pNewNode;
		}
		else {
			//Mid
			while (NULL != pNode->pNext) {
				if (pNewNode->nData <= pNode->pNext->nData) {
					pNewNode->pNext = pNode->pNext;
					pNewNode->pPrev = pNode;
					pNode->pNext->pPrev = pNewNode;
					pNode->pNext = pNewNode;
					break;
				}
				pNode = pNode->pNext;
			}
			if (pNode->pNext == NULL) {
				pNewNode->pPrev = pNode;
				pNode->pNext = pNewNode;
				tail = pNewNode;
			}
		}
	}
}

void PrintList_Head() {
	NODE* pNode = head;
	while (NULL != pNode) {
		printf("%d->", pNode->nData);
		pNode = pNode->pNext;
	}
	printf("NULL\n");
}

void PrintList_Tail() {
	NODE* pNode = tail;
	while (NULL != pNode) {
		printf("%d->", pNode->nData);
		pNode = pNode->pPrev;
	}
	printf("NULL\n");
}

int main(void) {
	int input = 0;
	while (1) {
		printf("Input Data : ");
		scanf_s("%d", &input);
		if (input == EOF) break; //-1, Break

		if (input >= GetAverage()) {
			printf("Tail Insert!\n");
			printf("Average = %d\n", GetAverage());
			InsertNodeFromTail(input);
		}
		else {
			printf("Head Insert!\n");
			printf("Average = %d\n", GetAverage());
			InsertNodeFromHead(input);
		}
	}
	PrintList_Head();
	PrintList_Tail();
	printf("\n");
	DeleteNode(10);
	DeleteNode(30);
	DeleteNode(99);
	PrintList_Head();
	PrintList_Tail();
	return 0;
}