#include<stdio.h>
#include<malloc.h>
#include<memory.h>
#include<stdlib.h>

typedef int HPDataType;

typedef struct Heap { 
	HPDataType* _a;  
	int _size;   
	int _capacity; 
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp); 
void CheckCapacity(Heap* hp);
void swap(HPDataType* p1, HPDataType* p2);

void HeapPush(Heap* hp, HPDataType x); 
void HeapPop(Heap* hp);

HPDataType HeapTop(Heap* hp); 
int HeapSize(Heap* hp); 
int HeapEmpty(Heap* hp);

// ∂—≈≈–Ú 
void HeapSort(int* a, int n);

void JustUp(HPDataType* a, int n);
void JustDown(HPDataType* a, int n, int root);

void TestHeap();