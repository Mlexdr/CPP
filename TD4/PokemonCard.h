#ifndef PCard_h
#define PCard_h
#include "Card.h"


class PokemonCard : public Card{
    public:
        PokemonCard(string,string,string,int,int,int,string,int,int,string,int);
        void displayInfo() const override;
        void healToMax();
        void addEnergyToAttacks();
        bool getAttackDetails(int attackIndex, int energyCost, int currentEnergy,string description, int damage) const;
        void receiveDamage(int damage);
        bool isKnockedOut() const;
        
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        vector<tuple<int,int,string,int>>  attacks;

};



#endif