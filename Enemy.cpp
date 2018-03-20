#include "stdafx.h"
#include "Enemy.h"


void Enemy::move(int ** mp,int px, int py,vector<shot> &sht, const int lim, Player &pl, int gx,int gy)
{
	int dx;
	int dy;
	bool kl_pl;

	if (sqrt((gx - x) * (gx - x) + (gy - y) * (gy - y)) <= sqrt((px - x) * (px - x) + (py - y) * (py - y)))
	{
		kl_pl = false;
		dx = gx - x;
		dy = gy - y;
	}
	else
	{
		kl_pl = true;
		dx = px - x;
		dy = py - y;
	}
	if (kl)
		return;
	if (abs(dx) < abs(dy))
	{
		if (dx > 0 && x + 1 < lim && mp[y][x + 1] == 0)
		{
			swap(mp[y][x + 1], mp[y][x]);
			x++;
		}
		else if (dx < 0 && x > 0 && mp[y][x - 1] == 0)
		{
			swap(mp[y][x - 1], mp[y][x]);
			x--;
		}
		else if (dy < 6 || kl_pl)
		{
			shoot(mp, 1, py, sht, pl);
		}
		else if (mp[y + 1][x] == 0)
		{
			swap(mp[y + 1][x], mp[y][x]);
			y++;
		}
		else if (mp[y - 1][x] == 0)
		{
			swap(mp[y - 1][x], mp[y][x]);
			y--;
		}
	}
	else
	{
		if (dy > 0 && y + 1 < lim && mp[y + 1][x] == 0)
		{
			swap(mp[y + 1][x], mp[y][x]);
			y++;
		}
		else if (dy < 0 && y > 0 && mp[y - 1][x] == 0)
		{
			swap(mp[y - 1][x], mp[y][x]);
			y--;
		}
		else if (dy < 6 ||   kl_pl)
		{ 
			shoot(mp, 2, px, sht, pl);
		}
		else if (mp[y][x + 1] == 0)
		{
			swap(mp[y][x + 1], mp[y][x]);
			x++;
		}
		else if (mp[y][x + 1] == 0)
		{
			swap(mp[y][x - 1], mp[y][x]);
			x--;
		}
	}
}

void Enemy::shoot(int ** m, int side, int cr, vector <shot> &sht, Player &pl)
{
	shot s;
	if (side == 2 && cr < x)
	{
		if (m[y][x - 1] != 0)
		{
			if (m[y][x - 1] == -1)
				pl.lives--;
			return;
		}
		s.dir = 1;
		s.x = x - 1;
		s.y = y;
		s.en = true;
		sht.push_back(s);
	}
	else if (side == 1 && cr < y)
	{
		if (m[y - 1][x] != 0)
		{
			if (m[y - 1][x] == -1)
				pl.lives--;
			return;
		}
		s.dir = 2;
		s.x = x;
		s.y = y - 1;
		s.en = true;
		sht.push_back(s);
	}
	else if (side == 2 && cr > x)
	{
		if (m[y][x + 1] != 0)
		{
			if (m[y][x + 1] == -1)
				pl.lives--;
			return;
		}
		s.dir = 3;
		s.x = x + 1;
		s.y = y;
		s.en = true;
		sht.push_back(s);
	}
	else if (side == 1 && cr > y)
	{
		if (m[y + 1][x] != 0)
		{
			if (m[y + 1][x] == -1)
				pl.lives--;
			return;
		}
		s.dir = 4;
		s.x = x;
		s.y = y + 1;
		s.en = true;
		sht.push_back(s);
	}
}

int Enemy::Getx()
{
	return this->x;
}

int Enemy::Gety()
{
	return this->y;
}

void Enemy::SetKl(bool v)
{
	this->kl = v;
}

void Enemy::SetKl(int x, int y)
{
	if (this->x == x && this->y == y)
		this->kl = true;
}

Enemy::Enemy()
{
	this->kl = false;
}

Enemy::Enemy(int x, int y)
{
	this->kl = false;
	this->x = x;
	this->y = y;
}


Enemy::~Enemy()
{
}
