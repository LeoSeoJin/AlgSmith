#ifndef ALGSMITH_ALGADT_HEAPPRIORITYQUEUE_ALG_ADT_HEAP_PRIORITY_QUEUE_H_
#define ALGSMITH_ALGADT_HEAPPRIORITYQUEUE_ALG_ADT_HEAP_PRIORITY_QUEUE_H_

#include <vector>
#include "..\Heap\MinHeap\alg_adt_minheap.h"
#include "..\Heap\MinHeap\VectorMinHeap\alg_adt_vector_minheap.h"
#include "..\..\AlgObj\AlgSortObj\PQueueObj\alg_pqueue_obj.h"
using namespace std;

class HeapPQueue{
 public:
  HeapPQueue();
  HeapPQueue(vector<PQueueObj*>&);
  virtual ~HeapPQueue();

  void Insert(vector<PQueueObj*>&,PQueueObj* p);
  AlgSortObj* Minimum();
  void DecreaseKey(vector<PQueueObj*>&,PQueueObj*,int,Date);
  void GetPriority(PQueueObj*,Date&);

 protected:
  //VectorMinHeap* heap_pqueue;
  MinHeap* heap_pqueue;
};


#endif // ALGSMITH_ALGADT_HEAPPRIORITYQUEUE_ALG_ADT_HEAP_PRIORITY_QUEUE_H_
