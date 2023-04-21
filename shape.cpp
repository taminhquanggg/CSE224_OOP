#include <iostream>
using namespace std;

class Shape {
	public:
		virtual void draw() {
			cout<<"Ve hinh";
		}
		void calcArea() {
			
		}
};

class Line: public Shape {
	public:
		void draw() {
			cout<<"Ve duong thang\n";
		}
		void calcArea() {
			cout<<"Chieu dai duong thang\n";
		}
};


class Circle: public Shape {
	public:
		void draw() {
			cout<<"Ve hinh tron\n";
		}
		void calcArea() {
			cout<<"Dien tich hinh tron\n";
		}
};

class Triangle: public Shape {
	public:
		void draw() {
			cout<<"Ve tam giac\n";
		}
		void calcArea() {
			cout<<"Dien tich tam giac\n";
		}
};



int main() {
	Shape *S[3];
	int n, k;
	
	cout<<"Nhap so Shape: "; cin>>n;
	for (int i = 0; i<n; i++) {
		cout<<"Nhap loai hinh: "; 
		cin>>k;
		switch(k) {
			case 1: //static_cast<Line*>(S[i])->draw();
					S[i] = new Line();
					S[i]->draw();
					break;
			case 2: //static_cast<Circle*>(S[i])->draw();
					S[i] = new Circle();
					S[i]->draw();
					break;
			case 3: //static_cast<Triangle*>(S[i])->draw();
					S[i] = new Triangle();
					S[i]->draw();
					break;
		}
			
					
	}
	
	return 0;
}
