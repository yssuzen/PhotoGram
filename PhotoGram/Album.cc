#include "Album.h"

Album::Album(const string& title, const string& description):title(title), description(description) {}

int Album::size() const{
    return photos.size();
}

string Album::getTitle() const{
    return title;
}

Photo* Album::getPhoto(int index) const{
    return photos[index];
}

bool Album::equals(const string& t) const{
    if (title == t){
        return true;
    }
    return false;
}

bool Album::lessThan(Album& album) const{
    if (title < album.title){
        return true;
    }
    return false;
}

void Album::addPhoto(Photo* photo){
    photos.add(photo);
}

void Album::print(ostream& os) const{
    os<<"Album title: "<<title<<endl;
    os<<"Album description: "<<description<<endl;
    os<<"Number of photos in the array: "<<photos.size()<<endl;
}

void Album::display(ostream& os) const{
    print(os);
    os<<"Photos: "<<endl;
    for (int i = 0; i < photos.size(); i++){
        os<<"Photo #"<<(i+1)<<endl;
        photos[i]->display(os);
    }
}

ostream& operator<<(ostream& os, const Album& album){
    album.print(os);
    return os;
}

