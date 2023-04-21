#include<iostream>
#include<string>
using namespace std;

class SinhVien {
	private:
		string hoTen;
		string namSinh;
		string Tuoi;
		string Lop;
	public:
		void nhapTTSV() {
			cout<<"- Ho ten: "; getline(cin, hoTen);
			cout<<"- Nam sinh: "; getline(cin, namSinh);
			cout<<"- Tuoi: "; getline(cin, Tuoi);
			cout<<"- Lop: "; getline(cin, Lop);
			fflush(stdin); 
			
		}
		
		void inTTSV() {
			cout<<"- Ho ten: "<<hoTen<<endl;
			cout<<"- Nam sinh: "<<namSinh<<endl;
			cout<<"- Tuoi: "<<Tuoi<<endl;
			cout<<"- Lop: "<<Lop<<endl;
		}
		
		string getLop() {
			return Lop;
		}
		
};

class TheMuon:public SinhVien {
	private:
		string soPhieuMuon;
		string ngayMuon;
		string hanTra;
		string soHieuSach;
	public:
		
		void nhapTTThe() {
			fflush(stdin);
			cout<<"Nhap thong tin the:"<<endl;
			cout<<"- So phieu muon: "; getline(cin, soPhieuMuon);
			cout<<"- Ngay muon: "; getline(cin, ngayMuon);
			cout<<"- Han tra: "; getline(cin, hanTra);
			cout<<"- So hieu sach: "; getline(cin, soHieuSach);
			nhapTTSV();
		}
		
		void inTTThe() {
			cout<<"Thong tin the:"<<endl;
			cout<<"- So phieu muon: "<<soPhieuMuon<<endl;
			cout<<"- Ngay muon: "<<ngayMuon<<endl;
			cout<<"- Han tra: "<<hanTra<<endl;
			cout<<"- So hieu sach: "<<soHieuSach<<endl;
			inTTSV();
		}
		
		
		
};

int main() {
	int m, d=0;
	cout<<"=================\n===DANG KY THE===\n=================\n";
	cout<<"Nhap so the can dang ky: "; cin>>m;
	TheMuon TM[m];
	for (int i = 0; i<m; i++) {
		cout<<endl<<"NHAP THONG TIN THE "<<i+1<<":"<<endl;
		TM[i].nhapTTThe();
	}
	cout<<"\n=================\n==THONG TIN THE==\n=================\n";
	for (int i = 0; i<m; i++) {
		cout<<endl<<"IN THONG TIN THE "<<i+1<<":"<<endl;
		TM[i].inTTThe();
	}
	
	for (int i = 0; i<m; i++) {
		if (TM[i].getLop() == "K3A") {
			d++;
		}
	}
	
	cout<<endl<<"So luong the muon cua lop K3A la: "<<d;
	
	return 0;
}
