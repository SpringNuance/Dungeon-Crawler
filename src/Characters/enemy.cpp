#include "enemy.hpp"
#include <cmath>

//Enemy is a class that all enemy type classes inherit. Holds information
//about the movement speed and attack damage of 
//an enemy character, its own location in a room and a vector that holds
//its action pattern that the enemy will proceed through by one every time
//it takes a turn. Enemies will randomize the step they are on in their
//action pattern when they are created.


Enemy::Enemy(const std::string& name, const std::string& description, DungeonTile* tile, EnemyAI enemyai, std::vector<ActionType> actionvector)
    : Character(EnemyCharacter, 1, tile), enemyai_(enemyai), actionvector_(actionvector), name_(name), description_(description) {
        indexinactionvector_ = rand() % actionvector_.size();
    }

EnemyAI Enemy::GetEnemyAI() const {
    return enemyai_;
}

std::vector<ActionType> Enemy::GetActionVector() const {
    return actionvector_;
}

int Enemy::GetCurrentActionIndex() const {
    return indexinactionvector_;
}

ActionType Enemy::GetCurrentAction() const {
    return actionvector_[indexinactionvector_];
}

void Enemy::MoveTowards(Character* targetcharacter) {
    //Attempts to move the character to the given direction,
    int ydiff = GetYCoordinate() - targetcharacter->GetYCoordinate();
    int xdiff = GetXCoordinate() - targetcharacter->GetXCoordinate();
    // xdiff > 0 => enemy is left, go W
    //xdiff < 0 => enemy is right, go E
    //ydiff > 0 => enemy is up, go N
    //ydiff < 0 => enemy is down , go  S
    int rndm = (rand() % 2);
    int attemptsuccessful = -1;
    if (abs(xdiff) > abs(ydiff)) { //Horizontal movement attempt
        if (xdiff > 0) { //attempt to move towards W
            attemptsuccessful = MoveToDirection("W");
            if (attemptsuccessful < 0) {
                if (ydiff == 0) {
                    if (rndm == 1) {
                        if (currenttile_->GetTileNeighbor("N")->IsPassable()){
                            if ((currenttile_->GetTileNeighbor("N")->GetTileNeighbor("W")->GetTileType() !=  Wall) && (currenttile_->GetTileNeighbor("N")->GetTileNeighbor("W")->GetTileType() != Pit)) {
                                MoveToDirection("N");
                            }
                            else if (currenttile_->GetTileNeighbor("S")->IsPassable()){
                                MoveToDirection("S");
                            }
                            else{
                                MoveToDirection("N");
                            }
                        }
                        else {
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("S");
                            }
                        }
                    }
                    else {
                        if (currenttile_ -> GetTileNeighbor("S")->IsPassable()) {
                            if ((currenttile_->GetTileNeighbor("S")->GetTileNeighbor("W")->GetTileType() != Wall) && (currenttile_->GetTileNeighbor("S")->GetTileNeighbor("W")->GetTileType() != Pit)) {
                                MoveToDirection("S");
                            }
                            else if (currenttile_->GetTileNeighbor("N")->IsPassable() ){
                                MoveToDirection("N");
                            }
                            else {
                                MoveToDirection("S");
                            }
                        }
                        else {
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("N");
                            }
                        }
                    }
                }
                else {
                    if (ydiff > 0) {
                        attemptsuccessful = MoveToDirection("N");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("S");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("E");
                            }
                        }
                    }
                    else {
                        attemptsuccessful = MoveToDirection("S");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("N");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("E");
                            }
                        }
                    }
                }
            }
        }
        else { //Attempt to move towards E
            attemptsuccessful = MoveToDirection("E");
            if (attemptsuccessful < 0) {
                if (ydiff == 0) {
                    if (rndm == 1) {
                        if (currenttile_->GetTileNeighbor("N")->IsPassable()){
                            if ((currenttile_->GetTileNeighbor("N")->GetTileNeighbor("E")->GetTileType() !=  Wall) && (currenttile_->GetTileNeighbor("N")->GetTileNeighbor("E")->GetTileType() != Pit)) {
                                MoveToDirection("N");
                            }
                            else if (currenttile_->GetTileNeighbor("S")->IsPassable()){
                                MoveToDirection("S");
                            }
                            else{
                                MoveToDirection("N");
                            }
                        }
                        else {
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("S");
                            }
                        }
                    }
                    else {
                        if (currenttile_ -> GetTileNeighbor("S")->IsPassable()) {
                            if ((currenttile_->GetTileNeighbor("S")->GetTileNeighbor("E")->GetTileType() != Wall) && (currenttile_->GetTileNeighbor("S")->GetTileNeighbor("E")->GetTileType() != Pit)) {
                                MoveToDirection("S");
                            }
                            else if (currenttile_->GetTileNeighbor("N")->IsPassable() ){
                                MoveToDirection("N");
                            }
                            else {
                                MoveToDirection("S");
                            }
                        }
                        else {
                           attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("N");
                            }
                        }
                    }
                }
                else {
                    if (ydiff > 0) {
                        attemptsuccessful = MoveToDirection("N");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("S");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("W");
                            }
                        }
                    }
                    else {
                        attemptsuccessful = MoveToDirection("S");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("N");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("W");
                            }
                        }
                    }
                }
            }
        }
    }
    else if (abs(ydiff) > abs(xdiff)) { //vertical movement attempt
        if (ydiff > 0) { //attempt to move towards N
            attemptsuccessful = MoveToDirection("N");
            if (attemptsuccessful < 0) {
                if (xdiff == 0) {
                    if (rndm == 1) {
                        if (currenttile_->GetTileNeighbor("E")->IsPassable()) {
                            if ((currenttile_->GetTileNeighbor("E")->GetTileNeighbor("N")->GetTileType() !=  Wall) && (currenttile_->GetTileNeighbor("E")->GetTileNeighbor("N")->GetTileType() != Pit)) {
                                MoveToDirection("E");
                            }
                            else if (currenttile_->GetTileNeighbor("W")->IsPassable()) {
                                MoveToDirection("W");
                            }
                            else if (currenttile_->GetTileNeighbor("E")->IsPassable()){
                                MoveToDirection("E");
                            }
                            else {
                                MoveToDirection("S");
                            }
                        }
                        else {
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("S");
                            }
                        }
                    }
                    else {
                        if (currenttile_->GetTileNeighbor("W")->IsPassable()) {
                            if ((currenttile_->GetTileNeighbor("W")->GetTileNeighbor("N")->GetTileType() != Wall) && (currenttile_->GetTileNeighbor("W")->GetTileNeighbor("N")->GetTileType() != Pit)) {
                                MoveToDirection("W");
                            }
                            else if (currenttile_->GetTileNeighbor("E")->IsPassable() ){
                                MoveToDirection("E");
                            }
                            else {
                                MoveToDirection("W");
                            }
                        }
                        else {
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("S");
                            }
                        }
                    }
                }
                else {
                    if (xdiff > 0) {
                        attemptsuccessful = MoveToDirection("W");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("S");
                            }
                        }
                    }
                    else {
                        attemptsuccessful = MoveToDirection("E");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("S");
                            }
                        }
                    }
                }
            }
        }
        else { //attempt to move towards S
            attemptsuccessful = MoveToDirection("S");
            if (attemptsuccessful < 0) {
                if (xdiff == 0) {
                    if (rndm == 1) {
                        if (currenttile_->GetTileNeighbor("E")->IsPassable()){
                            if ((currenttile_->GetTileNeighbor("E")->GetTileNeighbor("S")->GetTileType() !=  Wall) && (currenttile_->GetTileNeighbor("E")->GetTileNeighbor("S")->GetTileType() != Pit)) {
                                MoveToDirection("E");
                            }
                            else if (currenttile_->GetTileNeighbor("W")->IsPassable()){
                                MoveToDirection("W");
                            }
                            else{
                                MoveToDirection("E");
                            }
                        }
                        else {
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("N");
                            }
                        }
                    }
                    else {
                        if (currenttile_->GetTileNeighbor("W")->IsPassable()) {
                            if ((currenttile_->GetTileNeighbor("W")->GetTileNeighbor("S")->GetTileType() != Wall) && (currenttile_->GetTileNeighbor("W")->GetTileNeighbor("S")->GetTileType() != Pit)) {
                                MoveToDirection("W");
                            }
                            else if (currenttile_->GetTileNeighbor("E")->IsPassable() ){
                                MoveToDirection("E");
                            }
                            else {
                                MoveToDirection("W");
                            }
                        }
                        else {
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("N");
                            }
                        }
                    }
                }
                else {
                    if (xdiff > 0) {
                        attemptsuccessful = MoveToDirection("W");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("N");
                            }
                        }
                    }
                    else {
                        attemptsuccessful = MoveToDirection("E");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("N");
                            }
                        }
                    }
                }
            }   
        }
    }
    else { //DIFFERENCES ARE EQUAL
        std::string attemptdirx = "";
        std::string attemptdiry = "";
        if (xdiff > 0) {
            attemptdirx = "W";
        }
        else {
            attemptdirx = "E";
        }
        if (ydiff > 0) {
            attemptdiry = "N";
        }
        else {
            attemptdiry = "S";
        }
        if (rndm == 1) { // Attempt horizontal first
            if (currenttile_->GetTileNeighbor(attemptdirx.c_str())->IsPassable()) {
                MoveToDirection(attemptdirx.c_str());
            }
            else {
                if (currenttile_->GetTileNeighbor(attemptdiry.c_str())->IsPassable()) {
                    //Move to attemptdiry
                    MoveToDirection(attemptdiry.c_str());
                }
                else {
                    int r = (rand()%2);
                    if (r == 1) {
                        if (attemptdirx == "E") {
                            //attempt to move to W
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                if (attemptdiry == "N") {
                                    //attempt to move to S
                                    MoveToDirection("S");
                                }
                                else {
                                    //attempt to move to N
                                    MoveToDirection("N");
                                }
                            }
                        }
                        else {
                            //attempt to move to E
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                if (attemptdiry == "N") {
                                    //attempt to move to S
                                    MoveToDirection("S");
                                }
                                else {
                                    //attempt to move to N
                                    MoveToDirection("N");
                                }
                            }
                        }
                    }
                    else {
                        if (attemptdiry == "N") {
                            //attempt to move to S
                            attemptsuccessful = MoveToDirection("S");
                            if (attemptsuccessful < 0) {
                                if (attemptdirx == "E") {
                                    //attempt to move to W
                                    MoveToDirection("W");
                                }
                                else {
                                    //attempt to move to E
                                    MoveToDirection("E");
                                }
                            }
                        }
                        else {
                            //attempt to move to N
                            attemptsuccessful = MoveToDirection("N");
                            if (attemptsuccessful < 0) {
                                if (attemptdirx == "E") {
                                    //attempt to move to W
                                    MoveToDirection("W");
                                }
                                else {
                                    //attempt to move to E
                                    MoveToDirection("E");
                                }
                            }
                        }
                    }
                }
            }
        }
        else { //Attempt vertical first
            if (currenttile_->GetTileNeighbor(attemptdiry.c_str())->IsPassable()) {
                MoveToDirection(attemptdiry.c_str());
            }
            else {
                if (currenttile_->GetTileNeighbor(attemptdirx.c_str())->IsPassable()) {
                    //Move to attemptdirx
                    MoveToDirection(attemptdirx.c_str());
                }
                else {
                    int rr= (rand()%2);
                    
                    if (rr == 0) {
                        if (attemptdirx == "E") {
                            //attempt to move to W
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                if (attemptdiry == "N") {
                                    //attempt to move to S
                                    MoveToDirection("S");
                                }
                                else {
                                    //attempt to move to N
                                    MoveToDirection("N");
                                }
                            }
                        }
                        else {
                            //attempt to move to E
                            attemptsuccessful= MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                if (attemptdiry == "N") {
                                    //attempt to move to S
                                    MoveToDirection("S");
                                }
                                else {
                                    //attempt to move to N
                                    MoveToDirection("N");
                                }
                            }
                        }
                    }
                    else {
                        if (attemptdiry == "N") {
                            //attempt to move to S
                            attemptsuccessful= MoveToDirection("S");
                            if (attemptsuccessful < 0) {
                                if (attemptdirx == "E") {
                                    MoveToDirection("W");
                                    //attempt to move to W
                                }
                                else {
                                    //attempt to move to E
                                    MoveToDirection("E");
                                }
                            }
                        }
                        else {
                            //attempt to move to N
                            attemptsuccessful = MoveToDirection("N");
                            if (attemptsuccessful < 0) {
                                if (attemptdirx == "E") {
                                    //attempt to move to W
                                    MoveToDirection("W");
                                }
                                else {
                                    //attempt to move to E
                                    MoveToDirection("E");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Enemy::MoveAwayFrom(Character* targetcharacter) {
    //Attempts to move the character away from the given character
    int ydiff = GetYCoordinate() - targetcharacter->GetYCoordinate();
    int xdiff = GetXCoordinate() - targetcharacter->GetXCoordinate();
    //xdiff > 0 => go E
    //xdiff < 0 => go W
    //ydiff > 0 => go S
    //ydiff < 0 => go N
    int rndm = (rand() % 2);
    int attemptsuccessful = -1;
    if (abs(xdiff) < abs(ydiff)) { //Horizontal movement attempt
        if (xdiff > 0) { //attempt to move towards E
            attemptsuccessful = MoveToDirection("E");
            if (attemptsuccessful < 0) {
                if (ydiff > 0) {
                    attemptsuccessful = MoveToDirection("S");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("N");
                        if (attemptsuccessful < 0) {
                            MoveToDirection("W");
                        }
                    }
                }
                else {
                    attemptsuccessful = MoveToDirection("N");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("S");
                        if (attemptsuccessful < 0) {
                            MoveToDirection("W");
                        }
                    }
                }
            }
        }
        else if (xdiff < 0) { //Attempt to move towards W
            attemptsuccessful = MoveToDirection("W");
            if (attemptsuccessful < 0) {
                if (ydiff > 0) {
                    attemptsuccessful = MoveToDirection("S");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("N");
                        if (attemptsuccessful < 0) {
                            MoveToDirection("E");
                        }
                    }
                }
                else {
                    attemptsuccessful = MoveToDirection("N");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("S");
                        if (attemptsuccessful < 0) {
                            MoveToDirection("E");
                        }
                    }
                }
            }
        }
        else {
            rndm = (rand() % 2);
            if (rndm == 1) {
                attemptsuccessful = MoveToDirection("E");
                if (attemptsuccessful < 0) {
                    attemptsuccessful = MoveToDirection("W");
                    if (attemptsuccessful < 0) {
                        if (ydiff > 0) {
                            attemptsuccessful = MoveToDirection("S");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("N");
                            }
                        }
                        else {
                            attemptsuccessful = MoveToDirection("N");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("S");
                            }
                        }
                    }
                }
            }
            else {
                attemptsuccessful = MoveToDirection("W");
                if (attemptsuccessful < 0) {
                    attemptsuccessful = MoveToDirection("E");
                    if (attemptsuccessful < 0) {
                        if (ydiff > 0) {
                            attemptsuccessful = MoveToDirection("S");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("N");
                            }
                        }
                        else {
                            attemptsuccessful = MoveToDirection("N");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("S");
                            }
                        }
                    }
                }
            }
        }
    }
    else if (abs(ydiff) < abs(xdiff)) { //vertical movement attempt
        if (ydiff > 0) { //attempt to move towards S
            attemptsuccessful = MoveToDirection("S");
            if (attemptsuccessful < 0) {
                if (xdiff > 0) {
                    attemptsuccessful = MoveToDirection("E");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("W");
                        if (attemptsuccessful < 0) {
                            MoveToDirection("N");
                        }
                    }
                }
                else {
                    attemptsuccessful = MoveToDirection("W");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("E");
                        if (attemptsuccessful < 0) {
                            MoveToDirection("N");
                        }
                    }
                }
            }
        }
        else if (ydiff < 0) { //attempt to move towards N
            attemptsuccessful = MoveToDirection("N");
            if (attemptsuccessful < 0) {
                if (xdiff > 0) {
                    attemptsuccessful = MoveToDirection("E");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("W");
                        if (attemptsuccessful < 0) {
                            MoveToDirection("S");
                        }
                    }
                }
                else {
                    attemptsuccessful = MoveToDirection("W");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("E");
                        if (attemptsuccessful < 0) {
                            MoveToDirection("S");
                        }
                    }
                }
            }
        }
        else { //ydiff = 0
            if (xdiff > 0) {
                rndm = rand() % 2;
                if (rndm == 1) {
                    attemptsuccessful = MoveToDirection("S");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("N");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("W");
                            }
                        }
                    }
                }
                else {
                    attemptsuccessful = MoveToDirection("N");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("S");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("W");
                            }
                        }
                    }
                }
            }
            else {
                rndm = rand() % 2;
                if (rndm == 0) {
                    attemptsuccessful = MoveToDirection("S");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("N");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("E");
                            }
                        }
                    }
                }
                else { 
                    attemptsuccessful = MoveToDirection("N");
                    if (attemptsuccessful < 0) {
                        attemptsuccessful = MoveToDirection("S");
                        if (attemptsuccessful < 0) {
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                MoveToDirection("E");
                            }
                        }
                    }
                }
            }
        }
    }
    else { //DIFFERENCES ARE EQUAL
        std::string attemptdirx = "";
        std::string attemptdiry = "";
        if (xdiff > 0) {
            attemptdirx = "E";
        }
        else {
            attemptdirx = "W";
        }
        if (ydiff > 0) {
            attemptdiry = "S";
        }
        else {
            attemptdiry = "N";
        }
        if (rndm == 1) { // Attempt horizontal first
            if (currenttile_->GetTileNeighbor(attemptdirx.c_str())->IsPassable()) {
                MoveToDirection(attemptdirx.c_str());
            }
            else {
                if (currenttile_->GetTileNeighbor(attemptdiry.c_str())->IsPassable()) {
                    //Move to attemptdiry
                    MoveToDirection(attemptdiry.c_str());
                }
                else {
                    int r = (rand()%2);
                    if (r == 1) {
                        if (attemptdirx == "W") {
                            //attempt to move to W
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                if (attemptdiry == "S") {
                                    //attempt to move to S
                                    MoveToDirection("N");
                                }
                                else {
                                    //attempt to move to N
                                    MoveToDirection("S");
                                }
                            }
                        }
                        else {
                            //attempt to move to E
                            attemptsuccessful = MoveToDirection("W");
                            if (attemptsuccessful = -1) {
                                if (attemptdiry == "S") {
                                    //attempt to move to S
                                    MoveToDirection("N");
                                }
                                else {
                                    //attempt to move to N
                                    MoveToDirection("S");
                                }
                            }
                        }
                    }
                    else {
                        if (attemptdiry == "S") {
                            //attempt to move to S
                            attemptsuccessful = MoveToDirection("N");
                            if (attemptsuccessful < 0) {
                                if (attemptdirx == "W") {
                                    //attempt to move to W
                                    MoveToDirection("E");
                                }
                                else {
                                    //attempt to move to E
                                    MoveToDirection("W");
                                }
                            }
                        }
                        else {
                            //attempt to move to N
                            attemptsuccessful = MoveToDirection("S");
                            if (attemptsuccessful < 0) {
                                if (attemptdirx == "W") {
                                    //attempt to move to W
                                    MoveToDirection("E");
                                }
                                else {
                                    //attempt to move to E
                                    MoveToDirection("W");
                                }
                            }
                        }
                    }
                }
            }
        }
        else { //Attempt vertical first
            if (currenttile_->GetTileNeighbor(attemptdiry.c_str())->IsPassable()) {
                MoveToDirection(attemptdiry.c_str());
            }
            else {
                if (currenttile_->GetTileNeighbor(attemptdirx.c_str())->IsPassable()) {
                    //Move to attemptdirx
                    MoveToDirection(attemptdirx.c_str());
                }
                else {
                    int rr= (rand()%2);
                    
                    if (rr == 0) {
                        if (attemptdirx == "W") {
                            //attempt to move to W
                            attemptsuccessful = MoveToDirection("E");
                            if (attemptsuccessful < 0) {
                                if (attemptdiry == "S") {
                                    //attempt to move to S
                                    MoveToDirection("N");
                                }
                                else {
                                    //attempt to move to N
                                    MoveToDirection("S");
                                }
                            }
                        }
                        else {
                            //attempt to move to E
                            attemptsuccessful= MoveToDirection("W");
                            if (attemptsuccessful < 0) {
                                if (attemptdiry == "S") {
                                    //attempt to move to S
                                    MoveToDirection("N");
                                }
                                else {
                                    //attempt to move to N
                                    MoveToDirection("S");
                                }
                            }
                        }
                    }
                    else {
                        if (attemptdiry == "S") {
                            //attempt to move to S
                            attemptsuccessful= MoveToDirection("N");
                            if (attemptsuccessful < 0) {
                                if (attemptdirx == "W") {
                                    MoveToDirection("E");
                                    //attempt to move to W
                                }
                                else {
                                    //attempt to move to E
                                    MoveToDirection("W");
                                }
                            }
                        }
                        else {
                            //attempt to move to N
                            attemptsuccessful = MoveToDirection("S");
                            if (attemptsuccessful < 0) {
                                if (attemptdirx == "W") {
                                    //attempt to move to W
                                    MoveToDirection("E");
                                }
                                else {
                                    //attempt to move to E
                                    MoveToDirection("W");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Enemy::DistanceToCharacterLargerThanThree(Character* targetcharacter) const {
    DungeonTile* measurertile = targetcharacter->GetCurrentTile();
    int distance = 0;
    std::string xdir = "";
    std::string ydir = "";
    int ydifference = GetYCoordinate() - measurertile->GetYCoord();
    int xdifference = GetXCoordinate() - measurertile->GetXCoord();
    while ((measurertile->GetXCoord() != GetXCoordinate() && measurertile->GetYCoord() != GetYCoordinate()) || distance < 3) {
        if (xdifference > 0) {
            xdir = "E";
        }
        else {
            xdir = "W";
        }
        if (ydifference > 0) {
            ydir = "S";
        }
        else {
            ydir = "N";
        }
        if (abs(xdifference) > abs(ydifference)) {
            if (measurertile->GetTileNeighbor(xdir.c_str())->GetTileType() != Wall) {
                measurertile = measurertile->GetTileNeighbor(xdir.c_str());
            }
            else {
                measurertile = measurertile->GetTileNeighbor(ydir.c_str());
            }
        }
        else if (abs(ydifference) > abs(xdifference)) {
            if (measurertile->GetTileNeighbor(ydir.c_str())->GetTileType() != Wall) {
                measurertile = measurertile->GetTileNeighbor(ydir.c_str());
            }
            else {
                measurertile = measurertile->GetTileNeighbor(xdir.c_str());
            }
        }
        else {
            int randomnumber = rand() % 2 + 1;
            if (randomnumber == 1) {
                if (measurertile->GetTileNeighbor(ydir.c_str())->GetTileType() != Wall) {
                    measurertile = measurertile->GetTileNeighbor(ydir.c_str());
                }
                else {
                    measurertile = measurertile->GetTileNeighbor(xdir.c_str());
                }
            }
            else {
                if (measurertile->GetTileNeighbor(xdir.c_str())->GetTileType() != Wall) {
                    measurertile = measurertile->GetTileNeighbor(xdir.c_str());
                }
                else {
                    measurertile = measurertile->GetTileNeighbor(ydir.c_str());
                }
            }
        }
        ydifference = GetYCoordinate() - measurertile->GetYCoord();
        xdifference = GetXCoordinate() - measurertile->GetXCoord();
        if (ydifference == 0 && xdifference == 0) {
            break;
        }
        distance++;
    }

    if (measurertile->GetXCoord() == GetXCoordinate() && measurertile->GetYCoord() == GetYCoordinate()) {
        return false;
    }
    else {
        return true;
    }
}

bool Enemy::NextToCharacter(Character* targetcharacter) const {
    return ((GetXCoordinate() == targetcharacter->GetXCoordinate() && (abs(GetYCoordinate() - targetcharacter->GetYCoordinate()) == 1)) || (GetYCoordinate() == targetcharacter->GetYCoordinate() && (abs(GetXCoordinate() - targetcharacter->GetXCoordinate()) == 1)));
}

void Enemy::TakeAction(Character* targetcharacter, int fillernumber) {
    fillernumber = 1;
    RemoveDefensePoints();
    if (isstunned_ == 0 && (currenttile_->GetTileNeighbor("N")->IsPassable() || currenttile_->GetTileNeighbor("E")->IsPassable() || currenttile_->GetTileNeighbor("W")->IsPassable() || currenttile_->GetTileNeighbor("S")->IsPassable())) {
        if (enemyai_ == Random) {
            int randomnumber = rand() % 4 + 1;
            int movedsuccessfully = -1;
            bool attemptednorth = false;
            bool attemptedeast = false;
            bool attemptedwest = false;
            bool attemptedsouth = false;
            while (movedsuccessfully < 0 && !(attemptednorth && attemptedwest && attemptedeast && attemptedsouth)) {
                if (randomnumber == 1 && !attemptednorth) {
                    movedsuccessfully = MoveToDirection("N");
                    attemptednorth = true;
                }
                if (randomnumber == 2 && !attemptedeast) {
                    movedsuccessfully = MoveToDirection("E");
                    attemptedeast = true;
                }
                if (randomnumber == 3 && !attemptedwest) {
                    movedsuccessfully = MoveToDirection("W");
                    attemptedwest = true;
                }
                if (randomnumber == 4 && !attemptedsouth) {
                    movedsuccessfully = MoveToDirection("S");
                    attemptedsouth = true;
                }
                randomnumber = rand() % 4 + 1;
            }
        }
        if (enemyai_ == Aggressive) {
            MoveTowards(targetcharacter);
        }
        if (enemyai_ == Careful) {
            if (DistanceToCharacterLargerThanThree(targetcharacter)) {
                MoveTowards(targetcharacter);
            }
            else {
                MoveAwayFrom(targetcharacter);
            }
        }
        if (currenttile_->GetTrapState() == Spikes) {
            TakeDamage(1);
        }
        if (GetHealthPoints() <= 0) {
            return;
        }
        if (indexinactionvector_ < actionvector_.size() - 1) {
            indexinactionvector_+= fillernumber;
        }
        else {
            indexinactionvector_ = 0;
        }
        if (actionvector_[indexinactionvector_] == Defend_1) {
            AddDefensePoints(1);
        }
        if (actionvector_[indexinactionvector_] == Defend_2) {
            AddDefensePoints(2);
        }
        if (actionvector_[indexinactionvector_] == Defend_3) {
            AddDefensePoints(3);
        }
        if (actionvector_[indexinactionvector_] == Melee_1 && NextToCharacter(targetcharacter)) {
            targetcharacter->TakeDamage(1);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun(1);
            }
        }
        if (actionvector_[indexinactionvector_] == Melee_2 && NextToCharacter(targetcharacter)) {
            targetcharacter->TakeDamage(2);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun(1);
            }
        }
        if (actionvector_[indexinactionvector_] == Melee_3 && NextToCharacter(targetcharacter)) {
            targetcharacter->TakeDamage(3);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun(1);
            }
        }
        if (actionvector_[indexinactionvector_] == Ranged_1 && !DistanceToCharacterLargerThanThree(targetcharacter)) {
            targetcharacter->TakeDamage(1);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun(1);
            }
        }
        if (actionvector_[indexinactionvector_] == Ranged_2 && !DistanceToCharacterLargerThanThree(targetcharacter)) {
            targetcharacter->TakeDamage(2);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun(1);
            }
        }
        if (actionvector_[indexinactionvector_] == Ranged_3 && !DistanceToCharacterLargerThanThree(targetcharacter)) {
            targetcharacter->TakeDamage(3);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun(1);
            }
        }
    }
    else {
        UnStun();
    }
}

void Enemy::TakeDamage(int damage) {
    int takendamage = damage - defensepoints_;
    if (takendamage < 0) {
        takendamage = 0;
    }
    healthpoints_ = healthpoints_ - (takendamage);
    if (healthpoints_ <= 0) {
        currenttile_->RemoveCharacter();
    }
}

int Enemy::MoveToDirection(std::string direction) {
    if (currenttile_->GetTileNeighbor(direction)->IsPassable()) {
        currenttile_->GetTileNeighbor(direction)->SetCharacter();
        currenttile_->RemoveCharacter();
        currenttile_ = currenttile_->GetTileNeighbor(direction);
        return 1;
    }
    else {
        return -1;
    }
}

std::string Enemy::GetDescription() const {
    return description_;
}


Slime::Slime(DungeonTile* tile) : Enemy("Slime", "A blindly wandering blob of acidic jelly that tries to eat anything near it.", tile, Random, {Melee_1, Empty}) {}

LargeSlime::LargeSlime(DungeonTile* tile) : Enemy("Large slime", "A blindly wandering large blob of acidic jelly that tries to eat anything near it.", tile, Random, {Melee_2, Empty}) {}

HugeSlime::HugeSlime(DungeonTile* tile) : Enemy("Huge slime", "A blindly wandering enormous blob of acidic jelly that tries to eat anything near it.", tile, Random, {Melee_3, Empty}) {}

SmallSpider::SmallSpider(DungeonTile* tile) : Enemy("Spider", "A cave-dwelling arachnid with a set of sharp fangs.", tile, Aggressive, {Melee_1, Empty}) {}

Spider::Spider(DungeonTile* tile) : Enemy("Large spider", "An unusually large cave-dwelling arachnid with a set of long sharp fangs.", tile, Aggressive, {Melee_1, Melee_1, Empty}) {}

BigSpider::BigSpider(DungeonTile* tile) : Enemy("Huge spider", "A massive cave-dwelling arachnid with a set of enormous sharp fangs.", tile, Aggressive, {Melee_2, Melee_2, Empty}) {}

SpitterSpider::SpitterSpider(DungeonTile* tile) : Enemy("Spitter spider", "A large cave-dwelling arachnid that prefers to spit acidic venom from a distance.", tile, Careful, {Ranged_1, Empty, Melee_1, Empty}) {}

Skeleton::Skeleton(DungeonTile* tile) : Enemy("Skeleton", "The rotting skeleton of some poor peasant reanimated by dark magic. It is wielding a sword and a small shield.", tile, Aggressive, {Melee_1, Defend_1}) {}

SkeletonWarrior::SkeletonWarrior(DungeonTile* tile) : Enemy("Skeleton warrior", "The rotting skeleton of some poor warrior reanimated by dark magic. It is wielding a warhammer and a shield.", tile, Aggressive, {Melee_2, Defend_2}) {}

SkeletonKnight::SkeletonKnight(DungeonTile* tile) : Enemy("Skeleton knight", "The rotting skeleton of some poor knight reanimated by dark magic. It is wearing a full suit of armor and wields a sword.", tile, Aggressive, {Melee_1, Defend_2, Defend_2}) {}

SkeletonArcher::SkeletonArcher(DungeonTile* tile) : Enemy("Skeleton archer", "The rotting skeleton of some poor adventurer reanimated by dark magic. It is wielding a bow and has a quiver full of arrows.", tile, Careful, {Ranged_2, Empty, Empty, Empty}) {}

SkeletonMage::SkeletonMage(DungeonTile* tile) : Enemy("Skeleton mage", "The rotting skeleton of some poor mage reanimated by dark magic. It is wielding a magic staff that glows menacingly in the darkness.", tile, Careful, {Ranged_1, Empty, Defend_1}) {}

Lich::Lich(DungeonTile* tile) : Enemy("The Lich", "The undead king of the underworld, said to have been the most powerful necromancer who ever existed when he was still alive.", tile, Stationary, {Ranged_3, Defend_3, Melee_3, Empty}) {}
