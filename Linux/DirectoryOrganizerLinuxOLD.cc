#include <iostream>
#include <iterator>
#include <unistd.h>
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>
#include <ctime>

//Traverse loops through all files in the directory and if they are a regular file it moves them
void traverse(std::string path, std::string sortBy);

//Decides which sorting function to use
void sendFile(std::string path, std::string sortBy);

//Organizes files based on extension
void extMov(std::string path);

//Organizes files alphabetically
void alphaMov(std::string path);

//Organizes files by month and year
void dateMov(std::string path);

//Checks to see if the path is a regular file or a directory
bool isDir(const char *file);


int main(){

	//On a unix system the max length a username can be is 32 characters long, just to add some extra room the buffer max will be size 50
	int max = 50;

	char *name = (char*)malloc(sizeof(*name) * max);
	
	//getlogin_r returns the user name currently logged in, this is to navigate to the downloads folder	
	getlogin_r(name, max);

	std::string strName = name; 
	std::string path = "/home/" + strName;

	//Runs is used to rename duplicate files, it gets incremented everytime a duplicate file is found
	//runs then gets appended to the end of a duplicate file
	int runs = 0;

	//specifies where to find the settings file and then opens it
	std::ifstream settings;
	settings.open("./config/settings.csv");

	//The option from settings.csv will be stored in sortBy
	std::string sortBy;
	//The second value from settigns.csv will be stored in addedPath
	std::string addedPath;

	//count to make sure the values get stored correctly
	int value = 0;
	while(settings.good()){
		std::string line;
		getline(settings, line, ',');

		if(line.length() > 1 && value == 0){
			sortBy = line;
			value++;
		}//end of if
		if(line.length() > 1 && value == 1){
			addedPath = line;
		}//end of if

	}//end of reading settings file

	//Closes the settings file
	settings.close();

	//appends the path from settings.csv to the path to be sorted
	path = path + addedPath;
    std::cout << "Path: " << path << std::endl;

	traverse(path, sortBy);

}//End of Main


void traverse(std::string path, std::string sortBy){

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
			sendFile(files[i], sortBy);
		}
	}

}//End of traverse


void sendFile(std::string path, std::string sortBy){

	if(sortBy == "ext"){
		extMov(path);
	}//end of extension check
	else if(sortBy == "aplha"){
		alphaMov(path);
	}
	else if(sortBy == "data"){
		dateMov(path);
	}//end of else if

}//end of sendFile

void extMov(std::string path){

	std::string dirPath = path.substr(0,path.find_last_of("/"));

	//Grabs the extention of the file
	std::string ext = path.substr(path.find_last_of(".")+1);

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

}//end of extMov 

//Sorts files alphabetically
void alphaMov(std::string path){


	int runs = 0;

	std::string parentPath = path.substr(0,path.find_last_of('/'));
	std::string fileName = path.substr(path.find_last_of('/')+1);
	char firstLetter = toupper(fileName[0]);

	//Grabs the extention of the file
	std::string ext = path.substr(path.find_last_of(".")+1);

	//Stores the target directory
	std::string aplhaPath = parentPath + "/" + firstLetter + "/";

	std::string destPath;

	if(!isDir(aplhaPath.c_str())){
		
		std::cout << aplhaPath << " Will be created!" << std::endl;
		std::string call = std::string("mkdir ") + aplhaPath;

		const int dir_err = system(call.c_str());
		if (dir_err == -1){
				std::cout << "Error createing directory: " << aplhaPath << std::endl;
				exit(1);
		}//end of nested if
	}//end of if
		 destPath = aplhaPath + fileName;
	
	//Checks to see if the file already exists in the destination directory, if it does 
	//the file gets the run number appended before the extension. This is looped until the file does not exist
	//in the destination directory, then the file is ready to be moved
	while(access(destPath.c_str(), F_OK) != -1){
		int lastIndex = fileName.find_last_of('.');
		runs++;
		std::string rename = fileName.substr(0, lastIndex) + "(" + std::to_string(runs) + ")" + "." + ext;
		destPath = aplhaPath + rename;
	}//end of while
	std::cout << "Dest Path: " << destPath << std::endl;

	//Moves the renamed file to its destination directory
	if(rename(path.c_str(), destPath.c_str())){
		std::cout << "Error moving files!" << std::endl;
		exit(1);
	}//end of if



}//end of alphaMov

void dateMov(std::string path){

    /*
	time_t date = time(0);

	tm *ltm = localtime(&date);

	std::string month = std::string(1 + ltm->tm_mon);
	std::string year = std::string(1970 + ltm->tm_year);
	
	std::cout << "Month: " << month << " Year: " << year << std::endl;
*/
}//end of dateMov

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
