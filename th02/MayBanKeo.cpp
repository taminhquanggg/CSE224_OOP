#include<iostream>
using namespace std;

class cashRegister {
	private:
		int cashOnHand;
	public:
		cashRegister() {
			cashOnHand = 500;
		}
		
		cashRegister(int cash) {
			cashOnHand = cash;
		}
		
		int getCurrentBalance() {
			return this->cashOnHand;
		}
		
		void acceptAmount(int cash) {
			cashOnHand = cashOnHand + cash;
		}
};

class dispenserType {
	private:
		int numberOfItems;
		int cost;
	public:
		dispenserType() {
			numberOfItems = 50;
			cost = 50;
		}
		
		dispenserType (int numberOfItems,int cost) {
			this->numberOfItems = numberOfItems;
			this->cost = cost;
		}
		
		int getNoOfItems() {
			return this->numberOfItems;
		}
		
		int getCost() {
			return this->cost;
		}
		
		void makeSale() {
			numberOfItems--;
		}
};

void showSelection() {
	cout<<"===MAY BAN KEO TU DONG==="<<endl;
	cout<<"Nhap lua chon cua ban de mua hang"<<endl;
	cout<<"- Nhap 1 de mua Candy"<<endl;
	cout<<"- Nhap 2 de mua Chip"<<endl;
	cout<<"- Nhap 3 de mua Gum"<<endl;
	cout<<"- Nhap 4 de mua Cookie"<<endl;
	cout<<"========================="<<endl;
}

void sellProduct(dispenserType &item, cashRegister &customer) {
	int inputMoney;
	if (item.getNoOfItems()>0) {
		cout<<"Gia cua san pham la: "<<item.getCost()<<endl;
		cout<<"Nhap so tien tra: "; cin>>inputMoney;
		if (inputMoney<item.getCost()) {
			cout<<"So tien khong du !"<<endl;
		}
		else {
			customer.acceptAmount(inputMoney);
			item.makeSale();
			cout<<"Ban da mua hang thanh cong !"<<endl;
		}
	}
	else {
		cout<<"San pham da duoc ban het !"<<endl;
	}
	
}

int main() {
	cashRegister customer;
	dispenserType candies(2, 10);
	dispenserType chips(200, 70);
	dispenserType gum(100, 50);
	dispenserType cookies(50, 90);
	
	int choose;
	showSelection();
	cout<<"Nhap lua chon cua ban: "; cin>>choose;
	while (choose>0 && choose<5) {
		switch (choose) {
			case 1: sellProduct(candies,customer);
					break;
			case 2: sellProduct(chips,customer);
					break;
			case 3: sellProduct(gum,customer);
					break;
			case 4: sellProduct(cookies,customer);
					break;
			default:
				cout<<"Gia tri khong co trong menu."<<endl;
		}
		cout<<"Nhap lua chon cua ban: "; cin>>choose;
	}
		
	
	return 0;
}
