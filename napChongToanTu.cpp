#include <iostream>
using namespace std;

class TLClass {
	private:
		string id;
		string name;		//ten lop hoc
		string description;	//mieu ta lop hoc
		string position;	//vi tri lop hoc
	public:
		friend istream& operator >> (istream &in, TLClass &a);
		friend ostream& operator << (ostream &out, TLClass a);
		string getID() {
			return this->id;
		}
		string getName() {
			return this->name;
		}
		string getDescription() {
			return this->description;
		}
		string getPosition() {
			return this->position;
		}
};

istream& operator >> (istream &in, TLClass &a) {
	cout<<"- ID lop hoc: "; cin>>a.id;
	cin.ignore();
	cout<<"- Mo ta lop hoc: "; getline(cin, a.description);
	cout<<"- Vi tri lop hoc: "; getline(cin, a.position);
}

ostream& operator << (ostream &out, TLClass a) {
	cout<<"- ID lop hoc: "<<a.id<<endl;
	cout<<"- Mo ta lop hoc: "<<a.description<<endl;
	cout<<"- Vi tri lop hoc: "<<a.position<<endl;
}

class TLStudent {
	private:
		string id;
		string name;		//ten sv
		string address;		//dia chi
		string description;	//mieu ta 
		TLClass tlClass;	//lop hoc
		double note;		//diem tong ket
	public:
		friend istream& operator >> (istream &in, TLStudent &a);
		friend ostream& operator << (ostream &out, TLStudent a);
	
		string getId() {
			return this->id;
		}
		string getName() {
			return this->name;
		}
		string getAddress() {
			return this->address;
		}
		string getDescription() {
			return this->description;
		}
		TLClass getClass() {
			return this->tlClass;
		}
		double getNote() {
			return this->note;
		}
};

istream& operator >> (istream &in, TLStudent &a) {
	cout<<"Nhap thong tin sinh vien:\n";
	cout<<"- ID: "; cin>>a.id;
	cin.ignore();
	cout<<"- Ho va ten: "; getline(cin, a.name);
	cout<<"- Dia chi nha: "; getline(cin, a.address);
	cout<<"- Mieu ta SV: "; getline(cin, a.description);
	cin>>a.tlClass;
	cout<<"- Diem tong ket: "; cin>>a.note;
}

ostream& operator << (ostream &out, TLStudent a) {
	cout<<"\nThong tin sinh vien:\n";
	cout<<"- Ho va ten: "<<a.name<<endl;
	cout<<"- Dia chi nha: "<<a.address<<endl;
	cout<<"- Mieu ta SV: "<<a.description<<endl;
	cout<<a.tlClass;
	cout<<"- Diem tong ket: "<<a.note<<endl;
}

int main() {
	TLStudent SV;
	cin>>SV;
	cout<<SV;
	return 0;
}
