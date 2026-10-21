#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers){
    set<int> checked={};
    int count;
    for(int i=0;i<numbers.size();i++){
        count=0;
        if(!checked.count(numbers[i])){
            for(int j=0;j<numbers.size();j++){
                if(numbers[i]==numbers[j]){
                    count++;
                }
            }
            checked.insert(numbers[i]);
            cout<<endl<<numbers[i]<<": "<<count<<" times";
        }
            
    }
}

map<int,int> countFrequencyOptimal(const vector<int>& numbers){
    map<int,int> result={};
    for(int i=0;i<numbers.size();i++){
        result[numbers[i]]+=1;
    }
    return result;
}

int main(){
    vector<int> numbers={1,2,3,4,1,5,5,6};

    cout<<endl<<"Frequency brute force";
    countFrequencyBruteForce(numbers);

    cout<<endl<<endl<<"Frequency optimal";
    map<int,int> frequencyMapOptimal= countFrequencyOptimal(numbers);
    for(const auto& entry : frequencyMapOptimal){
        cout<<endl<<entry.first<<": "<<entry.second<<" times";
    }
}