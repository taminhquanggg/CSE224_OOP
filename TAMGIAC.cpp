#include<iostream>
using namespace std;

class POINT {
	private:
		float x, y;
	public:
		POINT() {
			x = 0;
			y = 0;
		}
		
		POINT(float x, float y) {
			this->x = x;
			this->y	= y;
		}
		
		~POINT ();
		
		
		
		void nhap() {
			cout<<"x = "; cin>>x;
			cout<<"y = "; cin>>y;
		}
		
		void xuat() {
			cout<<"x = "<<x<<endl;
			cout<<"y = "<<y<<endl;
		}
};

class TAMGIAC: public POINT {
	private:
		POINT A, B, C;
	public:
		TAMGIAC() {
			
		}
		
		
		void nhap() {
			A.nhap();
			B.nhap();
			C.nhap();
		}
		
		void xuat(){
			A.xuat();
			B.xuat();
			C.xuat();
		}
		
		
};

int main(){
	TAMGIAC ABC;
	ABC.nhap();
	ABC.xuat();
	return 0;
	
}
