#include "character.hpp"


//A class that represents one of the six slots in the player inventory. Holds an Item.

InventorySlot::InventorySlot(Item* item) : item_(item) {}

bool InventorySlot::IsEmpty() const {
    if (item_ == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

Item* InventorySlot::GetItem() const {
    return item_;
}

bool InventorySlot::AddItem(Item* item) {
    if (IsEmpty()) {
        item_ = item;
        item_->PickUp();
        return true;
    }
    else {
        return false;
    }
}

void InventorySlot::DropItem() {
    item_->Drop();
    item_ = nullptr;
}

void InventorySlot::Clear() {
    item_ = nullptr;
}

void InventorySlot::SwapAdd(Item* item) {
    item_ = item;
}


int InventorySlot::UseItem() {
    int returned = 0;
    if (item_ != nullptr) {
        returned = item_->Use();
        if (returned != 0) {
            if (item_->GetDurability() == 0) {
                item_ = nullptr;
            }
        }
    }
    return returned;
}

//Character is a class that all character-related classes inherit.
//A character represents an active entity in a room, such as the player, 
//enemies or allied characters. Holds information such as the type of
//the character (player, enemy, allied) and its health points.


Character::Character(CharacterType charactertype, int healthpoints, DungeonTile* currenttile)
    : charactertype_(charactertype), healthpoints_(healthpoints), defensepoints_(0), isstunned_(false), currenttile_(currenttile) {
        if (currenttile_ != nullptr) {
            currenttile_->SetCharacter();
        }
    }

CharacterType Character::GetCharacterType() const {
    return charactertype_;
}

DungeonTile* Character::GetCurrentTile() const {
    return currenttile_;
}

int Character::GetXCoordinate() const {
    if (currenttile_ != nullptr) {
        return currenttile_->GetXCoord();
    }
    else {
        return -1;
    }
}

int Character::GetYCoordinate() const {
    if (currenttile_ != nullptr) {
        return currenttile_->GetYCoord();
    }
    else {
        return -1;
    }
}

int Character::GetHealthPoints() const {
    return healthpoints_;
}

int Character::GetDefensePoints() const {
    return defensepoints_;
}

void Character::AddDefensePoints(int defense) {
    defensepoints_ += defense;
}

void Character::RemoveDefensePoints() {
    defensepoints_ = 0;
}

void Character::Stun(int stunamount) {
    isstunned_ += stunamount;
}

void Character::UnStun() {
    if (isstunned_ > 0) {
        isstunned_--;
    }
}

bool Character::IsStunned() const {
    return isstunned_;
}

void Character::MoveToTile(DungeonTile* tile) {
    if (currenttile_ != nullptr) {
        currenttile_->RemoveCharacter();
    }
    currenttile_ = tile;
    currenttile_->SetCharacter();
}