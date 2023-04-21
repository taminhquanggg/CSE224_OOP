#include<iostream>
using namespace std;

class CanBo {
	private:
		string HoTen;
		string GioiTinh;
		int NamSinh;
		
	public:
		CanBo() {
			
		}
		
		~CanBo() {
			
		}
		
		virtual void Nhap() {
			fflush(stdin);
			cout<<"\tHo ten: "; getline(cin, HoTen);
			cout<<"\tGioi tinh: "; getline(cin, GioiTinh);
			fflush(stdin);
			cout<<"\tNam sinh: "; cin>>NamSinh;
		}
		
		virtual void Xuat() {
			cout<<"\tHo ten: "<<HoTen<<endl;
			cout<<"\tGioi tinh: "<<GioiTinh<<endl;
			cout<<"\tNam sinh: "<<NamSinh<<endl;
		}
		
		int Tuoi() {
			return 2019 - this->NamSinh;
		}
		
		virtual bool NghiHuu()=0;
		
		virtual double Luong()=0;
};

class BienChe: public CanBo {
	private:
		string DonVi;
		int HSLuong;
	public:
		BienChe() {
			
		}
		
		~BienChe() {
			
		}
		
		void Nhap() {
			cout<<"Nhap thong tin can bo bien che:\n";
			CanBo::Nhap();
			fflush(stdin);
			cout<<"\tNhap Don vi: "; getline(cin,DonVi);
			cout<<"\tNhap He so luong: ";cin>>HSLuong;
		}
		
		void Xuat() {
			cout<<"Thong tin can bo bien che:\n";
			CanBo::Xuat();
			cout<<"\tDon vi:"<<DonVi<<endl;
			cout<<"\tHe so luong:"<<HSLuong<<endl;
			if (NghiHuu()==true){
				cout<<"\tDa nghi huu"<<endl;
			}
			else {
				cout<<"\tChua nghi huu"<<endl;
			}
			cout<<"\tLuong: "<<Luong()<<endl;
		}
		
		bool NghiHuu() {
			if (Tuoi()>=60) {
				return true;
			}
			else {
				return false;
			}
		}
		
		double Luong() {
			if (NghiHuu() == true) {
				return 0.7*1310;
			}
			else {
				return 1310*HSLuong;
			}
		}
};

class HopDong: public CanBo {
	private:
		int NamCongTac;
		int HeSoThamNien;
		float MucLuong;
	public:
		HopDong() {
			
		}
		
		~HopDong() {
			
		}
		
		void Nhap() {
			cout<<"Nhap thong tin can bo hop dong:\n";
			CanBo::Nhap();
			cout<<"\tNhap nam cong tac: ";cin>>NamCongTac;
			cout<<"\tNhap he so tham nien: ";cin>>HeSoThamNien;
			cout<<"\tNhap Muc luong: ";cin>>MucLuong;
		}
		
		void Xuat() {
			cout<<"Thong tin can bo hop dong:\n";
			CanBo::Xuat();
			cout<<"\tNam cong tac: "<<NamCongTac<<endl;
			cout<<"\tHe so tham nien: "<<HeSoThamNien<<endl;
			cout<<"\tMuc luong: "<<MucLuong<<endl;
			if (NghiHuu()==true){
				cout<<"\tDa nghi huu"<<endl;
			}
			else {
				cout<<"\tChua nghi huu"<<endl;
			}
			cout<<"\tLuong: "<<Luong()<<endl;
		}
		
		bool NghiHuu() {
			if (NamCongTac>=35) {
				return true;
			}
			else {
				return false;
			}
		}
		
		double Luong() {
			if (NghiHuu() == false) {
				return MucLuong*HeSoThamNien;
			}
			else {
				return 0;
			}
		}
};

int main() {
	CanBo *CB;
	CB = new BienChe;
	CB->Nhap();
	CB->Xuat();
	
	CB = new HopDong;
	CB->Nhap();
	CB->Xuat();
	
	return 0;

	
}
