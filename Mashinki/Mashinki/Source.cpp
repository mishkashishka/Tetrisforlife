//#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <random>
#include <conio.h>

using namespace std;
bool stopgame = false;
float speedGame = 35;
int er = 0;
char Map[15][8] = {
	"######",
	"#   $#",
	"#    #",
	"#    #",
	"#    #",
	"#    #",
	"#    #",
	"#    #",
	"#   @#",
	"######" };

int main()

{	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 4);
	while (stopgame == false)
	{
		//speedGame = speedGame - er / 100;
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			cout << Map[i] << endl;
		}
		for (int y = 0; y < 15; y++) {
			for (int x = 0; x < 8; x++)
			{
				switch (Map[y][x])
				{
				case '@':
					if (GetAsyncKeyState(VK_LEFT) != 0)
						{
							int x2 = x - 1;
							switch (Map[y][x2])
							{
							case ' ':
								Map[y][x2] = Map[y][x];
								Map[y][x] = ' ';
								x -= 1;
								system("cls");
								Sleep(0.5);
								for (int i = 0; i < 15; i++)
								{
									cout << Map[i] << endl;
								}
								
							default:
								break;
							}
						}
						if (GetAsyncKeyState(VK_RIGHT) != 0)
						{
							int x2 = x + 1;
							switch (Map[y][x2])
							{
							case ' ':
								Map[y][x2] = Map[y][x];
								Map[y][x] = ' ';
								x += 1;
								system("cls");
								Sleep(0.5);
								for (int i = 0; i < 15; i++)
								{
									cout << Map[i] << endl;
								}
							default:
								break;
							}
						}
						break;
				case '$':
					if (y == 2) {
						Map[1][dist(gen)] = Map[y][x];
					}
					if (1) {
						int y2 = y + 1;
						switch (Map[y2][x])
						{
						case '@':
							stopgame = 1;
							break;
						case ' ':
							Map[y2][x] = Map[y][x];
							Map[y][x] = ' ';
							y += 1;
							break;
						case '#':
							Map[y][x] = ' ';
							y += 1;
							er = er + 1;
							break;
						default:
							break;
						}
					}
				default:
					break;
				}
			}
			Sleep(speedGame);
		}
		if (stopgame==1)
		{
			cout << "Your score:" << er << endl;
			system("pause");
		}
	}
	return 0;
}


