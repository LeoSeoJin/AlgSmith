/*
 * alg_adt_maxheap.h
 *
 *  Created on: 2013-4-21
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGADT_HEAP_MAXHEAP_ALG_ADT_MAXHEAP_H_
#define ALGSMITH_ALGADT_HEAP_MAXHEAP_ALG_ADT_MAXHEAP_H_

#include "..\..\..\AlgObj\AlgSortObj\alg_sort_obj.h"
#include "..\alg_adt_heap.h"

class MaxHeap:public Heap{
 public:
  MaxHeap();
  virtual ~MaxHeap();

  virtual void MaxHeapify(int,int);
  virtual void BuildMaxHeap();

  virtual AlgSortObj* HeapMaximum();
  virtual void HeapExtractMax();
  virtual void MaxHeapInsert(AlgSortObj*);

  int Getlength() {return length;}

 protected:
  int length;
};

#endif // ALGSMITH_ALGADT_HEAP_MAXHEAP_ALG_ADT_MAXHEAP_H_
