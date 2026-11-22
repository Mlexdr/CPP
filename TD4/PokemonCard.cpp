#include "PokemonCard.h"



PokemonCard::PokemonCard(string name,string type,string family, int evolution,
    int pv,int en_attack1,string des_attack1,int pow_attack1,int en_attack2,
    string des_attack2,int pow_attack2) :
        Card(name),
        pokemonType(type),
        familyName(family),
        evolutionLevel(evolution),
        maxHP(pv),
        hp(pv),
        attacks(vector<tuple<int,int,string,int>> {
            tuple<int,int,string,int>(en_attack1,0,des_attack1,pow_attack1),
            tuple<int,int,string,int>(en_attack2,0,des_attack2,pow_attack2)}){}

void PokemonCard::displayInfo() const{
    cout <<"Pokemon Card - Name: " << cardName << ", "<< "Type: " << pokemonType << ", " 
    << "Evolution level: " << evolutionLevel << " of the family \""<<familyName
    <<", HP: " << hp << "\"\n"<<"Attacks:\n";
    for (std::size_t i = 0; i < attacks.size(); ++i){
        const auto& attack = attacks[i];
        cout << "Attack #" << i << ":\n"
             << "Attack cost: " << get<0>(attack) << '\n'
             << "Attack current energy storage: " << get<1>(attack) << '\n'
             << "Attack description: " << get<2>(attack) << '\n'
             << "Attack damage: " << get<3>(attack) << '\n';
    }
}

void PokemonCard::healToMax(){
    hp = maxHP;
}

void PokemonCard::addEnergyToAttacks(){
    for (auto& attack : attacks){
        ++get<1>(attack);
    }
}

bool PokemonCard::getAttackDetails(int attackIndex, int energyCost,int currentEnergy,string description, int damage) const{
    auto attack = attacks[attackIndex];
    energyCost = get<0>(attack);
    currentEnergy = get<1>(attack);
    description = get<2>(attack);
    damage = get<3>(attack);
    return true;
}

void PokemonCard::receiveDamage(int damage){
    if (damage <= 0){
        return;
    }
    hp = damage >= hp ? 0 : hp - damage;
}

bool PokemonCard::isKnockedOut() const{
    return hp <= 0;
}