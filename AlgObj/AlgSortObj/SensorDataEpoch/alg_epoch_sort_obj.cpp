/*
 * alg_epoch_sort_obj.cpp
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "alg_epoch_sort_obj.h"

SensorDataEpoch::SensorDataEpoch(AlgObj* p):PQueueObj(p) {
}

SensorDataEpoch::~SensorDataEpoch() {
}

int SensorDataEpoch::Compare(AlgSortObj* p) {
    SensorData* temp1 = (SensorData*)obj;
    SensorData* temp2 = (SensorData*)(p->Getobj());
    if (temp1->Getepoch() > temp2->Getepoch()) return 1;
    else if (temp1->Getepoch() < temp2->Getepoch()) return -1;
    else return 0;
}

void SensorDataEpoch::Setkey(int k) {
    ((SensorData*)obj)->Setepoch(k);
}

void SensorDataEpoch::Increasekey(int k) {
    if (((SensorData*)obj)->Getepoch() >= k) return;
    else Setkey(k);
}

void SensorDataEpoch::Decreasekey(int k) {
    if (((SensorData*)obj)->Getepoch() <= k) return;
    else Setkey(k);
}

void SensorDataEpoch::Getkey(int& t) {
    t = ((SensorData*)obj)->Getepoch();
}
