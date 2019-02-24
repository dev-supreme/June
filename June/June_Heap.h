#ifndef __JUNE_HEAP_H__
#define __JUNE_HEAP_H__
#define TRUE 1
#define FALSE 0
#define HEAP_LEN 10

/*** Heap 관련 연산들 ****/
void Heapify(int* arr, int size, int mid);
void BuildMaxHeap(int * arr, int size);
int extractMax(int* arr, int* size);
void PrintHeap(int* arr, int size);
void HInsert(int* arr, int* size,int data);
#endif // !__JUNE_HEAP_H__
