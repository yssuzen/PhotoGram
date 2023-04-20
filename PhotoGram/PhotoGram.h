#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Array.h"
#include "Album.h"
#include "Photo.h"
#include "Criteria.h"
#include "View.h"
#include "MediaFactory.h"

using namespace std;

class PhotoGram{
    public:
        PhotoGram();
        ~PhotoGram();

        bool addAlbum(const string&, const string&);
        bool addToAlbum(int, Array<Photo*>&);
        bool uploadPhoto(const string&);
        bool deleteAlbum(int);
        void getPhotos(const Criteria&, Array<Photo*>&);
        
        void displayAlbum(int, View&);
        int printAlbums(View&);
        void displayPhoto(int, View&);
        int printPhotos(View&);



    private:
        Array<Album*> albums;
        Array<Photo*> photos;
        MediaFactory media;

};

#endif
