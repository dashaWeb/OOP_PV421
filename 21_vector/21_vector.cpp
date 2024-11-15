#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printVector(const vector<T>& v)
{
	for (auto& i : v)
	{
		cout << i << "\t";
	}
	cout << endl;
}

int main()
{
    vector<int> v{ 10,20,30,40,50,60 };
    vector <double> v2{ 1.2,2.3,25.2 };
	cout << "Vector int    :: "; printVector(v);
	cout << "Vector double :: "; printVector(v2);

	cout << "Size     :: " << v.size() << endl;
	cout << "Capacity :: " << v.capacity() << endl;
	cout << "Max size :: " << v.max_size() << endl;

	for (size_t i = 0; i < 3; i++)
	{
		v.push_back(rand() % 100);
		cout << "Size :: " << v.size() << "\t Capacity :: " << v.capacity() << endl;
	}
	cout << "Vector int    :: "; printVector(v);
	v.pop_back();
	cout << "Vector int    :: "; printVector(v);

	v.insert(v.begin(), 55);
	cout << "Vector int    :: "; printVector(v);
	v.insert(v.begin() + 2, 55);
	cout << "Vector int    :: "; printVector(v);
	v.insert(v.begin() + v.size() / 2, 99);
	cout << "Vector int    :: "; printVector(v);
	v.insert(v.end(), {1,2,3});
	cout << "Vector int    :: "; printVector(v);

	v.erase(v.begin());
	cout << "Vector int    :: "; printVector(v);
	v.erase(v.begin() + 5);
	cout << "Vector int    :: "; printVector(v);
	v.erase(v.begin() + 5, v.end());
	cout << "Vector int    :: "; printVector(v);

}
