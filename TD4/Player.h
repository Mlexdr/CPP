#ifndef Player_h
#define Player_h
#include "Card.h"
#include "PokemonCard.h"
#include <utility>
#include <vector>

class EnergyCard;

class Player{
    public:
        Player(const string& name);
        ~Player();
        Player& operator=(const Player&) = delete;
        bool addCardToBench(Card* card); 
        bool attachEnergyCard(int energyBenchIndex, int pokemonActionIndex);
        void displayBench() const;
        bool activatePokemonCard(int benchIndex);
        bool useTrainer(int benchIndex);
        bool attack(int attackerActionIndex, int attackIndex,Player& opponent, int targetActionIndex);
        void displayAction() const;

    private:
        string playerName;
        vector<Card*> ownedCards;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;
        vector<pair<PokemonCard*, EnergyCard*>> attachedEnergyCards;
};
#endif