#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<fstream>
#include <cstdlib>
#include"SeqList.h"
#include"Station.h"
#include"Path.h"
#define MAXNUM 100
#define IPOSSIBLE_NUM -1
class Map
{
private:
	Map() {};
	Map(int num);
	~Map();
	SeqList<Station> list;
	double Edges[MAXNUM][MAXNUM];
	SeqList<Path> edges;
	static Map *map;

public:
	int getNumVertexes()
	{
		return list.Size();
	}
	int getNumEdges()
	{
		return edges.Size();
	}
	static Map* getInstance();
	bool isStation(Station st);//�жϳ�վ�Ƿ����
	bool isEdges(Path pa);//�ж�·�Ƿ����
	void addStation();
	void deleteStation(int i);
	void addPath();
	void deletePath(int start,int end);
	void station_Show();
	void path_Show();
	void fromfileStation();
	void infileStation();
	void fromfilePath();
	void infilePath();
	void voluation_Length();//·�̣�Ȩֵ,��ֵ
	void voluation_Time();//ʱ�䣬Ȩֵ
	int toId(string name);//������ת��Ϊ��Ӧ�ĳ���id
	friend istream& operator>>(istream &is, Station &station);
	friend istream& operator>>(istream &is, Path &path);
	friend istream& operator>>(istream &is, PathTrain &pathnode);
};
Map* Map::getInstance() {
	if (map == NULL) {
		map = new Map(100);
		cout << "get";
	}
	return map;
}
Map::~Map() {
	cout << "ɾ������";
	if (map != NULL) {
		delete map;
	}
}
Map::Map(int num )
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i == j)
			{
				Edges[i][j] = 0;
			}
			else {
				Edges[i][j] = IPOSSIBLE_NUM;
			}
		}
	}
}

bool Map::isStation(Station st)
{
	for (int i = 0; i < list.Size(); i++)
	{
      if (st.getName() == list[i].getName() || st.getId() == list[i].getId())
      {
		  cout << "wer";
	    return false;
       }
	}
	return true;
}

bool Map::isEdges(Path pa)
{
	for (int i = 0; i < edges.Size(); i++)
	{
		if (pa.getStart_station() == edges[i].getStart_station() && pa.getEnd_station() == edges[i].getEnd_station())
		{
			return false;
		}
	}
	return true;
}

void Map::addStation()
{
	Station st;
	cout << "�����복վ��վ������վ�����,��վ�Ľ���" << endl;
	cin >> st;
	if (isStation(st))
	{
		list.Insert(st, list.Size());
		cout << "���ӳɹ�����" << endl;
		infileStation();
	}
	else {
		cout << "�ó�վ�Ѵ��ڣ�����ʧ��!!!" << endl;
	}
}

void Map::deleteStation(int i)
{
	if (i<0 || i>list.Size()) {
		cout << "�ó�վ������!!!" << endl;
	}
	else {
		list.Delete(i);
		cout << "ɾ���ɹ�����" << endl;
		infileStation();
	}
	
}

void Map::addPath()
{
	Path pa;
	cout << "�������·�ߵ����վ���֣��յ�վ���֣�����,����Ŀ" << endl;
	cin >> pa;
	if (isEdges(pa)) {
	edges.Insert(pa, edges.Size());
	cout << "���ӳɹ�������" << endl;
		infilePath();
	}
	else {
		cout << "��·���Ѵ��ڣ�����ʧ��!!!" << endl;
	}
}

void Map::deletePath(int start, int end)
{
	int temp;
	for (int i = 0; i < edges.Size(); i++) {
		if (edges[i].getStart_station() == (start+1)&& edges[i].getEnd_station() == (end+1)) {
			temp = i;
			break;
		}
	}
	if (!isEdges(edges.GetData(temp))) {
		edges.Delete(temp);
		cout << "ɾ���ɹ�������" << endl;
		infilePath();
	}
	else {
		cout << "��·�߲����ڣ���" << endl;
	}
}

istream& operator>>(istream &is, Station &station)
{
	string name,introduce;
	int id;
	is >> name >> id>>introduce;
	station.setId(id);
	station.setName(name);
	station.setIntroduce(introduce);
	return is;
}
istream& operator>>(istream &is, Path &path)
{
	string start, end;
	int trainnum;
	double length;
	SeqList<PathTrain> pathtrain;
	PathTrain pathnode;
	//Map *map = Map::getInstance();
	is >> start >> end >> length >> trainnum;
	for (int i = 0; i < trainnum; i++) {
		cin >> pathnode;
		pathtrain.Insert(pathnode, pathtrain.Size());
	}
	path.setStart_station((*map).toId(start));
	path.setEnd_station((*map).toId(start));
	path.setLength(length);
	path.setTrainNumber(trainnum);
	path.setTrain(pathtrain);
	//delete map;
	return is;
}

istream& operator>>(istream &is, PathTrain& pathnode) {
	string start_time, end_time, trainname;
	cout << "�������������ʼʱ�䣬��վʱ��" << endl;
	is >> trainname >> start_time >> end_time;
	pathnode.setStart_time(start_time);
	pathnode.setEnd_time(end_time);
	pathnode.setTrain_name(trainname);
	return is;
}

void Map::station_Show() {
	fromfileStation();
	cout << "��������" << " " << "���д���" << " " << "���н���" << endl;
	for (int i = 0; i < list.Size(); i++) {
		cout << list[i].getName() << " "<<list[i].getId()<<" "<<list[i].getIntroduce();
		cout << endl;
	}
	
}

void Map::path_Show() {
	fromfilePath();
	cout << "����վ   " << "�յ�վ  " << "�г���  " << "����ʱ��  " << "��վʱ��   " << endl;
	for (int i = 0; i < edges.Size(); i++) {
		int start = edges[i].getStart_station();
		int end = edges[i].getEnd_station();
		for (int j = 0; j < edges[i].getTrainNumber(); j++) {
			cout << list[start-1].getName() << "  " << list[end-1].getName() << "  ";
			cout << (edges[i].getTrain())[j].getTrain_name()<<"  "<< edges[i].getTrain()[j].getStart_time() << " "<< edges[i].getTrain()[j].getEnd_time()<<endl;
		}	
	}
}

void Map::fromfileStation() {
	fstream ifile;
	ifile.open("Station.txt");
	if (!ifile)  cout << "Դ�ļ���ʧ��" << endl;
	else {
		if (ifile.eof())
			ifile.get();
		Station temp;
		string name,introduce;
		int id;
		while (!ifile.eof()) {
			ifile >> name >>id>>introduce;
			temp.setId(id);
			temp.setName(name);
			temp.setIntroduce(introduce);
			list.Insert(temp, list.Size());
		}
		ifile.close();
	}
}

void  Map::infileStation() {
	fclose(fopen("Station.txt", "w"));
	fstream ifile;
	ifile.open("Station.txt");
	if (!ifile)  cout << "Դ�ļ���ʧ��" << endl;
	else {
	   int i = 0;
	   while (i<list.Size()) {
		   if (i == list.Size() - 1) {
			   ifile << list[i].getName() << " " << list[i].getId()<<" "<<list[i].getIntroduce();
			   break;
		   }
		   ifile << list[i].getName() << " " << list[i].getId() << " " << list[i].getIntroduce() << endl;
		   i++;
		}
		ifile.close();
	}
}

void Map::fromfilePath() {
	fstream ofile;
	ofile.open("Path.txt");
	if (!ofile)  cout << "Դ�ļ���ʧ��" << endl;
	else {
		if (ofile.eof())
			ofile.get();
		Path path;
		PathTrain pathnode;
		int start, end,trainnum;
		double length;
		string start_time, end_time,train_name;
		while (!ofile.eof()) {
			ofile >> start >> end >> length >> trainnum;
			SeqList<PathTrain> seqlist;
			for (int i = 0; i < trainnum; i++) {
				ofile >> train_name >> start_time >> end_time;
				pathnode.setStart_time(start_time);
				pathnode.setEnd_time(end_time);
				pathnode.setTrain_name(train_name);
				pathnode.setSum_time(pathnode.sum());
				seqlist.Insert(pathnode, seqlist.Size());
			}
			path.setStart_station(start);
			path.setEnd_station(end);
			path.setLength(length);
			path.setTrainNumber(trainnum);
			path.setTrain(seqlist);
			edges.Insert(path, edges.Size());
			//seqlist.Cleardate();
		}
		ofile.close();
	}
}

void  Map::infilePath() {
	fclose(fopen("Path.txt", "w"));
	fstream ofile;
	ofile.open("Path.txt");
	if (!ofile)  cout << "Դ�ļ���ʧ��" << endl;
	else {
		int i = 0;
		while (i<edges.Size()) {
			if (i == edges.Size() - 1) {
				ofile << edges[i].getStart_station() << " " << edges[i].getEnd_station()<<" "
					<<edges[i].getLength()<<" "<<edges[i].getTrainNumber()<<" ";
				for (int j= 0; j < edges[i].getTrainNumber(); j++) {
					ofile << edges[i].getTrain()[j].getTrain_name() << " "
						<< edges[i].getTrain()[j].getStart_time() << " "
						<< edges[i].getTrain()[j].getEnd_time();
				}
				break;
			}
			ofile << edges[i].getStart_station() << " " << edges[i].getEnd_station() << " "
				<< edges[i].getLength() << " " << edges[i].getTrainNumber() << " ";
			for (int j = 0; j < edges[i].getTrainNumber(); j++) {
				if (j == edges[i].getTrainNumber() - 1) {
					ofile << edges[i].getTrain()[j].getTrain_name() << " "
						<< edges[i].getTrain()[j].getStart_time() << " "
						<< edges[i].getTrain()[j].getEnd_time() << endl;
					break;
				}
				ofile << edges[i].getTrain()[j].getTrain_name() << " "
					<< edges[i].getTrain()[j].getStart_time() << " "
					<< edges[i].getTrain()[j].getEnd_time()<<" ";
			}
			i++;
		}
		ofile.close();
	}
}

void Map::voluation_Length() {
	for (int i = 0; i < edges.Size(); i++) {
		Edges[edges[i].getStart_station()][edges[i].getEnd_station()] = edges[i].getLength();
	}
}

void Map::voluation_Time() {
	
	for (int i = 0; i < edges.Size(); i++) {
		double sumtime=edges[i].getTrain()[0].getSum_time();
		for (int j = 0; j < edges[i].getTrainNumber(); j++) {
			if (edges[i].getTrain()[j].getSum_time() < sumtime) {
				sumtime = edges[i].getTrain()[j].getSum_time();
			}
		}
		Edges[edges[i].getStart_station()][edges[i].getEnd_station()] = sumtime;
	}

}
int Map::toId(string name) {
	for (int i = 0; i < list.Size(); i++) {
		if (list[i].getName() == name) {
			return i;
		}
	}
	return IPOSSIBLE_NUM;
}