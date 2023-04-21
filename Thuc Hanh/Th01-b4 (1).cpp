#include<iostream>
#include<math.h>
using namespace std;

class phanSo {
	private:
		int ts, ms;
	public:
		phanSo() {
			
		}
		
		~phanSo() {
			
		}
		
		void nhap() {
			while (ms==0) {
				cout<<"TS: "; cin>>ts;
				cout<<"MS: "; cin>>ms;
			}
			
		}
		
		int UCLN(int m, int n) {
			m = abs(m);
			n = abs(n);
			if (m == 0 && n == 0)
			    return 1;
			    
			while (m != n) {
				if (m > n)
				    m -= n;
				else n -= m;
			}
			return m;
		}
			
		void xuat() {
			int ucln = UCLN(ts, ms);
			
			
			cout<<"Phan so: "<<ts<<"/"<<ms<<endl;
		}
		
		phanSo operator +(phanSo a) {
			phanSo kq;
			kq.ts = this->ts*a.ms + a.ts*this->ms;
			kq.ms = this->ms*a.ms;
			int ucln = UCLN(kq.ts, kq.ms);
			kq.ts = kq.ts/ucln;
			kq.ms = kq.ms/ucln;
			return kq;
		}
		
		phanSo operator - (phanSo a) {
			phanSo kq;
			kq.ts = this->ts*a.ms - a.ts*this->ms;
			kq.ms = this->ms*a.ms;
			int ucln = UCLN(kq.ts, kq.ms);
			kq.ts = kq.ts/ucln;
			kq.ms = kq.ms/ucln;
			return kq;
		}
		
		phanSo operator * (phanSo a) {
			phanSo kq;
			kq.ts = this->ts*a.ts;
			kq.ms = this->ms*a.ms;
			int ucln = UCLN(kq.ts, kq.ms);
			kq.ts = kq.ts/ucln;
			kq.ms = kq.ms/ucln;
			return kq;
		}
		
		phanSo operator / (phanSo a) {
			phanSo kq;
			phanSo t;
			t.ts = a.ms;
			t.ms = a.ts;
			kq.ts = this->ts*t.ts;
			kq.ms = this->ms*t.ms;
			int ucln = UCLN(kq.ts, kq.ms);
			kq.ts = kq.ts/ucln;
			kq.ms = kq.ms/ucln;
			return kq;
		}
		
		
		
		
};


int main(){
	phanSo PS1, PS2;
	PS1.nhap();
	PS1.xuat();
	PS2.nhap();
	PS2.xuat();
	
//	cout<<"Cong: ";
//	phanSo PSTong = PS1 + PS2;
//	PSTong.xuat();
//	
//	cout<<"Tru: ";
//	phanSo PSHieu = PS1 - PS2;
//	PSHieu.xuat();
//	
//	cout<<"Nhan: ";
//	phanSo PSTich = PS1 * PS2;
//	PSTich.xuat();
//	
//	cout<<"Chia: ";
//	phanSo PSThuong = PS1 / PS2;
//	PSThuong.xuat();
	return 0;
}
