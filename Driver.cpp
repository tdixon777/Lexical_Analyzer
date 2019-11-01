#include <iostream>
#include "lexical.h"



using namespace std;

int main()
{
	/*fstream myStream;
	myStream.open("test1.txt");

	if(!myStream.is_open())
		cout<<"ERROR - CANNOT OPEN FILE\n";*/
	
	//string fileName;
	
	//mylex.lexicalAnalysis("test1.txt"); //calling function to perform lexical analysis
	
	lexical mylex;
	mylex.parse(mylex,"incorrectTest.txt");

	int a;
	cin>>a;
}
