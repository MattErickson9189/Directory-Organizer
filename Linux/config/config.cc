#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	ifstream settings;
	settings.open("settings.csv");

	while(settings.good()){
		string line;
		getline(settings, line, ',');
		cout << line << endl;
	}

	settings.close();

}
