#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "Game.h"

using namespace std;

int GameProcess1(int n, int buttom, int iFieldWidth, int iFieldHeight, char chLiveCell, char chDeadCell, bool *bCellArray, bool *bTempCellArray)
{
	cout << "                            Введите число поколений: \n";
	cout << "                                       "; cin >> n;

	if(n <= 10000)
	{
	srand((unsigned)time(NULL));
	int iGenerations(n);
	for (int y = 0; y < iFieldHeight; y++)
	{
		for (int x = 0; x < iFieldWidth; x++)
		{
			if ( bCellArray[x + y * iFieldWidth] )
			{
				cout << chLiveCell;
			}
			else
			{
				cout << chDeadCell;
			}
		}
		cout << '\n';
	}
	cout << '\n';
	for (int y = 0; y < iFieldHeight; y++)
	{
		for (int x = 0; x < iFieldWidth; x++)
		{
			bCellArray[x + y * iFieldWidth] = rand() % 2;
			
			if ( bCellArray[x + y * iFieldWidth] )
			{
				cout << chLiveCell;
			}
			else
			{
				cout << chDeadCell;
			}
		}
		cout << '\n';
	}
	
	cout << '\n';
	cout << '\n';
	
	for (int g = 0; g < iGenerations; g++)
	{	
		for (int y = 0; y < iFieldHeight; y++)
		{
			int iCellCounter = 0;
			for (int x = 0; x < iFieldWidth; x++)
			{
				if ( ((x - 1) >= 0) && ( (y - 1) >= 0) )
				{
					if (bCellArray[(x - 1) + (y - 1) * iFieldWidth]) iCellCounter++;
				}
				if ((y - 1) >= 0) 
				{
					if (bCellArray[x + (y - 1) * iFieldWidth]) iCellCounter++;
				}
				if (((x + 1) <= iFieldWidth) && ((y - 1) >= 0)) 
				{
					if (bCellArray[(x + 1) + (y - 1) * iFieldWidth]) iCellCounter++;
				}
				
				if ((x - 1) >= 0) 
				{
					if (bCellArray[(x - 1) + y * iFieldWidth]) iCellCounter++;
				}

				if ((x + 1) <= iFieldWidth - 1) 
				{
					if (bCellArray[(x + 1) + y * iFieldWidth]) iCellCounter++;
				}
				if (((x - 1) >= 0) && ((y + 1) <= iFieldHeight - 1)) 
				{
					if (bCellArray[(x - 1) + (y + 1) * iFieldWidth]) iCellCounter++;
				}
				if ((y + 1) <= iFieldHeight - 1) 
				{
					if (bCellArray[x + (y + 1) * iFieldWidth]) iCellCounter++;
				}
				if (((x + 1) <= iFieldWidth - 1) && ((y + 1) <= iFieldHeight - 1))
				{
					if (bCellArray[(x + 1) + (y + 1) * iFieldWidth]) iCellCounter++;
				}
				if ((iCellCounter < 2) || (iCellCounter > 3))
				{
					bTempCellArray[x + y * iFieldWidth] = false;
					cout << chDeadCell;
				}
				else
				{
					if ((!bCellArray[x + y * iFieldWidth]) && (iCellCounter != 3))
					{
						bTempCellArray[x + y * iFieldWidth] = false;
						cout << chDeadCell;
					}
					else
					{
						bTempCellArray[x + y * iFieldWidth] = true;
						cout << chLiveCell;
					}
				}
				iCellCounter = 0;	
			} 
			cout << '\n';
		}
		if(g < iGenerations-1)
		{
		usleep(100000);
		system("clear");
		}
		else
		{
		cout<<"Введите любмую клавишу, чтобы выйти в меню\n";
		int p;
		cin >> p;
		}
		for (int i = 0; i < (iFieldWidth * iFieldHeight); i++)
		{
			bCellArray[i] = bTempCellArray[i];
		}
	}
	}
	else
	{
		cout<<"Задано слишком большое число: n > 10000\n";
		system("Pause");
		system("clear");
		return 0;
	}
}


}
