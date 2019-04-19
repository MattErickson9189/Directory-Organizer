#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>


bool traverse(std::string path, int r);
void sendFile(std::string path, int r);


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

	for(int i = 0; i < files.size(); i++){
		sendFile(files[i],runs);
	}

}//End of traverse


void sendFile(std::string path, int runs){

	std::string dirPath = path.substr(0,path.find_last_of("/"));

	std::string ext = path.substr(path.find_last_of(".")+1);

	dirPath = dirPath + "/" + ext;

	std::cout << "This will be the created directory: " << dirPath << std::endl;

}
