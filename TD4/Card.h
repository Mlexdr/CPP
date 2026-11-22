#ifndef Card_h
#define Card_h
#include <string>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
class Card{
    public:
        virtual void displayInfo() const =0;
        virtual ~Card()=default;
        Card(const string&);
        const string getCardName() const;
    protected:
        string cardName;
};



#endif