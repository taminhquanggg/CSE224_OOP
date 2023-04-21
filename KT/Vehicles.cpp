#include<iostream>
using namespace std;

class Vehicles {
	protected:
		int speed;
	public:
		Vehicles() {
			
		}
		
		Vehicles(int speed) {
			this->speed = speed;
		}
		
		virtual const double maxSpeed()=0;
};

class Ferrari:public Vehicles {
	private:
		string color;
		double numSpeed;
	public:
		Ferrari() {
			
		}
		
		Ferrari(string color, double numSpeed, int speed) {
			this->color = color;
			this->numSpeed = numSpeed;
			this->speed = speed;
		}
		
		const double maxSpeed() {
			return numSpeed*speed;
		}
		
		void input() {
			cin.ignore();
			cout<<"Mau sac: "; getline(cin, color);
			cout<<"He so toc do: "; cin>>numSpeed;
			cout<<"Toc do tieu chuan: "; cin>>speed;
		}
		
		void output() {
			cout<<"FERRARI"<<endl;
			cout<<"Mau sac: "<<color<<endl;
			cout<<"He so toc do: "<<numSpeed<<endl;
			cout<<"Toc do tieu chuan: "<<speed<<endl;
			cout<<"Toc do toi da: "<<maxSpeed()<<endl;
		}
		
		bool operator > (Ferrari f) {
			if (this->maxSpeed()>f.maxSpeed()) {
				return true;
			}
			return false;
		}
};

int main() {
	Ferrari F[100];
	int n;
	cout<<"Nhap so xe Ferrari: "; cin>>n;
	for (int i=0; i<n; i++) {
		cout<<"Nhap thong tin Ferrari thu "<<i+1<<":"<<endl;
		F[i].input();
	}
	cout<<endl<<"DANH SACH FERRARI"<<endl;
	for (int i=0; i<n; i++) {
		cout<<"Thong tin Ferrari thu "<<i+1<<":"<<endl;
		F[i].output();
	}
	
	Ferrari max;
	max = F[0];
	for (int i=1; i<n; i++) {
		if (F[i]>max) {
			max = F[i];
		}
	}
	cout<<endl<<"Ferrari co toc do toi da lon nhat"<<endl;
	max.output();
	return 0;
}
