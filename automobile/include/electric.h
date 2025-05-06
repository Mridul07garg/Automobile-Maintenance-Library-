#pragma once
#include<iostream>
#include<automobile.h>
using namespace std;

class electricCar:public automobile{
    public:
    electricCar(string make,string model,int year,int odometerReading):
    automobile(make,model,year,odometerReading){}

    string getType() const override{
        return "Electric";
    }
};
