#ifndef SearchingAlgorithm_h
#define SearchingAlgorithm_h
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

class SearchingAlgorithm{
    public:
        SearchingAlgorithm();
        virtual int search(vector<int> list,int target)=0;//renvoie l'indice de l'élément cherché ou -1
//premier élément a l'indice 0
        void displaySearchResults(ostream&,int result,int target);

    protected:
        int numberComparisons;
        static int totalComparison;
        static int totalSearch;
        static double averageComparison;
};
#endif