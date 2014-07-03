#ifndef ALGSMITH_ALGORITHMS_ALGORITHM_H_
#define ALGSMITH_ALGORITHMS_ALGORITHM_H_

#include <vector>
#include "..\AlgObj\AlgSortObj\alg_sort_obj.h"
#include "..\AlgAdt\Heap\MaxHeap\VectorMaxHeap\alg_adt_vector_maxheap.h"

void HeapSort(vector<AlgSortObj*>& p) {
    VectorMaxHeap* h = new VectorMaxHeap(p);
    h->BuildMaxHeap();
    for (int i = p.size() - 1; i >= 0; i--) {
        AlgSortObj* temp = h->Getheap()[0];
        h->Getheap()[0] = h->Getheap()[i];
        h->Getheap()[i] = temp;
        h->MaxHeapify(0,i-1);
    }
    for (int i = 0; i < (int)p.size(); i++)
        p[i] = h->Getheap()[i];
}


#endif // ALGSMITH_ALGORITHMS_ALGORITHM_H_
