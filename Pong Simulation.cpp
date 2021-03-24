// Pong Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <random>
#include <mutex>
#include "Player.h"
#include "score.h"

using namespace std;

Score score(0, 0);

mutex m;

void RandomPlayerHits(Player* player, bool* finish)
{
	m.lock();
	int* i = new int;
	srand((int)i);
	delete i;
	player->setHit(rand() % 101);
	m.unlock();
	
	cout << "Hits : " << player->getHit();
	if (player->getPlayer() == 0) {
		cout << " Player X ";
	}
	else {
		cout << " Player Y ";
	}

	if (player->getHit() <= 50)
	{
		if (player->getPlayer() == 0)
		{
			score.addScoreY();
		}
		else
		{
			score.addScoreX();
		}
		cout << "Don't get hit" << endl;

		*finish = true;
	}
	else
	{
		cout << "Is Hit" << endl;
	}

	this_thread::sleep_for(chrono::seconds(2));
}

void randomPlayerTurn(int* player) {
	int* i = new int;
	srand((int)i);
	delete i;
	*player = rand() % 2;
}

int main()
{
	srand(time(0));

	Player playerX(0);

	Player playerY = playerX;

	int game = 1;
	while (score.playerXScore() < 10 && score.playerYScore() < 10)
	{
		int turn;
		thread RandomFirst(randomPlayerTurn, &turn);
		RandomFirst.join();
		bool gameFinish = false;

		cout << "---Round " << game << "---" << endl;
		while (gameFinish == false) {
			if (turn == 0)
			{
				cout << "Player X First" << endl;

				thread playerXThread(RandomPlayerHits, &playerX, &gameFinish);
				playerXThread.join();

				if (gameFinish == true) {
					game++;
					break;
				}

				thread playerYThread(RandomPlayerHits, &playerY, &gameFinish);
				playerYThread.join();

				if (gameFinish == true) {
					game++;
					break;
				}
			}
			else if (turn == 1)
			{
				cout << "Player Y First" << endl;

				thread playerYThread(RandomPlayerHits, &playerY, &gameFinish);
				playerYThread.join();

				if (gameFinish == true)
				{
					game++;
					break;
				}

				thread playerXThread(RandomPlayerHits, &playerX, &gameFinish);
				playerXThread.join();

				if (gameFinish == true) {
					game++;
					break;
				}
			}
		}
	}

	cout << "\nTotal Score: " << endl;
	if (score.playerXScore() >= 10) {
		cout << "Player X :  " << score.playerXScore() << "-" << score.playerYScore() << ". Player X Win!" << endl;
	}
	else {
		cout << "Player Y :  " << score.playerYScore() << "-" << score.playerXScore() << ". Player Y Win!" << endl;
	}

	return 0;
}