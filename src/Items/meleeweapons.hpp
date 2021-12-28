#pragma once


#include "item.hpp"

//A class that all melee weapons inherit.
//The conditions for using a melee weapon:
//-An enemy is in range of the weapon
//-The weapon isn't on cooldown.

class MeleeWeapon : public Item {
    public:
    MeleeWeapon(const std::string& name, const std::string& description, int durability, int maxcooldown, int damage, int range, bool isstunning, bool targetseveralenemies);
    
    bool CanBeUsed() const;
    
    int Use();

    int GetDamage() const;

    int GetRange() const;

    bool IsStunning() const;

    bool TargetSeveralEnemies() const;

    bool IsThrown() const {return false;};

    protected:
    int range_; //The range of the weapon.
    int damage_; //The damage of the weapon.
    bool isstunning_; //If the weapon is stunning, it will stun the struck enemy and enemies adjacent to it.
    bool targetseveralenemies_; //If the weapon can target several enemies, it will attack all enemies in attack range instead of just one.
};



class ShortSword : public MeleeWeapon {
    public:
    ShortSword();
};


class ArmingSword : public MeleeWeapon {
    public:
    ArmingSword();
};


class LongSword : public MeleeWeapon {
    public:
    LongSword();
};


class HandAxe : public MeleeWeapon {
    public:
    HandAxe();
};


class BattleAxe : public MeleeWeapon {
    public:
    BattleAxe();
};


class Mace : public MeleeWeapon {
    public:
    Mace();
};


class WarHammer : public MeleeWeapon {
    public:
    WarHammer();
};