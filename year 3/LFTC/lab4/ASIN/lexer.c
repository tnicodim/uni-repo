#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"
#include "utils.h"

Token tokens[MAX_TOKENS];
int nTokens;

int line=1;		// the current line in the input file

// adds a token to the end of the tokens list and returns it
// sets its code and line
Token *addTk(int code){
	if(nTokens==MAX_TOKENS)err("too many tokens");
	Token *tk=&tokens[nTokens];
	tk->code=code;
	tk->line=line;
	nTokens++;
	return tk;
	}

// copy in the dst buffer the string between [begin,end)
char *copyn(char *dst,const char *begin,const char *end){
	char *p=dst;
	if(end-begin>MAX_STR)err("string too long");
	while(begin!=end)*p++=*begin++;
	*p='\0';
	return dst;
	}

void tokenize(const char *pch){
	const char *start;
	Token *tk;
	char buf[MAX_STR+1];
	for(;;){
		switch(*pch){
			case ' ':
			case '\t':
				pch++;
				break;
			case '\r':		// handles different kinds of newlines (Windows: \r\n, Linux: \n, MacOS, OS X: \r or \n)
				if(pch[1]=='\n')pch++;
				// fallthrough to \n
			case '\n':
				line++;
				pch++;
				break;
			case '#':
				while (*pch != '\n' && *pch != '\r' && *pch != '\0') 
				{
					pch++;
				}
				break;
			case ';':
				addTk(SEMICOLON);
				pch++;
				break;
			case ':':
				addTk(COLON);
				pch++;
				break;
			case '+':
				addTk(ADD);
				pch++;
				break;
			case '-':
				addTk(SUB);
				pch++;
				break;
			case '*':
				addTk(MUL);
				pch++;
				break;
			case '/':
				addTk(DIV);
				pch++;
				break;
			case '!':
				if (pch[1] == '=') {
					addTk(NOTEQ);
					pch += 2;
				}
				else {
					addTk(NOT);
					pch++;
				}
				break;
			case '|':
				if (pch[1] == '|') {
					addTk(OR);
					pch += 2;
				}
				break;
			case '&':
				if (pch[1] == '&') {
					addTk(AND);
					pch += 2;
				}
				break;
			case '<':
				addTk(LESS);
				pch++;
				break;
			case '>':
				if (pch[1] == '=') {
					addTk(GREATEREQ);
					pch += 2;
				}
				else {
					addTk(GREATER);
					pch++;
				}
				break;
			case '(':
				addTk(LPAR);
				pch++;
				break;
			case ')':
				addTk(RPAR);
				pch++;
				break;
			case '\0':addTk(FINISH);return;
			case '"':
				for(start=++pch;*pch!='"';pch++){
					if (*pch == '\0')
						err("File end reached during string reading");
				}
				tk = addTk(STR);
				copyn(tk->text, start, pch);
				pch++;
				break;
			case ',':addTk(COMMA);pch++;break;
			case '=':
				if(pch[1]=='='){
					addTk(EQUAL);
					pch+=2;
					}else{
					addTk(ASSIGN);
					pch++;
					}
				break;
			default:
				if(isalpha(*pch)||*pch=='_'){
					for(start=pch++;isalnum(*pch)||*pch=='_';pch++){}
					char *text=copyn(buf,start,pch);
					if(strcmp(text,"int")==0)addTk(TYPE_INT);
					else if (strcmp(text, "real") == 0)addTk(TYPE_REAL);
					else if (strcmp(text, "str") == 0)addTk(TYPE_STR);
					else if (strcmp(text, "return") == 0)addTk(RETURN);
					else if (strcmp(text, "end") == 0)addTk(END);
					else if (strcmp(text, "while") == 0)addTk(WHILE);
					else if (strcmp(text, "else") == 0)addTk(ELSE);
					else if (strcmp(text, "if") == 0)addTk(IF);
					else if (strcmp(text, "function") == 0)addTk(FUNCTION);
					else if (strcmp(text, "var") == 0)addTk(VAR);
					else{
						tk=addTk(ID);
						strcpy(tk->text,text);
						}
					}
				else if (isdigit(*pch)) {
					for (start = pch; isdigit(*pch); pch++) {}
					if (*pch == '.') {
						for (pch++; isdigit(*pch); pch++) {}
						tk = addTk(REAL);
						tk->r = atof(copyn(buf, start, pch));
					}else{
						tk = addTk(INT);
						tk->i = atoi(copyn(buf,start,pch));
					}
				}
				else err("invalid char: %c (%d)",*pch,*pch);
			}
		}
	}

	const char* enumToString(int value) {
		switch (value) {
		case ID: return "ID";
		case TYPE_INT: return "TYPE_INT";
		case TYPE_REAL: return "TYPE_REAL";
		case TYPE_STR: return "TYPE_STR";
		case VAR: return "VAR";
		case FUNCTION: return "FUNCTION";
		case IF: return "IF";
		case ELSE: return "ELSE";
		case WHILE: return "WHILE";
		case END: return "END";
		case RETURN: return "RETURN";
		case COMMA: return "COMMA";
		case FINISH: return "FINISH";
		case SEMICOLON: return "SEMICOLON";
		case LPAR: return "LPAR";
		case RPAR: return "RPAR";
		case COLON: return "COLON";
		case ADD: return "ADD";
		case SUB: return "SUB";
		case MUL: return "MUL";
		case DIV: return "DIV";
		case AND: return "AND";
		case OR: return "OR";
		case NOT: return "NOT";
		case ASSIGN: return "ASSIGN";
		case EQUAL: return "EQUAL";
		case NOTEQ: return "NOTEQ";
		case LESS: return "LESS";
		case GREATER: return "GREATER";
		case GREATEREQ: return "GREATEREQ";
		case STR: return "STR";
		case INT: return "INT";
		case REAL: return "REAL";
		default: return "UNKNOWN";
		}
	}

void showTokens(){
	for(int i=0;i<nTokens;i++){
		Token *tk=&tokens[i];
		printf("%d ",tk->line);
		if (tk->code == ID) {
			printf("ID:%s\n", tk->text);
		}
		else if (tk->code == STR) {
			printf("STR:%s\n", tk->text);
		}
		else if (tk->code == INT) {
			printf("INT:%d\n", tk->i);
		}
		else if (tk->code == REAL) {
			printf("REAL:%.5f\n", tk->r);
		}
		else {
			printf("%s\n", enumToString(tk->code));
		}
		}
	}
