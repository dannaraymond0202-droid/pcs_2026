#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string file = "input.txt";
	ifstream ifs(file);
	if ( ifs.is_open() ) { 
		while( !ifs.eof() ) {
			string location;
			double temp1;
			double temp2;
			double temp3;
			double temp4;
			ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
			double media;
		 	media = (temp1 + temp2 + temp3 + temp4)/4;
			cout<< "A "<<location << " c'è una temperatura media di " << media << "\n";
			
		}
	}
	return 0;
}