#include<iostream>
#include<string>
using namespace std;

class MyDate {
	private:
		int year;
		int month;
		int day;
		
		
	public:
		static char strMonths[12];
		static string strDays[12];
		static int daysInMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		
		static bool isLeapYear(int year) {
			if ((year%4==0 && year%100!=0) || (year%400==0)) {
				return true;
			}
			else return false;
		}
		
		static bool isValidDate(int year, int month, int day) {
			if (year>=1 && year<=9999) {
				if (isLeapYear(year, month, day) and month==2) {
					if (day>0 && day<29) {
						return true;
					}
				}
				else if (month>=1 && month<=12) {
					if (day>0 && day<daysInMonths[month]) {
						return true;
					}
				}
			}
			return false;
		}
		
		static int getDayOfWeek(int year, int month, int day) {
			int y = year;
			int m = month;
			int d = day;
			y -= (14-m)/12;
		    m += 12*((14-m)/12)-2;
		    getDay = (d + y + y/4 - y/100 + y/400 + (31*m)/12)%7;
		    return getDay;
		}
		
		MyDate(int year, int month, int day) {
			setDate(year, month, day);
		}
		
		void setDate(int year, int month, int day) {
			if (isValidDate(year, month, day)) {
				this->year = year;
				this->month = month;
				this->day = day;
			}
			else {
				this->year = 1;
				this->month = 1;
				this->day = 2021;
			}
			
		}
		
		int getYear() {
			return this->year;
		}
		
		int getMonth() {
			return this->month;
		}
		
		int getDay() {
			return this->day;
		}
		
		void setYear(int year) {
			if (year>=1 && year<=9999) {
				this->year = year;
			}
			else this->year = 2021;
		}
		
		void setMonth(int month) {
			if (month>=1 && month<=12) {
				this->month = month;
			}
			else this->month = 1;
			
		}
		
		void setDay(int day) {
			if (day>=1 && day<=daysInMonths[this->month]) {
				if (isLeapYear(this->year) && this->month==2) {
					if (day<=29) {
						this->day = day;
						return;
					}
				}
				this->day = day;
			}
			else {
				this->day = 1;
			}
			
		}
		
		string toString() {
			return strDays[getDayOfWeek(this->day, this->month, this->year)] +" "+ this->day + " " + daysInMonths[this->month] + " " + this->year;
		}
		
		
		MyDate nextDay() {
			MyDate kq;
			if (this->day == daysInMonths[this->month]) {
				kq.day = 1;
				if (this->month == 12) {
					kq.month = 1;
					kq.year = this->year + 1;
				}
				else {
					kq.month = this->month + 1;
					kq.year = this->year;
				}
			}
			else {
				kq.day = this->day + 1;
				kq.month = this->month;
				kq.year = this->year;
			}
			
			return kq;
		}
		
		MyDate nextMonth() {
			MyDate kq;
			if (this->day == daysInMonths[this->month]) {
				if (this->month == 12) {
					kq.day = daysInMonths[1];
					kq.month = 1;
					kq.year = this->year + 1;
				}
				else {
					kq.day = daysInMonths[this->month+1];
					kq.month = this.month+1;
					kq.year = this->year + 1;
				}
			}
			else {
				kq.day = this->day;
				kq.month = this->month+1;
				kq.year = this->year;
			}
			
			return kq;
		}
		
		MyDate nextYear() {
			MyDate kq;
			if (isLeapYear(this->year) && this->day == daysInMonths[this->month] && this->month==2) {
				kq.day = 28;
				kq.month = 2;
				kq.year = this->year + 1;
			}
			
			else {
				kq.day = this->day;
				kq.month = this->month;
				kq.year = this->year + 1;
			}
			
			
			return kq;
		}
		
//		MyDate lastDay() {
//			
//		}
//		
//		MyDate lastMonth() {
//			
//		}
//		
//		MyDate lastYear() {
//			
//		}
		
};

int main() {
	MyDate day;
	day.setDate(11, 12, 2021);
	return 0;
}
