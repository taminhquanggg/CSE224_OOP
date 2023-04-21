#include<iostream>
using namespace std;

class NhanVien {
	protected:
		string HoTen;
		int NamSinh;
		string GioiTinh;
		string DiaChi;
	public:
		friend istream& operator >> (istream &in, NhanVien &a);
		friend ostream& operator << (ostream &out, NhanVien a);
};

istream& operator >> (istream &in, NhanVien &a) {
	cout<<"- Ho ten: "; getline(cin, a.HoTen);
	cin.ignore();
	cout<<"- Nam sinh: "; cin>>a.NamSinh;
	cout<<"- Gioi tinh: "; getline(cin, a.GioiTinh);
	cout<<"- Dia chi: "; getline(cin, a.DiaChi);
}

ostream& operator << (ostream &out, NhanVien a) {
	cout<<a.HoTen<<"\t"<<a.NamSinh<<"\t"<<a.GioiTinh<<"\t"<<a.DiaChi<<endl;
}

int main() {
	
}
