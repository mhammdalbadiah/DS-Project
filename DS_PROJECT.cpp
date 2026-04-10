/*


    4/9/2026

 





######### The Overview ########

Implement a C++ application called Airline Management System. The system operates with
multiple Flights, Offices, and Passengers.
• An Office can issue a Ticket that includes a Passenger and a Flight.
• Each Flight must maintain a list of its issued Tickets, which must be displayed in the
flight's profile.

===========================================================================================

Stucture on mohammed al-badiah 

    Modified at 4/9/2026 12:00 pm 

1) 4 Classes " booking office , passenger , ticket , flight " 
   each class has setter & getter functions , Safety functions to protect the system of invalid input 


*/

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <vector>

using namespace std ;




// ############################################################################
//                                 CLASSES SECTION 
// ############################################################################









// ======== Booking Office Class !! ===========

class Booking_Office {


    string Office_Name , Office_Location , Office_ID ;


public :

    // Modify By Mohammed
    // Safety Functions for the Setter functions

    bool str_check(string Ofc) {

        if (Ofc.empty()) {

            cout << "Invalid Input , Don't make the input empty ! " << endl;
            return false;
        }

        bool onlySpaces = true ;

        for (char c : Ofc) {

            if (!isspace(static_cast<unsigned char>(c))) {
                onlySpaces = false ;
                break ;
            }
        }

        if (onlySpaces) {

            cout << "Invalid Input , Don't make the input spaces only ! " << endl;
            return false;
        }

        if (Ofc.length() < 3 || Ofc.length() > 20) {

            cout << "Invalid Input , Make the input between 3 - 20 characters ! " << endl;
            return false;
        }

        return true;
    }


    bool checkOfficeID() {

        if (Office_ID.empty()) {

            cout << "Office ID cannot be empty !" << endl;
            return false;
        }

        if (Office_ID.length() != 10) {

            cout << "Office ID must be exactly 10 digits !" << endl;
            return false;
        }

        for (char c : Office_ID) {

            if (!isdigit(static_cast<unsigned char>(c))) {

                cout << "Office ID must contain digits only !" << endl;
                return false;
            }
        }

        return true;
    }



    // ############# Setter Functions ! ###########


    void set_Office_Name() {

        string OfcN ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter the Office Name: " ;
            getline(cin, OfcN);

            if (str_check(OfcN)) {

                Office_Name = OfcN;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void set_Office_Location() {

        string OfcL ;

        while (true) {

            cout << "#########################################" << endl;
            cout << "Please Enter the Location of the Office: " ;
            getline(cin, OfcL);

            if (str_check(OfcL)) {

                Office_Location = OfcL;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void set_Office_ID() {

        string ID ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter the Office ID (10 digits): " ;
            getline(cin, ID);

            Office_ID = ID;

            if (checkOfficeID()) {
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    // ##### Getter Functions ! #####
    string get_Office_Name() { return Office_Name; }
    string get_Office_Location() { return Office_Location; }
    string get_Office_ID() { return Office_ID; }

};




// ============== Passengers Class ==============

class Passenger {


    string ID , Name , PassportNo ;


public :


    // ########## Safety Functions for Setter functions #########

    bool checkText(string value) {

        if (value.empty()) {

            cout << "Invalid input , field cannot be empty !" << endl;
            return false;
        }

        bool onlySpaces = true ;

        for (char c : value) {

            if (!isspace(static_cast<unsigned char>(c))) {
                onlySpaces = false ;
                break ;
            }
        }

        if (onlySpaces) {

            cout << "Invalid input , field cannot be spaces only !" << endl;
            return false;
        }

        if (value.length() < 3 || value.length() > 20) {

            cout << "Invalid input , length must be between 3 and 20 !" << endl;
            return false;
        }

        return true;
    }



    bool checkDigitsOnly(string value , int requiredLength) {

        if (value.empty()) {

            cout << "Invalid input , field cannot be empty !" << endl;
            return false;
        }

        if (value.length() != requiredLength) {

            cout << "Invalid input , it must be exactly " << requiredLength << " digits !" << endl;
            return false;
        }

        for (char c : value) {

            if (!isdigit(static_cast<unsigned char>(c))) {

                cout << "Invalid input , digits only !" << endl;
                return false;
            }
        }

        return true;
    }



    bool checkPassportNo(string value) {

        if (value.empty()) {

            cout << "Passport Number cannot be empty !" << endl;
            return false;
        }

        bool onlySpaces = true ;

        for (char c : value) {

            if (!isspace(static_cast<unsigned char>(c))) {
                onlySpaces = false ;
                break ;
            }
        }

        if (onlySpaces) {

            cout << "Passport Number cannot be spaces only !" << endl;
            return false;
        }

        if (value.length() < 5 || value.length() > 15) {

            cout << "Passport Number length must be between 5 and 15 !" << endl;
            return false;
        }

        for (char c : value) {

            if (!isalnum(static_cast<unsigned char>(c))) {

                cout << "Passport Number must contain letters and digits only !" << endl;
                return false;
            }
        }

        return true;
    }



    // ####################### SETTER FUNCTIONS ###########################

    void setID() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Passenger ID: " ;
            getline(cin, input);

            if (checkDigitsOnly(input, 10)) {

                ID = input;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setName() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Passenger Name: " ;
            getline(cin, input);

            if (checkText(input)) {

                Name = input;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setPassportNo() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Passport Number: " ;
            getline(cin, input);

            if (checkPassportNo(input)) {

                PassportNo = input;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    // ############## GETTER FUNCTIONS #################

    string getID() { return ID; }

    string getName() { return Name; }

    string getPassportNo() { return PassportNo; }

};







// ============== Ticket Class ==============

class Ticket {


    string TicketNo , FlightNo , OfficeName ;
    vector<Passenger> PassengerList ;


public :


    // ########## Safety Functions for Setter functions #########

    bool checkText(string value) {

        if (value.empty()) {

            cout << "Invalid input , field cannot be empty !" << endl;
            return false;
        }

        bool onlySpaces = true ;

        for (char c : value) {

            if (!isspace(static_cast<unsigned char>(c))) {
                onlySpaces = false ;
                break ;
            }
        }

        if (onlySpaces) {

            cout << "Invalid input , field cannot be spaces only !" << endl;
            return false;
        }

        if (value.length() < 2 || value.length() > 20) {

            cout << "Invalid input , length must be between 2 and 20 !" << endl;
            return false;
        }

        return true;
    }



    bool checkPassengerList(vector<Passenger> PList) {

        if (PList.empty()) {

            cout << "Passenger List cannot be empty !" << endl;
            return false;
        }

        return true;
    }



    // ####################### SETTER FUNCTIONS ###########################

    void setTicketNo() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Ticket Number: " ;
            getline(cin, input);

            if (checkText(input)) {

                TicketNo = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setFlightNo() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Flight Number: " ;
            getline(cin, input);

            if (checkText(input)) {

                FlightNo = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setOfficeName() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Office Name: " ;
            getline(cin, input);

            if (checkText(input)) {

                OfficeName = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setPassengerList(vector<Passenger> PList) {

        if (checkPassengerList(PList)) {

            PassengerList = PList ;
        }
    }



    // ############## GETTER FUNCTIONS #################

    string getTicketNo() { return TicketNo ; }

    string getFlightNo() { return FlightNo ; }

    string getOfficeName() { return OfficeName ; }

    const vector<Passenger>& getPassengerList() { return PassengerList ; }



    // ########### Display Function ###########

    void displayTicket() {

        cout << "=====================================" << endl;
        cout << "            Ticket Profile           " << endl;
        cout << "=====================================" << endl;
        cout << "Ticket Number  : " << TicketNo << endl;
        cout << "Flight Number  : " << FlightNo << endl;
        cout << "Office Name    : " << OfficeName << endl;
        cout << "Passenger List : " << endl;

        if (PassengerList.empty()) {

            cout << "No Passengers Found !" << endl;
        }

        for (int i = 0 ; i < PassengerList.size() ; i++) {

            cout << i + 1 << ") " << PassengerList[i].getName()
                 << " | ID : " << PassengerList[i].getID()
                 << " | Passport No : " << PassengerList[i].getPassportNo() << endl;
        }

        cout << endl;
    }

};




// ============== Flight Class ==============

class Flight {


    string FlightID , Destination , Gate , DepartureTime ;
    vector<Ticket> TicketList ;


public :


    // ########## Safety Functions for Setter functions #########

    bool checkText(string value) {

        if (value.empty()) {

            cout << "Invalid input , field cannot be empty !" << endl;
            return false;
        }

        bool onlySpaces = true ;

        for (char c : value) {

            if (!isspace(static_cast<unsigned char>(c))) {
                onlySpaces = false ;
                break ;
            }
        }

        if (onlySpaces) {

            cout << "Invalid input , field cannot be spaces only !" << endl;
            return false;
        }

        if (value.length() < 2 || value.length() > 25) {

            cout << "Invalid input , length must be between 2 and 25 !" << endl;
            return false;
        }

        return true;
    }



    bool checkTicketList(vector<Ticket> TList) {

        if (TList.empty()) {

            cout << "Ticket List cannot be empty !" << endl;
            return false;
        }

        return true;
    }



    bool checkDepartureTime(string value) {

        if (value.empty()) {

            cout << "Departure Time cannot be empty !" << endl;
            return false;
        }

        bool onlySpaces = true ;

        for (char c : value) {

            if (!isspace(static_cast<unsigned char>(c))) {
                onlySpaces = false ;
                break ;
            }
        }

        if (onlySpaces) {

            cout << "Departure Time cannot be spaces only !" << endl;
            return false;
        }

        if (value.length() < 3 || value.length() > 20) {

            cout << "Departure Time length must be between 3 and 20 !" << endl;
            return false;
        }

        return true;
    }



    // ####################### SETTER FUNCTIONS ###########################

    void setFlightID() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Flight ID: " ;
            getline(cin, input);

            if (checkText(input)) {

                FlightID = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setDestination() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Destination: " ;
            getline(cin, input);

            if (checkText(input)) {

                Destination = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setGate() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Gate: " ;
            getline(cin, input);

            if (checkText(input)) {

                Gate = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setDepartureTime() {

        string input ;

        while (true) {

            cout << "################################" << endl;
            cout << "Please Enter Departure Time: " ;
            getline(cin, input);

            if (checkDepartureTime(input)) {

                DepartureTime = input ;
                break;
            }
        }

        cout << "################################" << endl;
        cout << endl;
    }



    void setTicketList(vector<Ticket> TList) {

        if (checkTicketList(TList)) {

            TicketList = TList ;
        }
    }



    // ############## GETTER FUNCTIONS #################

    string getFlightID() { return FlightID ; }

    string getDestination() { return Destination ; }

    string getGate() { return Gate ; }

    string getDepartureTime() { return DepartureTime ; }

    const vector<Ticket>& getTicketList() { return TicketList ; }



    // ########### Display Function ###########

    void displayFlightProfile() {

        cout << "=====================================" << endl;
        cout << "            Flight Profile           " << endl;
        cout << "=====================================" << endl;
        cout << "Flight ID       : " << FlightID << endl;
        cout << "Destination     : " << Destination << endl;
        cout << "Gate            : " << Gate << endl;
        cout << "Departure Time  : " << DepartureTime << endl;
        cout << "Issued Tickets  : " << endl;

        if (TicketList.empty()) {

            cout << "No Tickets Found !" << endl;
        }

        for (int i = 0 ; i < TicketList.size() ; i++) {

            cout << i + 1 << ") Ticket No : " << TicketList[i].getTicketNo()
                 << " | Office Name : " << TicketList[i].getOfficeName()
                 << " | Flight No : " << TicketList[i].getFlightNo() << endl;
        }

        cout << endl;
    }

};
