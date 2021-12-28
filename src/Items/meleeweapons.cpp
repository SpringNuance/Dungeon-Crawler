#include "meleeweapons.hpp"


//A class that all melee weapons inherit.
//The conditions for using a melee weapon:
//-An enemy is in range of the weapon
//-The weapon isn't on cooldown.

MeleeWeapon::MeleeWeapon(const std::string& name, const std::string& description, int durability, int maxcooldown, int damage, int range, bool isstunning, bool targetseveralenemies)
    : Item(name, description, MeleeWeaponItem, durability, maxcooldown), damage_(damage), range_(range), isstunning_(isstunning), targetseveralenemies_(targetseveralenemies) {}

bool MeleeWeapon::CanBeUsed() const {
    if ((cooldown_ == 0 && isactive_)) {
        return true;
    }
    else {
        return false;
    }
}

int MeleeWeapon::Use() {
    if (CanBeUsed()) {
        cooldown_ = maxcooldown_;
        durability_--;
        return damage_;
    }
    else {
        return 0;
    }
}

int MeleeWeapon::GetDamage() const {
    return damage_;
}

int MeleeWeapon::GetRange() const {
    return range_;
}

bool MeleeWeapon::IsStunning() const {
    return isstunning_;
}

bool MeleeWeapon::TargetSeveralEnemies() const {
    return targetseveralenemies_;
}



//Cooldown 3, Damage 1.
ShortSword::ShortSword() : MeleeWeapon("Shortsword", "A short and sturdy sword with a comfortable grip.", 999, 4, 1, 1, false, false) {}

//Cooldown 5, Damage 1. Hits several enemies.
ArmingSword::ArmingSword() : MeleeWeapon("Arming sword", "A medium sized single-handed sword that can cut down multiple enemies with a single swing.", 999, 5, 1, 1, false, true) {}

//Cooldown 6, Damage 2. Hits several enemies.
LongSword::LongSword() : MeleeWeapon("Longsword", "A large two-handed sword that can cut down multiple enemies with a single wide swing.", 999, 6, 2, 1, false, true) {}

//Cooldown 5, Damage 2.
HandAxe::HandAxe() : MeleeWeapon("Hatchet", "A simple one-handed axe. Quite hefty.", 999, 5, 2, 1, false, false) {}

//Cooldown 6, Damage 3.
BattleAxe::BattleAxe() : MeleeWeapon("Battleaxe", "A large axe with a massive head and a long handle. Cuts through almost anything.", 999, 6, 3, 1, false, false) {}

//Cooldown 5, Damage 1. Stuns targets.
Mace::Mace() : MeleeWeapon("Mace", "A simple mace with a metallic weight at the end of a wooden handle. Stuns the struck enemy and enemies next to it.", 999, 5, 1, 1, true, false) {}

//Cooldown 6, Damage 2. Stuns targets.
WarHammer::WarHammer() : MeleeWeapon("Warhammer", "A hammer specifically designed for cracking skulls on the battlefield. Stuns the struck enemy and enemies next to it.", 999, 6, 2, 1, true, false) {}