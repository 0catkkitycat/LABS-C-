#include <iostream>
#include <string>

class FarmAnimal {
public:

    virtual double getWaterConsumption() const = 0;

};

class cow : public FarmAnimal {
private:
    double weight;
public:
    cow(double weight) : weight(weight) {}
    double getWaterConsumption() const override { return weight / 100 * 8.6; }
};

class sheep : public FarmAnimal {
private:
    double weight;
public:
    sheep(double weight) : weight(weight) {}
    double getWaterConsumption() const override { return weight / 10 * 1.1; }
};

class horse : public FarmAnimal {
private:
    double weight;
public:
    horse(double weight) : weight(weight) {}
    double getWaterConsumption() const override { return weight / 100 * 6.8; }
};

int main() {

    double waterConsumption = 0.0;
    std::string animal;
    double weight;


    while (true) {
        std::cout << "Enter the animal species (cow, sheep, horse, or quit): \n";
        std::cin >> animal;


        if (animal == "quit") {
            std::cout << "\nThe total water consumption is: " << waterConsumption << std::endl;
            break;
        }

        std::cout << "Enter animal weight: \n";
        std::cin >> weight;

        if (animal == "cow") {
            cow myCow(weight);
            waterConsumption += myCow.getWaterConsumption();
        }
        else if (animal == "sheep") {
            sheep mySheep(weight);
            waterConsumption += mySheep.getWaterConsumption();
        }
        else if (animal == "horse") {
            horse myHorse(weight);
            waterConsumption += myHorse.getWaterConsumption();
        }
        else {
            std::cout << "Invalid animal species. Please try again.\n";
        }

        std::cout << "The total water consumption is: " << waterConsumption << std::endl;
    }



    return 0;
}