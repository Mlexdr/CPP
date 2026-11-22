#ifndef TCard_h
#define TCard_h
#include "Card.h"


class TrainerCard : public Card{
    public:
        TrainerCard(string,string);
        void displayInfo() const override;
        const string getEffect() const;
    private:
        string trainerEffect;
};
#endif