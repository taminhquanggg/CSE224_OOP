#include<iostream>
using namespace std;

class Vector {
	public:
		float *v;
		int n;
	public:
		Vector() {
			
		}
		
		void nhap() {
			cout<<"n = "; cin>>n;
			v = new float[n];
			for (int i=0; i<n; i++) {
				cout<<"v["<<i<<"] = ";
				cin>>v[i];
			}
		}
		
		void xuat() {
			for (int i=0; i<n; i++)
				cout<<v[i]<<" ";
			cout<<endl;
		}
		
		~Vector() {
			delete[] v;
			n = 0;
		}
};

class Matrix {
	private:
		int row, col;
		float m[100][100];
	public:
		Matrix() {
			
		}
		
		~Matrix() {
			
		}
		
		void nhap() {
			cout<<"row = "; cin>>row;
			cout<<"col = "; cin>>col;
			for (int i=0; i<row; i++) {
				for (int j=0; j<col; j++) {
					cout<<"m["<<i<<"]["<<j<<"] = ";
					cin>>m[i][j];
				}
			}
		}
		
		void xuat() {
			for (int i=0; i<row; i++) {
				for (int j=0; j<col; j++) {
					cout<<m[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
		void nhanMT(Vector vt) {
			Vector kq;
			kq.n = row;
			kq.v = new float[kq.n];
			if (col = vt.n) {
				for (int i=0; i<row; i++){
					kq.v[i] = 0;
					for (int j=0; j<col; j++) {
						kq.v[i] = kq.v[i] + m[i][j]*vt.v[j];
					}
				}
				kq.xuat();
			}
			else {
				cout<<"Khong ton tai phep nhan!";
			}
		}
		
};

int main() {
	Matrix m;
	m.nhap();
	m.xuat();
	
	Vector v;
	v.nhap();
	v.xuat();
	
	m.nhanMT(v);
}
