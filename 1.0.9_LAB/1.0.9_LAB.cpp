#include <iostream>
#include <string>

using namespace std;

class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area()
	{
		return side * side; 
	}

private:
	double    side;
};

AdHocSquare::AdHocSquare(double side)
{
	this->side = side;
}

void AdHocSquare::set_side(double new_side) {
		if (new_side >= 0) {
		this->side = new_side;
		}
}


class LazySquare
{
public:
	LazySquare(double side);
	void set_side(double side);
	double get_area();
private:
	double    side;
	double    area;
	bool      side_changed;
};

LazySquare::LazySquare(double side) {
	this->side = side;
	this->area = side * side;
	this->side_changed = false;
}

void LazySquare::set_side(double side) {
	this->side = side;
	this->side_changed = true;
}

double LazySquare::get_area() {
	if (side_changed) {
		area = side * side;
	}

	return area;
}

int main() {
	AdHocSquare s1(20);
	LazySquare s2(27);

	cout << "AdHocSquare area: " << s1.get_area() << endl;
	s1.set_side(10);
	cout << "AdHocSquare area: " << s1.get_area() << endl;

	cout << "LazySquare area: " << s2.get_area() << endl;
	s2.set_side(10);
	cout << "LazySquare area: " << s2.get_area() << endl;
}
