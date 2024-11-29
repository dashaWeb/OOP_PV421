#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeToFileArray(const int* arr, const size_t& size, const string& pathFile);
void showFile(const string& pathFile);
int* readFromFileArray(size_t& size, const string& pathFile);

int main()
{
	const size_t SIZE = 5;
	int arr[SIZE]{ 4,14,-5,23,56 };
	string fname = "number.txt";
	//writeToFileArray(arr, SIZE, fname);
	showFile(fname);
	cout << "\n ==============================================\n";
	size_t size;
	int* mas = readFromFileArray(size, fname);
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] + 2 << "\t";
	}cout << endl;
}

void writeToFileArray(const int* arr, const size_t& size, const string& pathFile)
{
	ofstream file;
	file.open(pathFile/*, ios_base::out | ios_base::trunc | ios_base::app*/);
	if (!file.good()/*!file.is_open()*/)
	{
		cout << "Error. File not open" << endl;
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		file << arr[i] << "\n";
	}
	//file.close();
}

void showFile(const string& pathFile)
{
	fstream file(pathFile, ios_base::in);
	if (!file.is_open())
	{
		cout << "Error. File not open" << endl;
		return;
	}
	cout << "\n=============== file.rdbuf() ===============" << endl;
	cout << file.rdbuf() << endl;

	cout << "\n=============== line by line (getline(file,line))===============" << endl;

	file.seekg(0);

	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}

	cout << "\n=============== line by line  (file.getline(line_, 20))===============" << endl;
	//cout << file.tellg() << endl;
	//file.ignore();
	file.clear();
	file.seekg(0);
	//cout << file.tellg() << endl;
	char line_[20];
	while (file.getline(line_, 20))
	{
		cout << line_ << endl;
	}

	cout << "\n=============== read char ===============" << endl;
	file.clear();
	file.seekg(0);

	char ch;
	while (file.get(ch))
	{
		cout << ch;
	}

	cout << "\n=============== read char (ch = file.get()) != EOF ===============" << endl;
	file.clear();
	file.seekg(0);

	while ((ch = file.get()) != EOF)
	{
		cout << ch;
	}

}

int* readFromFileArray(size_t& size, const string& pathFile)
{
	size = 0;
	fstream file(pathFile, ios_base::in);
	if (!file.is_open())
	{
		cout << "Error. File not open" << endl;
		return nullptr;
	}

	int value;
	while (file >> value) ++size; // file.good()

	int* tmp = new int[size];
	file.clear();
	file.seekg(0, ios_base::beg);
	int i = 0;
	while (file >> value)tmp[i++] = value;

	return tmp;
}
