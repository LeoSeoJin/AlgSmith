/*
 * alg_time_sort_obj.cpp
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "stdio.h"
#include "alg_time_sort_obj.h"

SensorDataTime::SensorDataTime(AlgObj* p):PQueueObj(p) {
}

SensorDataTime::~SensorDataTime() {
}

void SensorDataTime::Setkey(Time k) {
    ((SensorData*)obj)->Settime(k);
}

void SensorDataTime::Increasekey(Time k) {
    if (CompareTime(((SensorData*)obj)->Gettime(),k) >= 0) return;
    else Setkey(k);
}

void SensorDataTime::Decreasekey(Time k) {
    if (CompareTime(((SensorData*)obj)->Gettime(),k) <= 0) return;
    else Setkey(k);
}

void SensorDataTime::Getkey(Time& t) {
    t.hour = ((SensorData*)obj)->Gettime().hour;
    t.minute = ((SensorData*)obj)->Gettime().minute;
    t.seconds = ((SensorData*)obj)->Gettime().seconds;
}

int SensorDataTime::Compare(AlgSortObj* p) {
    SensorData* temp1 = (SensorData*)obj;
    SensorData* temp2 = (SensorData*)(p->Getobj());
    int r = CompareTime(temp1->Gettime(),temp2->Gettime());
    return r;
}

int CompareTime(Time t1,Time t2) {
    if (t1.hour > t2.hour) return 1;
    else {
        if (t1.hour < t2.hour) return -1;
        else {
            if (t1.minute > t2.minute) return 1;
            else {
                if (t1.minute < t2.minute) return -1;
                else {
                    if (t1.seconds > t2.seconds) return 1;
                    else if (t1.seconds < t2.seconds) return -1;
                    else return 0;
                }
            }
        }
    }
}

