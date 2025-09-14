#include <iostream>
#include <array>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus(); FlightBooking();
private:
    int id;
    int capacity;
    int reserved;

public:
    void addReservations(int Seats);
    void cancelReservations(int Seats);
	int getid() const { return id; }

};

FlightBooking::FlightBooking() {
    id = 0;
    capacity = 0;
    reserved = 0;
}

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
        std::cout << "You cannot have negative reservations " << std::endl;
        return;
    }
    if (capacity * 1.05 < reserved + Seats) {
        std::cout << "Reservations cannot be more than 105% of capacity " << std::endl;
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
        std::cout << "Negative reservations cannot be canceled " << std::endl;
        return;
    }

    this->reserved -= Seats;
}


int main() {
    const int MaxBooking = 10;
    FlightBooking booking[MaxBooking];

    while (1) {
        std::string input = " ";

        std::cout << "What do you want to do?" << std::endl;
        std::cin >> input;

        if (input == "exit") {
            break;
        }
        else if (input == "create") {
            int id, capacity, reserved;
            std::cout << "Enter flight ID, capacity and reserved seats: ";
            std::cin >> id >> capacity >> reserved;
            bool exists = false;
            for (int i = 0; i < MaxBooking; i++) {
                if (booking[i].getid() == id) {
                    exists = true;
                    std::cout << "Flight with this ID already exists." << std::endl;
                    break;
                }
            }
            if (!exists) {
                for (int i = 0; i < MaxBooking; i++) {
                    if (booking[i].getid() == 0) {
                        booking[i] = FlightBooking(id, capacity, reserved);
                        break;
                    }
                }
            }
        }
        else if (input == "add") {
            int id, seats;
            std::cout << "Enter flight ID and number of seats to add: ";
            std::cin >> id >> seats;
            bool found = false;
            for (int i = 0; i < MaxBooking; i++) {
                if (booking[i].getid() == id) {
                    booking[i].addReservations(seats);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Flight with this ID does not exist." << std::endl;
            }
        }
        else if (input == "cancel") {
            int id, seats;
            std::cout << "Enter flight ID and number of seats to cancel: ";
            std::cin >> id >> seats;
            bool found = false;
            for (int i = 0; i < MaxBooking; i++) {
                if (booking[i].getid() == id) {
                    booking[i].cancelReservations(seats);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Flight with this ID does not exist." << std::endl;
            }
        }
        else if(input == "delete") {
            int id;
			std::cout << "Enter flight ID to delete: ";
			std::cin >> id;
			bool found = false;
            for (int i = 0; i < MaxBooking; i++) {
                if (booking[i].getid() == id) {
                    booking[i] = FlightBooking();
                    found = true;
                    break;
                }
            }
        }
        else if (input == "print") {
            for (int i = 0; i < MaxBooking; i++) {
                if (booking[i].getid() != 0) {
                    booking[i].printStatus();
                }
            }
        }
        else {
            std::cout << "Unknown command." << std::endl;
        }
        
    }return 0;
}
