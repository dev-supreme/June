#pragma once
#ifndef __JUNE_TREE_H__
#define __JUNE_TREE_H__
#define TRUE 1
#define FALSE 0
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

void QueueInit(QUEUE * pq);
void Insert(Node ** root, int nData);
void Enqueue(QUEUE * pq, Node * data, int depth);
Node * Dequeue(QUEUE * pq);
void TreeLelvelOrder(Node * root);
Node * FindTreeNode(Node ** root, int key);
int Delete(Node ** root, int key);
#endif // !__JUNE_TREE_H__
