#include<iostream>
#include<math.h>
using namespace std;

template <class T>
class phanSo {
	private:
		T ts;
		T ms;
	public:
		phanSo() {
			
		}
		
		~phanSo() {
			
		}
		
		T UCLN(T m, T n) {
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
		
		friend istream& operator >> (istream& in, phanSo<T> &a) {
			cout<<endl<<"- Tu so: "; in>>a.ts;
			cout<<"- Mau so: "; in>>a.ms;
			return in;
		}
		
		friend ostream& operator << (ostream& out, phanSo<T> &a) {
			if (a.ts>0 and a.ms<0) {
					a.ts = a.ts * -1;
					a.ms = a.ms * -1;
				}
				
			if (a.ts<0 and a.ms<0) {
				a.ts = a.ts * -1;
				a.ms = a.ms * -1;
			}
			
			if (a.ts%a.ms ==0) {
				out<<"Phan so: "<<a.ts*1.0/a.ms<<endl;
			}
			else {
				T ucln = a.UCLN(a.ts, a.ms);
				a.ts = a.ts*1.0/ucln;
				a.ms = a.ms*1.0/ucln;
				out<<"Phan so: "<<a.ts<<"/"<<a.ms<<endl;
			}
//			out<<endl<<"\t"<<a.ts<<"/"<<a.ms;
			return out;
		}
		
		
		
		phanSo operator + (phanSo<T> a) {
			phanSo<T> kq;
			kq.ts = this->ts*a.ms + a.ts*this->ms;
			kq.ms = this->ms*a.ms;
			return kq;
		}
		
		phanSo operator - (phanSo<T> a) {
			phanSo<T> kq;
			kq.ts = this->ts*a.ms - a.ts*this->ms;
			kq.ms = this->ms*a.ms;
			return kq;
		}
		
		phanSo operator * (phanSo<T> a) {
			phanSo<T> kq;
			kq.ts = this->ts*a.ts;
			kq.ms = this->ms*a.ms;
			return kq;
		}
		
		phanSo operator / (phanSo<T> a) {
			phanSo<T> kq;
			kq.ts = this->ts*a.ms;
			kq.ms = this->ms*a.ts;
			return kq;
		}
		
		bool operator > (const phanSo<T> &a) {
			if (this->ts*1.0/this->ms > a.ts*1.0/a.ms) {
				return true;
			}
			return false;
		}
		
		void operator = (phanSo<T> a) {
			this->ts = a.ts;
			this->ms = a.ms;
		}
		
};

template <class T>
void Print(T a[], int n) {
	cout<<endl<<"Danh sach: "<<endl;
	for (int i = 0; i<n; i++) {
		cout<<a[i]<<" ";
	}
}

template <class T>
void Max(T a[], int n) {
	T max;
	max = a[0];
	for (int i = 1; i<n; i++) {
		if (a[i]>max) {
			max = a[i];
		}
	}
	
	cout<<endl<<"Max la "<<max;
}


int main(){
	int n;
	cout<<"Nhap so PS: "; cin>>n;
	phanSo<int> PS[n];
	for (int i = 0; i<n; i++) {
		cout<<"Nhap phan so "<<i<<":";
		cin>>PS[i];
	}
	Print(PS, n);
	Max(PS, n);
	
	int k;
	cout<<"Nhap so so nguyen: "; cin>>k;
	int a[k];
	for (int i = 0; i<k; i++) {
		cout<<"Nhap so "<<i<<" :";
		cin>>a[i];
	}
	Print(a, k);
	Max(a, k);
	return 0;
}
