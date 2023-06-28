#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    void validateSides() {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
            throw runtime_error("Invalid side length. All sides must be greater than 0.");
        }
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            throw runtime_error("Invalid side lengths. The sum of any two sides must be greater than the third side.");
        }
    }

    double calculateAreaRightAngle() {
        validateSides();
        // Assuming side1 and side2 are the perpendicular sides (legs) of the right-angled triangle
        return (side1 * side2) / 2.0;
    }

    double calculateAreaHeron() {
        validateSides();
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

int main() {
    double side1, side2, side3;

    try {
        cout << "Enter the lengths of the 3 sides of the triangle: ";
        cin >> side1 >> side2 >> side3;

        Triangle triangle(side1, side2, side3);

        double areaRightAngle = triangle.calculateAreaRightAngle();
        cout << "Area of the right-angled triangle: " << areaRightAngle << endl;

        double areaHeron = triangle.calculateAreaHeron();
        cout << "Area of the triangle using Heron's formula: " << areaHeron << endl;
    }
    catch (const exception& ex) {
        cout << "Error: " << ex.what() << endl;
    }

    return 0;
}

