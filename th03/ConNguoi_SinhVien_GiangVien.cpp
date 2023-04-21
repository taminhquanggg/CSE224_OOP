#include<iostream>
using namespace std;

class ConNguoi {
	private:
		string HoTen;
		int Tuoi;
		string GioiTinh;
	public:
		ConNguoi() {
			
		}
		
		~ConNguoi() {
			
		}
		
		virtual void Nhap(){
			fflush(stdin);
			cout<<"\tHo ten: "; getline(cin, HoTen);
			cout<<"\tTuoi: "; cin>>Tuoi;
			fflush(stdin);
			cout<<"\tGioi tinh: "; getline(cin, GioiTinh);
		};
		virtual void Xuat(){
			cout<<"\tHo ten: "<<HoTen;
			cout<<"\tTuoi: "<<Tuoi;
			cout<<"\tGioi tinh: "<<GioiTinh;
		};
		virtual bool KhenThuong()=0;
};

class Sinhvien:public ConNguoi {
	private:
		string Lop;
		float DTB;
	public:
		Sinhvien() {
			
		}
		
		~Sinhvien() {
			
		}
		
		void Nhap() {
			ConNguoi::Nhap();
			fflush(stdin);
			cout<<"\tLop: "; getline(cin, Lop);
			cout<<"\tDTB: "; cin>>DTB;
		}
		
		void Xuat() {
			ConNguoi::Xuat();
			cout<<"\tLop: "<<Lop;
			cout<<"\tDTB: "<<DTB<<endl;
		}
		
		bool KhenThuong() {
			if (DTB>=8.0) {
				return true;
			}
			else {
				return false;
			}
		}
};

class GiangVien: public ConNguoi {
	private:
		string BoMon;
		int SoBaiBao;
	public:
		GiangVien() {
			
		}
		
		~GiangVien() {
			
		}
		
		void Nhap() {
			ConNguoi::Nhap();
			cout<<"\tBo mon: "; getline(cin, BoMon);
			cout<<"\tSo bai bao: "; cin>>SoBaiBao;
			
		}
		
		void Xuat() {
			ConNguoi::Xuat();
			cout<<"\tBo mon: "<<BoMon;
			cout<<"\tSo bai bao: "<<SoBaiBao<<endl;
		}
		
		bool KhenThuong() {
			if (SoBaiBao>=1) {
				return true;
			}
			else {
				return false;
			}
		}
};

int main() {
	ConNguoi *P;
	int m,n;
	cout<<"Nhap so sinh vien: "; cin>>n;
	ConNguoi *SV[n];
	for (int i = 0; i<n; i++) {
		cout<<"Nhap thong tin sinh vien "<<i+1<<" : \n";
		SV[i] = new Sinhvien;
		SV[i]->Nhap();
	}
	
	cout<<"Thong tin sinh vien : \n";
	for (int i = 0; i<n; i++) {
		SV[i]->Xuat();
	}
	
	cout<<"Danh sach sinh vien duoc khen thuong: \n";
	for (int i = 0; i<n; i++) {
		if (SV[i]->KhenThuong()==true) {
			SV[i]->Xuat();
		}	
	}
	
	cout<<"Nhap so giang vien: "; cin>>m;
	ConNguoi *GV[m];
	for (int i = 0; i<m; i++) {
		cout<<"Nhap thong tin giang vien "<<i+1<<" : \n";
		GV[i] = new GiangVien;
		GV[i]->Nhap();
	}
	
	cout<<"Thong tin giang vien : \n";
	for (int i = 0; i<m; i++) {
		GV[i]->Xuat();
	}
	
	cout<<"Danh sach giang vien duoc khen thuong: \n";
	for (int i = 0; i<m; i++) {
		if (GV[i]->KhenThuong()==true) {
			GV[i]->Xuat();
		}
	}
	
	
}
