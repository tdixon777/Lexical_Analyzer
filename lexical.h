#include <iostream>
#include <fstream>
#include <string>
#pragma once

using namespace std;

//Token Codes
//multiple char tokens
#define CONST 10 //same as int_lit in book
#define ID 11 //same as ident in book
#define DECLARER 27
#define	ASSIGN_OP 20

//single char tokens
#define COMMA  17
#define PERIOD  18
#define SEMICOLON 19
#define PLUS 21
#define MINUS 22
#define TIMES 23
#define DIVIDE 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

//Character Classes//
#define LETTER 0 
#define DIGIT 1
#define UNKNOWN 99

class lexical
{
public:
	lexical();
	

	int charClass;
	char lexeme[100];
	char nextChar;
	int lexLen;
	int token;
	int nextToken;
	int lineNum;
	fstream myStream;

	//functions for the lexical analyzer
	void addChar();
	void getChar();
	void getNonBlank();
	void lexicalAnalysis(string fileName);
	int lex();
	int lookUp(char ch);

	//functions for the parser
	void parse(lexical &lexObject, string fileName);
	void program(lexical &lexObject);
	void body(lexical &lexObject);
	void declaration(lexical &lexObject);
	void idList(lexical &lexObject);
	void idList2(lexical &lexObject);
	void statList(lexical &lexObject);
	void statList2(lexical &lexObject);
	void statement(lexical &lexObject);
	void expression(lexical &lexObject);
	void expression2(lexical &lexObject);
	void term(lexical &lexObject);
	void term2(lexical &lexObject);
	void factor(lexical &lexObject);

	void error();



};