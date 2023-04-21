#include<iostream>
using namespace std;

class String{
	private:
		char *str;
		int length;
	public:
		String() {
			length = 1;
			str = new char[length];
			str[0] = ' ';
		}
		
		String(String &s1) {
			length = s1.length;
			str = new char[length];
			for (int i = 0; i<length; i++){
				str[i] = s1.str[i];
			}
		}
		
		~String() {
			delete[] str;
			length = 0;
		}
		
		friend istream& operator >> (istream &in, String &s1);

	    friend ostream& operator << (ostream &out, String s1);
		
		void operator = (const String& s1) {
			length = s1.length;
			str = new char[length];
			for (int i=0; i<length; i++) {
				str[i] = s1.str[i];
			}
		}
		
		float operator [] (int i) {
			return str[i];
		}
		
		friend bool operator == (String s1, String s2);
		
		friend bool operator != (String s1, String s2);
		
		bool operator < (String s1) {
			for (int i = 0; i<this->length; i++) {
				if (str[i]<s1.str[i]) {
					return true;
				}
			}
			return false;
		}
		
		bool operator <= (String s1) {
			for (int i = 0; i<this->length; i++) {
				if (str[i]<=s1.str[i]) {
					return true;
				}
			}
			return false;
		}
		
		bool operator > (String s1) {
			for (int i = 0; i<this->length; i++) {
				if (str[i]>s1.str[i]) {
					return true;
				}
			}
			return false;
		}
		
		bool operator >= (String s1) {
			for (int i = 0; i<this->length; i++) {
				if (str[i]>=s1.str[i]) {
					return true;
				}
			}
			return false;
		}
		
		void operator += (String s1) {
			String k;
			k.length = this->length + s1.length;
			int index = 0;
			for (int i = 0; i<this->length; i++) {
				k.str[index] = this->str[i];
				index++;
			}
			for (int i = 0; i<s1.length; i++) {
				k.str[index] = s1.str[i];
				index++;
			}
			this->length = k.length;
			this->str = new char(this->length);
			for (int i = 0; i< this->length; i++){
				this->str[i] = k.str[i];
			}
		}
		
		
};

istream& operator >> (istream &in, String &s1){
	cout << "\nlength = "; cin>>s1.length;
	s1.str = new char[s1.length];
	cout<<"Nhap chuoi:";
	for (int i=0; i<s1.length; i++) {
		cin >> s1.str[i];
	}
	return in;
}
		
ostream& operator << (ostream &out, String s1){
	cout<<"\nChuoi:";
	for (int i=0; i<s1.length; i++) {
		cout<< s1.str[i];
	}
	return out;
}

bool operator == (String s1, String s2){
	for (int i = 0; i<s1.length; i++) {
		if (s1.str[i] != s2.str[i]) {
			return false;
		}
	}
	return true;
}

bool operator != (String s1, String s2) {
	for (int i = 0; i<s1.length; i++) {
		if (s1.str[i] != s2.str[i]) {
			return true;
		}
	}
	return false;
}

int main(){
	//nhap chuoi s
	String s;
	cin>>s;
	cout<<s;
	//gan chuoi s1 = s
	String s1 = s;
	cout<<s1;
	//nhap chuoi s2
	String s2;
	cin>>s2;
	cout<<s2;
	//gan noi s2 vao s
	s += s2;
	cout<<s;
}
