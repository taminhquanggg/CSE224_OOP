#include<iostream>
using namespace std;

class Candidate {
	private:
		string id;
		string name;
		string date;
		float math;
		float liter;
		float english;
	public:
		Candidate() {
			
		}
		
		Candidate(string id, string name, string date, float math, float liter, float english) {
			this->id = id;
			this->name = name;
			this->date = date;
			this->math = math;
			this->liter = liter;
			this->english = english;
		}
		
		~Candidate() {
			
		}
};

class TestCandidate {
	private:
		Candidate X;
	public:
		TestCandidate(string id, string name, string date, float math, float liter, float english): X(id, name, date, math, liter, english){
			
		}
		
		~TestCandidate() {
			
		}
};

int main() {
	
	int n;
	string id;
	string name;
	string date;
	float math;
	float liter;
	float english;
	TestCandidate TC[n];
	cout<<"n = "; cin>>n;
	for (int i = 0; i<n; i++) {
		
	}
}
