#include <stdio.h>
#include <stdlib.h>
#include "June_Heap.h"

int main() {
	int arr[HEAP_LEN] = { 1,6,29,300,10,16,77,8,3,22 };
	int size = 10;
	PrintHeap(arr, size);
	BuildMaxHeap(arr, size);
	HInsert(arr, &size, 5);
	HInsert(arr, &size, 6);
	HInsert(arr, &size, 7);
	PrintHeap(arr, size);
	return 0;
}