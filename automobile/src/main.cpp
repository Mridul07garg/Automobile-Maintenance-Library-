#include <iostream>
#include "electric.h"
#include "gascar.h"
#include "dieselcar.h"
#include "maintenanceTask.h"
#include "maintenanceLibrary.h"

int main() {
    // Create vehicles
    automobile* electric = new electricCar("Tesla", "Model 5", 2023,4500 );
    automobile* gas = new gasCar("Maruti", "Dzire", 2019, 30000);
    automobile* diesel = new dieselCar("Tata", "Nexon", 2022, 1500);

    // Create maintenance tasks
    maintenanceTask oilChange("Oil Change", "Change the engine oil", {"Electric", "Gas", "Diesel"});
    maintenanceTask brakeCheck("Brake Check", "Inspect and replace brake pads", {"Electric", "Gas", "Diesel"});
    maintenanceTask batteyryCheck("Battery Check", "Inspect battery health", {"Electric"});
    // Create the maintenance library and add vehicles
    maintenanceLibrary library;
    library.addVehicle(electric);
    library.addVehicle(gas);
    library.addVehicle(diesel);
    
    // Add tasks to vehicles
    library.addTask(gas, oilChange);
    library.addTask(gas, brakeCheck);   
    library.addTask(electric, oilChange);
    library.addTask(electric, brakeCheck);
    library.addTask(diesel, oilChange); 
    library.addTask(diesel, brakeCheck);
    library.addTask(electric, batteyryCheck); 
    library.addTask(diesel, batteyryCheck); 

    // Display vehicles and their tasks
    std::cout << "\n--- Maintenance List ---\n";
    library.allTasksandVehicles();

    // Remove a task
    cout << "\nRemoving task: " << brakeCheck.taskName << " from vehicle: " << gas->getMake() << " " << gas->getModel() << std::endl;
    library.removeTask(gas, brakeCheck);
    

    // Display updated list
    std::cout << "\n--- Updated Maintenance List ---\n";
    library.allTasksandVehicles();

    // Clean up heap memory
    delete electric;
    delete gas;
    delete diesel;

    return 0;
}
