#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& numbers,int target){
    for(int i=0;i<numbers.size();i++){    
        for(int j=0;j<numbers.size();j++){
            if(!i==j){
                if (numbers[i]+numbers[j]==target){
                    return {i,j};
                }
            }
        }        
    }
    return {-1,-1};
}

vector<int> twoSumOptimal(const vector<int>& numbers,int target){
    int me_mario;
    unordered_map<int,int> map={};
    for(int i=0;i<numbers.size();i++){
        me_mario=target-numbers[i];
        if(map.count(me_mario)){
            return{map[me_mario],i};
        }
        map.insert({numbers[i],i});
    }
    return{-1,-1};
}

int main(){
    vector<int> numbers={2,7,11,15};
    int target=9;
    vector<int> indicesBruteForce= twoSumBruteForce(numbers, target);
    cout<<endl<<"Brute force solution : ["
    <<indicesBruteForce[0]
    <<", "
    <<indicesBruteForce[1]
    <<"]"
    <<endl;
    
    vector<int> indicesOptimal= twoSumOptimal(numbers, target);
    cout<<endl<<"Optimal solution : ["
    <<indicesOptimal[0]
    <<", "
    <<indicesOptimal[1]
    <<"]"
    <<endl;
    
}