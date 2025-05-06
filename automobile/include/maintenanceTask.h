#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class maintenanceTask{
    public:
        string taskName;
        string description;
        vector<string> applicableVehicleTypes;
    

        maintenanceTask(string taskName, string description, vector<string> applicableVehicleTypes)
        {
            this->taskName = taskName;
            this->description = description;
            this->applicableVehicleTypes = applicableVehicleTypes;
        }
    bool isApplicableToo(const string vehicleType)
    {
        if(find(applicableVehicleTypes.begin(),applicableVehicleTypes.end(),vehicleType) != applicableVehicleTypes.end())
           return true;
        else    
            return false;
    }

    bool operator==(const maintenanceTask& other) const {
        return taskName == other.taskName &&
               description == other.description &&
               applicableVehicleTypes == other.applicableVehicleTypes;
    }
};