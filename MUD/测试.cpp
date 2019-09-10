#include <iostream>
#include <string>
#include "Users.h"
#include "Player.h"
using namespace std;

string username;
string password;
Player player;
int answer;

void login()
{
	cout << "用户名：";
	cin >> username;
	cout << "密码：";
	cin >> password;
	player = Player(username, password);
}

void signIn()
{
	Users a;
}

int main()
{
menu:
	cout << "0. 退出游戏" << endl;
	cout << "1. 登陆" << endl;
	cout << "2. 注册" << endl;
	cin >> answer;

	switch (answer)
	{
	case 0:
		return 0;
	case 1:
		login();
		cout << "待完成。" << endl;
		break;
		/*断点*/
	case 2:
		signIn();
		goto menu;
	default:
		cout << "错误选项！" << endl;
		break;
	}

	system("pause");
	return 0;
}