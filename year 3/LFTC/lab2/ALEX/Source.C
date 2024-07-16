#define _CRT_SECURE_NO_WARNINGS

#include "lexer.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>

int main(){
	char* inbuf = loadFile("1.q");
	tokenize(inbuf);
	showTokens();
	free(inbuf);
	return 0;
}