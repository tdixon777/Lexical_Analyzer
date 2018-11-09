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
	lexical mylex;
	
	//mylex.lexicalAnalysis("test1.txt"); //calling function to perform lexical analysis
	
	
	mylex.parse(mylex,"incorrectTest.txt");

	int a;
	cin>>a;
}
