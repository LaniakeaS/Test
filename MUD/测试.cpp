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
	cout << "�û�����";
	cin >> username;
	cout << "���룺";
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
	cout << "0. �˳���Ϸ" << endl;
	cout << "1. ��½" << endl;
	cout << "2. ע��" << endl;
	cin >> answer;

	switch (answer)
	{
	case 0:
		return 0;
	case 1:
		login();
		cout << "����ɡ�" << endl;
		break;
		/*�ϵ�*/
	case 2:
		signIn();
		goto menu;
	default:
		cout << "����ѡ�" << endl;
		break;
	}

	system("pause");
	return 0;
}