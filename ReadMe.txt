� ����� �������� �������� ����� ����������, ������� ������, �������� ����������

2 task:
   ����� ���� ��� ����������� ��������� �����,
   ����� �������� ���� ���������� ���������, ������� ������������:
   - ���������� ���� ������� - �� ����� ����������� ��������,     - �������� � �����������
   - �������� ������ �� ������ ����������
   - ��� ������������ �������� �� ������ ����������- ���� ������, ���� ��������� �������
   - �����������
   - ��������� �� �������:
     - ����������� 
     - ��������������
     - ������������� (0^0, ../0, ..^������� � �.�.)

   � ������ �������� ����������, ��� �������� �������, ��������� �� ������� � ���������.

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