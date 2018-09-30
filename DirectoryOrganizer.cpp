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
				if (tempPath.substr(tempPath.find_last_of(".") + 1) == "txt") {
					
					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string txtPath = path + "\\txt";
					if (stat(txtPath.c_str(), &s) != 0) {
						_mkdir(txtPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\txt";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of txt check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "docx") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string wordPath = path + "\\Doc";
					if (stat(wordPath.c_str(), &s) != 0) {
						_mkdir(wordPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Doc";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of docx check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "mp3") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string mp3Path = path + "\\mp3";
					if (stat(mp3Path.c_str(), &s) != 0) {
						_mkdir(mp3Path.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\mp3";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of mp3 check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "pdf") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string pdfPath = path + "\\Pdf";
					if (stat(pdfPath.c_str(), &s) != 0) {
						_mkdir(pdfPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\PDF";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of pdf check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "jpg") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string jpegPath = path + "\\Jpg";
					if (stat(jpegPath.c_str(), &s) != 0) {
						_mkdir(jpegPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Jpg";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of jpeg check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "exe") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string exePath = path + "\\exe";
					if (stat(exePath.c_str(), &s) != 0) {
						_mkdir(exePath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\exe";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of exe check


				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "png") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string pngPath = path + "\\png";
					if (stat(pngPath.c_str(), &s) != 0) {
						_mkdir(pngPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Png";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of png check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "doc") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string wordPath = path + "\\Doc";
					if (stat(wordPath.c_str(), &s) != 0) {
						_mkdir(wordPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Doc";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of doc check
				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "zip") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string zipPath = path + "\\Zip";
					if (stat(zipPath.c_str(), &s) != 0) {
						_mkdir(zipPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Zip";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of zip check
				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "jar") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string jarPath = path + "\\Jar";
					if (stat(jarPath.c_str(), &s) != 0) {
						_mkdir(jarPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Jar";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of jar check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "mp4") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string mp4Path = path + "\\mp4";
					if (stat(mp4Path.c_str(), &s) != 0) {
						_mkdir(mp4Path.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\mp4";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of mp4 check
				
				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "7z") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string zPath = path + "\\7z";
					if (stat(zPath.c_str(), &s) != 0) {
						_mkdir(zPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\7z";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of 7z check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "html") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string htmlPath = path + "\\HTML";
					if (stat(htmlPath.c_str(), &s) != 0) {
						_mkdir(htmlPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\HTML";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of jar check

				else if (tempPath.substr(tempPath.find_last_of(".") + 1) == "rar") {

					//Checks to see if sorting dirs exist, if they dont it creates them.
					std::string rarPath = path + "\\Rar";
					if (stat(rarPath.c_str(), &s) != 0) {
						_mkdir(rarPath.c_str());
					}//end of if

					std::cout << files.at(place) << std::endl;
					std::string dirPath = path + "\\Rar";

					fs::path p = tempPath;

					//sets the desired path
					std::string newPath = dirPath + '\\' + p.filename().string();

					//copies and moves the file
					rename(tempPath.c_str(), newPath.c_str());

				}//end of rar check

			}//end of file check

		}//end of stat

		place++;
	}//end of for

	system("Pause");

	return 0;
}//end of main
