#include "shields.hpp"


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

Shield::Shield(const std::string& name, const std::string& description, int durability, int maxcooldown, int defense)
    : Item(name, description, ShieldItem, durability, maxcooldown), defense_(defense) {}

bool Shield::CanBeUsed() const {
    if ((cooldown_ == 0 && isactive_)) {
        return true;
    }
    else {
        return false;
    }
}

int Shield::Use() {
    if (CanBeUsed()) {
        cooldown_ = maxcooldown_;
        durability_--;
        return defense_;
    }
    else {
        return 0;
    }
}

int Shield::GetDefense() const {
    return defense_;
}


//Cooldown 4, Defense 1.
RoundShield::RoundShield() : Shield("Round shield", "A small round wooden shield. Not very sturdy, but at least it is light.", 999, 4, 1) {}


//Cooldown 6, Defense 2.
HeaterShield::HeaterShield() : Shield("Heater shield", "A medium sized wooden shield.", 999, 6, 2) {}


//Cooldown 5, Defense 2.
KiteShield::KiteShield() : Shield("Kite shield", "A large wooden shield shaped like an upside down droplet.", 999, 5, 2) {}


//Cooldown 7, Defense 3.
TowerShield::TowerShield() : Shield("Tower shield", "An enormous shield with an inpenetrable defense. It is a shame it is so heavy.", 999, 7, 3) {}
