#pragma once


#include "../Items/item.hpp"
#include <vector>
#include <stdlib.h>
#include <time.h>

//A class that is inherited by all tile types.

enum TileType {
    Floor,
    Wall,
    Pit,
    Door,
    Trap,
    Spawner,
    Exit,
    Entrance,
    Loot
};

enum TrapState {
    Dormant,
    Emerging,
    Spikes
};

class DungeonTile {
    public:
    DungeonTile(TileType tiletype, int xcoord, int ycoord); //Constructs a new tile.

    bool IsPassable() const; //Returns true if the tile can be walked onto.

    Item* GetItem() const; //Returns a pointer to the item on the tile.

    bool HasCharacter() const; //Returns true if there is a character standing on the tile.

    int GetXCoord() const; //Returns the X-coordinate of the tile.

    int GetYCoord() const; //Returns the Y-coordinate of the tile.

    void PlaceItem(Item* item); //Places an item on the tile.

    bool SetCharacter(); //Informs the tile that a Character has stepped into it.
    //Returns true if setting the character was successful, false if there already was a character on the tile.

    void RemoveCharacter(); //Informs the tile that a Character has left it.

    TileType GetTileType() const; //Returns the type of the tile.

    DungeonTile* GetTileNeighbor(const std::string direction) const; //Returns a pointer to the neighboring tile in the given direction.

    void SetTileNeighbors(std::vector<DungeonTile*> neighborvector); //Sets the tile neigbors.

    void Close(); //Changes the isopen value to false. Also changes the ispassable value to false if the tile is a door.

    void Open(); //Changes the isopen value to true. Also changes the ispassable value to true if the tile is a door.

    bool IsOpen() const; //Returns true if the isopen status is true.

    TrapState GetTrapState() const; //Returns the trap state of the tile.

    void ProceedTrapState(); //Proceeds the trap state of the tile if the tile is a trap tile.


    private:
    bool ispassable_; //The status of the tile. True if passable, false otherwise.
    bool isopen_; //Value that describes the status of floor exits and door tiles.
    Item* item_; //The item on the tile.
    bool hascharacter_; //Tells if there is a Character on the tile or not.
    TileType tiletype_; //The type of the tile, e.g. FloorTile or WallTile.
    int xcoord_; //The x-coordinate of the tile in a room.
    int ycoord_; //The y-coordinate of the tile in a room.
    TrapState trapstate_; //The status of trap tiles.
    std::vector<DungeonTile*> tileneighbors_; //Neighboring tiles of the tile stored as NEWS.
};