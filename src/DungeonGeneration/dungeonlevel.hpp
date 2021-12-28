#pragma once


#include "dungeonroom.hpp"
#include <cstdlib>
#include <vector>
#include <random>
#include <utility>
#include <algorithm>

//Represents a level of the dungeon.
//A level consists of nine rooms connected by doors on a 3 x 3 grid.

enum Direction { Up , Down , Left , Right };

class DungeonLevel {
    public:
    DungeonLevel(int sidelength); 
    
    int GetSideLength() const;
    std::pair<int,int> GetStartPos() const;
    std::vector<std::vector<DungeonRoom*>> GetRooms() const;
    
    private:
    int sidelength_; // side length of the map
    std::pair<int,int> startPos_; // starting room
    std::vector<std::vector<DungeonRoom*>> rooms_; // Two dimensional vector that stores the rooms.
};