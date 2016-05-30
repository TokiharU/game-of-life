#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "Game.h"

int GameProcess1(int n, int buttom, int iFieldWidth, int iFieldHeight, char chLiveCell, char chDeadCell, bool *bCellArray, bool *bTempCellArray);
int GameProcess2(int n, int buttom, int iFieldWidth, int iFieldHeight, char chLiveCell, char chDeadCell, bool *bCellArray, bool *bTempCellArray);
int GameProcess3(int n, int buttom, int iFieldWidth, int iFieldHeight, char chLiveCell, char chDeadCell, bool *bCellArray, bool *bTempCellArray);

using namespace std;
int main()
{
	menu:
	setlocale(LC_CTYPE, "Russian");
	const int iFieldWidth(79), iFieldHeight(24);
	const char chLiveCell = ('*'), chDeadCell(' ');
	bool bCellArray[iFieldWidth * iFieldHeight] = {false};
	bool bTempCellArray[iFieldWidth * iFieldHeight] = {false};
	int p,n, buttom;
	
	cout << "...............................................................................\n";
	cout << ".###########################......Game of Life.....###########################.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#.................................1. Game 1 [Random]........................#.\n";
	cout << ".#.................................2. Game 2 [Glider]........................#.\n"; 
	cout << "...................................3. Game 3 [Eyes]............................\n";
	cout << ".#.................................4. Exit ..................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".#...........................................................................#.\n";
	cout << ".###########################.......................###########################.\n";
	cout << "...............................................................................\n";
	cout << "                                 Please, enter: "; cin >> buttom;
	system("clear");

	switch (buttom)
	{
		case 1:
		{
			GameProcess1( n, buttom, iFieldWidth, iFieldHeight, chLiveCell, chDeadCell, bCellArray, bTempCellArray);
			goto menu;
		}
		case 2:
		{
			GameProcess2(n, buttom, iFieldWidth, iFieldHeight, chLiveCell, chDeadCell, bCellArray, bTempCellArray);
			goto menu;
		}
		case 3:
		{
			GameProcess3(n, buttom, iFieldWidth, iFieldHeight, chLiveCell, chDeadCell, bCellArray, bTempCellArray);
			goto menu;
		}
		case 4:
		{
			break;
		}
		default:
			system("clear");
			cout<<"Неверный пункт меню!\n";
			cout<<"Введите любмую клавишу, чтобы выйти в меню\n";
			system("Pause");
			goto menu;
	}
	return 0;
}
