/*
 * Project: IFJ16, a programming language interpreter
 * FIT VUT Brno
 * Authors: xzaryb00 - Zarybnický Jakub
 *          xtamas01 - Tamaškovič Marek
 *          xvasko12 - Vaško Martin
 *          xvasko14 - Vaško Michal
 *          xzales12 - Záleský Jiří
 */
 // Pomaly na tom pracujem postupne tu zacnem pridavat co mam 

// Zatial som si len vypisal klcuove slova alebo rezervovane slova ktore funkcia kontroluje
#include "Stringology.h"




int check_keyword(String str)
{ 
    if(strlen(str)> LNG_KEYWORD) return IDENTIFIER;
    }
    if(str[0] == 'b') {
        if(strcmp(str, "boolean") == 0)
            return BOOLEAN;
        return IDENTIFIER;
        if(strcmp(str, "break") == 0)
            return BREAK;
        return IDENTIFIER;
    }
    if(str[0] == 'c') {
        if(strcmp(str, "class") == 0)
            return CLASS;
        return IDENTIFIER;
        if(strcmp(str, "continue") == 0)
            return CONTINUE;
        return IDENTIFIER;
    }
    if(str[0] == 'd') {
        if(strcmp(str, "do") == 0)
            return DO;
        return IDENTIFIER;
        if(strcmp(str, "double") == 0)
            return DOUBLE;
        return IDENTIFIER;
    }
    if(str[0] == 'e') {
        if(strcmp(str, "else") == 0)
            return ELSE;
    }
    if(str[0] == 'f') {
        if(strcmp(str, "false") == 0)
            return FALSE;
        if(strcmp(str, "for") == 0)
            return FOR;
        return IDENTIFIER;
    }
    if(str[0] == 'i') {
        if(strcmp(str, "if") == 0)
            return IF;
        if(strcmp(str, "int") == 0)
            return INT;
        return IDENTIFIER;
    }
    if(str[0] == 'r') {
        if(strcmp(str, "return") == 0)
            return RETURN;
        return IDENTIFIER;
    }
    if(str[0] == 'S') {
        if(strcmp(str, "String") == 0)
            return STRING;
        return IDENTIFIER;
    }
     if(str[0] == 's') {
        if(strcmp(str, "static") == 0)
            return STATIC;
        return IDENTIFIER;
    }
    if(str[0] == 't') {
        if(strcmp(str, "true") == 0)
            return TRUE;
        return IDENTIFIER;
    }
    if(str[0] == 'w') {
        if(strcmp(str, "void") == 0)
            return VOID;
        return IDENTIFIER;
    }   
    if(str[0] == 'w') {
        if(strcmp(str, "while") == 0)
            return WHILE;
        return IDENTIFIER;
    }
    return IDENTIFIER;
}

int Get_Token(void)
{ 
	int v;
	while () {
		switch (state) {
		
		 case Neutral_State :   // nacitame znak
		 v = fgetc(input);
		 case Start_state :
		        if(isspace(v)) {
				 state = NEUTRAL_STATE
				 if(c == '\n')
				 ++line }
				
				else if(isalpha(v) || v == '_' || v == '$') //pokracujeme dalej na stav IDEN
				 state = AUT_IDEN;
				
				else if(isdigit(v))  //pokracujeme na stav cisla
				 state = AUT_NUM;
				 
				else if(c == '+') {
                    state = NEUTRAL_STATE;
                    return PLUS;
                }
                else if(c == '-'){
                    state = NEUTRAL_STATE;
                    return MINUS;
                }
                else if(c == '*') {
                    state = NEUTRAL_STATE;
                    return MUL;
                }
                else if(c == '/')      // pokracujeme dalej kvoli moznosti komentaru
                    state = AUT_DIV;
                 else if(c == '<')
                    state = AUT_LESS;  // pokracujeme kvoli moznosti mensie rovne
                else if(c == '>')
                    state = AUT_GREAT; // moznost vacsie rovne
                else if(c == '=')
                    state = AUT_EQUALS;  // moznost rovnsti
                else if(c == '!')
                    state = AUT_NOT_EQUALS; // moznost nerovnosti
                else if(c == ';') {
                    state = NEUTRAL_STATE;  //Neviem ci tu mam zahrnovat aj dvojbodku, bodkociarku, bodku atd... toto som tu dal ale neviem ci to treba
                    return SEMICOLON;
                }
                else if(c == '"')    //skaceme na stav String
                    state = AUT_STRING;
                     
                else if(c == EOF)
                    return NOTHING;
                else {
                    state = FNEUTRAL_STATE;
                    return ERROR;
                }
                   break;
                    
                
           
                    
                
				 
		 
		 
			
	





Token getNextToken(FILE *stream);
enum TokenType { Integer, Double, String, Type, SimpleId, CompoundId, Reserved, Symbol };
typedef struct {
     int lineNum;
     int lineChar; //For error reporting
     TokenType type;
     union {
          struct { int intValue };
          struct { double doubleValue; };
          struct { char *stringValue; };
          struct { char *typeValue; };
          struct { char *localId; };
          struct { char *namespace; char *staticId; };
          struct { char *reservedValue; };
          struct { char *symbolValue; };
        
     };
} Token;


