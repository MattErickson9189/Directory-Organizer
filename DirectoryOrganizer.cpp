// DownloadOrganizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <sys/stat.h>
#include <sstream>
#include <Windows.h>


namespace fs = std::experimental::filesystem;

//creates stat struct
struct stat s;

//declares the method
std::string GetLastErrorAsString();

int main()
{
	//intializes vector to hold the files
	std::vector<std::string> files;

	//sets the path
	std::string path = "C:\\Users\\matte\\Downloads";

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
				if (tempPath.substr(tempPath.find_last_of(".") + 1) == "txt") {
					
					
					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\TXT";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of if

			}//end of file check

		}//end of stat

		place++;
	}//end of for

	return 0;
}//end of main

 //Method to give reason to why file could not be moved
std::string GetLastErrorAsString()
{
	//Get the error message, if any.
	DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0)
		return std::string(); //No error message has been recorded

	LPSTR messageBuffer = nullptr;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

	std::string message(messageBuffer, size);

	//Free the buffer.
	LocalFree(messageBuffer);

	return message;
}