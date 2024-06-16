#include <bits/stdc++.h>

using namespace std;

class StaffInfo {
private:
    struct Employee {
        string fullName;
        string contactNumber;
        string jobPosition;
        int daysOfDuty;
    };

public:
    map<int, Employee> staffMap;
    int nextEmployeeID;
    StaffInfo() : nextEmployeeID(1) {
        staffMap[nextEmployeeID++] = {"Rahul Kumar", "9876543210", "Manager", 25};
        staffMap[nextEmployeeID++] = {"Priya Sharma", "9988776655", "Assistant", 23};
        staffMap[nextEmployeeID++] = {"Amit Singh", "9876543210", "Assistant", 26};
        staffMap[nextEmployeeID++] = {"Riya Patel", "9988776655", "Manager", 24};
        staffMap[nextEmployeeID++] = {"Suresh Verma", "9876543210", "Assistant", 25};
        staffMap[nextEmployeeID++] = {"Deepa Singh", "9988776655", "Manager", 22};
        staffMap[nextEmployeeID++] = {"Sanjay Gupta", "9876543210", "Manager", 24};
        staffMap[nextEmployeeID++] = {"Anjali Sharma", "9988776655", "Assistant", 25};
        staffMap[nextEmployeeID++] = {"Vikas Patel", "9876543210", "Manager", 26};
        staffMap[nextEmployeeID++] = {"Aarav Verma", "9988776655", "Assistant", 23};
    }

    void addStaff() {
        string fullName, contactNumber, jobPosition;
        cout << "Enter employee's full name: ";
        cin.ignore(); // Ignore the newline character in the buffer
        getline(cin, fullName);
        cout << "Enter employee's contact number: ";
        getline(cin, contactNumber);
        cout << "Enter employee's job position: ";
        getline(cin, jobPosition);

        Employee emp;
        emp.fullName = fullName;
        emp.contactNumber = contactNumber;
        emp.jobPosition = jobPosition;
        emp.daysOfDuty = 0;

        staffMap[nextEmployeeID++] = emp;
        cout << "Staff added successfully. Employee ID: " << nextEmployeeID - 1 << endl;
    }

    void updateStaffInfo() {
        int employeeID;
        cout << "Enter employee ID to update: ";
        cin >> employeeID;

        if (staffMap.find(employeeID) != staffMap.end()) {
            string fullName, contactNumber, jobPosition;
            cout << "Enter employee's full name: ";
            cin.ignore(); // Ignore the newline character in the buffer
            getline(cin, fullName);
            cout << "Enter employee's contact number: ";
            getline(cin, contactNumber);
            cout << "Enter employee's job position: ";
            getline(cin, jobPosition);

            staffMap[employeeID].fullName = fullName;
            staffMap[employeeID].contactNumber = contactNumber;
            staffMap[employeeID].jobPosition = jobPosition;

            cout << "Staff info updated successfully for Employee ID: " << employeeID << endl;
        } else {
            cout << "Employee ID not found.\n";
        }
    }

    void deleteStaff() {
        int employeeID;
        cout << "Enter employee ID to delete: ";
        cin >> employeeID;

        if (staffMap.find(employeeID) != staffMap.end()) {
            staffMap.erase(employeeID);
            cout << "Staff deleted successfully for Employee ID: " << employeeID << endl;
        } else {
            cout << "Employee ID not found.\n";
        }
    }

    float calculateSalary() {
        int employeeID;
        cout << "Enter employee ID to calculate salary: ";
        cin >> employeeID;

        if (staffMap.find(employeeID) != staffMap.end()) {
            const string& jobPosition = staffMap[employeeID].jobPosition;
            float dailySalary = 0;
            if (jobPosition == "Manager") {
                dailySalary = 1000; // Example salary for Manager
            } else if (jobPosition == "Assistant") {
                dailySalary = 800; // Example salary for Assistant
            } // Add more job positions and corresponding salaries as needed

            float salary = dailySalary * staffMap[employeeID].daysOfDuty;
            cout << "Salary for Employee ID " << employeeID << " is: " << salary << endl;
            return salary;
        } else {
            cout << "Employee ID not found.\n";
            return 0;
        }
    }
};

class PassengerCheckIn {
private:
    struct Passenger {
        string passportID;
        string contactDetails;
        string transitAirports;
        string departureAirport;
        bool checkedIn;
        string boardingPass;
        string baggageInfo;
        vector<string> bookedAirlines;
    };

    map<string, Passenger> passengerMap; // Using passport ID as key

public:
    PassengerCheckIn() {
        passengerMap["A123456"] = {"A123456", "john@example.com", "Guwahati International Airport", "DEL", false, "", "2 pieces, 20kg each"};
        passengerMap["B987654"] = {"B987654", "alice@example.com", "Indira Gandhi International Airport", "BOM", true, "Boarding pass issued", "1 piece, 15kg"};
        passengerMap["C246810"] = {"C246810", "michael@example.com", "None", "BLR", true, "Boarding pass issued", "3 pieces, 25kg each"};
        passengerMap["D135792"] = {"D135792", "jane@example.com", "None", "CCU", false, "", "1 piece, 10kg"};
        passengerMap["E246813"] = {"E246813", "bob@example.com", "None", "AMD", true, "Boarding pass issued", "2 pieces, 12kg each"};
        passengerMap["F987654"] = {"F987654", "emma@example.com", "Guwahati International Airport", "HYD", false, "", "1 piece, 18kg"};
        passengerMap["G135792"] = {"G135792", "william@example.com", "None", "GOI", true, "Boarding pass issued", "2 pieces, 22kg each"};
        passengerMap["H357924"] = {"H357924", "olivia@example.com", "None", "PNQ", true, "Boarding pass issued", "1 piece, 30kg"};
        passengerMap["I246813"] = {"I246813", "james@example.com", "None", "IXC", false, "", "3 pieces, 15kg each"};
        passengerMap["J123457"] = {"J123457", "sophia@example.com", "Guwahati International Airport", "TRV", true, "Boarding pass issued", "2 pieces, 25kg each"};
    }

    void bookTicket() {
        string passportID, contactDetails, transitAirports, departureAirport;
        cout << "Enter passenger's passport ID: ";
        cin >> passportID;
        if (passengerMap.find(passportID) == passengerMap.end()) {
            cout << "Enter passenger's contact details: ";
            cin >> contactDetails;
            cout << "Enter transit airports (if any): ";
            cin >> transitAirports;
            cout << "Enter departure airport: ";
            cin >> departureAirport;
            passengerMap[passportID] = {passportID, contactDetails, transitAirports, departureAirport, false, "", "0", {}};
            cout << "Ticket booked successfully.\n\n";
        } else {
            cout << "Passport ID already exists. Ticket cannot be booked.\n\n";
        }
    }


    void viewBookedAirlines() {
        string passportID;
        cout << "Enter passenger's passport ID: ";
        cin >> passportID;
        if (passengerMap.find(passportID) != passengerMap.end()) {
            const Passenger& passenger = passengerMap[passportID];
            cout << "Airlines booked by passenger " << passportID << ":\n\n";
            if (passenger.bookedAirlines.empty()) {
                cout << "No airlines booked.\n";
            } else {
                for (const auto& airline : passenger.bookedAirlines) {
                    cout << airline << endl;
                }
            }
            cout << endl;
        } else {
            cout << "Passenger not found.\n\n";
        }
    }


    void checkIn() {
        string passportID;
        cout << "Enter passenger's passport ID: ";
        cin >> passportID;
        if (passengerMap.find(passportID) != passengerMap.end()) {
            Passenger& passenger = passengerMap[passportID];
            if (!passenger.checkedIn) {
                passenger.checkedIn = true;
                cout << "Enter departure airport: ";
                cin >> passenger.departureAirport;
                cout << "Passenger checked in successfully.\n\n\n";
            } else {
                cout << "Passenger is already checked in.\n\n\n";
            }
        } else {
            cout << "Passenger not found.\n\n";
        }
    }

    void issueBoardingPass() {
        string passportID;
        cout << "Enter passenger's passport ID: ";
        cin >> passportID;
        if (passengerMap.find(passportID) != passengerMap.end()) {
            Passenger& passenger = passengerMap[passportID];
            if (passenger.checkedIn) {
                passenger.boardingPass = "Boarding pass issued"; // Dummy boarding pass
                cout << "Boarding pass issued successfully.\n";
            } else {
                cout << "Passenger is not checked in.\n";
            }
        } else {
            cout << "Passenger not found.\n";
        }
    }

    void updateBaggageInfo() {
        string passportID;
        cout << "Enter passenger's passport ID: ";
        cin >> passportID;
        if (passengerMap.find(passportID) != passengerMap.end()) {
            Passenger& passenger = passengerMap[passportID];
            cout << "Enter updated baggage information: ";
            cin >> passenger.baggageInfo;
            cout << "Baggage information updated successfully.\n";
        } else {
            cout << "Passenger not found.\n";
        }
    }

    void cancelCheckIn() {
        string passportID;
        cout << "Enter passenger's passport ID: ";
        cin >> passportID;
        if (passengerMap.find(passportID) != passengerMap.end()) {
            Passenger& passenger = passengerMap[passportID];
            if (passenger.checkedIn) {
                passenger.checkedIn = false;
                passenger.departureAirport = ""; // Reset departure airport
                passenger.boardingPass = ""; // Reset boarding pass
                cout << "Check-in cancelled successfully.\n";
            } else {
                cout << "Passenger is not checked in.\n";
            }
        } else {
            cout << "Passenger not found.\n";
        }
    }

    void getCheckInStatus() {
        string passportID;
        cout << "Enter passenger's passport ID: ";
        cin >> passportID;
        if (passengerMap.find(passportID) != passengerMap.end()) {
            const Passenger& passenger = passengerMap[passportID];
            if (passenger.checkedIn) {
                cout << "Passenger is checked in.\n\n";
            } else {
                cout << "Passenger is not checked in.\n\n";
            }
        } else {
            cout << "Passenger not found.\n\n";
        }
    }

    void validatePassenger() {
        string passportID;
        cout << "Enter passenger's passport ID: ";
        cin >> passportID;
        if (passengerMap.find(passportID) != passengerMap.end()) {
            cout << "Passenger is valid.\n\n";
        } else {
            cout << "Passenger not found.\n\n";
        }
    }
    void viewPassengerDetails() {
    string passportID;
    cout << "Enter passenger's passport ID: ";
    cin >> passportID;
    if (passengerMap.find(passportID) != passengerMap.end()) {
        const Passenger& passenger = passengerMap[passportID];
        cout << "Passenger Details:\n";
        cout << "Passport ID: " << passenger.passportID << endl;
        cout << "Contact Details: " << passenger.contactDetails << endl;
        cout << "Transit Airports: " << passenger.transitAirports << endl;
        cout << "Departure Airport: " << passenger.departureAirport << endl;
        cout << "Checked In: " << (passenger.checkedIn ? "Yes" : "No") << endl;
        if (passenger.checkedIn) {
            cout << "Boarding Pass: " << passenger.boardingPass << endl;
        }
        cout << "Baggage Info: " << passenger.baggageInfo << endl;
        cout << "Booked Airlines: ";
        if (passenger.bookedAirlines.empty()) {
            cout << "None";
        } else {
            for (const auto& airline : passenger.bookedAirlines) {
                cout << airline << ", ";
            }
        }
        cout << endl << endl;
    } else {
        cout << "Passenger not found.\n\n";
    }
}

};

class AirlineInformation {
private:
    struct Airline {
        string airlineName;
        string airlineContactInfo;
        string operatingBases;
        int passengerCapability;
        int cargoCapability;
    };

    map<string, Airline> airlineMap; // Using airline code as key

public:
    AirlineInformation() {
        // Hardcoded Indian airline data
        airlineMap["AI"] = {"Air India", "contact@airindia.in", "Indira Gandhi International Airport (DEL), Chhatrapati Shivaji Maharaj International Airport (BOM)", 180, 450};
        airlineMap["6E"] = {"IndiGo", "contact@goindigo.in", "Rahul Gandhi International Airport (DEL), Kempegowda International Airport (BLR)", 200, 500};
        airlineMap["SG"] = {"SpiceJet", "contact@spicejet.com", "Guwahati International Airport (DEL), Chhatrapati Shivaji Maharaj International Airport (BOM)", 160, 400};
        airlineMap["UK"] = {"Vistara", "contact@airvistara.com", "Mumbai International Airport (DEL), Kempegowda International Airport (BLR)", 180, 450};
        airlineMap["G8"] = {"Go First", "contact@gofirst.com", "Rahul Gandhi International Airport (DEL), Chhatrapati Shivaji Maharaj International Airport (BOM)", 150, 380};
        airlineMap["I5"] = {"AirAsia India", "contact@airasia.in", "Sivasagar International Airport (DEL), Kempegowda International Airport (BLR)", 170, 420};
    }

    void addAirline() {
        string airlineCode;
        cout << "Enter airline code: ";
        cin >> airlineCode;
        Airline airline;
        cout << "Enter airline name: ";
        cin >> airline.airlineName;
        cout << "Enter airline contact info: ";
        cin >> airline.airlineContactInfo;
        cout << "Enter operating bases: ";
        cin >> airline.operatingBases;
        cout << "Enter passenger capability: ";
        cin >> airline.passengerCapability;
        cout << "Enter cargo capability: ";
        cin >> airline.cargoCapability;
        airlineMap[airlineCode] = airline;
        cout << "Airline added successfully.\n";
    }

    void updateAirlineInfo() {
        string airlineCode;
        cout << "Enter airline code: ";
        cin >> airlineCode;
        if (airlineMap.find(airlineCode) != airlineMap.end()) {
            Airline& airline = airlineMap[airlineCode];
            cout << "Enter updated airline name: ";
            cin >> airline.airlineName;
            cout << "Enter updated airline contact info: ";
            cin >> airline.airlineContactInfo;
            cout << "Enter updated operating bases: ";
            cin >> airline.operatingBases;
            cout << "Enter updated passenger capability: ";
            cin >> airline.passengerCapability;
            cout << "Enter updated cargo capability: ";
            cin >> airline.cargoCapability;
            cout << "Airline information updated successfully.\n";
        } else {
            cout << "Airline not found.\n";
        }
    }

    void deleteAirline() {
        string airlineCode;
        cout << "Enter airline code: ";
        cin >> airlineCode;
        if (airlineMap.find(airlineCode) != airlineMap.end()) {
            airlineMap.erase(airlineCode);
            cout << "Airline deleted successfully.\n";
        } else {
            cout << "Airline not found.\n";
        }
    }

    void searchAirline() {
        string airlineCode;
        cout << "Enter airline code: ";
        cin >> airlineCode;
        if (airlineMap.find(airlineCode) != airlineMap.end()) {
            displayAirlineInfo(airlineCode);
        } else {
            cout << "Airline not found.\n";
        }
    }

    void retrieveAirlineInfo() {
        for (const auto& pair : airlineMap) {
            displayAirlineInfo(pair.first);
        }
    }

private:
    void displayAirlineInfo(const string& airlineCode) {
        const Airline& airline = airlineMap.at(airlineCode);
        cout << "Airline Code: " << airlineCode << endl;
        cout << "Airline Name: " << airline.airlineName << endl;
        cout << "Airline Contact Info: " << airline.airlineContactInfo << endl;
        cout << "Operating Bases: " << airline.operatingBases << endl;
        cout << "Passenger Capability: " << airline.passengerCapability << endl;
        cout << "Cargo Capability: " << airline.cargoCapability << endl << endl;
    }
};

class FlightPlan {
private:
    struct Flight {
        string departureAirportCode;
        string arrivalAirportCode;
        time_t arrivalTime;
        time_t departureTime;
        string flightStatus;
    };

    int nextFlightNo;
    map<int, Flight> flightMap;

public:
    FlightPlan() : nextFlightNo(1) {
        flightMap[nextFlightNo++] = {"JFK", "LAX", time(nullptr) + 3600, time(nullptr) + 7200, "Scheduled"};
        flightMap[nextFlightNo++] = {"LAX", "ORD", time(nullptr) + 10800, time(nullptr) + 14400, "Scheduled"};
        flightMap[nextFlightNo++] = {"ORD", "DFW", time(nullptr) + 18000, time(nullptr) + 28600, "Scheduled"};
        flightMap[nextFlightNo++] = {"DFW", "ATL", time(nullptr) + 25200, time(nullptr) + 28800, "Scheduled"};
        flightMap[nextFlightNo++] = {"ATL", "LGA", time(nullptr) + 32400, time(nullptr) + 36000, "Scheduled"};
        flightMap[nextFlightNo++] = {"LGA", "MIA", time(nullptr) + 39600, time(nullptr) + 43200, "Scheduled"};
    }

    void createFlightPlan() {
        Flight flight;
        cout << "Enter departure airport code: ";
        cin >> flight.departureAirportCode;
        cout << "Enter arrival airport code: ";
        cin >> flight.arrivalAirportCode;
        flight.departureTime = time(nullptr); // Current time as departure time
        flight.arrivalTime = flight.departureTime + 3600; // Assume arrival is 1 hour after departure
        flight.flightStatus = "Scheduled";
        flightMap[nextFlightNo++] = flight;
        cout << "Flight plan created successfully. Flight No: " << nextFlightNo - 1 << endl;
    }

    void updateFlightPlan() {
        int flightNo;
        cout << "Enter flight number: ";
        cin >> flightNo;
        if (flightMap.find(flightNo) != flightMap.end()) {
            Flight& flight = flightMap[flightNo];
            cout << "Enter updated departure airport code: ";
            cin >> flight.departureAirportCode;
            cout << "Enter updated arrival airport code: ";
            cin >> flight.arrivalAirportCode;
            cout << "Flight plan updated successfully for Flight No: " << flightNo << endl;
        } else {
            cout << "Flight not found.\n";
        }
    }

    void deleteFlightPlan() {
        int flightNo;
        cout << "Enter flight number: ";
        cin >> flightNo;
        if (flightMap.find(flightNo) != flightMap.end()) {
            flightMap.erase(flightNo);
            cout << "Flight plan deleted successfully for Flight No: " << flightNo << endl;
        } else {
            cout << "Flight not found.\n";
        }
    }

    void updateFlightStatus() {
        int flightNo;
        cout << "Enter flight number: ";
        cin >> flightNo;
        if (flightMap.find(flightNo) != flightMap.end()) {
            Flight& flight = flightMap[flightNo];
            cout << "Enter updated flight status: ";
            cin >> flight.flightStatus;
            cout << "Flight status updated successfully for Flight No: " << flightNo << endl;
        } else {
            cout << "Flight not found.\n";
        }
    }

    void calculateFuelRequirements() {
        int flightNo;
        cout << "Enter flight number: ";
        cin >> flightNo;
        if (flightMap.find(flightNo) != flightMap.end()) {
            const Flight& flight = flightMap[flightNo];
            // Assuming fuel requirement calculation based on departure and arrival time
            // Dummy calculation: 10% of flight duration in hours
            double flightDuration = difftime(flight.arrivalTime, flight.departureTime) / 3600.0; // in hours
            double fuelRequirement = -1256.34 * flightDuration; // 10% of flight duration
            cout << "Fuel requirements for Flight No " << flightNo << ": " << fuelRequirement << " L/hr\n\n";
        } else {
            cout << "Flight not found.\n";
        }
    }

    void viewFlightSchedule() const {
        cout << "Flight Schedule:\n\n";
        for (auto it = flightMap.begin(); it != flightMap.end(); ++it) {
            const Flight& flight = it->second;
            cout << "Flight No: " << it->first << ", Departure: " << flight.departureAirportCode << ", Arrival: " << flight.arrivalAirportCode << ", Status: " << flight.flightStatus << endl << endl;
        }
    }
};

class BaggageHandling {
private:
    struct Baggage {
        string passengerID;
        int flightNumber;
        bool transferStatus;
    };

    int nextBaggageID;
    map<int, Baggage> baggageMap;

public:
    BaggageHandling() : nextBaggageID(1) {
        baggageMap[nextBaggageID++] = {"P001", 101, false};
        baggageMap[nextBaggageID++] = {"P002", 205, false};
        baggageMap[nextBaggageID++] = {"P003", 309, false};
        baggageMap[nextBaggageID++] = {"P004", 412, true};
        baggageMap[nextBaggageID++] = {"P005", 518, true};
        baggageMap[nextBaggageID++] = {"P006", 624, false};
    }

    void checkInBaggage() {
        Baggage baggage;
        cout << "Enter passenger's ID: ";
        cin >> baggage.passengerID;
        cout << "Enter flight number: ";
        cin >> baggage.flightNumber;
        baggage.transferStatus = false; // Assuming initially not transferred
        baggageMap[nextBaggageID++] = baggage;
        cout << "Baggage checked in successfully. Baggage ID: " << nextBaggageID - 1 << endl;
    }

    void updateTransferStatus() {
        int baggageID;
        cout << "Enter baggage ID: ";
        cin >> baggageID;
        if (baggageMap.find(baggageID) != baggageMap.end()) {
            char transferStatusInput;
            cout << "Is baggage transferred? (y/n): ";
            cin >> transferStatusInput;
            bool transferStatus = (transferStatusInput == 'y' || transferStatusInput == 'Y');
            baggageMap[baggageID].transferStatus = transferStatus;
            cout << "Transfer status updated successfully for Baggage ID: " << baggageID << endl;
        } else {
            cout << "Baggage not found.\n";
        }
    }
};

class CargoHandling {
private:
    struct Cargo {
        string airlineCode;
        int flightNumber;
        double weight;
        time_t arrivalTime;
        string status;
    };

    int nextCargoId;
    map<int, Cargo> cargoMap;
    const double baseChargePerKg = 2.5; 
    const double additionalChargePerHour = 1.0; 

public:
    CargoHandling() : nextCargoId(1) {
        cargoMap[nextCargoId++] = {"AA", 101, 1500.5, time(nullptr), "Booked"};
        cargoMap[nextCargoId++] = {"DL", 205, 2000.0, time(nullptr), "Arrived"};
        cargoMap[nextCargoId++] = {"UA", 309, 1000.75, time(nullptr), "In Transit"};
        cargoMap[nextCargoId++] = {"LH", 412, 1800.25, time(nullptr), "Booked"};
        cargoMap[nextCargoId++] = {"BA", 518, 2500.0, time(nullptr), "Delivered"};
        cargoMap[nextCargoId++] = {"EK", 624, 3000.0, time(nullptr), "Booked"};
    }

    void bookCargo() {
        Cargo cargo;
        cout << "Enter airline code: ";
        cin >> cargo.airlineCode;
        cout << "Enter flight number: ";
        cin >> cargo.flightNumber;
        cout << "Enter weight of cargo (in kg): ";
        cin >> cargo.weight;
        cargo.arrivalTime = time(nullptr); // Current time as arrival time
        cargo.status = "Booked";
        cargoMap[nextCargoId++] = cargo;
        
        cout << "Cargo booked successfully. Cargo ID: " << nextCargoId - 1 << endl;
    }

    void updateCargoStatus() {
        int cargoId;
        cout << "Enter cargo ID: ";
        cin >> cargoId;
        string newStatus;
        cout << "Enter new status: ";
        cin >> newStatus;
        cargoMap[cargoId].status = newStatus;
        cout << "Cargo status updated successfully for Cargo ID: " << cargoId << endl;
    }

    double calculateCharges() {
        int cargoId;
        cout << "Enter cargo ID: ";
        cin >> cargoId;
        Cargo& cargo = cargoMap[cargoId];
        
        double totalCharge = baseChargePerKg * cargo.weight;

        return totalCharge;
    }
};

class AssetManagement {
private:
    struct Asset {
        string assetName;
        string assetType;
        string location;
        int checkInCount;
        vector<string> maintenanceHistory;
    };

    int nextAssetID;
    map<int, Asset> assetMap;

public:
    AssetManagement() : nextAssetID(1) {
        assetMap[1] = {"Fueling Station", "Fueling Capabilities", "Terminal 1, Gate A", 0, {"Initial installation"}};
        assetMap[2] = {"Check-in Counter", "Passenger Handling", "Terminal 2, Gate B", 0, {"Initial setup"}};
        assetMap[3] = {"Baggage Conveyor", "Baggage Handling", "Terminal 3, Gate C", 0, {"Assembly completed"}};
        assetMap[4] = {"Security Scanner", "Security Equipment", "Terminal 4, Gate D", 0, {"Installed"}};
        assetMap[5] = {"Maintenance Workshop", "Maintenance Facilities", "Terminal 5, Gate E", 0, {"Operational"}};
        nextAssetID = 6; 
    }

    void addAsset() {
        Asset asset;
        cout << "Enter asset name: ";
        getline(cin, asset.assetName);
        cout << "Enter asset type: ";
        getline(cin, asset.assetType);
        cout << "Enter location: ";
        getline(cin, asset.location);
        asset.checkInCount = 0;
        assetMap[nextAssetID++] = asset;
        cout << "Asset added successfully. Asset ID: " << nextAssetID - 1 << endl << endl;
    }

    void updateAsset() {
        int assetID;
        cout << "Enter asset ID: ";
        cin >> assetID;
        cin.ignore(); // Ignore the newline character
        if (assetMap.find(assetID) != assetMap.end()) {
            Asset& asset = assetMap[assetID];
            cout << "Enter updated asset name: ";
            getline(cin, asset.assetName);
            cout << "Enter updated asset type: ";
            getline(cin, asset.assetType);
            cout << "Enter updated location: ";
            getline(cin, asset.location);
            cout << "Asset updated successfully for Asset ID: " << assetID << endl << endl;
        } else {
            cout << "Asset not found.\n";
        }
    }

    void deleteAsset() {
        int assetID;
        cout << "Enter asset ID: ";
        cin >> assetID;
        if (assetMap.find(assetID) != assetMap.end()) {
            assetMap.erase(assetID);
            cout << "Asset deleted successfully for Asset ID: " << assetID << endl << endl;
        } else {
            cout << "Asset not found.\n";
        }
    }

    void retrieveAsset() {
        int assetID;
        cout << "Enter asset ID: ";
        cin >> assetID;
        if (assetMap.find(assetID) != assetMap.end()) {
            const Asset& asset = assetMap[assetID];
            cout << "Asset Name: " << asset.assetName << endl;
            cout << "Asset Type: " << asset.assetType << endl;
            cout << "Location: " << asset.location << endl;
            cout << "Check-in Count: " << asset.checkInCount << endl;
            cout << "Maintenance History:\n\n";
            for (const string& maintenanceEvent : asset.maintenanceHistory) {
                cout << maintenanceEvent << endl;
            }
        } else {
            cout << "Asset not found.\n\n";
        }
    }

    void addMaintenanceEvent() {
        int assetID;
        cout << "Enter asset ID: ";
        cin >> assetID;
        cin.ignore(); // Ignore the newline character
        if (assetMap.find(assetID) != assetMap.end()) {
            Asset& asset = assetMap[assetID];
            cout << "Enter maintenance event: ";
            string maintenanceEvent;
            getline(cin, maintenanceEvent);
            asset.maintenanceHistory.push_back(maintenanceEvent);
            cout << "Maintenance event added successfully for Asset ID: " << assetID << endl;
        } else {
            cout << "Asset not found.\n";
        }
    }

    void incrementCheckInCount() {
        int assetID;
        cout << "Enter asset ID: ";
        cin >> assetID;
        if (assetMap.find(assetID) != assetMap.end()) {
            assetMap[assetID].checkInCount++;
            cout << "Check-in count incremented successfully for Asset ID: " << assetID << endl;
        } else {
            cout << "Asset not found.\n";
        }
    }
    void viewAssets() const {
        cout << "\n\nList of assets:\n\n";
        for (auto it = assetMap.begin(); it != assetMap.end(); ++it) {
            const Asset& asset = it->second;
            cout << "Asset ID: " << it->first << ", Name: " << asset.assetName << ", Type: " << asset.assetType << ", Location: " << asset.location << endl << endl;
        }
    }
};

class Maintenance {
private:
    struct MaintenanceRecord {
        int assetID;
        string assetName;
        string maintenanceType;
        string maintenanceSchedule;
        string maintenanceStatus;
    };

    int nextRecordID;
    map<int, MaintenanceRecord> maintenanceMap;

public:
    Maintenance() : nextRecordID(1) {}

    void scheduleMaintenance() {
        int assetID;
        cout << "Enter asset ID: ";
        cin >> assetID;
        if (assetIDExists(assetID)) {
            MaintenanceRecord record;
            record.assetID = assetID;
            cin.ignore(); // Ignore the newline character
            cout << "Enter asset name: ";
            getline(cin, record.assetName);
            cout << "Enter maintenance type: ";
            getline(cin, record.maintenanceType);
            cout << "Enter maintenance schedule: ";
            getline(cin, record.maintenanceSchedule);
            record.maintenanceStatus = "Scheduled";
            maintenanceMap[nextRecordID++] = record;
            cout << "Maintenance scheduled successfully. Record ID: " << nextRecordID - 1 << endl;
        } else {
            cout << "Asset ID not found.\n";
        }
    }

    void addMaintenanceRecord() {
        int assetID;
        cout << "Enter asset ID: ";
        cin >> assetID;
        if (assetIDExists(assetID)) {
            MaintenanceRecord record;
            record.assetID = assetID;
            cin.ignore(); // Ignore the newline character
            cout << "Enter asset name: ";
            getline(cin, record.assetName);
            cout << "Enter maintenance type: ";
            getline(cin, record.maintenanceType);
            cout << "Enter maintenance schedule: ";
            getline(cin, record.maintenanceSchedule);
            cout << "Enter maintenance status: ";
            getline(cin, record.maintenanceStatus);
            maintenanceMap[nextRecordID++] = record;
            cout << "Maintenance record added successfully. Record ID: " << nextRecordID - 1 << endl << endl;
        } else {
            cout << "Asset ID not found.\n";
        }
    }

private:
    bool assetIDExists(int assetID) const {
        return maintenanceMap.find(assetID) != maintenanceMap.end();
    }
};

class Complaints {
private:
    struct Complaint {
        int complaintID;
        int personID;
        string description;
    };

    int nextComplaintID;
    map<int, Complaint> complaintMap;

public:
    Complaints() : nextComplaintID(1) {}

    void viewComplaints() const {
        cout << "List of complaints:\n";
        for (auto it = complaintMap.begin(); it != complaintMap.end(); ++it) {
            const Complaint& complaint = it->second;
            cout << "Complaint ID: " << complaint.complaintID << ", Person ID: " << complaint.personID << ", Description: " << complaint.description << endl;
        }
    }

    void addComplaint() {
        int personID;
        string description;
        cout << "Enter person ID: ";
        cin >> personID;
        cin.ignore(); // Ignore the newline character
        cout << "Enter complaint description: ";
        getline(cin, description);

        Complaint complaint;
        complaint.complaintID = nextComplaintID++;
        complaint.personID = personID;
        complaint.description = description;
        complaintMap[complaint.complaintID] = complaint;
        cout << "Complaint added successfully. Complaint ID: " << complaint.complaintID << endl;
    }

    void deleteComplaint() {
        int complaintID;
        cout << "Enter complaint ID to delete: ";
        cin >> complaintID;

        auto it = complaintMap.find(complaintID);
        if (it != complaintMap.end()) {
            complaintMap.erase(it);
            cout << "Complaint deleted successfully. Complaint ID: " << complaintID << endl;
        } else {
            cout << "Complaint ID not found.\n";
        }
    }
};

class VehicleManagement {
private:
    struct Vehicle {
        string type;
        string model;
        string number;
        string status;
        string fuelingInfo;
    };

    int nextVehicleID;
    map<int, Vehicle> vehicleMap;

public:
    VehicleManagement() : nextVehicleID(1) {
        vehicleMap[nextVehicleID++] = {"Security Vehicle", "Ford Explorer", "SV001", "Available", "Fuel tank full"};
        vehicleMap[nextVehicleID++] = {"Baggage Cart", "Airport Cart AC1000", "BC002", "In Use", "Needs charging"};
        vehicleMap[nextVehicleID++] = {"Passenger Shuttle", "Mercedes-Benz Sprinter", "PS003", "Available", "Fuel tank full"}; 
    }

    void addVehicle() {
        Vehicle vehicle;
        cout << "Enter vehicle type: ";
        getline(cin, vehicle.type);
        cout << "Enter vehicle model: ";
        getline(cin, vehicle.model);
        cout << "Enter vehicle number: ";
        getline(cin, vehicle.number);
        cout << "Enter vehicle status: ";
        getline(cin, vehicle.status);
        cout << "Enter fueling information: ";
        getline(cin, vehicle.fuelingInfo);
        vehicleMap[nextVehicleID++] = vehicle;
        cout << "Vehicle added successfully. Vehicle ID: " << nextVehicleID - 1 << endl;
    }

    void deleteVehicle() {
        int vehicleID;
        cout << "Enter vehicle ID to delete: ";
        cin >> vehicleID;
        cin.ignore(); // Clear input buffer
        auto it = vehicleMap.find(vehicleID);
        if (it != vehicleMap.end()) {
            vehicleMap.erase(it);
            cout << "Vehicle deleted successfully. Vehicle ID: " << vehicleID << endl;
        } else {
            cout << "Vehicle ID not found.\n";
        }
    }

    void updateVehicle() {
        int vehicleID;
        cout << "Enter vehicle ID to update: ";
        cin >> vehicleID;
        cin.ignore(); // Clear input buffer
        auto it = vehicleMap.find(vehicleID);
        if (it != vehicleMap.end()) {
            Vehicle& vehicle = it->second;
            cout << "Enter vehicle type: ";
            getline(cin, vehicle.type);
            cout << "Enter vehicle model: ";
            getline(cin, vehicle.model);
            cout << "Enter vehicle number: ";
            getline(cin, vehicle.number);
            cout << "Enter vehicle status: ";
            getline(cin, vehicle.status);
            cout << "Enter fueling information: ";
            getline(cin, vehicle.fuelingInfo);
            cout << "Vehicle updated successfully. Vehicle ID: " << vehicleID << endl;
        } else {
            cout << "Vehicle ID not found.\n";
        }
    }

    void viewVehicleInfo() const {
        int vehicleID;
        cout << "Enter vehicle ID to view information: ";
        cin >> vehicleID;
        cin.ignore(); // Clear input buffer
        auto it = vehicleMap.find(vehicleID);
        if (it != vehicleMap.end()) {
            const Vehicle& vehicle = it->second;
            cout << "Vehicle ID: " << vehicleID << endl;
            cout << "Type: " << vehicle.type << endl;
            cout << "Model: " << vehicle.model << endl;
            cout << "Number: " << vehicle.number << endl;
            cout << "Status: " << vehicle.status << endl;
            cout << "Fueling Info: " << vehicle.fuelingInfo << endl;
        } else {
            cout << "Vehicle ID not found.\n";
        }
    }
};

class Catering {
private:
    map<int, string> inflightMeals;
    map<int, string> menuPlanning;
    map<int, string> cafesID;

public:
    Catering() {
        inflightMeals[1] = "Vegetarian Meal";
        inflightMeals[2] = "Non-Vegetarian Meal";
        inflightMeals[3] = "Vegan Meal";
        inflightMeals[4] = "Gluten-Free Meal";
        inflightMeals[5] = "Seafood Meal";

        // Hardcoded data for menu planning
        menuPlanning[1] = "Breakfast";
        menuPlanning[2] = "Lunch";
        menuPlanning[3] = "Dinner";
        menuPlanning[4] = "Snacks";
        menuPlanning[5] = "Beverages";

        // Hardcoded data for cafe locations
        cafesID[1] = "Cafe 1";
        cafesID[2] = "Cafe 2";
        cafesID[3] = "Cafe 3";
        cafesID[4] = "Cafe 4";
        cafesID[5] = "Cafe 5";
    }

    void viewFlightMeals() const {
        cout << "Inflight Meals:\n";
        for (auto it = inflightMeals.begin(); it != inflightMeals.end(); ++it) {
            cout << "ID: " << it->first << ", Meal: " << it->second << endl;
        }
    }

    void viewCafeLocations() const {
        cout << "Cafe Locations:\n";
        for (auto it = cafesID.begin(); it != cafesID.end(); ++it) {
            cout << "ID: " << it->first << ", Location: " << it->second << endl;
        }
    }

};

class SecurityIncidences {
private:
    struct Incident {
        string date;
        string passengerID;
        string baggageID;
        string incidentType;
        string description;
    };

    map<int, Incident> incidentMap;
    int nextIncidentID;

public:
    SecurityIncidences() : nextIncidentID(1) {
        incidentMap[nextIncidentID++] = {"2023-01-15", "P001", "B001", "Unauthorized Access", "Passenger attempted to enter restricted area without permission."};
        incidentMap[nextIncidentID++] = {"2023-02-21", "P002", "B002", "Suspicious Behavior", "Passenger acting suspiciously near boarding gate."};
        incidentMap[nextIncidentID++] = {"2023-03-10", "P003", "NA", "Lost Item", "Passenger reported a lost item at security checkpoint."};
    }

    void addIncident() {
        Incident inc;
        cout << "Enter date of incident (YYYY-MM-DD): ";
        getline(cin, inc.date);
        cout << "Enter passenger ID: ";
        getline(cin, inc.passengerID);
        cout << "Enter baggage ID (if involved, otherwise enter NA): ";
        getline(cin, inc.baggageID);
        cout << "Enter incident type: ";
        getline(cin, inc.incidentType);
        cout << "Enter incident description: ";
        getline(cin, inc.description);
        incidentMap[nextIncidentID++] = inc;
        cout << "Incident added successfully.\n";
    }

    void updateIncident() {
        int incidentID;
        cout << endl << "Enter Incident Id" << endl;
        cin >> incidentID;
        auto it = incidentMap.find(incidentID);
        if (it != incidentMap.end()) {
            Incident& inc = it->second;
            cout << "Enter updated date of incident (YYYY-MM-DD): ";
            getline(cin, inc.date);
            cout << "Enter updated passenger ID: ";
            getline(cin, inc.passengerID);
            cout << "Enter updated baggage ID (if involved, otherwise enter NA): ";
            getline(cin, inc.baggageID);
            cout << "Enter updated incident type: ";
            getline(cin, inc.incidentType);
            cout << "Enter updated incident description: ";
            getline(cin, inc.description);
            cout << "Incident updated successfully.\n";
        } else {
            cout << "Incident ID not found.\n";
        }
    }

    void viewIncidents() const {
        cout << "Security Incidents:\n";
        for (const auto& pair : incidentMap) {
            const Incident& inc = pair.second;
            cout << "Incident ID: " << pair.first << endl;
            cout << "Date: " << inc.date << endl;
            cout << "Passenger ID: " << inc.passengerID << endl;
            cout << "Baggage ID: " << inc.baggageID << endl;
            cout << "Incident Type: " << inc.incidentType << endl;
            cout << "Description: " << inc.description << endl << endl;
        }
    }
};

class AirportStaff {
private:
    struct Employee {
        string employeeID;
        string name;
        string contactInfo;
        string position;
        int daysWorked;
        string password; 
    };

    map<int, Employee> staffMap;
    int nextEmployeeID;
    const float baseSalaryPerDay = 100.0; 

public:
    AirportStaff() : nextEmployeeID(1100) {
        staffMap[nextEmployeeID++] = {"S1100", "John Smith", "john.smith@example.com", "Security Officer", 15, "staff1"};
        staffMap[nextEmployeeID++] = {"S1101", "Alice Johnson", "alice.johnson@example.com", "Customer Service Representative", 20, "staff2"};
        staffMap[nextEmployeeID++] = {"S1102", "Michael Brown", "michael.brown@example.com", "Baggage Handler", 18, "staff3"};
        staffMap[nextEmployeeID++] = {"S1103", "Emily Davis", "emily.davis@example.com", "Cleaning Staff", 22, "staff4"};
        staffMap[nextEmployeeID++] = {"S1104", "James Wilson", "james.wilson@example.com", "Flight Attendant", 17, "staff5"};
        staffMap[nextEmployeeID++] = {"S1105", "Emma Martinez", "emma.martinez@example.com", "Pilot", 25, "staff6"};
        staffMap[nextEmployeeID++] = {"S1106", "William Garcia", "william.garcia@example.com", "Maintenance Technician", 19, "staff7"};
        staffMap[nextEmployeeID++] = {"S1107", "Olivia Rodriguez", "olivia.rodriguez@example.com", "Ground Crew", 21, "staff8"};
        staffMap[nextEmployeeID++] = {"S1108", "Daniel Lee", "daniel.lee@example.com", "Air Traffic Controller", 16, "staff9"};
        staffMap[nextEmployeeID++] = {"S1109", "Sophia Hernandez", "sophia.hernandez@example.com", "Ramp Agent", 23, "staff10"};
    }

    bool verifyPassword() {
        string password;
        cout << "Enter password: ";
        cin >> password;
        return password == "airportpassword";
    }

    void calculateSalary() {
        int employeeID;
        cout << "Enter employee ID to calculate salary: ";
        cin >> employeeID;
        cin.ignore(); // Clear input buffer
        auto it = staffMap.find(employeeID);
        if (it != staffMap.end()) {
            Employee& emp = it->second;
            float salary = baseSalaryPerDay * emp.daysWorked;
            cout << "Salary for Employee ID " << employeeID << " (" << emp.name << ") is: $" << salary << endl;
        } else {
            cout << "Employee ID not found.\n";
        }
    }
    void viewStaffRecord() {
        cout << "Staff Records:\n";
        for (const auto& pair : staffMap) {
            const Employee& emp = pair.second;
            cout << "Employee ID: " << emp.employeeID << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Contact Info: " << emp.contactInfo << endl;
            cout << "Position: " << emp.position << endl;
            cout << "Days Worked: " << emp.daysWorked << endl;
            cout << endl;
        }
    }
};


class SecurityPersonal {
private:
    struct Employee {
        string employeeID;
        string name;
        string contactInfo;
        string position;
        string assignedLocation;
        string password; 
    };

public:
    map<int, Employee> secMap;
    int nextEmployeeID;
    SecurityPersonal() : nextEmployeeID(1) {
        // Hardcoded data for 8 security personnel
        secMap[nextEmployeeID++] = {"S001", "John Smith", "john.smith@example.com", "Security Officer", "Gate A", "password1"};
        secMap[nextEmployeeID++] = {"S002", "Alice Johnson", "alice.johnson@example.com", "Security Officer", "Gate B", "password2"};
        secMap[nextEmployeeID++] = {"S003", "Michael Brown", "michael.brown@example.com", "Security Officer", "Gate C", "password3"};
        secMap[nextEmployeeID++] = {"S004", "Emily Davis", "emily.davis@example.com", "Security Officer", "Gate D", "password4"};
        secMap[nextEmployeeID++] = {"S005", "James Wilson", "james.wilson@example.com", "Security Officer", "Terminal Entrance", "password5"};
        secMap[nextEmployeeID++] = {"S006", "Emma Martinez", "emma.martinez@example.com", "Security Officer", "Baggage Screening Area", "password6"};
        secMap[nextEmployeeID++] = {"S007", "William Garcia", "william.garcia@example.com", "Security Officer", "Arrivals Hall", "password7"};
        secMap[nextEmployeeID++] = {"S008", "Olivia Rodriguez", "olivia.rodriguez@example.com", "Security Officer", "Departures Hall", "password8"};
    }

    bool verifyPassword() {
        string password;
        cout << "Enter password: ";
        cin >> password;

        
        for (const auto& pair : secMap) {
            const auto& id = pair.first;
            const auto& emp = pair.second;
            if (emp.password == password) {
                cout << "Password verified.\n";
                return true;
            }
        }

        cout << "Incorrect password.\n";
        return false;
    }


    void addSecurityPersonal() {
        Employee emp;
        cout << "Enter employee ID: ";
        cin >> emp.employeeID;
        cin.ignore(); 
        cout << "Enter employee's name: ";
        getline(cin, emp.name);
        cout << "Enter employee's contact info: ";
        getline(cin, emp.contactInfo);
        cout << "Enter employee's position: ";
        getline(cin, emp.position);
        cout << "Enter employee's assigned location: ";
        getline(cin, emp.assignedLocation);
        cout << "Enter employee's password: ";
        cin >> emp.password;
        secMap[nextEmployeeID++] = emp;
        cout << "Security personnel added successfully.\n";
    }

    void viewSecurityIncidences() {
        
        cout << "Viewing security incidences...\n";
    }
    void viewSecurityPersonalRecord() {
        cout << "Viewing security personnel records...\n";
        for (const auto& pair : secMap) {
            const auto& emp = pair.second;
            cout << "Employee ID: " << emp.employeeID << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Contact Info: " << emp.contactInfo << endl;
            cout << "Position: " << emp.position << endl;
            cout << "Assigned Location: " << emp.assignedLocation << endl << endl;
        }
    }
};

class AirlineRepresentative {
private:
    struct Representative {
        string name;
        string password;
        string airline;
    };

public:
    map<string, Representative> representatives;
    AirlineRepresentative() {
        representatives["ID1"] = {"John Smith", "airline1", "Airline 1"};
        representatives["ID2"] = {"Alice Johnson", "airline2", "Airline 2"};
        representatives["ID3"] = {"Michael Brown", "airline3", "Airline 3"};
    }

    bool verifyPassword() {
        string employeeID, password;
        cout << "Enter employee ID: ";
        cin >> employeeID;
        cin.ignore(); 
        cout << "Enter password: ";
        cin >> password;

        auto it = representatives.find(employeeID);
        if (it != representatives.end() && it->second.password == password) {
            cout << "Password verified.\n";
            return true;
        } else {
            cout << "Invalid credentials.\n\n";
            return false;
        }
    }
};


class Administrator : public StaffInfo, public SecurityPersonal {
    private:
        string adminId;
        string password;

    public:
        Administrator(const string& id, const string& pass) : adminId(id), password(pass) {}
        bool verifyLogin() const {
            string enteredPassword;
            cout << "Enter password: ";
            cin >> enteredPassword;
            return enteredPassword == password;
        }

};

int main() {
    StaffInfo staff;
    PassengerCheckIn passcheck;
    AirlineInformation air_info;
    FlightPlan fplan;
    BaggageHandling bhand;
    CargoHandling chand;
    AssetManagement am;
    VehicleManagement vm;
    Catering cat;
    SecurityIncidences sec_in;
    AirportStaff as;
    SecurityPersonal sp;
    AirlineRepresentative air_rep;
    Complaints cm;
    Maintenance m;

    int choice_admin=1, choice_arep=1, choice_staff=1, choice_sec=1, choice_pass=1;

    Administrator admin("admin123", "password123");

    int choice;
    do
    {
        cout << endl << "**** Welcome to Airport Management System ****" << endl;
        cout << "Please select your role:" << endl;
        cout << "1. Administrator" << endl;
        cout << "2. Airline Representative" << endl;
        cout << "3. Airport Staff" << endl;
        cout << "4. Security Personnel" << endl;
        cout << "5. Passengers" << endl;
        cout << "6. EXIT" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            if(!admin.verifyLogin()){
                cout << endl << "Incorrect Password" << endl;
                break;
            }
            while (choice_admin!=8)
            {
                cout << "\n\n **** Administrator Dashboard: ****" << endl;
                cout << "1. Add Staff" << endl;
                cout << "2. Remove Staff" << endl;
                cout << "3. Update Staff" << endl;
                cout << "4. View Airport Staff" << endl;
                cout << "5. View Security Staff" << endl;
                cout << "6. Calculate Salary of Airport Staff" << endl;

                cout << " COMPLAINTS " << endl;
                cout << "7. View Complaints" << endl;

                cout << "8. EXIT" << endl;

                cin >> choice_admin;

                switch (choice_admin)
                {
                case 1:
                    staff.addStaff();
                    cout << endl << endl;
                    break;
                case 2:
                    staff.deleteStaff();
                    cout << endl;
                    break;
                case 3:
                    staff.updateStaffInfo();
                    cout << endl;
                    break;
                case 4:
                    as.viewStaffRecord();
                    cout << endl;
                    break;
                case 5:
                    sp.viewSecurityPersonalRecord();
                    cout << endl;
                    break;
                case 6:
                    staff.calculateSalary();
                    cout << endl;
                    break;
                case 7:
                    cm.viewComplaints();
                    cout << endl;
                    break;
                case 8:
                cout << "Exiting..." << endl;
                    break;
                }
            }

            break;
        case 2:
            if(!air_rep.verifyPassword()){
                cout << endl << "Invalid Password" << endl;
                break;
            }
            while (choice_arep!=6)
            {
                cout << "\n**** Airline Representative Dashboard **** :" << endl;

                cout << "\n\n  AIRLINE INFORMATION " << endl;
                cout << "1. Retrive Airline Information" << endl;
                cout << "2. Search Airline Information" << endl;

                cout << "\n\n  FLIGHT PLAN " << endl;
                cout << "3. Update Flight Status" << endl;
                cout << "4. Calculate Fuel Requirements" << endl;

                cout << "\n\n  CARGO HANDLING " << endl;
                cout << "5. Update Cargo Status" << endl;
                cout << "6. EXIT" << endl << endl;
                cout << "Enter your choice: ";

                cin >> choice_arep;

                switch (choice_arep)
                {
                case 1:
                    air_info.retrieveAirlineInfo();
                    cout << endl;
                    break;
                case 2:
                    air_info.searchAirline();
                    cout << endl;
                    break;
                case 3:
                    fplan.updateFlightStatus();
                    cout << endl;
                    break;
                case 4:
                    fplan.calculateFuelRequirements();
                    cout << endl;
                    break;
                case 5:
                    chand.updateCargoStatus();
                    cout << endl;
                    break;
                case 6:
                    cout << endl << "Exiting..." << endl;
                    break;
                }
            }

            break;
        case 3:
            if (!as.verifyPassword())
            {
                cout << "Wrong password!" << endl;
                break;
            }
            while (choice_staff!=36)
            {
                cout << "\n**** Airport Staff Dashboard **** :" << endl;

                cout << "\n\n  AIRLINE INFORMATION " << endl;
                cout << "1. Add Airline" << endl;
                cout << "2. Update Airline" << endl;
                cout << "3. Retrive Airline Information" << endl;
                cout << "4. Search Airline Information" << endl;
                cout << "5. Delete Airline" << endl;

                cout << "\n\n  FLIGHT PLAN " << endl;
                cout << "6. Create Flight Plan" << endl;
                cout << "7. Update Flight Plan" << endl;
                cout << "8. Delete Flight Plan" << endl;
                cout << "9. Update Flight Status" << endl;
                cout << "10. View Flight Schedule" << endl;              // new
                cout << "11. Calculate Fuel Requirements" << endl;

                cout << "\n\n  PASSENGER CHECK-IN " << endl;
                cout << "12. Check-in" << endl;
                cout << "13. Issue Boarding Pass" << endl;
                cout << "14. Update Baggage Information" << endl;
                cout << "15. Cancel Check-in" << endl;
                cout << "16. Get Check-in Status" << endl;
                cout << "17. Validate Passenger" << endl;
                cout << "18. View Passenger Details" << endl;

                cout << "\n\n  BAGGAGE HANDLING " << endl;
                cout << "19. Check-in" << endl;
                cout << "20. Update Status" << endl;
                cout << "21. Calculate Cargo Charges" << endl;   // new

                cout << "\n\n  ASSET MANAGEMENT " << endl;
                cout << "22. Add Asset" << endl;
                cout << "23. Update Asset" << endl;
                cout << "24. Delete Asset" << endl;
                cout << "25. Retrive Asset" << endl;
                cout << "26. View Asset" << endl;
                cout << "27. Increment Check-in Count" << endl;
                cout << "28. Add Maintanence Event" << endl;

                cout << "\n\n  VEHICLE MANAGEMENT " << endl;
                cout << "29. Add Vehicle" << endl;
                cout << "30. Update Vehicle" << endl;
                cout << "31. Delete Vehicle" << endl;
                cout << "32. View Vehicle Information" << endl;

                cout << "\n\n  MAINTENANCE " << endl;
                cout << "33. Schedule Maintenance"<<endl;
                cout << "34. Add Maintenance Record" << endl;

                cout << "\n\n COMPLAINTS " << endl;
                cout << "35. Add Complaints" << endl;
                cout << "36. Delete Complaints" << endl;

                cout << "37. EXIT" << endl;

                cout << "Enter your choice: ";
                cin >> choice_staff;

                switch (choice_staff)
                {
                case 1:
                    air_info.addAirline();
                    cout << endl;
                    break;
                case 2:
                    air_info.updateAirlineInfo();
                    cout << endl;
                    break;
                case 3:
                    air_info.retrieveAirlineInfo();
                    cout << endl;
                    break;
                case 4:
                    air_info.searchAirline();
                    cout << endl;
                    break;
                case 5:
                    air_info.deleteAirline();
                    cout << endl;
                    break;
                case 6:
                    fplan.createFlightPlan();
                    cout << endl;
                    break;
                case 7:
                    fplan.updateFlightPlan();     
                    cout << endl;
                    break;
                case 8:
                    fplan.deleteFlightPlan();
                    cout << endl;
                    break;
                case 9:
                    fplan.updateFlightStatus();
                    cout << endl;
                    break;
                case 10:
                    fplan.viewFlightSchedule();
                    cout << endl;
                    break;
                case 11:
                    fplan.calculateFuelRequirements();
                    cout << endl;
                    break;
                case 12:
                    passcheck.checkIn();
                    cout << endl;
                    break;
                case 13:
                    passcheck.issueBoardingPass();
                    cout << endl;
                    break;
                case 14:
                    passcheck.updateBaggageInfo();
                    cout << endl;
                    break;
                case 15:
                    passcheck.cancelCheckIn();
                    cout << endl;
                    break;
                case 16:
                    passcheck.getCheckInStatus();
                    cout << endl;
                    break;
                case 17:
                    passcheck.validatePassenger();
                    cout << endl;
                    break;
                case 18:
                    passcheck.viewPassengerDetails();
                    cout << endl;
                    break;
                case 19:
                    bhand.checkInBaggage();
                    cout << endl;
                    break;
                case 20:
                    bhand.updateTransferStatus();
                    cout << endl;
                    break;
                case 21:
                    chand.calculateCharges();
                    cout << endl;
                    break;
                case 22:
                    am.addAsset();
                    cout <<endl;
                    break;
                case 23:
                    am.updateAsset();
                    cout << endl;
                    break;
                case 24:
                    am.deleteAsset();
                    cout << endl;
                    break;
                case 25:
                    am.retrieveAsset();
                    cout << endl;
                    break;
                case 26:
                    am.viewAssets();
                    cout << endl;
                    break;
                case 27:
                    am.addMaintenanceEvent();
                    cout << endl;
                    break;
                case 28:
                    am.incrementCheckInCount();
                    cout << endl;
                    break;
                case 29:
                    vm.addVehicle();
                    cout << endl;
                    break;
                case 30:
                    vm.updateVehicle();
                    cout << endl;
                    break;
                case 31:
                    vm.deleteVehicle();
                    cout << endl;
                    break;
                case 32:
                    vm.viewVehicleInfo();
                    cout << endl;
                    break;
                case 33:
                    m.scheduleMaintenance();
                    cout << endl;
                    break;
                case 34:
                    m.addMaintenanceRecord();
                    cout << endl;
                    break;
                case 35:
                    cm.addComplaint();
                    cout << endl;
                    break;
                case 36:
                    cm.deleteComplaint();
                    cout << endl;
                    break;
                case 37:
                    break;
            }

            break;
        case 4:
            if (!sp.verifyPassword())
            {
                cout << "Wrong password!";
                break;
            }
            while (choice_sec!=4)
            {
                cout << "\n\n **** Security Personal Dashboard **** " << std::endl;
                cout << "1. Add Incident" << endl;
                cout << "2. Update Incident" << endl;
                cout << "3. View Incidents" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice_sec;

                switch (choice_sec)
                {
                case 1:
                    sec_in.addIncident();
                    cout << endl;
                    break;
                case 2:
                    sec_in.updateIncident();
                    cout << endl;
                    break;

                case 3:
                    sec_in.viewIncidents();
                    cout << endl;
                    break;
                case 4:
                    break;
                }
            }

            break;
        case 5:
            while (choice_pass!=8)
            {
                cout << "\n\n **** Passenger Dashboard ****" << endl;
                cout << "\n\n AIRLINE INFORMATION" << endl;

                cout << "1. Search Airline Information" << endl;
                cout << "2. Retrive Airline Information" << endl;

                cout << "\n\n FLIGHT PLAN" << endl;
                cout << "3. View Flight Schedule" << endl;
                cout << "4. Book Ticket" << endl;
                cout << "5. View Ticket Booking" << endl;

                cout << "\n\n CATERING" << endl;

                cout << "5. In-Flight Menus" << endl;
                cout << "6. Cafes" << endl;

                cout << "\n\n COMPLAINTS "<< endl;
                cout << "7. Add Complaints" << endl;
 
                cout << endl << "8. EXIT" << endl;

                cout << "Enter your choice: ";
                cin >> choice_pass;

                switch (choice_pass)
                {
                case 1:
                    air_info.searchAirline();
                    cout << endl;
                    break;
                case 2:
                    air_info.retrieveAirlineInfo();
                    cout << endl;
                    break;
                case 3:
                    fplan.viewFlightSchedule();
                    cout << endl;
                    break;
                case 4:
                    passcheck.bookTicket();
                    cout << endl;
                    break;
                case 5:
                    passcheck.viewBookedAirlines();
                    cout << endl;
                    break;
                case 6:
                    cat.viewCafeLocations();
                    cout << endl;
                    break;
                case 7:
                    cm.addComplaint();
                    cout << endl;
                    break;
                case 8:
                    cout << endl <<"EXITING..." << endl;
                    break;
                }
            }
            break;
        case 6:
            cout << endl << "EXITING... " << endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
        }
    } while (choice != 6);

    return 0;
}


