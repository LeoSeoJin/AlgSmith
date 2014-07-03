/*
 * alg_adt_minheap.h
 *
 *  Created on: 2013-4-21
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGADT_HEAP_MINHEAP_ALG_ADT_MINHEAP_H_
#define ALGSMITH_ALGADT_HEAP_MINHEAP_ALG_ADT_MINHEAP_H_

#include "..\alg_adt_heap.h"
#include "..\..\..\AlgObj\AlgSortObj\alg_sort_obj.h"

class MinHeap: public Heap {
 public:
  MinHeap();
  virtual ~MinHeap();

  virtual void MinHeapify(int,int);
  virtual void BuildMinHeap();

  virtual AlgSortObj* HeapMinimum();
  virtual void HeapExtractMin();
  virtual void MinHeapInsert(AlgSortObj*);

  int Getlength() {return length;}

 protected:
  int length;
};


#endif // ALGSMITH_ALGADT_HEAP_MINHEAP_ALG_ADT_MINHEAP_H_
