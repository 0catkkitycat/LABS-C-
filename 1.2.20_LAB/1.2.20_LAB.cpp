#include <iostream>
#include <string>
#include <cmath>
#include <limits>

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

class Line2D {
private:
    double slope;
    double y_intercept;

public:
    Line2D(const Point2D& p1, const Point2D& p2);
    std::string toString() const;
};

Line2D::Line2D(const Point2D& p1, const Point2D& p2) {
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();

    if (dx == 0) {
        this->slope = std::numeric_limits<double>::infinity();
        this->y_intercept = p1.getX();
    }
    else {
        this->slope = dy / dx;
        this->y_intercept = p1.getY() - this->slope * p1.getX();
    }
}

std::string Line2D::toString() const {
    if (std::isinf(slope)) {
        return "x = " + std::to_string(y_intercept);
    }

    std::string sign = (y_intercept >= 0) ? " + " : " - ";
    return "y = " + std::to_string(slope) + "x" + sign + std::to_string(std::abs(y_intercept));
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
            std::cin.clear();
            std::cin.ignore(100, '\n');
            i--;
        }
    }

    std::cout << "\n--- Line Information ---" << std::endl;
    Line2D line(points[0], points[1]);
    std::cout << "The equation of the line is: " << line.toString() << std::endl;

    return 0;
}