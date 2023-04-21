#include<iostream>
using namespace std;

class Vector {
	private:
		int data[100];
		int size;
	public:
		Vector() {
			size = 0;
		}
		
		Vector(int size) {
			this->size = size;
		}
		
		Vector(int size, int data[100]) {
			this->size = size;
			for (int i = 0; i<size; i++) {
				this->data[i] = data[i];
			}
		}
		
		int getSize() const {
			return size;
		}
		
		int &kthElement(int k) {
			return data[k];
		}
		
		double operator * (Vector vt) {
			double s = 0;
			for (int i = 0; i<size; i++) {
				s = s + this->data[i] * vt.data[i];
			}
			return s;
		}
		
		friend double multiphy(Vector vt1, Vector vt2);
};

double multiphy(Vector vt1, Vector vt2) {
	if (vt1.size != vt2.size) return 0;
	return vt1*vt2;
}

int main() {
	int a[3] = {1, 2 ,3}, b[3] = {3, 3, 3};
	Vector vt1(3, a), vt2(3, b);
	cout<<"Tich vo huong = "<<multiphy(vt1, vt2);
	return 0;
}
