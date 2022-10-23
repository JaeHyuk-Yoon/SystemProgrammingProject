#include <iostream>
#include <map>

using namespace std;

struct Student {
	string name;
	int middlePoint;
	int finalPoint;
};

int main()
{
	int snum;
	
	map<int, Student> mapstudent;
	
	cout << "Enter student num : ";
	cin >> snum;
	
	for(int i = 0 ; i<snum ; i++)
	{
		Student student;
		
		cout << "Enter student[" << i << "] Info (name middle final) : ";
		cin >> student.name >> student.middlePoint >> student.finalPoint;
		
		/*map에 넣기*/
		mapstudent.emplace(i, student);
		cout <<"\""<< student.name << "\" 님이 ";
		cout << "트리에 추가되었습니다." << endl;
	}
	
	for (auto i = begin(mapstudent); i !=end(mapstudent); ++i)
		cout << "이름 = " << i-> second.name 
		<< " 중간 점수 = " << i-> second.middlePoint 
		<< " 기말 점수 = " << i-> second.finalPoint << endl;
}
