#include <iostream>
#include <fstream>

using namespace std;

int main(){


	cout << "Welcome to the Directory Organizer congiguration setup!" << endl;
	
	cout << "[1] View current configs\n" << "[2] Change sorting method\n" << "[3] Change directory to be sorted\n";
	cout << "[4} Exit" << endl;

	string method;
	string path;
	int check = 0;

	ifstream settings;
	settings.open("settings.csv");

	while(settings.good()){
		string line;
		getline(settings, line, ',');
		
		if(line.length() > 1 && check == 0){
				method = line;
				check = 1;
		}//end of check
		else if(line.length() > 1 && check == 1){
				path = line;
				break;
		}

	}

	settings.close();

	int x;

	cout << "Enter your choice: ";
	cin >> x;

	if(x == 1){
		cout << "Method: " << method << endl << "Path: " << path << endl;
	}

}
