#include<iostream>
#include<string>
using namespace std;

class String {
	private:
		char *str;
		int length;
	public:
		String() {
			length = 1;
			str = new char[length];
			str[0] = ' ';
		}
		
		String(const char *s) {
			str = new char[1];
			length = 1;
			str[0] = s[0];
		}
		
		String(String &s) {
			length = s.length;
			str = new char[length];
			for (int i = 0; i<length; i++) {
				str[i] = s.str[i];
			}
		}
		
		~String() {
			length = 0;
			delete[] str;
		}
		
		void nhap() {
			cout<<"Length = "; cin>>length;
			str = new char[length];
			cout<<"Nhap xau: ";
			for (int i=0; i<length; i++) {
				cin>>str[i];
			}
		}
		
		void xuat() {
			cout<<"Length = "<<length<<endl;
			cout<<"Xau vua nhap: ";
			for (int i=0; i<length; i++) {
				cout<<str[i];
			}
			cout<<endl;
		}
		
		String noiXau(String s) {
			String c;
			c.length = this->length + s.length;
			int index = 0;
			for(int i = 0; i<this->length; i++) {
				c.str[index] = this->str[i];
				index++;
			}
			for(int i = 0; i<s.length; i++) {
				c.str[index] = s.str[i];
				index++;
			}
			return c;
		}
};

int main() {
	String s1;
	s1.nhap();
	s1.xuat();
	String s2;
	s2.nhap();
	s2.xuat();
	String s3;
	s3 = s1.noiXau(s2);

	s3.xuat();
	return 0;
}
