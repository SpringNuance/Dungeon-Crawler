
// C++ standard libraries
#include <iostream>
#include <vector>

// SFML
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// Project
#include "DungeonGeneration/dungeonlevel.hpp"
#include "DungeonGeneration/dungeonroom.hpp"
#include "DungeonGeneration/dungeontile.hpp"

#include "Characters/enemy.hpp"
#include "Characters/characterplayer.hpp"

#include "Items/meleeweapons.hpp"
#include "Items/rangedweapons.hpp"
#include "Items/shields.hpp"
#include "Items/potions.hpp"

#include "textures.cpp"


// Global variables
const int gameboard_orig_x = 64;
const int gameboard_orig_y = 66;




// A function that generates a vector of five enemies depending on the level the player is on.
//################################################################################################################################################################################
std::vector<Character*> GenerateRoomEnemies(int level) {
	if (level == 1) {
		int randomnumber = rand() % 3 + 1;
		if (randomnumber == 1) {
			return {new Slime(nullptr), new Slime(nullptr), new Slime(nullptr), new Slime(nullptr), new Slime(nullptr)};
		}
		else if (randomnumber == 2) {
			return {new SmallSpider(nullptr), nullptr, new Slime(nullptr), new SmallSpider(nullptr), nullptr};
		}
		else {
			return {nullptr, new Slime(nullptr), new Slime(nullptr), new Slime(nullptr), new SmallSpider(nullptr)};
		}
	}
	else if (level == 2) {
		int randomnumber = rand() % 4 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new LargeSlime(nullptr), new SmallSpider(nullptr), new LargeSlime(nullptr), new SmallSpider(nullptr), new SmallSpider(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new Spider(nullptr), new Slime(nullptr), new Slime(nullptr), new Spider(nullptr), new Spider(nullptr)};
		}
		else {
			return {new Spider(nullptr), new LargeSlime(nullptr), new Spider(nullptr), new Spider(nullptr), new Spider(nullptr)};
		}
	}
	else if (level == 3) {
		int randomnumber = rand() % 4 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new Spider(nullptr), new Spider(nullptr), new Spider(nullptr), new Spider(nullptr), new Spider(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new Spider(nullptr), new HugeSlime(nullptr), new HugeSlime(nullptr), new Spider(nullptr), new Spider(nullptr)};
		}
		else {
			return {new LargeSlime(nullptr), new LargeSlime(nullptr), new LargeSlime(nullptr), new BigSpider(nullptr), new SpitterSpider(nullptr)};
		}
	}
	else if (level == 4) {
		int randomnumber = rand() % 5 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new BigSpider(nullptr), new BigSpider(nullptr), new HugeSlime(nullptr), new BigSpider(nullptr), new HugeSlime(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new SpitterSpider(nullptr), new SmallSpider(nullptr), new SmallSpider(nullptr), new SpitterSpider(nullptr), new SmallSpider(nullptr)};
		}
		else if (randomnumber == 4) {
			return {new Spider(nullptr), new SpitterSpider(nullptr), new Spider(nullptr), new Spider(nullptr), nullptr};
		}
		else {
			return {new SpitterSpider(nullptr), new BigSpider(nullptr), new BigSpider(nullptr), new BigSpider(nullptr), nullptr};
		}
	}
	else if (level == 5) {
		int randomnumber = rand() % 5 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new Skeleton(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new Skeleton(nullptr), new SkeletonWarrior(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new SkeletonKnight(nullptr), new Skeleton(nullptr), new Skeleton(nullptr), new SkeletonArcher(nullptr), new Skeleton(nullptr)};
		}
		else if (randomnumber == 4) {
			return {new SkeletonArcher(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new Skeleton(nullptr), new Skeleton(nullptr)};
		}
		else {
			return {new SkeletonMage(nullptr), new SkeletonWarrior(nullptr), new SkeletonKnight(nullptr), new Skeleton(nullptr), new Skeleton(nullptr)};
		}
	}
	else {
		int randomnumber = rand() % 7 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new SkeletonArcher(nullptr), new SkeletonWarrior(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new SkeletonKnight(nullptr), new SkeletonMage(nullptr), new Skeleton(nullptr), new SkeletonMage(nullptr), new Skeleton(nullptr)};
		}
		else if (randomnumber == 4) {
			return {new SkeletonArcher(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new SkeletonKnight(nullptr), new SkeletonWarrior(nullptr)};
		}
		else if (randomnumber == 5) {
			return {new SkeletonKnight(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new SkeletonKnight(nullptr), new SkeletonWarrior(nullptr)};
		}
		else if (randomnumber == 6) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else {
			return {new SkeletonMage(nullptr), new SkeletonKnight(nullptr), new SkeletonKnight(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr)};
		}
	}
}


std::vector<std::vector<Item*>> CreateLoot() {
	std::vector<std::vector<Item*>> lootvector;

	//Level 1 loot: A heater shield, a melee weapon and a potion
	std::vector<Item*> level1lootvector = {new HeaterShield(), new HealthPotion()};
	int randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level1lootvector.push_back(new HandAxe());
	}
	else if (randomnumber == 2) {
		level1lootvector.push_back(new ArmingSword());
	}
	else {
		level1lootvector.push_back(new Mace());
	}

	//Level 2 loot: A melee & ranged weapon, a heater shield and a health&stamina potion
	randomnumber = rand() % 3 + 1;
	std::vector<Item*> level2lootvector;
	if (randomnumber == 1) {
		level2lootvector.push_back(new HandAxe());
	}
	else if (randomnumber == 2) {
		level2lootvector.push_back(new ArmingSword());
	}
	else {
		level2lootvector.push_back(new Mace());
	}
	level2lootvector.push_back(new HealthPotion());
	level2lootvector.push_back(new StaminaPotion());
	level2lootvector.push_back(new HeaterShield());
	randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level2lootvector.push_back(new Javelin());
	}
	else if (randomnumber == 2) {
		level2lootvector.push_back(new Bolas());
	}
	else {
		level2lootvector.push_back(new Sling());
	}

	//Level 3 loot: A kite shield and a melee weapon, and a health potion
	randomnumber = rand() % 3 + 1;
	std::vector<Item*> level3lootvector;
	randomnumber = rand() % 3 + 1;
	level3lootvector.push_back(new KiteShield());
	randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level3lootvector.push_back(new HandAxe());
	}
	else if (randomnumber == 2) {
		level3lootvector.push_back(new ArmingSword());
	}
	else {
		level3lootvector.push_back(new Mace());
	}
	level3lootvector.push_back(new HealthPotion());
	
	//Level 4 loot: A strong melee & ranged weapon, a health potion and a kite shield
	std::vector<Item*> level4lootvector;
	randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level4lootvector.push_back(new BattleAxe());
	}
	else if (randomnumber == 2) {
		level4lootvector.push_back(new LongSword());
	}
	else {
		level4lootvector.push_back(new WarHammer());
	}
	level4lootvector.push_back(new HealthPotion());
	level4lootvector.push_back(new KiteShield());
	randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level4lootvector.push_back(new Javelin());
	}
	else if (randomnumber == 2) {
		level4lootvector.push_back(new Bolas());
	}
	else {
		level4lootvector.push_back(new Sling());
	}

	//Level 5 loot: A ranged weapon, two health potions, a tower & kite shield and a strong melee weapon
	randomnumber = rand() % 3 + 1;
	std::vector<Item*> level5lootvector;
	if (randomnumber == 1) {
		level5lootvector.push_back(new Javelin());
	}
	else if (randomnumber == 2) {
		level5lootvector.push_back(new Bolas());
	}
	else {
		level5lootvector.push_back(new Sling());
	}
	level5lootvector.push_back(new HealthPotion());
	level5lootvector.push_back(new TowerShield());
	randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level5lootvector.push_back(new BattleAxe());
	}
	else if (randomnumber == 2) {
		level5lootvector.push_back(new LongSword());
	}
	else {
		level5lootvector.push_back(new WarHammer());
	}
	level5lootvector.push_back(new HealthPotion());
	
	//Level 6 loot: Two health potions, two tower shields, and a strong melee weapon.
	std::vector<Item*> level6lootvector;
	level6lootvector.push_back(new HealthPotion());
	level6lootvector.push_back(new TowerShield());
	level6lootvector.push_back(new TowerShield());
	randomnumber = rand() % 3 + 1;
	level6lootvector.push_back(new HealthPotion());
	if (randomnumber == 1) {
		level6lootvector.push_back(new BattleAxe());
	}
	else if (randomnumber == 2) {
		level6lootvector.push_back(new LongSword());
	}
	else {
		level6lootvector.push_back(new WarHammer());
	}

	lootvector.push_back(level1lootvector);
	lootvector.push_back(level2lootvector);
	lootvector.push_back(level3lootvector);
	lootvector.push_back(level4lootvector);
	lootvector.push_back(level5lootvector);
	lootvector.push_back(level6lootvector);
	return lootvector;
}





// This is a function for rendering one screen during a game. The function draws the whole game view with all its current contents whenever called.
//################################################################################################################################################################################
void RenderScreen(sf::RenderWindow* window, std::vector<std::vector<DungeonTile*>> tile_matrix, bool islastroominlevel, std::vector<Character*> enemyvec, Character* player, int currentlevel, bool combatongoing, Textures* textures) {

	// Create all sprites
	sf::Sprite game_view(textures->game_view);
	sf::Sprite sprite_door_closed(textures->door_closed);
	sf::Sprite sprite_floor(textures->floor);
	sf::Sprite sprite_levelexitclosed(textures->levelexitclosed);
	sf::Sprite sprite_levelexitopen(textures->levelexitopen);
	sf::Sprite sprite_pit(textures->pit);
	sf::Sprite sprite_trap1(textures->trap1);
	sf::Sprite sprite_trap2(textures->trap2);
	sf::Sprite sprite_trap3(textures->trap3);
	sf::Sprite sprite_wall(textures->wall);
	sf::Sprite sprite_healthpotion(textures->healthpotion);
	sf::Sprite sprite_staminapotion(textures->staminapotion);
	sf::Sprite sprite_shortsword(textures->shortsword);
	sf::Sprite sprite_armingsword(textures->armingsword);
	sf::Sprite sprite_longsword(textures->longsword);
	sf::Sprite sprite_hatchet(textures->hatchet);
	sf::Sprite sprite_battleaxe(textures->battleaxe);
	sf::Sprite sprite_mace(textures->mace);
	sf::Sprite sprite_warhammer(textures->warhammer);
	sf::Sprite sprite_roundshield(textures->roundshield);
	sf::Sprite sprite_heatershield(textures->heatershield);
	sf::Sprite sprite_kiteshield(textures->kiteshield);
	sf::Sprite sprite_towershield(textures->towershield);
	sf::Sprite sprite_sling(textures->sling);
	sf::Sprite sprite_bolas(textures->bolas);
	sf::Sprite sprite_javelin(textures->javelin);
	sf::Sprite sprite_aiaggressive(textures->aiaggressive);
	sf::Sprite sprite_aicareful(textures->aicareful);
	sf::Sprite sprite_aiboss(textures->aiboss);
	sf::Sprite sprite_airandom(textures->airandom);
	sf::Sprite sprite_aistunned(textures->aistunned);
	sf::Sprite sprite_defense1(textures->defense1);
	sf::Sprite sprite_defense2(textures->defense2);
	sf::Sprite sprite_defense3(textures->defense3);
	sf::Sprite sprite_melee1(textures->melee1);
	sf::Sprite sprite_melee2(textures->melee2);
	sf::Sprite sprite_melee3(textures->melee3);
	sf::Sprite sprite_ranged1(textures->ranged1);
	sf::Sprite sprite_ranged2(textures->ranged2);
	sf::Sprite sprite_ranged3(textures->ranged3);
	sf::Sprite sprite_emptyaction(textures->emptyaction);
	sf::Sprite sprite_enemybase(textures->enemybase);
	sf::Sprite sprite_playerbase(textures->playerbase);
	sf::Sprite sprite_depth1(textures->depth1);
	sf::Sprite sprite_depth2(textures->depth2);
	sf::Sprite sprite_depth3(textures->depth3);
	sf::Sprite sprite_depth4(textures->depth4);
	sf::Sprite sprite_depth5(textures->depth5);
	sf::Sprite sprite_depth6(textures->depth6);
	sf::Sprite sprite_health0(textures->health0);
	sf::Sprite sprite_health1(textures->health1);
	sf::Sprite sprite_health2(textures->health2);
	sf::Sprite sprite_health3(textures->health3);
	sf::Sprite sprite_health4(textures->health4);
	sf::Sprite sprite_health5(textures->health5);
	sf::Sprite sprite_nrzero(textures->nrzero);
	sf::Sprite sprite_nrone(textures->nrone);
	sf::Sprite sprite_nrtwo(textures->nrtwo);
	sf::Sprite sprite_nrthree(textures->nrthree);
	sf::Sprite sprite_nrfour(textures->nrfour);
	sf::Sprite sprite_nrfive(textures->nrfive);
	sf::Sprite sprite_nrsix(textures->nrsix);
	sf::Sprite sprite_nrseven(textures->nrseven);
	sf::Sprite sprite_nreight(textures->nreight);
	sf::Sprite sprite_nrinf(textures->nrinf);
	sf::Sprite sprite_att(textures->att);
	sf::Sprite sprite_defse(textures->defse);
	sf::Sprite sprite_coold(textures->coold);
	sf::Sprite sprite_maxcoold(textures->maxcoold);
	sf::Sprite sprite_dur(textures->dur);
	sf::Sprite sprite_nonum(textures->nonum);
	sf::Sprite sprite_infobtnview(textures->infobtnview);

	int x_orig = 64;
	int y_orig = 66;

	window->clear();
	window->draw(game_view);
	
	for (std::vector<DungeonTile*> i : tile_matrix) {
		for (DungeonTile* tile : i) {
			sf::Sprite sprite;
			sf::Sprite itemsprite;
			int x = x_orig + (tile->GetXCoord())*64;
			int y = y_orig + (tile->GetYCoord())*64;

			TileType tiletype = tile->GetTileType();
			if (tiletype == Floor || tiletype == Spawner || tiletype == Entrance || tiletype == Loot) {
				sprite = sprite_floor;
			}
			else if (tiletype == Wall) {
				sprite = sprite_wall;				
			}
			else if (tiletype == Pit) {
				sprite = sprite_pit;
			}
			else if (tiletype == Door) {
				if (!tile->IsOpen()) {
					sprite = sprite_door_closed;
				}
				else {
					sprite = sprite_floor;
				}
			}
			else if (tiletype == Trap) {
				if (tile->GetTrapState() == Dormant) {
					sprite = sprite_trap1;
				}
				else if (tile->GetTrapState() == Emerging) {
					sprite = sprite_trap2;
				}
				else {
					sprite = sprite_trap3;
				}
			}
			else if (tiletype == Exit) {
				if (islastroominlevel) {
					if (!tile->IsOpen()) {
						sprite = sprite_levelexitclosed;
					}
					else {
						sprite = sprite_levelexitopen;
					}
				}
				else {
					sprite = sprite_floor;
				}
			}
			sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
			window->draw(sprite);

			if (tile->GetItem() != nullptr) {
				auto item = tile->GetItem();
				if (item->GetName() == "Potion of healing") {
					itemsprite = sprite_healthpotion;
				}
				else if (item->GetName() == "Potion of stamina") {
					itemsprite = sprite_staminapotion;
				}
				else if (item->GetName() == "Javelin") {
					itemsprite = sprite_javelin;
				}
				else if (item->GetName() == "Bolas") {
					itemsprite = sprite_bolas;
				}
				else if (item->GetName() == "Sling") {
					itemsprite = sprite_sling;
				}
				else if (item->GetName() == "Round shield") {
					itemsprite = sprite_roundshield;
				}
				else if (item->GetName() == "Heater shield") {
					itemsprite = sprite_heatershield;
				}
				else if (item->GetName() == "Kite shield") {
					itemsprite = sprite_kiteshield;
				}
				else if (item->GetName() == "Tower shield") {
					itemsprite = sprite_towershield;
				}
				else if (item->GetName() == "Shortsword") {
					itemsprite = sprite_shortsword;
				}
				else if (item->GetName() == "Arming sword") {
					itemsprite = sprite_armingsword;
				}
				else if (item->GetName() == "Longsword") {
					itemsprite = sprite_longsword;
				}
				else if (item->GetName() == "Hatchet") {
					itemsprite = sprite_hatchet;
				}
				else if (item->GetName() == "Battleaxe") {
					itemsprite = sprite_battleaxe;
				}
				else if (item->GetName() == "Mace") {
					itemsprite = sprite_mace;
				}
				else if (item->GetName() == "Warhammer") {
					itemsprite = sprite_warhammer;	
				}
				itemsprite.setPosition(static_cast<float>(x), static_cast<float>(y));
				window->draw(itemsprite);
			}
		}
	}
    for (auto enemy : enemyvec) {
		sf::Sprite enemysprite = sprite_enemybase;
		sf::Sprite weaponsprite;
		sf::Sprite statussprite;
		if (enemy != nullptr) {
			int xcoord = enemy->GetXCoordinate();
			int ycoord = enemy->GetYCoordinate();
			int x = x_orig + (xcoord) * 64;
			int y = y_orig + (ycoord) * 64;
			ActionType currentaction = enemy->GetCurrentAction();
			EnemyAI currentAI = enemy->GetEnemyAI();
			//Draw the basic black enemy sprite here, the rest is drawn on top of it.
			if (currentaction == Melee_1) {
				//Draw the sword
				weaponsprite = sprite_melee1;
			}
			else if (currentaction == Melee_2) {
				//Draw the warhammer
				weaponsprite = sprite_melee2;
			}
			else if (currentaction == Melee_3) {
				//Draw the axe
				weaponsprite = sprite_melee3;
			}
			else if (currentaction == Ranged_1) {
				//Draw the smallest bow
				weaponsprite = sprite_ranged1;
			}
			else if (currentaction == Ranged_2) {
				//Draw the medium sized bow
				weaponsprite = sprite_ranged2;
			}
			else if (currentaction == Ranged_3) {
				//Draw the largest bow
				weaponsprite = sprite_ranged3;
			}
			else if (currentaction == Defend_1) {
				//Draw the shield with number 1
				weaponsprite = sprite_defense1;
			}
			else if (currentaction == Defend_2) {
				//Draw the shield with number 2
				weaponsprite = sprite_defense2;
			}
			else if (currentaction == Defend_3) {
				//Draw the shield with number 3
				weaponsprite = sprite_defense3;
			}
			else {
				//Draw the empty enemy sprite (has zero at top right corner)
				weaponsprite = sprite_emptyaction;
			}

			if (enemy->IsStunned()) {
				//Draw the Stunned AI symbol
				statussprite = sprite_aistunned;
			}
			else if (currentAI == Aggressive) {
				//Draw the Aggressive AI symbol
				statussprite = sprite_aiaggressive;
			}
			else if (currentAI == Careful) {
				//Draw the Careful AI symbol
				statussprite = sprite_aicareful;
			}
			else if (currentAI == Random) {
				//Draw the Random AI symbol
				statussprite = sprite_airandom;
			}
			else {
				//Draw the Boss AI symbol
				statussprite = sprite_aiboss;
			}

			for (auto sprite : {enemysprite, weaponsprite, statussprite}) {
				sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
				window->draw(sprite);
			}
		}
	}
	if (player != nullptr) {
		sf::Sprite healthsprite;
		sf::Sprite lvlsprite;
		int playerxcoord = player->GetXCoordinate();
		int playerycoord = player->GetYCoordinate();
		int x = x_orig + (playerxcoord) * 64;
		int y = y_orig + (playerycoord) * 64;
		auto inventory = player->GetInventory();
		int playerhp = player->GetHealthPoints();
		if (playerhp == 0) {
			healthsprite = sprite_health0;
		}
		else if (playerhp == 1) {
			healthsprite = sprite_health1;
		}
		else if (playerhp == 2) {
			healthsprite = sprite_health2;
		}
		else if (playerhp == 3) {
			healthsprite = sprite_health3;
		}
		else if (playerhp == 4) {
			healthsprite = sprite_health4;
		}
		else {
			healthsprite = sprite_health5;
		}
		healthsprite.setPosition(972, 78);
		window->draw(healthsprite);

		if (currentlevel == 1) {
			lvlsprite = sprite_depth1;
		}
		else if (currentlevel == 2) {
			lvlsprite = sprite_depth2;
		}
		else if (currentlevel == 3) {
			lvlsprite = sprite_depth3;
		}
		else if (currentlevel == 4) {
			lvlsprite = sprite_depth4;
		}
		else if (currentlevel == 5) {
			lvlsprite = sprite_depth5;
		}
		else {
			lvlsprite = sprite_depth6;
		}
		lvlsprite.setPosition(1421, 78);
		window->draw(lvlsprite);

		sprite_playerbase.setPosition(x, y);
		window->draw(sprite_playerbase);
		
		for (int inventoryindex = 0; inventoryindex < 6; inventoryindex++) {
			sf::Sprite item;
			sf::Sprite attackdefense;
			sf::Sprite durability;
			sf::Sprite cooldown;
			sf::Sprite topcooldown;
			sf::Sprite durnumber;
			sf::Sprite attdefnumber;
			sf::Sprite cdnumber;
			sf::Sprite topcdnumber;
			if (!inventory[inventoryindex]->IsEmpty()) {
				auto invitem = inventory[inventoryindex]->GetItem();
				topcooldown = sprite_maxcoold;
				cooldown = sprite_coold;
				attackdefense = sprite_nonum;
				durnumber = sprite_nrinf;
				durability = sprite_dur;
				if (invitem->GetItemType() == ShieldItem) {
					attackdefense = sprite_defse;
					if (invitem->GetDefense() == 0) {
						attdefnumber = sprite_nrzero;
					}
					if (invitem->GetDefense() == 1) {
						attdefnumber = sprite_nrone;
					}
					if (invitem->GetDefense() == 2) {
						attdefnumber = sprite_nrtwo;
					}
					if (invitem->GetDefense() == 3) {
						attdefnumber = sprite_nrthree;
					}
				}
				if (invitem->GetItemType() == MeleeWeaponItem || invitem->GetItemType() == RangedWeaponItem) {
					attackdefense = sprite_att;
					if (invitem->GetDamage() == 0) {
						attdefnumber = sprite_nrzero;
					}
					if (invitem->GetDamage() == 1) {
						attdefnumber = sprite_nrone;
					}
					if (invitem->GetDamage() == 2) {
						attdefnumber = sprite_nrtwo;
					}
					if (invitem->GetDamage() == 3) {
						attdefnumber = sprite_nrthree;
					}
				}
				if (invitem->GetMaxCoolDown() == 1) {
					topcdnumber = sprite_nrone;
				}
				if (invitem->GetMaxCoolDown() == 2) {
					topcdnumber = sprite_nrtwo;
				}
				if (invitem->GetMaxCoolDown() == 3) {
					topcdnumber = sprite_nrthree;
				}
				if (invitem->GetMaxCoolDown() == 4) {
					topcdnumber = sprite_nrfour;
				}
				if (invitem->GetMaxCoolDown() == 5) {
					topcdnumber = sprite_nrfive;
				}
				if (invitem->GetMaxCoolDown() == 6) {
					topcdnumber = sprite_nrsix;
				}
				if (invitem->GetMaxCoolDown() == 7) {
					topcdnumber = sprite_nrseven;
				}
				if (invitem->GetMaxCoolDown() == 8) {
					topcdnumber = sprite_nreight;
				}
				if (invitem->GetCoolDown() == 0) {
					cdnumber = sprite_nrzero;
				}
				if (invitem->GetCoolDown() == 1) {
					cdnumber = sprite_nrone;
				}
				if (invitem->GetCoolDown() == 2) {
					cdnumber = sprite_nrtwo;
				}
				if (invitem->GetCoolDown() == 3) {
					cdnumber = sprite_nrthree;
				}
				if (invitem->GetCoolDown() == 4) {
					cdnumber = sprite_nrfour;
				}
				if (invitem->GetCoolDown() == 5) {
					cdnumber = sprite_nrfive;
				}
				if (invitem->GetCoolDown() == 6) {
					cdnumber = sprite_nrsix;
				}
				if (invitem->GetCoolDown() == 7) {
					cdnumber = sprite_nrseven;
				}
				if (invitem->GetCoolDown() == 8) {
					cdnumber = sprite_nreight;
				}

				if (invitem->GetName() == "Potion of healing") {
					item = sprite_healthpotion;
					topcooldown = sprite_nonum;
					cooldown = sprite_nonum;
					durnumber = sprite_nrone;
					attdefnumber = sprite_nonum;
					cdnumber = sprite_nonum;
					topcdnumber = sprite_nonum;

				}
				else if (invitem->GetName() == "Potion of stamina") {
					item = sprite_staminapotion;
					topcooldown = sprite_nonum;
					cooldown = sprite_nonum;
					durnumber = sprite_nrone;
					attdefnumber = sprite_nonum;
					cdnumber = sprite_nonum;
					topcdnumber = sprite_nonum;
				}
				else if (invitem->GetName() == "Javelin") {
					item = sprite_javelin;
				}
				else if (invitem->GetName() == "Bolas") {
					item = sprite_bolas;
				}
				else if (invitem->GetName() == "Sling") {
					item = sprite_sling;
				}
				else if (invitem->GetName() == "Round shield") {
					item = sprite_roundshield;
				}
				else if (invitem->GetName() == "Heater shield") {
					item = sprite_heatershield;
				}
				else if (invitem->GetName() == "Kite shield") {
					item = sprite_kiteshield;
				}
				else if (invitem->GetName() == "Tower shield") {
					item = sprite_towershield;
				}
				else if (invitem->GetName() == "Shortsword") {
					item = sprite_shortsword;
				}
				else if (invitem->GetName() == "Arming sword") {
					item = sprite_armingsword;
				}
				else if (invitem->GetName() == "Longsword") {
					item = sprite_longsword;
				}
				else if (invitem->GetName() == "Hatchet") {
					item = sprite_hatchet;
				}
				else if (invitem->GetName() == "Battleaxe") {
					item = sprite_battleaxe;
				}
				else if (invitem->GetName() == "Mace") {
					item = sprite_mace;
				}
				else {
					item = sprite_warhammer;
				}
				
				if (inventoryindex == 0) {
					// Top & player tile
					item.setPosition(1216, 322);
					sf::Sprite item2 = item;
					int x = x_orig + (player->GetXCoordinate())*64;
					int y = y_orig + (player->GetYCoordinate())*64;
					item2.setPosition(x, y);
					window->draw(item2);
					attdefnumber.setPosition(1157, 263);
					attackdefense.setPosition(1157,263);
					topcooldown.setPosition(1285, 391);
					topcdnumber.setPosition(1285, 391);
					cooldown.setPosition(1157, 391);
					cdnumber.setPosition(1157, 391);
					durability.setPosition(1285, 263);
					durnumber.setPosition(1285, 263);
				}
				else if (inventoryindex == 1) {
					// N
					item.setPosition(1216, 130);
					attdefnumber.setPosition(1157, 71);
					attackdefense.setPosition(1157, 71);
					topcooldown.setPosition(1285, 199);
					topcdnumber.setPosition(1285, 199);
					cooldown.setPosition(1157, 199);
					cdnumber.setPosition(1157, 199);
					durability.setPosition(1285, 71);
					durnumber.setPosition(1285, 71);
				}
				else if (inventoryindex == 2) {
					// E
					item.setPosition(1408, 322);
					attdefnumber.setPosition(1349, 263);
					attackdefense.setPosition(1349,263);
					topcooldown.setPosition(1477, 391);
					topcdnumber.setPosition(1477, 391);
					cooldown.setPosition(1349, 391);
					cdnumber.setPosition(1349, 391);
					durability.setPosition(1477, 263);
					durnumber.setPosition(1477, 263);
				}
				else if (inventoryindex == 3) {
					// W
					item.setPosition(1024, 322);
					attdefnumber.setPosition(965, 263);
					attackdefense.setPosition(965,263);
					topcooldown.setPosition(1093, 391);
					topcdnumber.setPosition(1093, 391);
					cooldown.setPosition(965, 391);
					cdnumber.setPosition(965, 391);
					durability.setPosition(1093, 263);
					durnumber.setPosition(1093, 263);
				}
				else if (inventoryindex == 4) {
					// S
					item.setPosition(1216, 514);
					attdefnumber.setPosition(1157, 455);
					attackdefense.setPosition(1157, 455);
					topcooldown.setPosition(1285, 583);
					topcdnumber.setPosition(1285, 583);
					cooldown.setPosition(1157, 583);
					cdnumber.setPosition(1157, 583);
					durability.setPosition(1285, 455);
					durnumber.setPosition(1285, 455);
				}
				else {
					// Bottom
					item.setPosition(1216, 706);
					attdefnumber.setPosition(1157, 647);
					attackdefense.setPosition(1157, 647);
					topcooldown.setPosition(1285, 775);
					topcdnumber.setPosition(1285, 775);
					cooldown.setPosition(1157, 775);
					cdnumber.setPosition(1157, 775);
					durability.setPosition(1285, 647);
					durnumber.setPosition(1285, 647);
				}
				// which index --> position --> sprite
			}
			window->draw(item);
			window->draw(attdefnumber);
			window->draw(attackdefense);
			window->draw(topcooldown);
			window->draw(topcdnumber);
			window->draw(cooldown);
			window->draw(cdnumber);
			window->draw(durability);
			window->draw(durnumber);

			if (combatongoing) {
				sf::Sprite sprite_diminvbutton(textures->diminvbutton);
				sprite_diminvbutton.setPosition(960, 514);
				window->draw(sprite_diminvbutton);
			}
		}
	}
	
	window->display();
}





// This is a helper function of the function 'InfoButtonMode'. The function is simply used for showing info cards of inventory items.
//################################################################################################################################################################################
void InventoryItemInfo(sf::RenderWindow* window, Textures* textures, Character* player, int invslot, Item* item) {
	if (invslot == -1 && item == nullptr) return;
	else if (invslot != -1) {
		std::vector<InventorySlot*> inventory = player->GetInventory();
		item = inventory[invslot]->GetItem();
	}
	
	if (item == nullptr) return;
	else {
		sf::Sprite info;
		if (item->GetName() == "Potion of healing")  info.setTexture(textures->healingpotioninfo);
		else if (item->GetName() == "Potion of stamina") info.setTexture(textures->staminapotioninfo);
		else if (item->GetName() == "Javelin") info.setTexture(textures->javelininfo);
		else if (item->GetName() == "Bolas") info.setTexture(textures->bolasinfo);
		else if (item->GetName() == "Sling") info.setTexture(textures->slinginfo);
		else if (item->GetName() == "Round shield") info.setTexture(textures->roundshieldinfo);
		else if (item->GetName() == "Heater shield") info.setTexture(textures->heatershieldinfo);
		else if (item->GetName() == "Kite shield") info.setTexture(textures->kiteshieldinfo);
		else if (item->GetName() == "Tower shield") info.setTexture(textures->towershieldinfo);
		else if (item->GetName() == "Shortsword") info.setTexture(textures->shortswordinfo);
		else if (item->GetName() == "Arming sword") info.setTexture(textures->armingswordinfo);
		else if (item->GetName() == "Longsword") info.setTexture(textures->longswordinfo);
		else if (item->GetName() == "Hatchet") info.setTexture(textures->hatchetinfo);
		else if (item->GetName() == "Battleaxe") info.setTexture(textures->battleaxeinfo);
		else if (item->GetName() == "Mace") info.setTexture(textures->maceinfo);
		else if (item->GetName() == "Warhammer") info.setTexture(textures->warhammerinfo);
		info.setPosition(188, 263);
		window->draw(info);
		window->display();

		while (true) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
				break;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) continue;
				break;
			}
		}
	}	
}





// This function is called when the player clicks the inspect button in the game mode. The functions allows drawing info cards of items and enemies when they are clicked.
//################################################################################################################################################################################
void InfoButtonMode(sf::RenderWindow* window, 
					Textures* textures, 
					Character* player, 
					sf::RectangleShape* infobutton, 
					sf::RectangleShape* inventory0, 
					sf::RectangleShape* inventory1, 
					sf::RectangleShape* inventory2, 
					sf::RectangleShape* inventory3, 
					sf::RectangleShape* inventory4, 
					sf::RectangleShape* inventory5,
					std::vector<Character*>* enemyvector,
					DungeonRoom* currentroom
					) 
{
	sf::Sprite infobtnview(textures->infobtnview);
	window->draw(infobtnview);
	window->display();

	while (true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
			sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
			if (mousePos.x < (gameboard_orig_x + 12*64) && mousePos.x > (gameboard_orig_x) && mousePos.y > gameboard_orig_y && mousePos.y < (900 - gameboard_orig_y)) {
				int actionpriority = 0;
				for (auto enemy : *enemyvector) {
					if (enemy != nullptr) {
						
						sf::Sprite actionpriosprite;
						if (actionpriority == 0) actionpriosprite.setTexture(textures->action0);
						else if (actionpriority == 1) actionpriosprite.setTexture(textures->action1);
						else if (actionpriority == 2) actionpriosprite.setTexture(textures->action2);
						else if (actionpriority == 3) actionpriosprite.setTexture(textures->action3);
						else if (actionpriority == 4) actionpriosprite.setTexture(textures->action4);
						actionpriosprite.setPosition(680, 359);

						int x = gameboard_orig_x + (enemy->GetXCoordinate())*64;
						int y = gameboard_orig_y + (enemy->GetYCoordinate())*64;
						sf::RectangleShape rect(sf::Vector2f(64, 64));
						rect.setPosition(x, y);
						if (rect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
							sf::Sprite info;
							if (dynamic_cast<Slime*>(enemy) != nullptr) info.setTexture(textures->slimeinfo);
							else if (dynamic_cast<LargeSlime*>(enemy) != nullptr) info.setTexture(textures->largeslimeinfo);
							else if (dynamic_cast<HugeSlime*>(enemy) != nullptr) info.setTexture(textures->hugeslimeinfo);
							else if (dynamic_cast<SmallSpider*>(enemy) != nullptr) info.setTexture(textures->smallspiderinfo);
							else if (dynamic_cast<Spider*>(enemy) != nullptr) info.setTexture(textures->spiderinfo);
							else if (dynamic_cast<BigSpider*>(enemy) != nullptr) info.setTexture(textures->hugespiderinfo);
							else if (dynamic_cast<SpitterSpider*>(enemy) != nullptr) info.setTexture(textures->spitterinfo);
							else if (dynamic_cast<Skeleton*>(enemy) != nullptr) info.setTexture(textures-> skeletoninfo);
							else if (dynamic_cast<SkeletonWarrior*>(enemy) != nullptr) info.setTexture(textures->skeletonwarriorinfo);
							else if (dynamic_cast<SkeletonKnight*>(enemy) != nullptr) info.setTexture(textures->skeletonknightinfo);
							else if (dynamic_cast<SkeletonArcher*>(enemy) != nullptr) info.setTexture(textures->skeletonarcherinfo);
							else if (dynamic_cast<SkeletonMage*>(enemy) != nullptr) info.setTexture(textures->skeletonmageinfo);
							else if (dynamic_cast<Lich*>(enemy) != nullptr) info.setTexture(textures->lichinfo);
							info.setPosition(188, 263);
							window->draw(info);
							sf::Sprite selectionrect(textures->selectionrectangle);
							if (enemy->GetCurrentActionIndex() == 0) {
								selectionrect.setPosition(196, 271);
							}
							if (enemy->GetCurrentActionIndex() == 1) {
								selectionrect.setPosition(268, 271);
							}
							if (enemy->GetCurrentActionIndex() == 2) {
								selectionrect.setPosition(340, 271);
							}
							if (enemy->GetCurrentActionIndex() == 3) {
								selectionrect.setPosition(412, 271);
							}
							window->draw(selectionrect);
							window->draw(actionpriosprite);
							window->display();

							while (true) {
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
									break;
								}
								else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
									while (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) continue;
									break;
								}
							}
						}
						actionpriority++;
					}
				}		
				int j_clicked = (int)(mousePos.y - gameboard_orig_y) / 64;
				int i_clicked = (int)(mousePos.x - gameboard_orig_x) / 64;
				auto tile = currentroom->GetDungeonTile(j_clicked, i_clicked);
				auto item = tile->GetItem();
				if (item != nullptr) {
					InventoryItemInfo(window, textures, player, -1, item);
					break;
				}
				break;
			}
			else {
				if (infobutton->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					break;
				}
				else if (inventory0->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					InventoryItemInfo(window, textures, player, 0, nullptr);
					break;
				}
				else if (inventory1->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					InventoryItemInfo(window, textures, player, 1, nullptr);
					break;
				}
				else if (inventory2->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					InventoryItemInfo(window, textures, player, 2, nullptr);
					break;
				}
				else if (inventory3->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					InventoryItemInfo(window, textures, player, 3, nullptr);
					break;
				}
				else if (inventory4->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					InventoryItemInfo(window, textures, player, 4, nullptr);
					break;
				}
				else if (inventory5->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					InventoryItemInfo(window, textures, player, 5, nullptr);
					break;
				}
				break;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) continue;
			break;
		}
	}
}





// This function draws a map of the current level. The function is called when the player clicks the map button in the game view.
//################################################################################################################################################################################
void PrintLevelMap(sf::RenderWindow* window, Character* player, DungeonLevel* level, DungeonRoom* currentroom, Textures* textures) {
    sf::Sprite mapbtnview(textures->mapbtnview);
	window->draw(mapbtnview);
	window->display();

    for (auto roomvec : level->GetRooms()) {
        for (auto room : roomvec) {
            int printinglocation_y = gameboard_orig_y + 192 + (room->GetIndexInLevel().first * 128);
            int printinglocation_x = gameboard_orig_x + 192 + (room->GetIndexInLevel().second * 128);
            if (!room->IsExplored()) {
                //Print unexplored room
				sf::Sprite sprite(textures->unexploredlocation);
				sprite.setPosition(printinglocation_x, printinglocation_y);
				window->draw(sprite);

				if (room->GetIndexInLevel() == currentroom->GetIndexInLevel()) {
					//Print player character
					sf::Sprite combatlocation(textures->combatlocation);
					combatlocation.setPosition(printinglocation_x, printinglocation_y);
					window->draw(combatlocation);
					sf::Sprite sprite(textures->playerlocation);
					sprite.setPosition(printinglocation_x, printinglocation_y);
					window->draw(sprite);
				}
            }
            else {
                if (room->GetRoomType() == _1DoorRoom) {
                    if (room->GetDoorOrientation() == North) {
                        //Print north facing 1DoorRoom
						sf::Sprite sprite(textures->_1doorroomnorth);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else if (room->GetDoorOrientation() == East) {
                        //Print east facing 1DoorRoom
						sf::Sprite sprite(textures->_1doorroomeast);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else if (room->GetDoorOrientation() == West) {
                        //Print west facing 1DoorRoom
						sf::Sprite sprite(textures->_1doorroomwest);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else {
                        //Print south facing 1DoorRoom
						sf::Sprite sprite(textures->_1doorroomsouth);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                }
                else if (room->GetRoomType() == _3DoorRoom) {
                    if (room->GetDoorOrientation() == North) {
                        //Print north facing 3DoorRoom
						sf::Sprite sprite(textures->_3doorroomnorth);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else if (room->GetDoorOrientation() == East) {
                        //Print east facing 3DoorRoom
						sf::Sprite sprite(textures->unexploredlocation);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else if (room->GetDoorOrientation() == West) {
                        //Print west facing 3DoorRoom
						sf::Sprite sprite(textures->_3doorroomwest);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else {
                        //Print south facing 3DoorRoom
						sf::Sprite sprite(textures->_3doorroomsouth);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                }
                else if (room->GetRoomType() == _2DoorRoomCorner || room->GetRoomType() == _2DoorRoomOpposite) {
                    if (room->GetDoorOrientation() == Horizontal) {
                        //Print a horizontal 2DoorRoomOpposite
						sf::Sprite sprite(textures->_2doorroomhorizontal);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else if (room->GetDoorOrientation() == Vertical) {
                        //Print a vertical 2DoorRoomOpposite
						sf::Sprite sprite(textures->_2doorroomvertical);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else if (room->GetDoorOrientation() == NorthWest) {
                        //Print NW 2DoorRoomCorner
						sf::Sprite sprite(textures->_2doorroomnw);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else if (room->GetDoorOrientation() == SouthWest) {
                        //Print SW 2DoorRoomCorner
						sf::Sprite sprite(textures->_2doorroomsw);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else if (room->GetDoorOrientation() == NorthEast) {
                        //Print NE 2DoorRoomCorner
						sf::Sprite sprite(textures->_2doorroomne);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                    else if (room->GetDoorOrientation() == SouthEast) {
                        //Print SE 2DoorRoomCorner
						sf::Sprite sprite(textures->_2doorroomse);
						sprite.setPosition(printinglocation_x, printinglocation_y);
						window->draw(sprite);
                    }
                }
                else {
                    //Print four door room
					sf::Sprite sprite(textures->_4doorroom);
					sprite.setPosition(printinglocation_x, printinglocation_y);
					window->draw(sprite);
                }
                bool hasitem = false;
                for (auto tilevec : room->GetAllTiles()) {
                    for (auto tile : tilevec) {
                        if (tile->GetItem() != nullptr) {
                            hasitem = true;
                            break;
                        }
                    }
                    if (hasitem) {
                        break;
                    }
                }
				if (room->GetIndexInLevel() == currentroom->GetIndexInLevel()) {
                    //Print player character
					sf::Sprite sprite(textures->playerlocation);
					sprite.setPosition(printinglocation_x, printinglocation_y);
					window->draw(sprite);
                }
                else if (hasitem) {
                    //Print loot sack
					sf::Sprite sprite(textures->lootlocation);
					sprite.setPosition(printinglocation_x, printinglocation_y);
					window->draw(sprite);
                }
            }
        }
    }
	window->display();

	while (true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
			break;
		}
	}
}





// This function is called when the player clicks the inventory button. The function allows swapping contents of two inventory slots or dropping an item.
//################################################################################################################################################################################
void InventoryButtonAct(sf::RenderWindow* window, 
						Character* player, 
						DungeonRoom* currentroom, 
						sf::RectangleShape* infobutton, 
						sf::RectangleShape* inventory0, 
						sf::RectangleShape* inventory1, 
						sf::RectangleShape* inventory2, 
						sf::RectangleShape* inventory3, 
						sf::RectangleShape* inventory4, 
						sf::RectangleShape* inventory5,
						Textures* textures) 
{
	sf::Sprite invbtnview(textures->invbtnview);
	window->draw(invbtnview);
	window->display();

	std::vector<InventorySlot*> inventory = player->GetInventory();
	sf::RectangleShape gameboard(sf::Vector2f(768, 768));
	gameboard.setPosition(gameboard_orig_x, gameboard_orig_y);

	InventorySlot* slot1 = nullptr;
	InventorySlot* slot2 = nullptr;
	Item* item1 = nullptr;
	Item* item2 = nullptr;

	while (true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
			
			sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
			if (inventory0->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				if (inventory[0] == nullptr) return;
				else {
					slot1 = inventory[0];
					item1 = inventory[0]->GetItem();
					break;
				}
			}
			else if (inventory1->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				if (inventory[1] == nullptr) return;
				else {
					slot1 = inventory[1];
					item1 = inventory[1]->GetItem();
					break;
				}
			}
			else if (inventory2->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				if (inventory[2] == nullptr) return;
				else {
					slot1 = inventory[2];
					item1 = inventory[2]->GetItem();
					break;
				}
			}
			else if (inventory3->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				if (inventory[3] == nullptr) return;
				else {
					slot1 = inventory[3];
					item1 = inventory[3]->GetItem();
					break;
				}
			}
			else if (inventory4->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				if (inventory[4] == nullptr) return;
				else {
					slot1 = inventory[4];
					item1 = inventory[4]->GetItem();
					break;
				}
			}
			else if (inventory5->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				if (inventory[5] == nullptr) return;
				else {
					slot1 = inventory[5];
					item1 = inventory[5]->GetItem();
					break;
				}
			}
			else return;
		}
	}
	while (true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
			
			sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
			if (inventory0->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				slot2 = inventory[0];
				item2 = slot2->GetItem();
				break;
			}
			else if (inventory1->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				slot2 = inventory[1];
				item2 = slot2->GetItem();
				break;
			}
			else if (inventory2->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				slot2 = inventory[2];
				item2 = slot2->GetItem();
				break;
			}
			else if (inventory3->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				slot2 = inventory[3];
				item2 = slot2->GetItem();
				break;
			}
			else if (inventory4->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				slot2 = inventory[4];
				item2 = slot2->GetItem();
				break;
			}
			else if (inventory5->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				slot2 = inventory[5];
				item2 = slot2->GetItem();
				break;
			}
			else if (gameboard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				DungeonTile* currenttile = player->GetCurrentTile();
				if (currenttile->GetItem() == nullptr) {
					currenttile->PlaceItem(item1);
					slot1->DropItem();
				}
				return;
			}
		}
	}
	slot1->Clear();
	slot2->Clear();
	slot1->SwapAdd(item2);
	slot2->SwapAdd(item1);
}





//This function holds a game loop for one dungeon.
//################################################################################################################################################################################
bool Level(sf::RenderWindow* window, DungeonLevel level, int depth, Character* player, std::vector<std::vector<Item*>> lootvector, Textures* textures) {
	std::vector<std::vector<DungeonRoom*>> rooms = level.GetRooms();
	DungeonRoom* currentroom = rooms[level.GetStartPos().first][level.GetStartPos().second];
    bool lootgiven = false;
	bool lastroominlevelset = false;
    int randomnumberx = rand() % (level.GetSideLength()); //Random number for loot placement
    int randomnumbery = rand() % (level.GetSideLength()); //Random number for loot placement
    for (auto loot : lootvector[depth - 1]) { //Give random rooms loot.
        while (!lootgiven) {
            randomnumberx = rand() % (level.GetSideLength());
            randomnumbery = rand() % (level.GetSideLength());
            if (rooms[randomnumberx][randomnumbery]->GetIndexInLevel() != currentroom->GetIndexInLevel() && rooms[randomnumberx][randomnumbery]->GetLootItem() == nullptr) {
                rooms[randomnumberx][randomnumbery]->GiveLoot(loot);
                lootgiven = true;
            }
        }
        lootgiven = false;
    }
    int exploredroomscounter = 1;
    int levelroomcount = level.GetSideLength() * level.GetSideLength();
    int levelycoord = level.GetStartPos().first;
    int levelxcoord = level.GetStartPos().second;
    bool loopbreaker = false;
    bool combat = false;
    int enemiesalive = 0;
    std::vector<Character*> enemyvector = {nullptr};
    for (auto tilevec : currentroom->GetAllTiles()) {
        for (auto tile : tilevec) {
            if (tile->GetTileType() == Entrance) {
                player->MoveToTile(tile);
                loopbreaker = true;
                break;
            }
        }
        if (loopbreaker) {
            break;
        }
    }
    
	// Define all game view buttons
	sf::RectangleShape end_game_button(sf::Vector2f(115, 115));
    end_game_button.setPosition(1415, 712);

	sf::RectangleShape inventorybutton(sf::Vector2f(115, 115));
    inventorybutton.setPosition(966, 519);

	sf::RectangleShape mapbutton(sf::Vector2f(115, 115));
    mapbutton.setPosition(1414, 519);

	sf::RectangleShape infobutton(sf::Vector2f(115, 115));
    infobutton.setPosition(966, 712);

	sf::RectangleShape inventory0(sf::Vector2f(64, 64));
	inventory0.setPosition(1217, 322);

	sf::RectangleShape inventory1(sf::Vector2f(64, 64));
	inventory1.setPosition(1217, 131);

	sf::RectangleShape inventory2(sf::Vector2f(64, 64));
	inventory2.setPosition(1407, 322);

	sf::RectangleShape inventory3(sf::Vector2f(64, 64));
	inventory3.setPosition(1024, 322);

	sf::RectangleShape inventory4(sf::Vector2f(64, 64));
	inventory4.setPosition(1217, 513);

	sf::RectangleShape inventory5(sf::Vector2f(64, 64));
	inventory5.setPosition(1217, 706);

	sf::ConvexShape north;
    north.setPointCount(3);
    north.setPoint(0, sf::Vector2f(448, 13));
    north.setPoint(1, sf::Vector2f(482, 50));
	north.setPoint(2, sf::Vector2f(414, 50));

	sf::ConvexShape west;
    west.setPointCount(3);
    west.setPoint(0, sf::Vector2f(12, 448));
    west.setPoint(1, sf::Vector2f(48, 414));
	west.setPoint(2, sf::Vector2f(48, 482));

	sf::ConvexShape south;
    south.setPointCount(3);
    south.setPoint(0, sf::Vector2f(448, 886));
    south.setPoint(1, sf::Vector2f(412, 847));
	south.setPoint(2, sf::Vector2f(482, 849));

	sf::ConvexShape east;
    east.setPointCount(3);
	east.setPoint(0, sf::Vector2f(884, 448));
    east.setPoint(1, sf::Vector2f(848, 484));
	east.setPoint(2, sf::Vector2f(846, 414));

	// Game loop
	bool run = true;
	while (run) {
		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat, textures);
		// Player input loop
		int validmove = -1;
		while (validmove < 0) {
			if (player->GetCurrentTile()->GetTileNeighbor("N") != nullptr && player->GetCurrentTile()->GetTileNeighbor("E") != nullptr&& player->GetCurrentTile()->GetTileNeighbor("W") != nullptr && player->GetCurrentTile()->GetTileNeighbor("S") != nullptr) {
				if (!(player->GetCurrentTile()->GetTileNeighbor("N")->IsPassable()) && !(player->GetCurrentTile()->GetTileNeighbor("E")->IsPassable()) && !(player->GetCurrentTile()->GetTileNeighbor("W")->IsPassable()) && !(player->GetCurrentTile()->GetTileNeighbor("S")->IsPassable())) {
					validmove = 0;
					continue;
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;

				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
				if (end_game_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					return false;
				}
				else if (inventorybutton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && !combat) {
					InventoryButtonAct(window, player, currentroom, &inventorybutton, &inventory0, &inventory1, &inventory2, &inventory3, &inventory4, &inventory5, textures);
					RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat, textures);
				}
				else if (mapbutton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					PrintLevelMap(window, player, &level, currentroom, textures);
					RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat, textures);
				}
				else if (infobutton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					InfoButtonMode(window, textures, player, &infobutton, &inventory0, &inventory1, &inventory2, &inventory3, &inventory4, &inventory5, &enemyvector, currentroom);
					RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat, textures);
				}
				else if (north.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					validmove = player->MoveToDirection("N");
				}
				else if (east.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					validmove = player->MoveToDirection("E");
				}
				else if (south.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					validmove = player->MoveToDirection("S");
				}
				else if (west.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					validmove = player->MoveToDirection("W");				
				}
			}

			if (sf::Keyboard::isKeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) continue;
					validmove = player->MoveToDirection("N");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) continue;
					validmove = player->MoveToDirection("W");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) continue;
					validmove = player->MoveToDirection("S");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) continue;
					validmove = player->MoveToDirection("E");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) continue;
					validmove = player->MoveToDirection("N");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) continue;
					validmove = player->MoveToDirection("W");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) continue;
					validmove = player->MoveToDirection("S");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) continue;
					validmove = player->MoveToDirection("E");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) continue;
					InfoButtonMode(window, textures, player, &infobutton, &inventory0, &inventory1, &inventory2, &inventory3, &inventory4, &inventory5, &enemyvector, currentroom);
					RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat, textures);
				}
			}
		}

		//After moving, check if the player is on a door tile. This will move the player to the next room in that direction.
		
		int playerx = player->GetXCoordinate();
		int playery = player->GetYCoordinate();

		if ((playerx == 0 && playery == 5) || (playerx == 0 && playery == 6) ||
		(playerx == 11 && playery == 5) || (playerx == 11 && playery == 6) ||
		(playerx == 5 && playery == 11) || (playerx == 6 && playery == 11) ||
		(playerx == 5 && playery == 0) || (playerx == 6 && playery == 0)) {
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[5][0]) {
				player->MoveToTile(currentroom->GetNeighbors()[2]->GetAllTiles()[5][10]);
				currentroom = currentroom->GetNeighbors()[2];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[6][0]) {
				player->MoveToTile(currentroom->GetNeighbors()[2]->GetAllTiles()[6][10]);
				currentroom = currentroom->GetNeighbors()[2];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[5][11]) {
				player->MoveToTile(currentroom->GetNeighbors()[1]->GetAllTiles()[5][1]);
				currentroom = currentroom->GetNeighbors()[1];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[6][11]) {
				player->MoveToTile(currentroom->GetNeighbors()[1]->GetAllTiles()[6][1]);
				currentroom = currentroom->GetNeighbors()[1];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[11][5]) {
				player->MoveToTile(currentroom->GetNeighbors()[3]->GetAllTiles()[1][5]);
				currentroom = currentroom->GetNeighbors()[3];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[11][6]) {
				player->MoveToTile(currentroom->GetNeighbors()[3]->GetAllTiles()[1][6]);
				currentroom = currentroom->GetNeighbors()[3];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[0][5]) {
				player->MoveToTile(currentroom->GetNeighbors()[0]->GetAllTiles()[10][5]);
				currentroom = currentroom->GetNeighbors()[0];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[0][6]) {
				player->MoveToTile(currentroom->GetNeighbors()[0]->GetAllTiles()[10][6]);
				currentroom = currentroom->GetNeighbors()[0];
			}
		
			if (!currentroom->IsExplored()) {
				exploredroomscounter++;
				enemyvector.clear();
				enemyvector = GenerateRoomEnemies(depth);
				if (exploredroomscounter == levelroomcount && !lastroominlevelset) {
					currentroom->SetLastRoomInLevel();
					lastroominlevelset = true;
				}

				if (depth == 6 && currentroom->IsLastRoomInLevel()) {
					enemyvector = {new SkeletonWarrior(nullptr), new SkeletonKnight(nullptr), new Lich(nullptr), new SkeletonKnight(nullptr), new SkeletonWarrior(nullptr)};
					//BOSS
				}

				currentroom->SpawnEnemies(enemyvector); //Enemies may be spawned and doors close if there are enemies present.
				for (auto enemyinvec : enemyvector) {
					if (enemyinvec != nullptr) {
						combat = true; //Combat value is set to true.
						enemiesalive++;
					}
				}
			}
			continue;
		}

		int damage = 0;
		if (validmove == 10) {
			for (auto enemy1 : enemyvector) {
				damage = 0;
				if (enemy1 != nullptr) {
					if (!enemy1->DistanceToCharacterLargerThanThree(player)) {
						damage = player->GetInventory()[0]->UseItem();
						if (player->GetInventory()[0]->GetItem()->IsStunning() && player->GetInventory()[0]->GetItem()->GetCoolDown() == player->GetInventory()[0]->GetItem()->GetMaxCoolDown()) {
							enemy1->Stun(2);
							for (auto enemy2 : enemyvector) {
								if (enemy2 != nullptr && enemy2 != enemy1) {
									if (enemy1->NextToCharacter(enemy2)) {
										enemy2->Stun(3);
									}
								}
							}
						}
						if (player->GetInventory()[0]->GetItem()->IsThrown() && damage > 0) {
							if (enemy1->GetCurrentTile()->GetItem() == nullptr) {
								enemy1->GetCurrentTile()->PlaceItem(player->GetInventory()[0]->GetItem());
								player->GetInventory()[0]->DropItem();
							}
							else {
								if (enemy1->GetCurrentTile()->GetTileNeighbor("N")->GetItem() == nullptr && enemy1->GetCurrentTile()->GetTileNeighbor("N")->GetTileType() != Wall && enemy1->GetCurrentTile()->GetTileNeighbor("N")->GetTileType() != Pit && enemy1->GetCurrentTile()->GetTileNeighbor("N")->GetTileType() != Door) {
									enemy1->GetCurrentTile()->GetTileNeighbor("N")->PlaceItem(player->GetInventory()[0]->GetItem());
									player->GetInventory()[0]->DropItem();
								}
								else if (enemy1->GetCurrentTile()->GetTileNeighbor("E")->GetItem() == nullptr && enemy1->GetCurrentTile()->GetTileNeighbor("E")->GetTileType() != Wall && enemy1->GetCurrentTile()->GetTileNeighbor("E")->GetTileType() != Pit && enemy1->GetCurrentTile()->GetTileNeighbor("E")->GetTileType() != Door) {
									enemy1->GetCurrentTile()->GetTileNeighbor("E")->PlaceItem(player->GetInventory()[0]->GetItem());
									player->GetInventory()[0]->DropItem();
								}
								else if (enemy1->GetCurrentTile()->GetTileNeighbor("W")->GetItem() == nullptr && enemy1->GetCurrentTile()->GetTileNeighbor("W")->GetTileType() != Wall && enemy1->GetCurrentTile()->GetTileNeighbor("W")->GetTileType() != Pit && enemy1->GetCurrentTile()->GetTileNeighbor("W")->GetTileType() != Door) {
									enemy1->GetCurrentTile()->GetTileNeighbor("W")->PlaceItem(player->GetInventory()[0]->GetItem());
									player->GetInventory()[0]->DropItem();
								}
								else if (enemy1->GetCurrentTile()->GetTileNeighbor("S")->GetItem() == nullptr && enemy1->GetCurrentTile()->GetTileNeighbor("S")->GetTileType() != Wall && enemy1->GetCurrentTile()->GetTileNeighbor("S")->GetTileType() != Pit && enemy1->GetCurrentTile()->GetTileNeighbor("S")->GetTileType() != Door) {
									enemy1->GetCurrentTile()->GetTileNeighbor("S")->PlaceItem(player->GetInventory()[0]->GetItem());
									player->GetInventory()[0]->DropItem();
								}
							}
						}
						if (damage >= 12) {
							damage = 0;
						}
						enemy1->TakeDamage(damage);
						break;
					}
				}
			}
		}

		if (validmove == 11) {
			if (player->GetCurrentTile()->GetTileNeighbor("N") != nullptr && player->GetCurrentTile()->GetTileNeighbor("E") != nullptr && player->GetCurrentTile()->GetTileNeighbor("W") != nullptr && player->GetCurrentTile()->GetTileNeighbor("S") != nullptr) {
				if (player->GetCurrentTile()->GetTileNeighbor("N")->HasCharacter() || player->GetCurrentTile()->GetTileNeighbor("E")->HasCharacter() || player->GetCurrentTile()->GetTileNeighbor("W")->HasCharacter() || player->GetCurrentTile()->GetTileNeighbor("S")->HasCharacter()) {
					damage = player->GetInventory()[0]->UseItem();
					if (player->GetInventory()[0]->GetItem()->TargetSeveralEnemies()) {
						for (auto enemy3 : enemyvector) {
							if (enemy3 != nullptr) {
								if (enemy3->NextToCharacter(player)) {
									enemy3->TakeDamage(damage);
								}
							}
						}
					}
					else {
						for (auto enemy4 : enemyvector) {
							if (enemy4 != nullptr) {
								if (enemy4->NextToCharacter(player)) {
									if (player->GetInventory()[0]->GetItem()->IsStunning() && player->GetInventory()[0]->GetItem()->GetCoolDown() == player->GetInventory()[0]->GetItem()->GetMaxCoolDown()) {
										enemy4->Stun(2);
										for (auto enemy5 : enemyvector) {
											if (enemy5 != nullptr && enemy5 != enemy4) {
												if (enemy4->NextToCharacter(enemy5)) {
													enemy5->Stun(3);
												}
											}
										}
									}
									enemy4->TakeDamage(damage);
									break;
								}
							}
						}
					}
				}
			}
		}

		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat, textures);

		if (player->GetCurrentTile()->GetTileType() == Exit && player->GetCurrentTile()->IsOpen() && currentroom->IsLastRoomInLevel()) {
			return true;
		}

		if (enemiesalive == 0) {
			currentroom->OpenDoors();
			combat = false;
		}

		if (exploredroomscounter == levelroomcount && enemiesalive == 0 && player->GetCurrentTile()->GetTileType() != Exit) {
			for (auto dungeontilevec : currentroom->GetAllTiles()) {
				for (auto exittile : dungeontilevec) {
					if (exittile->GetTileType() == Exit) {
						exittile->Open();
					}
				}
			}
		} //Open level exit

		for (auto traptilevec : currentroom->GetAllTiles()) {
			for (auto trap : traptilevec) {
				trap->ProceedTrapState();
			}
		}

		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat, textures);

		for (auto enemy : enemyvector) {
			if (enemy != nullptr) {
				if (enemy->GetHealthPoints() > 0) {
					enemy->TakeAction(player, 1);
				}
			}
		}
		
		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat, textures);

		for (int enemyindex = 0; enemyindex < enemyvector.size(); enemyindex++) {
			if (enemyvector[enemyindex] != nullptr) {
				if (enemyvector[enemyindex]->GetHealthPoints() <= 0) {
					enemyvector[enemyindex] = nullptr;
					enemiesalive--;
				}
			}
		}
		if (player->GetHealthPoints() <= 0) {
			//GAME OVER
			sf::Sprite gameover(textures->gameover);
			window->draw(gameover);
			window->display();
			
			while (true) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
					
					sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
					if (end_game_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						return false;
					}
				}
			}
			return false;
		}

		if (!combat && depth == 6 && currentroom->IsLastRoomInLevel()) {
			//GAME WON
			sf::Sprite gamewon(textures->gamewon);
			window->draw(gamewon);
			window->display();
			
			while (true) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
					
					sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
					if (end_game_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						return false;
					}
				}
			}
			return false;
		}
		
		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat, textures);
	}
	return false;
}





// This function loops through six levels of one game instance. Returns when player clears through all the levels, dies or stops the game.
//################################################################################################################################################################################
void LevelLoop(sf::RenderWindow* window, Textures* textures) {
	srand(time(NULL));
    auto const levels = {1, 2, 3, 4, 5, 6};
    int sidelength;
    std::vector<std::vector<Item*>> lootvector = CreateLoot();
    Character* player = new Player(nullptr);
    
    for (int i : levels) {
        if (i == 1) sidelength = 2;
        else sidelength = 3;

		DungeonLevel level(sidelength);
		bool keeprunning = Level(window, level, i, player, lootvector, textures);
		if (!keeprunning) return;
	}
}





// Show the instructions and credits view.
//################################################################################################################################################################################
void ShowInstructions(sf::RenderWindow* window, Textures* textures) {
	sf::Sprite insructions(textures->instructions);
	sf::Sprite credits(textures->credits);
	window->draw(insructions);
	window->display();

	while (true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
			
			window->draw(credits);
			window->display();

			while (true) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;
					break;
				}
			}
			break;
		}
	}
}





// This is a main function that creates a renderwindow and holds an application loop.
//################################################################################################################################################################################
int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Dungeon Crawler", sf::Style::Close);
	sf::RenderWindow* w;
	w = &window;

	auto desktop = sf::VideoMode::getDesktopMode();
	sf::Vector2i posvec(desktop.width/2 - window.getSize().x/2, desktop.height/2 - window.getSize().y/2);
	window.setPosition(posvec);

	Textures* textures = new Textures;

    // Start menu items
    sf::Texture menu_texture;
    menu_texture.loadFromFile("../src/Graphics/GUI_Sprites/MainMenu.png");
    sf::Sprite main_menu(menu_texture);

	sf::ConvexShape quit_button;
	quit_button.setPointCount(4);
    quit_button.setPoint(0, sf::Vector2f(545, 337));
    quit_button.setPoint(1, sf::Vector2f(731, 429));
    quit_button.setPoint(2, sf::Vector2f(713, 659));
    quit_button.setPoint(3, sf::Vector2f(539, 583));

    sf::ConvexShape start_button;
    start_button.setPointCount(4);
    start_button.setPoint(0, sf::Vector2f(1081, 315));
    start_button.setPoint(1, sf::Vector2f(1071, 581));
    start_button.setPoint(2, sf::Vector2f(853, 661));
    start_button.setPoint(3, sf::Vector2f(851, 421));

    sf::ConvexShape instructions_button;
    instructions_button.setPointCount(4);
    instructions_button.setPoint(0, sf::Vector2f(797, 119));
    instructions_button.setPoint(1, sf::Vector2f(987, 217));
    instructions_button.setPoint(2, sf::Vector2f(805, 343));
    instructions_button.setPoint(3, sf::Vector2f(615, 245));

   	window.clear();
	window.draw(main_menu);
	window.display();

	enum AppState {
		MainMenu,
		Game,
		Instructions
	};

	int i = 0;

	AppState state = MainMenu;

	// The main application loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && state == MainMenu) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				
				if (quit_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					window.close();
				}
				else if (start_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					state = Game;
					LevelLoop(w, textures);
					window.clear();
					window.draw(main_menu);
					window.display();
				}
				else if (instructions_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					state = Instructions;
					ShowInstructions(w, textures);
					window.clear();
					window.draw(main_menu);
					window.display();
				}
			}
			else if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && state == Instructions) {
				if (i < 1) i++;
				else {
					state = MainMenu;
					i = 0;
				}
			}
			else if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && state == Game) {
				state = MainMenu;
			}
		}
	}
    return 0;
}