#include "potions.hpp"


//A class that all potions inherit.
//Potions have only one point of durability.

Potion::Potion(const std::string& name, const std::string& description, int effect)
    : Item(name, description, PotionItem, 1, 0), effect_(effect) {}

bool Potion::CanBeUsed() const {
    if ((isactive_)) {
        return true;
    }
    else {
        return false;
    }
}

int Potion::Use() {
    durability_--;
    return effect_;
}

int Potion::GetEffect() const {
    return effect_;
}


//Effect 1 - Restores one point of health to the player. Can only be used if the player is missing health.
HealthPotion::HealthPotion() : Potion("Potion of healing", "A small vial with some red liquid inside. It will restore one health point upon drinking.", 1) {}


//Effect 2 - Restores all item cooldowns. Can be used only when an item is on cooldown AND there are enemies in the same room as the player.
StaminaPotion::StaminaPotion() : Potion("Potion of stamina", "A small vial with some blue liquid inside. It will restore all item cooldowns upon drinking.", 2) {}
