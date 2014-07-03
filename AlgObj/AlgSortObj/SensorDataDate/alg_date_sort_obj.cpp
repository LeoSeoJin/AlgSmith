/*
 * alg_date_sort_obj.cpp
 *
 *  Created on: 2013-4-16
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "alg_date_sort_obj.h"
#include "stdio.h"

SensorDataDate::SensorDataDate(AlgObj* p):PQueueObj(p) {
}

SensorDataDate::~SensorDataDate() {
}
int SensorDataDate::Compare(AlgSortObj* p) {
    SensorData* temp1 = (SensorData*)obj;
    SensorData* temp2 = (SensorData*)(p->Getobj());
    int r = CompareDate(temp1->Getdate(),temp2->Getdate());
    return r;
}

void SensorDataDate::Setkey(Date k) {
    ((SensorData*)obj)->Setdate(k);
}

void SensorDataDate::Increasekey(Date k) {
    if (CompareDate(((SensorData*)obj)->Getdate(),k) >= 0) return;
    else Setkey(k);
}

void SensorDataDate::Decreasekey(Date k) {
    printf("1111\n");
    if (CompareDate(((SensorData*)obj)->Getdate(),k) <= 0) return;
    else Setkey(k);
}

void SensorDataDate::Getkey(Date& t) {
    t.year = ((SensorData*)obj)->Getdate().year;
    t.month = ((SensorData*)obj)->Getdate().month;
    t.day = ((SensorData*)obj)->Getdate().day;
}

int CompareDate(Date t1,Date t2) {
    if (t1.year > t2.year) return 1;
    else {
        if (t1.year < t2.year) return -1;
        else {
            if (t1.month > t2.month) return 1;
            else {
                if (t1.month < t2.month) return -1;
                else {
                    if (t1.day > t2.day) return 1;
                    else if (t1.day < t2.day) return -1;
                    else return 0;
                }
            }
        }
    }
}
