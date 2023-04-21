#include<iostream>
#include<cmath>
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

template<class T>
class Vector {
	private:
		T v[100];
		int n;
	public:
		Vector() {
			
		}
		
		~Vector() {
			
		}
		
		void nhap() {
			cout<<"n = "; cin>>n;
			for (int i = 0; i<n; i++) {
				cout<<"v["<<i<<"] = ";
				cin>>v[i];
			}
		}
		
		void xuat() {
			cout<<endl<<"Vector:";
			for (int i = 0; i<n; i++) {
				cout<<" "<<v[i];
			}
		}
		
		friend istream& operator >> (istream& in, Vector<T> &vt) {
			cout<<"n = "; in>>vt.n;
			for (int i = 0; i<vt.n; i++) {
				cout<<"v["<<i<<"] = ";
				in>>vt.v[i];
			}
			return in;
		}
		
		friend ostream& operator << (ostream& out, Vector<T> &vt) {
			out<<endl<<"Vector:";
			for (int i = 0; i<vt.n; i++) {
				out<<" "<<vt.v[i];
			}
			return out;
		}
		
		void operator = (Vector<T> &vt) {
			n = vt.n;
			for (int i = 0; i<vt.n; i++) {
				this->v[i] = vt.v[i];
			}
		}
		
		bool operator == (Vector<T> &vt) {
			if (this->n == vt.n) {
				for (int i = 0; i<n; i++) {
					if (this->v[i] != vt.v[i]) {
						return false;
					}
				}
			}
			else {
				return false;
			}
			return true;
		}
		
		bool operator != (Vector<T> &vt) {
			if (this->n != vt.n) {
				return true;
			}
			else {
				for (int i = 0; i<n; i++) {
					if (this->v[i] != vt.v[i]) {
						return true;
					}
					
				}
			}
		}
		
		T operator [] (int k) {
			for (int i = 0; i<n; i++) {
				if (i == k) {
					return this->v[i];
				}
			}
		}
};

int main() {
	Vector<int> v_int1;
	cout<<endl<<"------------------\nVector int 1:"<<endl;
	cin>>v_int1;
	cout<<v_int1;
	
	Vector<int> v_int2;
	cout<<endl<<"------------------\nVector int 2:"<<endl;
	cin>>v_int2;
	cout<<v_int2;
	
	v_int1 = v_int2;
	cout<<endl<<"Vector 1 sau gan:"<<endl;
	cout<<v_int1;
	
	//vector float
	
	Vector<float> v_float1;
	cout<<endl<<"------------------\nVector float 1:"<<endl;
	cin>>v_float1;
	cout<<v_float1;
	
	cout<<endl<<"v_float1[1] = "<<v_float1[1]<<endl;
	
	//vector phan so
	
	Vector<phanSo<int> > v_ps;
	cout<<endl<<"------------------\nVector ps:"<<endl;
	cin>>v_ps;
	cout<<v_ps;
	return 0;
}
