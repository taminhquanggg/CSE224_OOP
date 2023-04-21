#include<iostream>
using namespace std;

template<class T>
T Min(T a, T b) {
	if (a>b) {
		return b;
	}
	else return a;
}

template<class T>
void min() {
	T a, b; 
	cout<<"a[1] = "; cin>>a;
	cout<<"a[2] = "; cin>>b;
	cout<<"Min: "<<Min(a, b)<<endl;
}


template<class T>
void min_Arr() {
	int n;
	cout<<"n = "; cin>>n;
	T a[n];
	cout<<"Nhap Arr: "<<endl;
	
	for (int i = 0; i<n; i++) {
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	
	T min = a[0];
	for (int i = 1; i<n; i++) {
		if (a[i]<min) {
			min = a[i];
		}
	}
	cout<<"Min Arr = "<<min;
	
}

int main() {
	cout<<"2 so nguyen: "<<endl;
	min<int>();
	cout<<"2 so thuc: "<<endl;
	min<float>();
	cout<<"2 chuoi ki tu: "<<endl;
	min<string>();
	
	cout<<"mang so nguyen: "<<endl;
	min_Arr<int>();
	cout<<endl<<"mang so thuc: "<<endl;
	min_Arr<float>();
	cout<<endl<<"mang chuoi ki tu: "<<endl;
	min_Arr<string>();
	
	
	
}
