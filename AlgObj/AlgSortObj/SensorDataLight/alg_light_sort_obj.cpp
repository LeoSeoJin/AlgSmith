/*
 * alg_light_sort_obj.cpp
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "alg_light_sort_obj.h"

SensorDataLight::SensorDataLight(AlgObj* p):PQueueObj(p) {
}

SensorDataLight::~SensorDataLight() {
}

int SensorDataLight::Compare(AlgSortObj* p) {
    SensorData* temp1 = (SensorData*)obj;
    SensorData* temp2 = (SensorData*)(p->Getobj());
    if (temp1->Getlight() > temp2->Getlight()) return 1;
    else if (temp1->Getlight() < temp2->Getlight()) return -1;
    else return 0;
}

void SensorDataLight::Setkey(double k) {
    ((SensorData*)obj)->Setlight(k);
}

void SensorDataLight::Decreasekey(double k) {
    if (((SensorData*)obj)->Getlight() <= k) return;
    else Setkey(k);
}

void SensorDataLight::Increasekey(double k) {
    if (((SensorData*)obj)->Getlight() >= k) return;
    else Setkey(k);
}

void SensorDataLight::Getkey(double& t) {
    t = ((SensorData*)obj)->Getlight();
}
