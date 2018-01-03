#pragma once
#include"Map.h"
Map* Map::map = NULL;
void mainLoop();
void Menu();
bool Enter();
void Manage(Map *map);
void DeleteStation(Map *map);
void DeletePath(Map *map);
void Message_control(Map *map);
void mainLoop()
{
	
	Map *map = Map::getInstance();
	while (true)
	{
		Menu();
		int choice;
		cout << "���������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case 1:map->station_Show(); break;
		case 2:(*map).station_Show(); break;
		case 3:(*map).station_Show(); break;
		case 4:(*map).station_Show(); break;
		case 5:Message_control(map); break;
		case 6:Manage(map); break;
		case 0:exit(0);
		}
	}
}

void Menu()//�˵�
{
	cout << " ������������������������������������������" << endl;
	cout << "             ȫ����ͨ��ѯģ��ϵͳ" << endl;
	cout << "              1��������Ϣ��ѯ" << endl;
	cout << "              2�������е�·����ѯ" << endl;
	cout << "              3�����������з���·����ѯ" << endl;
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

void Manage(Map *map)//����Ա����
{
	if (Enter()) {
		cout << " ������������������������������������������" << endl;
		cout << "             ȫ����ͨ��ѯ����Ա����" << endl;
		cout << "              1�����ӳ���" << endl;
		cout << "              2��ɾ������" << endl;
		cout << "              3������·��" << endl;
		cout << "              4��ɾ��·��" << endl;
		cout << "              5�����ӽ�ͨ����" << endl;
	//	cout << "              6����������" << endl;
		cout << "              0���˳�ϵͳ" << endl;
		cout << " ������������������������������������������" << endl;
		int choice;
		cout << "���������ѡ��:" << endl;
		cin >> choice;
		switch (choice) {
		case 1:map->addStation(); break;
		case 2:DeleteStation(map); break;
		case 3:map->addPath(); break;
		case 4:DeletePath(map); break;
		case 5:break;
	//	case 6:(*map).addMessage();
		case 0:break;
		default:break;
		}
	}
}
void DeleteStation(Map *map) {
	cout << "������Ҫɾ���ĳ�������:";
	string choice;
	cin >> choice;
	map->deleteStation(map->toId(choice));
}
void DeletePath(Map *map) {
	cout << "�������·�����ӵ�������������:";
	string name1, name2;
	cin >> name1 >> name2;
	map->deletePath(map->toId(name1), map->toId(name2));
}
void Message_control(Map *map) {
	cout << "1.�鿴������ " << "2.����" << endl;
	cout << "��ѡ�����ϲ���:";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:map->Message_Show(); break;
	case 2:map->addMessage(); break;
	}
}