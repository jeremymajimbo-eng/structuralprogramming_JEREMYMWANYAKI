#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// ======================================================
// ABSTRACT BASE CLASS
// Demonstrates abstraction and polymorphism
// ======================================================

class CityArea {
protected:
    int areaID;
    string areaName;
    int population;
    float pollutionLevel;

public:

    // Constructor
    CityArea(int id, string name, int pop, float pollution) {
        areaID = id;
        areaName = name;
        population = pop;
        pollutionLevel = pollution;
    }

    // Pure virtual function (Abstract Class)
    virtual void displayInfo() = 0;

    // Getter methods
    int getID() {
        return areaID;
    }

    string getName() {
        return areaName;
    }

    float getPollution() {
        return pollutionLevel;
    }

    // Virtual Destructor
    virtual ~CityArea() {

    }
};

// ======================================================
// DERIVED CLASS
// Demonstrates inheritance and overriding
// ======================================================

class SmartZone : public CityArea {

private:
    int trafficLevel;
    int hospitals;
    int schools;

public:

    // Constructor
    SmartZone(int id, string name, int pop,
              float pollution, int traffic,
              int hosp, int sch)
        : CityArea(id, name, pop, pollution) {

        trafficLevel = traffic;
        hospitals = hosp;
        schools = sch;
    }

    // Overridden function (Runtime Polymorphism)
    void displayInfo() override {

        cout << "\n====================================";
        cout << "\nSMART CITY AREA INFORMATION";
        cout << "\n====================================";

        cout << "\nArea ID: " << areaID;
        cout << "\nArea Name: " << areaName;
        cout << "\nPopulation: " << population;
        cout << "\nPollution Level: " << pollutionLevel;
        cout << "\nTraffic Level: " << trafficLevel;
        cout << "\nHospitals: " << hospitals;
        cout << "\nSchools: " << schools;

        // Control structures
        if (trafficLevel > 80) {
            cout << "\nTraffic Status: HIGH CONGESTION";
        }
        else if (trafficLevel >= 50) {
            cout << "\nTraffic Status: MODERATE";
        }
        else {
            cout << "\nTraffic Status: LOW";
        }

        // Relational operators
        if (pollutionLevel > 70) {
            cout << "\nEnvironmental Status: POLLUTION WARNING";
        }
        else {
            cout << "\nEnvironmental Status: SAFE";
        }

        cout << "\n====================================\n";
    }

    // Method Overloading
    void calculateDevelopmentIndex() {

        float index =
            (100 - pollutionLevel) +
            (100 - trafficLevel);

        cout << "\nDevelopment Index: " << index;
    }

    // Overloaded method
    void calculateDevelopmentIndex(float bonus) {

        float index =
            (100 - pollutionLevel) +
            (100 - trafficLevel) + bonus;

        cout << "\nDevelopment Index with Bonus: "
             << index;
    }

    // Destructor
    ~SmartZone() {

    }
};

// ======================================================
// SMART CITY MANAGEMENT SYSTEM
// Encapsulation demonstrated
// ======================================================

class SmartCitySystem {

private:

    // Vector from C++ Class Library
    vector<SmartZone> areas;

public:

    // Add area
    void addArea(SmartZone zone) {
        areas.push_back(zone);
    }

    // Display all areas
    void displayAllAreas() {

        if (areas.empty()) {
            cout << "\nNo areas available.\n";
            return;
        }

        for (int i = 0; i < areas.size(); i++) {
            areas[i].displayInfo();
        }
    }

    // Search area using ID
    void searchArea(int id) {

        bool found = false;

        for (int i = 0; i < areas.size(); i++) {

            if (areas[i].getID() == id) {

                areas[i].displayInfo();

                // Calling overloaded methods
                areas[i].calculateDevelopmentIndex();
                areas[i].calculateDevelopmentIndex(20);

                found = true;
            }
        }

        // Exception Handling
        if (!found) {
            throw runtime_error(
                "ERROR: Area ID not found!"
            );
        }
    }

    // Save report to file
    void saveToFile() {

        ofstream file("SmartCityReport.txt");

        if (!file) {
            cout << "\nFile could not be opened.\n";
            return;
        }

        file << "SMART CITY REPORT\n";
        file << "========================\n";

        for (int i = 0; i < areas.size(); i++) {

            file << "Area ID: "
                 << areas[i].getID() << endl;

            file << "Area Name: "
                 << areas[i].getName() << endl;

            file << "-------------------------\n";
        }

        file.close();

        cout << "\nReport saved successfully.\n";
    }
};

// ======================================================
// MAIN FUNCTION
// ======================================================

int main() {

    SmartCitySystem city;

    // Arrays and Strings
    string names[5] = {
        "CBD",
        "Westlands",
        "Industrial Area",
        "Karen",
        "Eastleigh"
    };

    // Adding areas
    city.addArea(
        SmartZone(1, names[0], 500000,
        75.5, 90, 5, 10)
    );

    city.addArea(
        SmartZone(2, names[1], 300000,
        40.2, 55, 4, 8)
    );

    city.addArea(
        SmartZone(3, names[2], 450000,
        88.7, 95, 2, 5)
    );

    city.addArea(
        SmartZone(4, names[3], 150000,
        20.5, 30, 6, 9)
    );

    city.addArea(
        SmartZone(5, names[4], 350000,
        65.1, 70, 3, 6)
    );

    int choice;
    int searchID;

    do {

        cout << "\n====================================";
        cout << "\n SMART CITY & URBAN PLANNING SYSTEM";
        cout << "\n====================================";

        cout << "\n1. Display All Areas";
        cout << "\n2. Search Area by ID";
        cout << "\n3. Save Report to File";
        cout << "\n4. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            city.displayAllAreas();
            break;

        case 2:

            cout << "\nEnter Area ID: ";
            cin >> searchID;

            try {
                city.searchArea(searchID);
            }

            catch(exception &e) {
                cout << "\n" << e.what() << endl;
            }

            break;

        case 3:
            city.saveToFile();
            break;

        case 4:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}
