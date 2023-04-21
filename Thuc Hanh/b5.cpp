#include<iostream>
using namespace std;

class vector{
	private:
		float *v;
		int n;
		
	public:
		
		static int count;	
		static int getcount() {
			return count;
		}
		
		vector() {
			count++;
		}
		
		vector(int size, int *a) {
			n = size;
			v = new float[n];
			for (int i=0; i<n; i++) {
				v[i] = a[i];
			}
			count++;
		}
		
		vector(vector &a) {
			n = a.n;
			v = new float[n];
			for (int i=0; i<n; i++) {
				v[i] = a.v[i];
			}
			count++;
		}
		
		~vector(){
			
			delete[] v;
			n = 0;
		}
		
		friend istream& operator >> (istream &in, vector &vt) {
			
			cout << "n = "; cin >> vt.n;
			vt.v = new float[vt.n];
			for (int i=0; i<vt.n; i++) {
				cout << "- v["<<i<<"] = ";
				cin >> vt.v[i];
			}
			return in;
	    }
	    friend ostream& operator << (ostream &out, vector vt) {
	    	
			for (int i=0; i<vt.n; i++) {
				cout << "- v["<<i<<"] = " << vt.v[i] << "\n";
			}
			return out;
	    }
		
		void operator = (const vector& k) {
			n = k.n;
			v = new float[n];
			for (int i=0; i<n; i++) {
				v[i] = k.v[i];
			}
		}
		
		float operator [] (int i) {
			return v[i];
		}
		
		bool operator == (vector k) {
			for (int i = 0; i<n; i++) {
				if (this->v[i] != k.v[i]) {
					return false;
				}
			}
			return true;
		}
		
		bool operator != (vector k) {
			for (int i = 0; i<n; i++) {
				if (this->v[i] != k.v[i]) {
					return true;
				}
			}
			return false;
		}
		
		int length() {
			return n;
		}
		
		
};

int vector::count = 0;


int main(){
	//Nhap vector A
	cout<<"NHAP VECTOR A: \n";
	vector a;
	cin>>a;
	cout<<"\nVECTOR A: \n";
	cout<<a;
	
	//Sao chep vector a vao b
	vector b(a);
	cout<<"\nVECTOR B: \n";
	cout<<b;
	
	//Nhap vector C
	cout<<"\nNHAP VECTOR C: \n";
	vector c;
	cin>>c;
	cout<<"\nVECTOR C: \n";
	cout<<c;
	
	//So sanh A va B
	if (a==b) {
		cout<<"A = B";
	}
	else {
		cout<<"A != B";
	}
	//So sanh A va C

	if (a==c) {
		cout<<"\nA = C";
	}
	else {
		cout<<"\nA != C";
	}
	
	//in ra phan tu thu 2 cua C
	cout<<"\nc[2] = "<<c[2];
	
	//in ra do dai cua C
	cout<<"\nlength(c) = "<<c.length();
	
	//gan b = c roi in ra b
	b = c;
	cout<<"\nVECTOR B: \n";
	cout<<b;

}
