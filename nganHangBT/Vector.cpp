#include<iostream>
using namespace std;

class Vector {
	private:
		float *v;
		int n;
	public:
		Vector() {
			cout<<"n = "; cin>>n;
			v = new float[n];
			for (int i = 0; i<n; i++) {
				cout<<"v["<<i<<"] = "; 
				cin>>v[i];
			}
		}
		
		Vector(int n) {
			this->n = n;
			v = new float[n];
			for (int i = 0; i<n; i++) {
				cout<<"v["<<i<<"] = "; 
				cin>>v[i];
			}
		}
		
		Vector(int n, float v[]) {
			this->n = n;
			this->v = new float[n];
			for (int i = 0; i<n; i++) {
				this->v[i] = v[i];
			}
		}
		
		Vector(Vector &V) {
			this->n = V.n;
			this->v = new float[n];
			for (int i = 0; i<n; i++) {
				this->v[i] = V.v[i];
			}
		}
		
		~Vector() {
			delete[] v;
			n = 0;
		}
};

int main() {
	cout<<"-----------------VECTOR V1-----------------\n";
	Vector V1;
	cout<<"\n-----------------VECTOR V2-----------------\n";
	Vector V2(5);
}
