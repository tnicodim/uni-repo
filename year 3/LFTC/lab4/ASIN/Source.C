#define _CRT_SECURE_NO_WARNINGS

#include "lexer.h"
#include "utils.h"
#include "parser.h"
#include "ad.h"
#include "at.h"
#include "gen.h"

#include <stdlib.h>
#include <stdio.h>

int main(){
	char* inbuf = loadFile("1.q");
	tokenize(inbuf);
	showTokens();
	free(inbuf);
	parse();
	return 0;
}