#pragma once
#include <fstream>
#include <string>
using namespace std;

class Users
{
private:
	int id;
	string pname;
	string pw;

public:
	//利用构造函数注册账户
	Users()
	{
		//读取id文件
		ifstream inID("ID.txt", ios::in);

		if (!inID)
		{
			cerr << "ID文件打开失败！" << endl;
			exit(1);
		}
		else
			inID >> id;//读取ID文件中的数据到变量id（从0开始）

		inID.close();
		//end

		//输入用户信息
		cout << "用户名：";//创建用户名
		cin >> pname;
		cout << "密码：";//创建用户密码
		cin >> pw;
		//end

		//检查信息合法性
		ifstream inUserInfo("userinfo.txt", ios::in);

		if (!inUserInfo)
		{
			cerr << "用户文件打开失败！" << endl;
			exit(1);
		}
		else
		{
			string line;

			while (getline(inUserInfo, line))
			{
				string token;
				string delimiter = "\t";
				size_t position = line.find(delimiter);
				token = line.substr(0, position);

				if (stoi(token) == id)
				{
					cerr << "致命错误，重复的ID！" << endl;
					system("pause");
					exit(1);
				}

				line.erase(0, (position + delimiter.length()));
				position = line.find(delimiter);
				token = line.substr(0, position);

				if (token == pname || pname == "NULL")
				{
					cerr << "重复的用户名！" << endl;
					system("pause");
					exit(1);
				}

				if (pw == "NULL")
				{
					cerr << "无效密码！" << endl;
					system("pause");
					exit(1);
				}
			}
		}

		inUserInfo.close();
		//end

		//将玩家初始信息写入文件
		ofstream outUserInfo("userinfo.txt", ios::app);

		if (!outUserInfo)
		{
			cerr << "用户文件打开失败！" << endl;
			exit(1);
		}
		else
			outUserInfo << id << "\t" << pname << "\t" << pw << "\t" << 1 << "\t" << 100 << "\t" << 0 << endl;

		outUserInfo.close();
		//end

		//更新id文件
		ofstream outID("ID.txt", ios::out);

		if (!outID)
		{
			cerr << "ID文件打开失败！" << endl;
			exit(1);
		}
		else
			outID << ++id;

		outID.close();//关闭ID文件
		//end

		cout << "Success!" << endl;
		system("pause");
	}
};

