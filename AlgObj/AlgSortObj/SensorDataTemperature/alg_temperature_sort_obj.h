/*
 * alg_temperature_sort_obj.h
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGOBJ_ALGSORTOBJ_TEMPERATURESORTOBJ_ALG_TEMPERATURE_SORT_OBJ_H_
#define ALGSMITH_ALGOBJ_ALGSORTOBJ_TEMPERATURESORTOBJ_ALG_TEMPERATURE_SORT_OBJ_H_

#include "..\alg_sort_obj.h"
#include "..\PQueueObj\alg_pqueue_obj.h"

class SensorDataTemperature:public PQueueObj {
 public:
  SensorDataTemperature(AlgObj*);
  ~SensorDataTemperature();
  virtual int Compare(AlgSortObj*);
  virtual void Setkey(double);
  virtual void Increasekey(double);
  virtual void Decreasekey(double);
  virtual void Getkey(double&);
};

#endif // ALGSMITH_ALGOBJ_ALGSORTOBJ_TEMPERATURESORTOBJ_ALG_TEMPERATURE_SORT_OBJ_H_
#ifndef ALG_TEMPERATURE_SORT_OBJ_H_INCLUDED
#define ALG_TEMPERATURE_SORT_OBJ_H_INCLUDED



#endif // ALG_TEMPERATURE_SORT_OBJ_H_INCLUDED
