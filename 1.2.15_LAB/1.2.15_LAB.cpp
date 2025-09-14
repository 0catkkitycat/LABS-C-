#include <iostream>

class GymMember {
private:
    int id;
    int months;
    char name[50]; // Usamos un array de char para el nombre

public:
    GymMember(int id, const char* memberName, int months) {
        this->id = id;
        this->months = months;
        // Copia el nombre
        int i = 0;
        while (memberName[i] != '\0' && i < 49) {
            this->name[i] = memberName[i];
            i++;
        }
        this->name[i] = '\0';
    }

    GymMember() {
        this->id = 0;
        this->months = 0;
        this->name[0] = '\0'; // Marca el slot como vacío
    }

    int getID() const {
        return this->id;
    }

    void printStatus() const {
        if (id == 0) {
            return;
        }
        std::cout << "Member [" << id << "]: " << name << " - " << months << " months remaining." << std::endl;
    }

    bool extendMembership(int n) {
        if (n <= 0) {
            std::cout << "Cannot perform this operation: Months to extend must be a positive number." << std::endl;
            return false;
        }
        this->months += n;
        std::cout << "Membership extended by " << n << " months for " << name << "." << std::endl;
        return true;
    }

    bool cancelMembership() {
        if (this->months == 0) {
            std::cout << "Cannot perform this operation: Membership is already canceled." << std::endl;
            return false;
        }
        this->months = 0;
        std::cout << "Membership canceled for " << name << "." << std::endl;
        return true;
    }
};

int main() {
    const int MAX_MEMBERS = 10;
    GymMember members[MAX_MEMBERS];

    char command[20];
    int id, n;
    char name[50];
    bool found;

    while (true) {
        std::cout << "\n--- Current Members ---" << std::endl;
        for (int i = 0; i < MAX_MEMBERS; i++) {
            members[i].printStatus();
        }
        std::cout << "-----------------------" << std::endl;

        std::cout << "Enter command (create, delete, extend, cancel, quit): ";
        std::cin >> command;

        if (std::strcmp(command, "quit") == 0) {
            break;
        }

        if (std::strcmp(command, "create") == 0) {
            std::cout << "Enter member ID and name: ";
            std::cin >> id;
            std::cin.getline(name, 50);

            if (id <= 0) {
                std::cout << "Cannot perform this operation: ID must be a positive number." << std::endl;
                continue;
            }

            found = false;
            for (int i = 0; i < MAX_MEMBERS; i++) {
                if (members[i].getID() == id) {
                    std::cout << "Cannot perform this operation: A member with this ID already exists." << std::endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                int emptyIndex = -1;
                for (int i = 0; i < MAX_MEMBERS; i++) {
                    if (members[i].getID() == 0) {
                        emptyIndex = i;
                        break;
                    }
                }
                if (emptyIndex != -1) {
                    members[emptyIndex] = GymMember(id, name, 0);
                    std::cout << "Member [" << id << "] " << name << " created successfully." << std::endl;
                }
                else {
                    std::cout << "Cannot perform this operation: Maximum number of members reached." << std::endl;
                }
            }
        }
        else if (std::strcmp(command, "delete") == 0) {
			std::cout << "Enter member ID to delete: ";
            std::cin >> id;
            found = false;
            for (int i = 0; i < MAX_MEMBERS; i++) {
                if (members[i].getID() == id) {
                    members[i] = GymMember();
                    std::cout << "Member [" << id << "] deleted successfully." << std::endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Cannot perform this operation: Member ID not found." << std::endl;
            }
        }
        else if (std::strcmp(command, "extend") == 0) {
			std::cout << "Enter member ID and number of months to extend: ";
            std::cin >> id >> n;
            found = false;
            for (int i = 0; i < MAX_MEMBERS; i++) {
                if (members[i].getID() == id) {
                    members[i].extendMembership(n);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Cannot perform this operation: Member ID not found." << std::endl;
            }
        }
        else if (std::strcmp(command, "cancel") == 0) {
			std::cout << "Enter member ID to cancel membership: ";
            std::cin >> id;
            found = false;
            for (int i = 0; i < MAX_MEMBERS; i++) {
                if (members[i].getID() == id) {
                    members[i].cancelMembership();
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Cannot perform this operation: Member ID not found." << std::endl;
            }
        }
        else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    return 0;
}