#include "dungeonroom.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h> //For randomization purposes.
#include <time.h> //For creating a random seed.
#include <string>
#include <algorithm> //For mirroring rooms horizontally.
#include <utility>


//Randomizes the name of the file in order to allow reading a random room file.
std::string RandomizeFileName(RoomType roomtype) {
    std::string filename;
    unsigned int randomnumber = 0;
    if (roomtype == _1DoorRoom) {
        filename = "1DoorRooms/";
        randomnumber = rand() % 13 + 1; //Random number between 1 and the amount of rooms in 1DoorRooms storage folder
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else if (roomtype == _2DoorRoomCorner) {
        filename = "2DoorRoomsCorner/";
        randomnumber = rand() % 13 + 1; //Random number between 1 and the amount of rooms in 2DoorRoomsCorner storage folder
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else if (roomtype == _2DoorRoomOpposite) {
        filename = "2DoorRoomsOpposite/";
        randomnumber = rand() % 13 + 1; //Random number between 1 and the amount of rooms in 2DoorRoomsOpposite storage folder
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else if (roomtype == _3DoorRoom) {
        filename = "3DoorRooms/";
        randomnumber = rand() % 7 + 1; //Random number between 1 and the amount of rooms in 3DoorRooms storage folder
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else {
        filename = "4DoorRooms/1"; //There will be only one type of four door rooms.
    }
    return filename;
}

//Mirrors the contents given as the parameter vertically.
std::vector<std::string> MirrorRoomVertically(std::vector<std::string> roomvector) {
    std::vector<std::string> roomvector2;
    for (int i = 11; i >= 0; i--) {
        roomvector2.push_back(roomvector[i]);
    }
    return roomvector2;
}

//Mirrors the contents given as the parameter horizontally.
std::vector<std::string> MirrorRoomHorizontally(std::vector<std::string> roomvector) {
    for (int j = 0; j < 12; j++) {
        for (int i = 0; i < 12 / 2; i++) {
            std::swap(roomvector[j][i], roomvector[j][11 - i]);
        }
    }
    return roomvector;
}

//Rotates the contents of the vector clockwise.
//Rotates the contents of the vector clockwise.
std::vector<std::string> RotateRoomClockwise(std::vector<std::string> roomvector) {
    std::vector<std::string> roomvector2;
    std::string tempstring = "";
    for (int j = 0; j < 12; j++) {
        for (int i = 11; i >= 0; i--) {
            tempstring += roomvector[i][j];
        }
        roomvector2.push_back(tempstring);
        tempstring = "";
    }
    return roomvector2;
}

std::vector<std::string> RandomizeRoom(std::vector<std::string> roomvector, DoorOrientation doororientation) {
    if (doororientation == East || doororientation == SouthEast || doororientation == Horizontal) {
        roomvector = RotateRoomClockwise(roomvector);
    }
    if (doororientation == South || doororientation == SouthWest) {
        roomvector = RotateRoomClockwise(roomvector);
        roomvector = RotateRoomClockwise(roomvector);
    }
    if (doororientation == West || doororientation == NorthWest) {
        roomvector = RotateRoomClockwise(roomvector);
        roomvector = RotateRoomClockwise(roomvector);
        roomvector = RotateRoomClockwise(roomvector);
    }
    int randomnumber = rand() % 2; //Random number that is either 1 or 0.
    if (randomnumber == 1) { //Mirror the room vertically with 50% probability.
        roomvector = MirrorRoomVertically(roomvector);
        if (doororientation == NorthEast || doororientation == SouthWest) {
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == SouthEast || doororientation == NorthWest) {
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == North || doororientation == South) {
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
    }

    randomnumber = rand() % 2; //Random number that is either 1 or 0.
    if (randomnumber == 1) { //Mirror the room horizontally with 50% probability.
        roomvector = MirrorRoomHorizontally(roomvector);
        if (doororientation == NorthWest || doororientation == SouthEast) {
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == NorthEast || doororientation == SouthWest) {
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == East || doororientation == West) {
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
    }
    return roomvector;
}

std::vector<std::vector<DungeonTile*>> CreateTiles(std::vector<std::string> roomvector, bool isplayerstartingroom) {
    std::vector<std::vector<DungeonTile*>> tilevector;
    std::vector<DungeonTile*> tempvector;
    std::vector<DungeonTile*> neighborvector;
    for (int j = 0; j < 12; j++) {
        for (int i = 0; i < 12; i++) {
            if (roomvector[j][i] == '#') {
                tempvector.push_back(new DungeonTile(TileType::Wall, i, j));
                // DungeonTile::DungeonTile(TileType tiletype, int xcoord, int ycoord) 
            }
            else if (roomvector[j][i] == '*') {
                tempvector.push_back(new DungeonTile(TileType::Floor, i, j));
            }
            else if (roomvector[j][i] == '+') {
                tempvector.push_back(new DungeonTile(TileType::Pit, i, j));
            }
            else if (roomvector[j][i] == '=') {
                tempvector.push_back(new DungeonTile(TileType::Door, i, j));
            }
            else if (roomvector[j][i] == 'E') {
                tempvector.push_back(new DungeonTile(TileType::Spawner, i, j));
            }
            else if (roomvector[j][i] == 'T') {
                tempvector.push_back(new DungeonTile(TileType::Trap, i, j));
            }
            else if (roomvector[j][i] == 'U') {
                if (isplayerstartingroom) {
                    tempvector.push_back(new DungeonTile(TileType::Entrance, i, j));
                }
                else {
                    tempvector.push_back(new DungeonTile(TileType::Floor, i, j));
                }
            }
            else if (roomvector[j][i] == 'L') {
                tempvector.push_back(new DungeonTile(TileType::Loot, i, j));
            }
            else {
                tempvector.push_back(new DungeonTile(TileType::Exit, i, j));
            }
        }
        tilevector.push_back(tempvector);
        for (int k = 0; k < 12; k++) {
            tempvector.pop_back();
        }
    }
    for (int a = 0; a < 12; a++) {
        for (int b = 0; b < 12; b++) {
            if (a - 1 >= 0) { //North neighbor
                neighborvector.push_back(tilevector[a - 1][b]);
            }
            else {
                neighborvector.push_back(nullptr);
            }
            if (b + 1 <= 11) { //East neighbor
                neighborvector.push_back(tilevector[a][b + 1]);
            }
            else {
                neighborvector.push_back(nullptr);
            }
            if (b - 1 >= 0) { //West neighbor
                neighborvector.push_back(tilevector[a][b - 1]);
            }
            else {
                neighborvector.push_back(nullptr);
            }
            if (a + 1 <= 11) { //South neighbor
                neighborvector.push_back(tilevector[a + 1][b]);
            }
            else {
                neighborvector.push_back(nullptr);
            }
            tilevector[a][b]->SetTileNeighbors(neighborvector);
            neighborvector.pop_back();
            neighborvector.pop_back();
            neighborvector.pop_back();
            neighborvector.pop_back();
        }
    }
    return tilevector;
}

//Represents a room of a level.
//A room consists of 144 tiles on a 12 x 12 grid.

DungeonRoom::DungeonRoom(std::pair<int,int> indexinlevel, RoomType roomtype, DoorOrientation doororientation, Item* loot, bool isplayerstartingroom)
    : indexinlevel_(indexinlevel), roomtype_(roomtype), doororientation_(doororientation), hasbeenexplored_(isplayerstartingroom), lastroominlevel_(false), loot_(loot) {
        std::vector<DungeonRoom*> neighbors_;
        std::fstream roomfile;
        std::string filename = "../src/DungeonGeneration/RoomStorage/";
        roomfile.open((filename += (RandomizeFileName(roomtype) + ".txt")), std::ios::in);
        if (!roomfile) {
            filename = "RoomStorage/";
            roomfile.open((filename += (RandomizeFileName(roomtype) + ".txt")), std::ios::in);
            if (!roomfile) {
                std::cout << "ERROR: File opening in RoomStorage failed. The opening path in dungeonroom.cpp may be incorrect.\nRunning the program and debugging it require different paths." << std::endl;
                throw;
            }
        }
        std::string readline;
        std::vector<std::string> roomvector;
        int i = 0;
        while (std::getline(roomfile, readline) && i < 12) {
            std::istringstream iss(readline);
            roomvector.push_back(readline);
            i++;
        }
        roomvector = RandomizeRoom(roomvector, doororientation);
        alltiles_ = CreateTiles(roomvector, isplayerstartingroom);
    }

std::pair<int,int> DungeonRoom::GetIndexInLevel() const {
    return indexinlevel_;
}

DungeonTile* DungeonRoom::GetDungeonTile(int xcoord, int ycoord) const {
    return alltiles_[xcoord][ycoord];
}

std::vector<std::vector<DungeonTile*>> DungeonRoom::GetAllTiles() const {
    return alltiles_;
}

bool DungeonRoom::IsExplored() const {
    return hasbeenexplored_;
}

bool DungeonRoom::IsLastRoomInLevel() const {
    return lastroominlevel_;
}

void DungeonRoom::SetLastRoomInLevel() {
    lastroominlevel_ = true;
}

void DungeonRoom::SpawnEnemies(std::vector<Character*> enemyvector) {
    int spawnedenemies = 0;
    int index = 0;
    if (!hasbeenexplored_) {
        for (auto j : alltiles_) {
            for (auto i : j) {
                if (i->GetTileType() == Spawner) {
                    if (enemyvector[index] != nullptr) {
                        i->SetCharacter();
                        enemyvector[index]->MoveToTile(i);
                        spawnedenemies++;
                    }
                    index++;
                }
            }
        }
        if (spawnedenemies > 0) {
            CloseDoors();
        }
        else {
            hasbeenexplored_ = true;
            SpawnLoot();
        }
    }
}

void DungeonRoom::GiveLoot(Item* lootitem) {
    loot_ = lootitem;
}

Item* DungeonRoom::GetLootItem() const {
    return loot_;
}

void DungeonRoom::SpawnLoot() {
    if (loot_ != nullptr) {
        for (auto j : alltiles_) {
            for (auto i : j) {
                if (i->GetTileType() == Loot && i->GetItem() == nullptr) {
                    i->PlaceItem(loot_);
                    loot_ = nullptr;
                }
            }
        }
    }
}

void DungeonRoom::CloseDoors() {
    alltiles_[0][5]->Close();
    alltiles_[0][6]->Close();
    alltiles_[11][5]->Close();
    alltiles_[11][6]->Close();
    alltiles_[5][0]->Close();
    alltiles_[6][0]->Close();
    alltiles_[5][11]->Close();
    alltiles_[6][11]->Close();
}

void DungeonRoom::OpenDoors() {
    hasbeenexplored_ = true;
    SpawnLoot();
    alltiles_[0][5]->Open();
    alltiles_[0][6]->Open();
    alltiles_[11][5]->Open();
    alltiles_[11][6]->Open();
    alltiles_[5][0]->Open();
    alltiles_[6][0]->Open();
    alltiles_[5][11]->Open();
    alltiles_[6][11]->Open();
}

std::vector<DungeonRoom*> DungeonRoom::GetNeighbors() const {
        return neighbors_;
}

DoorOrientation DungeonRoom::GetDoorOrientation() const {
    return doororientation_;
} 

RoomType DungeonRoom::GetRoomType() const {
    return roomtype_;
}

void DungeonRoom::AddNeighbor(DungeonRoom* room) {
    neighbors_.push_back(room);
}

