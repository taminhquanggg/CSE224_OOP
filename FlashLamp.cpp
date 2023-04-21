#include<iostream>
using namespace std;

class Battery {
	private:
		int energy;
	public:
		Battery() {
			energy = 10;
		}
		void setEnergy (int energy) {
			this->energy = energy;
		}
		int getEnergy() {
			return this->energy;
		}
		void decreaseEnergy() {
			this->energy = this->energy - 2;
		}
};

class FlashLamp {
	private:
		bool status;
		Battery battery;
	public:
		FlashLamp() {
			status = false;
			battery.setBattery(0);
		}
		int setBattery(Battery b) {
			int energy = b.getEnergy();
			this->battery.setBattery(energy);
		}
		
		int getBatteryInfo() {
			return this->battery.getEnergy();
		}
		
		void turnOn() {
			status = true;
			cout<<"Den bat - ";
			if (getBatteryInfo()>0) {
				cout<<"den sang"<<endl;
			}
			else {
				cout<<"den khong sang"<<endl;
			}
			battery.decreaseEnergy();
		}
		
		void turnOff() {
			status = false;
			cout<<"Den tat"<<endl;
		}
};

class TestFlashLamp {
	public:
		void main() {
			Battery pin;
			FlashLamp den;
			pin.setEnergy(50);
			cout<<pin.getEnergy();
			den.setBattery(pin);
			for (int i = 0; i<10; i++) {
				den.turnOn();
				den.turnOff();
			}
			cout<<den.getBatteryInfo();
		}
};

int main() {
	TestFlashLamp test;
	test.main();
	return 0;
}
