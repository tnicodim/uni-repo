#pragma once
#include <stdbool.h>

// parse the extracted tokens
void parse();

bool consume(int code);

bool factor();

bool exprPrefix();

bool exprMul();

bool exprAdd();

bool exprComp();

bool exprAssign();

bool exprLogic();

bool expr();

bool instr();

bool funcParam();

bool funcParams();

bool block();

bool defFunc();

bool baseType();

bool defVar();

bool program();
