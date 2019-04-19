#include <iostream>
#include <unistd.h>


int main(){

	char name[50];
       	getlogin_r(name, 50);

	std::cout << name << std::endl;


}
