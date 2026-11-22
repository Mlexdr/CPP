#include "EnergyCard.h"


EnergyCard::EnergyCard(string name):energyType(name),Card("energy"){}

void EnergyCard::displayInfo() const{
    cout << "Name: " << cardName << '\n'<< "Energy type: " << energyType << '\n';
}
const string EnergyCard::getEnergyType() const{
    return energyType;
}