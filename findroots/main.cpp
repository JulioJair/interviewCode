//Find roots of cubic equation

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
//Assign the command line arguments to vars
    string aString(argv[1]);
    double a = stof(aString);

    string bString(argv[2]);
    double b = stof(bString);

    string cString(argv[3]);
    double c = stof(cString);

    string dString(argv[4]);
    double d = stof(dString);

    double r1, r2, r3;
    double Re[3] = {};
    const double PI = 4 * atan(1);

    // Reduced equation: X^3 - 3pX - 2q = 0, where X = x-b/(3a)
    double p = (pow(b, 2) - 3 * a * c) / (9. * pow(a, 2));
    double q = (9 * a * b * c - 27.0 * pow(a, 2) * d - 2 * pow(b, 3)) / (54 * pow(a, 3));
    double offset = b / (3 * a);

    // Discriminant
    double discriminant = pow(p, 3) - pow(q, 2);

    cout << "{";
    if (discriminant > 0) //then the equation has three distinct real roots.
    {
        double theta = acos(q / (p * sqrt(p)));
        double r = 2 * sqrt(p);
        for (int n = 0; n < 3; n++) Re[n] = r * cos((theta + 2 * n * PI) / 3) - offset;
        cout << Re[0] << "," << Re[1] << "," << Re[2];
    } else {
        double gamma1 = cbrt(q + sqrt(-discriminant));
        double gamma2 = cbrt(q - sqrt(-discriminant));

        r1 = gamma1 + gamma2 - offset;
        cout << r1;

        double re = -0.5 * (gamma1 + gamma2) - offset;
//        double im = (gamma1 - gamma2) * sqrt(3) / 2;
        if (discriminant == 0) //then the equation has a repeated root and all its roots are real.
        {
            r2 = re;
            r3 = re;
            cout << "," << r2 << "," << r3;
        } else { //then the equation has one real root and two non-real complex conjugate roots.
//            cout << re << " + " << im << " i\n";
//            cout << re << " - " << im << " i\n";
        }
    }

    cout << "}" << endl;

    return 0;
}
