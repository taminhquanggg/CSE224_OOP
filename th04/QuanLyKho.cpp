#include<iostream>
using namespace std;

int m, n;

//Class MatHang

class MatHang {
	private:
		static int maHang;
		int maH;
		string tenH;
		string nhomH;
		double gia;
	public:
		MatHang() {
			
		}
		
		friend istream& operator >> (istream& in, MatHang &a) {
			cout<<"- Ma hang: "<<++maHang<<endl;
			a.maH = maHang;
			cin.ignore();
			
			cout<<"- Nhap ten hang: "; getline(in, a.tenH);
			
			cout<<"- Danh sach nhom hang:\n";
			cout<<"\t1. Hang thoi trang.\n";
			cout<<"\t2. Hang tieu dung.\n";
			cout<<"\t3. Hang dien may.\n";
			cout<<"\t4. Hang gia dung.\n";
			int chon;
			cout<<"- Chon nhom hang theo ma (1/2/3/4): "; cin>>chon;
			switch (chon) {
				case 1:
					a.nhomH = "Hang thoi trang";
					break;
				case 2:
					a.nhomH = "Hang tieu dung";
					break;
				case 3:
					a.nhomH = "Hang dien may";
					break;
				case 4:
					a.nhomH = "Hang gia dung";
					break;
			}
			cout<<"- Nhap gia ban: "; in>>a.gia;
			
			return in;
		}
		friend ostream& operator << (ostream& out, const MatHang &a) {
			out<<"\n\t#"<<a.maH<<"\t"<<a.tenH<<"\t"<<a.nhomH<<"\t"<<a.gia;
			return out;
		}
		
};

int MatHang::maHang = 999;

//Class Nguoi

class Nguoi {
	protected:
		string hoTen;
		string diaChi;
		string SDT;
	public:
		Nguoi() {
			
		}
	
};

//Class KhachHang

class KhachHang:public Nguoi {
	private:
		static int maKHang;
		int maKH;
		string loaiKh;
		int numMH;
		int dsMH[100];
	public:
		KhachHang() {
			
		}
		
		friend istream& operator >> (istream& in, KhachHang &a) {
			cout<<"- Ma KH: "<<++maKHang<<endl;
			a.maKH = maKHang;
			cin.ignore();
			
			cout<<"- Nhap ho ten KH: "; getline(in, a.hoTen);
			cout<<"- Nhap dia chi KH: "; getline(in, a.diaChi);
			cout<<"- Nhap SDT KH: "; getline(in, a.SDT);
			
			cout<<"- Danh sach loai KH:\n";
			cout<<"\t1. Mua le.\n";
			cout<<"\t2. Mua buon.\n";
			int chon;
			cout<<"- Chon nhom hang theo ma (1/2): "; cin>>chon;
			switch (chon) {
				case 1:
					a.loaiKh = "Mua le";
					break;
				case 2:
					a.loaiKh = "Mua buon";
					break;
			}
			
			cout<<"- Nhap so MH da mua: "; in>>a.numMH;
			for (int i =0; i<a.numMH; i++){
				cout<<"\t- Nhap ma MH da mua "<<i+1<<" : ";
				in>>a.dsMH[i];
			}
			return in;
		}
		
		friend ostream& operator << (ostream& out, const KhachHang &a) {
			out<<"\n\t#"<<a.maKH<<"\t"<<a.hoTen<<"\t"<<a.diaChi<<"\t"<<a.SDT<<"\t"<<a.loaiKh;
			return out;
		}
		
		int getMaKH() {
			return this->maKH;
		}
		
};

int KhachHang::maKHang = 9999;

//Khai bao mat hang
MatHang MH[100];
void input_MH() {
	cout<<"Nhap so luong MH: "; cin>>m;
	for (int i=0; i<m; i++) {
		cout<<"------------------";
		cout<<endl<<"Thong tin MH thu "<<i<<" :"<<endl;
		cin>>MH[i];
	}
}

void output_MH() {
	cout<<"\n------------------";
	cout<<endl<<"Thong tin MH :";
	for (int i = 0; i<m; i++) {
		cout<<MH[i];
	}
}

//Khai bao khach hang
KhachHang KH[100];
void input_KH() {
	cout<<"\n------------------";
	cout<<"\nNhap so luong KH: "; cin>>n;
	for (int i=0; i<n; i++) {
		cout<<"------------------";
		cout<<endl<<"Thong tin KH thu "<<i<<" :"<<endl;
		cin>>KH[i];
	}
}

void output_KH() {
	cout<<"\n------------------";
	cout<<endl<<"Thong tin KH :";
	for (int i = 0; i<n; i++) {
		cout<<KH[i];
	}
}

void KT_MaKH() {
	int maKH;
	cout<<"\n------------------";
	cout<<endl<<"Nhap ma KH can tim kiem :"; cin>>maKH;
	for (int i = 0; i<n; i++) {
		if (KH[i].getMaKH() == maKH) {
			cout<<"\n------------------";
			cout<<endl<<"Thong tin KH ma "<<maKH<<" :";
			cout<<KH[i];
			return;
		}
	}
	
	n++;
	cout<<"\n------------------";
	cout<<endl<<"Khong tim thay ma KH"<<maKH<<", nhap thong tin KH moi :";
	cin>>KH[n-1];
	output_KH();
}

int main() {
	input_MH();
	output_MH();
	input_KH();
	output_KH();
	KT_MaKH();
	return 0;
}
