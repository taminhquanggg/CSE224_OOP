#include<iostream>
using namespace std;

template<class T>
class SoPhuc{
	private:
		T a, b;
	public:
		SoPhuc(){
			a = 0;
			b = 0;
		}
		
		SoPhuc(int a, int b){
			this->a = a;
			this->b = b;
		}

		~SoPhuc(){
			a = 0;
			b = 0;
		}
		
		friend istream& operator >> (istream& in, SoPhuc<T> &k) {
			cout<<"Nhap gia tri so phuc:\n";
			cout<<"Phan thuc: "; cin>>k.a;
			cout<<"Phan ao: "; cin>>k.b;
		}

		friend ostream& operator << (ostream& out, SoPhuc<T> k){
			cout<<"Gia tri so phuc: "<<k.a<<"+"<<k.b<<"i\n";
			
		}
		
		SoPhuc operator + (SoPhuc<T> m){
			SoPhuc<T> kq;
			kq.a = this->a + m.a;
			kq.b = this->b + m.b;
			return kq;
		}
		
		SoPhuc operator - (SoPhuc<T> m){
			SoPhuc<T> kq;
			kq.a = this->a - m.a;
			kq.b = this->b - m.b;
			return kq;
		}
		
		friend SoPhuc operator * (SoPhuc<T> k, SoPhuc<T> m) {
			SoPhuc<T> kq;
			kq.a = k.a*m.a - k.b*m.b;
			kq.b = k.a*m.b + k.b*m.a;
			return kq;
		}
};


template<class T>
class Stack {
	private:
		int Size;
		int Top;
		T *Data;
	public:
		Stack() {
			Top = -1;
			Size = 10;
			Data = new T[Size];
		}
		
		Stack(int size) {
			Size = size;
			Top = -1;
			Data = new T[Size];
		}
		
		~Stack() {
			delete[] Data;
		}
		
		bool isEmpty() {
			return (Top == -1);
		}
		
		bool Push(const T &itemp) {
			if (Top<Size) {
				Top++;
				Data[Top] = itemp;
				return true;
			}
			
			return false;
			
		}
		
		T Pop() {
			T top = Data[Top];
			Top--;
			return top;
		}
		
		T topItem() {
			return Data[Top];
		}
		
		
};

int main() {
	cout<<"STACK INT\n";
	Stack<int> a;
	a.Push(5);
	a.Push(6);
	a.Push(7);
	a.Push(8);
	a.Push(9);
	a.Push(10);
	cout<<"Top item: "<<a.topItem()<<endl;
	cout<<"Stack: ";
	while (a.isEmpty()==false) {
		cout<<a.Pop()<<" ";
	}
	cout<<endl<<"Stack rong? "<<a.isEmpty();
	
	
	cout<<"\n------------------\nSTACK CHAR\n";
	Stack<char> c(100);
	c.Push('q');
	c.Push('u');
	c.Push('a');
	c.Push('n');
	c.Push('g');
	cout<<"Top item: "<<c.topItem()<<endl;
	cout<<"Stack: ";
	while (c.isEmpty()==false) {
		cout<<c.Pop()<<" ";
	}
	cout<<endl<<"Stack rong? "<<c.isEmpty();
	
	
	cout<<"\n------------------\nSTACK FLOAT\n";
	Stack<float> f(10);
	f.Push(1.2);
	f.Push(4.6);
	f.Push(7.3);
	f.Push(8.2);
	f.Push(9.1);
	cout<<"Top item: "<<f.topItem()<<endl;
	cout<<"Stack: ";
	while (f.isEmpty()==false) {
		cout<<f.Pop()<<" ";
	}
	cout<<endl<<"Stack rong? "<<f.isEmpty();
	
	cout<<"\n------------------\nSTACK SO PHUC\n";
	Stack<SoPhuc<int> > sp(1000);
	sp.Push(SoPhuc<int>(1, 2));
	sp.Push(SoPhuc<int>(2, 6));
	
	cout<<"Top item: "<<sp.topItem()<<endl;
	cout<<"Stack: "<<endl;
	while (sp.isEmpty()==false) {
		cout<<sp.Pop();
	}
	cout<<endl<<"Stack rong? "<<sp.isEmpty();
	
	
}
