/*
 * alg_temperature_sort_obj.cpp
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "alg_temperature_sort_obj.h"

SensorDataTemperature::SensorDataTemperature(AlgObj* p):PQueueObj(p) {
}

SensorDataTemperature::~SensorDataTemperature() {
}

int SensorDataTemperature::Compare(AlgSortObj* p) {
    SensorData* temp1 = (SensorData*)obj;
    SensorData* temp2 = (SensorData*)(p->Getobj());
    if (temp1->Gettemperature() > temp2->Gettemperature()) return 1;
    else if (temp1->Gettemperature() < temp2->Gettemperature()) return -1;
    else return 0;
}

void SensorDataTemperature::Setkey(double k) {
    ((SensorData*)obj)->Settemperature(k);
}

void SensorDataTemperature::Increasekey(double k) {
    if (((SensorData*)obj)->Gettemperature() >= k) return;
    else Setkey(k);
}

void SensorDataTemperature::Decreasekey(double k) {
    if (((SensorData*)obj)->Gettemperature() <= k) return;
    else Setkey(k);
}

void SensorDataTemperature::Getkey(double& t) {
    printf("222\n");
    t = ((SensorData*)obj)->Gettemperature();
}
