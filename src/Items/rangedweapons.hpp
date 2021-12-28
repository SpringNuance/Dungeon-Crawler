#pragma once


#include "item.hpp"


//A class that all ranged weapons inherit.
//The maximum range of any ranged weapon is 3.
//The conditions for using a ranged weapon:
//-An enemy is in range of the weapon, but not in a tile next to the 
//player and the attack of the ranged weapon can "walk" to the same tile
//as the enemy without passing walls in moves specified by the weapon's 
//range.
//-The weapon isn't on cooldown.


class RangedWeapon : public Item {
    public:
    RangedWeapon(const std::string& name, const std::string& description, int durability, int maxcooldown, int damage, int range, bool isstunning, bool isthrown);
    
    bool CanBeUsed() const;
    
    int Use();

    int GetDamage() const;

    int GetRange() const;

    bool IsStunning() const;

    bool IsThrown() const;

    bool TargetSeveralEnemies() const {return false;};

    int GetDefense() const {return 0;};

    protected:
    int range_; //The range of the weapon.
    int damage_; //The damage of the weapon.
    bool isstunning_; //If a ranged weapon is stunning, it will stun its target and enemies adjacent to it.
    bool isthrown_; //If the weapon is a throwing weapon, it will be removed from player inventory upon using and placed on the target tile.
};


class Javelin : public RangedWeapon {
    public:
    Javelin();
};


class Bolas : public RangedWeapon {
    public:
    Bolas();
};


class Sling : public RangedWeapon {
    public:
    Sling();
};