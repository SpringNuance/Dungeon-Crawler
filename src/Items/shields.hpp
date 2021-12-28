#pragma once


#include "item.hpp"


//A class that all shields inherit.
//The condition for activating a shield is having an attack target the
//player while the shield is in the top inventory slot of the player.
//An active shield will defend against all attacks towards the player during
//the turn it is activated, and will stun all enemies that attacked the
//player while next to them. The shield must also not be on cooldown for
//it to be used.

//Shields have a defense stat, which tells how much damage they will
//block from attacks. If a shield has one point of defense, it will
//negate all attacks that deal one damage. If an attack that deals two
//damage hits the shield, it will absorb one damage and allow the remaining
//point of damage to get through and damage the player.


class Shield : public Item {
    public:
    Shield(const std::string& name, const std::string& description, int durability, int maxcooldown, int defense);
    
    bool CanBeUsed() const;
    
    int Use();

    int GetDefense() const;

    int GetDamage() const {return 0;};

    int GetRange() const {return 0;};

    bool IsStunning() const {return false;};

    bool TargetSeveralEnemies() const {return false;};

    bool IsThrown() const {return false;};

    protected:
    int defense_;
};


class RoundShield : public Shield {
    public:
    RoundShield();
};


class HeaterShield : public Shield {
    public:
    HeaterShield();
};


class KiteShield : public Shield {
    public:
    KiteShield();
};


class TowerShield : public Shield {
    public:
    TowerShield();
};