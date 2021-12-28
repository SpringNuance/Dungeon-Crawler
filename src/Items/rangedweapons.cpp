#include "rangedweapons.hpp"


//A class that all ranged weapons inherit.
//The maximum range of any ranged weapon is 3.
//The conditions for using a ranged weapon:
//-An enemy is in range of the weapon, but not in a tile next to the 
//player and the attack of the ranged weapon can "walk" to the same tile
//as the enemy without passing walls in moves specified by the weapon's 
//range.
//-The weapon isn't on cooldown.


RangedWeapon::RangedWeapon(const std::string& name, const std::string& description, int durability, int maxcooldown, int damage, int range, bool isstunning, bool isthrown)
    : Item(name, description, RangedWeaponItem, durability, maxcooldown), damage_(damage), range_(range), isstunning_(isstunning), isthrown_(isthrown) {}

bool RangedWeapon::CanBeUsed() const {
    if ((cooldown_ == 0 && isactive_)) {
        return true;
    }
    else {
        return false;
    }
}

int RangedWeapon::Use() {
    if (CanBeUsed()) {
        cooldown_ = maxcooldown_;
        durability_--;
        return damage_;
    }
    else {
        return 0;
    }
}

int RangedWeapon::GetDamage() const {
    return damage_;
}

int RangedWeapon::GetRange() const {
    return range_;
}

bool RangedWeapon::IsStunning() const {
    return isstunning_;
}

bool RangedWeapon::IsThrown() const {
    return isthrown_;
}


//Cooldown 7, Damage 2. Thrown.
Javelin::Javelin() : RangedWeapon("Javelin", "A hefty throwing spear with a sharp tip.", 999, 5, 2, 3, false, true) {}


//Cooldown 7, Damage 0. Thrown. Stunning.
Bolas::Bolas() : RangedWeapon("Bolas", "A throwing weapon consisting of weights attached to each other with rope. It stuns the target it is thrown at and any enemies next to it.", 999, 5, 1, 3, true, true) {}


//Cooldown 8, Damage 1.
Sling::Sling() : RangedWeapon("Sling", "A simple piece of leather meant for slinging stones, which means that the ammunition is very plentiful. It takes a while to load though.", 999, 8, 1, 3, false, false) {}
