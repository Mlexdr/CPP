#include "BiarySearch.h"

        
int BiarySearch:: search(vector<int> list, int target){
    int size=list.size();
    int high=size-1;
    int low=0;
    int position;
     while(low<=high){
        numberComparisons++;
        position=floor((low+high)/2);
        if (list[position]==target){
            return position;
        }
        if (list[position]>target){
            high=position-1;
        }
        else{
            low=position+1;
        }
    }
    return -1;
}