#include<iostream>
using namespace std;

class Color {
	protected:
		string TenMau;
		string MaMau;
	public:
		Color() {
			TenMau = "0";
			MaMau = "0";
		}
		
		Color(string TenMau, string MaMau) {
			this->TenMau = TenMau;
			this->MaMau = MaMau;
		}
		
		~Color(){
			TenMau = "0";
			MaMau = "0";
		}
		
		friend istream& operator >> (istream &in, Color &C) {
			cout<<"Nhap thong tin Color:\n";
			cout<<"\tTen mau: "; getline(in, C.TenMau);
			cout<<"\tMa mau: "; getline(in, C.MaMau);
			return in;
		}
		
		friend ostream& operator << (ostream &out, Color &C){
			out<<"Thong tin Color:\n";
			out<<"\tTen mau: "<<C.TenMau<<endl;
			out<<"\tMa mau: "<<C.MaMau<<endl;
			return out;
		}
		
		string getTenMau(){
			return this->TenMau;
		}
};

class Point {
	protected:
		int x;
		int y;
	public:
		Point() {
			x = 0;
			y = 0;
		}
		
		Point(int x, int y) {
			this->x = x;
			this->y = y;
		}
		
		~Point() {
			x = 0;
			y = 0;
		}
		
		friend istream& operator >> (istream &in, Point &P) {
			cout<<"Nhap thong tin Point:\n";
			cout<<"\tx = "; in>>P.x;
			cout<<"\ty = "; in>>P.y;
			return in;
		}
		
		friend ostream& operator << (ostream &out, Point &P){
			out<<"Thong tin Point:\n";
			out<<"\tx = "<<P.x<<endl;
			out<<"\ty = "<<P.y<<endl;
			return out;
		}
		
		bool CheoChinh() {
			if (this->x == this->y)
				return true;
			else 
				return false;
		}
};

class Pixel:public Color, public Point {
	public:
		Pixel() {
			TenMau = "0";
			MaMau = "0";
			x = 0;
			y = 0;
		}
		
		Pixel(string tenmau, string mamau, int x, int y) {
			this->TenMau = tenmau;
			this->MaMau = mamau;
			this->x = x;
			this->y = y;
		}
		
		~Pixel() {
			TenMau = "0";
			MaMau = "0";
			x = 0;
			y = 0;
		}
		
		friend istream& operator >> (istream &in, Pixel &pix) {
			cout<<"Nhap thong tin Color:\n";
			fflush(stdin);
			cout<<"\tTen mau: "; getline(in, pix.TenMau);
			fflush(stdin);
			cout<<"\tMa mau: "; getline(in, pix.MaMau);
			cout<<"Nhap thong tin Point:\n";
			cout<<"\tx = "; in>>pix.x;
			cout<<"\ty = "; in>>pix.y;
			return in;
		}
		
		friend ostream& operator << (ostream &out, Pixel &pix){
			cout<<"Thong tin Color:\n";
			cout<<"\tTen mau: "<<pix.TenMau<<endl;
			cout<<"\tMa mau: "<<pix.MaMau<<endl;
			cout<<"Nhap thong tin Point:\n";
			cout<<"\tx = "<<pix.x<<endl;
			cout<<"\ty = "<<pix.y<<endl;
			return out;
		}
		
		bool KiemTra() {
			if (this->getTenMau() == "Xanh" && this->CheoChinh() == true) {
				return true;
			}
			return false;
		}
};

int main() {
	int n;
	cout<<"Nhap n = "; cin>>n;
	Pixel *pix = new Pixel[n];
	for (int i = 0; i<n; i++){
		cout<<"Nhap Pixel "<<i+1<<" :\n";
		cin>>pix[i];
	}
	
	cout<<"Kiem tra:\n";
	for (int i = 0; i<n; i++){
		if (pix[i].KiemTra() == true) {
			cout<<pix[i]<<endl;
		}
	}
	
}
