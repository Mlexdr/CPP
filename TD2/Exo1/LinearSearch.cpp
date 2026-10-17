#include "LinearSearch.h"

LinearSearch::search(vector<int> list, int target){
    int n=list.size();
    numberComparisons=0;
    for(int i=0;i<n;i++){
        numberComparisons++;
        if ( list[i]==target){
            return i;
        }    
    }
    return-1;
}