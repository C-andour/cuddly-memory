#include<iostream>
#include"StudentSet.h"
using namespace std;
void Operation()
{
	cout << "0.�˳�����ϵͳ" << endl;
	cout << "1.ѧ�Ų�ѯĳ��ѧ���ľ�����Ϣ" << endl;
	cout << "2.����������ѯĳ��ѧ���ľ�����Ϣ" << endl;
	cout << "3.������ָ��λ�ò���ѧ��������Ϣ��ѧ�Ų�����ͬ��" << endl;
	cout << "4.���Ը���ѧ��ɾ��ĳ��ѧ��" << endl;
	cout << "5.���Ը���ѧ���޸�ĳ��ѧ���Ļ�����Ϣ" << endl;
	cout << "6.���Ը����ܳɼ��Ӹߵ��ͽ�������" << endl;
	cout << "7.�������ȫ��ѧ����Ϣ" << endl;
	cout << "������������" << endl;
	cout << endl;
}
int main()
{
	StudentSet ss;
	ss.n = 3;
	ss.stu = new Student[ss.n];//��̬����ѧ������
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
		case 0://�˳�����ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		case 1://1.ѧ�Ų�ѯĳ��ѧ���ľ�����Ϣ
			int num;
			cout << "������ѧ��" << endl;
			cin >> num;
			count1 = IdSearch(ss,num);
			if (count1 != -1) Output(ss.stu[count1]);
			else cout << "���޴���";
			break;
		case 2://2.����������ѯĳ��ѧ���ľ�����Ϣ
			count2 = Namesearch(ss);
			if (count2 != -1)Output(ss.stu[count2]);
			else cout << "���޴���";
			break;
		case 3://3.������ָ��λ�ò���ѧ��������Ϣ��ѧ�Ų�����ͬ��
			Student s;
			Input(s);
			if (Insert(ss, s))
				cout << "����ɹ�";
			else
				cout << "ѧ���ظ�,����ʧ��";
			system("pause");
			system("cls");
			break;
		case 4://4.���Ը���ѧ��ɾ��ĳ��ѧ��
			cout << "������Ҫɾ����ѧ��ѧ��:" << endl;
			cin >> num;
			if (IdDelete(ss, num))
				cout << "ɾ���ɹ�";
			else
				cout << "���޴���,ɾ��ʧ��";
			system("pause");
			system("cls");
			break;
		case 5://5.���Ը���ѧ���޸�ĳ��ѧ���Ļ�����Ϣ
			cout << "������Ҫ�޸ĵ�ѧ��ѧ��:" << endl;
			cin >> num;
			cout << "������Ҫ�޸�ѧ���Ļ�����Ϣ:" << endl;
			Input(s);
			if (IdModify(ss, num, s))
				cout << "�޸ĳɹ�";
			else
				cout << "���޴���,�޸�ʧ��";
			break;
		case 6://6.���Ը����ܳɼ��Ӹߵ��ͽ�������
			Sortscore(ss);
			Output(ss);
			break;
		case 7://7.�������ȫ��ѧ����Ϣ
			Output(ss);
			system("pause");
			system("cls");
			break;
		}
	}
}