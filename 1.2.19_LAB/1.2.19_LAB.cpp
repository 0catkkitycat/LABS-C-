#include <iostream>
#include <string>
#include <cmath>

class Point2D {
private:
    double x;
    double y;

public:
    Point2D(double x, double y);
    Point2D();
    std::string toString();

    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    double distanceTo(Point2D that);
};

Point2D::Point2D() {
    this->x = 0;
    this->y = 0;
}

Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}

std::string Point2D::toString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

double Point2D::distanceTo(Point2D that) {
    double diffX = x - that.getX();
    double diffY = y - that.getY();
    return sqrt(pow(diffX, 2) + pow(diffY, 2));
}

int main() {
    Point2D points[2];
    double x_coord, y_coord;
    char comma;

    for (int i = 0; i < 2; i++) {
        std::cout << "Please provide point " << i + 1 << " in (x,y) format: ";
        if (std::cin >> x_coord >> comma >> y_coord && comma == ',') {
            points[i] = Point2D(x_coord, y_coord);
            std::cout << "Added point " << points[i].toString() << std::endl;
        }
        else {
            std::cout << "Invalid input. Please use the format 'x,y'." << std::endl;
            std::cin.ignore(100, '\n');
            i--;
        }
    }

    std::cout << "The distance between point " << points[0].toString() << " and point " << points[1].toString() << " is " << points[0].distanceTo(points[1]) << std::endl;

    return 0;
}