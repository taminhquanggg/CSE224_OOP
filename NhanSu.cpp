#include<iostream>
using namespace std;

class Nguoi {
	private: 
		string hoTen;
		string diaChi;
		string namSinh;
	public:
		Nguoi() {
			
		}
		
		void nhapTT() {
			cout<<"Nhap thong tin: "<<endl;
			cout<<"- Ho va ten: "; getline(cin, hoTen);
			cout<<"- Dia chi: "; getline(cin, diaChi);
			cout<<"- Nam sinh: "; getline(cin, namSinh);
		}
		
		void inTT() {
			cout<<"Thong tin: "<<endl;
			cout<<"- Ho va ten: "<<hoTen<<endl;
			cout<<"- Dia chi: "<<diaChi<<endl;
			cout<<"- Nam sinh: "<<namSinh<<endl;
			cin.ignore();
		}
};

class NhanSu:public Nguoi {
	private:
		string maNhanSu;
		int heSoChucVu;
		int heSoLuong;
		int luongCoBan;
	public:
		
		void nhapTTNhanSu() {
			nhapTT();
			cout<<"- Ma nhan su: "; getline(cin, maNhanSu);
			cout<<"- He so chuc vu: "; cin>>heSoChucVu;
			cout<<"- He so luong: "; cin>>heSoLuong;
		}
		void inTTNhanSu() {
			inTT();
			cout<<"- Ma nhan su: "<<maNhanSu<<endl;
			cout<<"- He so chuc vu: "<<heSoChucVu<<endl;
			cout<<"- He so luong: "<<heSoLuong<<endl;
			cout<<"- Tong luong: "<<tinhLuong()<<endl;
		}
		void setLuongCoBan(int lcb) {
			luongCoBan = lcb;
		}
		
		double tinhLuong() {
			return (heSoLuong+heSoChucVu)*luongCoBan-heSoLuong*luongCoBan*5/100;
		}
};

int main() {
	Nguoi a, b;
	NhanSu c, d;
	int lcb;
	
	cout<<"#LOP NGUOI:\nNGUOI A:\n";
	a.nhapTT();
	a.inTT();
	
	cout<<"\nNGUOI B:\n";
	b.nhapTT();
	b.inTT();
	
	cout<<"\n#LOP NHAN SU:\nNHAN SU C:\n";
	c.nhapTTNhanSu();
	cout<<"Nhap luong co ban cua nhan su C: "; cin>>lcb;
	c.setLuongCoBan(lcb);
	c.inTTNhanSu();
	
	cout<<"\nNHAN SU D:\n";
	d.nhapTTNhanSu();
	cout<<"Nhap luong co ban cua nhan su D: "; cin>>lcb;
	d.setLuongCoBan(lcb);
	d.inTTNhanSu();
	
	return 0;
}
