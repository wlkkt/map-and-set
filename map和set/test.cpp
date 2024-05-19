#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;

//void test_set1()
//{
//	// set����Ҫ������������������
//	// ��λ�������������+ȥ��
//	set<int> s1;
//	s1.insert(1);
//	s1.insert(11);
//	s1.insert(3);
//	s1.insert(1);
//	s1.insert(4);
//	s1.insert(2);
//
//	set<int>::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		//*it = 1;//���������ܸı�
//		cout << *it << " ";
//		++it;
//	}//��ӡ���Ϊ1 2 3 4 11������ʱ���һ��ֵ�Ѿ����˾Ͳ��ٲ���
//	cout << endl;
//
//	//��������Ϊvector����
//	vector<int> v = { 3,2,8,1,10,2 };
//	set<int> s2(v.begin(), v.end());
//	for (auto e : s2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//set����ʹ��{}���г�ʼ��
//	set<int> s3 = { 3,2,8,1,10,2 };
//	for (auto e : s3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//set��ɾ��
//	s3.erase(8);
//	s3.erase(18);
//	for (auto e : s3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//set�Ĳ���ɾ��
//	auto pos = s3.find(10);
//	if (pos != s3.end())
//	{
//		cout << *pos << endl;
//		s3.erase(pos);
//	}
//	else
//	{
//		cout << "�Ҳ���" << endl;
//	}
//	for (auto e : s3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//
////set�е�lower_bound��upper_bound���ֱ�����Ѱ�������д��ڵ���x�ʹ���x��ֵ�������ã�
//void test_set2()
//{
//	std::set<int> myset;
//	for (int i = 1; i < 10; i++)
//		myset.insert(i * 10); //��set�в���10 20 30 40 50 60 70 80 90
//
//	for (auto e : myset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	auto itlow = myset.lower_bound(25);                // >= x
//	auto itup = myset.upper_bound(60);                 // > x
//	//lower_bound��������һ��ָ����ڻ���ڸ���ֵ�ĵ�һ��Ԫ�صĵ�����
//	//upper_bound��������һ��ָ����ڸ���ֵ�ĵ�һ��Ԫ�صĵ�����
//	//����ָ��30�ĵ�������ָ��70�ĵ�����
//
//
//	// [30, 70)
//	myset.erase(itlow, itup);                     //10 20 70 80 90
//
//	for (auto e : myset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//
////multiset��ʹ��
//void test_set3()
//{
//	// keyģ������
//	// ���� ����ȥ�أ���������
//	// 
//	multiset<int> s1;
//	s1.insert(1);
//	s1.insert(11);
//	s1.insert(3);
//	s1.insert(1);
//	s1.insert(4);
//	s1.insert(2);
//	s1.insert(4);
//	s1.insert(2);
//	s1.insert(1);
//	s1.insert(2);
//	s1.insert(1);
//
//	multiset<int>::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		//*it = 1;
//		cout << *it << " ";
//		++it;
//	}//��ӡ���Ϊ1 1 1 1 2 2 2 3 4 4 11
//	cout << endl;
//
//	//��ȡ���е�2
//	auto pos = s1.find(2);
//	while (pos != s1.end() && *pos == 2)
//	{
//		cout << *pos << " ";
//		++pos;
//	}
//}
//
//int main()
//{
//	test_set1();
//	test_set2();
//	test_set3();
//	return 0;
//}


void test_map1()
{
	//����map�����͵Ķ���
	map<string, string> dict;

	//���ȶ���������pair�����͵Ķ���Ȼ���ٲ���map
	pair<string, string> kv1("sort", "����");
	dict.insert(kv1);

	//�ڽ�����pair����ֱ�Ӳ���map
	dict.insert(pair<string, string>("left", "���"));

	//��ʹ��make_pair���룬�ɱ�����ʶ��make_pair�еĲ�������
	dict.insert(make_pair("right", "�ұ�"));


	//// ��ʽ����ת����std::pair<std::string, std::string> �� const std::pair<const std::string, std::string>& ��
	//pair<string, string> kv2 = { "string", "�ַ���" };
	//dict1.insert({ "string", "�ַ���" });

	////ʹ��C++11��initializer_list��map�����͵Ķ�����г�ʼ��
	//map<string, string> dict2 = { { "string", "�ַ���" }, { "right", "�ұ�" } };


	//�Լ�ֵ�Եı���
	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();//ʹ��auto���ⳤ���͵���д����ǰ����Ҫ֪�������������ʲô����ȥʡ��
	while (it != dict.end())
	{
		// iterator key�����޸� value�����޸�
		// const_iterator key�����޸� value�����޸�
	
		//it->first += 'x';//wrong
		it->second += 'x';//right�����ļ�ֵ�Ե�value

		//cout << (*it) << endl;//

		cout << it->first << ":" << it->second << endl;

		//�������ַ�ʽ��
		//cout << (*it).first << ":" << (*it).second << endl;
		//cout << it.operator->()->first << ":" << it.operator->()->second << endl;
		++it;
	}
	cout << endl;

	//C++11���÷�
	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	////C++17ʱ֧�ֵ��÷���������python�Ľṹ�󶨣���
	//for (auto& [x, y] : dict)
	//{
	//	cout << x << ":" << y << endl;
	//}
	//cout << endl;

	//map<string, string> dict2 = { {"string", "�ַ���"}, {"left", "���"},{"right", "�ұ�"} };
	map<string, string> dict2 = { kv1, {"left", "���"},{"right", "�ұ�"} };
}


void test_map2()
{
	//ͳ��һ�����ݳ��ֵĴ���
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
"ƻ��", "�㽶", "ƻ��", "�㽶","ƻ��","��ݮ", "ƻ��","��ݮ" };
	map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
		//auto it = countMap.find(e);//find�������ص���һ��������
		//if (it != countMap.end())
		//{
		//	it->second++;
		//}
		//else
		//{
		//	countMap.insert({ e, 1 });
		//}
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	//�����Ŷ����ͬkey�ļ�ֵ�ԣ�����ֵ������key����Ӧ�ĵ�����
	multimap<int, string> sortMap;
	for (auto& kv : countMap)
	{
		sortMap.insert({ kv.second, kv.first });
	}
	cout << endl;

	for (auto& kv : sortMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

//V& operator[](const K& key)
//{
//	// ���ܲ���ɹ�����ʧ�ܣ�pair��iteratorʼ��ָ��key���ڽڵ��iterator
//	pair<iterator, bool> ret = this->insert(make_pair(key, V()));
//	iterator it = ret.fisrt;
//	return it->second;
//}

void test_map3()
{
	map<string, string> dict;
	dict.insert({ "string", "�ַ���" });

	// ���루һ�㲻����ô�ã�
	dict["right"];

	// ����+�޸�
	dict["left"] = "���";

	// "����"
	cout << dict["string"] << endl;

	// �޸�
	dict["right"] = "�ұ�";

	string str;
	cin >> str;

	//����ָ��key��map�����͵Ķ����еĳ��ִ�����Ҳ���������ж�ĳ��key�Ƿ����
	if (dict.count(str))
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
}

int main()
{
	//test_map1();
	test_map2();
	//test_map3();
	return 0;
}

