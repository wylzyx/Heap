#include"Heap.h"
#include<assert.h>

void HeapInit(Heap* hp, HPDataType* a, int n) {
	int i = 0;
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	memcpy(hp->_a, a, sizeof(HPDataType) * n);

	for (i = (hp->_size - 2) / 2; i >= 0; i--) {
		JustDown(hp->_a, hp->_size, i);
	}
}


void HeapDestory(Heap* hp) {
	if (hp->_a) {
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = hp->_capacity = 0;
	}
}

//¼ì²éÈİÁ¿
void CheckCapacity(Heap* hp) {
	if (hp->_size == hp->_capacity) {
	 	hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
	}
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	CheckCapacity(hp);
	hp->_a[hp->_size] = x;
	++hp->_size;

	JustUp(hp->_a, hp->_size);
}

void HeapPop(Heap* hp) {
	if (HeapEmpty(hp) == 0) {
		Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
		--hp->_size;
		JustDown(hp->_a, hp->_size, 0);
	}
}

HPDataType HeapTop(Heap* hp) {
	assert(hp && hp->_size);
	return hp->_a[0];
}

int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp) {
	assert(hp);
	return hp->_size == 0;
}

// ¶ÑÅÅĞò 
void HeapSort(int* a, int n) {
	//½¨¶Ñ
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; i++) {
		JustDown(a, n, i);
	}
	//¶ÑÅÅĞò
	int end = n - 1;
	while (end > 0) {
		//½»»»
		Swap(&a[0], &a[end]);
		//´Ó¶Ñ¶¥ÏòÏÂÅÅĞò
		JustDown(a, end, 0);
		--end;
	}

}

void JustDown(HPDataType* a, int n, int root) {
	int parent = root;
	int child = parent * 2 + 1;
	while (parent > 0) {
		if (a[parent] > a[child]) {
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void JustUp(HPDataType* a, int n) {
	int child = n - 1;
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

/*void TestHeap() {
	int i = 0;
	int a[] = { 0, 1};
	Heap hp;
	HeapPop(&hp);
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	TestHeap();
	system("pause");
	return 0;
}*/