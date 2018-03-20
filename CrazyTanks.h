#pragma once

#include <utility>
#include <string>
#include <iostream>
#include <cstdlib>
#include <future>
#include <conio.h>
#include <locale.h>
#include <ctime>
#include <thread>
#include <iterator>

using namespace std;

struct shot
{
	unsigned int x;
	unsigned int y;
	int	dir;
	bool en;
};