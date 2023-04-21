#include<iostream>
#include<math.h>
using namespace std;
class Point{
	private:
		float x, y;
	public:
		Point(){
			
		}

		~Point(){
			
		}
		
		friend istream& operator >> (istream& in, Point &a);
		friend ostream& operator << (ostream& out, Point a);
		
		double KhoangCach(Point b){
			double kq;
			kq = sqrt(pow(this->x-b.x, 2)+pow(this->y-b.y, 2));
			return kq;
		}	
		
		
};

istream& operator >> (istream& in, Point &a){
	cout<<"Nhap gia tri cua Point: ";
	cin>>a.x>>a.y;
}

ostream& operator << (ostream& out, Point a){
	cout<<"Gia tri cua Point: "<<a.x<<" "<<a.y;
	
}

class Dagiac{
	public:
		Point a[100];
		int Size;
	public:
		Dagiac(){
			
		}
		
		~Dagiac(){
			
		}
		
		friend istream& operator >> (istream& in, Dagiac &g);
		friend ostream& operator << (ostream& out, Dagiac g);
		
		bool KiemTra(){
			if (this->Size==3) {
				return true;
			}
			return false;
		}
		
		bool KiemTraCan(){
			if ((this->a[0].KhoangCach(this->a[1]) == this->a[1].KhoangCach(this->a[2]))
				|| (this->a[1].KhoangCach(this->a[2]) == this->a[2].KhoangCach(this->a[0]))
				|| (this->a[0].KhoangCach(this->a[2]) == this->a[1].KhoangCach(this->a[2]))){
					return true;
				}
			return false;
		}
		
};

istream& operator >> (istream& in, Dagiac &g){
	cout<<"Nhap gia tri da giac:\n";
	cout<<"Nhap so canh: "; cin>>g.Size;
	for (int i = 0; i<g.Size; i++){
		cout<<"Nhap chieu dau canh "<<i+1<<" : ";
		cin>>g.a[i];
	}
}

ostream& operator << (ostream& out, Dagiac g){
	for (int i = 0; i<g.Size; i++){
		cout<<"Chieu dau canh "<<i+1<<" : ";
		cout<<g.a[i]<<endl;
	}
	
}
int main()
{
	Dagiac A;
	cin>>A;
	cout<<A;
	cout<<A.KiemTra();
	cout<<A.KiemTraCan();
	return 0;
}

