#include "dungeontile.hpp"

//A class that is inherited by all tile types.


DungeonTile::DungeonTile(TileType tiletype, int xcoord, int ycoord) 
    : item_(nullptr), tiletype_(tiletype), hascharacter_(false), xcoord_(xcoord), ycoord_(ycoord) {
    if (tiletype == Wall) {
        ispassable_ = false;
        isopen_ = false;
    }
    else if (tiletype == Floor) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Pit) {
        ispassable_ = false;
        isopen_ = false;
    }
    else if (tiletype == Door) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Spawner) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Trap) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Entrance) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Loot) {
        ispassable_ = true;
        isopen_ = true;
    }
    else {
        ispassable_ = true;
        isopen_ = false;
    }
    if (tiletype != Trap) {
        trapstate_ = Dormant;
    }
    else {
        int randomnumber = rand() % 3 + 1;
        if (randomnumber == 1) {
            trapstate_ = Dormant;
        }
        else if (randomnumber == 2) {
            trapstate_ = Emerging;
        }
        else {
            trapstate_ = Spikes;
        }
    }
    
    std::vector<DungeonTile*> tileneighbors_;
}


bool DungeonTile::IsPassable() const {
    return ispassable_;
}

Item* DungeonTile::GetItem() const {
    return item_;
}

bool DungeonTile::HasCharacter() const {
    return hascharacter_;
}

int DungeonTile::GetXCoord() const {
    return xcoord_;
}

int DungeonTile::GetYCoord() const {
    return ycoord_;
}

void DungeonTile::PlaceItem(Item* item) {
    item_ = item;
}

bool DungeonTile::SetCharacter() {
    if (HasCharacter() == true) {
        return false;
    }
    else {
        hascharacter_ = true;
        ispassable_ = false;
        return true;
    }
}

void DungeonTile::RemoveCharacter() {
    hascharacter_ = false;
    if (tiletype_ != Pit && tiletype_ != Wall) {
        ispassable_ = true;
    }
}

TileType DungeonTile::GetTileType() const {
    return tiletype_;
}

DungeonTile* DungeonTile::GetTileNeighbor(const std::string direction) const {
    if (direction == "N") {
        return tileneighbors_[0];
    }
    else if (direction == "E") {
        return tileneighbors_[1];
    }
    else if (direction == "W") {
        return tileneighbors_[2];
    }
    else {
        return tileneighbors_[3];
    }
}

void DungeonTile::SetTileNeighbors(std::vector<DungeonTile*> neighborvector) {
    tileneighbors_.push_back(neighborvector[0]);
    tileneighbors_.push_back(neighborvector[1]);
    tileneighbors_.push_back(neighborvector[2]);
    tileneighbors_.push_back(neighborvector[3]);
}


void DungeonTile::Close() {
    if (tiletype_ == Door) {
        isopen_ = false;
        ispassable_ = false;
    }
}

void DungeonTile::Open() {
    if (tiletype_ != Pit && tiletype_ != Wall && item_ == nullptr) {
        isopen_ = true;
        if (hascharacter_ == false) {
            ispassable_ = true;
        }
    }
}

bool DungeonTile::IsOpen() const {
    return isopen_;
}

TrapState DungeonTile::GetTrapState() const {
    return trapstate_;
}

void DungeonTile::ProceedTrapState() {
    if (tiletype_ == Trap) {
        if (trapstate_ == Dormant) {
            trapstate_ = Emerging;
        }
        else if (trapstate_ == Emerging) {
            trapstate_ = Spikes;
        }
        else {
            trapstate_ = Dormant;
        }
    }
}