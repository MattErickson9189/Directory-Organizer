#include <iostream>
#include <fstream>

using namespace std;

int main(){


	cout << "Welcome to the Directory Organizer congiguration setup!" << endl;
	
	cout << "[1] View current configs\n" << "[2] Change sorting method\n" << "[3] Change directory to be sorted\n";
	cout << "[4} Exit" << endl;
		
	ifstream settings;
	settings.open("settings.csv");

	while(settings.good()){
		string line;
		getline(settings, line, ',');
		cout << line << endl;
	}

	settings.close();

}
