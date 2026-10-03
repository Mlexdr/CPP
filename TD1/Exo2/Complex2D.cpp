#include "Complex2D.h"

void Complex2D::print(){
        std::cout << std::endl<< "Partie Reelle : ";
        std::cout<<this->getA();
        std::cout <<std::endl<<"Partie Imaginaire : ";
        std::cout<<this->getB();
 
}

Complex2D::Complex2D(){
    this->a=0;this->b=0;
}
Complex2D::Complex2D(double a, double b){
    this->a=a;this->b=b;
}
Complex2D::Complex2D(double x){
    this->a=x;this->b=x;
}
Complex2D::Complex2D(const Complex2D& c){
    a=c.a,b=c.b;
}

void Complex2D::set(double a, double b){
    this->a=a;this->b=b;
}
double Complex2D::getA(){
    return this->a;
}
double Complex2D::getB(){
    return this->b;
}

Complex2D Complex2D::plus( Complex2D b){
    Complex2D result(this->getA()+b.getA(),this->getB()+b.getB());
    return result;
}
Complex2D Complex2D::minus( Complex2D b){
    Complex2D result(this->getA()-b.getA(),this->getB()-b.getB());
    return result;
}
Complex2D Complex2D::mult( Complex2D c){
    
    Complex2D result(this->a*c.getA()-this->b*c.getB(),this->b*c.getA()+c.getB()*this->a);
    return result;
}


Complex2D Complex2D::divide(Complex2D c){
    double re=(a*c.getA()+b*c.getB())/(c.getA()*c.getA()+c.getB()*c.getB());
    double im=(b*c.getA()-a*c.getB())/(c.getA()*c.getA()+c.getB()*c.getB());
    Complex2D res=Complex2D(re,im);
    return res;
}
double Complex2D::norm(){
    return sqrt(a*a+b*b);
}
bool Complex2D::is_higher(Complex2D c){
    bool res=(this->norm()>c.norm());
    return res;
}
bool Complex2D::is_smaller(Complex2D c){
    bool res=(this->norm()<c.norm());
    return res;
}
void Complex2D::is_higher_print(Complex2D c){
    if (this->is_higher(c)){
        std::cout<<"True";
    }
    else{
        std::cout<<"False";
    };
}
void Complex2D::is_smaller_print(Complex2D c){
    if (this->is_smaller(c)){
        std::cout<<"True";
    }
    else{
        std::cout<<"False";
    };
}


