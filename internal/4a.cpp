#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    int *real;
    int *imag;

public:
    Complex() {
        real = new int;
        imag = new int;
    }

    Complex(int x, int y) {
        real = new int;
        imag = new int;
        *real = x;
        *imag = y;
    }

    Complex(const Complex &c) {
        cout << "Copy Constructor invoked\n";
        real = new int;
        imag = new int;
        *real = *c.real;
        *imag = *c.imag;
    }

    ~Complex() {
        delete real;
        delete imag;
    }

    void display() {
        cout << "Complex Value:\n" << *real << "+i" << *imag << endl;
    }

    void read() {
        int r, i;
        cout << "Enter Real Value\n";
        cin >> r;
        cout << "Enter Imaginary Value\n";
        cin >> i;
        *real = r;
        *imag = i;
    }

    int getreal() {
        return *real;
    }

    int getimag() {
        return *imag;
    }

    void operator=(const Complex &c) {
        *real = *c.real;
        *imag = *c.imag;
        cout << "Operator Assignment worked\n";
        cout << *real << "+i" << *imag << endl;
    }

    Complex operator+(const Complex &C) {
        Complex Ctemp;
        *Ctemp.real = *real + *C.real;
        *Ctemp.imag = *imag + *C.imag;
        return Ctemp;
    }

    Complex& operator+=(const Complex &C) {
        *real = *real + *C.real;
        *imag = *imag + *C.imag;
        return *this;
    }

    void operator++() {
        *real = *real + 1;
        *imag = *imag + 1;
    }

    bool operator==(const Complex &c) const {
        int mod1, mod2;
        mod1 = sqrt((*real) * (*real) + (*imag) * (*imag));
        mod2 = sqrt((*c.real) * (*c.real) + (*c.imag) * (*c.imag));

        return mod1 == mod2;
    }

    friend bool operator>(const Complex &a, const Complex &b);
    friend bool operator>=(const Complex &a, const Complex &b);
    friend bool operator<=(const Complex &a, const Complex &b);
};

bool operator>(const Complex &a, const Complex &b) {
    double sum1 = 0, sum2 = 0;
    sum1 = sqrt(pow(*(a.real), 2) + pow(*(a.imag), 2));
    sum2 = sqrt(pow(*(b.real), 2) + pow(*(b.imag), 2));
    return sum1 > sum2;
}

bool operator>=(const Complex &a, const Complex &b) {
    double sum1 = 0, sum2 = 0;
    sum1 = sqrt(pow(*(a.real), 2) + pow(*(a.imag), 2));
    sum2 = sqrt(pow(*(b.real), 2) + pow(*(b.imag), 2));
    return sum1 >= sum2;
}

bool operator<=(const Complex &a, const Complex &b) {
    double sum1 = 0, sum2 = 0;
    sum1 = sqrt(pow(*(a.real), 2) + pow(*(a.imag), 2));
    sum2 = sqrt(pow(*(b.real), 2) + pow(*(b.imag), 2));
    return sum1 <= sum2;
}

int main() {
    Complex c1;
    Complex c2(3, 5);
    Complex c4(6, 8), c5(6, -8);

    c2.display();
    c1 = c2 + c4;
    cout << "\nAddition of C2 and C4 complex numbers\n";
    c1.display();
    c1 = c2; //assignment operator
    if (c4 == c1)
        cout << "\nBoth complex numbers are equivalent\n";
    else
        cout << "\nBoth complex numbers are not equivalent\n";

    if (c4 > c1)
        cout << "\nC4 is greater than C1\n";
    else
        cout << "\nC1 is greater than C4\n";

    if (c4 >= c1)
        cout << "\nC4 is greater than or equal to C1\n";
    else
        cout << "\nC1 is greater than C4\n";

    if (c2 <= c4)
        cout << "\nC2 is less than or equal to C1\n";
    else
        cout << "\nC4 is greater than C2\n";

    cout << "\nPre-incrementing C5\n";
    ++c5;
    c5.display();

    c5 += c4;
    c5.display();

    Complex c3 = c1;
    c3.display();

    return 0;
}

