//#include <iostream>
//using namespace std;
//
//struct Point
//{
//	int x = 0, y = 0;
//	virtual void print() const
//	{
//		cout << "(" << x << "," << y << ")" << endl;
//	}
//};
//
//struct Point3D : Point
//{
//	int z = 0;
//	void print() const override
//	{
//		cout << "(" << x << "," << y << "," << z << ")" << endl;
//	}
//	void draw()
//	{
//		cout << "Testttt" << endl;
//	}
//};
//
//struct String
//{
//	string str;
//};
//int main()
//{
//
//
//	/*char symbol = 300;
//	cout << (int)symbol << endl;*/
//
//	char ch{ 0 };
//	short sh{ 0 };
//	int i{ 122 };
//	double d{ 0 };
//	// type1 ---> type
//	// static_cast<type2>(Var type1);
//	auto s = static_cast<char>(i);
//	cout << "static_cast<char>(i) --> " << s << endl;
//
//	short* ptr_sh = reinterpret_cast<short*>(&d);
//	//static_cast<double>(ptr_sh);
//	//reinterpret_cast<double>(ptr_sh);
//
//	Point point;
//	point.x = 2;
//	point.y = 3;
//	point.print();
//
//	Point3D point_3;
//	point_3.x = 1;
//	point_3.y = 2;
//	point_3.z = 3;
//	point_3.print();
//
//	//Point point_ = point_3; // ok 
//	Point& point_ = point_3; // ok 
//	point_.print();
//
//	if (typeid(point_) == typeid(Point3D))
//	{
//		Point3D res = static_cast<Point3D&>(point_);
//		res.print();
//		res.draw();
//	}
//	else {
//		cout << "Untenable casting " << endl;
//	}
//
//	//String ss = (String&)point_;
//}
