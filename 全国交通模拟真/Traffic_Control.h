#pragma once
#include<Windows.h>
#include"Map.h"
Map* Map::map = NULL;
void mainLoop();
void Menu();
bool Enter();
void Manage(Map *map);
//void DeleteStation(Map *map);
void DeletePath(Map *map);
void Message_control(Map *map);
void Path_short(Map *map);
void SerchStationMessage(Map *map);
void SerchStation(Map *map);
void mainLoop()
{
	
	Map *map = Map::getInstance();
	map->fromfileMessage();
	map->fromfilePath();
	map->fromfileStation();
	while (true)
	{
		Menu();
		int choice;
		cout << "���������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case 1:SerchStationMessage(map); break;
		case 2:Path_short(map); break;
		case 3:map->OptimumPath(); break;
		case 4:Message_control(map); break;
		case 5:Manage(map); break;
		case 6:map->path_Show(); break;
		case 0:exit(0);
		}
		cin.get();
		getchar();
		system("cls");
	}
	
}

void Menu()//�˵�
{
	cout << " ������������������������������������������" << endl;
	cout << "             ȫ����ͨ��ѯģ��ϵͳ" << endl;
	cout << "              1��������Ϣ��ѯ" << endl;
	cout << "              2�������е�·����ѯ" << endl;
	cout << "              3������з�������·����ѯ" << endl;
	cout << "              4���ο�������" << endl;
	cout << "              5������Ա����" << endl;
	cout << "              6���г�ʱ�̱�" << endl;
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
		//cout << "              2��ɾ������" << endl;
		cout << "              2������·��" << endl;
		cout << "              3��ɾ��·��" << endl;
		//cout << "              5�����ӽ�ͨ����" << endl;
	   //	cout << "              6����������" << endl;
		cout << "              0���˳�ϵͳ" << endl;
		cout << " ������������������������������������������" << endl;
		int choice;
		cout << "���������ѡ��:" << endl;
		cin >> choice;
		switch (choice) {
		case 1:map->addStation(); break;
		//case 2:DeleteStation(map); break;
		case 2:map->addPath(); break;
		case 3:DeletePath(map); break;
		//case 5:break;
	//	case 6:(*map).addMessage();
		case 0:break;
		default:break;
		}
	}
}
/*void DeleteStation(Map *map) {
	cout << "������Ҫɾ���ĳ�������:";
	string choice;
	cin >> choice;
	map->deleteStation(map->toId(choice));
}*/
void DeletePath(Map *map) {
	cout << "�������·�����ӵ�������������:";
	string name1, name2;
	cin >> name1 >> name2;
	map->deletePath(map->toId(name1), map->toId(name2));
}
void Message_control(Map *map) {
	cout << "1.�鿴������      " << "2.����" << endl;
	cout << "��ѡ�����ϲ���:";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:map->Message_Show(); break;
	case 2:map->addMessage(); break;
	}
}
void Path_short(Map *map) {
	cout << "������ѡ��:1.���������·����ѯ   2.����������·����ѯ"<<endl;
	int choice;
	cin >>choice ;
	cout << "������Ҫ��ѯ���������У�";
	string name1, name2;
	cin >> name1 >> name2;
	int temp=0;
	switch (choice) {
	case 1: {
		cout << "��ѡ����������:1.���·��    2.���ʱ��" << endl;
		int chose;
		cin >> chose;
		if (chose == 2) {
			map->voluation_Time();
			map->Short_Floyd();
			map->show_ShowTime(name1, name2);
		}
		else {
			map->voluation_Length();
			map->Short_Floyd();
			map->show_ShortPath(name1, name2);
		}
	    }break;
	case 2:
		  map->voluation_Length();
		  map->DFS(map->toId(name1), map->toId(name2),temp);
		  if (temp == 0) {
			  cout << "������������·�ߣ�����" << endl;
		  }
		  break;
	}
	
}
void SerchStationMessage(Map *map)
{
	cout << "��ѡ�����:1.ȫ����ѯ     2.������ѯ"<<endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:map->station_Show(); break;
	case 2:SerchStation(map); break;
	}
}

void SerchStation(Map *map)
{
	cout << "�������������:";
	string name;
	cin >> name;
	if (map->isStation(name)) {
		cout << "��������" << "    " << "���д���" << "    " << "���н���" << endl;
		for (int i = 0; i < map->getList().Size(); i++) {
			if (map->getList()[i].getName() == name) {
				cout << map->getList()[i].getName() << "         " << map->getList()[i].getId() << "         "
					<< map->getList()[i].getIntroduce() << endl;
				break;
			}
		}
	}
	else {
		cout << "�ó��в����ڣ�����" << endl;
	}
	
}