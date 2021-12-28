#pragma once


#include <string>

//Item is a class that all item type classes will inherit.

enum ItemType {
    MeleeWeaponItem,
    RangedWeaponItem,
    ShieldItem,
    PotionItem
};

class Item {
    public:
    Item(const std::string& name, const std::string& description, ItemType itemtype, unsigned int durability, unsigned int maxcooldown); //constructs a new item.

    const std::string& GetName() const; //Returns the name of the item.

    const ItemType GetItemType() const; //Returns the type of the item.

    unsigned int GetDurability() const; //Returns the durability of the item.

    unsigned int GetMaxCoolDown() const; //Returns the max cooldown of the item.

    unsigned int GetCoolDown() const; //Returns the current cooldown of the item.

    bool IsActive() const; //Returns the status of the item. True if in player inventory.

    void ReduceCoolDown(); //Reduces the cooldown by one, but not below zero and only when the item is active.

    std::string GetDescription() const; //Returns the description of the item.

    virtual int Use() {return 0;}; //Overridden by subclasses. Triggers the item effect and returns the value. 
    //For MeleeWeapons this value is the damage, if 0 the item was not used.
    //For RangedWeapons this value is the damage, if 0 the item was not used.
    //For Shields this value is the added defense power, if 0 the item was not used.
    //For Potions this value signifies the effect. If 0 the item was not used. If 1 the potion heals the player by 1. If 2, a stamina potion.

    void PickUp(); //Sets the isactive status to true.

    void Drop(); //Sets the isactive status to false and adds one point to the cooldown if the item isn't on cooldown.

    virtual int GetDamage() const {return 0;};

    virtual int GetDefense() const {return 0;};

    virtual int GetRange() const {return 0;};

    virtual bool IsStunning() const {return false;};

    virtual bool TargetSeveralEnemies() const {return false;};

    virtual bool IsThrown() const {return false;};

    protected:
    std::string name_; //The name of the item.
    std::string description_;
    ItemType itemtype_; //The type of the item.
    unsigned int durability_; //The durability of the item.
    unsigned int maxcooldown_; //The maximum cooldown of the item.
    unsigned int cooldown_; //The current cooldown status of the item.
    bool isactive_; //Status of the item. True when in player inventory, false otherwise.
};