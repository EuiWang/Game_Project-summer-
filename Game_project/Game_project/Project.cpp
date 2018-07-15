#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define DOWN 1
#define UP 0
#define LEFT 2
#define RIGHT 3
#define SPACE 4
#define ENTER 5
#define ESC 6


// �Լ� ȣ��
void Title(); // ó�� �޴� ���ȭ�� -> ��Ʈ���
void gotoxy(int, int); // �ܼ�â���� �Էµ� ��ǥ������ �̵�
int Menu_Start(); // ù��° �޴� ���� �Լ�
int Keycontrol(); // Key�� �Է¹޾����� �����ϴ� �Լ� -> �Է� Ű���尪�� �ƽ�Ű�ڵ尪���� ��ȯ�Ͽ� ����
int Menu_Score(); // ���������͸� ������ �޴��� �̵�
int Menu_Select(); // ���� ���� ȭ������ �̵�
void init(); // �ܼ� ����

int main()
{
	init();
	Menu_Start();
}

void Title()
{
	cout << "\n" << "\n";
	cout << "    ####         ####   ###   ####     ##   ### \n";
	cout << "    ## ##       ## ##   ###   ## ##    ##   ### \n";
	cout << "    ##  ##     ##  ##   ###   ##  ##   ##   ### \n";
	cout << "    ##   ##   ##   ##   ###   ##   ##  ##   ### \n";
	cout << "    ##    ## ##    ##   ###   ##    ## ##   ### \n";
	cout << "    ##     ###     ##   ###   ##     ####   ### \n";
	cout << "\n";
	cout << "                                                #####         ####   ####           ####   ####### \n";
	cout << "                                               ##            ## ##   ## ##         ## ##   ## \n";
	cout << "                                              ##            ##  ##   ##  ##       ##  ##   ## \n";
	cout << "                                             ##   ###      #######   ##   ##     ##   ##   ######\n";
	cout << "                                             ##    ##     ##    ##   ##    ##   ##    ##   ## \n";
	cout << "                                              ##   ##    ##     ##   ##     ## ##     ##   ## \n";
	cout << "                                               #####    ##      ##   ##      ###      ##   ####### \n";
}

void init()
{
	system("title Mini Game World");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);



}

void gotoxy(int x, int y) 
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int Menu_Start()
{
	Title();
	int x = 44;
	int y = 21;
	gotoxy(x - 2, y);
	cout << "> �� �� �� ��";
	gotoxy(x, y + 1);
	cout << "�� �� �� ��";
	gotoxy(x, y + 2);
	cout << "  ��   ��  " << "\n";
	while (1)
	{
		int n = Keycontrol();
		switch (n)
		{
			case UP:
			{
				if (y > 21)
				{
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << "> ";
				}
				break;
			}
			case DOWN:
			{
				if (y < 23)
				{
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
				}
				break;
			}
		
			case ENTER: // y���� 0,1,2�� �ϳ��� �Ŀ� �̰��� �����ι޾Ƽ� � ������ �ߴ��� �˼�����.
			{
				y = y - 21;
				if (y == 0)
				{
					return Menu_Select(); 
				}
				else if (y == 1)
				{
					return Menu_Score();
				}
				else if (y == 2)
				{
					return 0;
				}
			}
		}

	} 
	cout << "\n" << "==========================================================================================";
}  
   
int Menu_Score()
{
	system("cls");
	Title();
	int x = 44;
	int y = 21;
	gotoxy(x - 2, y);
	cout << "> �� �� �� ��";
	gotoxy(x, y + 1);
	cout << "�� Ʈ �� ��";
	gotoxy(x, y + 2);
	cout << "�� �� �� ��";
	while (1)
	{
		int n = Keycontrol();
		switch (n)
		{
		case UP:
		{
			if (y > 21)
			{
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << "> ";
			}
			break;
		}
		case DOWN:
		{
			if (y < 23)
			{
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}

		case ENTER:
		{
			y = y - 21;
			if (y == 0)
			{
				cout << "ok";
			}
			else if (y == 1)
			{
				cout << "ok";
			}
			else if (y == 2)
			{
				system("cls");
				return Menu_Start();
			}
		}
		}

	}
	
}

int Menu_Select()
{
	system("cls");
	Title();
	int x = 44;
	int y = 21;
	gotoxy(x - 2, y);
	cout << "> �� �� �� ��";
	gotoxy(x, y + 1);
	cout << "�� Ʈ �� ��";
	gotoxy(x, y + 2);
	cout << "�� �� �� ��";
	while (1)
	{
		int n = Keycontrol();
		switch (n)
		{
		case UP:
		{
			if (y > 21)
			{
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << "> ";
			}
			break;
		}
		case DOWN:
		{
			if (y < 23)
			{
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}

		case ENTER: 
		{
			y = y - 21;
			if (y == 0)
			{
				cout << "ok";
			}
			else if (y == 1)
			{
				cout << "ok";
			}
			else if (y == 2)
			{
				system("cls");
				return Menu_Start();
			}
		}
		}

	}


}

int Keycontrol()
{
	int key;

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 224 || key == 0)
			{
				key = _getch();
				switch (key)
				{
				case 72:
					return UP;
					break;
				case 75:
					return LEFT;
					break;
				case 77:
					return RIGHT;
					break;
				case 80:
					return DOWN;
					break;
				}
			}
			else
			{
				if (key == 13)
					return ENTER;
				else if (key == 32)
					return SPACE;
				else if (key == 27)
					return ESC;
			}
		}
	}
}