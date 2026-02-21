#include<iostream>
#include<string>
using namespace std;

class user{
public:
    string username;
    string email;
    bool login(string inputPass)
    

    
    void logout();
    int User(string u, string e, string p) : username(u), email(e), password(p)
};
private:{

    string password;
    int ph_no;
    string role;


};

class Passenger
{
private:
    int passengerId;
    string name;
    string phone;

    bool validatePassport();   // internal

public:
    void addPassenger();
    void updatePassenger();
};

class Flight
{
private:
    int flightId;
    string source;
    string destination;
    int totalSeats;
    int availableSeats;

    void updateSeatCount();   // internal helper

public:
    Flight();
    void addFlight();
    void updateFlight();
    void deleteFlight();
    bool checkAvailability();
};

class Booking
{
private:
    int bookingId;
    int flightId;
    int passengerId;

    void generateBookingID();   // internal
    void updateSeat();          // internal

public:
    void createBooking();
    void cancelBooking();
};

int main(){


}