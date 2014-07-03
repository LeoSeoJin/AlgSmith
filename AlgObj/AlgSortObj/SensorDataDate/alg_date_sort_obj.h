/*
 * alg_date_sort_obj.h
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGOBJ_ALGSORTOBJ_DATESORTOBJ_ALG_DATE_SORT_OBJ_H_
#define ALGSMITH_ALGOBJ_ALGSORTOBJ_DATESORTOBJ_ALG_DATE_SORT_OBJ_H_

#include "..\alg_sort_obj.h"
#include "..\PQueueObj\alg_pqueue_obj.h"
#include "..\..\AlgAppObj\SensorData\alg_app_obj_Sensordata.h"

class SensorDataDate:public PQueueObj{
 public:
  SensorDataDate(AlgObj*);
  ~SensorDataDate();
  virtual int Compare(AlgSortObj*);
  virtual void Setkey(Date);
  virtual void Increasekey(Date);
  virtual void Decreasekey(Date);
  virtual void Getkey(Date&);
};

int CompareDate(Date,Date);
#endif // ALGSMITH_ALGOBJ_ALGSORTOBJ_DATESORTOBJ_ALG_DATE_SORT_OBJ_H_
