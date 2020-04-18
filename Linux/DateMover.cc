#include "DateMover.h"
#include <string>
#include <time.h>
#include <map>
#include <iostream>
#include <unistd.h>

void DateMover::sendFile(std::string path){

    //set up map for month
    std::map<int,std::string> monthMap;
    std::map<int,std::string>::iterator it;
    
    monthMap[1]="January";
    monthMap[2]="February";
    monthMap[3]="March";
    monthMap[4]="April";
    monthMap[5]="May";
    monthMap[6]="June";
    monthMap[7]="July";
    monthMap[8]="August";
    monthMap[9]="September";
    monthMap[10]="October";
    monthMap[11]="November";
    monthMap[12]="December";
    
    int runs = 0;
    
    time_t  currentTime = time(NULL);
    struct tm *time = localtime(&currentTime);

    int m = time->tm_mon + 1;
    int year = time->tm_year + 1900;

    std::string month = monthMap.find(m)->second;

    std::string dirPath = path.substr(0,path.find_last_of("/"));
    dirPath = dirPath + "/" + month + std::to_string(year) + "/";

    //Checks to see if the destination path already exists or not, makes it if it doesnt
    if(!isDir(dirPath.c_str())){
        std::string call = std::string("mkdir ") + dirPath;
        const int dir_err = system(call.c_str());
        if(dir_err == -1){
            std::cout << "Error creating directory: " << dirPath << std::endl;
            exit(1);
        }//end of nested if
    }//end of if

    //grab the file name 
    std::string fileName = path.substr(path.find_last_of("/")+1);
    std::string destPath = dirPath + fileName;

    //Checks to see if the file already exists in this directory, if it does append a number to it
    while(access(destPath.c_str(), F_OK) != -1){
        int lastIndex = fileName.find_last_of(".");
        runs++;
        //grab the extension
        std::string ext = path.substr(path.find_last_of(".")+1);
        std::string rename = fileName.substr(0, lastIndex) + "(" + std::to_string(runs) + ")" + "." + ext;
        destPath = dirPath + rename;
    }//end of while

    std::cout << "Dest Path: " << destPath << std::endl;

    //moves the file to its destination
    if(rename(path.c_str(), destPath.c_str())){
        std::cout << "Error Moving Files!" << std::endl;
        exit(1);
    }//end of if

}
