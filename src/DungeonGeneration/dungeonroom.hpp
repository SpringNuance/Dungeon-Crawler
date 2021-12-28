#pragma once


#include "dungeontile.hpp"
#include "../Characters/character.hpp"
#include "../Characters/characterplayer.hpp"
#include "../Characters/enemy.hpp"
#include "../Items/item.hpp"
#include <vector>


//Represents a room on a level.
//A room consists of 144 tiles on a 12 x 12 grid.


enum RoomType {
    _1DoorRoom,
    _2DoorRoomCorner,
    _2DoorRoomOpposite,
    _3DoorRoom,
    _4DoorRoom
};

enum DoorOrientation {
    North,
    East,
    South,
    West,
    NorthEast,
    SouthEast,
    SouthWest,
    NorthWest,
    Horizontal,
    Vertical,
    Omni
};


class DungeonRoom {
    public:
    DungeonRoom(std::pair<int,int> indexinlevel, RoomType roomtype, DoorOrientation doororientation, Item* loot, bool isplayerstartingroom);

    std::pair<int,int> GetIndexInLevel() const; //Returns the index of the room in a level.

    DungeonTile* GetDungeonTile(int xcoord, int ycoord) const; //Returns a pointer to the dungeon tile in the given coordinates.

    std::vector<std::vector<DungeonTile*>> GetAllTiles() const; //Returns a vector of all tiles in the room.

    bool IsExplored() const; //Returns true if the room has been already explored.

    bool IsLastRoomInLevel() const; //Returns true if the room is the last one to be explored in a level.

    void SetLastRoomInLevel(); //Sets the room as the last room in the level.

    void SpawnEnemies(std::vector<Character*> enemyvector); //Spawns enemies on Enemy spawning tiles if the room hasn't been explored yet and the player enters the room.

    void GiveLoot(Item* lootitem); //Assigns a new loot item to the room.

    Item* GetLootItem() const; //Returns the room loot item.

    void SpawnLoot(); //Spawns loot on a loot tile if the room was given loot when it was created.

    void CloseDoors(); //Closes the doors of the room until all enemies have been defeated.

    void OpenDoors(); //Opens the doors of the room when all enemies have been defeated.
    
    std::vector<DungeonRoom*> GetNeighbors() const; // return the room neighbors

    DoorOrientation GetDoorOrientation() const; //Returns the door orientation of the room.

    RoomType GetRoomType() const; //Returns the room type of the room.
    
    void AddNeighbor(DungeonRoom *room);

    private:
    std::pair<int, int> indexinlevel_; //The index of the room in the list of Rooms on a level.
    RoomType roomtype_; //The type of the room.
    DoorOrientation doororientation_; //The door orientation of the room.
    bool hasbeenexplored_; //True if the room has already been explored.
    bool lastroominlevel_; //True if the room is the last one the player enters.
    Item* loot_; //A pointer to the loot item.
    std::vector<std::vector<DungeonTile*>> alltiles_; // A vector that stores all tiles in the room.
    std::vector<DungeonRoom*> neighbors_; // A vector that stores the neighboring rooms of the room in the order NEWS.
};