#include <iostream>
#include <tuple>
#include <initializer_list>
using namespace std;

int** createMatrix(const size_t& row, const size_t col);
void fillMatrix(int** arr, const size_t& row, const size_t col, int min = 1, int max = 20);
void printMatrix(int** arr, const size_t& row, const size_t col);
pair<int, int> min_max(int** arr, const size_t& row, const size_t col);

using Product = tuple<string, double, size_t>;

int main()
{

	pair<int, string> p{ 1, "one" };
	pair<int, string> p2{ 2, "two" };


	cout << "Pair #1 --->  first :: " << p.first << "\t second :: " << p.second << endl;
	cout << "Pair #2 --->  first :: " << p2.first << "\t second :: " << p2.second << endl;

	p.swap(p2);
	cout << endl;
	cout << "Pair #1 --->  first :: " << p.first << "\t second :: " << p.second << endl;
	cout << "Pair #2 --->  first :: " << p2.first << "\t second :: " << p2.second << endl;

	int row = 3, col = 4;
	int** arr = createMatrix(row, col);
	fillMatrix(arr, row, col);
	printMatrix(arr, row, col);
	//pair<int, int> res = min_max(arr, row, col);
	auto res = min_max(arr, row, col);
	cout << "Min :: " << res.first << endl;
	cout << "Max :: " << res.second << endl;

	//tuple<string, double, size_t> product { "Bread",17.5,100 };
	Product product { "Bread",17.5,100 };
	cout << "Product #1 --> " << get<0>(product) << "\t" << get<1>(product) << "\t" << get<2>(product) << endl;


	initializer_list<int> list{ 10,20,30,40,50,60,70 };
	cout << "List size --> " << list.size() << endl;
	cout << "First element --> " << *list.begin() << endl;
	cout << "Last element --> " << *(list.end()-1) << endl;

	cout << "================ All list (for and [])" << endl;
	for (size_t i = 0; i < list.size(); i++)
	{
		cout << list.begin()[i] << "\t";
	}cout << endl;

	cout << "================ All list (for and pointer)" << endl;
	for (auto ptr = list.begin(); ptr != list.end(); ptr++)
	{
		cout << *ptr << "\t";
	}cout << endl;

	cout << "================ All list (range for)" << endl;
	for (auto& item : list)
	{
		cout << item << "\t";
	}cout << endl;
}

int** createMatrix(const size_t& row, const size_t col)
{
	int** tmp = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = new int[col];
	}
	return tmp;
}

void fillMatrix(int** arr, const size_t& row, const size_t col, int min, int max)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = min + rand() % (max - min + 1);
		}
	}
}

void printMatrix(int** arr, const size_t& row, const size_t col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}cout << endl;
	}
}

pair<int, int> min_max(int** arr, const size_t& row, const size_t col)
{
	int min = arr[0][0];
	int max = arr[0][0];
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (max < arr[i][j])
				max = arr[i][j];

			if (min > arr[i][j])
				min = arr[i][j];
		}
	}
	return { min,max };
}
