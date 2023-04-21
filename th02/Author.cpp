#include<iostream>
using namespace std;

class Author{
	private:
		string name;
		string email;
		char gender;
	public:
		
		Author(string name, string email, char gender) {
			this->name = name;
			this->email = email;
			this->gender = gender;
		}
		
		string getName() {
			return this->name;
		}
		
		string getEmail() {
			return this->email;
		}
		
		void setEmail(string email) {
			this->email = email;
		}
		
		char getGender() {
			return this->gender;
		}
		
		string toString() {
			return this->name+" ("+this->gender+") "+" at "+this->email;
		}
};

class Book {
	private: 
		string name;
		Author author;
		double price;
		int qtyInStock;
	public:
		Book(string name, Author author, double price):author(author) {
			this->name = name;
			this->price = price;
			this->qtyInStock = 0;
		}
		
		Book(string name, Author author, double price, int qtyInStock):author(author) {
			this->name = name;
			this->price = price;
			this->qtyInStock = qtyInStock;
		}
		
		string getName() {
			return this->name;
		}
		
		Author getAuthor() {
			return this->author;
		}
		
		double getPrice() {
			return this->price;
		}
		
		void setPrice(double price) {
			this->price = price;
		}
		
		int getQtyInStock() {
			return qtyInStock;
		}
		
		void setQtyInStock(int qtyInStock){
			this->qtyInStock = qtyInStock;
		}
		
		string toString() {
			return "'" + this->name + "' by " + this->author.toString();
		}
		
		string getAuthorName() {
			return this->author.getName();
		}
		
		string getAuthorEmail() {
			return this->author.getEmail();
		}
		
		char getAuthorGender() {
			return this->author.getGender();
		}
};

int main() {
	
	//TestAuthor
	Author X("Ta Minh Quang", "taquang0211@gmail.com", 'm');
	string newEmail;
	cout<<"- Name: "<<X.getName()<<endl;
	cout<<"- Email: "<<X.getEmail()<<endl;
	cout<<"- Gender: "<<X.getGender()<<endl;
	cout<<"To string: "<<X.toString()<<endl;
	cout<<"New email: "; cin>>newEmail;
	X.setEmail(newEmail);
	cout<<"To string: "<<X.toString()<<endl;
	
	//TestBook
	Author auth("Ta Minh Quang", "taquang0211@gmail.com", 'm');
	Book English("English 1", auth, 10000);
	cout<<"- Author name: "<<English.getAuthorName()<<endl;
	cout<<"- Author email: "<<English.getAuthorEmail()<<endl;
	cout<<"- Author gender: "<<English.getAuthorGender()<<endl;
	
	return 0;
	
}
