/*
 * alg_sort_obj_key.h
 *
 *  Created on: 2013-5-10
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGOBJ_ALGSORTOBJ_PQUEUEOBJ_ALG_PQUEUE_OBJ_H_
#define ALGSMITH_ALGOBJ_ALGSORTOBJ_PQUEUEOBJ_ALG_PQUEUE_OBJ_H_

#include "..\alg_sort_obj.h"
#include "..\..\AlgAppObj\SensorData\alg_app_obj_Sensordata.h"

class PQueueObj: public AlgSortObj {
 public:
  PQueueObj();
  PQueueObj(AlgObj*);
  virtual ~PQueueObj();

  virtual void Setkey(Date k) {}
  virtual void Setkey(Time k) {}
  virtual void Setkey(int k) {}
  virtual void Setkey(double k) {}

  virtual void Getkey(Date& t) {}
  virtual void Getkey(Time& t) {}
  virtual void Getkey(int& t) {}
  virtual void Getkey(double& t) {}

  virtual void Increasekey(Date k) {}
  virtual void Increasekey(Time k) {}
  virtual void Increasekey(int k) {}
  virtual void Increasekey(double k) {}

  virtual void Decreasekey(Date k) {}
  virtual void Decreasekey(Time k) {}
  virtual void Decreasekey(int k) {}
  virtual void Decreasekey(double k) {}
};

#endif //ALGSMITH_ALGOBJ_ALGSORTOBJ_PQUEUEOBJ_ALG_PQUEUE_OBJ_H_
