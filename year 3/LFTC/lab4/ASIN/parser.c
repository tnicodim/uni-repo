#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "lexer.h"
#include "parser.h"
#include "ad.h"
#include "at.h"
#include "gen.h"

int iTk;	// the iterator in tokens
Token *consumed;	// the last consumed token

// same as err, but also prints the line of the current token
_Noreturn; void tkerr(const char *fmt,...){
	fprintf(stderr,"error in line %d: ",tokens[iTk].line);
	va_list va;
	va_start(va,fmt);
	vfprintf(stderr,fmt,va);
	va_end(va);
	fprintf(stderr,"\n");
	exit(EXIT_FAILURE);
	}

bool consume(int code) {
	if (tokens[iTk].code == code) {
		consumed = &tokens[iTk++];
		return true;
	}
	return false;
}


///* factor ::= int
//| real
//| str
//| lpar expr rpar
//| id ( lpar ( expr ( comma expr )* )? rpar )?
//*/
bool factor() {
	if (consume(INT)) {
		setRet(TYPE_INT, false);
		Text_write(crtCode, "%d", consumed->i);
		return true;
	}
	if (consume(REAL))
	{
		setRet(TYPE_REAL, false);
		Text_write(crtCode, "%g", consumed->r);
		return true;
	}
	if (consume(STR))
	{
		setRet(TYPE_STR, false);
		Text_write(crtCode, "\"%s\"", consumed->text);
		return true;
	}
	if (consume(LPAR)) {
		Text_write(crtCode, "(");
		if (expr()) {
			if (consume(RPAR)) {
				Text_write(crtCode,")");
				return true;
			}
				
			else tkerr("missing ) after expression");
		}
		else tkerr("invalid expression after (");
	}
	if (consume(ID))
	{
		Symbol* s = searchSymbol(consumed->text);
		if (!s)tkerr("undefined symbol: %s", consumed->text);
		Text_write(crtCode, "%s", s->name);
		if (consume(LPAR))
		{
			if (s->kind != KIND_FN)tkerr("%s cannot be called, because it is not a function", s->name);
			Symbol* argDef = s->args;
			Text_write(crtCode, "(");
			if (expr())
			{
				if (!argDef)tkerr("the function %s is called with too many arguments", s->name);
				if (argDef->type != ret.type)tkerr("the argument type at function %s call is different from the one given at its definition",s->name);
					argDef = argDef->next;
				while (consume(COMMA))
				{
					Text_write(crtCode, ",");
					if (expr())
					{
						if (!argDef)tkerr("the function %s is called with too many arguments", s->name);
						if (argDef->type != ret.type)tkerr("the argument type at function %s call is different from the one given at its definition",s->name);
							argDef = argDef->next;
					}
				}
			}
			if (consume(RPAR))
			{
				if (argDef)tkerr("the function %s is called with too few arguments", s->name);
				setRet(s->type, false);
				Text_write(crtCode, ")");
				return true;
			}
			else {
				tkerr("Missing ')' or invalid expression");
			}
		}
		if (s->kind == KIND_FN)tkerr("the function %s can only be called", s->name);
		setRet(s->type, true);
		return true;
	}
	return false;
}

// exprPrefix ::= ( SUB | NOT )? factor
bool exprPrefix() {
	if (consume(SUB)) {
		Text_write(crtCode, "-");
		if (factor()) {
			if (ret.type == TYPE_STR)tkerr("the expression of unary - must be of type int or real");
			ret.lval = false;
			return true;
		}
		else tkerr("Invalid expression after -");
	}
	if (consume(NOT)) {
		Text_write(crtCode, "!");
		if (factor()) {
			if (ret.type == TYPE_STR)tkerr("the expression of ! must be of type int or real");
			setRet(TYPE_INT, false);
			return true;
		}
		else tkerr("Invalid expression after !");
	}
	return factor();
}


// exprMul ::= exprPrefix ( ( MUL | DIV ) exprPrefix )*
bool exprMul() {
	if (exprPrefix()) {
		while (consume(MUL)) {
			Ret leftType = ret;
			Text_write(crtCode, "*");
			if (leftType.type == TYPE_STR)tkerr("the operands of * or / cannot be of type str");
			if (exprPrefix()) {
				if (leftType.type != ret.type)tkerr("different types for the operands of * or /");
				ret.lval = false;
			}
			else {
				tkerr("Invalid expression after multiplication");
				return false;
			}
		}
		while (consume(DIV)) {
			Ret leftType = ret;
			Text_write(crtCode, "/");
			if (leftType.type == TYPE_STR)tkerr("the operands of * or / cannot be of type str");
			if (exprPrefix()) {
				if (leftType.type != ret.type)tkerr("different types for the operands of * or /");
				ret.lval = false;
			}
			else {
				tkerr("Invalid expression after division");
				return false;
			}
		}
		return true;
	}
	return false;
}


// exprAdd ::= exprMul ( ( ADD | SUB ) exprMul )*
bool exprAdd() {
	if (exprMul()) {
		while (consume(ADD)){
			Ret leftType = ret;
			Text_write(crtCode, "+");
			if (leftType.type == TYPE_STR)tkerr("the operands of + or - cannot be of type str");
			if (exprMul()) {
				if (leftType.type != ret.type)tkerr("different types for the operands of + or -");
				ret.lval = false;
			}
			else {
				tkerr("Invalid expression after addition");
				return false;
			}
		}
		while (consume(SUB)) {
			Ret leftType = ret;
			Text_write(crtCode, "-");
			if (leftType.type == TYPE_STR)tkerr("the operands of + or - cannot be of type str");
			if (exprMul()) {
				if (leftType.type != ret.type)tkerr("different types for the operands of + or -");
				ret.lval = false;
			}
			else {
				tkerr("Invalid expression after subtraction");
				return false;
			}
		}
		return true;
	}
	return false;
}


// exprComp ::= exprAdd ( ( LESS | EQUAL ) exprAdd )?
bool exprComp() {
	if (exprAdd()) {
		if (consume(LESS)){
			Ret leftType = ret;
			Text_write(crtCode, "<");
			if (exprAdd()) {
				if (leftType.type != ret.type)tkerr("different types for the operands of < or ==");
				setRet(TYPE_INT, false); // the result of comparation is int 0 or 1
			}
			else {
				tkerr("Invalid expression after <");
				return false;
			}
		}
		if (consume(EQUAL)) {
			Ret leftType = ret;
			Text_write(crtCode, "==");
			if (exprAdd()) {
				if (leftType.type != ret.type)tkerr("different types for the operands of < or ==");
				setRet(TYPE_INT, false); // the result of comparation is int 0 or 1
			}
			else {
				tkerr("Invalid expression after =");
				return false;
			}
		}
		return true;
	}
	return false;
}	

// exprAssign ::= ( ID ASSIGN )? exprComp
bool exprAssign() {
	int idx = iTk;
	if (consume(ID)) {
		const char* name = consumed->text;
		if (consume(ASSIGN)) {
			Text_write(crtCode, "%s=", name);
			if (exprComp()) {
				Symbol* s = searchSymbol(name);
				if (!s)tkerr("undefined symbol: %s", name);
				if (s->kind == KIND_FN)tkerr("a function (%s) cannot be used as a destination for assignment ", name);
				if (s->type != ret.type)tkerr("the source and destination for assignment must have the same type");
				ret.lval = false;
				return true;
			}
			else tkerr("Invalid expression after =");
		}
		iTk = idx;
	}
	return exprComp();
}

// exprLogic ::= exprAssign ( ( AND | OR ) exprAssign )*
bool exprLogic() {
	if (exprAssign()) {
		while (consume(AND)) {
			Ret leftType = ret;
			Text_write(crtCode, "&&");
			if (leftType.type == TYPE_STR)tkerr("the left operand of && or || cannot be of type str");
			if (exprAssign()) {
				if (ret.type == TYPE_STR)tkerr("the right operand of && or || cannot be of type str");
				setRet(TYPE_INT, false);
			}
			else {
				tkerr("Invalid expression after AND");
				return false;
			}
		}
		while (consume(OR)) {
			Ret leftType = ret;
			Text_write(crtCode, "||");
		if (leftType.type == TYPE_STR)tkerr("the left operand of && or || cannot be of type str");
			if (exprAssign()) {
				if (ret.type == TYPE_STR)tkerr("the right operand of && or || cannot be of type str");
				setRet(TYPE_INT, false);
			}
			else {
				tkerr("Invalid expression after OR");
				return false;
			}
		}
		return true;
	}
	return false;
}


// expr ::= exprLogic
bool expr() {
	return exprLogic();
}

//  instr ::= expr? SEMICOLON
// | IF LPAR expr RPAR block(ELSE block) ? END
// | RETURN expr SEMICOLON
// | WHILE LPAR expr RPAR block END
bool instr(){
	if (expr()) {
		if (consume(SEMICOLON)) {
			Text_write(crtCode, ";\n");
			return true;
		}
		else tkerr("Missing ; after expression");
	}
	if (consume(SEMICOLON)) {
		return true;
	}
	if (consume(IF)) {
		if (consume(LPAR)) {
			Text_write(crtCode, "if(");
			if (expr()){
				if (ret.type == TYPE_STR)tkerr("the if condition must have type int or real");
				if (consume(RPAR)) {
					Text_write(crtCode, "){\n");
					if (block()) {
						Text_write(crtCode, "}\n");
						if (consume(ELSE)) {
							Text_write(crtCode, "else{\n");
							if (block()) {
								Text_write(crtCode, "}\n");
							}
							else tkerr("Invalid else statement (block)");
						}
						if (consume(END)) {
							return true;
						}
						else tkerr("Missing end statement");
					}
					else tkerr("Invalid if statement (block)");
				}
				else tkerr("Missing ) for the if statement");
			}
			else tkerr("Invalid if condition");
		}
		else tkerr("Missing ( for the if statement");
	}
	if (consume(RETURN)) {
		Text_write(crtCode, "return ");
		if (expr()) {
			if (!crtFn)tkerr("return can be used only in a function");
			if (ret.type != crtFn->type)tkerr("the return type must be the same as the function return type");
			if (consume(SEMICOLON)) {
				Text_write(crtCode, ";\n");
				return true;
			}
			else tkerr("Missing ; after return statement");
		}
		else ("Invalid expression after return statement");
	}
	if (consume(WHILE)) {
		Text_write(crtCode, "while(");
		if (consume(LPAR)) {
			if (expr()) {
				if (ret.type == TYPE_STR)tkerr("the while condition must have type int or real");
				if (consume(RPAR)) {
					Text_write(crtCode, "){\n");
					if (block()) {
						if (consume(END)) {
							Text_write(crtCode, "}\n");
							return true;
						}
						else tkerr("Missing end statement");
					}
					else tkerr("Invalid while statement (block)");
				}
				else tkerr("Missing ) after while statement");
			}
			else tkerr("Invalid while condition");
		}
		else tkerr("Missing ( after while statement");
	}
	return false;
}
// funcParam ::= ID COLON baseType
bool funcParam() {
	if (consume(ID)) {
			const char* name = consumed->text;
			Symbol* s = searchInCurrentDomain(name);
			if (s)tkerr("symbol redefinition: %s", name);
			s = addSymbol(name, KIND_ARG);
			Symbol* sFnParam = addFnArg(crtFn, name);
		if (consume(COLON)) {
			if (baseType()) {
				s->type = ret.type;
				sFnParam->type = ret.type;
				Text_write(&tFnHeader, "%s %s", cType(ret.type), name);
				return true;
			}
			else tkerr("Invalid base type in function parameter declaration");
		}
		else tkerr("Missing : after parameter");
	}
	return false;
}

// funcParams ::= funcParam ( COMMA funcParam )*
bool funcParams() {
	if (funcParam()) {
		while (consume(COMMA)) {
			Text_write(&tFnHeader, ",");
			if (funcParam()) {
			}
			else tkerr("Missing function parameter after ,");
		}
	}
	return false;
}

// block :: = instr+
bool block() {
	if (instr()) {
		while (instr()) {
		}
		return true;
	}
	return false;

}

// defFunc ::= FUNCTION ID LPAR funcParams? RPAR COLON baseType defVar* block END
bool defFunc() {	
	if (consume(FUNCTION)) {
		if (consume(ID)) {
			const char* name = consumed->text;
			Symbol* s = searchInCurrentDomain(name);
			if (s)tkerr("symbol redefinition: %s", name);
			crtFn = addSymbol(name, KIND_FN);
			crtFn->args = NULL;
			addDomain();
			crtCode = &tFunctions;
			crtVar = &tFunctions;
			Text_clear(&tFnHeader);
			Text_write(&tFnHeader, "%s(", name);
			if (consume(LPAR)) {
				funcParams();
				if (consume(RPAR)) {
					if (consume(COLON)) {
						if (baseType()) {
							crtFn->type = ret.type;
							Text_write(&tFunctions, "\n%s %s){\n", cType(ret.type), tFnHeader.buf);
						}
						else {
							tkerr("Invalid base type in function definition");
						}
						while (defVar()) {
						}
						if (block()) {
							if (consume(END)) {
								stergeDomeniu();
								crtFn = NULL;
								Text_write(&tFunctions, "}\n");
								crtCode = &tMain;
								crtVar = &tBegin;
								return true;
							}
							else {
								tkerr("Missing 'END' after function definition");
							}
						}
						else {
							tkerr("Invalid function block");
						}
					}
					else {
						tkerr("Missing ':' after function parameter list");
					}
				}
				else {
					tkerr("Missing ')' after function parameter list");
				}
			}
			else {
				tkerr("Missing '(' after function name");
			}
		}
		else {
			tkerr("Missing function name (identifier)");
		}
	}
	return false;
}


// baseType ::= TYPE_INT | TYPE_REAL | TYPE_STR
bool baseType() {
	if (consume(TYPE_INT))
	{
		ret.type = TYPE_INT;
		return true;
	}
	if (consume(TYPE_REAL))
	{
		ret.type = TYPE_REAL;
		return true;
	}
	if (consume(TYPE_STR))
	{
		ret.type = TYPE_STR;
		return true;
	}
	return false;
}

// defVar ::= VAR ID COLON baseType SEMICOLON
bool defVar()
{
	if (consume(VAR))
	{
		if (consume(ID))
		{
			const char* name = consumed->text;
			Symbol* s = searchInCurrentDomain(name);
			if (s)
				tkerr("symbol redefinition: %s", name);
			s = addSymbol(name, KIND_VAR);
			s->local = crtFn != NULL;
			if (consume(COLON))
			{
				if (baseType())
				{
					s->type = ret.type;
					if (consume(SEMICOLON))
					{
						Text_write(crtVar, "%s %s;\n", cType(ret.type), name);
						return true;
					}
					else {
						tkerr("Missing ';' at the end");
					}
				}
				else {
					tkerr("Please specify the variable type");
				}
			}
			else {
				tkerr("Missing ':' after ID");
			}
		}
		else {
			tkerr("Missing ID after VAR");
		}
	}
	return false;
}



// program ::= ( defVar | defFunc | block )* FINISH
bool program(){
		addDomain(); // creates the global domain
		addPredefinedFns(); // it will be inserted after the code for domain analysis
		crtCode = &tMain;
		crtVar = &tBegin;
		Text_write(&tBegin, "#include \"quick.h\"\n\n");
		Text_write(&tMain, "\nint main(){\n");
	for(;;){
		if(defVar()){}
		else if(defFunc()){}
		else if(block()){}
		else break;
		}
	if(consume(FINISH)){
		stergeDomeniu(); // deletes the global domain
		Text_write(&tMain, "return 0;\n}\n");
		FILE* fis = fopen("1.c", "w");
		if (!fis) {
			printf("cannot write to file 1.c\n");
			exit(EXIT_FAILURE);
		}
		fwrite(tBegin.buf, sizeof(char), tBegin.n, fis);
		fwrite(tFunctions.buf, sizeof(char), tFunctions.n, fis);
		fwrite(tMain.buf, sizeof(char), tMain.n, fis);
		fclose(fis);
		return true;
		}else tkerr("syntax error");
	return false;
}



void parse(){
	iTk=0;
	program();
	}
