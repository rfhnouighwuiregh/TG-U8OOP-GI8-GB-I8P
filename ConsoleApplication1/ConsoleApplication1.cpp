#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Point {
    double x, y;
    Point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
};


class Figure {
public:
    virtual double Square() const = 0;    
    virtual double Perimeter() const = 0; 
    virtual Point Center() const = 0;     
    virtual ~Figure() {}                  
};

class Triangle : public Figure {
private:
    Point p1, p2, p3;  

public:
    Triangle(Point a = Point(0, 0), Point b = Point(1, 0), Point c = Point(0, 1))
        : p1(a), p2(b), p3(c) {}

    double Square() const override {
       
        return 0.5 * std::abs(
            p1.x * (p2.y - p3.y) +
            p2.x * (p3.y - p1.y) +
            p3.x * (p1.y - p2.y)
        );
    }

    double Perimeter() const override {
        double a = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
        double b = std::sqrt(std::pow(p3.x - p2.x, 2) + std::pow(p3.y - p2.y, 2));
        double c = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));
        return a + b + c;
    }

    Point Center() const override {
        
        return Point((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3);
    }
};

class Parallelogram : public Figure {
private:
    Point p1, p2, p3;  

public:
    Parallelogram(Point a = Point(0, 0), Point b = Point(2, 0), Point c = Point(1, 2))
        : p1(a), p2(b), p3(c) {}

    double Square() const override {
       
        double vec1x = p2.x - p1.x;
        double vec1y = p2.y - p1.y;
        double vec2x = p3.x - p1.x;
        double vec2y = p3.y - p1.y;
        return std::abs(vec1x * vec2y - vec1y * vec2x);
    }

    double Perimeter() const override {
        double side1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
        double side2 = std::sqrt(std::pow(p3.x - p1.x, 2) + std::pow(p3.y - p1.y, 2));
        return 2 * (side1 + side2);
    }

    Point Center() const override {
       
        Point p4(p1.x + p2.x - p3.x, p1.y + p2.y - p3.y); 
        return Point((p1.x + p2.x + p3.x + p4.x) / 4, (p1.y + p2.y + p3.y + p4.y) / 4);
    }
};

class Circle : public Figure {
private:
    Point center;
    double radius;

public:
    Circle(Point c = Point(0, 0), double r = 1) : center(c), radius(r) {}

    double Square() const override {
        return M_PI * radius * radius;
    }

    double Perimeter() const override {
        return 2 * M_PI * radius;
    }

    Point Center() const override {
        return center;
    }
};


int main() {
    Triangle t;
    Parallelogram p;
    Circle c;

    std::cout << "Triangle:\n";
    std::cout << "Area: " << t.Square() << "\n";
    std::cout << "Perimeter: " << t.Perimeter() << "\n";
    std::cout << "Center: (" << t.Center().x << ", " << t.Center().y << ")\n\n";

    std::cout << "Parallelogram:\n";
    std::cout << "Area: " << p.Square() << "\n";
    std::cout << "Perimeter: " << p.Perimeter() << "\n";
    std::cout << "Center: (" << p.Center().x << ", " << p.Center().y << ")\n\n";

    std::cout << "Circle:\n";
    std::cout << "Area: " << c.Square() << "\n";
    std::cout << "Perimeter: " << c.Perimeter() << "\n";
    std::cout << "Center: (" << c.Center().x << ", " << c.Center().y << ")\n";

    return 0;
}