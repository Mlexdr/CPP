#ifndef ECard_h
#define ECard_h
#include "Card.h"

using namespace std;
class EnergyCard : public Card{
    private:
        string energyType;
    public:
        EnergyCard(string);
        void displayInfo() const override;
        const string getEnergyType() const;
};
#endif