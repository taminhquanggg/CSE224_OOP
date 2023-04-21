#include<iostream>
using namespace std;
class SoPhuc{
	private:
		int a, b;
	public:
		SoPhuc(){
			
		}

		~SoPhuc(){
			
		}
		
		friend istream& operator >> (istream& in, SoPhuc &k);
		friend ostream& operator << (ostream& out, SoPhuc k);
		
		SoPhuc operator + (SoPhuc m){
			SoPhuc kq;
			kq.a = this->a + m.a;
			kq.b = this->b + m.b;
			return kq;
		}
		
		SoPhuc operator - (SoPhuc m){
			SoPhuc kq;
			kq.a = this->a - m.a;
			kq.b = this->b - m.b;
			return kq;
		}
		
		friend SoPhuc operator * (SoPhuc k, SoPhuc m);
};

istream& operator >> (istream& in, SoPhuc &k){
	cout<<"Nhap gia tri so phuc:\n";
	cout<<"Phan thuc: "; cin>>k.a;
	cout<<"Phan ao: "; cin>>k.b;
}

ostream& operator << (ostream& out, SoPhuc k){
	cout<<"Gia tri so phuc: "<<k.a<<"+"<<k.b<<"i\n";
	
}

SoPhuc operator * (SoPhuc k, SoPhuc m){
	SoPhuc kq;
	kq.a = k.a*m.a - k.b*m.b;
	kq.b = k.a*m.b + k.b*m.a;
	return kq;
}

class Dagiac{
	public:
		Point a[100];
		int Size;
	private:
		Dagiac(){
			
		}
		
		~Dagiac(){
			
		}
		
		friend istream& operator >> (istream& in, Dagiac &a);
		friend ostream& operator << (ostream& out, Dagiac a);
		
};

istream& operator >> (istream& in, Dagiac &a){
	cout<<"Nhap gia tri da giac:\n";
	cout<<"Nhap so canh: "; cin>>Dagiac.Size;
	for (int i = 0; i<Dagiac.Size; i++){
		cout<<"Nhap chieu dau canh "<<i+1<<" :";
		cin>>Dagiac.Point[i];
	}
}

//ostream& operator << (ostream& out, Dagiac a){
//	cout<<"Gia tri so phuc: "<<k.a<<"+"<<k.b<<"i\n";
//	
//}
int main()
{
	Dagiac A;
	cin>>A;
	return 0;
}
