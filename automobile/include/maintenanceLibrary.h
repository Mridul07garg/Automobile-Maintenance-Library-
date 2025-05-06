#include<automobile.h>
#include<maintenanceTask.h>
#include<map>
#include<vector>
#include<string>

using namespace std;

class maintenanceLibrary{
    private: 
        vector<automobile*> vehicles;
        map<automobile*,vector<maintenanceTask>> tasks;
    
    public:
    void addVehicle(automobile* vehicle)
    {
        vehicles.push_back(vehicle);
    }

    void removeVehicle(automobile* vehicle)
    {
        auto it = find(vehicles.begin(), vehicles.end(), vehicle);
        if (it != vehicles.end()) 
        {
            vehicles.erase(it);
        }
        tasks.erase(vehicle);
    }

    void allVehicles()
    {
        for(auto vehicle : vehicles)
        {
            cout << vehicle->getMake() <<" "<<vehicle->getModel()<<" "<<vehicle->getYear()<<" "<<vehicle->getType() << endl;
        }
    }

    void allTasksandVehicles()
    {
        for(auto vehicle : vehicles)
        {
            cout << vehicle->getMake() <<" "<<vehicle->getModel()<<" "<<vehicle->getYear()<<" "<<vehicle->getType() << endl;
            cout << "Tasks: " << endl;
            for(auto task : tasks[vehicle])
            {
                cout << task.taskName << endl;
            }
            cout << endl;
        }
    }
    void addTask(automobile* vehicle, maintenanceTask task)
    {
        if(task.isApplicableToo(vehicle->getType()))
        {
            if(find(vehicles.begin(), vehicles.end(), vehicle) != vehicles.end())
            {
                tasks[vehicle].push_back(task);
            }
        } 
        else {
            cout << task.taskName <<" is not applicable "<<" to "<<vehicle->getType()<<" vehicle type." << endl;
            return;
        }
    }

    void removeTask(automobile* vehicle, maintenanceTask task){
        if(find(vehicles.begin(), vehicles.end(), vehicle) != vehicles.end())
        {
            auto it = find(tasks[vehicle].begin(), tasks[vehicle].end(), task);
            if(it != tasks[vehicle].end())
            {
                tasks[vehicle].erase(it);
            }
            else
            {
                cout << "Task not found for this vehicle." << endl;
            }
        }
        else
        {
            cout << "Vehicle not found." << endl;
        }   
    }

    void allTasks(automobile* vehicle)
    {
        if(find(vehicles.begin(), vehicles.end(), vehicle) != vehicles.end())
        {
            cout << "Tasks for " << vehicle->getMake() <<" "<<vehicle->getModel()<<" "<<vehicle->getYear()<<" "<<vehicle->getType() << endl;
            for(auto task : tasks[vehicle])
            {
                cout << task.taskName << endl;
            }
        }
        else
        {
            cout << "Vehicle not found." << endl;
        }   
    }

};