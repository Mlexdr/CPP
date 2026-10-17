#ifndef MatrixNumerical_h
#define MatrixNumerical_h
#include "MatrixBase.h"
#include <type_traits>
template <typename T>
class MatrixNumerical :public MatrixBase<T>{
    static_assert(
        (std::is_same<T,size_t>::value)||
        (std::is_same<T,int>::value)||
        (std::is_same<T,float>::value)||
        (std::is_same<T,double>::value)||
        (std::is_same<T,long>::value)||
        (std::is_same<T,long int>::value)||
        (std::is_same<T,long double>::value)||
        (std::is_same<T,long long>::value)||
        (std::is_same<T,long long int>::value)||
        (std::is_same<T,short>::value)||
        (std::is_same<T,short int>::value)||
        (std::is_same<T,unsigned int>::value)||
        (std::is_same<T,unsigned long>::value)||
        (std::is_same<T,unsigned long int>::value)||
        (std::is_same<T,unsigned long long>::value)||
        (std::is_same<T,unsigned long long int>::value)||
        (std::is_same<T,unsigned short>::value)||
        (std::is_same<T,unsigned short int>::value)||
        (std::is_same<T,signed int>::value)||
        (std::is_same<T,signed long>::value)||
        (std::is_same<T,signed long int>::value)||
        (std::is_same<T,signed long long>::value)||
        (std::is_same<T,signed long long int>::value)||
        (std::is_same<T,signed short>::value)||
        (std::is_same<T,signed short int>::value)
    );
    public:
        MatrixNumerical();
        MatrixNumerical(size_t);
        MatrixNumerical(size_t , size_t );
        MatrixNumerical(size_t ,size_t , T);
        MatrixNumerical(const MatrixNumerical<T>&);
        MatrixNumerical(const MatrixNumerical<T>&,size_t,size_t);

        T getDeterminant();

        MatrixNumerical operator+(const MatrixNumerical& matrix)const;
        MatrixNumerical operator-(const MatrixNumerical& matrix)const;
        MatrixNumerical operator*(const MatrixNumerical& matrix)const;
        MatrixNumerical<float> operator*(const float&)const;
        MatrixNumerical<float> getInverse();
        MatrixNumerical<float> operator/( MatrixNumerical matrix);
        static MatrixNumerical<T> getIdentity(size_t);
  

};
#include "MatrixNumerical.cpp"

#endif