#include<iostream>
using namespace std;
template <class T>
class PhanSo {
	private:
		T ts;
		T ms;
	public:
		PhanSo() {
			
		}
		
		friend istream& operator >> (istream& in, PhanSo<T> &a) {
			cout<<endl<<"- Tu so: "; in>>a.ts;
			cout<<"- Mau so: "; in>>a.ms;
		}
		
		friend ostream& operator << (ostream& out, const PhanSo<T> &a) {
			out<<endl<<"\t"<<a.ts<<"/"<<a.ms;
		}
		
		bool operator > (const PhanSo<T> &a) {
			if (this->ts*1.0/this->ms > a.ts*1.0/a.ms) {
				return true;
			}
			return false;
		}
		
		void operator = (PhanSo<T> &a) {
			PhanSo<T> b;
			b.ts = this->ts;
			b.ms = this->ms;
			this->ts = a.ts;
			this->ms = a.ms;
			a.ts = b.ts;
			a.ms = b.ms;
		}
		
};

template <class T>
void Swap(T &a, T &b) {
	T k = a;
	a = b;
	b = k;
}

template <class T>
void Print(T a[], int n) {
	cout<<endl<<"Danh sach: ";
	for (int i = 0; i<n; i++) {
		cout<<a[i];
	}
}

template <class T>
void Sort(T a[], int n) {
	for (int i = 0; i<n-1; i++) {
		for (int j = i+1; j<n; j++) {
			if (a[i]>a[j]) {
				Swap(a[i], a[j]);
			}
		}
		
	}
}

int main() {
	int n;
	cout<<"Nhap so PS: "; cin>>n;
	PhanSo<int> PS[n];
	for (int i = 0; i<n; i++) {
		cout<<"Nhap phan so "<<i<<":";
		cin>>PS[i];
	}
	Print(PS, n);
	Sort(PS, n);
	Print(PS, n);
	return 0;
	
}
