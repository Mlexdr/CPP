#include "MatrixBase.h"
#include "MatrixNumerical.h"

int main(){
    MatrixBase<int> m(2,3);
    m.addElement(4,0,0);
    std::cout<<std::endl<<"m:";
    m.Display(std::cout);
    std::cout<<std::endl<<"m[0][0]="<<m.getElement(0,0)<<std::endl;

    MatrixBase<int> m2;
    m2.addElement(3,1,2);
    std::cout<<std::endl<<"m2:";
    m2.Display(std::cout);

    MatrixNumerical<int> m3(3,3,7);
    m3.addElement(0,1,0);
    m3.addElement(0,0,1);
    std::cout<<std::endl<<"m3:";
    m3.Display(std::cout);
    std::cout<<std::endl<<"det(m3)="<<m3.getDeterminant()<<std::endl;

    MatrixNumerical<double> m4(2);
    m4.addElement(1,0,0);
    m4.addElement(2,0,1);
    m4.addElement(3,1,0);
    m4.addElement(4,1,1);
    std::cout<<std::endl<<"m4:";
    m4.Display(std::cout);


    MatrixBase<int> m5(m);
    std::cout<<std::endl<<"m5 (copie de m):";
    m5.Display(std::cout);
    
    MatrixNumerical<int> m6(3,3,0);
    m6.addElement(1,0,0);
    m6.addElement(8,1,0);
    m6.addElement(7,1,2);
    m6.addElement(2,1,1);
    m6.addElement(1,2,2);
    m6.addElement(1,3,3);
    std::cout<<std::endl<<"m6:";
    m6.Display(std::cout);

    MatrixNumerical<int> m7(m6,3,3);
    std::cout<<std::endl<<"m7(m6 sans de la ligne 3 et de la colonne 3):";
    m7.Display(std::cout);
    
    MatrixNumerical<int> m8=m3+m6;
    std::cout<<std::endl<<"m8(m3+m6):";
    m8.Display(std::cout);

    MatrixNumerical<int> m9=m3-m6;
    std::cout<<std::endl<<"m9(m3-m6):";
    m9.Display(std::cout);

    MatrixNumerical<int> m10=m3*m6;
    std::cout<<std::endl<<"m10(m3*m6):";
    m10.Display(std::cout);

    MatrixNumerical<float> m11=m3*2;
    std::cout<<std::endl<<"m11(2*m3):";
    m11.Display(std::cout);

    MatrixNumerical<float> m12=m4.getInverse();
    std::cout<<std::endl<<"m12(inverse de m4):";
    m12.Display(std::cout);

    MatrixNumerical<float> m13=m4/m4;
    std::cout<<std::endl<<"m13(m4/m4):";
    m13.Display(std::cout);

    MatrixNumerical<int> id=m3.getIdentity(6);
    std::cout<<std::endl<<"id(6):";
    id.Display(std::cout);
    return 1;
}