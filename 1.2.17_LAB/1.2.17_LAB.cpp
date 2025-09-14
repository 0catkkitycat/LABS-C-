#include <iostream>
#include <string>
#include <cmath>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) {
        if (den == 0) {
            std::cerr << "Warning: Denominator can't be zero. Setting to 0/1." << std::endl;
            this->numerator = 0;
            this->denominator = 1;
            return;
        }

        if (den < 0) {
            num = -num;
            den = -den;
        }
        int common = gcd(std::abs(num), den);
        this->numerator = num / common;
        this->denominator = den / common;
    }

    std::string toString() const {
        if (numerator == 0) {
            return "0";
        }

        int absNum = std::abs(numerator);
        int absDen = std::abs(denominator);
        std::string result = "";

        if (numerator < 0) {
            result += "-";
        }

        int wholePart = absNum / absDen;
        int remainingNum = absNum % absDen;

        if (wholePart > 0) {
            result += std::to_string(wholePart);
            if (remainingNum > 0) {
                result += " ";
            }
        }

        if (remainingNum > 0) {
            result += std::to_string(remainingNum) + "/" + std::to_string(absDen);
        }

        return result;
    }

    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    void printFraction() const {
        std::cout << toString() << " is " << toDouble() << " in decimal" << std::endl;
    }

    Fraction add(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction subtract(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Warning: Can't divide by zero fraction." << std::endl;
            return Fraction(0, 1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
};

int main() {
    int num1, den1, num2, den2;
    char slash;

    std::cout << "Enter the first fraction (e.g., 3/4): ";
    if (!(std::cin >> num1 >> slash >> den1) || slash != '/') {
        std::cout << "Invalid input format." << std::endl;
        return 1;
    }

    std::cout << "Enter the second fraction (e.g., 1/2): ";
    if (!(std::cin >> num2 >> slash >> den2) || slash != '/') {
        std::cout << "Invalid input format." << std::endl;
        return 1;
    }

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    std::cout << "\n--- Arithmetic Operations ---" << std::endl;
    std::cout << f1.toString() << " + " << f2.toString() << " = ";
    f1.add(f2).printFraction();

    std::cout << f1.toString() << " - " << f2.toString() << " = ";
    f1.subtract(f2).printFraction();

    std::cout << f1.toString() << " * " << f2.toString() << " = ";
    f1.multiply(f2).printFraction();

    std::cout << f1.toString() << " / " << f2.toString() << " = ";
    f1.divide(f2).printFraction();

    return 0;
}