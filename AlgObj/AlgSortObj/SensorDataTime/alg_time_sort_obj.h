/*
 * alg_time_sort_obj.h
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGOBJ_ALGSORTOBJ_TIMESORTOBJ_ALG_TIME_SORT_OBJ_H_
#define ALGSMITH_ALGOBJ_ALGSORTOBJ_TIMESORTOBJ_ALG_TIME_SORT_OBJ_H_

#include "..\alg_sort_obj.h"
#include "..\PQueueObj\alg_pqueue_obj.h"
#include "..\..\AlgAppObj\SensorData\alg_app_obj_Sensordata.h"

class SensorDataTime:public PQueueObj {
 public:
  SensorDataTime(AlgObj*);
  ~SensorDataTime();
  virtual int Compare(AlgSortObj*);
  virtual void Setkey(Time);
  virtual void Increasekey(Time);
  virtual void Decreasekey(Time);
  virtual void Getkey(Time&);
};

int CompareTime(Time,Time);
#endif // ALGSMITH_ALGOBJ_ALGSORTOBJ_TIMESORTOBJ_ALG_TIME_SORT_OBJ_H_
