#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <deque>
#include <ctime>
#pragma warning(disable:4996)
using namespace std;
HANDLE hOut;
COORD pos;

//1.ʵ��gotoxy����
void gotoxy(short x, short y)
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ���
	pos = { x, y };
	SetConsoleCursorPosition(hOut, pos);  //�ƶ���굽ָ��λ��
}
void HideCursor() //���ع��
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false;    //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
}

//2.�ߵĽṹ��
struct Snake
{
	char body;
	short position_x, position_y;    //�ߵ�����
};

//3.��Ϸ������
class Game
{
private:
	char image;
	enum mapSize { width = 60, height = 30 }; //��Ϸ��ͼ
	deque<Snake> snake;      //����һ�����У�װ�ߵ�����
	int score = 0;        //��Ϸ����
	char hit = 'w';       //��������
	bool eat_Food = false;      //�Ƿ�Ե�ʳ��
	short food_x, food_y;      //ʳ������
	int speed = 400;       //�ߵ��ٶ�
	bool snake_state = true;     //�ߵ�״̬
	int level = 1;        //��Ϸ�ؿ�
public:
	Game();
	void draw_Frame()  //���߿�
	{
		for (int i = 0; i < height; i++)
		{
			gotoxy(0, i);
			cout << "��";
			gotoxy(width, i);
			cout << "��";
		}
		for (int i = 0; i <= width; i += 2) //�� �������ռ�����ַ�λ�ã�������+2
		{
			gotoxy(i, 0);
			cout << "��";
			gotoxy(i, height);
			cout << "��";
		}
	}
	void init_snake()  //��ʼ����
	{
		snake.push_back({ '#', width / 2, static_cast<short>(height / 2) }); //�����ͷ
		for (int i = 0; i < 3; i++) //�ߵĳ�ʼ������������Զ�
			snake.push_back({ char('o'), width / 2, static_cast<short>((height / 2) + 1 + i) });
		snake.push_back({ ' ', width / 2, static_cast<short>((height / 2) + 4) }); //�����β���ȷſգ��Ա��ں�����ӽ���ʱ����
	}
	void draw_Snake() //����
	{
		for (int k = 0; k < snake.size(); k++)
		{
			gotoxy(snake[k].position_x, snake[k].position_y);
			cout << snake[k].body;
		}
	}
	void clear_Tail() //�����β��������ʹ��������������������
	{
		int k = snake.size() - 1;
		gotoxy(snake[k].position_x, snake[k].position_y);
		cout << " "; //��ÿ�ƶ�һ�Σ���һ�񣩣��Ͱ���һ�λ���������β����
	}
	void draw_Food() //��ʳ��
	{
		while (1)
		{
			food_x = rand() % (width - 4) + 2; //ʳ��Ҫ�ڵ�ͼ�У������ٵ�ͼ�߿��ϣ���ͼ�ķ�����x����ռ�����ַ�λ������+2����-4���Ǽ�ȥ�߿�
			food_y = rand() % (height - 2) + 1; //����ͬ��
			if (wrong_Location() && food_x % 2 == 0)
				break;
		}
		gotoxy(food_x, food_y);
		cout << "O";
	}
	bool wrong_Location() //�ж�ʳ��������Ƿ����
	{
		for (auto i : snake) //c++11�Ļ��ڷ�Χ��ѭ��
		{
			if (food_x == i.position_x && food_y == i.position_y) //ʳ�ﲻ�ܳ������ߵ�������
				return 0;
		}
		return 1;
	}
	void judge_eatFood() //�ж��Ƿ�Ե�ʳ��
	{
		if (food_x == snake[0].position_x && food_y == snake[0].position_y)
			eat_Food = true;
	}
	void judge_state() //�ж����Ƿ�ײǽ��ײ����
	{
		if (snake.size() >= 2)
		{
			deque<Snake>::iterator iter = snake.begin() + 1; //ʵ�ʾ��ǰ�snake�������һ��������ͷ������iter��
			int x = (iter - 1)->position_x, y = (iter - 1)->position_y;
			for (; iter != snake.end(); ++iter)
			{
				if (iter->position_x == x && iter->position_y == y) //��ͷ����ײ����
					snake_state = false;
			}
		}
		if (snake[0].position_x == 1 ||
			snake[0].position_x == 59 ||
			snake[0].position_y == 0 ||
			snake[0].position_y == 30) //��ͷ����ײ�߿�
			snake_state = false;
	}
	void key_Down() //������Ӧ
	{
		char key = hit;
		if (_kbhit()) //���ܰ���
			hit = _getch();
		for (int i = snake.size() - 1; i > 0; i--) //�ߵ��ƶ�������ÿ�ƶ�һ�Σ�����һ�ڵ����嵽������ǰһ��������
		{
			snake[i].position_x = snake[i - 1].position_x;
			snake[i].position_y = snake[i - 1].position_y;
		}
		if ((hit == 'a' || hit == 'A') && hit != 'd')
		{
			hit = 'a'; snake[0].position_x--;
		}
		else if ((hit == 'd' || hit == 'D') && hit != 'a')
		{
			hit = 'd'; snake[0].position_x++;
		}
		else if ((hit == 'w' || hit == 'W') && hit != 's')
		{
			hit = 'w'; snake[0].position_y--;
		}
		else if ((hit == 's' || hit == 'S') && hit != 'w')
		{
			hit = 's'; snake[0].position_y++;
		}
	}
	void show()
	{
		gotoxy(65, 0);
		cout << "��ĵ÷���:";
		gotoxy(71, 1);
		cout << score;
		gotoxy(69, 2);
		cout << "�ؿ�:" << level;
	}
};
Game::Game()
{
	HideCursor();
	srand(static_cast<unsigned int>(time(NULL))); //���������
	init_snake();
	draw_Food();
	Snake tail; //��β
	while (1)
	{
		draw_Frame();
		tail = snake.back();
		if (eat_Food)
		{
			snake.back().body = 'o'; //�ѳ�ʼ���ߵĿ�β��ʾ��Ϊo��������Ч�����Ǽ���һ��
			snake.push_back(tail); //�����һ�ڿ�β�������´β���
			gotoxy(food_x, food_y);
			cout << " "; //ʳ�ﱻ�Ժ�Ҫ��ԭ����λ�û��գ����������λ�����±߿��λ
			draw_Food();
			score++;
			if (score % 5 == 0)
			{
				speed *= 0.8;
				level++;
			}
			eat_Food = false;
		}
		if (level == 10)
			break;
		key_Down();
		draw_Snake();
		judge_state();
		if (!snake_state)
			break;
		judge_eatFood();
		Sleep(speed);
		clear_Tail();
		show();
	}
}
int main()
{
	system("mode con cols=100 lines=40"); //���ô򿪴��ڴ�С
	system("color 7C"); //���ñ���ɫ��ǰ��ɫ
	system("title ̰���� v1.0");// ���ô��ڱ���
		Game game;
	gotoxy(0, 32);
	cout << "Game over!" << endl;
}