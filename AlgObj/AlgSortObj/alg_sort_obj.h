/*
 * alg_sort_obj.h
 *
 *  Created on: 2013-4-15
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGOBJ_ALGSORTOBJ_ALG_SORT_OBJ_H_
#define ALGSMITH_ALGOBJ_ALGSORTOBJ_ALG_SORT_OBJ_H_

#include "..\alg_obj.h"
#include "..\AlgAppObj\SensorData\alg_app_obj_sensordata.h"

class AlgSortObj: public AlgObj {
 public:
  AlgSortObj();
  AlgSortObj(AlgObj*);
  AlgSortObj(AlgSortObj*);
  ~AlgSortObj();
  AlgSortObj(const AlgSortObj&);
  AlgSortObj& operator = (const AlgSortObj&);
  AlgObj* Getobj() {return this->obj;}

  virtual int Compare(AlgSortObj*) {return 2;}

 protected:
  AlgObj* obj;
};

#endif // ALGSMITH_ALGOBJ_ALGSORTOBJ_ALG_SORT_OBJ_H_
