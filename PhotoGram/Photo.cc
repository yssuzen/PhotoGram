#include "Photo.h"

Photo::Photo(const string& title, const string& category, const Date& date, const string& content)
: title(title), category(category), date(date), content(content) {}

bool Photo::equals(const string& title) const{
	return this->title == title;
}

const Date& Photo::getDate() const{
	return date;
}

const string& Photo::getCategory() const{
	return category;
}

void Photo::print(ostream& os) const{
	os << title << ", " << category << ", ";
	date.print();
	os << ", " << content;
}

void Photo::display(ostream& os) const{
	os << "Title: " << title << endl;
	os << "Category: " << category << endl;
	os << "Date: ";
	date.print();
	os << endl;
	os << "Content: " << content << endl;
}

ostream& operator<<(ostream& os, const Photo& photo){
	photo.display(os);
	return os;
}

