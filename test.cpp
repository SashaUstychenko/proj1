#include <iostream>
#include <algorithm>
#include <numeric>
#include <ostream>
#include <vector>
#include <map>
#include "List.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>
#include <iomanip>
#include <locale>
#include <type_traits>
#include <utility>
#include <tuple>
#include "Prosto.h"
#include <cassert>
#include <memory>
//{{{Factorial
template<int n>
struct GN
{
	static void generate()
	
	{
		GN<n-1>::generate();
		std::cout<<n-1<<" ";
	}
};
template<>
struct GN<0>
{
	static void generate()
	{
		std::cout<<"0 ";
	}
};
template<unsigned int n>
struct factorial
{
	enum
	{
		value = n *factorial<n-1>::value
	};
};
template<>
struct factorial<0>
{
	enum {value = 1};
};
template<long long n>
struct factorial1 :
	std::integral_constant<long long,n * factorial1<n-1>::value>
{ };
template<>
struct factorial1<0> :
	std::integral_constant<long long,1>
{ };

constexpr long long factorial2(long long n)
{
	return (n==0)?1: n * factorial2(n-1);
}
constexpr long long factorial3(long long n)
{
	long long result = 1;
	for(int i = 1;i<=n;++i)
		result *=i;
	return result;
}

//}}}
//Уникнення дублюваню коду через в неконстантних методах
//через const_cast - який знімає константність 
class Student
{
	private:
		char midtermScore;
		char finalScore;
	public:
		char& GetScore(bool midterm)
		{
			return const_cast<char&>(const_cast<const Student*>(this)->GetScore(midterm));		
		}
		const char& GetScore(bool midterm)const
		{
			if(midterm)
			{
				return midtermScore;
			}
			else
			{
				return finalScore;
			}
		}
};
//----------------Mutable-----------------//
class TestMutable
{
	public:
		mutable int mutV;
		int othV;
		TestMutable(int mut_V,int oth_V)
			:mutV(mut_V),othV(oth_V)
		{		 
		}
		void Show()const
		{
			std::cout<<"Mutable :"<<mutV
				 <<std::endl
				 <<"NonMutable :"<<othV
				 <<std::endl;
		}
};
		
std::tuple<int,int,int,int> test11(int a,int b)
{
	return std::make_tuple(a+b,a-b,a*b,a/b);
}

template<typename Incrementable,typename OutputIterator>
void generate_sequence(Incrementable from,Incrementable to,OutputIterator output)
{
	for(Incrementable k = from;k!=to;++k)
		*output++ = k;
}
std::vector<int>insVec(int a,int b)
{
	std::vector<int>temp;
	for(int i = a;i<=b;i=++i)
		temp.push_back(i);

	return temp;
}

int func(int& f,int& b)
{
	f =1;
	b =2;
	return f+b;
}
typedef struct 
{
	long long int foo1;
	long long int foo2;
	long long int foo3;
}big_struct;

class MyDeleter
{
	public:
	void operator()(int * p)
	{

	std::cout<<"MyDeleter\n";
	delete p;}

};
std::unique_ptr<int>foo33()
{
	std::unique_ptr<int>ptr = std::make_unique<int>(55);
	return ptr;
}

class Vec 
{
	public:
		int x;
		int y;
		int z;

};
int main()
{
	
	{
		int rows = 5;
	 	for(int i = 1;i<=rows;i++)
	 	{
			 for(int j =1;j<=i;j++)
			 {
				 if(j==1||j==i)
				 {
				 std::cout<<"*";
				 }
				 else 
				 {
					 std::cout<<" ";
				 }
			 }
			 std::cout<<std::endl;
	        }
	}
	{
		int rows = 7;
		for(int i = 1 ;i<=rows;++i)
		{
			for(int j =rows;j>=i;--j)
			{
				if(j==i||j!=1-rows)
				{
					std::cout<<"*";
				}
				else 
				{
					std::cout<<" ";				
				}
			}
			std::cout<<std::endl;
		}
	}


}

































