#include<iostream>
#include<string>
using namespace std;
class VIENCHUC{
	protected:
		int mvc;
		string HoTen;
		int NamSinh;
		int hsl;
	public:
		VIENCHUC(){
			
		}

		virtual void nhap(){
			
			cout <<"Ma vien chuc: ";cin >> mvc;
			fflush(stdin);
			cout <<"Ho ten: ";getline(cin,HoTen);
			
			cout <<"Nam sinh: ";cin >> NamSinh;
			cout <<"He so luong: ";cin >> hsl;
		}
		virtual void xuat(){
			cout <<mvc<<"\t"<<HoTen<<"\t"<<NamSinh<<"\t"<<hsl<<"\t";
		}
		virtual long long luong() =0;
};
class CBHANHCHINH : public VIENCHUC{
	private:
		string ChucDanh;
		int PhuCap;
	public:
		CBHANHCHINH(){
			
		}

		void nhap(){
			VIENCHUC::nhap();
			cout <<"Chuc danh: ";
			cin.ignore();
			getline(cin,ChucDanh);
			cout <<"Phu cap: ";
			cin >> PhuCap;	
		}
		void xuat(){
			VIENCHUC::xuat();
			cout <<ChucDanh<<"\t"<<PhuCap<<"\t"<<luong()<<endl;	
		}
		
		long long luong() {
			return hsl*2000000 + PhuCap;
		}
};

class GIAOVIEN : public VIENCHUC{
	private:
		string mon;
		string trinhDo;
		int thamNien;
	public:
		GIAOVIEN() {
			
		}
		
		void nhap() {
			VIENCHUC::nhap();
			cin.ignore();
			cout<<"Mon day: "; getline(cin, mon);
			cout<<"Trinh do: "; getline(cin, trinhDo);
			cout<<"Tham nien: "; cin>>thamNien;
		}
		
		void xuat() {
			VIENCHUC::xuat();
			cout<<mon<<"\t"<<trinhDo<<"\t"<<thamNien<<"\t"<<luong()<<endl;
		}
		
		long long luong() {
			return hsl*2000000*(130+thamNien)/100;
		}
		
		
};
int main(){
	
	int n;
	cout<<"Nhap so vien chuc: "; cin>>n;
	VIENCHUC *VC[100];
	for (int i=0; i<n; i++) {
		int chon;
		cout<<"Nhap thong tin vien chuc "<<i+1<<" :"<<endl;
		cout<<"Lua chon doi tuong:"<<endl;
		cout<<"1. Can bo hanh chinh"<<endl;
		cout<<"2. Giao vien"<<endl;
		cout<<"Chon doi tuong (1/2): "; cin>>chon;
		if (chon==1) {
			VC[i] = new CBHANHCHINH();
			VC[i]->nhap();
		}
		else {
			VC[i] = new GIAOVIEN();
			VC[i]->nhap();
		}
	}
	for (int i=0; i<n; i++)
		VC[i]->xuat();
	
	VIENCHUC *max;
	max = VC[0];
	for (int i=1; i<n; i++) {
		if (VC[i]->luong()>max->luong()) {
			max = VC[i];
		}
	}
	cout<<"VIEN CHUC LUONG CAO NHAT:"<<endl;
	max->xuat();
}
