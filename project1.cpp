#include<iostream>
#include"StudentSet.h"
using namespace std;
void Operation()
{
	cout << "0.退出操作系统" << endl;
	cout << "1.学号查询某个学生的具体信息" << endl;
	cout << "2.根据姓名查询某个学生的具体信息" << endl;
	cout << "3.可以在指定位置插入学生基本信息（学号不能相同）" << endl;
	cout << "4.可以根据学号删除某个学生" << endl;
	cout << "5.可以根据学号修改某个学生的基本信息" << endl;
	cout << "6.可以根据总成绩从高到低进行排序" << endl;
	cout << "7.可以输出全部学生信息" << endl;
	cout << "请输入操作序号" << endl;
	cout << endl;
}
int main()
{
	StudentSet ss;
	ss.n = 3;
	ss.stu = new Student[ss.n];//动态创建学生数组
	ss.s_ize = 0;
	int count1 = 0;
	int count2 = 0;
	while (true)
	{
		Operation();
		int options;
		cin >> options;
		switch (options)
		{
		case 0://退出操作系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1://1.学号查询某个学生的具体信息
			int num;
			cout << "请输入学号" << endl;
			cin >> num;
			count1 = IdSearch(ss,num);
			if (count1 != -1) Output(ss.stu[count1]);
			else cout << "查无此人";
			break;
		case 2://2.根据姓名查询某个学生的具体信息
			count2 = Namesearch(ss);
			if (count2 != -1)Output(ss.stu[count2]);
			else cout << "查无此人";
			break;
		case 3://3.可以在指定位置插入学生基本信息（学号不能相同）
			Student s;
			Input(s);
			if (Insert(ss, s))
				cout << "插入成功";
			else
				cout << "学号重复,插入失败";
			system("pause");
			system("cls");
			break;
		case 4://4.可以根据学号删除某个学生
			cout << "请输入要删除的学生学号:" << endl;
			cin >> num;
			if (IdDelete(ss, num))
				cout << "删除成功";
			else
				cout << "查无此人,删除失败";
			system("pause");
			system("cls");
			break;
		case 5://5.可以根据学号修改某个学生的基本信息
			cout << "请输入要修改的学生学号:" << endl;
			cin >> num;
			cout << "请输入要修改学生的基本信息:" << endl;
			Input(s);
			if (IdModify(ss, num, s))
				cout << "修改成功";
			else
				cout << "查无此人,修改失败";
			break;
		case 6://6.可以根据总成绩从高到低进行排序
			Sortscore(ss);
			Output(ss);
			break;
		case 7://7.可以输出全部学生信息
			Output(ss);
			system("pause");
			system("cls");
			break;
		}
	}
}