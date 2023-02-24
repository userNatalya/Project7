#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
using namespace  std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}
void square(int x, int y, Color color)
{
	SetCursor(x, y);
	SetColor(color, Black);
	for (size_t i = 0; i < 10; i++)
	{
		SetCursor(x, y+i);
		SetColor(color, Black);
		for (size_t j = 0; j < 7; j++)
		{
			cout << "*";
		}
	}
	SetColor(White, Black);
}
void move(int x, int y, Color color)
{
	int key;
	do
	{
		square(x, y, color);
		key = _getch();
		square(x, y, Black);

		switch (key)
		{
		case Up:
			if (y > 0)
			{
				y--;
			}
			break;
		case Left:
			if (x > 0)
			{
				x--;
			}
			break;
		case Right:
			if (x < 50)
			{
				x++;
			}
			break;
		case Down:
			if (y < 30)
			{
				y++;
			}
			break;
		case Enter:
			color = (Color)(1 + rand() % 14);
			break;
		}
	} while (key != esc);
}

//Функция перемещает прямоугольник
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int x = 5, y = 7;
	Color color=Red;
	move(x, y, color);
}