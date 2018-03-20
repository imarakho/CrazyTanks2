// CrazyTanks.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Enemy.h"

void	gen_fort(int **mp)
{
	mp[19][6] = 2;
	mp[19][7] = -3;
	mp[19][8] = 2;
	mp[18][6] = 2;
	mp[18][7] = 2;
	mp[18][8] = 2;
}
 
int main()
{
	int **mp = 0;
	const int lim = 20;
	Player pl;
	srand(time(0));
	setlocale(LC_ALL, "");
	Enemy  en(rand() % 4, rand() % 4);
	Enemy en2(rand() % 4 + 5, rand() % 4 + 5);
	Enemy en3(rand() % 4 + 10, rand() % 4 + 10);
	vector<shot> st;
	setlocale(LC_ALL, "");
	mp = new int *[lim];
	for (int i = 0; i < lim; i++)
	{
		mp[i] = new int[lim];
		for (int j = 0; j < lim; j++)
			mp[i][j] = 0;
	}
	gen_fort(mp);
	mp[en3.Gety()][en3.Getx()] = -2;
	mp[en2.Gety()][en2.Getx()] = -2;
	mp[en.Gety()][en.Getx()] = -2;
	mp[pl.Gety()][pl.Getx()] = -1;
	int x;
	int y;
	for (int i = 0; i < 15; i++)
	{
		x = rand() % 18 + 1;
		y = rand() % 18 + 1;
		if (mp[y][x] == 0)
			mp[y][x] = 2;
	}
	while (true)
	{
		if (pl.lives <= 0 || mp[19][7] == 0)
		{
			cout << "Game Over!" << endl;
			_getch();
			break;
		}
		if (pl.scores == 300)
		{
			cout << "Victory!" << endl;
			_getch();
			break;
		}
		for (int i = 1; i < lim + 3; i++)
			cout << "_";
		cout << endl;
		for (int i = 0; i < lim; i++)
		{
			wcout << L"▌";
			for (int j = 0; j < lim; j++)
			{
				if (mp[i][j] == 1)
					cout << "*";
				else if (mp[i][j] == 3)
					cout << "+";
				else if (mp[i][j] == -3)
					cout << "G";
				else if (mp[i][j] == 2)
					wcout << "w";
				else if (mp[i][j] == 0)
					cout << " ";
				else if (mp[i][j] == -2)
					cout << "E";
				else if (mp[i][j] == -1)
					wcout << "^";
			}
			wcout << L"▌";
			cout << endl;
		}
		for (int i = 1; i < lim + 3; i++)
			cout << "-";
		cout << endl;
		cout << "Lives:" << pl.lives << endl;
		cout << "Scores:" << pl.scores << endl;
		cout << "Seconds played:" << clock() / 1000.0 << endl;
		if (_getch() == 32)
		{
			pl.shoot(mp, st, lim);
		}
		else
		{ 
			pl.move(_getch(), mp, st, lim);
			en.move(mp, pl.Getx(), pl.Gety(), st, lim, pl,7,19);
			en2.move(mp, pl.Getx(), pl.Gety(), st, lim, pl,7,19);
			en3.move(mp, pl.Getx(), pl.Gety(), st, lim, pl,7,19);
		}
		for (int i = 0; i < st.size(); i++)
		{
				if (st[i].dir == 1)
				{
					if (st[i].x > 0 && mp[st[i].y][st[i].x - 1] == 0 && mp[st[i].y][st[i].x] != 2)
					{	
						st[i].en ? mp[st[i].y][st[i].x] = 3 : mp[st[i].y][st[i].x] = 1;
						swap(mp[st[i].y][st[i].x], mp[st[i].y][st[i].x - 1]);
						st[i].x--;
					}
					else
					{
						if (mp[st[i].y][st[i].x - 1] == -2 && mp[st[i].y][st[i].x] == 1)
						{
							en.SetKl(st[i].x - 1, st[i].y);
							en2.SetKl(st[i].x - 1, st[i].y);
							en3.SetKl(st[i].x - 1, st[i].y);
							pl.scores += 100;
							if (mp[st[i].y][st[i].x - 1] != -1)
								mp[st[i].y][st[i].x - 1] = 0;
						}
						else if (mp[st[i].y][st[i].x - 1] == -1 && mp[st[i].y][st[i].x] == 3)
							pl.lives--;
						else if (mp[st[i].y][st[i].x - 1] == 2 || mp[st[i].y][st[i].x - 1] == -3)
							mp[st[i].y][st[i].x - 1] = 0;
						if(mp[st[i].y][st[i].x] != -1)
						mp[st[i].y][st[i].x] = 0;
						st.erase(st.begin() + i);
					}
				}
				else if (st[i].dir == 2)
				{
					if (st[i].y > 0 && mp[st[i].y - 1][st[i].x] == 0 && mp[st[i].y][st[i].x] != 2)
					{
						st[i].en ? mp[st[i].y][st[i].x] = 3 : mp[st[i].y][st[i].x] = 1;
						swap(mp[st[i].y][st[i].x], mp[st[i].y - 1][st[i].x]);
						st[i].y--;
					}
					else
					{
						if (st[i].y > 0 && mp[st[i].y - 1][st[i].x] == -2 && mp[st[i].y][st[i].x] == 1)
						{
							en.SetKl(st[i].x, st[i].y - 1);
							en2.SetKl(st[i].x, st[i].y - 1);
							en3.SetKl(st[i].x, st[i].y - 1);
							pl.scores += 100;
							if (mp[st[i].y - 1][st[i].x] != -1)
							mp[st[i].y - 1][st[i].x] = 0;
						}
						else if (st[i].y > 0 && mp[st[i].y - 1][st[i].x] == -1 && mp[st[i].y][st[i].x] == 3)
							pl.lives--;
						else if (st[i].y > 0 && (mp[st[i].y - 1][st[i].x] == 2 || mp[st[i].y - 1][st[i].x] == -3))
							mp[st[i].y - 1][st[i].x] = 0;
						if (mp[st[i].y][st[i].x] != -1)
						mp[st[i].y][st[i].x] = 0;
						st.erase(st.begin() + i);
					}
				}
				else if (st[i].dir == 3)
				{
					if (st[i].x + 1 < lim && mp[st[i].y][st[i].x + 1] == 0 && mp[st[i].y][st[i].x] != 2)
					{
						st[i].en ? mp[st[i].y][st[i].x] = 3 : mp[st[i].y][st[i].x] = 1;
						swap(mp[st[i].y][st[i].x], mp[st[i].y][st[i].x + 1]);
						st[i].x++;
					}
					else
					{
						if (mp[st[i].y][st[i].x + 1] == -2 && mp[st[i].y][st[i].x] == 1)
						{
							en.SetKl(st[i].x + 1, st[i].y);
							en2.SetKl(st[i].x + 1, st[i].y);
							en3.SetKl(st[i].x + 1, st[i].y);
							pl.scores += 100;
							if (mp[st[i].y][st[i].x + 1] != -1)
							mp[st[i].y][st[i].x + 1] = 0;
						}
						else if (mp[st[i].y][st[i].x + 1] == -1 && mp[st[i].y][st[i].x] == 3)
							pl.lives--;
						else if (mp[st[i].y][st[i].x + 1] == 2 || mp[st[i].y][st[i].x + 1] == -3)
							mp[st[i].y][st[i].x + 1] = 0;
						if (mp[st[i].y][st[i].x] != -1)
						mp[st[i].y][st[i].x] = 0;
						st.erase(st.begin() + i);
					}
				}
				else if (st[i].dir == 4)
				{
					if (st[i].y + 1 < lim && mp[st[i].y + 1][st[i].x] == 0 && mp[st[i].y][st[i].x] != 2)
					{
						st[i].en ? mp[st[i].y][st[i].x] = 3 : mp[st[i].y][st[i].x] = 1;
						swap(mp[st[i].y][st[i].x], mp[st[i].y + 1][st[i].x]);
							st[i].y++;
					}
					else
					{
						if (st[i].y < lim -1 && mp[st[i].y + 1][st[i].x] == -2 && mp[st[i].y][st[i].x] == 1)
						{
							en.SetKl(st[i].x, st[i].y + 1);
							en2.SetKl(st[i].x, st[i].y + 1);
							en3.SetKl(st[i].x, st[i].y + 1);
							pl.scores += 100;
							if (mp[st[i].y + 1][st[i].x] != -1)
							mp[st[i].y + 1][st[i].x] = 0;
						}
						else if (st[i].y < lim - 1 && mp[st[i].y + 1][st[i].x] == -1 && mp[st[i].y][st[i].x] == 3)
							pl.lives--;
						else if (st[i].y < lim -1 && (mp[st[i].y + 1][st[i].x] == 2 || mp[st[i].y + 1][st[i].x] == -3))
							mp[st[i].y + 1][st[i].x] = 0;
						if(mp[st[i].y][st[i].x] != -1)
							mp[st[i].y][st[i].x] = 0;
						st.erase(st.begin() + i);
					}
				}
			}
			system("cls");
	}
    return 0;
}

