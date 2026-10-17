#include "MatrixBase.h"

template <typename T>
MatrixBase<T>::MatrixBase(): rows(0), cols(0){}
template <typename T>
MatrixBase<T>::MatrixBase(size_t size): data(size,vector<T>(size)), rows(size), cols(size)
{
}

template <typename T>
MatrixBase<T>::MatrixBase(size_t _rows,size_t _cols): data(_rows,vector<T>(_cols)), rows(_rows), cols(_cols)
{
}
template <typename T>
MatrixBase<T>::MatrixBase(size_t _rows,size_t _cols,const T& val): data(_rows,vector<T>(_cols,val)), rows(_rows), cols(_cols)
{
}
template <typename T>
MatrixBase<T>::MatrixBase(const MatrixBase<T>& m){
    rows=m.getRows();
    cols=m.getCols();
    data=vector<vector<T>>(rows,vector<T>(cols));
    for(int i=0;i<rows;i++){
        for(int h=0;h<cols;h++){
            data[i][h]=m.getElement(i,h);
        }
    }
}
template <typename T>
MatrixBase<T>::MatrixBase(const MatrixBase<T>& m,size_t forbidden_r,size_t forbidden_c){
    rows=m.getRows()-1;
    cols=m.getCols()-1;
    data=vector<vector<T>>(rows,vector<T>(cols));
    for(int i=0;i<rows+1;i++){
        for(int h=0;h<cols+1;h++){
            if(i<forbidden_r-1 && h<forbidden_c-1){
                data[i][h]=m.getElement(i,h);
            }
            if(i<forbidden_r-1 && h>forbidden_c-1){
                data[i][h-1]=m.getElement(i,h);
            }
            if(i>forbidden_r-1 && h<forbidden_c-1){
                data[i-1][h]=m.getElement(i,h);
            }
            if(i>forbidden_r-1 && h>forbidden_c-1){
                data[i-1][h-1]=m.getElement(i,h);
            }
            
        }
    }
}

template <typename T>
void MatrixBase<T>::Display(ostream& cout)const{
    cout<<"\n[";
    for(int i=0;i<rows;i++){
        if(i==0){
            cout<<"[";
        }
        else{
            cout<<" [";
        }
        for(int h=0;h<cols;h++){
            cout<<" "<<data[i][h];
        }
        if(i==rows-1){
            cout<<" ]";
        }
        else{
            cout<<" ]\n";
        }
    }
    cout<<"]\n";
}
template <typename T>
void MatrixBase<T>::addElement(const T& a,size_t _rows,size_t _cols){
    if(_rows<rows && _cols<cols){
        data[_rows][_cols]=a;
    }
    
}
template <typename T>
T MatrixBase<T>::getElement(size_t _rows, size_t _cols)const{
    if(_rows<rows && _cols<cols){
        return data[_rows][_cols];
    }
}

template<typename T>
size_t MatrixBase<T>::getRows()const{
    return rows;
}

template<typename T>
size_t MatrixBase<T>::getCols()const{
    return cols;
}
