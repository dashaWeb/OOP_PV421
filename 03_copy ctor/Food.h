#pragma once



class Food {
private:
	char* name = nullptr;
	size_t kkal;
	size_t weight;
	int id_ = ++counter;
	static size_t counter; // ���������� ���������� ����, ����� ��������� �� ���� �� ����������� ��� (.cpp)
public:
	// with 4 params; in 1 ctor = 4 ctor (default and other)
	static const size_t MAX_WEIGHT = 2000;
	Food(const char* name = "Nofood", const size_t& kkal = 0,const size_t & weight = 0);
	~Food();
	Food(const Food& other);
	void operator = (const Food& other); // this(left operand)a = b(other,right)
	const char* getName() const
	{
		return this->name; // ��������� �-�� � ���� ���������� ������ inline
	}
	const size_t& getKkal() const;
	const size_t& getWeight() const;

	void setName(const char* name);
	void setKkal(const size_t& kkal);
	void setWeight(const size_t& weight);

	void print() const;
	static size_t getCounter(); // �������� ����� ��������� �� � ������, ��������� � ������, �� ������ this
};

inline const size_t& Food::getKkal() const
{
	return this->kkal;
}
inline const size_t& Food::getWeight() const
{
	return this->weight;
}
inline void Food::setKkal(const size_t& kkal)
{
	this->kkal = kkal;
}

inline void Food::setWeight(const size_t& weight)
{
	if(weight < MAX_WEIGHT)
		this->weight = weight;
}
inline size_t Food::getCounter() // ��������� ����� ���� ��������� � ���������� ������
{
	return counter;
}