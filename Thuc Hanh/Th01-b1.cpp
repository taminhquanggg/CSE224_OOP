#include<iostream>
using namespace std;

class hinhTron {
	private:
		double r;
	public:
		hinhTron() {
			
		}
		
		~hinhTron() {
			
		}
		
		void nhap() {
			while (r<=0) {
				cout<<"Ban kinh r = ";
				cin>>r;
			}
			
		}
		
		void chuVi() {
			cout<<"Chu vi = "<<2*3.14*r;
		}
		
		void dienTich() {
			cout<<"\nDien tich = "<<3.14*r*r;
		}
};

int main(){
	hinhTron C;
	C.nhap();
	C.chuVi();
	C.dienTich();
	return 0;
}
