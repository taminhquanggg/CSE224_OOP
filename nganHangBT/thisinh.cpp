#include<iostream>
using namespace std;
class THISINH {
	private:
		string SBD;
		float dToan, dHoa, dLy;
	public:
		void nhap() {
			cin.ignore();
			cout<<"\t- SBD: "; getline(cin, SBD);
			cout<<"\t- Diem Toan: "; cin>>dToan;
			cout<<"\t- Diem Hoa: "; cin>>dHoa;
			cout<<"\t- Diem Ly: "; cin>>dLy;
		}
		
		void xuat() {
			cout<<endl<<"\tSBD: "<<SBD<<"\tDiem Toan: "<<dToan<<"\tDiem Hoa: "<<dHoa<<"\tDiem Ly: "<<dLy<<endl;
		}
		
		float TongDiem() {
			return dToan+dHoa+dLy;
		}
};

class DSTHISINH {
	private:
		THISINH arr[100];
		int n;
	public:
		void Nhap() {
			cout<<"Nhap so thi sinh: "; cin>>n;
			for (int i=0; i<n; i++) {
				arr[i].nhap();
			}
		}
		
		void Xuat() {
			cout<<"So thi sinh: "<<n;
			cout<<endl<<"Danh sach thi sinh:";
			for (int i=0; i<n; i++) {
				arr[i].xuat();
			}
		}
		
		void Sort() {
			for (int i=0; i<n-1; i++)
				for (int j=i+1; j<n; j++)
					if (arr[i].TongDiem()>arr[j].TongDiem()) {
						THISINH k = arr[i];
						arr[i] = arr[j];
						arr[j] = k;
					}
		}
		
		void DiemCao() {
			cout<<"Danh sach thi sinh tong diem >= 18:";
			for (int i=0; i<n; i++) 
				if (arr[i].TongDiem() >= 18) {
					arr[i].xuat();
				}
		}
};

int main() {
	DSTHISINH t;
	t.Nhap();
	t.Xuat();
	t.Sort();
	cout<<endl<<"Danh sach thi sinh sau sap xep:"<<endl;
	t.Xuat();
	t.DiemCao();
	return 0;
}
