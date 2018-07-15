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


// 함수 호출
void Title(); // 처음 메뉴 출력화면 -> 도트찍기
void gotoxy(int, int); // 콘솔창에서 입력된 좌표값으로 이동
int Menu_Start(); // 첫번째 메뉴 구현 함수
int Keycontrol(); // Key를 입력받았을때 실행하는 함수 -> 입력 키보드값을 아스키코드값으로 반환하여 실행
int Menu_Score(); // 점수데이터를 저장한 메뉴로 이동
int Menu_Select(); // 게임 선택 화면으로 이동
void init(); // 콘솔 설정

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
	cout << "> 게 임 선 택";
	gotoxy(x, y + 1);
	cout << "점 수 보 기";
	gotoxy(x, y + 2);
	cout << "  종   료  " << "\n";
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
		
			case ENTER: // y값은 0,1,2중 하나로 후에 이것을 값으로받아서 어떤 선택을 했는지 알수있음.
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
	cout << "> 도 둑 잡 기";
	gotoxy(x, y + 1);
	cout << "테 트 리 스";
	gotoxy(x, y + 2);
	cout << "이 전 메 뉴";
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
	cout << "> 도 둑 잡 기";
	gotoxy(x, y + 1);
	cout << "테 트 리 스";
	gotoxy(x, y + 2);
	cout << "이 전 메 뉴";
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