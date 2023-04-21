#include<iostream>
#include<vector>
#include <sstream>
using namespace std;

class Vertex {
	protected:
		int x;
		int y;
	public:
		Vertex(){
			x = 0;
			y = 0;
		}
		Vertex(int x, int y){
			this->x = x;
			this->y = y;
		}
		
		string getSpec() const {
			stringstream ss;
			ss << "x=" << x << ",y=" << y;
			return(ss.str());
		}
		
		int  getX() const {
			return x;
		}
   		int  getY() const {
		   return y;
		}
};

class SegList{
	protected:
		vector<Vertex> vertices;
	public:
		SegList() {
		}
		~SegList(){
		}
		
		void addVertex(Vertex vertex) {
			vertices.push_back(vertex);
		}
		
		string getSpec() const{
			string spec;
			for(int i=0; i<vertices.size(); i++) {
				if(i != 0)
					spec += ",";
				spec += vertices[i].getSpec();
			}

			return(spec);
		}
};

class Triangle:public SegList {
	public:
		Triangle() {
			
		}
		~Triangle() {
			
		}
		
		string getSpec() const {
			string spec = "type=Triangle,";
		   	spec += SegList::getSpec();
		   	return(spec);
		}
};

class Square:public SegList {
	public:
		Square() {
			
		}
		~Square() {
			
		}
		
		string getSpec() const {
			string spec = "type=Square,";
		   	spec += SegList::getSpec();
		   	return(spec);
		}
};
int main(){
	Triangle T;
	Vertex t1(0,0);
	Vertex t2(10,0);
	Vertex t3(5,5);
	T.addVertex(t1);
	T.addVertex(t2);
	T.addVertex(t3);
	cout<<"Triangle: "<<T.getSpec()<<endl;
	
	Square S;
	Vertex s1(0,0);
	Vertex s2(10,0);
	Vertex s3(10,10);
	Vertex s4(0,10);
	S.addVertex(s1);
	S.addVertex(s2);
	S.addVertex(s3);
	S.addVertex(s4);
	cout<<"Square: "<<S.getSpec()<<endl;
	return 0;
	
}
