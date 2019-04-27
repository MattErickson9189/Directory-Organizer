#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>


void traverse(std::string path, int r);
void sendFile(std::string path, int r);
bool isDir(const char *file);


int main(){

	//On a unix system the max length a username can be is 32 characters long, just to add some extra room the buffer max will be size 50
	int max = 50;

	char *name = (char*)malloc(sizeof(*name) * max);
	
	//getlogin_r returns the user name currently logged in, this is to navigate to the downloads folder	
	getlogin_r(name, max);

	std::string strName = name; 
	std::string path = "/home/" + strName + "/Downloads/";

	//Runs is used to rename duplicate files, it gets incremented everytime a duplicate file is found
	//runs then gets appended to the end of a duplicate file
	int runs = 0;

	traverse(path,runs);

}//End of Main


void traverse(std::string path, int runs){

	//initializes the vector to store files then clears it.
	std::vector<std::string> files;
	files.clear();
	int place = 0;
	
	DIR *dp;
	struct dirent * dirp;
	//Opens up the downloads folder
	if((dp = opendir(path.c_str())) == NULL){
		std::cout << "Error opening " << path << std::endl;
		exit(1);
	}

	//Adds all the files to the vector
	while (( dirp = readdir(dp)) !=NULL){
		files.push_back(path + dirp->d_name);
	}

	closedir(dp);
	
	for(int i =0; i < files.size(); i++){
	
		//Checks to see if the file is a directory or regular file,
		//if it is a regular file it sends it to be renamed and moved
		if(!isDir(files[i].c_str())){
			sendFile(files[i],runs);
		}
	}

}//End of traverse


void sendFile(std::string path, int runs){

	std::string dirPath = path.substr(0,path.find_last_of("/"));

	//Grabs the extention of the file
	std::string ext = path.substr(path.find_last_of(".")+1);

	//This is so tar.gz files get sent to the tar/ directory
	if(ext == "gz"){
		ext = "tar";
	}

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
		}
	}

	//Grabs the file name with the extension
	std::string fileName = path.substr(path.find_last_of("/")+1);
	if(ext != "tar"){	
		fileName = fileName.substr(0,fileName.find_last_of("."));
	}

	std::string destPath;

	//if the extention is not tar.gz it adds the extension to the filename otherwise it does nothing
	if(ext != "tar"){
		 destPath = dirPath + fileName + "." + ext;
		
	}
	else{
		destPath = dirPath + fileName;
	}

	//Checks to see if the file already exists in the destination directory, if it does 
	//the file gets the run number appended before the extension. This is looped until the file does not exist
	//in the destination directory, then the file is ready to be moved
	while(access(destPath.c_str(), F_OK) != -1){
		int lastIndex = fileName.find_last_of('.');
		runs++;
		std::string rename = fileName.substr(0, lastIndex) + "(" + std::to_string(runs) + ")" + "." + ext;
		destPath = dirPath + rename + ".";
	}
	std::cout << "Dest Path: " << destPath << std::endl;

	//Moves the renamed file to its destination directory
	if(rename(path.c_str(), destPath.c_str())){
		std::cout << "Error moving files!" << std::endl;
		exit(1);
	}

}

//Checks to see if a file is a directory or regular file
bool isDir(const char *file){
	
	DIR *directory = opendir(file);

	if(directory != NULL){
		closedir(directory);
		return true;
	}
	else{
		return false;
	}
}
