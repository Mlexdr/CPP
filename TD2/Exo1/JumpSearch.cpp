#include "JumpSearch.h"

int JumpSearch::search(vector<int> list, int target){
    int size=list.size();
    int jump=floor(sqrt(size));
    int position=0;
    while(jump>0){
        numberComparisons++;
        if (list[position]==target){
            return position;
        }
        if (list[position]>target){
            jump=floor(jump/2);
            position-=jump;
        }
        else{
            if(list[position]<target && (position+jump)<size){
                position+=jump;}
            else{
                jump=floor(jump/2);
                position+=jump;
            }
        }
    }
    return -1;
}
