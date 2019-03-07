#include <stdio.h>
#include "June_Heap.h"

/*** Heap 관련 연산들 ****/

void Heapify(int* arr, int size, int mid) {
	int parent_node = mid;
	int left_node = parent_node * 2 + 1;
	int right_node = parent_node * 2 + 2;
	int largest_node = parent_node;
	int temp;

	if (left_node < size && arr[left_node] > arr[largest_node]) {
		largest_node = left_node;
	}

	if (right_node < size && arr[right_node] > arr[largest_node]) { 
		largest_node = right_node;
	}

	if (parent_node != largest_node) {
		temp = arr[largest_node];
		arr[largest_node] = arr[parent_node];
		arr[parent_node] = temp;
		Heapify(arr, size, largest_node);
	}
}

int extractMax(int* arr, int* size) {
	(*size)--;
	int max = arr[0];
	arr[0] = arr[*size];
	Heapify(arr, *size, 0);
	return max;
}

void HInsert(int* arr, int* size, int data) {
	arr[(*size)++] = data;
	Heapify(arr, *size, (*size));
	//HomeWork 0224
}

void PrintHeap(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void BuildMaxHeap(int * arr, int size) {
	int mid = size / 2 - 1;
	for (mid; mid >= 0; mid--) {
		Heapify(arr, size, mid);
	}
}
