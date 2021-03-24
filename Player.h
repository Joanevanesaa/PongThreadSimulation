#pragma once

class Player
{
private:

	enum player
	{
		playerX = 0,
		playerY = 1
	} currentPlayer;
	float hit;

public:
	Player(int i);
	Player(Player& clone);
	player getPlayer()
	{
		return currentPlayer;
	}
	float getHit();
	float setHit(float);

};

Player::Player(int i)
{
	if (i == 0)
	{
		currentPlayer = playerX;
	}
	else
		currentPlayer = playerY;

	hit = 0;
}

Player::Player(Player& clone)
{
	if (currentPlayer == playerX)
	{
		currentPlayer = playerY;
	}
	else
		currentPlayer = playerX;
	hit = 0;
}

float Player::setHit(float H)
{
	hit = H;
}

float Player::getHit()
{
	return hit;
}
