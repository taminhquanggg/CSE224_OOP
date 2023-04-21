#include<iostream>
using namespace std;

class VanDongVien {
	private:
		string hoten;
		int tuoi;
		string monthidau;
		float cannang;
		float chieucao;
		
	public:
		VanDongVien(){
			
		}
		VanDongVien(string hoten, int tuoi, string monthidau, float cannang, float chieucao) {
			this->hoten = hoten;
			this->tuoi = tuoi;
			this->monthidau = monthidau;
			this->cannang = cannang;
			this->chieucao = chieucao;
		}
		
		~VanDongVien(){
			
		}
		
		friend istream& operator >> (istream &in, VanDongVien &VDV);
		friend ostream& operator << (ostream &out, VanDongVien VDV);
		friend 
};
