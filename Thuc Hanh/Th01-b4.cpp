#include<iostream>
#include<math.h>
using namespace std;

class vector {
	private:
		float *v;
		int n;
		static int count;
	public:
		vector() {
			
		}
		
		vector(int size, int *a) {
			
		}
		
		vector(vector &a) {
			
		}
		
		~vector() {
			
		}
		
		friend istream& operator >> (istream& in, vector &v);
		friend ostream& operator << (ostream& out, vector k);
		
		
		
		
		
		
};


int main(){
	phanSo PS1, PS2;
	PS1.nhap();
	PS1.xuat();
	PS2.nhap();
	PS2.xuat();
	
	cout<<"Cong: ";
	phanSo PSTong = PS1 + PS2;
	PSTong.xuat();
	
	cout<<"Tru: ";
	phanSo PSHieu = PS1 - PS2;
	PSHieu.xuat();
	
	cout<<"Nhan: ";
	phanSo PSTich = PS1 * PS2;
	PSTich.xuat();
	
	cout<<"Chia: ";
	phanSo PSThuong = PS1 / PS2;
	PSThuong.xuat();
	return 0;
}
