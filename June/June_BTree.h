#pragma once
#ifndef __JUNE_BTREE_H__
#define __JUNE_BTREE_H__
#define TRUE 1
#define FALSE 0
#define HEAP_LEN 10

enum _NODETYPE {
	TWO_NODE,
	THREE_NODE,
	FOUR_NODE
};
typedef struct _node {
	int data[3];
	int nodeType;
	struct node* child[4];
	struct node* parent;
}Node;

Node * createNode(int data);
int InsertNode(Node ** root, int data);
int DeleteNode(Node ** root, int data);
Node* SearchNode(Node ** root, int data);
#endif // !__JUNE_BTREE_H__
