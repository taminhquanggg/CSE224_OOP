#include<iostream>
using namespace std;


class Complex {
	private:
		int real;
		int image;
	public:
		Complex() {
			
		}
		
		~Complex() {
			
		}
		
		friend istream& operator >> (istream &in, Complex &a);
		friend ostream& operator << (ostream &out, Complex &a);
		friend Complex operator + (Complex a, Complex b);
		friend Complex operator - (Complex a, Complex b);
};

istream& operator >> (istream &in, Complex &a) {
	cout<<"real = "; cin>>a.real;
	cout<<"image = "; cin>>a.image;
}

ostream& operator << (ostream &out, Complex &a) {
	cout<<"Complex = "<<a.real<<" + "<<a.image<<"*i";
}

Complex operator + (Complex a, Complex b) {
	Complex kq;
	kq.real = a.real + b.real;
	kq.image = a.image + b.image;
	return kq;
}

Complex operator - (Complex a, Complex b) {
	Complex kq;
	kq.real = a.real - b.real;
	kq.image = a.image - b.image;
	return kq;
}

int main() {
	Complex A;
	cin>>A;
	cout<<A;
	return 0;
}
