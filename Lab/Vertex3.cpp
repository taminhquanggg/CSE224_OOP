#include<iostream>
#include<vector>
#include <sstream>
#include<math.h>
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
		
		double getPerimeter() const {
			double result = 0;
			
			for (int i=0; i<vertices.size(); i++) {
				int postNext = i+1;
				if ((i+1) == vertices.size()) {
					postNext = 0;
				}
				double xResult = vertices[i].getX() - vertices[postNext].getX();
				double yResult = vertices[i].getY() - vertices[postNext].getY();
				double kq = sqrt(xResult*xResult + yResult*yResult);
				result = result + kq;
			}
			return result;
		}
		
		virtual double getArea() const {
			return(0);
		}
		
		double getMinX() const {
			if (vertices.size() == 0) {
				return 0;
			}
			
			double minX = vertices[0].getX();
			for (int i=1; i<vertices.size(); i++) {
				if (vertices[i].getX() < minX) {
					minX = vertices[i].getX();
				}
			}
			
			return minX;
		}
	   	double getMaxX() const {
	   		if (vertices.size() == 0) {
				return 0;
			}
			
			double maxX = vertices[0].getX();
			for (int i=1; i<vertices.size(); i++) {
				if (vertices[i].getX() > maxX) {
					maxX = vertices[i].getX();
				}
			}
			
			return maxX;
		}
	   	double getMinY() const {
	   		if (vertices.size() == 0) {
				return 0;
			}
			
			double minY = vertices[0].getY();
			for (int i=1; i<vertices.size(); i++) {
				if (vertices[i].getY() < minY) {
					minY = vertices[i].getY();
				}
			}
			
			return minY;
		}
	   	double getMaxY() const {
	   		if (vertices.size() == 0) {
				return 0;
			}
			
			double maxY = vertices[0].getY();
			for (int i=1; i<vertices.size(); i++) {
				if (vertices[i].getY() > maxY) {
					maxY = vertices[i].getY();
				}
			}
			
			return maxY;
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
		
		double getArea() const {
			double xMin = getMinX();
			double xMax = getMaxX();
			double yMin = getMinY();
			double yMax = getMaxY();
			
			double result = (xMax-xMin) * (yMax-yMin);
			return (result/2);
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
		
		double getArea() const {
			double xMin = getMinX();
			double xMax = getMaxX();
			double yMin = getMinY();
			double yMax = getMaxY();
			
			double result = (xMax-xMin) * (yMax-yMin);
			return result;
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
	
	Square S;
	Vertex s1(0,0);
	Vertex s2(10,0);
	Vertex s3(10,10);
	Vertex s4(0,10);
	S.addVertex(s1);
	S.addVertex(s2);
	S.addVertex(s3);
	S.addVertex(s4);
	
	SegList *triangleArea = &T;
	SegList *squareArea = &S;
	
	
	cout<<"Triangle: "<<T.getSpec()<<endl;
	cout <<"Perimeter: " <<T.getPerimeter() << endl;
	cout << "Area: " << triangleArea->getArea() << endl;

	cout<<"Square: "<<S.getSpec()<<endl;
	cout <<"Perimeter: " <<S.getPerimeter() << endl;
	cout << "Area: " << squareArea->getArea() << endl;
	return 0;
	
}
