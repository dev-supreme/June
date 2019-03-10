#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include "June_BTree.h"

Node * createNode(int data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	newNode->data[0] = 0;
	return newNode;
}

int InsertNode(Node ** root, int data) {
	Node * pNode = *root;
	if (NULL == pNode) {
		*root = createNode(data);
	}
	else {
		//Split
		while (NULL != pNode) {
			if (TWO_NODE == pNode->nodeType) {
				if (NULL == pNode->child[0]) {
					//InsertData
					if (data < pNode->data[0]) {
						pNode->data[1] = pNode->data[0];
						pNode->data[0] = data;
					}
					else if (data > pNode->data[0]) {
						pNode->data[1] = data;
					}
					pNode->nodeType = THREE_NODE;
					break;
				}
				else {
					if (data < pNode->data[0])
						pNode = pNode->child[0];
					else if (data > pNode->data[0] && data < pNode->data[1])
						pNode = pNode->child[1];
				}
			}
			else if (THREE_NODE == pNode->nodeType) {
				if (NULL == pNode->child[0]) {
					//InsertData
					if (data < pNode->data[0]) {
						pNode->data[3] = pNode->data[2];
						pNode->data[2] = pNode->data[1];
						pNode->data[1] = pNode->data[0];
						pNode->data[0] = data;
					}
					else if (data > pNode->data[0] && data < pNode->data[1]) {
						pNode->data[3] = pNode->data[2];
						pNode->data[2] = pNode->data[1];
						pNode->data[1] = data;
					}
					else if (data > pNode->data[1] && data < pNode->data[2]) {
						pNode->data[3] = pNode->data[2];
						pNode->data[2] = data;
					}
					else if (data > pNode->data[2]) {
						pNode->data[3] = data;
					}				
					pNode->nodeType = FOUR_NODE;
					break;
				}
				else {
					if (data < pNode->data[0])
						pNode = pNode->child[0];
					else if (data > pNode->data[0] && data < pNode->data[1])
						pNode = pNode->child[1];
					else if (data > pNode->data[1])
						pNode = pNode->child[2];
				}
			}
			else if (FOUR_NODE == pNode->nodeType) {
				//Split
				if (NULL == pNode->parent) {
					Node * newNode1 = createNode(pNode->data[0]);
					Node * newNode2= createNode(pNode->data[2]);
					pNode->nodeType = TWO_NODE;
					pNode->data[0] = pNode->data[1];
					pNode->child[0] = newNode1;
					pNode->child[1] = newNode2;

					newNode1->parent = pNode;
					newNode2->parent = printf;
				}
				else {
					//split inplementation
				}
			}
		}
	}
	return 0;
}
