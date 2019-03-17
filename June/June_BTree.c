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

Node * SearchNode(Node ** root, int data) {
	Node * pNode = *root;
	while (1) {
		if (NULL == pNode)
			return NULL;
		else {
			while(NULL != pNode){
				if (TWO_NODE == pNode->nodeType) {
					if (data == pNode->data[0]) {
						return pNode;
					}
					else {
						if (data < pNode->data[0])
							pNode = pNode->child[0];
						else if (data > pNode->data[0] && data < pNode->data[1])
							pNode = pNode->child[1];
					}
				}
				else if (THREE_NODE == pNode->nodeType) {
					for (int i = 0; i < 2; i++) {
						if (data == pNode->data[i]) {
							return pNode;
						}
					}
					if (data < pNode->data[0])
						pNode = pNode->child[0];
					else if (data > pNode->data[0] && data < pNode->data[1])
						pNode = pNode->child[1];
					else if (data > pNode->data[1])
						pNode = pNode->child[2];
				}
				else if (FOUR_NODE == pNode->nodeType) {
					for (int i = 0; i < 3; i++) {
						if (data == pNode->data[i]) {
							return pNode;
						}
					}
					//Å½»ö
				}
			}
		}
	}
}

int DeleteNode(Node ** root, int data) {
	Node * pNode = *root; 
	while (NULL != pNode) {
		if (TWO_NODE == pNode->nodeType) {
		}
		else if (THREE_NODE == pNode->nodeType) {
		}
		else if (FOUR_NODE == pNode->nodeType) {
		}
	}
}