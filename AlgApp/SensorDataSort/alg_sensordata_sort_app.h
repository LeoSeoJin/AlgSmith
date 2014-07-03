/*
 * alg_sensordata_sort_app.h
 *
 *  Created on: 2013-4-17
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGAPP_SENSORDATASORTAPP_ALG_SENSORDATA_SORT_APP_H_
#define ALGSMITH_ALGAPP_SENSORDATASORTAPP_ALG_SENSORDATA_SORT_APP_H_

#include "stdio.h"
#include <string>
#include <cstring>
#include <vector>

#include "..\alg_app.h"
#include "..\..\AlgObj\AlgSortObj\alg_sort_obj.h"
#include "..\..\AlgObj\AlgAppObj\SensorData\alg_app_obj_Sensordata.h"
#include "..\..\AlgObj\AlgSortObj\PQueueObj\alg_pqueue_obj.h"

class SensorDataSortApp: public AlgApp {
 public:
  SensorDataSortApp();
  virtual ~SensorDataSortApp();

  void InputData(char*);
  void OutputData(char*);
  void OutputData(vector<AlgSortObj*>&,char*);
  void OutputData(vector<PQueueObj*>&,char*);

  vector<AlgObj*>& Getvec_sensor_data() {return vec_sensor_data;}

 private:
  vector<AlgObj*> vec_sensor_data;
};

void OutputDouble(double,FILE*);
void OutputSensorData(SensorData*,FILE*);

#endif // ALGSMITH_ALGAPP_SENSORDATASORTAPP_ALG_SENSORDATA_SORT_APP_H_
