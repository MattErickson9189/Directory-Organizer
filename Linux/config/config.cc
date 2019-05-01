#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>

using namespace std;

int main(){


	//gets the login name and sets up path to the settings folder
	
	//sets the buffer for getlogin_r
	int max = 50;

	char *name = (char*)malloc(sizeof(*name) * max);

	//gets the login name of the user thats currently logged in
	getlogin_r(name, max);

	string strName = name;
	string configPath = "/home/" + strName + "/Directory-Organizer/config/settings.csv";


	cout << "Welcome to the Directory Organizer congiguration setup!" << endl;
	
	string method;
	string path;
	int check = 0;

	ifstream settings;
	settings.open(configPath);
	ofstream output;

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
		}//end of else
	}//end of while

	int x;

	while(x != 4){
		
		cout << "[1] View current configs\n" << "[2] Change sorting method\n" << "[3] Change directory to be sorted\n";
		cout << "[4} Exit" << endl;

		cout << "Enter your choice: ";
		cin >> x;

		if(x == 1){
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


			cout << endl << "Method: " << method << endl << "Path: " << path << endl << endl;

		}//end of if

		else if(x ==2){

			output.open(configPath);
			vector<string> choices = {"aplha", "ext", "date"};

			cout << endl << "Which method would you like to use?" << endl;
			cout << "[1] aplha\n" << "[2] ext\n" << "[3] date\n" << endl;

			int c;
			cin >> c;
			
			string choice = choices.at(c-1);
			
			cout << "Sorting method is now: " << choice << endl << endl;
			method = choice;				
			output << choice << "," << path << "," << endl;
			output.close();
		}//end of else if
		
		else if(x == 3){
			
			output.open(configPath);
			string input;

			cout << endl << "Enter in the new path: ";

			cin >> input;
			path = input; 

			output << method << "," << path << "," << endl;
			output.close();
		}//end of else if

	}//end of while
	cout << "\nGoodbye!" << endl;
}//end of main
