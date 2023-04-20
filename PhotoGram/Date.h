#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date {
	public:
		//constructor
		Date();
		Date(int year, int month, int day);
		Date(const Date&);
		
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);
		
		//getters
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		string getMonthName() const;
		
		//other
		void incDate();
		void addDays(int);
		void print() const;
		
		//overloaded operators
		bool operator<(const Date& other) const;
		bool operator==(const Date& other) const;
		bool operator<=(const Date& other) const;
		friend ostream& operator<<(ostream& os, const Date& date);
		
	
	private:
		//functions
		int getMaxDay() const;	
	
		//variables
		int day;
		int month;
		int year;
	
};
#endif

