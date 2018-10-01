// DownloadOrganizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <sys/stat.h>
#include <sstream>
#include <Windows.h>
#include <direct.h>
#include <Lmcons.h>

namespace fs = std::experimental::filesystem;

//creates stat struct
struct stat s;

void sendFile(std::string path);

int main()
{
	//intializes vector to hold the files
	std::vector<std::string> files;

	//gets username 
	TCHAR userName[UNLEN + 1];
	DWORD size = UNLEN + 1;

	GetUserName((TCHAR*)userName, &size);
	
	std::string name;
	name = userName;
	
	//sets the path
	std::string path = "C:\\Users\\" + name+ "\\Downloads";

	files.clear();

	int place = 0;
	
	for (auto & p : fs::directory_iterator(path)) {
		//converts file path to a string 
		std::stringstream ss;

		std::string tempPath = path;

		//stores the path in a string
		ss << p;
		files.push_back(ss.str());
		tempPath = files.at(place);
		
		if (stat(tempPath.c_str(), &s) == 0)
		{
			if (s.st_mode & S_IFREG)
			{
				sendFile(tempPath);
				
			}//end of file check
		}//end of stat
		
		place++;
	}//end of for
	
	system("Pause");

	return 0;
}//end of main

//This function sorts the files into desired folders
void sendFile(std::string path) {
	
	//gets parent path dir
	std::string parent = path.substr(0, path.find_last_of("/\\"));
	
	//gets the file ext
	std::string fileExt = path.substr(path.find_last_of(".") + 1);

	//sets the directory path
	std::string dirpath = parent + "\\" + fileExt;
	
	if (stat(dirpath.c_str(), &s) != 0) {
		_mkdir(dirpath.c_str());
	}//end of if

	fs::path p = path;
	
	//sets the desired path
	std::string newPath = dirpath + "\\" + p.filename().string();

	//prints the new destination
	std::cout << newPath << std::endl;

	//copies and moves the file
	rename(path.c_str(), newPath.c_str());

}//end of sendFile