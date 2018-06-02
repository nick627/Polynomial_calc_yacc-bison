¬ отчет добавьте страницу чисто грамматики, примеры ошибок, описание синтаксиса

2 task:
   ѕосле того как калькул€тор полиномов готов,
   Ќужно написать свой псведо€зык полиномов, который поддерживает:
   - переменные типа полином - им можно присваивать полиномы,     - работать с переменными
   - оператор вывода на печать переменной
   - как обрабатывать полиномы от разных переменных- либо ошибка, либо нормально считать
   - комментарии
   - сообщени€ об ошибках:
     - лексические 
     - синтаксические
     - семантические (0^0, ../0, ..^полином и т.д.)

   ¬ отчете привести грамматику, как хранитс€ полином, сообщени€ об ошибках с примерами.

for Windows:
   in file.y add:
   %{
      #define alloca malloc
   %}

   bison.exe -y -d file.y


for Linux:
   sudo apt-get install gcc

   sudo apt-get install bison flex


for make.sh:

   #!/bin/sh
   yacc -d polyc_yacc.y

   sed -i '1 i #include "polyc.h"' y.tab.h
   gcc source.c polyc.h y.tab.c y.tab.h -o a.out

   ./a.out


run: 
   #> sh make.sh
   #> ./a.out


link for C++ in yacc:
   http://www.gnu.org/software/bison/manual/html_node/Calc_002b_002b-Parser.html