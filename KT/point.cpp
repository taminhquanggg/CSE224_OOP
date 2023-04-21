#include<iostream>
#include<cmath>
using namespace std;

class CPoint{
	private:
		int x, y;
	public:
		CPoint() {

		}
		
		CPoint(int x, int y) {
			this->x = x;
			this->y = y;
		}
		
		void nhap() {
			cout<<"x = "; cin>>x;
			cout<<"y = "; cin>>y;
		}
		
		void xuat() {
			cout<<endl<<"x = "<<x<<"\ty = "<<y<<endl;
		}
		
		void turnRight() {
			x++;
		}
		
		friend double range(const CPoint k1, const CPoint k2);
		
		bool isStraight(const CPoint B, const CPoint C) {
			CPoint A;
			A.x = this->x;
			A.y = this->y;
			double a = range(A, B);
			double b = range(B, C);
			double c = range(A, C);
			if (a+b==c || a+c==b || b+c==a) {
				return true;
			}
			return false;
		}
};

double range(const CPoint k1, const CPoint k2){
	return sqrt(pow(k1.x - k2.x, 2) + pow(k1.y - k2.y, 2));
}

int main() {
	//Tao P1 
	CPoint P1(1, 2);
	//Tao P2
	CPoint P2;
	//Nhap P2
	P2.nhap();
	//Khoang cach P1 va P2
	cout<<"Khoang cach giua P1 va P2: "<<range(P1, P2);
	//Di chuyen P2 sang phai roi in ra
	P2.turnRight();
	P2.xuat();
	//Tao ra P3
	CPoint P3;
	P3.nhap();
	//In ra ket qua thang hang
	if (P1.isStraight(P2, P3)) cout<<"3 diem P1, P2, P3 thang hang";
	else cout<<"3 diem P1, P2, P3 khong thang hang";
	
	return 0;
}
