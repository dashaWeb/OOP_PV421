#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

bool div_3(int number)
{
	return number % 3 == 0;
}


int inc(int number)
{
	return number * 2;
}

template <typename ContType>
void print(const ContType& cont, const string& prompt = "")
{
	cout << prompt << " :: ";
	for (const auto& el : cont)
	{
		cout << el << "\t";
	}cout << endl;
}
int main()
{
	const int SIZE = 5;
	array<int, SIZE> arr{ 40,-4,5,38,6 };
	cout << "Print Array :: ";
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}cout << endl;

	cout << "Print Array :: ";
	for (/*array<int, SIZE>::iterator*/ auto it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << "\t";
	}cout << endl;

	cout << "Print Array Reverse :: ";
	for (/*array<int, SIZE>::iterator*/ auto it = arr.rbegin(); it != arr.rend(); it++)
	{
		cout << *it << "\t";
	}cout << endl;

	print(arr, "Print Array ");
	auto it = min_element(arr.begin(), arr.end());
	cout << "Min element :: " << *it << " \t index :: " << it - arr.begin() << endl;
	*it *= -1;
	print(arr, "Print Array ");

	it = max_element(arr.begin(), arr.end());
	cout << "Max element :: " << *it << " \t index :: " << it - arr.begin() << endl;

	//arr[5] = 777;
	try
	{
		arr.at(5) = 777;
	}
	catch (const std::exception& ex)
	{
		cout << "Bad index :: " << ex.what() << endl;
	}

	cout << "\n\n ================================================\n\n";
	vector<int> v(arr.rbegin(), arr.rend());
	print(v, "Print Vector");

	v.push_back(555);
	v.insert(v.begin() + v.size() / 2, 777);

	print(v, "Print Vector after push and insert");


	cout << "\n\n ================================================\n\n";
	deque<int> d(v.begin(), v.begin() + v.size() / 2);
	print(d, "Print Deque");
	d.resize(v.size(), -1);
	print(d, "Print Deque");
	copy(v.rbegin(), v.rend() - v.size() / 2, d.begin() + d.size() / 2);
	print(d, "Print Deque");
	d.push_front(10);
	d.push_back(10);
	d.insert(d.begin() + d.size() / 2, 10);
	print(d, "Print Deque");

	int value = 10;
	auto itF = find(d.begin(), d.end(), value);
	while (itF != end(d))
	{
		cout << "Found value :: " << value << " in index " << itF - begin(d) << endl;
		itF = find(itF + 1, d.end(), value);
	}

	cout << "Count of value " << value << " = " << count(d.begin(), d.end(), value) << endl;

	itF = find_if(d.begin(), d.end(), div_3);
	if (itF != end(d))
	{
		cout << "Found value :: " << *itF << " in index " << itF - begin(d) << endl;
	}
	else {
		cout << "Number not found " << endl;
	}

	cout << "\n\n ================================================\n\n";
	vector <int> vv(d.size());
	print(d, "Print Deque");
	transform(d.begin(), d.end(), vv.begin(), inc);
	print(vv, "Print Vector");

	sort(vv.begin(), vv.end());
	print(vv, "Print Vector");
	//sort(vv.rbegin(), vv.rend());
	sort(vv.begin(), vv.end(),greater<int>());
	print(vv, "Print Vector");
	int mult = 2;
	auto fun = [&](int a, int b)->double{
		double res = (double)a / b;
		mult = 44;
		return res * mult;
	};
	cout << "fun(5,2) --> " << fun(5, 2) << endl;
	// [capture list](formal parameters)-> resultTYpe{body};
	// [=] - захопити всі локальні змінні за значенням
	// [&] - захопити всі локальні змінні за посиланням
	// [nameVariable] - захопити  змінну за значенням
	// [&nameVariable] - захопити  змінну за посиланням
	print(d, "Print Deque");
	int divisors = 5;
	itF = find_if(d.begin(), d.end(), [divisors](auto value) {return value % divisors == 0; });
	if (itF != end(d))
	{
		cout << "Found value :: " << *itF << " in index " << itF - begin(d) << endl;
	}
	else {
		cout << "Number not found " << endl;
	}
	cout << "number % 5 == 0  -->" << count_if(d.begin(), d.end(), [divisors](auto a) {return a % divisors == 0; }) << endl;

	transform(d.begin(), d.end(), d.begin(), [](auto a) {return a * 10; });
	print(d, "Print Deque");

	deque<string> colors{ "red","yellow","blue","Orange","purple","Pink" };
	auto itColors = max_element(colors.begin(), colors.end(), [](auto s1, auto s2) {return s1.size() < s2.size(); });
	cout << "Result :: " << *itColors << endl;
	int size = (*itColors).size();
	itColors = find_if(colors.begin(), colors.end(), [size](auto s) {return s.size() == size; });
	while (itColors != colors.end())
	{
		cout << *itColors << endl;
		itColors = find_if(itColors+1, colors.end(), [size](auto s) {return s.size() == size; });
	}

	print(colors, "Colors :: ");
	sort(colors.begin(), colors.end(), [](auto s1, auto s2) {return tolower(s1[0]) < tolower(s2[0]); });
	print(colors, "Colors :: ");
	sort(colors.begin(), colors.end(), [](auto s1, auto s2) {return s1.size() > s2.size(); });
	print(colors, "Colors :: ");
}
