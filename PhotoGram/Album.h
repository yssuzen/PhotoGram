#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Photo.h"
#include "Array.h"

using namespace std;

class Album {
		
	public:
		//constructors
        Album(const string&, const string&);
		//Album(const Album&);
		
		//getters
		int size() const;
		string getTitle() const;
		//Photo* getPhoto(const string&) const;
		Photo* getPhoto(int) const;


		//other
		bool equals(const string&) const;
		bool lessThan(Album&) const;
		void addPhoto(Photo*);
		//bool addPhoto(int, Photo*);
		//Photo* removePhoto(const string&);
		//Photo* removePhoto(int);
		void print(ostream&) const;
		void display(ostream&) const;
	
	private:
		string title;
		string description;
		Array<Photo*> photos;
};

ostream& operator<<(ostream&, const Album&);
#endif
