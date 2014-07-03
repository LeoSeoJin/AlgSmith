/*
 * alg_humidity_sort_obj.cpp
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "alg_humidity_sort_obj.h"

SensorDataHumidity::SensorDataHumidity(AlgObj* p):PQueueObj(p) {
}

SensorDataHumidity::~SensorDataHumidity() {
}

int SensorDataHumidity::Compare(AlgSortObj* p) {
    SensorData* temp1 = (SensorData*)obj;
    SensorData* temp2 = (SensorData*)(p->Getobj());
    if (temp1->Gethumidity() > temp2->Gethumidity()) return 1;
    else if (temp1->Gethumidity() < temp2->Gethumidity()) return -1;
    else return 0;
}

void SensorDataHumidity::Setkey(double k) {
    ((SensorData*)obj)->Sethumidity(k);
}

void SensorDataHumidity::Increasekey(double k) {
    if (((SensorData*)obj)->Gethumidity() >= k) return;
    else Setkey(k);
}

void SensorDataHumidity::Decreasekey(double k) {
    if (((SensorData*)obj)->Gethumidity() <= k) return;
    else Setkey(k);
}

void SensorDataHumidity::Getkey(double& t) {
    t = ((SensorData*)obj)->Gethumidity();
}
