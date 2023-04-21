#include<iostream>
using namespace std;

class thiSinh {
	private:
		int SBD;
		float DToan;
		float DHoa;
		float DLy;
	public:
		thiSinh() {
			
		}
		
		~thiSinh() {
			
		}
		
		void nhap() {
			cout<<"\nNhap thong tin thi sinh: \n";
			cout<<"- SBD: "; cin>>SBD;
			cout<<"- Diem toan: "; cin>>DToan;
			cout<<"- Diem hoa: "; cin>>DHoa;
			cout<<"- Diem Ly: "; cin>>DLy;
			
		}
		
		void xuat() {
			cout<<"- SBD: "<<SBD
				<<"\tDiem toan: "<<DToan
				<<"\tDiem hoa: "<<DHoa
				<<"\tDiem Ly: "<<DLy<<endl;
			
		}
		
		float tongDiem() {
			return DToan+ DHoa+ DLy;
		}
};

class danhSachTS {
	private:
		thiSinh TS[10];
		int n;
	public:
		danhSachTS() {
			
		}
		
		~danhSachTS() {
			
		}
		
		void nhap() {
			cout<<"NHAP SO LUONG THI SINH: "; cin>>n;
			for (int i=0; i<n; i++) {
				TS[i].nhap();
			}
		}
		
		void xuat() {
			for (int i=0; i<n; i++) {
				TS[i].xuat();
			}
		}
		
		void sapXep() {
			for (int i=0; i<n-1; i++) {
				for (int j=i ; j<n; j++) {
					if (TS[i].tongDiem() > TS[j].tongDiem()) {
						thiSinh k = TS[i];
						TS[i] = TS[j];
						TS[j] = k;
					}
				}
				
			}
			cout<<"\n--------------------------------\nDANH SACH THI SINH SAU KHI SAP XEP:\n";
			this->xuat();
		}
		
		void max() {
			float max = TS[0].tongDiem();
			for (int i=1; i<n; i++) {
				if (TS[i].tongDiem() > max) {
					max = TS[i].tongDiem();
				}
			}
			
			cout<<"\n--------------------------------\nTHI SINH CO TONG DIEM CAO NHAT:\n";
			
			for (int i=0; i<n; i++) {
				if (TS[i].tongDiem() == max){
					TS[i].xuat();
				}
			}
		}
		
		void tongOver() {
			cout<<"\n--------------------------------\nTHI SINH CO TONG DIEM TREN 18:\n";
			for (int i=0; i<n; i++) {
				if (TS[i].tongDiem() > 18) {
					TS[i].xuat();
				}
			}
		}
};



int main(){
	danhSachTS DTS;
	DTS.nhap();
	cout<<"\n--------------------------------\nDANH SACH THI SINH VUA NHAP:\n";
	DTS.xuat();
	DTS.sapXep();
	DTS.max();
	DTS.tongOver();
	return 0;
}
