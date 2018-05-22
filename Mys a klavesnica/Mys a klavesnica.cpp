#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>


bool IsKeyPressed(int virtualKey)
{
	return((GetAsyncKeyState(virtualKey) & 0x8000) != 0 ? true : false);
}


int main()
{
	srand(time(NULL));
	short x = 0, y = 0;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point = { 2,2 };
	COORD point2;
	COORD point3 = { 2,22 };
	clock_t start, koniec;
	float  cas;
	int n = 0;
	char znak, znak_vstup;

	while (true)
	{
		if (n == 0) {
			SetConsoleCursorPosition(hConsole, point);
			//printf("Stlac F1 pre navod, F10 pre ukoncenie.");
			std::cout << "Stlac F1 pre navod, F10 pre ukoncenie.";
			n = 1;
		}

		if (IsKeyPressed(VK_ESCAPE) || IsKeyPressed(VK_F10))
		{
			printf("END!        \n");
			break;

		}
		if (IsKeyPressed(VK_F1))
		{
			printf("\n  Navod na pouzitie:\n");
			printf("\t Tlacidlom F2 spustite hru a meranie casu.\n");
			printf("\t Vasou ulohou je stlacit klaves ktory sa zobrazi na obrazovke.\n");
			printf("\t Pre ukoncenie stlacte ESC alebo F10.\n");
			n = 0;
		}
		if (IsKeyPressed(VK_F2))
		{
			system("cls");
			x = rand() % (70) + 5;
			y = rand() % (20) + 4;
			point2.X = x;
			point2.Y = y;
			SetConsoleCursorPosition(hConsole, point2);
			znak = rand() % (25) + 97;
			putchar(znak);
			start = clock();
			while (1)
			{
				if (_kbhit()) {
					znak_vstup = _getch();
					if (znak_vstup == znak)
						break;
				}
				Sleep(1);
			}
			koniec = clock();
			cas = (float)(koniec - start) / CLOCKS_PER_SEC*100;
			SetConsoleCursorPosition(hConsole, point3);
			printf("Klaves '%c' ste stlacili za %.0lf stotin sekundy.", znak, cas);
			n = 0;
		}	


		INPUT_RECORD *str = new INPUT_RECORD[1];
		DWORD num = 0;
		Sleep(1);
	}

    return 0;
}

