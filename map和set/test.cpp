#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;

void test_set1()
{
	// key模型搜索
	// 排序+去重
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
		cout << "找不到" << endl;
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
	// key模型搜索
	// 排序 不去重，允许冗余
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
	pair<string, string> kv1("sort", "排序");
	dict.insert(kv1);
	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(make_pair("right", "右边"));
	dict.insert(make_pair("right", "xxxx"));


	// 隐式类型转换
	//pair<string, string> kv2 = { "string", "字符串" };
	dict.insert({ "string", "字符串" });

	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		// iterator key不能修改 value可以修改
		// const_iterator key不能修改 value不能修改
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

	//map<string, string> dict2 = { {"string", "字符串"}, {"left", "左边"},{"right", "右边"} };
	map<string, string> dict2 = { kv1, {"left", "左边"},{"right", "右边"} };
}

void test_map2()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "香蕉","苹果","草莓", "苹果","草莓" };
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
//	// 不管插入成功还是失败，pair中iterator始终指向key所在节点的iterator
//	pair<iterator, bool> ret = this->insert(make_pair(key, V()));
//	iterator it = ret.fisrt;
//	return it->second;
//}

//void test_map3()
//{
//	map<string, string> dict;
//	dict.insert({ "string", "字符串" });
//
//	// 插入（一般不会这么用）
//	dict["right"];
//
//	// 插入+修改
//	dict["left"] = "左边";
//
//	// "查找"
//	cout << dict["string"] << endl;
//
//	// 修改
//	dict["right"] = "右边";
//
//	string str;
//	cin >> str;
//	if (dict.count(str))
//	{
//		cout << "在" << endl;
//	}
//	else
//	{
//		cout << "不在" << endl;
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