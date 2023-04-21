#include<iostream>
#include<cmath>
using namespace std;

class CPoint{
	private:
		float x, y;
	public:
		CPoint() {
			x = 0;
			y = 0;
		}
		
		CPoint(float x,float y) {
			this->x = x;
			this->y = y;
		}
		
		void nhap() {
			cout<<"x = "; cin>>x;
			cout<<"y = "; cin>>y;
		}
		
		void xuat() {
			cout<<endl<<"x = "<<x;
			cout<<endl<<"y = "<<y;
		}
		
		void turnRight() {
			x = x + 1;
		}
		
		double distance(const CPoint m) {
			return sqrt(pow(this->x-m.x, 2) + pow(this->y-m.y, 2));
		}
		
		bool KT( CPoint m, CPoint n) {
			double a = distance(m);
			double b = distance(n);
			double c = m.distance(n);
			if (a+b==c || a+c==b || b+c==a) {
				return true;
			}
			return false;
		}
};
int main() {
	CPoint P1(3,0);
	CPoint P2;
	cout<<"Nhap vao P2: "<<endl;
	P2.nhap();
	cout<<"Khoang cach P1 va P2: "<<P1.distance(P2);
	P2.turnRight();
	cout<<endl<<"P2 sau khi dich chuyen:";
	P2.xuat();
	CPoint P3;
	cout<<endl<<"Nhap vao P3: "<<endl;
	P3.nhap();
	cout<<"Kiem tra 3 diem thang hang: ";
	cout<<P1.KT(P2, P3);
	return 0;
}
