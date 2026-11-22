#include "TrainerCard.h"

TrainerCard::TrainerCard(string name, string effect): Card(name),trainerEffect(effect){}

void TrainerCard::displayInfo() const{
    cout <<"Trainer Card - "<< "Name: " << cardName << ", "<< "Effect: " << trainerEffect << '\n';
}

const string TrainerCard::getEffect() const{
    return trainerEffect;
}