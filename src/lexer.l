/* lexer.l */
D                   [0-9]
L                   [a-zA-Z_]
H                   [a-fA-F0-9]
E                   [Ee][+-]?{D}+
FS                  (f|F|l|L)
IS                  (u|U)?(L|LL|l|ll)?
%{
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <grammar.tab.h>
#include <classes_NT.h>
using namespace std;

extern unordered_map<string, string> symtab;
extern vector<string> program;
extern vector<pair<string, int>> error;
void comment();
void count();
int yylex();
extern int yylex();
extern int line_num;
extern bool iserror;

%}
%%
"/*"                    { comment();if(iserror){error.emplace_back("unterminated comment",line_num);}count();}
"//"[^\n]*(\n)?         { /* do nothing */  count();}
"auto"                  { symtab[yytext]="AUTO";program.emplace_back(yytext);count(); return AUTO;}
"break"                 { symtab[yytext]="BREAK";program.emplace_back(yytext);count(); return BREAK;}
"case"                  { symtab[yytext]="CASE";program.emplace_back(yytext);count(); return CASE;}
"char"                  { symtab[yytext]="CHAR";program.emplace_back(yytext);count(); return CHAR;}
"const"                 { symtab[yytext]="CONST";program.emplace_back(yytext);count(); return CONST;}
"continue"              { symtab[yytext]="CONTINUE";program.emplace_back(yytext);count(); return CONTINUE;}
"default"               { symtab[yytext]="DEFAULT";program.emplace_back(yytext);count(); return DEFAULT;}
"do"                    { symtab[yytext]="DO";program.emplace_back(yytext);count(); return DO;}
"double"                { symtab[yytext]="DOUBLE";program.emplace_back(yytext);count(); return DOUBLE;}
"else"                  { symtab[yytext]="ELSE";program.emplace_back(yytext);count(); return ELSE;}
"enum"                  { symtab[yytext]="ENUM";program.emplace_back(yytext);count(); return ENUM;}
"extern"                { symtab[yytext]="EXTERN";program.emplace_back(yytext);count(); return EXTERN;}
"float"                 { symtab[yytext]="FLOAT";program.emplace_back(yytext);count(); return FLOAT;}
"for"                   { symtab[yytext]="FOR";program.emplace_back(yytext);count(); return FOR;}
"goto"                  { symtab[yytext]="GOTO";program.emplace_back(yytext);count(); return GOTO;}
"if"                    { symtab[yytext]="IF";program.emplace_back(yytext);count(); return IF;}
"int"                   { symtab[yytext]="INT";program.emplace_back(yytext);count(); return INT;}
"long"                  { symtab[yytext]="LONG";program.emplace_back(yytext);count(); return LONG;}
"register"              { symtab[yytext]="REGISTER";program.emplace_back(yytext);count(); return REGISTER;}
"return"                { symtab[yytext]="RETURN";program.emplace_back(yytext);count(); return RETURN;}
"short"                 { symtab[yytext]="SHORT";program.emplace_back(yytext);count(); return SHORT;}
"signed"                { symtab[yytext]="SIGNED";program.emplace_back(yytext);count(); return SIGNED;}
"sizeof"                { symtab[yytext]="SIZEOF";program.emplace_back(yytext);count(); return SIZEOF;}
"static"                { symtab[yytext]="STATIC";program.emplace_back(yytext);count(); return STATIC;}
"struct"                { symtab[yytext]="STRUCT";program.emplace_back(yytext);count(); return STRUCT;}
"switch"                { symtab[yytext]="SWITCH";program.emplace_back(yytext);count(); return SWITCH;}
"typedef"               { symtab[yytext]="TYPEDEF";program.emplace_back(yytext);count(); return TYPEDEF;}
"union"                 { symtab[yytext]="UNION";program.emplace_back(yytext);count(); return UNION;}
"unsigned"              { symtab[yytext]="UNSIGNED";program.emplace_back(yytext);count(); return UNSIGNED;}
"void"                  { symtab[yytext]="VOID";program.emplace_back(yytext);count(); return VOID;}
"bool"                  { symtab[yytext]="BOOL";program.emplace_back(yytext);count(); return BOOL;}
"class"                 { symtab[yytext]="CLASS";program.emplace_back(yytext);count(); return CLASS;}
"delete"                 { symtab[yytext]="DELETE";program.emplace_back(yytext);count(); return DELETE;}
"new"                   { symtab[yytext]="NEW";program.emplace_back(yytext);count(); return NEW;}
"private"               { symtab[yytext]="PRIVATE";program.emplace_back(yytext);count(); return PRIVATE;}
"public"                { symtab[yytext]="PUBLIC";program.emplace_back(yytext);count(); return PUBLIC;}
"protected"             { symtab[yytext]="PROTECTED";program.emplace_back(yytext);count(); return PROTECTED;}
"this"                  { symtab[yytext]="THIS";program.emplace_back(yytext);count(); return THIS;}
"until"                 { symtab[yytext]="UNTIL";program.emplace_back(yytext);count(); return UNTIL;}
"true"                  { symtab[yytext]="TRUE";program.emplace_back(yytext);count(); return TRUE;}
"false"                 { symtab[yytext]="FALSE";program.emplace_back(yytext);count(); return FALSE;}
"volatile"              { symtab[yytext]="VOLATILE";program.emplace_back(yytext);count(); return VOLATILE;}
"while"                 { symtab[yytext]="WHILE";program.emplace_back(yytext);count(); return WHILE;}

{L}({L}|{D})*           { symtab[yytext]="IDENTIFIER";program.emplace_back(yytext);count(); return IDENTIFIER;}
0[xX]{H}+{IS}?          { symtab[yytext]="CONSTANT HEX";program.emplace_back(yytext);count();  return CONSTANT;}
{D}+{IS}                { symtab[yytext]="INTEGER";program.emplace_back(yytext);count();return CONSTANT;}
L?'(\\.|[^\\'])+'      { symtab[yytext]="CONSTANT CHAR";program.emplace_back(yytext);count();  return CONSTANT;}
{D}+{E}{FS}?            { symtab[yytext]="CONSTANT EXP";program.emplace_back(yytext);count(); return CONSTANT;}
{D}*"."{D}+({E})?{FS}?  { symtab[yytext]="CONSTANT FLOAT";program.emplace_back(yytext);count(); return CONSTANT;}
L?\"(\\.|[^\\"])*\"    { symtab[yytext]="STRING LITERAL";program.emplace_back(yytext);count();return STRING_LITERAL;}
"..."                   { symtab[yytext]="ELLIPSIS";program.emplace_back(yytext);count(); return ELLIPSIS;}
">>="                   { symtab[yytext]="RIGHT_ASSIGN";program.emplace_back(yytext);count(); return RIGHT_ASSIGN;}
"<<="                   { symtab[yytext]="LEFT_ASSIGN";program.emplace_back(yytext);count(); return LEFT_ASSIGN;}
"+="                    { symtab[yytext]="ADD_ASSIGN";program.emplace_back(yytext);count(); return ADD_ASSIGN;}
"-="                    { symtab[yytext]="SUB_ASSIGN";program.emplace_back(yytext);count(); return SUB_ASSIGN;}
"*="                    { symtab[yytext]="MUL_ASSIGN";program.emplace_back(yytext);count(); return MUL_ASSIGN;}
"/="                    { symtab[yytext]="DIV_ASSIGN";program.emplace_back(yytext);count(); return DIV_ASSIGN;}
"%="                    { symtab[yytext]="MOD_ASSIGN";program.emplace_back(yytext);count(); return MOD_ASSIGN;}
"&="                    { symtab[yytext]="AND_ASSIGN";program.emplace_back(yytext);count(); return AND_ASSIGN;}
"^="                    { symtab[yytext]="XOR_ASSIGN";program.emplace_back(yytext);count(); return XOR_ASSIGN;}
"|="                    { symtab[yytext]="OR_ASSIGN";program.emplace_back(yytext);count(); return OR_ASSIGN;}
">>"                    { symtab[yytext]="RIGHT_OP";program.emplace_back(yytext);count(); return RIGHT_OP;}
"<<"                    { symtab[yytext]="LEFT_OP";program.emplace_back(yytext);count(); return LEFT_OP;}
"++"                    { symtab[yytext]="INC_OP";program.emplace_back(yytext);count(); return INC_OP;}
"--"                    { symtab[yytext]="DEC_OP";program.emplace_back(yytext);count(); return DEC_OP;}
"->"                    { symtab[yytext]="PTR_OP";program.emplace_back(yytext);count(); return PTR_OP;}
"&&"                    { symtab[yytext]="AND_OP";program.emplace_back(yytext);count(); return AND_OP;}
"||"                    { symtab[yytext]="OR_OP";program.emplace_back(yytext);count(); return OR_OP;}
"<="                    { symtab[yytext]="LE_OP";program.emplace_back(yytext);count(); return LE_OP;}
">="                    { symtab[yytext]="GE_OP";program.emplace_back(yytext);count(); return GE_OP;}
"=="                    { symtab[yytext]="EQ_OP";program.emplace_back(yytext);count(); return EQ_OP;}
"!="                    { symtab[yytext]="NE_OP";program.emplace_back(yytext);count(); return NE_OP;}
";"                     { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return ';';}
("{"|"<%")               { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return '{';}
("}"|"%>")               { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return '}';}
","                     { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return ',';}
":"                     { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return ':';}
"="                     { symtab[yytext]="ASSIGN";program.emplace_back(yytext);count(); return '=';}
"("                     { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return '(';}
")"                     { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return ')';}
("["|"<:")               { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return '[';}
("]"|":>")               { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return ']';}
"."                     { symtab[yytext]="SEPERATOR";program.emplace_back(yytext);count(); return '.';}
"&"                     { symtab[yytext]="BITWISE_AND";program.emplace_back(yytext);count(); return '&';}
"!"                     { symtab[yytext]="NOT";program.emplace_back(yytext);count(); return '!';}
"~"                     { symtab[yytext]="BITWISE_NOT";program.emplace_back(yytext);count(); return '!';}
"-"                     { symtab[yytext]="MINUS";program.emplace_back(yytext);count(); return '-';}
"+"                     { symtab[yytext]="PLUS";program.emplace_back(yytext);count(); return '+';}
"*"                     { symtab[yytext]="MUL";program.emplace_back(yytext);count(); return '*';}
"/"                     { symtab[yytext]="DIV";program.emplace_back(yytext);count(); return '/';}
"%"                     { symtab[yytext]="MOD";program.emplace_back(yytext);count(); return '%';}
"<"                     { symtab[yytext]="LESSTHAN";program.emplace_back(yytext);count(); return '<';}
">"                     { symtab[yytext]="GREATERTHAN";program.emplace_back(yytext);count(); return '>';}
"^"                     { symtab[yytext]="XOR";program.emplace_back(yytext);count(); return '^';}
"|"                     { symtab[yytext]="OR";program.emplace_back(yytext);count(); return '|';}
"?"                     { symtab[yytext]="QUESTION MARK";program.emplace_back(yytext);count(); return '?';}
[ \t\v\n\f]              { /* DO NOTHING*/ count();}
.                       { iserror=true;error.emplace_back(yytext,line_num);count();}
%%
void comment()
{
    char c, c1;

loop:
    while ((c = yyinput()) != '*' && c != 0){
        if(c=='\n')line_num++;
    };
    if ((c1 = yyinput()) != '/' && c != 0)
    {
        unput(c1);
        goto loop;
    }

    if (c != 0){
        // do nothing
    }
    if(c==0){
        iserror=true;
    }

}
void count(){
    for(int i=0;i<yyleng;i++){
        if(yytext[i]=='\n')line_num++;
    }
}
int yywrap()
{
    return(1);
}
