#include "stdafx.h"
#include "PlayerClass.h"


void Player::how2timer(int ms)
{
	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;
	clock_t end_time = clock() + ms * CLOCKS_PER_MSEC;
	while (clock() < end_time) {} 
}

void Player::shoot(int ** m, vector<shot> &sht,const int lim)
{
	shot s;
	if (side == 75 && x > 0)
	{
		if (m[y][x - 1] == -2)
			scores += 100;
		s.dir = 1;
		s.x = x - 1;
		s.y = y;
		s.en = false;
		sht.push_back(s);
	}
	else if (side == 72 && y > 0)
	{
		if (m[y - 1][x] == -2)
			scores += 100;
		s.dir = 2;
		s.x = x;
		s.y = y - 1;
		s.en = false;
		sht.push_back(s);
	}
	else if (side == 77 && x < lim)
	{
		if (m[y][x + 1] == -2)
			scores += 100;
		s.dir = 3;
		s.x = x + 1;
		s.y = y;
		s.en = false;
		sht.push_back(s);
	}
	else if (side == 80 && y + 1 < lim)
	{
		if (m[y + 1][x] == -2)
			scores += 100;
		s.dir = 4;
		s.x = x;
		s.y = y + 1;
		s.en = false;
		sht.push_back(s);
	}
	//how2timer(50);
}

void Player::move(int sd, int **m, vector <shot> &sht,const int lim)
{
	if (sd == 75 && x - 1 >= 0 && (m[y][x - 1] == 0) && m[y][x] == -1)
	{
		side = sd;
		if(m[y][x - 1] == 0)
		swap(m[y][x - 1], m[y][x]);
		x--;
	}
	else if (sd == 72 && y - 1 >= 0 && (m[y - 1][x] == 0) && m[y][x] == -1)
	{
		side = sd;
		if (m[y - 1][x] == 0)
		swap(m[y - 1][x], m[y][x]);
		y--;
	}
	else if (sd == 77 && x + 1 <= lim - 1 && (m[y][x + 1] == 0) && m[y][x] == -1)
	{
		side = sd;
		if (m[y][x + 1] == 0)
		swap(m[y][x + 1], m[y][x]);
		x++;
	}
	else if (sd == 80 && y + 1 <= lim - 1 && (m[y + 1][x] == 0) && m[y][x] == -1)
	{
		side = sd;
		if (m[y + 1][x] == 0)
		swap(m[y + 1][x], m[y][x]);
		y++;
	}
}

void Player::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Player::Getx()
{
	return x;
}

int Player::Gety()
{
	return y;
}

Player::Player()
{
	this->draw = false;
	scores = 0;
	lives = 3;
	x = 10;
	y = 19;
}


Player::~Player()
{
}
