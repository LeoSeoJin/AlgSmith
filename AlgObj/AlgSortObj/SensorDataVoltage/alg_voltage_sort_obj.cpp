/*
 * alg_voltage_sort_obj.cpp
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "alg_voltage_sort_obj.h"

SensorDataVoltage::SensorDataVoltage(AlgObj* p):PQueueObj(p) {
}

SensorDataVoltage::~SensorDataVoltage() {
}

int SensorDataVoltage::Compare(AlgSortObj* p) {
    SensorData* temp1 = (SensorData*)obj;
    SensorData* temp2 = (SensorData*)(p->Getobj());
    if (temp1->Getvoltage() > temp2->Getvoltage()) return 1;
    else if (temp1->Getvoltage() < temp2->Getvoltage()) return -1;
    else return 0;
}

void SensorDataVoltage::Setkey(double k) {
    ((SensorData*)obj)->Setvoltage(k);
}

void SensorDataVoltage::Increasekey(double k) {
    if (((SensorData*)obj)->Getvoltage() >= k) return;
    else Setkey(k);
}

void SensorDataVoltage::Decreasekey(double k) {
    if (((SensorData*)obj)->Getvoltage() <= k) return;
    else Setkey(k);
}

void SensorDataVoltage::Getkey(double& t) {
    t = ((SensorData*)obj)->Getvoltage();
}
