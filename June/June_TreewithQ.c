#include <stdio.h>
#include <stdlib.h>

typedef struct _bTreeNode {
	int data;
	int depth;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
	struct _bTreeNode * parent;
}BTreeNode;
typedef BTreeNode Node;

typedef struct _qNode {
	Node * data;
	struct _qNode * next;
}QNODE;

typedef struct _queue {
	QNODE * front;
	QNODE * rear;
}QUEUE;

void QueueInit(QUEUE * pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

void Insert(Node ** root, int nData) {
	Node * newBt = (Node*)malloc(sizeof(Node));
	newBt->data = nData;
	newBt->left = NULL;
	newBt->right = NULL;
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
	if (NULL == pNode->left && NULL == pNode->right) {
		if (pNode->data < pNode->parent->data)
			pNode->parent->left = NULL;
		else
			pNode->parent->right = NULL;
		free(pNode);
		return 1;
	}
	else if (NULL == pNode->left && NULL != pNode->right) {
		if (pNode->data < pNode->parent->data)
			pNode->parent->left = NULL;
		else
			pNode->parent->right = NULL;
	}
	else if (NULL == pNode->right && NULL != pNode->left) {
		if (pNode->data < pNode->parent->data)
			pNode->parent->left = NULL;
		else
			pNode->parent->right = NULL;
	}
	else {

	}
	return 0;
}

int main() {
	Node * root = NULL;
	Insert(&root,10);
	Insert(&root, 3);
	Insert(&root, 5);
	Insert(&root, 14);
	Insert(&root, 12);
	Insert(&root, 2);
	Insert(&root, 17);
	Insert(&root, 4);
	Insert(&root, 9);
	TreeLelvelOrder(root);

	printf("\n\nFind node %d\n", FindTreeNode(&root, 14)->data);
	//printf("\n\nFind node %d\n", Delete(&root,14)->data);
	return 0;
}