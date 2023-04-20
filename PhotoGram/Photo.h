#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Photo {
		
	public:
		//constructor
		Photo(const string& title, const string& category, const Date& date, const string& content);
		
		//other
		bool equals(const string& title) const;
		const Date& getDate() const; 
		const string& getCategory() const;
		void print(ostream&) const;
		void display(ostream&) const;
	
	private:
	
		//variables
		string title;
		string category;
		string content;
		Date date;
	
};
ostream& operator<<(ostream& os, const Photo& photo);
#endif
