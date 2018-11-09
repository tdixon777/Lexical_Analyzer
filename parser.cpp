#include "parser.h"
//#include "lexical.h"
#include <iostream>

using namespace std;
void program(lexical &lexObject)
{
	cout<< "Enter program\n";
	lexObject.lex();
	if(lexObject.nextToken != ID)
	{	
		cout<<lexObject.nextToken;
	cout<<"error1 on line \n";
	}
	else
	{
		lexObject.lex();
		if(lexObject.nextToken != ID)
			cout<<"error2 on line \n";
		else
		{
			lexObject.lex();
			if(lexObject.nextToken != SEMICOLON)	
				cout<<"error3 on line \n";
			else
				cout<<"program line is correct\n";
		}
	}

	
}
void body(lexical &lexObject)
{
	cout<<"Enter body\n";
}
void declaration(lexical &lexObject)
{
	cout<<"Enter declaration\n";
}
void idlist(lexical &lexObject)
{
	cout<<"Enter idlist\n";
}
void idlist2(lexical &lexObject)
{
	cout<<"Enter idlist2\n";
}
void statlist(lexical &lexObject)
{
	cout<<"Enter statlist\n";
}
void statlist2(lexical &lexObject)
{
	cout<<"Enter statlist2\n";
}
void statement(lexical &lexObject)
{
	cout<<"Enter statement\n";
}
void expression(lexical &lexObject)
{
	cout<<"Enter expression\n";
}
void expression2(lexical &lexObject)
{
	cout<<"Enter expression2\n";
}
void term(lexical &lexObject)
{
	cout<<"Enter term\n";
}
void term2(lexical &lexObject)
{
	cout<<"Enter term2\n";
}
void factor(lexical &lexObject)
{
	cout<<"Enter factor\n";
}

/*void parseprogram(lexical &lexObject)
{
	if(lexObject.nextToken != ID)
		cout<<"error on line ";
	else
	{
		lexObject.lex();
		if(lexObject.nextToken != ID)*/

