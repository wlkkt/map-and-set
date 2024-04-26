#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;

void test_set1()
{
	// keyģ������
	// ����+ȥ��
	set<int> s1;
	s1.insert(1);
	s1.insert(11);
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);

	set<int>::iterator it = s1.begin();
	while (it != s1.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int> v = { 3,2,8,1,10,2 };
	set<int> s2(v.begin(), v.end());
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int> s3 = { 3,2,8,1,10,2 };
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;
	s3.erase(8);
	s3.erase(18);
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;

	auto pos = s3.find(10);
	if (pos != s3.end())
	{
		cout << *pos << endl;
		s3.erase(pos);
	}
	else
	{
		cout << "�Ҳ���" << endl;
	}
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	std::set<int> myset;
	for (int i = 1; i < 10; i++)
		myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;

	auto itlow = myset.lower_bound(25);                // >= x
	auto itup = myset.upper_bound(60);                 // > x

	// [30, 70)
	myset.erase(itlow, itup);                     // 10 20 70 80 90

	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	// keyģ������
	// ���� ��ȥ�أ���������
	// 
	multiset<int> s1;
	s1.insert(1);
	s1.insert(11);
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);
	s1.insert(1);

	multiset<int>::iterator it = s1.begin();
	while (it != s1.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	auto pos = s1.find(2);
	while (pos != s1.end() && *pos == 2)
	{
		cout << *pos << " ";
		++pos;
	}
}

void test_map1()
{
	map<string, string> dict;
	pair<string, string> kv1("sort", "����");
	dict.insert(kv1);
	dict.insert(pair<string, string>("left", "���"));
	dict.insert(make_pair("right", "�ұ�"));
	dict.insert(make_pair("right", "xxxx"));


	// ��ʽ����ת��
	//pair<string, string> kv2 = { "string", "�ַ���" };
	dict.insert({ "string", "�ַ���" });

	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		// iterator key�����޸� value�����޸�
		// const_iterator key�����޸� value�����޸�
		//it->first += 'x';
		it->second += 'x';

		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		//cout << it.operator->()->first << ":" << it.operator->()->second << endl;
		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		//auto& [x, y] = kv;
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	/*for (auto& [x, y] : dict)
	{
		cout << x << ":" << y << endl;
	}
	cout << endl;*/

	//map<string, string> dict2 = { {"string", "�ַ���"}, {"left", "���"},{"right", "�ұ�"} };
	map<string, string> dict2 = { kv1, {"left", "���"},{"right", "�ұ�"} };
}

void test_map2()
{
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
"ƻ��", "�㽶", "ƻ��", "�㽶","ƻ��","��ݮ", "ƻ��","��ݮ" };
	map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
		//auto it = countMap.find(e);
		//if (it != countMap.end())
		//{
		//	it->second++;
		//}
		//else
		//{
		//	//const pair<string, int>& val = { e, 1 };
		//	countMap.insert({ e, 1 });
		//}
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	// 21:13
	multimap<int, string> sortMap;
	for (auto& kv : countMap)
	{
		//sortMap[kv.second] = kv.first;
		sortMap.insert({ kv.second, kv.first });
	}
	cout << endl;

	for (auto& kv : sortMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

//
//V& operator[](const K& key)
//{
//	// ���ܲ���ɹ�����ʧ�ܣ�pair��iteratorʼ��ָ��key���ڽڵ��iterator
//	pair<iterator, bool> ret = this->insert(make_pair(key, V()));
//	iterator it = ret.fisrt;
//	return it->second;
//}

//void test_map3()
//{
//	map<string, string> dict;
//	dict.insert({ "string", "�ַ���" });
//
//	// ���루һ�㲻����ô�ã�
//	dict["right"];
//
//	// ����+�޸�
//	dict["left"] = "���";
//
//	// "����"
//	cout << dict["string"] << endl;
//
//	// �޸�
//	dict["right"] = "�ұ�";
//
//	string str;
//	cin >> str;
//	if (dict.count(str))
//	{
//		cout << "��" << endl;
//	}
//	else
//	{
//		cout << "����" << endl;
//	}
//}

//int main()
//{
//	//test_set3();
//	test_map2();
//
//	return 0;
//}

//int main()
//{
//	//test_map2();
//
//	return 0;
//}