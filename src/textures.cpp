#include <SFML/Graphics.hpp>


/* 
This class is solely a container for all the textures. Whenever a new game instance begins, this class is instantiated.
The created object is passed as a pointer and can be called whenever textures are needed. The texture container is 
held in RAM and textures are fetched from there instead of loading them from file every time they are needed. This allows 
us to avoid disk I/O when rendering screens and, thus, makes the game run faster.
*/

class Textures {
public:
	Textures() {
		game_view.loadFromFile("../src/Graphics/GUI_Sprites/UI_PIC.png");
		door_closed.loadFromFile("../src/Graphics/TileSprites/DoorClosed.png");
		floor.loadFromFile("../src/Graphics/TileSprites/Floor.png");
		levelexitclosed.loadFromFile("../src/Graphics/TileSprites/LevelExitClosed.png");
		levelexitopen.loadFromFile("../src/Graphics/TileSprites/LevelExitOpen.png");
		pit.loadFromFile("../src/Graphics/TileSprites/Pit.png");
		trap1.loadFromFile("../src/Graphics/TileSprites/Trap1.png");
		trap2.loadFromFile("../src/Graphics/TileSprites/Trap2.png");
		trap3.loadFromFile("../src/Graphics/TileSprites/Trap3.png");
		wall.loadFromFile("../src/Graphics/TileSprites/Wall.png");
		healthpotion.loadFromFile("../src/Graphics/ItemSprites/HealthPotion.png");
		staminapotion.loadFromFile("../src/Graphics/ItemSprites/StaminaPotion.png");
		shortsword.loadFromFile("../src/Graphics/ItemSprites/ShortSword.png");
		armingsword.loadFromFile("../src/Graphics/ItemSprites/ArmingSword.png");
		longsword.loadFromFile("../src/Graphics/ItemSprites/LongSword.png");
		hatchet.loadFromFile("../src/Graphics/ItemSprites/Hatchet.png");
		battleaxe.loadFromFile("../src/Graphics/ItemSprites/BattleAxe.png");
		mace.loadFromFile("../src/Graphics/ItemSprites/Mace.png");
		warhammer.loadFromFile("../src/Graphics/ItemSprites/WarHammer.png");
		roundshield.loadFromFile("../src/Graphics/ItemSprites/RoundShield.png");
		heatershield.loadFromFile("../src/Graphics/ItemSprites/HeaterShield.png");
		kiteshield.loadFromFile("../src/Graphics/ItemSprites/KiteShield.png");
		towershield.loadFromFile("../src/Graphics/ItemSprites/TowerShield.png");
		sling.loadFromFile("../src/Graphics/ItemSprites/Sling.png");
		bolas.loadFromFile("../src/Graphics/ItemSprites/Bolas.png");
		javelin.loadFromFile("../src/Graphics/ItemSprites/Javelin.png");
		aiaggressive.loadFromFile("../src/Graphics/CharacterSprites/AI_Aggressive.png");
		aicareful.loadFromFile("../src/Graphics/CharacterSprites/AI_Careful.png");
		aiboss.loadFromFile("../src/Graphics/CharacterSprites/AI_Boss.png");
		airandom.loadFromFile("../src/Graphics/CharacterSprites/AI_Random.png");
		aistunned.loadFromFile("../src/Graphics/CharacterSprites/AI_Stunned.png");
		defense1.loadFromFile("../src/Graphics/CharacterSprites/Defense1.png");
		defense2.loadFromFile("../src/Graphics/CharacterSprites/Defense2.png");
		defense3.loadFromFile("../src/Graphics/CharacterSprites/Defense3.png");
		melee1.loadFromFile("../src/Graphics/CharacterSprites/Melee1.png");
		melee2.loadFromFile("../src/Graphics/CharacterSprites/Melee2.png");
		melee3.loadFromFile("../src/Graphics/CharacterSprites/Melee3.png");
		ranged1.loadFromFile("../src/Graphics/CharacterSprites/Ranged1.png");
		ranged2.loadFromFile("../src/Graphics/CharacterSprites/Ranged2.png");
		ranged3.loadFromFile("../src/Graphics/CharacterSprites/Ranged3.png");
		emptyaction.loadFromFile("../src/Graphics/CharacterSprites/Empty.png");
		enemybase.loadFromFile("../src/Graphics/CharacterSprites/Enemy.png");
		playerbase.loadFromFile("../src/Graphics/CharacterSprites/Player.png");
		depth1.loadFromFile("../src/Graphics/GUI_Sprites/Depth1.png");
		depth2.loadFromFile("../src/Graphics/GUI_Sprites/Depth2.png");
		depth3.loadFromFile("../src/Graphics/GUI_Sprites/Depth3.png");
		depth4.loadFromFile("../src/Graphics/GUI_Sprites/Depth4.png");
		depth5.loadFromFile("../src/Graphics/GUI_Sprites/Depth5.png");
		depth6.loadFromFile("../src/Graphics/GUI_Sprites/Depth6.png");
		health0.loadFromFile("../src/Graphics/GUI_Sprites/Health0.png");
		health1.loadFromFile("../src/Graphics/GUI_Sprites/Health1.png");
		health2.loadFromFile("../src/Graphics/GUI_Sprites/Health2.png");
		health3.loadFromFile("../src/Graphics/GUI_Sprites/Health3.png");
		health4.loadFromFile("../src/Graphics/GUI_Sprites/Health4.png");
		health5.loadFromFile("../src/Graphics/GUI_Sprites/Health5.png");
		nrzero.loadFromFile("../src/Graphics/GUI_Sprites/0.png");
		nrone.loadFromFile("../src/Graphics/GUI_Sprites/1.png");
		nrtwo.loadFromFile("../src/Graphics/GUI_Sprites/2.png");
		nrthree.loadFromFile("../src/Graphics/GUI_Sprites/3.png");
		nrfour.loadFromFile("../src/Graphics/GUI_Sprites/4.png");
		nrfive.loadFromFile("../src/Graphics/GUI_Sprites/5.png");
		nrsix.loadFromFile("../src/Graphics/GUI_Sprites/6.png");
		nrseven.loadFromFile("../src/Graphics/GUI_Sprites/7.png");
		nreight.loadFromFile("../src/Graphics/GUI_Sprites/8.png");
		nrinf.loadFromFile("../src/Graphics/GUI_Sprites/Inf.png");
		att.loadFromFile("../src/Graphics/GUI_Sprites/Att.png");
		defse.loadFromFile("../src/Graphics/GUI_Sprites/Def.png");
		coold.loadFromFile("../src/Graphics/GUI_Sprites/CD.png");
		maxcoold.loadFromFile("../src/Graphics/GUI_Sprites/TCD.png");
		dur.loadFromFile("../src/Graphics/GUI_Sprites/Dur.png");
		nonum.loadFromFile("../src/Graphics/GUI_Sprites/NoNum.png");
		infobtnview.loadFromFile("../src/Graphics/GUI_Sprites/infobtnview.png");
		diminvbutton.loadFromFile("../src/Graphics/GUI_Sprites/DimInvButton.png");
		hugeslimeinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/HugeSlimeInfo.png");
		hugespiderinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/HugeSpiderInfo.png");
		largeslimeinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/LargeSlimeInfo.png");
		lichinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/LichInfo.png");
		selectionrectangle.loadFromFile("../src/Graphics/CharacterInfoSprites/SelectionRectangle.png");
		skeletonarcherinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonArcherInfo.png");
		skeletonarcherinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonArcherInfo.png");
		skeletoninfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonInfo.png");
		skeletonknightinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonKnightInfo.png");
		skeletonmageinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonMageInfo.png");
		skeletonwarriorinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SkeletonWarriorInfo.png");
		slimeinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SlimeInfo.png");
		spiderinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/LargeSpiderInfo.png");
		smallspiderinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SmallSpiderInfo.png");
		spitterinfo.loadFromFile("../src/Graphics/CharacterInfoSprites/SpitterSpiderInfo.png");
		armingswordinfo.loadFromFile("../src/Graphics/ItemInfoSprites/ArmingSwordInfo.png");
		battleaxeinfo.loadFromFile("../src/Graphics/ItemInfoSprites/BattleAxeInfo.png");
		bolasinfo.loadFromFile("../src/Graphics/ItemInfoSprites/BolasInfo.png");
		hatchetinfo.loadFromFile("../src/Graphics/ItemInfoSprites/HatchetInfo.png");
		healingpotioninfo.loadFromFile("../src/Graphics/ItemInfoSprites/HealingPotionInfo.png");
		heatershieldinfo.loadFromFile("../src/Graphics/ItemInfoSprites/HeaterShieldInfo.png");
		javelininfo.loadFromFile("../src/Graphics/ItemInfoSprites/JavelinInfo.png");
		kiteshieldinfo.loadFromFile("../src/Graphics/ItemInfoSprites/KiteShieldInfo.png");
		longswordinfo.loadFromFile("../src/Graphics/ItemInfoSprites/LongSwordInfo.png");
		maceinfo.loadFromFile("../src/Graphics/ItemInfoSprites/MaceInfo.png");
		roundshieldinfo.loadFromFile("../src/Graphics/ItemInfoSprites/RoundShieldInfo.png");
		shortswordinfo.loadFromFile("../src/Graphics/ItemInfoSprites/ShortSwordInfo.png");
		slinginfo.loadFromFile("../src/Graphics/ItemInfoSprites/SlingInfo.png");
		staminapotioninfo.loadFromFile("../src/Graphics/ItemInfoSprites/StaminaPotionInfo.png");
		towershieldinfo.loadFromFile("../src/Graphics/ItemInfoSprites/TowerShieldInfo.png");
		warhammerinfo.loadFromFile("../src/Graphics/ItemInfoSprites/WarHammerInfo.png");
		instructions.loadFromFile("../src/Graphics/GUI_Sprites/Instructions.png");
		gameover.loadFromFile("../src/Graphics/GUI_Sprites/GameOver.png");
		gamewon.loadFromFile("../src/Graphics/GUI_Sprites/GameWon.png");
		mapbtnview.loadFromFile("../src/Graphics/GUI_Sprites/mapbtnview.png");
		_1doorroomnorth.loadFromFile("../src/Graphics/MapSprites/1DoorRoomNorth.png");
		_1doorroomeast.loadFromFile("../src/Graphics/MapSprites/1DoorRoomEast.png");
		_1doorroomwest.loadFromFile("../src/Graphics/MapSprites/1DoorRoomWest.png");
		_1doorroomsouth.loadFromFile("../src/Graphics/MapSprites/1DoorRoomSouth.png");
		_2doorroomvertical.loadFromFile("../src/Graphics/MapSprites/2DoorRoomOppositeVertical.png");
		_2doorroomhorizontal.loadFromFile("../src/Graphics/MapSprites/2DoorRoomOppositeHorizontal.png");
		_2doorroomne.loadFromFile("../src/Graphics/MapSprites/2DoorRoomNE.png");
		_2doorroomnw.loadFromFile("../src/Graphics/MapSprites/2DoorRoomNW.png");
		_2doorroomse.loadFromFile("../src/Graphics/MapSprites/2DoorRoomSE.png");
		_2doorroomsw.loadFromFile("../src/Graphics/MapSprites/2DoorRoomSW.png");
		_3doorroomnorth.loadFromFile("../src/Graphics/MapSprites/3DoorRoomNorth.png");
		_3doorroomeast.loadFromFile("../src/Graphics/MapSprites/3DoorRoomEast.png");
		_3doorroomwest.loadFromFile("../src/Graphics/MapSprites/3DoorRoomWest.png");
		_3doorroomsouth.loadFromFile("../src/Graphics/MapSprites/3DoorRoomSouth.png");
		_4doorroom.loadFromFile("../src/Graphics/MapSprites/4DoorRoom.png");
		unexploredlocation.loadFromFile("../src/Graphics/MapSprites/UnexploredLocation.png");
		lootlocation.loadFromFile("../src/Graphics/MapSprites/LootLocation.png");
		playerlocation.loadFromFile("../src/Graphics/MapSprites/PlayerLocation.png");
		combatlocation.loadFromFile("../src/Graphics/MapSprites/CombatLocation.png");
		invbtnview.loadFromFile("../src/Graphics/GUI_Sprites/invbtnview.png");
		credits.loadFromFile("../src/Graphics/GUI_Sprites/Credits.png");
		action0.loadFromFile("../src/Graphics/CharacterInfoSprites/Action0.png");
		action1.loadFromFile("../src/Graphics/CharacterInfoSprites/Action1.png");
		action2.loadFromFile("../src/Graphics/CharacterInfoSprites/Action2.png");
		action3.loadFromFile("../src/Graphics/CharacterInfoSprites/Action3.png");
		action4.loadFromFile("../src/Graphics/CharacterInfoSprites/Action4.png");
	}


	sf::Texture action4;
	sf::Texture action3;
	sf::Texture action2;
	sf::Texture action1;
	sf::Texture action0;
	sf::Texture credits;
	sf::Texture invbtnview;
	sf::Texture combatlocation;
	sf::Texture _1doorroomnorth;
	sf::Texture _1doorroomeast;
	sf::Texture _1doorroomwest;
	sf::Texture _1doorroomsouth;
	sf::Texture _2doorroomvertical;
	sf::Texture _2doorroomhorizontal;
	sf::Texture _2doorroomne;
	sf::Texture _2doorroomnw;
	sf::Texture _2doorroomse;
	sf::Texture _2doorroomsw;
	sf::Texture _3doorroomnorth;
	sf::Texture _3doorroomeast;
	sf::Texture _3doorroomwest;
	sf::Texture _3doorroomsouth;
	sf::Texture unexploredlocation;
	sf::Texture lootlocation;
	sf::Texture playerlocation;
	sf::Texture _4doorroom;
	sf::Texture mapbtnview;
	sf::Texture gameover;
	sf::Texture gamewon;
	sf::Texture game_view;
	sf::Texture door_closed;
	sf::Texture floor;
	sf::Texture levelexitclosed;
	sf::Texture levelexitopen;
	sf::Texture pit;
	sf::Texture trap1;
	sf::Texture trap2;
	sf::Texture trap3;
	sf::Texture wall;
	sf::Texture healthpotion;
	sf::Texture staminapotion;
	sf::Texture shortsword;
	sf::Texture armingsword;
	sf::Texture longsword;
	sf::Texture hatchet;
	sf::Texture battleaxe;
	sf::Texture mace;
	sf::Texture warhammer;
	sf::Texture roundshield;
	sf::Texture heatershield;
	sf::Texture kiteshield;
	sf::Texture towershield;
	sf::Texture sling;
	sf::Texture bolas;
	sf::Texture javelin;
	sf::Texture aiaggressive;
	sf::Texture aicareful;
	sf::Texture aiboss;
	sf::Texture airandom;
	sf::Texture aistunned;
	sf::Texture defense1;
	sf::Texture defense2;
	sf::Texture defense3;
	sf::Texture melee1;
	sf::Texture melee2;
	sf::Texture melee3;
	sf::Texture ranged1;
	sf::Texture ranged2;
	sf::Texture ranged3;
	sf::Texture emptyaction;
	sf::Texture enemybase;
	sf::Texture playerbase;
	sf::Texture depth1;
	sf::Texture depth2;
	sf::Texture depth3;
	sf::Texture depth4;
	sf::Texture depth5;
	sf::Texture depth6;
	sf::Texture health0;
	sf::Texture health1;
	sf::Texture health2;
	sf::Texture health3;
	sf::Texture health4;
	sf::Texture health5;
	sf::Texture nrzero;
	sf::Texture nrone;
	sf::Texture nrtwo;
	sf::Texture nrthree;
	sf::Texture nrfour;
	sf::Texture nrfive;
	sf::Texture nrsix;
	sf::Texture nrseven;
	sf::Texture nreight;
	sf::Texture nrinf;
	sf::Texture att;
	sf::Texture defse;
	sf::Texture coold;
	sf::Texture maxcoold;
	sf::Texture dur;
	sf::Texture nonum;
	sf::Texture infobtnview;
	sf::Texture diminvbutton;
	sf::Texture hugeslimeinfo;
	sf::Texture hugespiderinfo;
	sf::Texture largeslimeinfo;
	sf::Texture lichinfo;
	sf::Texture selectionrectangle;
	sf::Texture skeletonarcherinfo;
	sf::Texture skeletoninfo;
	sf::Texture skeletonknightinfo;
	sf::Texture skeletonmageinfo;
	sf::Texture skeletonwarriorinfo;
	sf::Texture slimeinfo;
	sf::Texture smallspiderinfo;
	sf::Texture spiderinfo;
	sf::Texture spitterinfo;
	sf::Texture armingswordinfo;
	sf::Texture battleaxeinfo;
	sf::Texture bolasinfo;
	sf::Texture hatchetinfo;
	sf::Texture healingpotioninfo;
	sf::Texture heatershieldinfo;
	sf::Texture javelininfo;
	sf::Texture kiteshieldinfo;
	sf::Texture longswordinfo;
	sf::Texture maceinfo;
	sf::Texture roundshieldinfo;
	sf::Texture shortswordinfo;
	sf::Texture slinginfo;
	sf::Texture staminapotioninfo;
	sf::Texture towershieldinfo;
	sf::Texture warhammerinfo;
	sf::Texture instructions;
};