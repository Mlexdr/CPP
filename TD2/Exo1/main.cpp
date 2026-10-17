#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BiarySearch.h"
int main(){
    std::vector<int> list={0,1,3,5,8,10,15,16,23,27,32};
    int target_s=23;
    int target_f=99;
    LinearSearch linear;
    JumpSearch jump;
    BiarySearch biary;
    std::cout<<std::endl<<"Linear Search :"<<std::endl;
    int res1=linear.search(list,target_s);
    linear.displaySearchResults(std::cout,res1,target_s);
    std::cout<<std::endl<<"Linear Search pour un élément non présent dans la liste :"<<std::endl;
    int res2=linear.search(list,target_f);
    linear.displaySearchResults(std::cout,res2,target_f);


    std::cout<<std::endl<<"Jump Search :"<<std::endl;
    int res3=jump.search(list,target_s);
    jump.displaySearchResults(std::cout,res3,target_s);
    std::cout<<std::endl<<"Jump Search pour un élément non présent dans la liste:"<<std::endl;
    int res4=jump.search(list,target_f);
    jump.displaySearchResults(std::cout,res4,target_f);

    std::cout<<std::endl<<"Binary Search :"<<std::endl;
    int res5=biary.search(list,target_s);
    biary.displaySearchResults(std::cout,res5,target_s);
    std::cout<<std::endl<<"Binary Search pour un élément non présent dans la liste:"<<std::endl;
    int res6=biary.search(list,target_s);
    biary.displaySearchResults(std::cout,res6,target_f);
    return 0;
}