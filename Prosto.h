#include <iostream>
#include <cmath>
#include <pthread.h>
#include <string>

struct Point
{
	double x;
	double y;
	
	Point(double x,double y)
		:x(x),y(y)
	{}
};



class Shape
{
	public:
		virtual ~Shape() = default;
		virtual double get_surface()const = 0;
		virtual void describe_object()const
		{ std::cout<<"this is shape"<<std::endl;}
		double get_doubled_surfacce()const
		{return 2*get_surface();}
};

class Square : public Shape 
{
	private:
		Point top_left;
		double side_length;
 	public:
		Square(const Point& top_left,double side_length)
			:top_left(top_left),side_length(side_length)
		{}
	       	double get_surface() const override  
		{
			return side_length * side_length;
	    	}
		void describe_object() const override 
		{
			std::cout<<"this is square starting at "
				 <<top_left.x<<", "<<top_left.y
				 <<" with a lenght of "
				 <<side_length
				 <<std::endl;
		}

};
class Circle :public Shape
{
	private:
		Point center;
		double radius;
	public:
		Circle(const Point& center,double radius)
			:center(center),radius(radius)
		{}

		double get_surface()const override
		{
			return std::pow(radius,2)*M_PI;
		}
		double get_diametr()const
		{
			return std::pow(radius,2);
		}


};



class tester 
{
	private:
		int priv_num =42;
	public:
		tester(){};
		~tester(){};

		int get_privNum()
		{

			return this->priv_num;
		}


};
class Dog
{
	private:
		std::string name;
	public:
		Dog(std::string name)
		{
			this->name = name;
		}
		~Dog()
		{ }
		std::string getName() const
		{
			return this->name;
		}


};






