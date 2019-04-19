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

	traverse(path,1);
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
		}
	}

}//End of traverse


void sendFile(std::string path, int runs){

	std::string dirPath = path.substr(0,path.find_last_of("/"));

	std::string ext = path.substr(path.find_last_of(".")+1);

	dirPath = dirPath + "/" + ext;

	if(!isDir(dirPath.c_str())){
//		mkdir(dirPath);
	}
	
	std::string fileName = path.substr(path.find_last_of("/")+1);
	if(ext != "gz"){	
		fileName = fileName.substr(0,fileName.find_last_of("."));
	}
	std::cout << fileName << std::endl;

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
