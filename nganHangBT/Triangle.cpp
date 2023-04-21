#include<iostream>
#include<math.h>
using namespace std;

class Triangle {
	private:
		double a, b, c;
	public:
		Triangle() {
			a = 1;
			b = sqrt(2);
			c = 1;
		}
		
		~Triangle() {
			
		}
		
		void nhap() {
			do {
				cout<<"Nhap 3 canh cua tam giac:\n";
				cout<<"\ta = "; cin>>a;
				cout<<"\tb = "; cin>>b;
				cout<<"\tc = "; cin>>c;
			}
			while (a+b<=c || a+c<=b || b+c<=a);
		}
		
		void xuat() {
			cout<<"Dien tich = "<<dienTich()<<endl;
			cout<<"Loai tam giac: "<<kiemTra();
		}
		
		double dienTich() {
			double p = (a+b+c)/2;
			return sqrt(p*(p-a)*(p-b)*(p-c));
		}
		
		string kiemTra() {
			string kq;
			if (a==b &&b==c) {
				kq = "Deu";
			}
			else if (a==b || b==c || a==c) {
				if ((sqrt(a*a + b*b) == c) || (sqrt(a*a + c*c) == b) || (sqrt(b*b + c*c) == a)) {
					kq = "Vuong can";
				}
				else {
					kq = "Can";
				}
			}
			else if ((a*a == b*b + c*c) ||(b*b == a*a + c*c) ||(c*c == b*b + a*a)) {
				kq = "Vuong";
			}
			else {
				kq = "Thuong";
			}
			return kq;
		}
		
};

int main() {
	Triangle T;
	T.nhap();
	T.xuat();
	return 0;
}
