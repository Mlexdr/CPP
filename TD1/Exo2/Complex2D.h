#include <iostream>
#include <cmath>
using namespace std;

class Complex2D{
    public:
    Complex2D();
    Complex2D(double , double );
    Complex2D(double );
    Complex2D(const Complex2D& );
    void set(double , double );
    double getA();
    double getB();
    Complex2D plus( Complex2D );
    Complex2D minus( Complex2D );
    Complex2D mult( Complex2D );
    Complex2D divide(Complex2D );
    bool is_smaller(Complex2D );
    bool is_higher( Complex2D );
    void print();
    double norm();
    void is_higher_print(Complex2D);
    void is_smaller_print(Complex2D);

    private:
    double a;
    double b;
    
};