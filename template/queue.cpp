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
class Queue {
	private:
		int begin;
		int end;
		T *Data;
		int size;
	public:
		Queue() {
			end = -1;
			begin = 0;
			Data = new T[10];
			size = 10;
			
		}
		
		Queue(T a[], int size) {
			this->size = size;
			Data = new T[size];
			for (int i=0; i<size; i++) {
				enqueue(a[i]);
			}
		}
		
		~Queue() {
			delete[] Data;
		}
		
		bool isFull() {
			if (end == size)
				return true;
			return false;
		}
		
		bool isEmpty() {
			if (end == -1 || begin>end)
				return true;
			return false;
		}
		
		bool enqueue(T q) {
			if (isFull() == true) 
				return false;
			end++;
			Data[end] = q;
			return true;
		}
		
		bool dequeue(T &q) {
			if (isEmpty() == true || begin>end)
				return false;
			q = Data[begin];
			begin++;
			return true;
		}
		
		bool peek(T &q) {
			if (isEmpty() == true) 
				return false;
			q = Data[begin];
			return true;
		}
};

int main() {
	int a[100];
	int n;
	cout<<"n = "; cin>>n;
	for (int i = 0; i<n; i++) {
		cout<<"a["<<i<<"] = "; 
		cin>>a[i];
	}
	Queue<int> q1(a, n);
	int item1;
	while(q1.dequeue(item1)) {
		cout<<item1<<endl;
	}
	
	
	Queue<int> q;
	q.enqueue(0);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	int item;
	int _1stItem;
	if (q.peek(_1stItem)) 
		cout<<endl<<"_1stItem: "<<_1stItem<<endl;
	while(q.dequeue(item)) {
		cout<<item<<endl;
	}
	if (q.isEmpty()) 
		cout<<"Queue rong";
		
	Queue<char> qc;
	qc.enqueue('q');
	qc.enqueue('u');
	qc.enqueue('a');
	qc.enqueue('n');
	qc.enqueue('g');
	char itemC;
	char _1stItemC;
	if (qc.peek(_1stItemC)) 
		cout<<endl<<"_1stItemC: "<<_1stItemC<<endl;
	while(qc.dequeue(itemC)) {
		cout<<itemC<<endl;
	}
	if (qc.isEmpty()) 
		cout<<"Queue rong";
		
	Queue<float> qf;
	qf.enqueue(0.5);
	qf.enqueue(1.2);
	qf.enqueue(2.4);
	float itemF;
	float _1stItemF;
	if (qf.peek(_1stItemF)) 
		cout<<endl<<"_1stItemF: "<<_1stItemF<<endl;
	while(qf.dequeue(itemF)) {
		cout<<itemF<<endl;
	}
	if (qf.isEmpty()) 
		cout<<"Queue rong";


	Queue<SoPhuc<int> > qsp;
	qsp.enqueue(SoPhuc<int>(1, 2));
	qsp.enqueue(SoPhuc<int>(2, 6));
	SoPhuc<int> itemSP;
	while (qsp.dequeue(itemSP)) {
		cout<<itemSP;
	}
	if (qsp.isEmpty()) 
		cout<<"Queue rong";
	return 0;
}
