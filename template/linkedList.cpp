#include<iostream>
#include<string>
using namespace std;

template <class T>
class phanSo {
	private:
		T ts;
		T ms;
	public:
		phanSo() {
			
		}
		
		phanSo(T ts, T ms) {
			this->ts = ts;
			this->ms = ms;
		}
		
		~phanSo() {
			
		}
		
//		T UCLN(T m, T n) {
//			m = abs(m);
//			n = abs(n);
//			if (m == 0 && n == 0)
//			    return 1;
//			while (m != n) {
//				if (m > n)
//				    m -= n;
//				else n -= m;
//			}
//			return m;
//		}
		
		friend istream& operator >> (istream& in, phanSo<T> &a) {
			cout<<endl<<"- Tu so: "; in>>a.ts;
			cout<<"- Mau so: "; in>>a.ms;
			return in;
		}
		
		friend ostream& operator << (ostream& out, phanSo<T> &a) {
			out<<endl<<"\t"<<a.ts<<"/"<<a.ms;
			return out;
		}
		
		bool operator == (phanSo<T> a) {
			if (a.ts == this->ts && a.ms==this->ms)
				return true;
			return false;
		}
		
		phanSo operator + (phanSo<T> a) {
			phanSo<T> kq;
			kq.ts = this->ts*a.ms + a.ts*this->ms;
			kq.ms = this->ms*a.ms;
			return kq;
		}
		
		phanSo operator - (phanSo<T> a) {
			phanSo<T> kq;
			kq.ts = this->ts*a.ms - a.ts*this->ms;
			kq.ms = this->ms*a.ms;
			return kq;
		}
		
		phanSo operator * (phanSo<T> a) {
			phanSo<T> kq;
			kq.ts = this->ts*a.ts;
			kq.ms = this->ms*a.ms;
			return kq;
		}
		
		phanSo operator / (phanSo<T> a) {
			phanSo<T> kq;
			kq.ts = this->ts*a.ms;
			kq.ms = this->ms*a.ts;
			return kq;
		}
		
		bool operator > (const phanSo<T> &a) {
			if (this->ts*1.0/this->ms > a.ts*1.0/a.ms) {
				return true;
			}
			return false;
		}
		
		void operator = (phanSo<T> a) {
			this->ts = a.ts;
			this->ms = a.ms;
		}
		
};

template <class T>
class LinkedList {
	private:
		struct Node {
			T data;
			Node *pNext;
		};
		Node *pHead;
		Node *pTail;
	public:
		LinkedList() {
			pHead = NULL;
			pTail = NULL;
		}
		
		~LinkedList() {
			Node *head = pHead;
			while (head) {
				Node *tH = head;
				head = head->pNext;
				delete tH;
				tH = NULL;
			}
			
			Node *tail = pTail;
			while (tail) {
				Node *tT = tail;
				tail = tail->pNext;
				delete tT;
				tT = NULL;
			}

		}
		
		
		void Insert(T value) {
			Node *p = new Node();
			p->data = value;
			p->pNext = pHead;
			pHead = p;
		}
		
		void Delete() {
			if (pHead !=NULL) {
				Node *p = pHead;
				pHead = pHead->pNext;
				delete p;
			}
		}
		
		void Print() {
			Node *p = pHead;
			while(p!=NULL) {
				cout<<p->data<<" ";
				p = p->pNext;
			}
			cout<<endl;
		}
		
		bool Search(T value) {
			Node *p = pHead;
			while(p!=NULL){
				if (p->data == value)
					return true;
				p = p->pNext;
			}
			return false;
		}
		
		bool isEmpty() {
			Node *p = pHead;
			if (p==NULL)
				return true;
			return false;
		}
		
	
};

int main() {
	LinkedList<int> ListI;
	ListI.Insert(5);
	ListI.Insert(6);
	ListI.Insert(7);
	ListI.Insert(8);
	ListI.Insert(9);
	cout<<"LinkedList Int: "<<endl;
	ListI.Print();
	ListI.Delete();
	cout<<"LinkedList Int After Delete: "<<endl;
	ListI.Print();
	cout<<"Search Result = "<<ListI.Search(9);
	cout<<endl<<"isEmpty Result = "<<ListI.isEmpty()<<endl;
	
	
	LinkedList<char> ListC;
	ListC.Insert('q');
	ListC.Insert('u');
	ListC.Insert('a');
	ListC.Insert('n');
	ListC.Insert('g');
	cout<<"LinkedList Char: "<<endl;
	ListC.Print();
	ListC.Delete();
	cout<<"LinkedList Char After Delete: "<<endl;
	ListC.Print();
	cout<<"Search Result = "<<ListC.Search('u');
	cout<<endl<<"isEmpty Result = "<<ListC.isEmpty()<<endl;
	
	LinkedList<float> ListF;
	ListF.Insert(1.5);
	cout<<"LinkedList Float: "<<endl;
	ListF.Print();
	ListF.Delete();
	cout<<"LinkedList Float After Delete: "<<endl;
	ListF.Print();
	cout<<"Search Result = "<<ListF.Search(1.0);
	cout<<endl<<"isEmpty Result = "<<ListF.isEmpty()<<endl;
	
	LinkedList<phanSo<int> > ListPS;
	ListPS.Insert(phanSo<int>(4, 5));
	ListPS.Insert(phanSo<int>(1, 2));
	ListPS.Insert(phanSo<int>(4, 1));
	ListPS.Insert(phanSo<int>(4, 5));
	cout<<"LinkedList PhanSo: "<<endl;
	ListPS.Print();
	ListPS.Delete();
	cout<<"LinkedList PhanSo After Delete: "<<endl;
	ListPS.Print();
	cout<<"Search Result = "<<ListPS.Search(phanSo<int>(4, 5));
	cout<<endl<<"isEmpty Result = "<<ListPS.isEmpty()<<endl;
	
}
