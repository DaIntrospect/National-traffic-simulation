#pragma once
#include"Map.h"
Map* Map::map = NULL;
void mainLoop();
void Menu();
bool Enter();
void mainLoop()
{

	/*Map *map = Map::getInstance();
	(*map).station_Show();
	system("pause");
	(*map).path_Show();
	//system("pause");
	//(*map).fromfilePath();
	//(*map).path_Show();
	//(*map).station_Show();
	//cout << endl;
	//(*map).addStation();
	//map.fromfileStation();
	//(*map).station_Show();
	//for (int i = 0; i < 3; i++) {
	//map.addPath();
	(*map).addPath();
	//}
	//(*map).infilePath();
	//(*map).infilePath();
	//(*map).path_Show();
	system("pause");*/
	Menu();
	cout<<Enter();
	system("pause");
}

void Menu()//�˵�
{
	cout << " ������������������������������������������" << endl;
	cout << "             ȫ����ͨ��ѯģ��ϵͳ" << endl;
	cout << "              1��������Ϣ��ѯ" << endl;
	cout << "              2�������е�·����ѯ" << endl;
	cout << "              3������з���·����ѯ" << endl;
	cout << "              4������з�������·����ѯ" << endl;
	cout << "              5���ο�������" << endl;
	cout << "              6������Ա����" << endl;
	cout << "              0���˳�ϵͳ" << endl;
	cout << " ������������������������������������������" << endl;
}

bool Enter()//����
{
	cout << "�������û�����" << endl;
	string name;
	cin >> name;
	cout << "���������룺" << endl;
	string password;
	cin >> password;
	if (name == "���ֺ�"&&password == "123") {
		cout << "����ɹ�" << endl;
		return true;
	}
	cout << "����ʧ�ܣ�����" << endl;
	return false;
}