#include "Card.h"

Card::Card(const string& name):cardName(name){}
const string Card::getCardName() const{
    return cardName;
}