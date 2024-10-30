#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Engine {
public:
	Engine() = default;
	Engine(const string& model, const size_t& power, const double& volume)
		:model{ model }, power{ power }, volume{volume}
	{}
	void print() const;

private:
	string model = "Nomodel";
	size_t power = 0;
	double volume = 0;
};

inline void Engine::print() const {
	cout << "Model : " << model << "\t power : " << power << "\t volume : " << volume << endl;
}