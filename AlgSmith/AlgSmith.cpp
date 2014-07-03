/*
 * alg_smith.cpp
 *
 *  Created on: 2013-4-15
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include "stdio.h"
#include "stdlib.h"
#include <string>

#include "AlgSmith.h"
#include "..\AlgApp\alg_app.h"
#include "..\Algorithms\algorithm.h"
#include "..\AlgApp\SensorDataSort\alg_sensordata_sort_app.h"
#include "..\AlgObj\AlgSortObj\alg_sort_obj.h"
#include "..\AlgObj\AlgSortObj\SensorDataDate\alg_date_sort_obj.h"
#include "..\AlgObj\AlgSortObj\SensorDataTime\alg_time_sort_obj.h"
#include "..\AlgObj\AlgSortObj\SensorDataEpoch\alg_epoch_sort_obj.h"
#include "..\AlgObj\AlgSortObj\SensorDataMoteid\alg_moteid_sort_obj.h"
#include "..\AlgObj\AlgSortObj\SensorDataTemperature\alg_temperature_sort_obj.h"
#include "..\AlgObj\AlgSortObj\SensorDataHumidity\alg_humidity_sort_obj.h"
#include "..\AlgObj\AlgSortObj\SensorDataLight\alg_light_sort_obj.h"
#include "..\AlgObj\AlgSortObj\SensorDataVoltage\alg_voltage_sort_obj.h"
#include "..\AlgObj\AlgAppObj\SensorData\alg_app_obj_Sensordata.h"
#include "..\AlgAdt\Heap\MaxHeap\VectorMaxHeap\alg_adt_vector_maxheap.h"
#include "..\AlgAdt\Heap\MinHeap\VectorMinHeap\alg_adt_vector_minheap.h"
#include "..\AlgAdt\HeapPQueue\alg_adt_heap_priority_queue.h"

int main() {
    char inf[] = "30.txt";
    char* infile = &inf[0];
    char outf[] = "f1.fea";
    char* f1 = &outf[0];
    char outf2[] = "f2.fea";
    char* f2 = &outf2[0];
    char outf3[] = "f3.fea";
    char* f3 = &outf3[0];
    char outf4[] = "f4.fea";
    char* f4 = &outf4[0];
    char outf5[] = "f5.fea";
    char* f5 = &outf5[0];

    AlgApp* alg_app = new SensorDataSortApp;
    SensorDataSortApp* app_sort = (SensorDataSortApp*)alg_app;
    app_sort->InputData(infile);

    /*sort by date*/
    vector<AlgSortObj*> vec_time_sorted;
    vector<AlgSortObj*> vec_date_sorted;
    vector<AlgSortObj*> vec_temperature_sorted;
    vector<PQueueObj*> pq_vec_time_sorted;
    vector<PQueueObj*> pq_vec_date_sorted;
    vector<PQueueObj*> pq_vec_temperature_sorted;
    vector<AlgObj*>::iterator p = app_sort->Getvec_sensor_data().begin();
    vector<AlgObj*>::iterator last = app_sort->Getvec_sensor_data().end();

    while (p != last) {
        vec_time_sorted.push_back(new SensorDataTime(*p));
        vec_date_sorted.push_back(new SensorDataDate(*p));
        vec_temperature_sorted.push_back(new SensorDataTemperature(*p));
        pq_vec_time_sorted.push_back(new SensorDataTime(*p));
        pq_vec_date_sorted.push_back(new SensorDataDate(*p));
        pq_vec_temperature_sorted.push_back(new SensorDataTemperature(*p));
        p++;
    }

    HeapSort(vec_date_sorted);
    app_sort->OutputData(vec_date_sorted,f1);
    for (vector<AlgSortObj*>::iterator i = vec_date_sorted.begin(); i != vec_date_sorted.end();i++) {
        AlgSortObj* temp = new SensorDataTime((*i)->Getobj());
        delete *i;
        *i = temp;
    }
    HeapSort(vec_date_sorted);
    app_sort->OutputData(vec_date_sorted,f2);

    HeapSort(vec_time_sorted);
    app_sort->OutputData(vec_time_sorted,f2);
    HeapSort(vec_temperature_sorted);
    app_sort->OutputData(vec_temperature_sorted,f3);


    HeapPQueue* dpq = new HeapPQueue(pq_vec_date_sorted);
    app_sort->OutputData(pq_vec_date_sorted,f4);
    Date k = {2004,1,11};
    dpq->DecreaseKey(pq_vec_date_sorted,(SensorDataDate*)pq_vec_date_sorted[3],3,k);
    app_sort->OutputData(pq_vec_date_sorted,f5);

    for (vector<AlgSortObj*>::iterator i = vec_time_sorted.begin(); i != vec_time_sorted.end();) {
        delete *i;
        i = vec_time_sorted.erase(i);
    }

    for (vector<AlgSortObj*>::iterator i = vec_date_sorted.begin(); i != vec_date_sorted.end();) {
        delete *i;
        i = vec_date_sorted.erase(i);
    }

    for (vector<AlgSortObj*>::iterator i = vec_temperature_sorted.begin(); i != vec_temperature_sorted.end();) {
        delete *i;
        i = vec_temperature_sorted.erase(i);
    }

    for (vector<PQueueObj*>::iterator i = pq_vec_time_sorted.begin(); i != pq_vec_time_sorted.end();) {
        delete *i;
        i = pq_vec_time_sorted.erase(i);
    }

    for (vector<PQueueObj*>::iterator i = pq_vec_date_sorted.begin(); i != pq_vec_date_sorted.end();) {
        delete *i;
        i = pq_vec_date_sorted.erase(i);
    }

    for (vector<PQueueObj*>::iterator i = pq_vec_temperature_sorted.begin(); i != pq_vec_temperature_sorted.end();) {
        delete *i;
        i = pq_vec_temperature_sorted.erase(i);
    }

    system("pause");
    return 0;
}

