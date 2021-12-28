#pragma once


#include "../DungeonGeneration/dungeontile.hpp"
#include <string>

//Character is a class that all character-related classes inherit.
//A character represents an active entity in a room, such as the player, 
//enemies or allied characters. Holds information such as the type of
//the character (player, enemy, allied) and its health points.

enum CharacterType {
    PlayerCharacter,
    AlliedCharacter,
    EnemyCharacter
};

enum EnemyAI {
    Aggressive,
    Careful,
    Random,
    Stationary,
    PlayerAI
};

enum ActionType {
    Empty,
    Indirect,
    Melee_1,
    Ranged_1,
    Defend_1,
    Melee_2,
    Ranged_2,
    Defend_2,
    Melee_3,
    Ranged_3,
    Defend_3
};


//A class that represents one of the six slots in the player inventory. Holds an Item.

class InventorySlot {
    public:
    InventorySlot(Item* item); //Constructor.

    bool IsEmpty() const; //Returns true if the inventory slot is not holding an item.

    Item* GetItem() const; //Returns a pointer to the item in the inventory slot.

    bool AddItem(Item* item); //Attempts to add an item to the inventory slot. Returns true if successful. If the slot already has an item, returns false.

    void DropItem(); //Drops the item in the inventory slot.

    void Clear(); // Clears an inventory slot. Used in inventory actions.

    void SwapAdd(Item*); // Adds an item pointer to inventory slot. Accepts nullpointers also. Used in inventory actions.

    int UseItem(); //Attempts to use the item held in the inventory slot and returns a value from the item that signifies what it did.
    //Deletes the item from the slot if its durability reaches zero.

    private:
    Item* item_;
};

class Character {
    public:
    Character(CharacterType charactertype, int healthpoints, DungeonTile* currenttile); //Constructs a new character.

    CharacterType GetCharacterType() const; //Returns the character type.

    DungeonTile* GetCurrentTile() const; //Returns the tile the character is standing on.

    int GetXCoordinate() const; //Returns the X-coordinate of the character.

    int GetYCoordinate() const; //Returns the X-coordinate of the character.

    int GetHealthPoints() const; //Returns the healthpoints of the character.

    int GetDefensePoints() const; //Returns the defense points of the character.

    void AddDefensePoints(int defense); //Adds the amount of defense points given in the parameter.

    void RemoveDefensePoints(); //Sets the defense points to zero.

    virtual bool DistanceToCharacterLargerThanThree(Character* targetcharacter) const { return true; } //Returns false if the distance is three or less.

    virtual bool NextToCharacter(Character* targetcharacter) const {return false;}; //Checks if the target character is next to the character.

    virtual void TakeDamage(int damage) {}; //Reduces healthpoints by the amount of damage minus defense points.

    virtual void TakeAction(Character* targetcharacter, int fillernumber) {}; //Makes the character take an action. For Players the fillernumber is dealt as damage to targetcharacter.
    //Enemies will pathfind and attack the character given as target, and the int will not be used.

    void Stun(int stunamount); //Stuns the character.

    void UnStun(); //Reduces stunned status.

    bool IsStunned() const; //Returns true if the character is stunned.

    virtual int MoveToDirection(std::string direction) { return -1; }; //Attempts to move the character on the neighboring tile in the given direction. 
    //Returns -1 if did not succeed, otherwise positive.

    void MoveToTile(DungeonTile* tile); //Moves the character onto the given tile.

    virtual ActionType GetCurrentAction() const { return ActionType::Empty; };

    virtual EnemyAI GetEnemyAI() const { return EnemyAI::Stationary; };

    virtual int GetCurrentActionIndex() const { return 0; };

    virtual std::vector<InventorySlot*> GetInventory() const { return {nullptr}; }; //Returns the player inventory.

    protected:
    CharacterType charactertype_; //The type of the character.
    int healthpoints_; //The health points of the character.
    int defensepoints_; //The defense points of the character from using a shield. Blocks damage.
    int isstunned_; //Indicates if the character is stunned or not. 0 = no stun, other number = the amount of turns the character will remain stunned.
    DungeonTile* currenttile_; //A pointer to the tile the character is standing on.
};