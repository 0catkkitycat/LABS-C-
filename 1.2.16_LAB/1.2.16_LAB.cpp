#include <iostream>
#include <string>

using namespace std;

class Fraction{
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
private:
  int numerator;
  int denominator;
};

// implement Fraction methods

Fraction::Fraction(int numerator, int denominator) {
	if (denominator == 0) {
		throw std::invalid_argument("Denominator cannot be zero.");
	}
	this->numerator = numerator;
	this->denominator = denominator;
}

string Fraction::toString() {
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

double Fraction::toDouble() {
	return static_cast<double>(numerator) / denominator;
}

int main(void) {
  int num, den;
  char slash;
  std::string input = "";
  std::getline(std::cin, input);

  // parse input and get numerator and denominator
  std::cout << "Enter a fraction (numerator/denominator): ";{}
  if (std::cin >> num >> slash >> den && slash == '/') {
	  Fraction fraction(num, den);
	  std::cout << fraction.toString() << " is "
		  << fraction.toDouble() << "  in decimal :)" << std::endl;
  }
  else {
	  std::cout << "Unrecognized input, try again with something else :(" << std::endl;
  }
  Fraction fraction(num, den);
	return 0;
}