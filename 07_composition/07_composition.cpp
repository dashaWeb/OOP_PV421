#include <iostream>
using namespace std;

class Human {
public:
    Human() = default;
    Human(const string& name)
        :name{ name } {}
    void think() const
    {
        brain.think();
    }

    class Brain {
    public:
        void think() const
        {
            cout << "Think Brain" << endl;
        }
    };
private:
    string name;
    Brain brain;
};



int main()
{
    Human ivan("Ivan");
    ivan.think();

    
}
