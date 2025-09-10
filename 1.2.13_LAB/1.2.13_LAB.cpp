#include <iostream>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
private:
    int id;
    int capacity;
    int reserved;

public:
    void addReservations(int Seats);
	void cancelReservations(int Seats);

};

void FlightBooking::printStatus()
{
    std::cout << "Flight " << id << " " << reserved << "/" << capacity << " ( " << 100 / capacity * reserved << "%)" << std::endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    if (reserved > capacity * 1.05) {
        std::cout << "Las reservas no pueden ser más del 105% de la capacidad " << std::endl;
        reserved = 0;
    }

    if (reserved < 0) {
        reserved = 0; 
    }
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
   
}

void FlightBooking::addReservations(int Seats) 
{
    if (Seats < 0) {
		std::cout << "No se pueden tener reservas negativas " << std::endl;
        return;
	}
    if (capacity * 1.05 < reserved + Seats) {
        std::cout << "Las reservas no pueden ser más del 105% de la capacidad " << std::endl;
        return;
    }

	this->reserved += Seats;
}

void FlightBooking::cancelReservations(int Seats) {
    if (Seats > reserved) {
        reserved = 0;
		return;
    }
    if (Seats < 0) {
        std::cout << "No se pueden cancelar reservas negativas " << std::endl;
        return;
    }

	this->reserved -= Seats;
}

int main() {
    int reserved = 0,
        capacity = 0;
    std::string input = "";

    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;

    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;

    FlightBooking booking(1, capacity, reserved);
    while (input != "exit") {
        input = "";
        reserved = 0;
        capacity = 0;

        booking.printStatus();
		std::cin >> input;
        if (input == "add") {
            std::cout << "¿Cuántos asientos desea reservar? " << std::endl;
            std::cin >> reserved;
            booking.addReservations(reserved);
        }
        else if (input == "cancel") {
            std::cout << "¿Cuántos asientos desea cancelar?" << std::endl;
            std::cin >> reserved;
            booking.cancelReservations(reserved);
        }

    }
   

    return 0;
}
