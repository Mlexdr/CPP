#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input){
    stack<char> one;
    for(char i:input){
        one.push(i);
    }
    for(char i:input){
        if(one.top()!=i){
            return false;
        };
        one.pop();
    }
    return true;
    
}



int main(){
    cout << boolalpha;

    cout << "Is 'racecar' a palindrome ? "
        << isPalindrome("racecar") << endl;

    cout << "Is 'hello' a palindrome ? "
        << isPalindrome("hello") << endl;

    return 0;
}