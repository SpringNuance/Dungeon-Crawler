#pragma once


#include "character.hpp"
#include "meleeweapons.hpp"
#include "rangedweapons.hpp"
#include "potions.hpp"
#include "shields.hpp"
#include <vector>

//The character that represents the player on the game board.
//Moving will roll the player inventory along with the cube.
//After moving attempts to use the item on the top inventory tile
//of the player cube.




class Player : public Character {
    public:
    Player(DungeonTile* tile);

    std::vector<InventorySlot*> GetInventory() const; //Returns the player inventory.

    bool DropItemFromSlot(InventorySlot* inventoryslot); //Attempts to drop the item in the given inventory slot on the tile the player is standing on.
    //Returns true if successful.

    bool AddItemToSlot(Item* item); //Attempts to add the item to the first free inventory slot in the player inventory. Returns true if successful.

    int MoveToDirection(std::string direction); //Moves the player to the given direction. Returns non-negative value if moving was successful.

    bool DistanceToCharacterLargerThanThree(Character* targetcharacter) const { return true; }

    bool NextToCharacter(Character* targetcharacter) const; //Checks if the target character is next to the character.

    void TakeDamage(int damage); //Deals damage to the player.

    void TakeAction(Character* targetcharacter, int damage); //Hits the target character with a weapon if there is one in the top inventory slot.

    ActionType GetCurrentAction() const { return Empty; };

    EnemyAI GetEnemyAI() const { return PlayerAI; };

    int GetCurrentActionIndex() const { return 0; };

    private:
    std::vector<InventorySlot*> inventory_; //A vector of InventorySlots that are stored in the following order: TOP, N, E, W, S, BOTTOM.
};