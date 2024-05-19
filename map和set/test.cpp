#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;

//void test_set1()
//{
//	// set的主要功能是用于搜索数据
//	// 其次还可以用于排序+去重
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
//		//*it = 1;//迭代器不能改变
//		cout << *it << " ";
//		++it;
//	}//打印结果为1 2 3 4 11，插入时如果一个值已经有了就不再插入
//	cout << endl;
//
//	//可以用于为vector排序
//	vector<int> v = { 3,2,8,1,10,2 };
//	set<int> s2(v.begin(), v.end());
//	for (auto e : s2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//set可以使用{}进行初始化
//	set<int> s3 = { 3,2,8,1,10,2 };
//	for (auto e : s3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//set的删除
//	s3.erase(8);
//	s3.erase(18);
//	for (auto e : s3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//set的查找删除
//	auto pos = s3.find(10);
//	if (pos != s3.end())
//	{
//		cout << *pos << endl;
//		s3.erase(pos);
//	}
//	else
//	{
//		cout << "找不到" << endl;
//	}
//	for (auto e : s3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//
////set中的lower_bound和upper_bound，分别用于寻找数组中大于等于x和大于x的值（不常用）
//void test_set2()
//{
//	std::set<int> myset;
//	for (int i = 1; i < 10; i++)
//		myset.insert(i * 10); //向set中插入10 20 30 40 50 60 70 80 90
//
//	for (auto e : myset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	auto itlow = myset.lower_bound(25);                // >= x
//	auto itup = myset.upper_bound(60);                 // > x
//	//lower_bound函数返回一个指向大于或等于给定值的第一个元素的迭代器
//	//upper_bound函数返回一个指向大于给定值的第一个元素的迭代器
//	//返回指向30的迭代器和指向70的迭代器
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
////multiset的使用
//void test_set3()
//{
//	// key模型搜索
//	// 排序 但不去重，允许冗余
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
//	}//打印结果为1 1 1 1 2 2 2 3 4 4 11
//	cout << endl;
//
//	//获取所有的2
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
	//定义map类类型的对象
	map<string, string> dict;

	//①先定义有名的pair类类型的对象然后再插入map
	pair<string, string> kv1("sort", "排序");
	dict.insert(kv1);

	//②将匿名pair对象直接插入map
	dict.insert(pair<string, string>("left", "左边"));

	//③使用make_pair插入，由编译器识别make_pair中的参数类型
	dict.insert(make_pair("right", "右边"));


	//// 隐式类型转换（std::pair<std::string, std::string> 到 const std::pair<const std::string, std::string>& ）
	//pair<string, string> kv2 = { "string", "字符串" };
	//dict1.insert({ "string", "字符串" });

	////使用C++11的initializer_list对map类类型的对象进行初始化
	//map<string, string> dict2 = { { "string", "字符串" }, { "right", "右边" } };


	//对键值对的遍历
	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();//使用auto避免长类型的书写，但前提是要知道具体的类型是什么才能去省略
	while (it != dict.end())
	{
		// iterator key不能修改 value可以修改
		// const_iterator key不能修改 value不能修改
	
		//it->first += 'x';//wrong
		it->second += 'x';//right，更改键值对的value

		//cout << (*it) << endl;//

		cout << it->first << ":" << it->second << endl;

		//另外两种方式：
		//cout << (*it).first << ":" << (*it).second << endl;
		//cout << it.operator->()->first << ":" << it.operator->()->second << endl;
		++it;
	}
	cout << endl;

	//C++11的用法
	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	////C++17时支持的用法（类似于python的结构绑定？）
	//for (auto& [x, y] : dict)
	//{
	//	cout << x << ":" << y << endl;
	//}
	//cout << endl;

	//map<string, string> dict2 = { {"string", "字符串"}, {"left", "左边"},{"right", "右边"} };
	map<string, string> dict2 = { kv1, {"left", "左边"},{"right", "右边"} };
}


void test_map2()
{
	//统计一个数据出现的次数
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "香蕉","苹果","草莓", "苹果","草莓" };
	map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
		//auto it = countMap.find(e);//find函数返回的是一个迭代器
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

	//允许存放多个相同key的键值对，返回值类型是key所对应的迭代器
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
//	// 不管插入成功还是失败，pair中iterator始终指向key所在节点的iterator
//	pair<iterator, bool> ret = this->insert(make_pair(key, V()));
//	iterator it = ret.fisrt;
//	return it->second;
//}

void test_map3()
{
	map<string, string> dict;
	dict.insert({ "string", "字符串" });

	// 插入（一般不会这么用）
	dict["right"];

	// 插入+修改
	dict["left"] = "左边";

	// "查找"
	cout << dict["string"] << endl;

	// 修改
	dict["right"] = "右边";

	string str;
	cin >> str;

	//返回指定key在map类类型的对象中的出现次数，也可以用于判定某个key是否存在
	if (dict.count(str))
	{
		cout << "在" << endl;
	}
	else
	{
		cout << "不在" << endl;
	}
}

int main()
{
	//test_map1();
	test_map2();
	//test_map3();
	return 0;
}

