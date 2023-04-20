#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <ostream>
#include <string>
#include <iomanip>
#include "Photo.h"
#include "Date.h"

using namespace std;

class Criteria {
		
	public:
		virtual ~Criteria() {};
    		virtual bool matches(const Photo&) const = 0;
    		virtual void print(ostream&) const = 0;
};

class Cat_Criteria : virtual public Criteria {
	public:
	    	Cat_Criteria(const string& category);
	    	bool matches(const Photo&) const override;
	    	void print(ostream&) const override;
	    	string getCategory() const;
	private:
	    	string category;
};

class Date_Criteria : virtual public Criteria {
	public:
	    	Date_Criteria(const Date& start, const Date& end);
	    	bool matches(const Photo&) const override;
	    	void print(ostream&) const override;
	    	
	    	Date getStart() const;
    		Date getEnd() const; 
	private:
	    	Date start;
	    	Date end;
};

class CandD_Criteria : public Cat_Criteria, public Date_Criteria {
	public:
	    	CandD_Criteria(const Date& start, const Date& end, const string& category);
	    	bool matches(const Photo&) const override;
	    	void print(ostream&) const override;
};

ostream& operator<<(ostream& os, const Criteria& criteria);
#endif
