#pragma once

#include "CrazyTanks.h"
#include "PlayerClass.h"

class Enemy
{
private:
	int		x;
	int		y;
	bool	kl;
public:
	void	move(int **mp,int px,int py, vector<shot> &sh, const int lim, Player &pl, int gx, int gy);
	void	shoot(int **mp, int side, int cr, vector <shot> &sht, Player &pl);
	int		Getx();
	int		Gety();
	void	SetKl(bool v);
	void	SetKl(int x, int y);
			Enemy();
			Enemy(int x, int y);
			~Enemy();
};

