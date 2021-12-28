#pragma once


#include "character.hpp"
#include <stdlib.h> //For randomization purposes.
#include <time.h> //For creating a random seed.
#include <string>

//Enemy is a class that all enemy type classes inherit. Holds information
//about the movement speed and attack damage of 
//an enemy character, its own location in a room and a vector that holds
//its action pattern that the enemy will proceed through by one every time
//it takes a turn. Enemies will randomize the step they are on in their
//action pattern when they are created.


class Enemy : public Character {
    public:
    Enemy(const std::string& name, const std::string& description, DungeonTile* tile, EnemyAI enemyai, std::vector<ActionType> actionvector);

    EnemyAI GetEnemyAI() const; //Returns the AI type of the enemy. 

    std::vector<ActionType> GetActionVector() const; //Returns the enemy action pattern.

    ActionType GetCurrentAction() const; //Returns the current enemy action.

    int GetCurrentActionIndex() const; //Returns the current action vector index.

    void MoveTowards(Character* targetcharacter); //Pathfinds towards the target character.

    void MoveAwayFrom(Character* targetcharacter); //Pathfinds away from the targer character.

    bool DistanceToCharacterLargerThanThree(Character* targetcharacter) const; //Checks if an enemy can be reached in three steps through tiles that aren't walls.

    bool NextToCharacter(Character* targetcharacter) const; //Checks if the target character is next to the character.

    void TakeAction(Character* targetcharacter, int fillernumber); //Proceeds the actionvector index by one and moves the character according to its AI.

    void TakeDamage(int damage); //Damages the character.

    int MoveToDirection(std::string direction); //Attempts to move the character to the given direction, returns -1 if didn't succeed, positive otherwise.

    std::string GetDescription() const; //Returns the description of the enemy.

    std::vector<InventorySlot*> GetInventory() const {return {nullptr};};

    protected:
    EnemyAI enemyai_; //The behavior type of the enemy.
    std::vector<ActionType> actionvector_; //The vector that the enemy will proceed through whenever it takes a turn.
    int indexinactionvector_; //The current index of the action vector.
    std::string name_; //The name of the enemy.
    std::string description_; //A description of the enemy.
};


class Slime : public Enemy {
    public:
    Slime(DungeonTile* tile);
};

class LargeSlime : public Enemy {
    public:
    LargeSlime(DungeonTile* tile);
};

class HugeSlime : public Enemy {
    public:
    HugeSlime(DungeonTile* tile);
};

class SmallSpider : public Enemy {
    public:
    SmallSpider(DungeonTile* tile);
};

class Spider : public Enemy {
    public:
    Spider(DungeonTile* tile);
};

class BigSpider : public Enemy {
    public:
    BigSpider(DungeonTile* tile);
};

class SpitterSpider : public Enemy {
    public:
    SpitterSpider(DungeonTile* tile);
};

class Skeleton : public Enemy {
    public:
    Skeleton(DungeonTile* tile);
};

class SkeletonWarrior : public Enemy {
    public:
    SkeletonWarrior(DungeonTile* tile);
};

class SkeletonKnight : public Enemy {
    public:
    SkeletonKnight(DungeonTile* tile);
};

class SkeletonArcher : public Enemy {
    public:
    SkeletonArcher(DungeonTile* tile);
};

class SkeletonMage : public Enemy {
    public:
    SkeletonMage(DungeonTile* tile);
};

class Lich : public Enemy {
    public:
    Lich(DungeonTile* tile);
};