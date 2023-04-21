#include<iostream>
using namespace std;

class Computer {
	private:
		char code[4];
		float price;
	public:
		char *getCode() const {
			char *c = new char;
			for (int i = 0; i<4; i++) {
				c[i] = code[i];
			}
			return c;
		}
		
		float getPrice() const {
			return price;
		}
		void setPirce(float price) {
			this->price = price;
		}
		void setCode(char *c) {
			for (int i = 0; i<4; i++) {
				code[i] = c[i];
			}
		}
		
		bool operator == (Computer c) {
			for (int i = 0; i<4; i++) {
				if (this->code[0] != c.code[0]) {
					return false;
				}
			}
			if (this->price != c.price) {
				return false;
			}
			return true;
		}
		
		friend istream& operator >> (istream &in, Computer &c) {
			cout<<"Code: ";
			for (int i = 0; i<4; i++) {
				in>>c.code[i];
			}
			cout<<"Price: "; in>>c.price;
			return in;
		}
		
		friend ostream& operator << (ostream &out, Computer &c) {
			cout<<"Code: "<<c.getCode();
			cout<<endl<<"Price: "<<c.getPrice();
			return out;
		}
		
		friend bool operator > (Computer c1, Computer c2) {
			if (c1 == c2) {
				if (c1.price > c2.price) {
					return true;
				}		
			}
			
			else {
				for (int i = 0; i<4; i++) {
					if (c1.code[i] > c2.code[i]) {
						return true;
					}
				}
			}
			return false;
		}
		
		friend bool operator < (Computer c1, Computer c2) {
			if (c1 == c2) {
				if (c1.price < c2.price) {
					return true;
				}		
			}
			
			else {
				for (int i = 0; i<4; i++) {
					if (c1.code[i] < c2.code[i]) {
						return true;
					}
				}
			}
			return false;
		}
		
		bool operator >= (Computer c) {
			for (int i = 0; i<4; i++) {
				if (this->code[i] > c.code[i]) {
					continue;
				}
				else if (this->code[i] < c.code[i]) {
					return false;
				}
			}
			return true;
		}
		
		bool operator <= (Computer c) {
			for (int i = 0; i<4; i++) {
				if (this->code[0] < c.code[0]) {
					continue;
				}
				else if (this->code[0] > c.code[0]) {
					return false;
				}
			}
			return true;
		}
		
		void operator = (Computer c) {
			this->price = c.price;
			for (int i = 0; i<4; i++) {
				this->code[i] = c.code[i];
			}
		}
		
//		friend void sort(Computer cpt[], int size){
//			for (int i = 0; i<size-1; i++) {
//				for (int j = i+1; j<size; j++) {
//					if (cpt[i]>cpt[j]) {
//						Computer t = cpt[i];
//						cpt[i] = cpt[j];
//						cpt[j] = t;
//					}
//				}
//			}
//		}
};

template<class T>
void sort(T cpt[], int size) {
	for (int i = 0; i<size-1; i++) {
		for (int j = i+1; j<size; j++) {
			if (cpt[i]>cpt[j]) {
				T t = cpt[i];
				cpt[i] = cpt[j];
				cpt[j] = t;
			}
		}
	}
}

template<class T>
int _2ndElement(T a[], int size) {
	T Max, secondMax;
	if (a[0] > a[1]){
        Max = a[0];
        secondMax = a[1];
    }else{
        Max = a[1];
        secondMax = a[0];
    }
    for(int i = 2; i < size; i++){
        if(a[i] > Max){
            secondMax = Max;
            Max = a[i];
        }else if (a[i] > secondMax){
            secondMax = a[i];
        }
    }
    
    
    
    for (int i = 0; i<size; i++) {
    	if (secondMax == a[i]) {
    		return i;
		}
	}
}
int main() {
	int n;
	cout<<"Nhap so Computer: "; cin>>n;
	Computer c[n];
	for (int i = 0; i<n; i++) {
		cout<<endl<<"---------------\nComputer "<<i<<endl;
		cin>>c[i];
	}
	
	cout<<endl<<"---------------\nIN COMPUTER "<<endl;
	for (int i = 0; i<n; i++) {
		cout<<endl<<"---------------\nComputer "<<i<<endl;
		cout<<c[i];
	}
	
	cout<<endl<<"---------------\n_2ndElement = "<<endl;
	_2ndElement(c, n);
	
	cout<<endl<<"---------------\nSAP XEP "<<endl;
	sort(c, n);
	for (int i = 0; i<n; i++) {
		cout<<endl<<"---------------\nComputer "<<i<<endl;
		cout<<c[i];
	}
}
