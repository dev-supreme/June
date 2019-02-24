#include <stdio.h>
#include <stdlib.h>
#include "June_Tree.h"
void QueueInit(QUEUE * pq) {
	pq->front = NULL;
	pq->rear = NULL;
}
void Insert(Node ** root, int nData) {
	Node * newBt = (Node*)malloc(sizeof(Node));
	newBt->data = nData;
	newBt->left = NULL;
	newBt->right = NULL;
	newBt->parent = NULL;
	Node* pRoot = *root;

	if (NULL == pRoot) {
		*root = newBt;
	}
	else {
		Node * pNode = pRoot;
		while (1) {
			if (nData < pNode->data) {
				if (NULL == pNode->left) {
					pNode->left = newBt;
					newBt->parent = pNode;
					break;
				}
				else {
					pNode = pNode->left;
				}
			}
			else if (nData > pNode->data){
				if (NULL == pNode->right) {
					pNode->right = newBt;
					newBt->parent = pNode;
					break;
				}
				else {
					pNode = pNode->right;
				}
			}
		}
	}
}
void Enqueue(QUEUE * pq, Node * data, int depth) {
	QNODE * newNode = (QNODE*)malloc(sizeof(QNODE));
	newNode->data = data;
	newNode->next = NULL;
	newNode->data->depth = depth;

	if (NULL == pq->front) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}
Node * Dequeue(QUEUE * pq) {
	QNODE * pNode = pq->front;
	if (NULL == pNode) return NULL;
	Node * Data = pNode->data;
	pq->front = pq->front->next;
	free(pNode);
	pNode = NULL;
	return Data;
}
void TreeLelvelOrder(Node * root) {
	QUEUE q;
	QueueInit(&q);
	Enqueue(&q, root,1);
	Node * data = NULL;
	int curDepth = 1;
	while (1) {
		data = Dequeue(&q);
		if (NULL == data) break; // Q is Empty
		if (data->depth > curDepth) {
			printf("\n");
			curDepth++;
		}
		printf("%d ", data->data);
		if (NULL != data->left) {
			Enqueue(&q, data->left,data->depth +1);
		}
		if (NULL != data->right) {
			Enqueue(&q, data->right, data->depth + 1);
		}
	}
}

Node * FindTreeNode(Node ** root, int key) {
	Node * pNode = *root;
	while (1) {
		if (NULL == pNode)
			return NULL;
		if (key == pNode->data) {
			break;
		}
		else {
			if (key < pNode->data)
				pNode = pNode->left;
			else
				pNode = pNode->right;
		}
	}
	return pNode;
}

int Delete(Node ** root, int key) {
	Node * pNode = FindTreeNode(root, key);
	//3 cases(no child, 1 child, 2 childs)
	if (NULL == pNode) {
		return FALSE;
	}
	if (NULL == pNode->left && NULL == pNode->right) { //I have no child
		if (pNode->data < pNode->parent->data)//If I am left of my parent
			pNode->parent->left = NULL;
		else                             //If I am right of my parent
			pNode->parent->right = NULL;
		free(pNode);
		return TRUE;
	}
	else if (NULL == pNode->right && NULL != pNode->left) { //I have left child
		if (pNode->data < pNode->parent->data) { //If I am left of my parent
			pNode->parent->left = pNode->left; //Connect Parent's left with my left child
			pNode->left->parent = pNode->parent;
		}
		else {//If I am right of my parent
			pNode->parent->right = pNode->left; //Connect Parent's right with my left child
			pNode->left->parent = pNode->parent;
		}
		free(pNode);
		return TRUE;
	}
	else if (NULL == pNode->left && NULL != pNode->right) { //I have right child
		if (pNode->data < pNode->parent->data) {//If I am left of my parent
			pNode->parent->left = pNode->right; //Connect Parent's left with my right child
			pNode->right->parent = pNode->parent;
		}
		else {//If I am right of my parent
			pNode->parent->right = pNode->right;//Connect Parent's right with my right child
			pNode->right->parent = pNode->parent;
		}
		free(pNode);
		return TRUE;
	}
	else { //I have both(left, right) children
		if (pNode->data < pNode->parent->data){//왼쪽자식을 올리는 것으로 통일
			pNode->parent->left = pNode->left;
			pNode->left->parent = pNode->parent;
			pNode->left->right = pNode->right;
		}
		else {
			pNode->parent->right = pNode->left; 
			pNode->left->parent = pNode->parent;
			pNode->left->right = pNode->right;
		}
		free(pNode);
		return TRUE;
	}
	return FALSE;
}
