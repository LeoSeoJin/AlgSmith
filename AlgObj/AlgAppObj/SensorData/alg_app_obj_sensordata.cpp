/*
 * alg_app_obj_sensordata.cpp
 *
 *  Created on: 2013-4-17
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include <cstdlib>
#include "alg_app_obj_sensordata.h"

SensorData::SensorData() {
    date.day = 0;
    date.year = 0;
    date.month = 0;
    time.hour = 0;
    time.minute = 0;
    time.seconds = 0;
    epoch = 0;
    moteid = 0;
    temperature = 0;
    humidity = 0;
    light = 0;
    voltage = 0;
}

SensorData::~SensorData() {
    date.day = 0;
    date.year = 0;
    date.month = 0;
    time.hour = 0;
    time.minute = 0;
    time.seconds = 0;
    epoch = 0;
    moteid = 0;
    temperature = 0;
    humidity = 0;
    light = 0;
    voltage = 0;
}

SensorData::SensorData(int y,int m,int d,int h,int mi,
                                 double sec,int e,int mo,double te,
                                 double hu,double l,double v) {
    date.year = y;
    date.month = m;
    date.day = d;
    time.hour = h;
    time.minute = mi;
    time.seconds = sec;
    epoch = e;
    moteid = mo;
    temperature = te;
    humidity = hu;
    light = l;
    voltage = v;
}

SensorData::SensorData(Date d,Time t,int e,int m,double te,double h,double l,double v) {
    date.year = d.year;
    date.month = d.month;
    date.day = d.day;
    time.hour = t.hour;
    time.minute = t.minute;
    time.seconds = t.seconds;
    epoch = e;
    moteid = m;
    temperature = te;
    humidity = h;
    light = l;
    voltage = v;
}

SensorData::SensorData(const SensorData& a) {
    date.year = a.date.year;
    date.month = a.date.month;
    date.day = a.date.day;
    time.hour = a.time.hour;
    time.minute = a.time.minute;
    time.seconds = a.time.seconds;
    epoch = a.epoch;
    moteid = a.moteid;
    temperature = a.temperature;
    humidity = a.humidity;
    light = a.light;
    voltage = a.voltage;
}

