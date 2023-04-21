#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class SINHVIEN {
	private:
		string ID;
		string Name;
		int Age;
	public:
		void nhap(){
			fflush(stdin);
			cout<<"- MSV: "; getline(cin, ID);
			cout<<"- Ho va ten: "; getline(cin, Name);
			cout<<"- Tuoi: "; cin>>Age;
		}
		void xuat(){
			cout<<"\n- MSV: "
				<<ID<<"\n- Ho va ten: "
				<<Name<<"\n- Tuoi: "<<Age<<endl;
		}
};

class DIEMTONGKET : public SINHVIEN {
	private:
		float Math;
		float Physics;
		float Chemistry;
	public:
		void nhap(){
			cout<<"\nNHAP THONG TIN SV:\n";
			SINHVIEN::nhap();
			cout<<"- Diem Toan: "; cin>>Math;
			cout<<"- Diem Ly: "; cin>>Physics;
			cout<<"- Diem Hoa: "; cin>>Chemistry;
		}
		
		void in(){
			cout<<"\nTHONG TIN BANG DIEM";
			SINHVIEN::xuat();
			cout<<"- Diem Toan: "<<Math
				<<"\n- Diem Ly: "<<Physics
				<<"\n- Diem Hoa: "<<Chemistry
				<<"\n- Diem TB: "<<diemTB()
				<<"\n- Xep loai: "<<xepLoai()<<endl;
		}
		
		float diemTB() {
			return (Math+Physics+Chemistry)*1.0/3;
		}
		
		string xepLoai() {
			string loai;
			if (diemTB()<5) {
				loai = "Yeu";
			}
			else if (diemTB()<8) {
				loai = "Kha";
			}
			else if (diemTB()<=10) {
				loai = "Gioi";
			}
			return loai;
		}
};

int main(){
	DIEMTONGKET SV[10];
	int n, dK=0;
	
	cout<<"Nhap so SV: "; cin>>n;
	for (int i=0; i<n; i++) {
		SV[i].nhap();
	}
	
	cout<<"\n--------------------------------\nBANG DIEM\n";
	
	for (int i=0; i<n; i++) {
		SV[i].in();
	}
	
	cout<<"\n--------------------------------\nDANH SACH SV CO DTB LON HON 8";
	for (int i=0; i<n; i++) {
		if (SV[i].diemTB()>8) {
			cout<<"\n#"<<i+1;
			SV[i].in();
		}
	}
	
	for (int i=0; i<n; i++) {
		if (SV[i].xepLoai()=="Kha") {
			dK++;
		}
	}
	
	cout<<"\n--------------------------------\nSo SV xep loai kha: "<<dK;
	return 0;
}
