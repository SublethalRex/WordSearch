#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define N_WORDS 10
const int MAX_WORDS = 1024;
const int MAX_WORDS2 = 1024;

void main() {
	ifstream lfile;
	ifstream pfile;
	lfile.open("inputfile.txt");
	pfile.open("pfile.txt");
	ofstream outfile("outputfile.txt");
	int i;
	int j;
	int c;
	if (lfile.fail())
	{
		cout << "Input file opening failed.\n";
		system("pause");
		exit(1);
	}
	if(pfile.fail())
	{
		cout << "Input file opening failed.\n";
		system("pause");
		exit(1);
	}
	/* read 1 string (word) each time */
	string inStr[MAX_WORDS];
	string inStr2[MAX_WORDS2];
	
	for (i = 0; i < MAX_WORDS; i++) {
		if (!lfile.eof()) {
			c = 0;
			j = 0;
			lfile >> inStr[i];


			for (j = 0; j < MAX_WORDS2; j++) { //runs through the paragraph file 
				
				

				if (!pfile.eof()) { //searches each word of the pfile
					pfile >> inStr2[j];
					

					if (inStr[i] == inStr2[j]) { //compares pfile to the list files word
						c++;
						
						
					}
				}



			}
			outfile << inStr[i] << " appears " << c << " times." <<  endl; //puts the word and the amount of times it appeared in the output file
			cout << inStr[i] << " appears " << c << " times." << endl; //prints what wil be placed in the output file
			pfile.seekg(0, ios::beg); //resets the pfile to rescan through it all multiple times
			
			
		}
	}
	lfile.close();
	pfile.close();
	system("pause");



	system("pause");
}