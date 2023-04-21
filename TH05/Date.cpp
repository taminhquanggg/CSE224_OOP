#include<iostream>
using namespace std;

class Date {
	private:
		int Ngay;
		int Thang;
		int Nam;
	public:
		Date() {
			
		}
		
		friend istream& operator >> (istream& in, Date &a) {
			cout<<endl<<"\t- Nhap ngay: "; in>>a.Ngay;
			cout<<"\t- Nhap thang: "; in>>a.Thang;
			cout<<"\t- Nhap nam: "; in>>a.Nam;
			return in;
		}
		
		friend ostream& operator << (ostream& out, Date &a) {
			out<<endl<<"\t"<<a.Ngay<<"/"<<a.Thang<<"/"<<a.Nam;
			return out;
		}
		
		bool operator > (Date a) {
			if (this->Nam>a.Nam) {
				return true;
			}
			else if (this->Nam<a.Nam) {
				return false;
			}
			else {
				if (this->Thang>a.Thang) {
					return true;
				}
				else if (this->Thang<a.Thang) {
					return false;
				}
				else {
					if (this->Ngay>a.Ngay) {
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
};

template <class T>
class Array {
	private:
		T *arr;
		int Size;
	public:
		DS() {
			
		}
		
		friend istream& operator >> (istream& in, Array<T> &a) {
			cout<<"Size = "; cin>>a.Size;
			a.arr = new T[a.Size];
			for (int i=0; i<a.Size; i++) {
				cout<<"Arr["<<i<<"] = ";
				in>>a.arr[i];
			}
			return in;
		}
		
		friend ostream& operator << (ostream& out, Array<T> &a) {
			cout<<endl<<"Array:";
			for (int i=0; i<a.Size; i++) {
				out<<" "<<a.arr[i];
			}
			return out;
		}
		
		void Sort() {
			for (int i=0; i<Size-1; i++) {
				for (int j=i+1; j<Size; j++) {
					if (arr[i]>arr[j]) {
						T k = arr[i];
						arr[i] = arr[j];
						arr[j] = k;
					}
				}
			}
		}
		
};

int main() {
	
	cout<<"-----------------\nARRAY INT\n";
	Array<int> a;
	cin>>a;
	cout<<a;
	a.Sort();
	cout<<endl<<"Sort Array: ";
	cout<<a;
	
	cout<<"\n-----------------\nARRAY DATE\n";
	Array<Date> date;
	cin>>date;
	cout<<date;
	date.Sort();
	cout<<endl<<"Sort Array: "<<endl;
	cout<<date;
}
