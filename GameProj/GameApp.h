#pragma once

#include "Pigu.h"
#include "PiguEntity.h"
#include "PiguRenderer.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "PiguUtil.h"

class GameProjApp : public Pigu::PiguApp
{
public:
	
	GameProjApp(); //Constructor
	
	virtual void OnUpdate() override;
	//bool CollideX(const PiguEntity& one, const PiguEntity& another);
	//bool CollideY(const PiguEntity& one, const PiguEntity& another);
	bool Collide(const PiguEntity& one, const PiguEntity& another);


private:
	std::string img = "Assets/Images/";
	PiguEntity mHero{ {img+"RightHero.png", img+"LeftHero.png"} };
	PiguEntity mInnocent{ {img + "Enemy.png"} };
	PiguEntity mCollectedSign{ {img+"Collect0.png", img+"Collect1.png", img+"Collect2.png", img+"Collect3.png",
		img + "Collect4.png", img + "Collect5.png", img + "Collect6.png", img + "Collect7.png", img + "Collect8.png", 
		img + "Collect9.png", img + "Collect10.png"} };
	PiguEntity mCloud{ {img+"cloud1.png"} };
	PiguEntity mCoin{ {img+"CoinSmall.png"} };

	std::vector<PiguEntity> mEnemies{ {{img+"Enemy.png"}}, {{img+"Enemy.png"}}, {{img + "Enemy.png"}}, {{img + "Enemy.png"}} };
	std::vector<PiguEntity> mCollectedCoins{ {{img + "CoinSmall.png"}},
		{{img+"CoinSmall.png"}}, {{img+"CoinSmall.png"}}, {{img+"CoinSmall.png"}},
		{{img + "CoinSmall.png"}}, {{img + "CoinSmall.png"}}, {{img + "CoinSmall.png"}},
		{{img + "CoinSmall.png"}}, {{img + "CoinSmall.png"}}, {{img + "CoinSmall.png"}},
	};
	std::vector<PiguEntity> mBullets{ 
		{{img+"RightBullet.png", img+"LeftBullet.png"}}, 
		{{img+"RightBullet.png", img+"LeftBullet.png"}}, 
		{{img+"RightBullet.png", img+"LeftBullet.png"}}, 
		{{img+"RightBullet.png", img+"LeftBullet.png"}}, 
		{{img + "RightBullet.png", img + "LeftBullet.png"}},
		{{img + "RightBullet.png", img + "LeftBullet.png"}}
	};
	std::vector<PiguEntity> mExplosions{ 
		{{img+"Explode0.png", img+"Explode1.png", img+"Explode2.png", img+"Explode3.png", img+"Explode4.png"}},
		{{img+"Explode0.png", img+"Explode1.png", img+"Explode2.png", img+"Explode3.png", img+"Explode4.png"}},
		{{img+"Explode0.png", img+"Explode1.png", img+"Explode2.png", img+"Explode3.png", img+"Explode4.png"}},
		{{img+"Explode0.png", img+"Explode1.png", img+"Explode2.png", img+"Explode3.png", img+"Explode4.png"}} };
	std::vector<bool> mBullAvailable{ true, true, true, true, true, true };
	std::vector<bool> isExploding{ false, false, false, false };
	std::vector<int> mExpCount{ -1, -1, -1, -1}; //Exploding stage == 0, 1, 2, 3, 4, 5 (no explode, no enemy)

	PiguEntity mText{ {img + "intro.png", img + "win.png", img + "lose.png"} };

	//enum class HeroState{Standing, Running, Jumping} mHeroState{HeroState::Standing};
	//enum class HeroDirection{Left, Right} mHeroDirection{HeroDirection::Right};

	int mCountDown{ 0 };
	int mCollectedCount{ 0 };
	int mHorizontalSpeed{ 0 }; //speed measured in pixels per frame
	int mCloudVSpeed{ -2 };
	int mCoinSpeed{ -4 };
	int mLeftBullSpeed{ -3 };
	int mRightBullSpeed{ 3 };
	std::vector<int> enemySpeed{ -2, -2, -2, 0 };
	bool collided = false;
	int GameState{ 0 }; //0 = intro, 1 = win screen, 2 = loss screen, 3 = game is running
};