#include<iostream>
using namespace std;

template<class T>
T Max(T a, T b) {
	if (a<b) {
		return b;
	}
	else return a;
}

template<class T>
void max() {
	T a, b; 
	cout<<"a[1] = "; cin>>a;
	cout<<"a[2] = "; cin>>b;
	cout<<"Min: "<<Max(a, b)<<endl;
}


template<class T>
void max_Arr() {
	int n;
	cout<<"n = "; cin>>n;
	T a[n];
	cout<<"Nhap Arr: "<<endl;
	
	for (int i = 0; i<n; i++) {
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	
	T max = a[0];
	for (int i = 1; i<n; i++) {
		if (a[i]>max) {
			max = a[i];
		}
	}
	cout<<"Min Arr = "<<max;
	
}

int main() {
	cout<<"2 so nguyen: "<<endl;
	max<int>();
	cout<<"2 so thuc: "<<endl;
	max<float>();
	cout<<"2 chuoi ki tu: "<<endl;
	max<string>();
	
	cout<<"mang so nguyen: "<<endl;
	max_Arr<int>();
	cout<<endl<<"mang so thuc: "<<endl;
	max_Arr<float>();
	cout<<endl<<"mang chuoi ki tu: "<<endl;
	max_Arr<string>();

	
}
