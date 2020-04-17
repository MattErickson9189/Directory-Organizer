#include "DirectoryOrganizer.h"
#include <string>

DirectoryOrganizer::DirectoryOrganizer(Traverser &traverser, Organizer *organizeMethod){
    
    this->traverser = traverser;
    this->organizeMethod = organizeMethod;
    this->traverser.setMethod(this->organizeMethod);
}

void DirectoryOrganizer::organize(std::string path){
    this->traverser.traverse(path);
}


