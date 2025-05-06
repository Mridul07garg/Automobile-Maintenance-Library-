#pragma once
#include<automobile.h>

class gasCar :public automobile{
    public:
    gasCar(string make,string model,int year,int odometerReading):
    automobile(make,model,year,odometerReading){}

    string getType() const override{
        return "Gas";
    }
};