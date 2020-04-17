#include "Organizer.h"

bool Organizer::isDir(const char *file){

    DIR *directory = opendir(file);

    if(directory != NULL){
        closedir(directory);
        return true;
    }
    else{
        return false;
    }  
}
