#include <vector>
#include "Family.h"
using std::vector;


void print(vector<Grandpa*>& family)
{
	for (Grandpa* item : family)
	{
		/*item->Sleep();
		if (typeid(*item) == typeid(Daddy))
		{
			Daddy* res = static_cast<Daddy*>(item);
			res->Walk();
		}
		if (typeid(*item) == typeid(Son))
		{
			Son* res = static_cast<Son*>(item);
			res->Play();
		}*/
		item->Sleep();
		Daddy* res = dynamic_cast<Daddy*>(item);
		if (res != nullptr)
		{
			res->Walk();
		}
		Son* rs = dynamic_cast<Son*>(item);
		if (rs != nullptr)
		{
			rs->Play();
		}
	}
}


int main()
{
    vector<Grandpa*> family{new Grandpa("Ivan"), new Daddy("Matviy"), new Son("Pavlo")};
	print(family);
}

