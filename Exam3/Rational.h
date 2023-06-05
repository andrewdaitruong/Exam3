#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Rational
{
private:
	int numerator;
	int denominator;

	//greatest common denominator comparison
	int gcd(int a, int b) 
	{
		if (a == 0 || b == 0)
			return 0;
		
		else if (a == b)
			return a;
		
		else if (a > b)
			return gcd(a - b, b);
		
		else 
			return gcd(a, b - a);
	}

	//if denominator is less than 0, multiply -1 to numerator and denominator in order to have the numerator be negative and the denominator be positive
	void normalize()
	{
		if (denominator < 0)
		{
			denominator *= -1;
			numerator *= -1;
		}

		int temp = gcd(abs(numerator), abs(denominator));
		numerator /= temp;
		denominator /= temp;

	}

public:
	class ZeroDenominator 
	{
	private:
		string rational;

	public:
		ZeroDenominator()
		{}

		ZeroDenominator(Rational r)
		{
			rational = r.toString();
		}

		string toString()
		{
			return rational;
		}
	};

	Rational()
	{
		numerator = 0;
		denominator = 1;
	}

	//returns numberator and denominator into a string
	string toString()
	{
		return to_string(numerator) + "/" + to_string(denominator);
	}

	//checks if two numbers are rational, also throw exception if denominator is 0
	Rational(int newN, int newD)
	{
		numerator = newN;
		denominator = newD;
		if (denominator == 0)
			throw ZeroDenominator(*this);

		normalize();
	}

	//getter for numerator
	int getNumerator() const
	{
		return numerator;
	}

	//setter for numberator
	void setNumerator(int newN)
	{
		numerator = newN;
		normalize();
	}

	//getters for denominator
	int getDenominator() const
	{
		return denominator;
	}

	//setter for denominator. throws exception if denominator is 0
	void setDenominator(int newD)
	{
		denominator = newD;
		if (denominator == 0)
			throw ZeroDenominator(*this);

		normalize();
	}


	//compares two rational numbers if equal
	friend bool operator ==(const Rational& obj1, const Rational& obj2) 
	{
		return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
	}
	
	//compares two ration number if one is less than the other
	friend bool operator <(const Rational& obj1, const Rational& obj2)
	{
		return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
	}

	//outputting the object
	friend ostream& operator << (ostream& out,  Rational obj)
	{
		out << obj.toString();
		return out;
	}


};