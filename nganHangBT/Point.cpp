#include<iostream>
#include<math.h>
using namespace std;

class Point{
	private:
		int x, y;
	public:
		Point() {
			x = 0;
			y = 0;
		}
		
		~Point() {
			
		}
		
		void nhap() {
			cout<<"\tx = "; cin>>x;
			cout<<"\ty = "; cin>>y;
		}
		
		void xuat() {
			cout<<"\tx = "<<x<<"\ty = "<<y<<endl;
		}
		
		int getX() {
			return this->x;
		}
		
		int getY() {
			return this->y;
		}
		
		double range(Point k) {
			return sqrt(pow(x - k.getX(), 2) + pow(y - k.getY(), 2));
		}
};


int main() {
	int n;
	cout<<"Nhap so diem: "; cin>>n;
	Point P[n];
	for (int i=0; i<n; i++) {
		cout<<"Nhap toa do diem "<<i+1<<" : \n";
		P[i].nhap();
	}
	
	cout<<"Danh sach diem vua nhap:\n";
	for (int i=0; i<n; i++) {
		P[i].xuat();
	}
	
	double maxRange = P[0].range(P[1]);
	for (int i=1; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if (maxRange < P[i].range(P[j])) {
				maxRange = P[i].range(P[j]);
			}
		}
	}
	cout<<"Khoang cach lon nhat giua 2 diem: "<<maxRange<<endl;
	return 0;
}
