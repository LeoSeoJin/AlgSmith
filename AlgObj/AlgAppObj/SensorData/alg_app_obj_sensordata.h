/*
 * alg_app_obj_sensordata.h
 *
 *  Created on: 2013-4-17
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#ifndef ALGSMITH_ALGOBJ_ALGAPPOBJ_SENSORDATA_ALG_APP_OBJ_SENSORDATA_H_
#define ALGSMITH_ALGOBJ_ALGAPPOBJ_SENSORDATA_ALG_APP_OBJ_SENSORDATA_H_

#include "stdio.h"
#include "..\alg_app_obj.h"

struct Date {
    int year;
    int month;
    int day;
};

struct Time {
    int hour;
    int minute;
    double seconds;
};

class SensorData: public AlgAppObj {
 public:
  SensorData();
  ~SensorData();
  SensorData(int,int,int,int,int,double,int,int,double,double,double,double);
  SensorData(Date,Time,int,int,double,double,double,double);
  SensorData(const SensorData&);

  Date Getdate() {return date;}
  Time Gettime() {return time;}
  int Getepoch() {return epoch;}
  int Getmoteid() {return moteid;}
  double Gettemperature() {return temperature;}
  double Gethumidity() {return humidity;}
  double Getlight() {return light;}
  double Getvoltage() {return voltage;}

  void Setdate(Date k) {date.year = k.year;date.month = k.month;date.day = k.day;}
  void Settime(Time k) {time.hour = k.hour;time.minute = k.minute;time.seconds = k.seconds;}
  void Setepoch(int k) {epoch = k;}
  void Setmoteid(int k) {moteid = k;}
  void Settemperature(double k) {temperature = k;}
  void Sethumidity(double k) {humidity = k;}
  void Setlight(double k) {light = k;}
  void Setvoltage(double k) {voltage = k;}

 private:
  Date date;
  Time time;
  int epoch;
  int moteid;
  double temperature;
  double humidity;
  double light;
  double voltage;
};

#endif // ALGSMITH_ALGOBJ_ALGAPPOBJ_SENSORDATA_ALG_APP_OBJ_SENSORDATA_H_
