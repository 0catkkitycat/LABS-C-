#include <iostream>


class FarmAnimal {
public:
    FarmAnimal(double water_consumption);
    double getWaterConsumption();
    virtual std::string getName() { return name; }
    std::string name = "cat";

private:

    double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption) {
    this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption() {
    return water_consumption;
}


class dog : public FarmAnimal {
public:
    dog();

};

dog::dog() : FarmAnimal(10.0)
{
    name = "dog";
}

class elephant : public FarmAnimal
{
public:
    elephant(double given_water_consumption);
};

elephant::elephant(double given_water_consumption)
    : FarmAnimal(given_water_consumption) {
    name = "elephant";
}

void printConsumption(FarmAnimal& animal)
{
    std::cout << "The " << animal.getName() << " consumes " << animal.getWaterConsumption()
        << " liters of water\n";
}

int main()
{
    FarmAnimal animalA(5);
    dog animalB;
    elephant animalC(21);

    std::cout << animalA.getName() << " consumes " << animalA.getWaterConsumption()
        << " liters of water.\n";
    std::cout << "What about the others?\n";

    printConsumption(animalB);
    printConsumption(animalC);

    return 0;
}