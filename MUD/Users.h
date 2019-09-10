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
	//���ù��캯��ע���˻�
	Users()
	{
		//��ȡid�ļ�
		ifstream inID("ID.txt", ios::in);

		if (!inID)
		{
			cerr << "ID�ļ���ʧ�ܣ�" << endl;
			exit(1);
		}
		else
			inID >> id;//��ȡID�ļ��е����ݵ�����id����0��ʼ��

		inID.close();
		//end

		//�����û���Ϣ
		cout << "�û�����";//�����û���
		cin >> pname;
		cout << "���룺";//�����û�����
		cin >> pw;
		//end

		//�����Ϣ�Ϸ���
		ifstream inUserInfo("userinfo.txt", ios::in);

		if (!inUserInfo)
		{
			cerr << "�û��ļ���ʧ�ܣ�" << endl;
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
					cerr << "���������ظ���ID��" << endl;
					system("pause");
					exit(1);
				}

				line.erase(0, (position + delimiter.length()));
				position = line.find(delimiter);
				token = line.substr(0, position);

				if (token == pname || pname == "NULL")
				{
					cerr << "�ظ����û�����" << endl;
					system("pause");
					exit(1);
				}

				if (pw == "NULL")
				{
					cerr << "��Ч���룡" << endl;
					system("pause");
					exit(1);
				}
			}
		}

		inUserInfo.close();
		//end

		//����ҳ�ʼ��Ϣд���ļ�
		ofstream outUserInfo("userinfo.txt", ios::app);

		if (!outUserInfo)
		{
			cerr << "�û��ļ���ʧ�ܣ�" << endl;
			exit(1);
		}
		else
			outUserInfo << id << "\t" << pname << "\t" << pw << "\t" << 1 << "\t" << 100 << "\t" << 0 << endl;

		outUserInfo.close();
		//end

		//����id�ļ�
		ofstream outID("ID.txt", ios::out);

		if (!outID)
		{
			cerr << "ID�ļ���ʧ�ܣ�" << endl;
			exit(1);
		}
		else
			outID << ++id;

		outID.close();//�ر�ID�ļ�
		//end

		cout << "Success!" << endl;
		system("pause");
	}
};

