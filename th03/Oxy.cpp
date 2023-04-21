#include<iostream>
using namespace std;

class Oxy {
	protected:
		float x,y;
	public:
		Oxy() {
			x = 0;
			y = 0;
		}
		
		~Oxy() {
			x = 0;
			y = 0;
		}
		
		friend istream& operator >> (istream &in, Oxy &A) {
			cout<<"x = "; in>>A.x;
			cout<<"y = "; in>>A.y;
			return in;
		}
		
		friend ostream& operator << (ostream &out, Oxy &A){
			cout<<"\tx = "<<A.x<<"\ty = "<<A.y;
			return out;
		}
		
		friend Oxy TrungDiem(Oxy A, Oxy B);
};

Oxy TrungDiem(Oxy A, Oxy B) {
	Oxy kq;
	kq.x = (A.x + B.x)*0.5;
	kq.y = (A.y + B.y)*0.5;
	return kq;
}

class Oxyz: public Oxy {
	protected:
		float z;
	public:
		Oxyz() {
			z = 0;
		}
		
		~Oxyz() {
			z = 0;
		}
		
		friend istream& operator >> (istream &in, Oxyz &A) {
			cout<<"\tx = "; in>>A.x;
			cout<<"\ty = "; in>>A.y;
			cout<<"\tz = "; in>>A.z;
			return in;
		}
		
		friend ostream& operator << (ostream &out, Oxyz &A){
			cout<<"\tx = "<<A.x<<"\ty = "<<A.y<<"\tz = "<<A.z;
			return out;
		}
		
		friend Oxyz TrungDiem(Oxyz A, Oxyz B);
		
		bool check(Oxyz B) {
			if (this->x == -B.x && this->y == -B.y && this->z == -B.z) {
				return true;
			}
			
			return false;
		}
};

Oxyz TrungDiem(Oxyz A, Oxyz B) {
	Oxyz kq;
	kq.x = (A.x + B.x)*0.5;
	kq.y = (A.y + B.y)*0.5;
	kq.z = (A.z + B.z)*0.5;
	return kq;
}

int main() {
	int n;
	Oxyz O;
	cout<<"Nhap so diem: "; cin>>n;
	Oxyz A[n];
	for (int i = 0; i<n; i++) {
		cout<<"- Diem "<<i+1<<" : \n";
		cin>>A[i];
	}
	cout<<"- Danh sach diem:\n";
	for (int i = 0; i<n; i++) {
		cout<<A[i]<<endl;
	}
	for (int i = 0; i<n-1; i++) {
		for (int j = i+1; j<n; j++) {
			if (A[i].check(A[j]) == true) {
				cout<<"\nCap diem: "<<A[i]<<endl<<"\t"<<A[j]<<endl;
			}
		}
	}
	
	return 0;
}
