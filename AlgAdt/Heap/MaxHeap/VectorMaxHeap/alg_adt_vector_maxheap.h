/*
 * alg_adt_vector_maxheap.h
 *
 *  Created on: 2013-4-21
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGADT_HEAP_MAXHEAP_VECTORMAXHEAP_ALG_ADT_VECTOR_MAXHEAP_H_
#define ALGSMITH_ALGADT_HEAP_MAXHEAP_VECTORMAXHEAP_ALG_ADT_VECTOR_MAXHEAP_H_

#include <vector>
#include "..\..\..\..\AlgObj\AlgSortObj\alg_sort_obj.h"
#include "..\alg_adt_maxheap.h"

using namespace std;

class VectorMaxHeap:public MaxHeap{
 public:
  VectorMaxHeap();
  VectorMaxHeap(vector<AlgSortObj*>&);
  ~VectorMaxHeap();

  void MaxHeapify(int,int);
  void BuildMaxHeap();

  AlgSortObj* HeapMaximum();
  void HeapExtractMax();
  void MaxHeapInsert(AlgSortObj*);

  vector<AlgSortObj*>& Getheap();

 private:
  vector<AlgSortObj*> heap;
};

#endif // ALGSMITH_ALGADT_HEAP_MAXHEAP_VECTORMAXHEAP_ALG_ADT_VECTOR_MAXHEAP_H_
