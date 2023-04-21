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
			if (ts>0 and ms<0) {
					ts = ts * -1;
					ms = ms * -1;
				}
				
			if (ts<0 and ms<0) {
				ts = ts * -1;
				ms = ms * -1;
			}
			
			if (ts%ms ==0) {
				cout<<"Phan so: "<<ts/ms<<endl;
			}
			else {
				int ucln = UCLN(ts, ms);
				ts = ts/ucln;
				ms = ms/ucln;
				cout<<"Phan so: "<<ts<<"/"<<ms<<endl;
			}
		}
		
		phanSo operator + (phanSo a) {
			phanSo kq;
			kq.ts = this->ts*a.ms + a.ts*this->ms;
			kq.ms = this->ms*a.ms;
			return kq;
		}
		
		phanSo operator - (phanSo a) {
			phanSo kq;
			kq.ts = this->ts*a.ms - a.ts*this->ms;
			kq.ms = this->ms*a.ms;
			return kq;
			
			
		}
		
		phanSo operator * (phanSo a) {
			phanSo kq;
			kq.ts = this->ts*a.ts;
			kq.ms = this->ms*a.ms;
			return kq;
		}
		
		phanSo operator / (phanSo a) {
			phanSo kq;
			kq.ts = this->ts*a.ms;
			kq.ms = this->ms*a.ts;
			return kq;
		}
		
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
