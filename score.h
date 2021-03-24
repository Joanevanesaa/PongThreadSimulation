#pragma once


class Score
{
private:
	int scoreX = 0, scoreY = 0;
public:
	Score(int, int);
	int playerXScore();
	int playerYScore();
	void setScore(int, int);
	
	void addScoreX();
	void addScoreY();
};

Score::Score(int x, int y)
{
	scoreX = x;
	scoreY = y;
}

int Score::playerXScore()
{
	return scoreX;
}

int Score::playerYScore()
{
	return scoreY;
}

void Score::setScore(int x, int y)
{
	scoreX = x;
	scoreY = y;
}

void Score::addScoreX()
{
	scoreX++;
}

void Score::addScoreY()
{
	scoreY++;
}



