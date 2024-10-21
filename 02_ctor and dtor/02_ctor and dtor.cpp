#include <iostream>
using namespace std;

class City
{
private:
    char* name = nullptr;
    char* country = nullptr;
    size_t population = 0;

public:

    void print() const // не повинен змінювати стан обєкту(тобто жодне поле змінити не можна)
    {
        cout << "\t City       :: " << this->name << endl;
        cout << "\t Country    :: " << this->country << endl;
        cout << "\t Population :: " << this->population << endl;
        cout << endl;
    }
    City()
        :City("None")
    {
        cout << "Ctor 0 params" << endl;
    }
    City(const char* name)
        :City(name,"None")
    {
        cout << "Ctor 1 params" << endl;
    }
    City(const char* name, const char* country)
        :City(name,country,0)
    {
        cout << "Ctor 2 params" << endl;
    }
    City(const char* name, const char* country, const size_t& population)
        :population{population}
    {
        copyStr(this->name, name);
        copyStr(this->country, country);
        cout << "Ctor 3 params" << endl;
    }

    void setCity(const char* name)
    {
        if (isValid(name))
            copyStr(this->name, name);
        else
            copyStr(this->name, "None City");
    }
    void setCountry(const char* country)
    {
        if (isValid(country))
            copyStr(this->country, country);
        else
            copyStr(this->country, "None City");
    }
    inline void setPopulation(const size_t& population)
    {
        this->population = population;
    }
    inline const size_t& getPopulation() const // good style
    {
        return this->population;
    }
    inline const char* getCity() const
    {
        return this->name;
    }
    inline const char* getCountry() const
    {
        return this->country;
    }
    ~City() {
        cout << "Dtor " << endl;
        if (this->name != nullptr)
            delete[] this->name;
        if (this->country != nullptr)
            delete[] this->country;
    }
private: // strcpy_s (dest, source)
    void copyStr(char*& dest, const char* source)
    {
        if (dest != nullptr)
            delete[] dest;
        size_t size = strlen(source) + 1;
        dest = new char[size];
        strcpy_s(dest, size, source);
    }
    inline bool isValid(const char* source)
    {
        return name != nullptr and name[0] != '\0';
    }
    // inline - неведика функція, нерекурсивна, без циклів , без складних розгалужень
};

int main()
{
    //City one("Rivne", "Ukraine",243934);
    //cout << sizeof(one) << endl;
    //one.print();
    //City two;
    //two.print();

    //const char* tmp = two.getCity();
    //cout << tmp[0] << endl;
    ////tmp[0] = 'A';
    //cout << tmp << endl;
    //two.print();

    City* tmp = new City("Lviv", "Ukraine", 721301);
    tmp->print();

    delete tmp;

}

