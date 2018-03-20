#pragma once

#include "CrazyTanks.h"

class Player
{
private:
	int		x;
	int		y;
	int		side;
	int		st_mp;
public:
	int		scores;
	int		lives;
	void	how2timer(int ms);
	bool	draw;
	void	shoot(int **m, vector<shot> &sht,const int lim);
	void	move(int sd, int **m, vector <shot> &sht,const int lim);
	void	SetPosition(int x, int y);
	int		Getx();
	int		Gety();
			Player();
			~Player();
};

