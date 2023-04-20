#include "Criteria.h"

//Cat_Criteria
Cat_Criteria::Cat_Criteria(const string& category) : category(category) {}

bool Cat_Criteria::matches(const Photo& photo) const{
    return photo.getCategory() == this->category;
}

void Cat_Criteria::print(ostream& os) const {
    os << "Category Criteria: " << category << endl;
}

string Cat_Criteria::getCategory() const { return category; }

//Date_Criteria 
Date_Criteria::Date_Criteria(const Date& start, const Date& end) : start(start), end(end) {}

bool Date_Criteria::matches(const Photo& photo) const{
    Date photoDate = photo.getDate();
    return !(photoDate < start) && photoDate <= end;
}

void Date_Criteria::print(ostream& os) const {
    os << "Date Criteria: " << start.getMonthName() << " " << start.getDay() << ", " << start.getYear()
       << " to " << end.getMonthName() << " " << end.getDay() << ", " << end.getYear() << endl;
}

Date Date_Criteria::getStart() const { return start; }
Date Date_Criteria::getEnd() const { return end; }

//CandD_Criteria
CandD_Criteria::CandD_Criteria(const Date& start, const Date& end, const string& category)
        : Cat_Criteria(category), Date_Criteria(start, end) {}

bool CandD_Criteria::matches(const Photo& photo) const{
    return Cat_Criteria::matches(photo) && Date_Criteria::matches(photo);
}

void CandD_Criteria::print(ostream& os) const {
    os << "Category and Date Criteria: " << getCategory() << " from " << getStart().getMonthName() << " " << getStart().getDay()<< ", " << getStart().getYear() 
    << " to " << getEnd().getMonthName() << " " << getEnd().getDay() << ", " << getEnd().getYear() << endl;
}

ostream& operator<<(ostream& os, const Criteria& criteria) {
    criteria.print(os);
    return os;
}
