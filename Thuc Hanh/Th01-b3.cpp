#include<iostream>
#include<math.h>
using namespace std;

class tamGiac {
	private:
		double a, b, c;
	public:
		tamGiac() {
			a = 1;
			b = 1;
			c = sqrt(2);
		}
		
		~tamGiac() {
			
		}
		
		void nhap() {
			
			do {
				cout<<"Nhap thong tin tam giac: \n";
				cout<<"a = "; cin>>a;
				cout<<"b = "; cin>>b;
				cout<<"c = "; cin>>c;
			}
			while ((a+b<=c) || (a+c<=b) || (b+c<=a));

		}
		
		float dienTich(){
			double p = (a+b+c)/2;
			return sqrt(p*(p-a)*(p-b)*(p-c));
		}
		
		string KT() {
			string k;
			if (a==b && b==c ){
				k = "Deu";
			}
			else if (a==b || b==c || c==a) {
				if (sqrt(a*a + b*b) == c) {
					k = "Vuong can";
				}
				else {
					k = "Can";
				}
			}
			
			else if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (c*c + b*b == a*a)) {
				k = "Vuong";
			}
			
			else {
				k = "Thuong";
			}
			
			return k;	
		}
		
		void xuat() {
			cout<<"Dien tich: "<<this->dienTich();
			cout<<"\nTinh chat: "<<this->KT();
		}
		
};


int main(){
	
	tamGiac P;
	P.nhap();
	P.xuat();
	return 0;
}
