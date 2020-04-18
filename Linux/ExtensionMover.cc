#include "ExtensionMover.h"

void ExtensionMover::sendFile(std::string path){
    std::string dirPath = path.substr(0,path.find_last_of("/"));

    //Checks to see if the file does not have an extension
    int index = path.find_last_of(".");
    if(index == -1){
        return;
    }
    //Grabs the extention of the file
    std::string ext = path.substr(index+1);

    //flag to help rename files when there are duplicates
    int runs = 0;

    //This is so tar.gz files get sent to the tar/ directory
    if(ext == "gz"){
        ext = "tar";
    }//end of if

    //sets the string with the desired dest path
    dirPath = dirPath + "/" + ext + '/';

    //Checks to see if the destination path already exists or not, if it does not it creates the 
    //desired directory
    if(!isDir(dirPath.c_str())){
    
        std::string call = std::string("mkdir ") + dirPath;
        const int dir_err = system(call.c_str());
        if (dir_err == -1){
                std::cout << "Error createing directory: " << dirPath << std::endl;
                exit(1);
        }//end of nested if
    }//end of if

    //Grabs the file name with the extension
    std::string fileName = path.substr(path.find_last_of("/")+1);
    if(ext != "tar"){	
        fileName = fileName.substr(0,fileName.find_last_of("."));
    }//end of if

    std::string destPath;

    //if the extention is not tar.gz it adds the extension to the filename otherwise it does nothing
    if(ext != "tar"){
        destPath = dirPath + fileName + "." + ext;
        
    }//end of if
    else{
        destPath = dirPath + fileName;
    }//end of else

    //Checks to see if the file already exists in the destination directory, if it does 
    //the file gets the run number appended before the extension. This is looped until the file does not exist
    //in the destination directory, then the file is ready to be moved
    while(access(destPath.c_str(), F_OK) != -1){
        int lastIndex = fileName.find_last_of('.');
        runs++;
        std::string rename = fileName.substr(0, lastIndex) + "(" + std::to_string(runs) + ")" + "." + ext;
        destPath = dirPath + rename;
    }//end of while
    std::cout << "Dest Path: " << destPath << std::endl;

    //Moves the renamed file to its destination directory
    if(rename(path.c_str(), destPath.c_str())){
        std::cout << "Error moving files!" << std::endl;
        exit(1);
    }//end of if

}
