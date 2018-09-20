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


namespace fs = std::experimental::filesystem;

//creates stat struct
struct stat s;


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

		//Checks to see if sorting dirs exist, if they dont it creates them.
		std::string txtPath = path + "\\txt";
		if (stat(txtPath.c_str(), &s) != 0) {
			_mkdir(txtPath.c_str());
		}
		std::string wordPath = path + "\\Doc";
		if (stat(wordPath.c_str(), &s) != 0) {
			_mkdir(wordPath.c_str());
		}
		std::string mp3Path = path + "\\mp3";
		if (stat(mp3Path.c_str(), &s) != 0) {
			_mkdir(mp3Path.c_str());
		}
		std::string pdfPath = path + "\\Pdf";
		if (stat(pdfPath.c_str(), &s) != 0) {
			_mkdir(pdfPath.c_str());
		}
		std::string jpegPath = path + "\\Jpeg";
		if (stat(jpegPath.c_str(), &s) != 0) {
			_mkdir(jpegPath.c_str());
		}
		std::string pngPath = path + "\\png";
		if (stat(pngPath.c_str(), &s) != 0) {
			_mkdir(pngPath.c_str());
		}
		std::string otherPath = path + "\\Other";
		if (stat(otherPath.c_str(), &s) != 0) {
			_mkdir(otherPath.c_str());
		}


		if (stat(tempPath.c_str(), &s) == 0)
		{
			if (s.st_mode & S_IFREG)
			{
				if (tempPath.substr(tempPath.find_last_of(".") + 1) == "txt") {
					
					
					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\txt";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of txt check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "docx") {

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Doc";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of docx check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "mp3") {

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\mp3";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of mp3 check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "pdf") {

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\PDF";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of pdf check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "jpeg") {

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Jpeg";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of jpeg check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "png") {

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Png";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of png check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "doc") {

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Doc";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of doc check
				else {
					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Other";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());
				}
			}//end of file check

		}//end of stat

		place++;
	}//end of for

	return 0;
}//end of main
