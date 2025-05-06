#pragma once
#include<automobile.h>
using namespace std;

class dieselCar:public automobile{
    public:
    dieselCar(string make,string model,int year,int odometerReading):
    automobile(make,model,year,odometerReading){}

    string getType() const override{
        return "Diesel";
    }
};