del Code.txt
del Yacc.output
Tools\flex.exe Tools\Lex.l
move lex.yy.c Hamster\Lex.cpp
Tools\bison.exe -v -d Tools\Yacc.y
move Yacc.tab.c Hamster\Yacc.cpp
move Yacc.tab.h Hamster\Yacc.h
pause