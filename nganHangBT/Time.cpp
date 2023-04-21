#include<iostream>
using namespace std;

class Time {
	private:
		int h, m, s;
	public:
		void setHour() {
			do {
				cout<<"Nhap Gio: ";
				cin>>h;
			}
			while (h<0 || h>23);
		}
		
		void setMinute() {
			do {
				cout<<"Nhap Phut: ";
				cin>>m;
			}
			while (h<0 || h>59);
		}
		
		void setSecond() {
			do {
				cout<<"Nhap Giay: ";
				cin>>s;
			}
			while (h<0 || h>59);
		}
		
		void setTime(int h, int m, int s) {
			if (h>=0 && h<=23 && m>=0 && m<=59 && s>=0 && s<=59) {
				this->h = h;
				this->m = m;
				this->s = s;
			}
			else {
				this->h = 0;
				this->m = 0;
				this->s = 0;
			}
		}
		
		void _24hFormat() {
			cout<<"Time: "<<h<<":"<<m<<":"<<s<<endl;
		}
		
		void _12hFormat() {
			if (h<=12) {
				cout<<"Time: "<<h<<":"<<m<<":"<<s<<" AM";
			}
			else {
				cout<<"Time: "<<h-12<<":"<<m<<":"<<s<<" PM";
			}
		}
		
		void addSecond() {
			s++;
			if (s==60) {
				s = 0;
				m++;
				if (m==60) {
					m = 0;
					h++;
					if (h == 24) {
						h = 0;
					}
				}
			}
			cout<<endl<<"+1s"<<endl;
		}
};

int main() {
	Time t;
	t.setHour();
	t.setMinute();
	t.setSecond();
	t._24hFormat();
	t._12hFormat();
	
	for (int i=0; i<5; i++) {
		t.addSecond();
		t._24hFormat();
		t._12hFormat();
	}
	

}

