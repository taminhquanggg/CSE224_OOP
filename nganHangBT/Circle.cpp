#include<iostream>
using namespace std;
class Circle {
	private:
		float r;
	public:
		Circle() {
			r = 0;
		}
		
		Circle(float r) {
			this->r = r;
		}
		
		~Circle() {
			
		}
		
		void nhap() {
			cout<<"Nhap ban kinh hinh tron: ";
			cin>>r;
		}
		
		void xuat() {
			cout<<"Chu vi = "<<chuVi()<<endl;
			cout<<"Dien tich = "<<dienTich()<<endl;
		}
		
		double chuVi() {
			return 2*3.14*r;
		}
		
		double dienTich() {
			return 3.14*r*r;
		}
		
};

int main() {
	Circle c;
	c.nhap();
	c.xuat();
	return 0;
}
