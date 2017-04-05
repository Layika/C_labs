# Programowanie proceduralne

## Laboratorium 5

[tablice, funkcje, wkaźniki do ....](./wskazniki_zestawienie.pdf)

<div align="center">

## Zadania

</div>

1.  <font color="#ff0080">( 3 + za każde wywołanie 1 punkt)</font> Proszę napisać trzy funkcje, zgodne z poniższymi prototypami, które wypisują elementy tablic, które są pierwszymi argumentami

    `<font color="blue">void f1(int a[][columns], int x);</font> <font color="#808080">//wypisywanie wierszami</font>`
    `<font color="blue">void f2(int *apointer, int x);</font> <font color="#808080">//wypisywanie w jednym wierszu</font>`
    `<font color="blue">void f3(int **pp, int x, int y);</font><font color="#808080">//wypisywanie wierszami</font>`

    Korzystając z _[pliku](./array.c)_ proszę spróbować wykorzystać (jeżeli jest to możliwe) każdą funkcję do wypisania tablic array_1, array_2\. array_3, array_4 oraz array_5.

4.  <font color="#ff0080">( 2 )</font> Proszę napisać funkcję, która mnoży dwie tablice `**A**` i `**B**`, a wynik przekazuje przez tablicę `**C**` zgodnie z prototypem

    `<font color="blue">void mn_tab (int n,int m, int l, int A[][n], int B[][m], int C[][m]);</font>`

    Proszę przetestować funkcję dla tablic :

    `**int t_A [2][3] = {1,2,3,4,5,6};**`
    `**int t_B [3][4] = {1,1,1,1,1,1,1,1,1,1,1,1};**`

6.  <font color="#ff0080">( 2 )</font> Proszę napisać poprzednie zadanie z funkcją `**mn_tab_1**`

    `<font color="blue">.......... mn_tab_1 (int n, int m, int l, int A[][n], int B[][m]);</font>`

    Wynik proszę wypisać przy użyciu procedury

    `<font color="blue">void f1(int a[][4], int x );</font>`

9.  <font color="#ff0080">( 1 )</font> Proszę dokończyć program, który zamieni w łańcuchu **lancuch** litery duże na małe . Co należy wstawić zamiast pytajników ?
    Funkcja zamieniająca duże litery na małe **`char tolower(char)`**

        int main(void){
          char lancuch[ ]="ALA MA KOTA";
          int i = ?;
          printf("lancuch->?\n",?);
          while(?);
          printf("lancuch->?\n",?);
          return 0;
        }

12.  <font color="#ff0080">( 3 )</font> Proszę uzupełnić program. Procedura `**Slowa_Na_Duze**` zamienia pierwsze litery wyrazów na duże

        #include <stdio.h>
        #include <ctype.h>

        .......... Slowa_Na_Duze (char* tekst ) {
        char*wsk =............;

        if(  )         //jeśli pusty
            return(tekst);
        ........... = toupper(.............. );
        while (............ )
         if(........... == ...........  )  //jeśli początek wyrazu zamień na dużą
         ............... = toupper( ............... );
         return( tekst );
        }

        int main(void ) {

        char lancuch[100] = "to  jest      probka  tekstu    ";
           printf( "%s\n" , Slowa_Na_Duze( lancuch ) );
                return 0;
        }

15.  <font color="#ff0080">( 2 )</font> Proszę napisać własną wersję funkcji `**int strcmp (char *, char *);** `- funkcja zwraca wartość:
        <font color="#5f5f5f">< 0</font>  gdy  tekst_1 < tekst_2

       <font color="#5f5f5f">= 0</font>  gdy  tekst_1 == tekst_2

       <font color="#5f5f5f">> 0</font>  gdy  tekst_1 > tekst_2

    Proszę napisać funkcję bez użycia dodatkowych zmiennych. Można skorzystac z jednego ze schematów :

        int  str_n_cmp( char*tekst_1, char*tekst_2  )
        {while( ................ )
        {if(  .................. ) return( 0 );
                        ......... ;
                        ..........;
        }
        return(  .............. - ................  );
        }

    lub

        int  str_n1_cmp( char*tekst_1, char*tekst_2  )
        {for( ;...............; ........++ )
             if( ............) return( 0 );
        return(  .............. - ................ );
        }
