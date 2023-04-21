#include<iostream>
using namespace std;
class sophuc{
	private:
		
		int thuc,ao;
	public:
		sophuc(){
			
		}
		~sophuc(){
			
		}
		friend istream& operator >> (istream& in, sophuc &a);
		friend ostream& operator << (ostream& out, sophuc a);
		
		sophuc operator + (sophuc b){
			sophuc kq;
			kq.thuc = this->thuc + b.thuc;
			kq.ao = this->ao + b.ao;
			return kq;
		}
			sophuc operator - (sophuc b){
			sophuc kq;
			kq.thuc = this->thuc - b.thuc;
			kq.ao = this->ao - b.ao;
			return kq;
		}

};
istream& operator >>(istream& in, sophuc &a){
	cout << "thuc: ";
	cin >> a.thuc;
	cout << "ao: ";
	cin >> a.ao;
}


int main(){
	sophuc a,b;
	cin>>a>>b;
	cout << a << b;
	sophuc cong = a + b;
}

