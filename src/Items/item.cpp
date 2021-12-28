#include "item.hpp"


//Item is a class that all item type classes will inherit.

Item::Item(const std::string& name, const std::string& description, ItemType itemtype, unsigned int durability, unsigned int maxcooldown)
    : name_(name), description_(description), itemtype_(itemtype), durability_(durability), maxcooldown_(maxcooldown), cooldown_(0), isactive_(true) {}

const std::string& Item::GetName() const {
    return name_;
}

const ItemType Item::GetItemType() const {
    return itemtype_;
}

unsigned int Item::GetDurability() const {
    return durability_;
}

unsigned int Item::GetMaxCoolDown() const {
    return maxcooldown_;
}

unsigned int Item::GetCoolDown() const {
    return cooldown_;
}

bool Item::IsActive() const {
    return isactive_;
}

void Item::ReduceCoolDown() {
    if (IsActive() && cooldown_ > 0) {
        cooldown_--;
    }
}

std::string Item::GetDescription() const {
    return description_;
}

void Item::PickUp() {
    isactive_ = true;
}

void Item::Drop() {
    if (cooldown_ == 0) {
        cooldown_++;
    }
    isactive_ = false;
}