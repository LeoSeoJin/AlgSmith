/*
 * alg_sensordata_sort_app.cpp
 *
 *  Created on: 2013-4-17
 *      Author: Xue Jiang, xuejiang1225@gmail.com
 */

#include <stdlib.h>
#include <fstream>
#include <cmath>

#include "alg_sensordata_sort_app.h"
SensorDataSortApp::SensorDataSortApp() {
}

SensorDataSortApp::~SensorDataSortApp() {
    for (vector<AlgObj*>::iterator i = vec_sensor_data.begin(); i != vec_sensor_data.end(); i++)
        delete *i;
}

void SensorDataSortApp::InputData(char* infile) {
    int epoch,moteid;
    double temperature,humidity,light,voltage,seconds;
    int year,month,day,hour,minute;

    for (vector<AlgObj*>::iterator i = vec_sensor_data.begin(); i != vec_sensor_data.end(); i++)
        delete *i;

    ifstream fs;
    string line;
    char content[100];
    int space,pos;
    fs.open(infile);
    while (getline(fs,line)) {
        space = pos = moteid = 0;
        temperature = humidity = light = voltage = -1000.0;
        while (1) {
            pos = line.find(" ",pos);
            pos++;
            if (pos == 0) break;
            else space++;
        }
        char* str[space+1];
        for (int i = 0; i < (int)line.length(); i++)
            content[i] = line[i];
        content[line.length()] = '\0';

        for (int i = 0; i < space+1; i++) {
            if (i == 0)
                str[i] = strtok(content," ");
            else
                str[i] = strtok(NULL," ");
        }
        char* temp[3];
        for (int i = 0; i < 3; i++) {
            if (i == 0)
                temp[i] = strtok(str[0],"-");
            else
                temp[i] = strtok(NULL,"-");
        }
        year = atoi(temp[0]);
        month = atoi(temp[1]);
        day = atoi(temp[2]);
        for (int i = 0; i < 3; i++) {
            if (i == 0)
                temp[i] = strtok(str[1],":");
            else
                temp[i] = strtok(NULL,":");
        }
        hour = atoi(temp[0]);
        minute = atoi(temp[1]);
        seconds = atof(temp[2]);

        epoch = atoi(str[2]);
        if (space > 2) moteid = atoi(str[3]);
        if (space > 3) temperature = atof(str[4]);
        if (space > 4) humidity = atof(str[5]);
        if (space > 5) light = atof(str[6]);
        if (space > 6) voltage = atof(str[7]);

        AlgObj* t = new SensorData(year,month,day,hour,minute,seconds,epoch,moteid,temperature,humidity,light,voltage);
        vec_sensor_data.push_back(t);
    }
}

void SensorDataSortApp::OutputData(char* outfile) {
    FILE* f = fopen(outfile,"w");
    for (vector<AlgObj*>::iterator i = vec_sensor_data.begin(); i != vec_sensor_data.end(); i++) {
        SensorData* temp = (SensorData*)(*i);
        OutputSensorData(temp,f);
    }
    fclose(f);
}

void SensorDataSortApp::OutputData(vector<AlgSortObj*>& p,char* outfile) {
    FILE* f = fopen(outfile,"w");
    for (vector<AlgSortObj*>::iterator i = p.begin(); i != p.end(); i++) {
        SensorData* temp = (SensorData*)((*i)->Getobj());
        OutputSensorData(temp,f);
    }
    fclose(f);
}

void SensorDataSortApp::OutputData(vector<PQueueObj*>& p,char* outfile) {
    FILE* f = fopen(outfile,"w");
    for (vector<PQueueObj*>::iterator i = p.begin(); i != p.end(); i++) {
        SensorData* temp = (SensorData*)((*i)->Getobj());
        OutputSensorData(temp,f);
    }
    fclose(f);
}

void OutputDouble(double i,FILE* f) {
    if (fabs(i+1000.0) < 1e-6) return;
    int decimal, sign;
    char* buf;
    buf = fcvt(i, 10, &decimal, &sign);
    //gcvt(i,10,buf);
    //printf("len:%d  buf:%s\n",strlen(buf),buf);
    //printf("decimal:%d \n",decimal);
    if (decimal <= 0) {
        for (int j = fabs(decimal); j >= 0; j--) {
            for (int i = strlen(buf)-1; i > 0; i--)
                buf[i] = buf[i-1];
            buf[0] = '0';
        }
    }
    //for (int i = 0; i <= fabs(decimal); i++)
        //buf[i] = '0';
    //printf("buf2:%s\n",buf);
    //printf("%d  %s\n",decimal,buf);

    for (int i = (decimal > 0)?decimal:0; buf[i] != '\0'; i++) {
        if (buf[i] == '0') {
            int j = i + 1;
            for (; buf[j] != '\0'; j++)
                if (buf[j] != '0') break;
            if (buf[j] == '\0') {
                buf[i+1] = '\0';
                break;
            }
        }
    }
    //printf("%d   %d\n",decimal,strlen(buf));
    if (decimal != (int)(strlen(buf) - 1)) {
        if (decimal > 0) {
            for (int i = strlen(buf)-1; i > decimal; i--)
                buf[i] = buf[i-1];
            buf[decimal] = '.';
        }
        else {
            for (int i = strlen(buf)-1; i > 1; i--)
                buf[i] = buf[i-1];
            buf[1] = '.';
        }
    }

    else buf[decimal] = '\0';
    if (sign == 1) fprintf(f,"-");
    fprintf(f,"%s",buf);
}

void OutputSensorData(SensorData* p,FILE* f) {
    fprintf(f,"%d-%02d-%02d %02d:%02d:",p->Getdate().year,p->Getdate().month,p->Getdate().day,p->Gettime().hour,p->Gettime().minute);
    OutputDouble(p->Gettime().seconds,f);
    fprintf(f," %d ",p->Getepoch());
    if (p->Getmoteid() == 0) {fprintf(f,"\n");return;}
    fprintf(f,"%d ",p->Getmoteid());
    OutputDouble(p->Gettemperature(),f);
    fprintf(f," ");
    OutputDouble(p->Gethumidity(),f);
    fprintf(f," ");
    OutputDouble(p->Getlight(),f);
    fprintf(f," ");
    OutputDouble(p->Getvoltage(),f);
    fprintf(f,"\n");
}
