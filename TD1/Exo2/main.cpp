#include "Complex2D.h"

int main(){
    Complex2D z1(1,2);
    std::cout<<std::endl<< std::endl<<"z1= 1+ 2i \nz1:";
    z1.print();

    z1.set(2,3);
    std::cout<<std::endl<< std::endl<<"z1= 2+ 3i \nz1:";
    z1.print();
    
    std::cout<<std::endl<<std::endl<<"Re(z1)=";
    std::cout<<z1.getA();

    std::cout<<std::endl<<std::endl<<"Im(z1)=";
    std::cout<<z1.getB();

    Complex2D z2(5,6);
    std::cout<<std::endl<< std::endl<<"z2= 5+ 6i \nz2:";
    z2.print();
    
    std::cout<<std::endl<< std::endl<<"z3 = z1 + z2\nz3:";
    Complex2D z3(z1.plus(z2));
    z3.print();

    std::cout<<std::endl<< std::endl<<"z4 = z1 - z2\nz4:";
    Complex2D z4(z1.minus(z2));
    z4.print();

    std::cout<<std::endl<< std::endl<<"z5 = z1 * z2\nz5:";
    Complex2D z5(z1.mult(z2));
    z5.print();

    std::cout<<std::endl<< std::endl<<"z6 = z1 / z2\nz6:";
    Complex2D z6(z1.divide(z2));
    z6.print();

    std::cout<<std::endl<< std::endl<<"|z1| > |z2| :";
    z1.is_higher_print(z2);
    
    std::cout<<std::endl<<std::endl<< "|z1| < |z2| :";
    z1.is_smaller_print(z2);
}
