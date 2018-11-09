#include <iostream>
#include "lexical.h"
#include <string>
#include <ctype.h>

using namespace std;
int w;
lexical::lexical()
{	
}

void lexical::lexicalAnalysis(string fileName) //same as lex() in book
{
	//ofstream myStream;
	myStream.open(fileName);

	if(!myStream.is_open())
		cout<<"ERROR - CANNOT OPEN FILE\n";
	else
	{
		getChar();
		do
		{
			lex();
		}
		while (!myStream.eof());

		myStream.close();
	}
}

void lexical::parse(lexical &lexObject, string fileName)
{
	myStream.open(fileName);

	if(!myStream.is_open())
		cout<<"ERROR - CANNOT OPEN FILE\n";
	else
	{
		cout<<"program is open"<<endl;
	}
	getChar();// maybe
	lex();
	program(lexObject);


}

int lexical::lookUp(char ch)
{
	//cout<<"lookUp Entered"<<endl;
	//cout<<"ch is "<<ch<<endl;
	switch(ch)
	{
		cout<<"switch Entered, nextToken is "<<ch<<endl;
		case '(':
			addChar();
			nextToken = LEFT_PAREN;
			break;

		case ')':
			addChar();
			nextToken = RIGHT_PAREN;
			break;
		case '+':
			addChar();
			nextToken = PLUS;
			break;

		case '-':
			addChar();
			nextToken = MINUS;
			nextChar = myStream.get();
			if(nextChar == '>')
			{
				addChar();
				nextToken = DECLARER;
			}
			break;

		case '*':
			addChar();
			nextToken = TIMES;
			break;

		case '/':
			addChar();
			nextToken = DIVIDE;
			break;

		case '<':
			addChar();
			getChar();
			addChar();
			nextToken = ASSIGN_OP;
			break;

		case '.':
			addChar();
			nextToken = PERIOD;
			break;

		case ',':
			addChar();
			nextToken = COMMA;
			break;

		case ';':
			//cout<<"semicolon case Entered"<<endl;
			addChar();
			nextToken = SEMICOLON;
			break;

		default:
			addChar();
			nextToken = EOF; 
			break;
	}

	return nextToken;
}

void lexical::addChar()
{
	//cout<<"addChar Entered"<<endl;
	//cout<<"nextChar is "<<nextChar<<endl;
	if(lexLen <= 98)
	{
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = 0;
	}
	else
		cout<<("Error - lexeme is too long\n");
}

void lexical::getChar()
{
	//cout<<"getChar Entered"<<endl;
	nextChar = myStream.get();
	if(nextChar != EOF)
	{
		//cout<<"test: "<<nextChar <<"\n";
		if(isalpha(nextChar))
			charClass = LETTER;
		else if(isdigit(nextChar))
			charClass = DIGIT;
		else
			charClass = UNKNOWN;
	}
	else
		charClass = EOF;
}

void lexical::getNonBlank()
{
	//cout<<"getNonBlank Entered"<<endl;
	while(isspace(nextChar))
	{
		//cout<<"no error in GetNonBlank yet"<<endl;
		getChar();
	}
}

int lexical::lex()
{
	//cout<<"Entered lex"<<endl;
	lexLen = 0;
	getNonBlank();
	//cout<<"charclass is "<<charClass<<endl;
	//getChar();
	switch(charClass)
	{
	cout<<"lex switch statement Entered, charClass is "<<charClass<<endl;
	case LETTER:
		//cout<<"nextToken is "<<nextToken<<endl;
		addChar();

		getChar();
		while(charClass == LETTER || charClass == DIGIT)
		{
			//cout<<"charclass is letter, addChar and getChar called"<<endl;
			addChar();
			getChar();
		}

		nextToken = ID;
		//cout<<"nextToken is "<<nextToken<<endl;
		break;

	case DIGIT:
		addChar();
		getChar();
		while( charClass == DIGIT )
		{
			addChar();
			getChar();
		}
		nextToken = CONST;
		break;

	case UNKNOWN:
		lookUp(nextChar);
		getChar();
		break;

	case EOF:
		nextToken = EOF;
		lexeme[0] = 'E';
		lexeme[1] = 'O';
		lexeme[2] = 'F';
		break;
	}

	cout<<"Next token is: "<< nextToken << " Next lexeme is "<< lexeme << "\n";
	return nextToken;
}


	void lexical::program(lexical &lexObject)
	{
		
		cout<<"Enter program"<<endl;
		//cout<<"Token is "<<nextToken<<endl;
		lex(); //get first token
		
		if(nextToken == ID)
		{
			lex();
			if(nextToken == SEMICOLON)
			{
				lex(); //maybe
				lexObject.declaration(lexObject);
				lexObject.body(lexObject);
			}
			else
				error();
		}
		else
			error();

		if(nextToken == PERIOD)
		{	
			lex();
			if(nextToken!=EOF)
				error();
		}
		else
			error();	
		cout<<"Exit <program>"<<endl;
		cout<<"Program Finished"<<endl;
				
	}
	void lexical::body(lexical &lexObject)
	{
		cout<<"<Enter body>"<<endl;
		
		if(nextToken == ID)
		{
			lex();

			lexObject.statList(lexObject);
		}	
		else
			error();

		

		if(nextToken == ID)
			lex();
		else
			error();

		cout<<"Exit <body>"<<endl;

	}

	void lexical::declaration(lexical &lexObject)
	{
		cout<<"Enter <declaration>"<<endl;
		if(nextToken == ID)
		{
			lex();
			if(nextToken == DECLARER)
			{
				lex();
				lexObject.idList(lexObject);
				if(nextToken == SEMICOLON)
					lex();
				else
					error();
			}
			else
				error();	
		}	

		cout<<"Exit <declaration>"<<endl;
	}

	void lexical::idList(lexical &lexObject)
	{
		cout<<"Enter <idlist>"<<endl;
		if(nextToken == ID)
		{
			lex();
			lexObject.idList2(lexObject);
		}
		else
			error();

		cout<<"Exit <idlist>"<<endl;
	}

	void lexical::idList2(lexical &lexObject)
	{
		
		cout<<"Enter idlist2"<<endl;
		if(nextToken == COMMA)
		{			
			lex();
			
			if(nextToken == ID)
			{
				lex();
				lexObject.idList2(lexObject);
			}
			else
				error();
			cout<<"Exit <idlist2>"<<endl;
		}
	}

	void lexical::statList(lexical &lexObject)
	{
		cout<<"Enter <statlist>"<<endl;
		if(nextToken == ID)
		{
			lexObject.statement(lexObject);
			lexObject.statList2(lexObject);
		}
		else
			error();

		cout<<"Exit <statlist>"<<endl;
		
		
		
	}

	void lexical::statList2(lexical &lexObject)
	{
		cout<<"Enter <statlist2>"<<endl;
		if(nextToken == SEMICOLON)
		{	
			lex();
			lexObject.statement(lexObject);
			lexObject.statList2(lexObject);
		}

		cout<<"Exit <statList2>"<<endl;

	}

	void lexical::statement(lexical &lexObject)
	{
		cout<<"Enter <statement>"<<endl;
		if(nextToken == ID)
		{
			lex();
			if( nextToken == ASSIGN_OP)
			{
				lex();
				lexObject.expression(lexObject);
			}
			else
				error();
		}
		else
			error();

		cout<<"Exit <statement>"<<endl;
		
	}

	void lexical::expression(lexical &lexObject)
	{
		//lex();
		cout<<"Enter <expression>"<<endl;
		
		
		lexObject.term(lexObject);
		lexObject.expression2(lexObject);

		cout<<"Exit <expression>"<<endl;
	}

	void lexical::expression2(lexical &lexObject)
	{
		cout<<"Enter <expression2>"<<endl;
		
		if(nextToken == PLUS || nextToken == MINUS)
		{
			lex();
			lexObject.term(lexObject);
			lexObject.expression2(lexObject);
		}

		cout<<"Exit <expression2>"<<endl;
	}

	void lexical::term(lexical &lexObject)
	{
		cout<<"Enter <term>"<<endl;
		lexObject.factor(lexObject);
		lexObject.term2(lexObject);
		cout<<"Enter <term>"<<endl;
		
	}

	void lexical::term2(lexical &lexObject)
	{
		cout<<"Enter <term2>"<<endl;
		if(nextToken == TIMES || nextToken == DIVIDE )
		{
			lex();
			lexObject.factor(lexObject);
			lexObject.term2(lexObject);
		}

		//lexObject.factor(lexObject);

		cout<<"Exit <term2>"<<endl;
		
		

	}

	void lexical::factor(lexical &lexObject)
	{
		cout<<"Enter <factor>"<<endl;
		if(nextToken == CONST || nextToken == ID)
		{
			lex();
		}
		else
		{
			 if(nextToken == LEFT_PAREN)
			 {
				lex();
				lexObject.expression(lexObject);
				if(nextToken == RIGHT_PAREN)
				{
					lex();
					
				}
				else
					error();
			 }
			 else
				 error();
		}

		cout<<"Exit <factor>"<<endl;
	}

	void lexical:: error()
	{
		
		cout<<"error, program crashed";
		int a;
		cin>>a;

	}
