#include <iostream>
#include<cmath>
#include <ctime>
#define pi 3.14

using namespace std;

class Shape {
private:
	double shapeArea; 
	double shapeCircumference; 
public:
	double getArea()const { return shapeArea; }
	double getCircum()const { return shapeCircumference; } 
	void setArea(double shape_area) { shapeArea = shape_area; }  
	void setCircum(double circum) { shapeCircumference = circum; } 
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void display() = 0;
};

class Circle :public Shape {
private:
	double radious;
public:
	Circle(double r) { radious = r; }
	void calculateArea() { double CircleArea = pi * pow(radious, 2); setArea(CircleArea); } 
	void calculatePerimeter() { double CirclePerimeter = 2 * pi * radious; setCircum(CirclePerimeter); }
	void display() { cout << "Circle Area: " << getArea() << "\nCircle Perimeter: " << getCircum() <<"\nRadious: "<<radious<<"\nPi: "<<3.14 << endl; }
};

class Rectangle :public Shape {
private:
	double width, height;
public:
	Rectangle(double width_, double height_) { width = width_; height = height_; }
	void calculateArea() { double rectangleArea = width * height; setArea(rectangleArea); }
	void calculatePerimeter() { double rectanglePerimeter = 2 * (width + height); setCircum(rectanglePerimeter); } 
	void display() { cout << "Rectangle Area: " << getArea() << "\nRectangle Perimeter: " << getCircum()<<"\nWidth: "<<width<<"\nHeight: "<<height << endl; } 
};

int main()
{
	srand(static_cast<unsigned>(time(0))); 
	int randomShapeNumber = rand() % 20 + 1; 
	Shape** shapes = new Shape * [randomShapeNumber];  
	cout << randomShapeNumber << " shape has created|\n--------------------" << endl; 
	for (int i = 0; i < randomShapeNumber; i++) { 
		int randomNumber = rand() % 2 + 1;
		if (randomNumber == 1) {
			double randomRadious = rand() % 30 + 1; 
			shapes[i] = new Circle(randomRadious); 
			cout << "----------Circle created----------" << endl; 
			shapes[i]->calculateArea(); shapes[i]->calculatePerimeter();
			shapes[i]->display();
		}
		else {
			double randomWidth = rand() % 30 + 1;
			double randomHeight = rand() % 30 + 1;
			shapes[i] = new Rectangle(randomWidth, randomHeight);
			cout << "----------Rectangle created----------" << endl; 
			shapes[i]->calculateArea(); shapes[i]->calculatePerimeter(); 
			shapes[i]->display(); 
		}
	}
	for (int i = 0; i < randomShapeNumber; i++) {
		delete shapes[i];
	}
	delete[]shapes;
	return 0;
}

