#include<iostream>
using namespace std;

int m, n;

class MonHoc {
	private:
		static int mm;
		int maMon;
		string tenMon;
		int tongSoTiet;
		string loaiMonHoc;
	public:
		MonHoc() {
			
		}
		friend istream& operator >> (istream& in, MonHoc &a) {
			cout<<"- Ma mon: "<<++mm<<endl;
			a.maMon = mm;
			cin.ignore();
			
			cout<<"- Nhap ten mon: "; getline(in, a.tenMon);
			cout<<"- Nhap tong so tiet: "; in>>a.tongSoTiet;
		
			cout<<"- Danh sach mon hoc:\n";
			cout<<"\t1. Dai cuong.\n";
			cout<<"\t2. Co so nganh.\n";
			cout<<"\t3. Chuyen nganh bat buoc.\n";
			cout<<"\t4. Chuyen nganh tu chon.\n";
			int chon;
			cout<<"- Chon mon hoc theo ma (1/2/3/4): "; cin>>chon;
			switch (chon) {
				case 1:
					a.loaiMonHoc = "Dai cuong";
					break;
				case 2:
					a.loaiMonHoc = "Co so nganh";
					break;
				case 3:
					a.loaiMonHoc = "Chuyen nganh bat buoc";
					break;
				case 4:
					a.loaiMonHoc = "Chuyen nganh tu chon";
					break;
				default:
					a.loaiMonHoc = "trong";
			}
			
			return in;
		}
		friend ostream& operator << (ostream& out, const MonHoc &a) {
			out<<"\n\t#"<<a.maMon<<"\t"<<a.tenMon<<"\t"<<a.tongSoTiet<<"\t"<<a.loaiMonHoc;
			return out;
		}	
};

int MonHoc::mm = 99;

//Khai bao mang mon hoc
MonHoc MH[100];

void input_MH() {
	cout<<"Nhap vao so mon hoc: "; cin>>m;
	for (int i = 0; i<m; i++) {
		cout<<"------------------";
		cout<<endl<<"Thong tin mon hoc thu "<<i+1<<" :"<<endl;
		cin>>MH[i];
	}
}

void output_MH() {
	cout<<"------------------";
	cout<<endl<<"Thong tin mon hoc :";
	for (int i = 0; i<m; i++) {
		cout<<MH[i];
	}
}


class Nguoi {
	protected:
		string hoTen;
		string diaChi;
		string SDT;
	public:
		Nguoi() {
			
		}
	
};

class SVDK: public Nguoi {
	private:
		static int msv;
		int MaSV;
		string Lop;
		int SoMonDK;
		int MaMonDK[100];
	public:
		SVDK() {
			
		}
		
		friend istream& operator >> (istream& in, SVDK &a) {
			cout<<"- Ma SV: "<<++msv<<endl;
			a.MaSV = msv;
			cin.ignore();
			cout<<"- Nhap ho ten SV: "; getline(in, a.hoTen);
			cout<<"- Nhap dia chi SV: "; getline(in, a.diaChi);
			cout<<"- Nhap SDT SV: "; getline(in, a.SDT);
			cout<<"- Lop: "; in>>a.Lop;
			cout<<"- Nhap so mon da dang ki: "; in>>a.SoMonDK;
			for (int i =0; i<a.SoMonDK; i++){
				cout<<"\t- Nhap ma mon dang ki thu "<<i+1<<" : ";
				in>>a.MaMonDK[i];
			}
			return in;
		}
		
		friend ostream& operator << (ostream& out, const SVDK &a) {
			out<<"\n\t#"<<a.MaSV<<"\t"<<a.hoTen<<"\t"<<a.diaChi<<"\t"<<a.SDT<<"\t"<<a.Lop<<"\t";
			return out;
		}
		
		string get_hoTen() {
			return this->hoTen;
		}
		
};

int SVDK::msv = 9999;

//Khai bao svdk

SVDK svdk[100];
void input_SVDK() {
	cout<<"\n------------------";
	cout<<"\nNhap so luong svdk: "; cin>>n;
	for (int i=0; i<n; i++) {
		cout<<"------------------";
		cout<<endl<<"Thong tin svdk thu "<<i<<" :"<<endl;
		cin>>svdk[i];
	}
}

void output_SVDK() {
	cout<<"\n------------------";
	cout<<endl<<"Thong tin svdk :";
	for (int i = 0; i<n; i++) {
		cout<<svdk[i];
	}
}

void swap(SVDK &a, SVDK &b) {
	SVDK k;
	k = a;
	a = b;
	b = k;
}

void swap_SVDK() {
	for (int i=0; i<n-1; i++) {
		for (int j=i; j<n; j++) {
			if (svdk[i].get_hoTen()>svdk[j].get_hoTen()) {
				swap(svdk[i], svdk[j]);
			}
		}
	}
}

int main() {
	input_MH();
	output_MH();
	input_SVDK();
	output_SVDK();
	swap_SVDK();
	output_SVDK();
	return 0;
}
