#include<iostream>
using namespace std;

class POINT {
	protected:
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
		
		~POINT() {
			
		}

//		void nhap() {
//			cout<<"x = "; cin>>x;
//			cout<<"y = "; cin>>y;
//		}
		
		void xuat() {
			cout<<"Toa do: \n";
			cout<<"x = "<<x<<endl;
			cout<<"y = "<<y<<endl;
		}
		
//		void setX(float x) {
//			this->x = x;
//		}
//		
//		void setY(float y) {
//			this->y = y;
//		}
};

class TAMGIAC: public POINT {
	private:
		POINT A, B, C;
	public:
		
		TAMGIAC(float xA, float yA, float xB, float yB, float xC, float yC):A(xA, yA), B(xB, yB), C(xC, yC)  {
//			A.setX(xA); A.setY(yA);
//			B.setX(xB); B.setY(yB);
//			C.setX(xC); C.setY(yC);
		}
		
		~TAMGIAC() {
			
		}
		
		
		void xuat(){
			A.xuat();
			B.xuat();
			C.xuat();
		}
		
		
};

int main(){
	TAMGIAC ABC(1,2, 3, 4, 5, 6);
	ABC.xuat();
	return 0;
	
}
