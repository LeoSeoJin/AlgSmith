/*
 * alg_adt_vector_minheap.h
 *
 *  Created on: 2013-4-21
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGADT_HEAP_MINHEAP_VECTORMINHEAP_ALG_ADT_VECTOR_MINHEAP_H_
#define ALGSMITH_ALGADT_HEAP_MINHEAP_VECTORMINHEAP_ALG_ADT_VECTOR_MINHEAP_H_

#include <vector>
#include "..\..\..\..\AlgObj\AlgSortObj\alg_sort_obj.h"
#include "..\alg_adt_minheap.h"
#include "..\..\..\..\AlgObj\AlgSortObj\PQueueObj\alg_pqueue_obj.h"

using namespace std;

class VectorMinHeap:public MinHeap{
 public:
  VectorMinHeap();
  VectorMinHeap(vector<AlgSortObj*>&);
  VectorMinHeap(vector<PQueueObj*>&);
  ~VectorMinHeap();

  void MinHeapify(int,int);
  void BuildMinHeap();

  AlgSortObj* HeapMinimum();
  void HeapExtractMin();
  void MinHeapInsert(AlgSortObj*);

  vector<AlgSortObj*> & Getheap();

 private:
  vector<AlgSortObj*> heap;
};

#endif // ALGSMITH_ALGADT_HEAP_MINHEAP_VECTORMINHEAP_ALG_ADT_VECTOR_MINHEAP_H_
