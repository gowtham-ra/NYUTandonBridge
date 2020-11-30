// Created by Gowtham Ra on 30/09/20.
// Program to implement different operator overloading.

#include <iostream>
using namespace std;

class Vector {
    double x;
    double y;

public:
    Vector(double xX, double yY) : x(xX), y(yY) {}
    Vector() : x(0.0), y(0.0) {}

    double getX() const {
        return x;
    }
    void setX(double x) {
        Vector::x = x;
    }
    double getY() const {
        return y;
    }
    void setY(double y) {
        Vector::y = y;
    }

    friend Vector operator + (const Vector& obj1, const Vector& obj2);
    Vector& operator = (const Vector& obj);
    friend bool operator == (const Vector& obj1, const Vector& obj2);
    Vector operator ++ ();
    Vector operator ++ (int);

    friend ostream& operator << (ostream& out, const Vector& obj);

};

Vector operator+(const Vector &obj1, const Vector &obj2) {
    Vector temp;
    temp.x = obj1.x + obj2.x;
    temp.y = obj1.y + obj2.y;
    return temp;
}

Vector& Vector::operator=(const Vector &obj) {
    this->x = obj.x;
    this->y = obj.y;
    return *this;
}

bool operator==(const Vector &obj1, const Vector &obj2) {
    if (obj1.x == obj2.x && obj1.y == obj2.y)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &out, const Vector &obj) {
    out << obj.x << ", " << obj.y << endl;
    return out;
}

Vector Vector::operator++() {
    Vector temp;
    temp.x = ++x;
    temp.y = ++y;
    return temp;
}

Vector Vector::operator++(int) {
    Vector temp;
    temp.x = x++;
    temp.y = y++;
    return temp;
}


int main() {
    Vector speed(1.5, 2.5);
    Vector distance(3.5, 4.5);
    Vector result;

    result = speed + distance;

    cout << result;

    return 0;
}

