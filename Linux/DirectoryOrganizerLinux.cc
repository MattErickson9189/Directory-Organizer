#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>



bool traverse(std::string path, int r);
void sendFile(std::string path, int r);
bool isDir(const char *file);


int main(){

	char name[50];
       	getlogin_r(name, 50);

	std::string strName = name; 
	std::string path = "/home/" + strName + "/Downloads/";

	int runs = 0;

	while(traverse(path,runs)){
		runs++;
		traverse(path,runs);
	}
}//End of Main


bool traverse(std::string path, int runs){

	std::vector<std::string> files;
	files.clear();
	int place = 0;
	bool check = false; 
	
	DIR *dp;
	struct dirent * dirp;
	if((dp = opendir(path.c_str())) == NULL){
		std::cout << "Error opening " << path << std::endl;
		return 1;
	}

	while (( dirp = readdir(dp)) !=NULL){
		files.push_back(path + dirp->d_name);
	}

	closedir(dp);
	
	for(int i =0; i < files.size(); i++){
		
		if(!isDir(files[i].c_str())){

			sendFile(files[i],runs);
			check = true;
		}
	}

	return check;

}//End of traverse


void sendFile(std::string path, int runs){

	std::string dirPath = path.substr(0,path.find_last_of("/"));

	std::string ext = path.substr(path.find_last_of(".")+1);

	if(ext == "gz"){
		ext = "tar";
	}

	dirPath = dirPath + "/" + ext + '/';

	if(!isDir(dirPath.c_str())){
	
		std::string call = std::string("mkdir ") + dirPath;
		const int dir_err = system(call.c_str());
		if (dir_err == -1){
				std::cout << "Error createing directory: " << dirPath << std::endl;
				exit(1);
		}
	}

	std::string fileName = path.substr(path.find_last_of("/")+1);
	if(ext != "tar"){	
		fileName = fileName.substr(0,fileName.find_last_of("."));
	}

	//Gets to see if there is already a file with the same name in the directory
	//If there is, it appends the run count onto the fileName
	if(runs > 0){
		int lastIndex = fileName.find_last_of('.');
		fileName = fileName.substr(0, lastIndex) + "(" + std::to_string(runs) + ")" + "." + ext;
	}// end if

	std::string destPath;

	if(ext != "tar"){
		 destPath = dirPath + fileName + "." + ext;
		
	}
	else{
		destPath = dirPath + fileName;
	}

	std::cout << "Dest Path: " << destPath << std::endl;

	if(rename(path.c_str(), destPath.c_str())){
			std::cout << "Error moving files!" << std::endl;
			exit(1);
	}

}

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
