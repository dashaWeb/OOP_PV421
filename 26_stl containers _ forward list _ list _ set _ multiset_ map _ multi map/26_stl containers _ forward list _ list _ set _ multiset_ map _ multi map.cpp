#include <iostream>
#include <forward_list>
#include <list>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

template <typename ContType>
void print(const ContType& cont, const string& prompt = "")
{
	cout << prompt << " :: ";
	for (const auto& el : cont)
	{
		cout << el << "\t";
	}cout << endl;
}

void print(const map<int, string>& cont, const string& prompt = "")
{
	cout << prompt << endl;
	for (const auto& el : cont)
	{
		cout << "[" << el.first << "] - " << el.second << "\n";
	}cout << endl;
}

void print(const multimap<string, string>& cont, const string& prompt = "")
{
	cout << prompt << endl;
	for (const auto& el : cont)
	{
		cout << "[" << el.first << "] - " << el.second << "\n";
	}cout << endl;
}
int main()
{
	cout << "\n\n ==========================FORWARD LIST===================================\n\n";
	forward_list<int> fl{ 10,33,23,45,-1,10,100,-55,-88,2,47,50,11 };
	print(fl, "Print fwd list ");
	fl.push_front(5);
	print(fl, "Print fwd list ");
	int index = 2;
	auto it = fl.begin();
	advance(it, index);
	fl.insert_after(it, 77);
	print(fl, "Print fwd list ");
	int value = 10;

	//cout << "Enter number :: "; cin >> value;
	it = find(fl.begin(), fl.end(), value);
	if (it != fl.end())
	{
		cout << value << " was found" << endl;
		auto tmp = it;
		tmp++;
		if (tmp != fl.end())
		{
			cout << "will be deleted " << *tmp << endl;
			fl.erase_after(it);
		}
		else {
			cout << "Erase after " << value << " it is last element" << endl;
		}
	}
	print(fl, "Print fwd list ");
	cout << "\n\n =============================================================\n\n";
	fl.sort();
	print(fl, "Sorted fw list ");
	fl.sort(greater<int>()); // numb1 < numb2;
	print(fl, "Sorted fw list desc ");

	fl.remove(value); // 10;
	print(fl, "Sorted fw list remove ");

	int bound = 50;
	fl.remove_if([bound](const auto& el) {return el < bound; });
	print(fl, "Sorted fw list remove_if ");

	cout << "\n\n ============================= LIST ================================\n\n";
	{
		list<string> color{ "red", "green", "pink", "gold", "cyan" };
		print(color, "Print list");
		color.push_front("black");
		color.push_back("yellow");
		auto it = color.begin();
		advance(it, 2);
		color.insert(it, "lime");
		print(color, "Print list");

		char letter = 'e';
		color.remove_if([letter](auto s) {return s.find(letter) != -1; });
		print(color, "Print list");

	}
	cout << "\n\n ============================= MULTI SET ================================\n\n";
	{
		multiset<int> ms{ 10,12,10,50,40,80,-45,2,-78,2,33,10,10,11,14 };
		//multiset<int,greater<int>> ms{ 10,12,10,50,40,80,-45,2,-78,2,33,10,10,11,14 }; // desc
		print(ms, "Print multi set");
		for (auto it = ms.begin(); it != ms.end(); it++)
		{
			cout << *it << "\t";
		} cout << endl;
		for (auto it = ms.rbegin(); it != ms.rend(); it++)
		{
			cout << *it << "\t";
		} cout << endl;
		int key = 10;
		cout << "Min :: " << *ms.begin() << endl;
		cout << "Max :: " << *ms.rbegin() << endl;
		cout << "Count :: " << ms.count(key) << endl;
		print(ms, "Print multi set");
		auto it = find(ms.begin(), ms.end(), key);
		if (it != ms.end())
		{
			/// ms.erase(key);
			//ms.erase(it)
			//ms.erase(it, ms.end());
			auto tmp = it;
			advance(tmp, 5);
			ms.erase(it, tmp);

		}
		print(ms, "Print multi set");

		cout << "\n\n ============================= SET ================================\n\n";
		set<int> s1(ms.begin(), ms.end());
		print(s1, "Print Set");
		set<int> s2{ 2,10,45,78,12,14,33 };
		print(s2, "Print Set");
		ostream_iterator<int> outIt(cout, "\t");
		cout << "\n\n ============================= UNION ================================\n\n";
		set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), outIt);
		cout << "\n\n ============================= INTERSECTION ================================\n\n";
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), outIt);
		cout << "\n\n ============================= DIFFERENCE (s1 - s2) ================================\n\n";
		set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), outIt);
		cout << "\n\n ============================= DIFFERENCE (s2 - s1) ================================\n\n";
		set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), outIt);
	}
	cout << "\n\n ============================= MAP ================================\n\n";
	{
		map<int, string> people
		{
			pair<int, string>(555,"Anna"),
			make_pair(333,"Ivan"),
			{222,"Matviy"}
		};
		print(people);

		people.insert({ 888,"Den" });
		people.insert({ 888,"Tom" });
		print(people);


		people[555] = "Olia";
		people[777] = "Taras";
		print(people);

		int key = 1000;
		//cout << " Test by key --> " << people[key] << endl;
		try
		{
			cout << " Test by key --> " << people.at(key) << endl;

		}
		catch (const std::exception& ex)
		{
			cout << "\t\t Not find key " << key << endl;
			cout << "Error message :: " << ex.what() << endl;
		}
		print(people);
		key = 888;
		auto it = people.find(key);
		if (it != people.end())
		{
			cout << "Was found id " << key << " in index " << distance(people.begin(), it) << endl;
			people.erase(it);
			print(people);
		}
		else {
			cout << "Not found id" << endl;
		}

		key = 333;
		cout << "\n\n ============================= Lower_bound >= key ================================\n\n";
		it = people.lower_bound(key);
		if (it != people.end())
		{
			cout << "Found person with id >= " << key << "\t Name :: " << it->second << endl;
		}
		cout << "\n\n ============================= Upper_bound >= key ================================\n\n";
		it = people.upper_bound(key);
		if (it != people.end())
		{
			cout << "Found person with id > " << key << "\t Name :: " << it->second << endl;
		}

		cout << "Min id " << people.begin()->first << "\t Name :: " << people.begin()->second << endl;
		cout << "Max id " << people.rbegin()->first << "\t Name :: " << people.rbegin()->second << endl;
	}
	cout << "\n\n ============================= MULTI MAP ================================\n\n";
	{
		multimap<string, string> lib{
			{"J.K. Rowling","Harry Potter and the Philosopher's Stone"},
			{"David North","Battlefield Reclaimer"},
			{"J.K. Rowling","Harry Potter and the Chamber of Secrets"},
			{"J.K. Rowling","Harry Potter and the Prisoner of Azkaban"},
			{"J.K. Rowling","Harry Potter and the Order of the Phoenix"},
		};
		print(lib);
		lib.insert({ "LJ Andrews" ,"Crown of Blood and Ruin" });
		//lib["David North"];
		//lib.erase("J.K. Rowling");
		string author = "J.K. Rowling";
		auto p = lib.equal_range(author);
		if (p.first != lib.end())
		{
			cout << "\n\n _________________ Found books of ____ " << p.first->first << endl;
			for (auto it = p.first; it != p.second; it++)
			{
				cout << "\t\t " << it->second << endl;
			}
		}
		print(lib);
	}

}

 //{"Iron Flame", "Rebecca Yarros", "Entangled: Red Tower Books", "Fantasy"},
 //{ "The Ever King","LJ Andrews","Victorious","Fantasy" },
 //{ "Harry Potter and the Philosopher's Stone","J.K. Rowling","Pottermore Publishing","Children's Fantasy" },
 //{ "Harry Potter and the Chamber of Secrets","J.K. rowling","Pottermore Publishing","Children's Fantasy" },
 //{ "Harry Potter and the Prisoner of Azkaban","J.K. Rowling","Pottermore Publishing","Children's Fantasy" },
 //{ "Harry Potter and the Order of the Phoenix","J.K. Rowling","Pottermore Publishing","Children's Fantasy" },
 //{ "Harry Potter and the Half-Blood Prince","J.K. Rowling","Pottermore Publishing","Children's Fantasy" },
 //{ "Crown of Blood and Ruin","LJ Andrews","Victorious","Dark Fantasy Horror" },
 //{ "Battlefield Reclaimer","David North","High Peak Publishing","Fiction" },
 //{ "Swords of Empire","Robert Ryan","Trotting Fox Press","Fantasy" },