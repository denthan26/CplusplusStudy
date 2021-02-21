#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <deque>
#include <ctime>
#pragma warning(disable:4996)
using namespace std;
HANDLE hOut;
COORD pos;

//1.实现gotoxy函数
void gotoxy(short x, short y)
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); //获取句柄
	pos = { x, y };
	SetConsoleCursorPosition(hOut, pos);  //移动光标到指定位置
}
void HideCursor() //隐藏光标
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false;    //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}

//2.蛇的结构体
struct Snake
{
	char body;
	short position_x, position_y;    //蛇的坐标
};

//3.游戏运行类
class Game
{
private:
	char image;
	enum mapSize { width = 60, height = 30 }; //游戏地图
	deque<Snake> snake;      //定义一个队列，装蛇的身体
	int score = 0;        //游戏分数
	char hit = 'w';       //按键输入
	bool eat_Food = false;      //是否吃到食物
	short food_x, food_y;      //食物坐标
	int speed = 400;       //蛇的速度
	bool snake_state = true;     //蛇的状态
	int level = 1;        //游戏关卡
public:
	Game();
	void draw_Frame()  //画边框
	{
		for (int i = 0; i < height; i++)
		{
			gotoxy(0, i);
			cout << "■";
			gotoxy(width, i);
			cout << "■";
		}
		for (int i = 0; i <= width; i += 2) //■ 这个符号占两个字符位置，所以是+2
		{
			gotoxy(i, 0);
			cout << "■";
			gotoxy(i, height);
			cout << "■";
		}
	}
	void init_snake()  //初始化蛇
	{
		snake.push_back({ '#', width / 2, static_cast<short>(height / 2) }); //添加蛇头
		for (int i = 0; i < 3; i++) //蛇的初始身体节数，可自定
			snake.push_back({ char('o'), width / 2, static_cast<short>((height / 2) + 1 + i) });
		snake.push_back({ ' ', width / 2, static_cast<short>((height / 2) + 4) }); //添加蛇尾，先放空，以便于后面添加节数时操作
	}
	void draw_Snake() //画蛇
	{
		for (int k = 0; k < snake.size(); k++)
		{
			gotoxy(snake[k].position_x, snake[k].position_y);
			cout << snake[k].body;
		}
	}
	void clear_Tail() //清除蛇尾，不建议使用清屏函数，避免屏闪
	{
		int k = snake.size() - 1;
		gotoxy(snake[k].position_x, snake[k].position_y);
		cout << " "; //蛇每移动一次（即一格），就把上一次画出来的蛇尾擦掉
	}
	void draw_Food() //画食物
	{
		while (1)
		{
			food_x = rand() % (width - 4) + 2; //食物要在地图中，不能再地图边框上，地图的符号在x方向占两个字符位置所以+2，而-4则是减去边框
			food_y = rand() % (height - 2) + 1; //与上同理
			if (wrong_Location() && food_x % 2 == 0)
				break;
		}
		gotoxy(food_x, food_y);
		cout << "O";
	}
	bool wrong_Location() //判断食物的坐标是否合理
	{
		for (auto i : snake) //c++11的基于范围的循环
		{
			if (food_x == i.position_x && food_y == i.position_y) //食物不能出现在蛇的身体上
				return 0;
		}
		return 1;
	}
	void judge_eatFood() //判断是否吃到食物
	{
		if (food_x == snake[0].position_x && food_y == snake[0].position_y)
			eat_Food = true;
	}
	void judge_state() //判断蛇是否撞墙或撞身体
	{
		if (snake.size() >= 2)
		{
			deque<Snake>::iterator iter = snake.begin() + 1; //实际就是把snake容器里第一个（即蛇头）存在iter里
			int x = (iter - 1)->position_x, y = (iter - 1)->position_y;
			for (; iter != snake.end(); ++iter)
			{
				if (iter->position_x == x && iter->position_y == y) //蛇头不能撞自身
					snake_state = false;
			}
		}
		if (snake[0].position_x == 1 ||
			snake[0].position_x == 59 ||
			snake[0].position_y == 0 ||
			snake[0].position_y == 30) //蛇头不能撞边框
			snake_state = false;
	}
	void key_Down() //按键响应
	{
		char key = hit;
		if (_kbhit()) //接受按键
			hit = _getch();
		for (int i = snake.size() - 1; i > 0; i--) //蛇的移动方法，每移动一次，后面一节的身体到了它的前一节身体上
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
		cout << "你的得分是:";
		gotoxy(71, 1);
		cout << score;
		gotoxy(69, 2);
		cout << "关卡:" << level;
	}
};
Game::Game()
{
	HideCursor();
	srand(static_cast<unsigned int>(time(NULL))); //随机数种子
	init_snake();
	draw_Food();
	Snake tail; //蛇尾
	while (1)
	{
		draw_Frame();
		tail = snake.back();
		if (eat_Food)
		{
			snake.back().body = 'o'; //把初始化蛇的空尾显示化为o，看到的效果就是加了一节
			snake.push_back(tail); //再添加一节空尾，便于下次操作
			gotoxy(food_x, food_y);
			cout << " "; //食物被吃后要在原来的位置画空，否则光标会退位，导致边框错位
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
	system("mode con cols=100 lines=40"); //设置打开窗口大小
	system("color 7C"); //设置背景色和前景色
	system("title 贪吃蛇 v1.0");// 设置窗口标题
		Game game;
	gotoxy(0, 32);
	cout << "Game over!" << endl;
}