#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------\n"

class Point {
	double x;
	double y;
public:
	double get_x()const {
		return x;
	}
	double get_y()const {
		return y;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}

	//				  Constructors:
	/*Point() {
		x = y = double();
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x) {
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0) {
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point() {
		cout << "Destructor:\t\t" << this << endl;
	}

	//					Methods:
	double distance(const Point& other)const {
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const {
		cout << "X = " << x << "\tY = " << y << endl;
	}
	//				  Operators:
	Point& operator=(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Point& operator++() { // Prefix increment
		x++;
		y++;
		return *this;
	}
	Point& operator++(int) { // Postfix increment

		Point old = *this; //сохраняем стврое значение
		// Изменяем объект
		x++;
		y++;
		return old;
	}
};

Point operator+(const Point& left, const Point& right) {
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

double distance(const Point& A, const Point& B) {
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

int add(int a = 0, int b = 0) {
	return a + b;
}

//#define STRUCT_POINT
//#define CONTRUCTORS_CHECK
//#define DISTANCE_CHECK
//#define ASSIGMENT_CHEK

int main() {
	setlocale(LC_ALL, "Russian");

#ifdef STRUCT_POINT
	int a;	
	Point A;

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONTRUCTORS_CHECK
	Point A;		//Здесь вызывается конструктор по умолчанию (Default constructor)
//A.set_x(2);
//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;	//Single-argument constructor
	B.print();

	Point C(22, 33);
	C.print();

	Point D = C;	//Copy constructor
	D.print();

	Point E;	//Copy assigment
	E = C;
	E.print();

	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;*/
#endif // CONTRUCTORS_CHECK

#ifdef DISTANCE_CHECK

	Point A(2, 3);
	A.print();

	Point B(4, 5);
	B.print();
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B:" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A:" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B:  " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A:  " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef ASSIGMENT_CHEK
	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();

	int a, b, c;
	a = b = c = 2;
	cout << a << b << c << endl;

#endif // ASSIGMENT_CHEK

	Point A(2, 3);
	A.print();
	Point B(4, 5);
	B.print();
	Point C = A + B;
	C.print();
	C++;
	C.print();
	return 0;
}