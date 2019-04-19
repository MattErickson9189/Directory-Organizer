#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>

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
		files.push_back(dirp->d_name);
	}

	closedir(dp);

	for(int i = 0; i < files.size(); i++){

		std::cout << files[i] << std::endl;
	}

}


int main(){

	char name[50];
       	getlogin_r(name, 50);

	std::string strName = name; 
	std::string path = "/home/" + strName + "/Downloads/";

	traverse(path,1);
}
