/*
 * alg_adt_vector_maxheap.cpp
 *
 *  Created on: 2013-4-21
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "stdio.h"
#include "alg_adt_vector_maxheap.h"

VectorMaxHeap::VectorMaxHeap(){
    length = 0;
}

VectorMaxHeap::VectorMaxHeap(vector<AlgSortObj*>& p) {
    for (int i = 0; i < (int)p.size(); i++)
        heap.push_back(p[i]);
    length = p.size();
}

VectorMaxHeap::~VectorMaxHeap() {
    for (vector<AlgSortObj*>::iterator i = heap.begin(); i != heap.end();) {
        delete *i;
        i = heap.erase(i);
    }
    length = 0;
}
void VectorMaxHeap::MaxHeapify(int start,int m) {
    int i = start;
    int j = 2 * i + 1;
    AlgSortObj* temp = heap[i];
    while (j <= m) {
        if (j < m && (heap[j]->Compare(heap[j+1])==-1)) j++;
        if (temp->Compare(heap[j]) >= 0) break;
        else {
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    heap[i] = temp;
}

void VectorMaxHeap::BuildMaxHeap() {
    for (int i = (length-2)/2; i >= 0; i--)
        MaxHeapify(i,length-1);
}

AlgSortObj* VectorMaxHeap::HeapMaximum() {
    return heap[0];
}

vector<AlgSortObj*>& VectorMaxHeap::Getheap() {
    return heap;
}

void VectorMaxHeap::HeapExtractMax() {
    heap.erase(heap.begin());
    length--;
    MaxHeapify(0,length-1);
}

void VectorMaxHeap::MaxHeapInsert(AlgSortObj* p) {
    int i = length;
    length++;
    heap.push_back(p);
    AlgSortObj* temp;
    while ( (i >= 0) && (heap[i]->Compare(heap[i/2])==1) ){
        temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i = i/2;
    }
}
