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

