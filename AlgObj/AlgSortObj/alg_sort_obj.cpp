/*
 * alg_sort_obj.cpp
 *
 *  Created on: 2013-4-15
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "stdio.h"
#include "alg_sort_obj.h"
#include "..\alg_obj.h"
#include "..\AlgAppObj\SensorData\alg_app_obj_Sensordata.h"
using namespace std;

AlgSortObj::AlgSortObj() {
    obj = NULL;
}

AlgSortObj::AlgSortObj(AlgObj* a) {
    this->obj = new SensorData(*(SensorData*)a);
}

AlgSortObj::AlgSortObj(AlgSortObj* p) {
    this->obj = new SensorData(*(SensorData*)(p->Getobj()));
}

AlgSortObj::~AlgSortObj() {
    delete obj;
    obj = NULL;
}

AlgSortObj::AlgSortObj(const AlgSortObj& a) {
    this->obj = new SensorData(*((SensorData*)a.obj));
}

AlgSortObj& AlgSortObj:: operator = (const AlgSortObj& a) {
    delete this->obj;
    this->obj = new SensorData(*((SensorData*)a.obj));
    return *this;
}
