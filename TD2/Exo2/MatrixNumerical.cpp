#include "MatrixNumerical.h"

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t _rows,size_t _cols): MatrixBase<T>(_rows,_cols)
{
}
template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t size): MatrixBase<T>(size)
{
}
template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t _rows,size_t _cols, T val): MatrixBase<T>(_rows,_cols,val)
{
}
template <typename T>
MatrixNumerical<T>::MatrixNumerical(): MatrixBase<T>()
{
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(const MatrixNumerical<T>& m): MatrixBase<T>(m)
{
}
template <typename T>
MatrixNumerical<T>::MatrixNumerical(const MatrixNumerical<T>& m,size_t forbidden_r,size_t forbidden_c): MatrixBase<T>(m,forbidden_r,forbidden_c)
{
}
template <typename T>
T MatrixNumerical<T>::getDeterminant(){
    if(this->rows==this->cols){
    T res=0;
    int sign;
    size_t ref_row=this->rows;
    size_t ref_col=this->cols;
    T det;
    T tempo;
    if(ref_col==ref_row && ref_col==1){return this->getElement(0,0);}
    if(ref_col==ref_row && ref_col==2){return this->getElement(0,0)*this->getElement(1,1)-this->getElement(0,1)*this->getElement(1,0);}
    size_t i=ref_row-1;
    for(int h=0;h<ref_col;h++){
            sign = ((i + h) % 2 == 0) ? 1 : -1;
            MatrixNumerical<T> m(*this,i+1,h+1);
            det=m.getDeterminant();
            tempo=this->getElement(i,h)*det;
            res+=tempo*sign;
            
    }
    return res;
    }
    else{
        throw std::invalid_argument("Matrice non prise en charge");
    }
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& m)const{
    if(this->rows==m.getRows() && this->cols==m.getCols()){
    MatrixNumerical<T> res(*this);
    for(int i=0;i<this->rows;i++){
        for(int h=0;h<this->cols;h++){
            res.addElement(this->data[i][h]+m.getElement(i,h),i,h);
        }
    }
    return res;
    }
    else{
        throw std::invalid_argument("Matrice non prise en charge");
    }
}
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& m)const{
    if(this->rows==m.getRows() && this->cols==m.getCols()){
    MatrixNumerical<T> res(*this);
    for(int i=0;i<this->rows;i++){
        for(int h=0;h<this->cols;h++){
            res.addElement(this->data[i][h]-m.getElement(i,h),i,h);
        }
    }
    return res;
    }
}
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& m)const{
    if(this->rows==m.getRows() && this->cols==m.getCols()){
    MatrixNumerical<T> res(this->rows,this->cols);
    for (size_t i = 0; i<this->rows;i++){
        for(size_t h = 0; h<this->cols; h++){
            for(size_t k = 0; k<this->cols; k++){
                res.data[i][h] += this->data[i][k] * m.data[k][h];
            } 
        }
    }
    return res;
    }else{
        throw std::invalid_argument("Matrice non prise en charge");
    }
}
template <typename T>
MatrixNumerical<float> MatrixNumerical<T>::operator*(const float& a)const{
    MatrixNumerical<float> res(this->rows,this->cols);
    for(int i=0;i<this->rows;i++){
        for(int h=0;h<this->cols;h++){
            res.addElement(this->data[i][h]*a,i,h);
        }
    }
    return res;
    
}
template <typename T>
MatrixNumerical<float> MatrixNumerical<T>::getInverse(){
    float det=this->getDeterminant();
    if(det!=0){
        float cof=1/det;
        int sign;
        size_t col=this->cols;
        size_t row=this->rows;
        MatrixNumerical<float> res(row,col);
        for(int i=0;i<row;i++){
            for(int h=0;h<col;h++){
                sign = ((i + h) % 2 == 0) ? 1 : -1;
                MatrixNumerical<T> m(*this,i+1,h+1);
                res.addElement(m.getDeterminant()*sign,h,i);
            }
        }
        return res*cof;
    }
    else{
        throw std::runtime_error("Matrice non inversible");
    }
}
template <typename T>
MatrixNumerical<float> MatrixNumerical<T>::operator/( MatrixNumerical<T> m){
    if(this->rows==m.getRows() && this->cols==m.getCols()){
    
    MatrixNumerical<float> inv=m.getInverse();
    MatrixNumerical<float> res(this->rows,this->cols);
    float ope;
    for (size_t i = 0; i<this->rows;i++){
        for(size_t h = 0; h<this->cols; h++){
            ope=0;
            for(size_t k = 0; k<this->cols; k++){
                ope += this->data[i][k] * inv.getElement(k,h);
            } 
            res.addElement(ope,i,h);
        }
    }
    return res;
    }
    else{
        throw std::invalid_argument("Matrice non prise en charge");
    }
}
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(size_t size){
    MatrixNumerical<T> id(size);
    for(int i=0;i<size;i++){
        id.addElement(1,i,i);
    }
    return id;
}

