/*
 * alg_epoch_sort_obj.h
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGOBJ_ALGSORTOBJ_EPOCHSORTOBJ_ALG_EPOCH_SORT_OBJ_H_
#define ALGSMITH_ALGOBJ_ALGSORTOBJ_EPOCHSORTOBJ_ALG_EPOCH_SORT_OBJ_H_

#include "..\alg_sort_obj.h"
#include "..\PQueueObj\alg_pqueue_obj.h"

class SensorDataEpoch:public PQueueObj{
 public:
  SensorDataEpoch(AlgObj*);
  ~SensorDataEpoch();
  virtual int Compare(AlgSortObj*);
  virtual void Setkey(int);
  virtual void Increasekey(int);
  virtual void Decreasekey(int);
  virtual void Getkey(int&);
};

#endif // ALGSMITH_ALGOBJ_ALGSORTOBJ_EPOCHSORTOBJ_ALG_EPOCH_SORT_OBJ_H_
