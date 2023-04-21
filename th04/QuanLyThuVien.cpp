#include<iostream>
using namespace std;

int n, m;

//============================ Class Sach

class Sach {
	private:
		static int ms;
		int MaSach;
		string TenSach;
		string TacGia;
		string ChuyenNganh;
		int NamXuatBan;
	public:
		Sach() {

		}
		
		friend istream& operator >> (istream& in, Sach &s) {
			cout<<"- Ma sach: "<<++ms<<endl;
			s.MaSach = ms;
			cin.ignore();
			
			cout<<"- Nhap ten sach: "; getline(in, s.TenSach);
			cout<<"- Nhap ten tac gia: "; getline(in, s.TacGia);
		
			cout<<"- Danh sach chuyen nganh:\n";
			cout<<"\t1. Khoa hoc tu nhien.\n";
			cout<<"\t2. Van hoc - nghe thuat.\n";
			cout<<"\t3. Dien tu vien thong.\n";
			cout<<"\t4. Cong nghe thong tin.\n";
			int chon;
			cout<<"- Chon chuyen nganh theo ma (1/2/3/4): "; cin>>chon;
			switch (chon) {
				case 1:
					s.ChuyenNganh = "Khoa hoc tu nhien";
					break;
				case 2:
					s.ChuyenNganh = "Van hoc - Nghe thuat";
					break;
				case 3:
					s.ChuyenNganh = "Dien tu Vien thong";
					break;
				case 4:
					s.ChuyenNganh = "Cong nghe thong tin";
					break;
				default:
					s.ChuyenNganh = "trong";
			}
			
			cout<<"- Nhap nam xuat ban: "; in>>s.NamXuatBan;
			return in;
		}
		friend ostream& operator << (ostream& out, const Sach &s) {
			out<<"\n\t#"<<s.MaSach<<"\t"<<s.TenSach<<"\t"<<s.TacGia<<"\t"<<s.ChuyenNganh<<"\t"<<s.NamXuatBan;
			return out;
		}	
		int getMaSach() {
			return MaSach;
		}
};

int Sach::ms = 9999;

//============================== Nhap thong tin Sach

Sach dsSach[100];

void input_Sach() {
	cout<<"Nhap vao so dau sach: "; cin>>m;
	for (int i = 0; i<m; i++) {
		cout<<"------------------";
		cout<<endl<<"Thong tin dau sach thu "<<i<<" :"<<endl;
		cin>>dsSach[i];
	}
}

void output_Sach() {
	cout<<"------------------";
	cout<<endl<<"Thong tin dau sach :";
	for (int i = 0; i<m; i++) {
		cout<<dsSach[i];
	}
}

//============================== Class Nguoi

class Nguoi {
	protected:
		string hoTen;
		string diaChi;
		string SDT;
	public:
		Nguoi() {
			
		}
		
		
};

//================================= Class BanDoc

class BanDoc:public Nguoi {
	private:
		static int md;
		int MaBanDoc;
		string LoaiBanDoc;
		int SoSachMuon;
		int MaSachDaMuon[100];
	public:
		BanDoc() {
			
		}
		
		friend istream& operator >> (istream& in, BanDoc &a) {
			cout<<"- Ma ban doc: "<<++md<<endl;
			a.MaBanDoc = md;
			cin.ignore();
			cout<<"- Nhap ho ten ban doc: "; getline(in, a.hoTen);
			cout<<"- Nhap dia chi ban doc: "; getline(in, a.diaChi);
			cout<<"- Nhap SDT ban doc: "; getline(in, a.SDT);
			cout<<"- Danh sach loai ban doc:\n";
			cout<<"\t1. Sinh vien.\n";
			cout<<"\t2. Hoc vien cao hoc.\n";
			cout<<"\t3. Giao vien.\n";
			int chon;
			cout<<"- Chon loai ban doc theo ma (1/2/3): "; cin>>chon;
			switch (chon) {
				case 1:
					a.LoaiBanDoc = "Sinh vien";
					break;
				case 2:
					a.LoaiBanDoc = "Hoc vien cao hoc";
					break;
				case 3:
					a.LoaiBanDoc = "Giao vien";
					break;
				default:
					a.LoaiBanDoc = "trong";
			}
		
			cout<<"- Nhap so sach da muon: "; in>>a.SoSachMuon;
			for (int i =0; i<a.SoSachMuon; i++){
				cout<<"\t- Nhap ma sach da muon cuon sach "<<i+1<<" : ";
				in>>a.MaSachDaMuon[i];
			}
			return in;
		}
		
		friend ostream& operator << (ostream& out, const BanDoc &a) {
			out<<"\n\t#"<<a.MaBanDoc<<"\t"<<a.hoTen<<"\t"<<a.diaChi<<"\t"<<a.SDT<<"\t"<<a.LoaiBanDoc<<"\t";
			return out;
		}
		
		void sachMuon(Sach s[100]) {
			cout<<"So sach muon: "<<SoSachMuon<<endl;
			cout<<"Danh sach sach da muon: \n";
			int i = 0;
			while (i<SoSachMuon) {
				for (int j=0; i<m; i++) {
					if (MaSachDaMuon[i] == s[j].getMaSach()) {
						cout<<s[j];
					}
				}
				i++;
			}
		}
		
		int getMaBanDoc() {
			return this->MaBanDoc;
		}
		
};

int BanDoc::md = 9999;

//====================================== Khai bao lop BanDoc

BanDoc dsbd[100];
void input_BanDoc() {
	cout<<"\n------------------";
	cout<<"\nNhap so luong ban doc: "; cin>>n;
	for (int i=0; i<n; i++) {
		cout<<"------------------";
		cout<<endl<<"Thong tin ban doc thu "<<i<<" :"<<endl;
		cin>>dsbd[i];
	}
}

void output_BanDoc() {
	cout<<"\n------------------";
	cout<<endl<<"Thong tin ban doc :";
	for (int i = 0; i<n; i++) {
		cout<<dsbd[i];
	}
}

void input_MaBanDoc() {
	int maBD;
	cout<<"\n------------------";
	cout<<endl<<"Nhap ma ban doc: "; cin>>maBD;
	for (int i = 0; i<n; i++) {
		if (dsbd[i].getMaBanDoc() == maBD) {
			dsbd[i].sachMuon(dsSach);
		}
	}
}

int main() {
	input_Sach();
	output_Sach();
	input_BanDoc();
	output_BanDoc();
	input_MaBanDoc();
	return 0;
}
