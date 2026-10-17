#ifndef MatrixBase_h
#define MatrixBase_h
#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
template <typename T>
class MatrixBase{
    protected :
        vector<vector<T>> data;
        size_t rows;
        size_t cols;
    public :
        MatrixBase();
        MatrixBase(size_t);
        MatrixBase(size_t, size_t);
        MatrixBase(size_t,size_t, const T&);
        MatrixBase(const MatrixBase<T>&);
        MatrixBase(const MatrixBase<T>&,size_t,size_t);
        size_t getRows()const;
        size_t getCols()const;
        void Display(ostream&)const;
        void addElement(const T&,size_t ,size_t );
        T getElement(size_t, size_t)const;
    

};
#include "MatrixBase.cpp"
#endif