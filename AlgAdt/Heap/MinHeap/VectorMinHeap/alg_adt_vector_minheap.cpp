/*
 * alg_adt_vector_minheap.cpp
 *
 *  Created on: 2013-4-21
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "alg_adt_vector_minheap.h"

#include "stdio.h"

VectorMinHeap::VectorMinHeap() {
    length = 0;
}

VectorMinHeap::VectorMinHeap(vector<AlgSortObj*>& p) {
    for (int i = 0; i < (int)p.size(); i++)
         heap.push_back(p[i]);
    length = p.size();
}

VectorMinHeap::VectorMinHeap(vector<PQueueObj*>& p) {
    for (int i = 0; i < (int)p.size(); i++)
         heap.push_back(p[i]);
    length = p.size();
}

VectorMinHeap::~VectorMinHeap() {
    for (vector<AlgSortObj*>::iterator i = heap.begin(); i != heap.end();) {
        delete *i;
        i = heap.erase(i);
    }
    length = 0;
}

void VectorMinHeap::MinHeapify(int start,int m) {
    int i = start;
    int j = 2 * i + 1;
    AlgSortObj* temp = heap[i];
    while (j <= m) {
        if (j < m && (heap[j]->Compare(heap[j+1])==1)) j++;
        if (temp->Compare(heap[j]) <= 0) break;
        else {
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    heap[i] = temp;
}

void VectorMinHeap::BuildMinHeap() {
    for (int i = (length-2)/2; i >= 0; i--)
        MinHeapify(i,length-1);
}

AlgSortObj* VectorMinHeap::HeapMinimum() {
    return heap[0];
}

vector<AlgSortObj*>& VectorMinHeap::Getheap() {
    return heap;
}

void VectorMinHeap::HeapExtractMin() {
    heap.erase(heap.begin());
    length--;
    MinHeapify(0,length-1);
}

void VectorMinHeap::MinHeapInsert(AlgSortObj* p) {
    int i = length;
    length++;
    heap.push_back(p);
    AlgSortObj* temp;
    while ( (i >= 0) && (heap[i]->Compare(heap[i/2])==-1) ){
        temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i = i/2;
    }
}


