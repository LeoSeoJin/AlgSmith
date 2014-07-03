#include "alg_adt_heap_priority_queue.h"
#include "..\Heap\MinHeap\VectorMinHeap\alg_adt_vector_minheap.h"

#include "..\..\AlgApp\SensorDataSort\alg_sensordata_sort_app.h"

HeapPQueue::HeapPQueue(){
}

HeapPQueue::HeapPQueue(vector<PQueueObj*>& p) {
    heap_pqueue = new VectorMinHeap(p);
    heap_pqueue->BuildMinHeap();
    for (int i = 0; i < (int)p.size(); i++)
        p[i] = (PQueueObj*)(((VectorMinHeap*)heap_pqueue)->Getheap()[i]);
}

HeapPQueue::~HeapPQueue(){
}

void HeapPQueue::Insert(vector<PQueueObj*>& pq,PQueueObj* p){
    heap_pqueue->MinHeapInsert(p);
    for (int i = 0; i < heap_pqueue->Getlength(); i++)
        pq[i] = (PQueueObj*)(((VectorMinHeap*)heap_pqueue)->Getheap()[i]);
}

AlgSortObj* HeapPQueue::Minimum(){
    return heap_pqueue->HeapMinimum();
}

void HeapPQueue::DecreaseKey(vector<PQueueObj*>& pq,PQueueObj* p,int i,Date k) {
    p->Decreasekey(k);
    heap_pqueue->BuildMinHeap();
    for (int i = 0; i < heap_pqueue->Getlength(); i++)
        pq[i] = (PQueueObj*)(((VectorMinHeap*)heap_pqueue)->Getheap()[i]);
}

void HeapPQueue::GetPriority(PQueueObj* p,Date& k) {
    p->Getkey(k);
}
