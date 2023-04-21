#include<iostream>
using namespace std;

class VeMayBay {
	private:
		string TenChuyen;
		string NgayBay;
		double GiaVe;
	public:
		VeMayBay() {
			TenChuyen = "";
			NgayBay = "";
			GiaVe = 0;
		}
		~VeMayBay() {
			TenChuyen = "";
			NgayBay = "";
			GiaVe = 0;
		}
		
		void Nhap() {
			cout<<"\tNhap thong tin ve:\n";
			fflush(stdin);
			cout<<"\t\tTen chuyen: "; getline(cin,TenChuyen);
			fflush(stdin);
			cout<<"\t\tNgay bay: "; getline(cin,NgayBay);
			fflush(stdin);
			cout<<"\t\tGia ve: "; cin>>GiaVe;
		}
		
		void Xuat() {
			cout<<"\tThong tin ve:\n";
			cout<<"\t\tTen chuyen: "<<TenChuyen<<endl;
			cout<<"\t\tNgay bay: "<<NgayBay<<endl;
			cout<<"\t\tGia ve: "<<GiaVe<<endl;
		}
		
		double getGiaVe() {
			return this->GiaVe;
		}
};

class Nguoi {
	private:
		string HoTen;
		string GioiTinh;
		int Tuoi;
	public:
		Nguoi() {
			
		}
		
		~Nguoi() {
			
		}
		
		
		void Nhap() {
			cout<<"Nhap thong tin hanh khach:\n";
			fflush(stdin);
			cout<<"\tHo ten: "; getline(cin, HoTen);
			
			cout<<"\tGioi tinh: "; getline(cin, GioiTinh);
			fflush(stdin);
			cout<<"\tTuoi: "; cin>>Tuoi;
		}
		
		void Xuat() {
			cout<<"\nThong tin hanh khach:\n";
			cout<<"\tHo ten: "<<HoTen<<endl;
			cout<<"\tGioi tinh: "<<GioiTinh<<endl;
			cout<<"\tTuoi: "<<Tuoi<<endl;
		}
};

class HanhKhach : public Nguoi {
	private:
		VeMayBay ve[1000];
		int SoLuong;
	public:
		HanhKhach(){
			
		}
		
		~HanhKhach(){
			
		}
		
		void Nhap() {
			Nguoi::Nhap();
			cout<<"\tSo luong ve: "; cin>>SoLuong;
			for (int i = 0; i<SoLuong; i++) {
				ve[i].Nhap();
			}
		}
		
		void Xuat() {
			Nguoi::Xuat();
			cout<<"\tSo luong ve: "<<SoLuong<<endl;
			for (int i = 0; i<SoLuong; i++) {
				ve[i].Xuat();
				cout<<endl;
			}
			cout<<"\tTong tien: "<<TongTien()<<endl;
		}
		
		double TongTien() {
			double tong = 0;
			for (int i = 0; i<SoLuong; i++) {
				tong = tong + ve[i].getGiaVe();
			}
			return tong;
		}
};

int main() {
	int n;
	cout<<"Nhap so hanh khach: "; cin>>n;
	HanhKhach hk[n];
	for (int i = 0; i<n; i++) {
		hk[i].Nhap();
	}
	
	for (int i = 0; i<n; i++) {
		hk[i].Xuat();
	}
	
	cout<<"Danh sach sau sap xep: "<<endl;
	
	for (int i = 0; i<n-1; i++) {
		for (int j=i+1; j<n; i++) {
			if (hk[i].TongTien()<hk[j].TongTien()) {
				HanhKhach k = hk[i];
				hk[i] = hk[j];
				hk[j] = k;
			}
		}
	}
	
	
	for (int i = 0; i<n; i++) {
		hk[i].Xuat();
	}
	
}
