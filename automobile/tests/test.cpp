#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "electric.h"
#include "gascar.h"
#include "dieselcar.h"
#include "maintenanceTask.h"
#include "maintenanceLibrary.h"

// Simple assertion macro
#define ASSERT_TRUE(condition, message) \
    if (!(condition)) { \
        std::cerr << "Test failed: " << message << std::endl; \
        return false; \
    }

#define ASSERT_FALSE(condition, message) ASSERT_TRUE(!(condition), message)

// Test adding vehicles to the library
bool TestAddVehicle() {
    try {
        maintenanceLibrary library;
        automobile* electric = new electricCar("Tesla", "Model S", 2023, 1200);

        library.addVehicle(electric);

        // Check if the vehicle was added
        std::ostringstream output;
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
        library.allVehicles();
        std::cout.rdbuf(oldCout);

        bool result = output.str().find("Tesla Model S 2023 Electric") != std::string::npos;
        ASSERT_TRUE(result, "Failed to add vehicle: Tesla Model S");

        delete electric;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Exception in TestAddVehicle: " << e.what() << std::endl;
        return false;
    }
}

// Test adding tasks to a vehicle
bool TestAddTask() {
    try {
        maintenanceLibrary library;
        automobile* gas = new gasCar("Toyota", "Corolla", 2020, 25000);
        maintenanceTask oilChange("Oil Change", "Change the engine oil", {"Gas", "Diesel"});

        library.addVehicle(gas);
        library.addTask(gas, oilChange);

        // Check if the task was added
        std::ostringstream output;
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
        library.allTasksandVehicles();
        std::cout.rdbuf(oldCout);

        bool result = output.str().find("Oil Change") != std::string::npos;
        ASSERT_TRUE(result, "Failed to add task: Oil Change");

        delete gas;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Exception in TestAddTask: " << e.what() << std::endl;
        return false;
    }
}

// Test removing a task from a vehicle
bool TestRemoveTask() {
    try {
        maintenanceLibrary library;
        automobile* diesel = new dieselCar("Ford", "F-250", 2018, 45000);
        maintenanceTask brakeCheck("Brake Check", "Inspect and replace brake pads", {"Electric", "Gas", "Diesel"});

        library.addVehicle(diesel);
        library.addTask(diesel, brakeCheck);
        library.removeTask(diesel, brakeCheck);

        // Check if the task was removed
        std::ostringstream output;
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
        library.allTasksandVehicles();
        std::cout.rdbuf(oldCout);

        bool result = output.str().find("Brake Check") == std::string::npos;
        ASSERT_TRUE(result, "Failed to remove task: Brake Check");

        delete diesel;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Exception in TestRemoveTask: " << e.what() << std::endl;
        return false;
    }
}

// Test removing a vehicle from the library
bool TestRemoveVehicle() {
    try {
        maintenanceLibrary library;
        automobile* electric = new electricCar("Tesla", "Model 3", 2022, 5000);

        library.addVehicle(electric);
        library.removeVehicle(electric);

        // Check if the vehicle was removed
        std::ostringstream output;
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
        library.allVehicles();
        std::cout.rdbuf(oldCout);

        bool result = output.str().find("Tesla Model 3") == std::string::npos;
        ASSERT_TRUE(result, "Failed to remove vehicle: Tesla Model 3");

        delete electric;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Exception in TestRemoveVehicle: " << e.what() << std::endl;
        return false;
    }
}

// Main function to run all tests
int main() {
    std::cout << "Running tests...\n";

    try {
        if (TestAddVehicle()) {
            std::cout << "TestAddVehicle passed.\n";
        }

        if (TestAddTask()) {
            std::cout << "TestAddTask passed.\n";
        }

        if (TestRemoveTask()) {
            std::cout << "TestRemoveTask passed.\n";
        }

        if (TestRemoveVehicle()) {
            std::cout << "TestRemoveVehicle passed.\n";
        }

        std::cout << "All tests completed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception in main: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred in main.\n";
    }

    return 0;
}