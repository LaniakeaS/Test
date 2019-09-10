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

	Player(string un, string pw)//���ù��캯����½�˻�
	{
		ID = -1;
		name = "NULL";
		password = "NULL";
		level = -1;
		money = -1;
		exp = -1;

		//��֤��½��Ϣ
		ifstream inUserInfo("userinfo.txt", ios::in);

		if (!inUserInfo)
		{
			cerr << "�û��ļ���ʧ�ܣ�" << endl;
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
					cout << "�û��������ڣ�" << endl;
					system("pause");
					exit(1);
				}
				else if (!findPw)
				{
					cout << "�������" << endl;
					system("pause");
					exit(1);
				}
			}
			else
			{
				cout << "��½�ɹ���" << endl;
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

