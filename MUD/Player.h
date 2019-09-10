#pragma once
#include <string>
#include <fstream>
using namespace std;

class Player
{
private:
	int ID;
	string name;
	string password;
	int level;
	int money;
	int exp;

public:
	Player()
	{
		ID = -1;
		name = "NULL";
		password = "NULL";
		level = -1;
		money = -1;
		exp = -1;
	}

	Player(string un, string pw)//利用构造函数登陆账户
	{
		ID = -1;
		name = "NULL";
		password = "NULL";
		level = -1;
		money = -1;
		exp = -1;

		//验证登陆信息
		ifstream inUserInfo("userinfo.txt", ios::in);

		if (!inUserInfo)
		{
			cerr << "用户文件打开失败！" << endl;
			exit(1);
		}
		else
		{
			string line;
			bool isFind = false;
			bool findName = false;
			bool findPw = false;
			
			while (getline(inUserInfo, line))
			{
				string token;
				string delimiter = "\t";
				size_t position = line.find(delimiter);

				token = line.substr(0, position);
				ID = stoi(token);

				line.erase(0, (position + delimiter.length()));
				position = line.find(delimiter);
				token = line.substr(0, position);

				if (un == token)
				{
					findName = true;
					name = un;
				}

				line.erase(0, (position + delimiter.length()));
				position = line.find(delimiter);
				token = line.substr(0, position);

				if (pw == token)
				{
					findPw = true;
					password = pw;
				}

				if (findName && findPw)
				{
					isFind = true;

					line.erase(0, (position + delimiter.length()));
					position = line.find(delimiter);
					token = line.substr(0, position);
					level = stoi(token);

					line.erase(0, (position + delimiter.length()));
					position = line.find(delimiter);
					token = line.substr(0, position);
					money = stoi(token);

					line.erase(0, (position + delimiter.length()));
					position = line.find(delimiter);
					token = line.substr(0, position);
					exp = stoi(token);
					break;
				}
			}

			if (!isFind)
			{
				if (!findName)
				{
					cout << "用户名不存在！" << endl;
					system("pause");
					exit(1);
				}
				else if (!findPw)
				{
					cout << "密码错误！" << endl;
					system("pause");
					exit(1);
				}
			}
			else
			{
				cout << "登陆成功！" << endl;
				system("pause");
			}
		}

		inUserInfo.close();
		//end
	}

	int getID()
	{
		return ID;
	}

	string getName()
	{
		return name;
	}

	int getLevel()
	{
		return level;
	}

	int getMoney()
	{
		return money;
	}

	int getExp()
	{
		return exp;
	}

	string getPw()
	{
		return password;
	}

	void setName(string a)
	{
		name = string(a);
	}

	void setPw(string a)
	{
		password = string(a);
	}

	void setLevel(int a)
	{
		level = a;
	}

	void setMoney(int a)
	{
		money = a;
	}

	void setExp(int a)
	{
		exp = a;
	}

	void changeLevel(int a)
	{
		level += a;
	}

	void changeMoney(int a)
	{
		money += a;
	}

	void changeExp(int a)
	{
		exp += a;
	}
};

