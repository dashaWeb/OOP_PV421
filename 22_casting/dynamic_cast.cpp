#include "Person.h"
#include <vector>

int main()
{
	Person ann("Ann");
	Student denis("Denis", "Design");
	Aspirant ivan("Ivan", "Python", "AI");

	Person* ptr_denis = &denis;
	ptr_denis->print();

	Person* ptr_ivan = &ivan;
	ptr_ivan->print();

	cout << "\n======================\n\n";

	vector<Person*> peoples{ &ann, &denis, &ivan };
	for (auto& i : peoples)
	{
		i->print();
		Student* s = dynamic_cast<Student*>(i);
		if (s != nullptr)
			s->lear();
		Aspirant* a = dynamic_cast<Aspirant*>(i);
		if (a != nullptr)
			a->writeDyplom();
		cout << "\n======================\n\n";
	}
}