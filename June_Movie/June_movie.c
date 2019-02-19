#include "June_Movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ListInit(List * pList) {
	pList->head = NULL;
	pList->tail = NULL;
}

int IsListEmpty(List * pList) {
	if (NULL == pList->head)
		return TRUE;
	else
		return FALSE;
}

void Insert(List * pList, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (IsListEmpty(pList)) {
		pList->head = newNode;
		pList->tail = newNode;
	}
	else {
		newNode->prev = pList->tail;
		pList->tail->next = newNode;
		pList->tail = newNode;
	}
}

Node * Search(List * pList, const char * title) {
	if (IsListEmpty(pList)) {
		printf("List is Empty !");
		exit(-1);
	}
	Node * pNode = pList->head;
	printf("\n\"%s\" �˻� ��� : ", title);
	while (NULL != pNode) {
		if (0 == strcmp(pNode->data.title, title)) {
			PrintData(pNode->data, sizeof(pNode->data.score) / sizeof(int));
			return pNode;
		}
		else
			pNode = pNode->next;
	}
	printf("ã�� ��ȭ�� �����ϴ�......");
	return NULL;
}

void Delete(List * pList, const char * title) {
	Node * delNode = Search(pList, title);
	if (NULL == delNode) {
		printf("������ ��ȭ�� �������� ����.\n");
		return;
	}
	else {
		printf("%s��(��) ���� �Ǿ����ϴ�.\n",delNode->data.title);
		if (pList->head == pList->tail) {
			pList->head = NULL; pList->tail = NULL;
			free(delNode);
		}
		else if (pList->head == delNode ){
			delNode->next->prev = NULL;
			pList->head = pList->head->next;
			pList->head->prev = NULL;
			free(delNode);
		}
		else if (pList->tail == delNode) {
			pList->tail = pList->tail->prev;
			pList->tail->next = NULL;
			free(delNode);
		}
		else {
			delNode->prev->next = delNode->next;
			delNode->next->prev = delNode->prev;
			free(delNode);
		}
	}
	return;
}

//************************************ Movie
void Modify(List * pList) {
	//Node * modNode = 
}

void Score(List * pList, int score) {

}

int GetAvgScore(const Data data, const int NumofScore) {
	int sum = 0, avgScore;
	for (int i = 0; i < NumofScore; i++)
		sum += data.score[i];
	avgScore = sum / NumofScore;
	return avgScore;
}

void PrintList(List * pList) {
	if (IsListEmpty(pList)) {
		printf("List is Empty !");
		exit(-1);
	}
	Node * pNode = pList->head;
	while (NULL != pNode) {
		PrintData(pNode->data); //���� ���� �Ѱ��ִ� ��
		pNode = pNode->next;
	}
	//���⼭ PrintDetail�Ұ��� �����϶��...?
	printf("\n");
}

void PrintData(const Data data) {
	printf("����: %s(%d)\t", data.title,data.year);
}

void PrintDetail(const Data data) {
	printf("\n============================\n");
	printf("���� : %s\n", data.title);
	printf("���� : %s\n", data.director);
	printf("�帣 : %s\n", data.genre);
	printf("�ֿ���� : %s\n", data.actor);
	printf("�����⵵ : %d\n", data.year);
	printf("**********���� ���**********\n");
	printf("����= %d\n", data.avg_score);
	printf("============================\n");
}