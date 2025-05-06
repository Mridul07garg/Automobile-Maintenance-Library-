#include<iostream>
#pragma once
using namespace std;

class automobile{
    protected:
        string make;
        string model;
        int year;
        int odometerReading;
    
    public:
        automobile(string make,string model,int year,int odometerReading)
        {
            this->make = make;
            this->model = model;
            this->year = year;
            this->odometerReading = odometerReading;
        }

        virtual std::string getType() const = 0;
        
        string getMake()
        {
            return make;
        }

        string getModel()
        {
            return model;
        }

        int getYear()
        {
            return year;
        }

        int getOdometerReading()
        {
            return odometerReading;
        }
};