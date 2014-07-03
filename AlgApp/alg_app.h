/*
 * alg_app.h
 *
 *  Created on: 2013-4-15
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGAPP_ALG_APP_H_
#define ALGSMITH_ALGAPP_ALG_APP_H_

#include "stdio.h"
#include <string>
#include <cstring>
#include <vector>
#include "..\AlgSmith\AlgSmith.h"
#include "..\AlgObj\alg_obj.h"
#include "..\AlgObj\AlgSortObj\alg_sort_obj.h"
#include "..\AlgObj\AlgAppObj\SensorData\alg_app_obj_Sensordata.h"
using namespace std;

class AlgApp: public AlgSmith {
 public:
  AlgApp();
  virtual ~AlgApp();
};
#endif //ALGSMITH_ALGAPP_ALG_APP_H_
