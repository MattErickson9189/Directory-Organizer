#include "Traverser.h"


Traverser::Traverser(){

}


Traverser::Traverser(Organizer &method){

    this->method = method;

}

void Traverser::traverse(std::string path){

    //Initializes the vector to store files then clears it
    std::vector<std::string> files;
    files.clear();
    int place = 0;

    DIR *dp;
    struct dirent * dirp;
    //Opens up the downloads folder
    if((dp = opendir(path.c_str())) == NULL){
        std::cout << "Error opening " << path << std::endl;
    }

    //Adds all the files to the vector
    while (( dirp = readdir(dp)) != NULL){
        files.push_back(path + dirp->d_name);
    }

    closedir(dp);
    
    for(int i=0; i < files.size(); i++){
        //checks to see if the file is a directory or regular file
        //if it is a regular file it sends it to be renamed and moved
        std::cout << files[i] << std::endl;
        /*
        if(!method.isDir(files[i].c_str())){
            method.sendFile(files[i]);
        }
        */
    }
}

void Traverser::setMethod(Organizer &method){

    this->method = method;

}
