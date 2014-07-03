/*
 * alg_moteid_sort_obj.cpp
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "alg_moteid_sort_obj.h"

SensorDataMoteid::SensorDataMoteid(AlgObj* p):PQueueObj(p) {
}

SensorDataMoteid::~SensorDataMoteid() {
}

int SensorDataMoteid::Compare(AlgSortObj* p) {
    SensorData* temp1 = (SensorData*)obj;
    SensorData* temp2 = (SensorData*)(p->Getobj());
    if (temp1->Getmoteid() > temp2->Getmoteid()) return 1;
    else if (temp1->Getmoteid() < temp2->Getmoteid()) return -1;
    else return 0;
}

void SensorDataMoteid::Setkey(int k) {
    ((SensorData*)obj)->Setmoteid(k);
}

void SensorDataMoteid::Increasekey(int k) {
    if (((SensorData*)obj)->Getmoteid() >= k) return;
    else Setkey(k);
}

void SensorDataMoteid::Decreasekey(int k) {
    if (((SensorData*)obj)->Getmoteid() <= k) return;
    else Setkey(k);
}

void SensorDataMoteid::Getkey(int& t) {
    t = ((SensorData*)obj)->Getmoteid();
}
