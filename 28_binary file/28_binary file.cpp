#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const size_t SIZE = 50;
struct Train
{
	size_t number;
	char destination[SIZE];
	char from[SIZE];

	void print() const
	{
		cout << "\n======== Number of train " << number << " =============\n";
		cout << "\t Place From  :: " << from << endl;
		cout << "\t Destination :: " << destination << endl;

	}
};

int main()
{
	string fname = "train.dat";
	Train train{ 100,"Odesa","Lviv" };
	Train trainArr[2]{
		{70, "Prague","Odesa"},
		{88, "Warsaw","Poltava"},
	};
	vector<Train> trainVec
	{
		{55, "Budapest","Kyiv"},
		{33, "Rivne","Kyiv"},
	};
	//train.print();

	fstream file(fname, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
	if (!file.is_open())
	{
		cout << "Error!!! File not found" << endl;
		return 0;
	}
	//write one object train
	file.write((char*)&train, sizeof(train));
	// write array trains
	file.write(reinterpret_cast<const char*>(trainArr), sizeof(trainArr));

	// write vector trains
	file.write(reinterpret_cast<const char*>(trainVec.data()), sizeof(Train) * trainVec.size());


	// read all trains way 1
	file.seekg(0);
	Train tmp;
	while (file.read((char*)&tmp, sizeof(Train)))
	{
		tmp.print();
	}

	// read all trains way 2
	//cout << file.tellg() << endl;
	file.clear();
	file.seekg(0);
	vector<Train> result;
	while (file.read(reinterpret_cast<char*>(&tmp), sizeof(Train)))
	{
		result.push_back(tmp);
	}
	cout << "Result :: ";
	for (auto& i : result)
	{
		i.print();
	}

	cout << "Number of trains :: " << count_if(result.begin(), result.end(), [](Train el) {return !strcmp(el.from, "Kyiv"); }) << endl;
	cout << endl << endl;
	// read all trains way 3
	file.clear();
	file.seekg(0,ios_base::end);
	result.clear();
	size_t lengthFile = file.tellg();
	size_t length = lengthFile / sizeof(Train);
	result.resize(length);
	file.seekg(0);
	file.read(reinterpret_cast<char*>(result.data()), lengthFile);
	cout << "Result :: ";
	for (auto& i : result)
	{
		i.print();
	}

	cout << endl << endl;
	int index = 3;
	file.seekg(index * sizeof(Train));
	file.read(reinterpret_cast<char*>(&tmp), sizeof(Train));
	cout << "Train with index 3" << endl;
	tmp.print();
}

