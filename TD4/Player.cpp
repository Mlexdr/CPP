#include "Player.h"

#include "EnergyCard.h"
#include "TrainerCard.h"

#include <algorithm>
#include <iostream>

Player::Player(const string& name): playerName(name){}

Player::~Player(){
    for (Card* card : ownedCards){
        delete card;
    }
}

bool Player::addCardToBench(Card* card){

    if (find(ownedCards.begin(), ownedCards.end(), card) != ownedCards.end()){
        cout << "This card already belongs to the player.\n";
        return false;
    }

    ownedCards.push_back(card);
    benchCards.push_back(card);
    return true;
}

bool Player::activatePokemonCard(int benchIndex){
    if (benchIndex < 0 ||
        static_cast<std::size_t>(benchIndex) >= benchCards.size()){
        cout << "Pokemon bench index is out of range.\n";
        return false;
    }

    Card* card = benchCards[benchIndex];
    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(card);
    

    actionCards.push_back(pokemon);
    benchCards.erase(benchCards.begin() + benchIndex);
    cout << playerName << " is activating a Pokemon Card : "<< pokemon->getCardName() << '\n';
    return true;
}

bool Player::attachEnergyCard(int energyBenchIndex, int pokemonActionIndex){
    Card* card = benchCards[energyBenchIndex];
    EnergyCard* energy = dynamic_cast<EnergyCard*>(card);


    PokemonCard* pokemon = actionCards[pokemonActionIndex];
    attachedEnergyCards.push_back(make_pair(pokemon, energy));
    benchCards.erase(benchCards.begin() + energyBenchIndex);
    cout << playerName << " is attaching Energy Card of type "<< energy->getEnergyType() << " to the Pokemon "
    << pokemon->getCardName() << '\n';
    pokemon->addEnergyToAttacks();
    return true;
}

bool Player::useTrainer(int benchIndex){

    Card* card = benchCards[benchIndex];
    TrainerCard* trainer = dynamic_cast<TrainerCard*>(card);

    if (trainer->getEffect() != "heal all your action pokemon"){
        cout << "Unimplemented trainer effect: " << trainer->getEffect() << '\n';
        return false;
    }

    for (PokemonCard* pokemon : actionCards){
        pokemon->healToMax();
    }

    benchCards.erase(benchCards.begin() + benchIndex);
    ownedCards.erase(find(ownedCards.begin(), ownedCards.end(), trainer));
    delete trainer;
    return true;
}

bool Player::attack(int attackerActionIndex, int attackIndex, Player& opponent, int targetActionIndex){

    PokemonCard* attacker = actionCards[attackerActionIndex];
    PokemonCard* target = opponent.actionCards[targetActionIndex];
    int energyCost = 0;
    int currentEnergy = 0;
    int damage = 0;
    string description;
    !attacker->getAttackDetails(attackIndex, energyCost, currentEnergy, description, damage);

    if (currentEnergy < energyCost){
        cout << "Not enough attached energy to use this attack.\n";
        return false;
    }

    target->receiveDamage(damage);
    cout << playerName << " is attacking " << opponent.playerName<< "'s Pokemon " << target->getCardName()
    << " with " << attacker->getCardName()<< "'s attack: " << description << "\nReducing " << damage
    << " from " << opponent.playerName << "'s Pokemon's HP\n";
    if (target->isKnockedOut()){
        cout << "Pokemon " << target->getCardName() << " is K.O.\n";
    }
    else{
        cout << "Pokemon " << target->getCardName() << " is still alive\n";
    }
    return true;
}

void Player::displayBench() const
{
    cout <<"Bench cards for Player " <<playerName << " :\n";
    if (benchCards.empty()){
        cout << "  (empty)\n";
        return;
    }

    for (std::size_t i = 0; i < benchCards.size(); ++i){
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction() const{
    cout <<"Action cards for Player " <<playerName << " :\n";
    if (actionCards.empty()){
        cout << "  (none)\n";
        return;
    }

    for (std::size_t i = 0; i < actionCards.size(); ++i){
        PokemonCard* pokemon = actionCards[i];
        pokemon->displayInfo();

        for (const auto& attachment : attachedEnergyCards){
            if (attachment.first == pokemon){
                cout << "Attached energy:\n";
                attachment.second->displayInfo();
            }
        }
    }
}
