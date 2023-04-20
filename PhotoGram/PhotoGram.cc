#include "PhotoGram.h"

PhotoGram::PhotoGram(){}

PhotoGram::~PhotoGram(){
    for (int i = 0; i < albums.size(); i++){
        delete albums[i];
    }
    for (int i = 0; i < photos.size(); i++) {
        delete photos[i];
    }
}

bool PhotoGram::addAlbum(const string& title, const string& description){
    Album* album = media.createAlbum(title, description);
    
    if (albums.add(album)){
        return true;
    }
    else {
        cout<<"Failed to add album!"<<endl;
        return false;
    }
}


bool PhotoGram::addToAlbum(int index, Array<Photo*>& p){
    if (index < 0){
        cout<<"Failed to add album!"<<endl;
        return false;
    }
    else {

        for (int i = 0; i < p.size(); i++) {
            albums[index]->addPhoto(p[i]);
        }
        return true;
    }
}
   
bool PhotoGram::uploadPhoto(const string& title) {
    Photo* photo = media.uploadPhoto(title);
    photos.add(photo);
    return true;
}

bool PhotoGram::deleteAlbum(int index) {
    if(index < 0 || index>= albums.size() || index > MAX_ARRAY){
         cout<<"Failed to delete album!"<<endl;
        return false;
    }
    else{
        //delete albums[index];
        albums.remove(index);
        return true;
    }
}

void PhotoGram::getPhotos(const Criteria& criteria, Array<Photo*>& array) {
    for (int i = 0; i < photos.size(); i++) {
        if (criteria.matches(*photos[i])) {
            array.add(photos[i]);
        }
    }
    for (int i = 0; i < array.size(); i++) {
        array[i]->print(cout);
    }
}

void PhotoGram::displayAlbum(int index, View& view) {
    if (index < 0 || index >= albums.size() || index > MAX_ARRAY) {
        cout << "Failed to display album because of the invalid index!" << endl;
    }
    else {
        view.displayAlbum(*albums[index]);
    }
}

int PhotoGram::printAlbums(View& view) {
    view.printAlbums(albums);
    return albums.size();
}

void PhotoGram::displayPhoto(int index, View& view) {
    if (index < 0 || index >= photos.size() || index > MAX_ARRAY) {
        cout << "Failed to display photo because of the invalid index!" << endl;
    }
    else {
        view.displayPhoto(*photos[index]);
    }
}

int PhotoGram::printPhotos(View& view) {
    view.printPhotos(photos);
    return photos.size();
}
