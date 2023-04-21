#include<iostream>
#include<math.h>
using namespace std;

class vector {
	private:
		float *v;
		int n;
		
	public:
		static int count = 0;
		
		vector() {
			count +=1;
		}
		
		vector(int size, int *a) {
			n = size;
			v = new float[n];
			for (int i = 0; i<n; i++) {
				v[i] = a[i];
				}
			count +=1;
		}
		
		vector(vector &a) {
			n = a.n;
			v = new float[n];
			for (int i = 0; i<n; i++) {
				v[i] = a.v[i];
			}
			count +=1;
		}
		
		~vector() {
			n = 0;
			delete v[];
		}
		
		friend istream& operator >> (istream &in, Vector & a) {
			cout << "n = ";
			cin >> a.n;
			a.v = new float[a.n];
			for (int i=0; i<a.n; i++) {
				cout << "v["<<i<<"] = ";
				cin >> a.v[i];
			}
			return in;
	    }
		
		friend ostream& operator << (ostream &out, Vector & a) {
			for (int i=0; i<a.n; i++) {
				cout << "v["<<i<<"] = " << a.v[i] << "\n";
			}
			return out;
		}
		
		float operator [] (int i) {
			return v[i];
		}
		
		bool operator == (vector b) {
			for (int i=0; i<this->n; i++) {
				if (this->v[i] != b.v[i]) {
					return false;
				}
			}
			return true;
		}
		
		bool operator != (vector b) {
			for (int i=0; i<this->n; i++) {
				if (this->v[i] != b.v[i]) {
					return true;
				}
			}
			return false;
		}
		
		int length() {
			return this->n;
		}
		
};




int main(){
	vector VT;
//	cin>>VT;
	cout<<VT;
	return 0;
}
