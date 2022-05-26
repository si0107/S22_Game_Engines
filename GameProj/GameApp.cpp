#include "GameApp.h"


GameProjApp::GameProjApp()
{
	SetKeyPressedCallBack([this](const Pigu::KeyPressedPiguEvent& e)
		{
			switch (e.GetKeyCode())
			{
			case PIGU_KEY_LEFT:
				if (mHero.GetX() < 0)
					mHorizontalSpeed = 0;
				else
					mHorizontalSpeed = -5;
				mHero.SetActiveImage(1);
				break;
			case PIGU_KEY_RIGHT:
				if (mHero.GetX() > Pigu::GWindow::GetWindow()->GetWidth() - mHero.GetWidth())
					mHorizontalSpeed = 0;
				else
					mHorizontalSpeed = 5;
				mHero.SetActiveImage(0);
				break;
			case PIGU_KEY_UP:	//Height of Jump = height of Size of mHero --> later change to enemy + 20
				if ((mHero.GetActiveImage() == 1) && !(mHero.GetX() < 31)) //facing left and not on edge of screen
					mHero.SetX(mHero.GetX() - 30);
				else if ((mHero.GetActiveImage() == 1) && (mHero.GetX() < 31))
					mHero.SetX(1);
				else if ((mHero.GetActiveImage() == 0) && ((mHero.GetX() + mHero.GetWidth() + 31) > Pigu::GWindow::GetWindow()->GetWidth()))//facing right
					mHero.SetX(Pigu::GWindow::GetWindow()->GetWidth() - mHero.GetWidth());
				else
					mHero.SetX(mHero.GetX() + 30);
				
				mHero.SetY(mHero.GetY() + 30 + mEnemies[0].GetHeight());
				break;
			case PIGU_KEY_SPACE:  //use to shoot

				for (int i = 0; i < mBullAvailable.size(); i++)
				{
					if (mBullAvailable[i] == true) //if a bullet is available, use respective index in mBullets
					{
						if (mHero.GetActiveImage() == 1) //if facing left 
						{
							mBullets[i].SetActiveImage(1);
							mBullets[i].SetX(mHero.GetX() - mHero.GetWidth()); //shoot from left side of body
							mBullets[i].SetY(mHero.GetY() + mHero.GetHeight()/2 );
						}
						else //facing right
						{
							mBullets[i].SetActiveImage(0);
							mBullets[i].SetX(mHero.GetX() + mHero.GetWidth()); //shoot from right side of body
							mBullets[i].SetY(mHero.GetY() + mHero.GetHeight() / 2);
						}
						mBullAvailable[i] = false; //set unavailble until it leaves the screen
						break;//break from searching 
					}
				}
				break; //break if didn't find available
			}

		}
	);

	SetKeyReleasedCallBack([this](const Pigu::KeyReleasedPiguEvent& e)
		{
			switch (e.GetKeyCode())
			{
			case PIGU_KEY_UP:
				if ((mHero.GetActiveImage() == 1) && !(mHero.GetX() <= 31)) //facing left and not on edge
					mHero.SetX(mHero.GetX() - 30);
				else if ((mHero.GetActiveImage() == 1) && (mHero.GetX() <= 31)) //facing left and on edge
					mHero.SetX(1);
				else if ((mHero.GetActiveImage() == 0) && (mHero.GetX() + 30 >= Pigu::GWindow::GetWindow()->GetWidth() - mHero.GetWidth()))
					mHero.SetX(Pigu::GWindow::GetWindow()->GetWidth() - mHero.GetWidth());
				else
					mHero.SetX(mHero.GetX() + 30);
				mHero.SetY(mHero.GetY() - 30 - mEnemies[0].GetHeight());
				break;
			default:
				mHorizontalSpeed = 0;
			}

		}
	);

	//Set MText
	mText.SetActiveImage(0);
	mText.SetX(250);
	mText.SetY(175);

	//Intro Enemy
	mInnocent.SetActiveImage(0);
	mInnocent.SetX(450);
	mInnocent.SetY(150);

	//Vertical Enemy
	//mEnemies[0].SetActiveImage(0);
	mEnemies[0].SetX(400);
	mEnemies[0].SetY(600);

	//Set mHero
	mHero.SetActiveImage(0);
	mHero.SetX(0);
	mHero.SetY(0);


	//Horizontal Enemy
	mEnemies[1].SetX(Pigu::GWindow::GetWindow()->GetWidth() + 10);
	mEnemies[1].SetY(-10 - mEnemies[1].GetHeight());

	//Coin
	mCoin.SetX(Pigu::GWindow::GetWindow()->GetWidth() + 10);
	mCoin.SetY(-10 - mCoin.GetHeight());
	
	//Cloud
	mCloud.SetX(Pigu::GWindow::GetWindow()->GetWidth() - mCloud.GetWidth());
	mCloud.SetY(Pigu::GWindow::GetWindow()->GetHeight()/2);

	//Collected (0/3):
	mCollectedSign.SetActiveImage(0);
	mCollectedSign.SetX(10);
	mCollectedSign.SetY(Pigu::GWindow::GetWindow()->GetHeight() - mCollectedSign.GetHeight() - 10);

	int endOfSign = mCollectedSign.GetWidth() + mCollectedSign.GetX();
	int coinW = mCollectedCoins[0].GetWidth();


	for (int i = 0; i < mCollectedCoins.size(); i++) {
		mCollectedCoins[i].SetX(endOfSign + i*(coinW + 10));
		mCollectedCoins[i].SetY(mCollectedSign.GetY());
	}
}


void GameProjApp::OnUpdate()
{

	if (GameState == 0) // INTRO
	{
		//Loop Background
		if (mCloud.GetX() + mCloud.GetWidth() < 0)
			mCloud.SetX(mCloud.GetWidth() + Pigu::GWindow::GetWindow()->GetWidth() + 20);

		mCloud.SetX(mCloud.GetX() + mCloudVSpeed);

		mHero.SetX(mHero.GetX() + mHorizontalSpeed); //Adjust Hero Pos


		//bool collided = false;
		if (Collide(mHero, mInnocent))
		{
			mHero.SetActiveImage(0);
			mHero.SetX(0);
			mHero.SetY(0);

			collided = true;
		}

		mCloud.Draw();

		if (collided == true)
		{
			if (mCountDown >= 30)
			{
				mHero.SetActiveImage(0);
				mHero.SetX(0);
				mHero.SetY(0);
				GameState = 3;
			}
			else {
				mCountDown++;
				mHero.Draw();
			}
		}
		else{
			mText.Draw();
			mInnocent.Draw();
			mHero.Draw();
		}

	}
	else if (GameState == 3) // GAME RUNNING
	{
		//if mHero out of bounds
		if (mHero.GetX() < 0 || mHero.GetX() > Pigu::GWindow::GetWindow()->GetWidth() ||
			mHero.GetY() < 0 || mHero.GetY() > Pigu::GWindow::GetWindow()->GetHeight()) {
			mHero.SetActiveImage(0);
			mHero.SetX(0);
			mHero.SetY(0);
		}


		//Loop Background
		if (mCloud.GetX() + mCloud.GetWidth() < 0)
			mCloud.SetX(mCloud.GetWidth() + Pigu::GWindow::GetWindow()->GetWidth() + 20);

		mCloud.SetX(mCloud.GetX() + mCloudVSpeed);

		//Implement Randomness
		/* initialize random seed: */
		srand((unsigned)time(NULL));
		int randYPos = rand() % (mEnemies[1].GetHeight() * 2 + 50) + 0;
		int randYPosCoin = rand() % (mCoin.GetHeight() * 2 + 50) + 0;

		//Bound (Vert) Enemy
		if (isExploding[0] == false)
		{
			if (mEnemies[0].GetY() < 0)
				enemySpeed[0] *= -1;
			else if (mEnemies[0].GetY() > Pigu::GWindow::GetWindow()->GetHeight() - mEnemies[0].GetHeight())
				enemySpeed[0] *= -1;

			mEnemies[0].SetY(mEnemies[0].GetY() + enemySpeed[0]); //Adjust Vertical Enemy Pos
		}
		//mEnemies[0].SetY(mEnemies[0].GetY() + enemySpeed[0]); //Adjust Vertical Enemy Pos

		//Unbound (Horiz) Enemy
		if (isExploding[1] == false)
		{
			int initialX = Pigu::GWindow::GetWindow()->GetWidth() + 10;
			int initialY = (-10 - mEnemies[1].GetHeight());
			if (mEnemies[1].GetX() == initialX && mEnemies[1].GetY() == initialY)
				mEnemies[1].SetY(randYPos);
			//reset position and adjust velocity if it reaches end of the screen
			else if ((mEnemies[1].GetX() + mEnemies[1].GetWidth()) < -1) {
				mEnemies[1].SetX(initialX);
				mEnemies[1].SetY(randYPos);
				if (enemySpeed[1] >= -15)
					enemySpeed[1] -= 1;
				else if (enemySpeed[1] < -10)
					enemySpeed[1] = -2;
			}

			mEnemies[1].SetX(mEnemies[1].GetX() + enemySpeed[1]); //Adjust Horizontal Enemy Pos
		}

		//Unbound Coin
		int initialX = Pigu::GWindow::GetWindow()->GetWidth() + 10;
		int initialY = -10 - mCoin.GetHeight();
		if (mCoin.GetX() == initialX && mCoin.GetY() == initialY)
			mCoin.SetY(randYPosCoin);
		else if ((mCoin.GetX() + mCoin.GetWidth()) < -1) {
			mCoin.SetX(initialX);
			mCoin.SetY(randYPosCoin);
		}

		mCoin.SetX(mCoin.GetX() + mCoinSpeed);	//Adjust Coin Pos

		mHero.SetX(mHero.GetX() + mHorizontalSpeed); //Adjust Hero Pos

		//Bound Hero
		if (mHero.GetX() < 0)
			mHorizontalSpeed = 0;
		else if (mHero.GetX() > Pigu::GWindow::GetWindow()->GetWidth() - mHero.GetWidth())
			mHorizontalSpeed = 0;

		//Update Active Bullet Positions
		for (int i = 0; i < mBullAvailable.size(); i++)
			if (mBullAvailable[i] == false)
			{
				if (mBullets[i].GetActiveImage() == 1) //Facing Left
					mBullets[i].SetX(mBullets[i].GetX() + mLeftBullSpeed);
				else //Facing Right
					mBullets[i].SetX(mBullets[i].GetX() + mRightBullSpeed);

				bool bulletCollided = false;
				for (int j = 0; j < mEnemies.size(); j++) {

					if (Collide(mBullets[i], mEnemies[j])) //If bullet collids with enemy, remove bullet and enemy
					{
						if (isExploding[j] == false)
						{
							bulletCollided = true;
							mBullAvailable[i] = true;
							//mEnemies[j].SetX(-20 - mHero.GetWidth());
							//mEnemies[j].SetY(-20 - mHero.GetHeight());
							isExploding[j] = true;
							mExpCount[j] = 0;
							mExplosions[j].SetActiveImage(0);
							if (mBullets[i].GetActiveImage() == 0) //if bullet facing right
								mExplosions[j].SetX(mEnemies[j].GetX()); //explosion on left
							else
								mExplosions[j].SetX(mEnemies[j].GetX());
							mExplosions[j].SetY(mEnemies[j].GetY() + mEnemies[j].GetHeight() / 2);
						}
					}
				}

				if (!bulletCollided)
					mBullets[i].Draw();

				//Touching Sides of the screen
				if (mBullets[i].GetX() <= 0 || mBullets[i].GetX() >= Pigu::GWindow::GetWindow()->GetWidth()
					|| mBullets[i].GetY() <= 0 || mBullets[i].GetY() >= Pigu::GWindow::GetWindow()->GetHeight())
					mBullAvailable[i] = true; //make it available again
			}

		//Collisions ------------------------------------
		if (Collide(mHero, mEnemies[0]) || Collide(mHero, mEnemies[1]))
		{
			//exit(0);
			//Make all elements go off the screeen
			//Use -20 so you can't see them even if they jump
			if (isExploding[0] == false && isExploding[1] == false)
			{
				mHero.SetX(-20 - mHero.GetWidth());
				mHero.SetY(-20 - mHero.GetHeight());
				mHorizontalSpeed = 0;

				GameState = 2;
			}
		}

		if (Collide(mHero, mCoin) && (mCollectedCount == 9))
		{
			mCollectedCount++;
			mCollectedSign.SetActiveImage(mCollectedCount);
			GameState = 1;
		}

		if (Collide(mHero, mCoin) && !(mCollectedCount >= 10))
		{
			if (mCollectedCount < 10)
				mCollectedCount++;
			mCollectedSign.SetActiveImage(mCollectedCount);
			//exit(0);
			//Make all elements go off the screeen
			//Use -20 so you can't see them even if they jump
			mCoin.SetX(initialX);
			mCoin.SetY(initialY);
			//mHorizontalSpeed = 0;
		}

		mCloud.Draw();


		mCollectedSign.Draw();
		mHero.Draw();

		//Draw Explosions + Enemy
		for (int i = 0; i < mEnemies.size(); i++) {
			if (isExploding[i]) {
				enemySpeed[i] = 0;
				if (mExpCount[i] >= 0 && mExpCount[i] < 5) { //case 0
					mEnemies[i].Draw();
					mExplosions[i].Draw();
					mExpCount[i]++;
				}
				else if (mExpCount[i] >= 5 && mExpCount[i] < 10) { //case 1
					mExplosions[i].SetActiveImage(1);
					mEnemies[i].Draw();
					mExplosions[i].Draw();
					mExpCount[i]++;
				}
				else if (mExpCount[i] >= 10 && mExpCount[i] < 15) { //case 2
					mExplosions[i].SetActiveImage(2);
					mEnemies[i].Draw();
					mExplosions[i].Draw();
					mExpCount[i]++;
				}
				else if (mExpCount[i] >= 15 && mExpCount[i] < 20) { //case 3
					mExplosions[i].SetActiveImage(3);
					mEnemies[i].Draw();
					mExplosions[i].Draw();
					mExpCount[i]++;
				}
				else if (mExpCount[i] >= 20 && mExpCount[i] < 25) { //case 4
					mExplosions[i].SetActiveImage(4);
					mEnemies[i].Draw();
					mExplosions[i].Draw();
					mExpCount[i]++;
				}
				else if (mExpCount[i] >= 25 && mExpCount[i] < 30) { //case 6
					//Don't draw anything
					mExpCount[i]++;
					//mExplosions[i].SetActiveImage(0);
					//mExpCount[i] = -1;
					//isExploding[i] = false;
					//enemySpeed[i] = -2; // turn on velocity
				}
				else if (mExpCount[i] >= 30) { //Reset
					mExplosions[i].SetActiveImage(0);
					mExpCount[i] = -1;
					isExploding[i] = false;
					enemySpeed[i] = -2; // turn on velocity
					if (i == 0) {
						//Resent Vertical Enemy
						mEnemies[0].SetX(400);
						mEnemies[0].SetY(400);
					}
					else {
						//Horizontal Enemy
						mEnemies[1].SetX(Pigu::GWindow::GetWindow()->GetWidth() + 10);
						mEnemies[1].SetY(-10 - mEnemies[1].GetHeight());
					}

				}

			}
			else {
				mEnemies[i].Draw();
			}
		}

		mCoin.Draw();
		//Draw Collected Coins
		for (int i = 1; i <= mCollectedCount; i++)
		{
			int index = i - 1;
			mCollectedCoins[index].Draw();
		}
	}
	else if (GameState == 2) //Loss Screen
	{
		//Loop Background
		if (mCloud.GetX() + mCloud.GetWidth() < 0)
			mCloud.SetX(mCloud.GetWidth() + Pigu::GWindow::GetWindow()->GetWidth() + 20);

		mCloud.SetX(mCloud.GetX() + mCloudVSpeed);

		mCloud.Draw();

		mText.SetActiveImage(2);
		mText.SetX(250);
		mText.SetY(175);

		mText.Draw();
	}
	else if (GameState == 1) //Win Screen
	{
		//Loop Background
		if (mCloud.GetX() + mCloud.GetWidth() < 0)
			mCloud.SetX(mCloud.GetWidth() + Pigu::GWindow::GetWindow()->GetWidth() + 20);

		mCloud.SetX(mCloud.GetX() + mCloudVSpeed);

		mCloud.Draw();



		mText.SetActiveImage(1);
		mText.SetX(225);
		mText.SetY(175);

		mText.Draw();

		mCollectedSign.Draw();

		//Draw Collected Coins
		for (int i = 1; i <= mCollectedCount; i++)
		{
			int index = i - 1;
			mCollectedCoins[index].Draw();
		}

		mText.Draw();
	}
	

}


bool GameProjApp::Collide(const PiguEntity& one, const PiguEntity& another)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };

	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };
	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };

	bool collideX{ false };

	if ((anotherLeft <= oneLeft && oneLeft <= anotherRight) ||
		(oneLeft <= anotherLeft && anotherLeft <= oneRight))
		collideX = true;

	bool collideY{ false };
	
	if ((anotherBottom <= oneBottom && oneBottom <= anotherTop) ||
		(oneBottom <= anotherBottom && anotherBottom <= oneTop))
		collideY = true;
	
	return collideX && collideY;

}


/*
bool GameProjApp::CollideX(const PiguEntity& one, const PiguEntity& another)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };

	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };

	if ((anotherLeft <= oneLeft and oneRight <= anotherRight) or
		(anotherLeft <= oneRight and oneRight <= anotherRight) or
		(oneLeft <= anotherLeft and anotherLeft <= oneRight))
		return true;
	else
		return false;
}

bool GameProjApp::CollideY(const PiguEntity& one, const PiguEntity& another)
{
	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };

	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };

	if ((anotherBottom <= oneBottom and oneTop <= anotherTop) or
		(anotherBottom <= oneTop and oneTop <= anotherTop) or
		(oneBottom <= anotherBottom and anotherBottom <= oneTop))
		return true;
	else
		return false;
}
*/