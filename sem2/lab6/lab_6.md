*   funkcja **sprintf**

      ```
        #include <stdio.h>
        #include <string.h>
        #define MAX 20
        int main(void)
        {
            char imie[MAX];
            char nazwisko[MAX];
            char format[ ]="%s, %-19s: %6.2f zl\n";
            char napis[2 * MAX + 10];
            double wygrana;
            puts("Podaj swoje imie:");
            gets(imie);
            puts("Podaj swoje nazwisko:");
            gets(nazwisko);
            puts("Podaj wygrana sume pieniedzy:");

            scanf("%lf", &wygrana);
            printf ("forma wypisywania  %s", format);
            sprintf(napis, format, nazwisko, imie, wygrana);
            puts(napis);
            return 0;
        }
        ```

*   funkcja **strcat**

```
        #include <stdio.h>
        #include <string.h>
        main(){
        char tab[25] = "Ala ma ";
        char tab2[] = "kota i psa";
        printf("%s",strcat(tab,tab2));}
        }
```

*   funkcja **strchr**

```
        #include <stdio.h>
        #include <string.h>
        int main(){
        	char tekst[] = "To jest tekst";
        	printf("%s ",strchr(tekst,'e'));

        }
        ```

* * *

# Programowanie proceduralne

## Laboratorium 6


<div align="center">

## Zadania

</div>

1.  ( 2 ) Proszę uzupełnić program

```
        #include <stdio.h>

        #include <stdlib.h>
        #include <string.h>

        void print_string_array(_____________, _________________);//wypisywanie tablicy stringów
        ______ min_string (________________,_________________); //znajdowanie najmniejszego stringu w tablicy stringów - zwraca wskaźnik

        int main()

        {
            char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};

        	_____wsk_string;

        		size_t strings_len = ________________________________; //okreslenie długości tablicy strings

            print_string_array(strings, strings_len); //wypisanie tablicy

            wsk_string = min_string(strings,strings_len)//znalezienie najmniejszego stringu w tablicy

            printf("____________\n", wsk_string); //wypisanie najmniejszego stringu

        	return 0;
        }
```

4.  ( 3 ) Proszę uzupełnić program.

```
        #include <stdio.h>
        #include <string.h>
        #define ROZMIAR 81        //maksymalna dlugość łańcuchów
        #define GRAN 20           // maksymalna liczba łańcuchów
        void sortlan(char *lan[], int num);  //procedura sortująca łancuchy
        int main(void)
        {
          char dane[GRAN][ROZMIAR];    //tablica przechowujaca łańcuchy
          char *wsklan[GRAN];
          int licz = 0;                //licznik danych wejsciowych
          int k;                         */
          printf("Podaj maksymalnie %d wierszy \n",GRAN);
          printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");

         while (licz < GRAN && gets(dane[licz]) != NULL && dane[licz][0] != '\0')
          {
             ................. = ....................;    /ustaw wskaźniki na łańcuchy
             licz++;
          }
          srtlan(................, licz);
          puts("\n Oto uporzadkowana lista:\n");
          for (k = 0; k < licz; k++)
             puts(........................) ;
          return 0;
        }

        // procedura sortująca  - która tablica jest sortowana ?

        void sortlan(char *lan[], int num)
        {
          //potrzebne zmienne lokalne

          for (.......; ........;.........)
             for (...............; ...............; .............)
                if (strcmp(.................,....................) > 0)
                {
                    .......................;
                    .......................;
                    .......................;
                }
        }
      ```

6.  ( 2 ) W funkcji `**main** `proszę zadeklarować tablicę jednowymiarową `**losuj_wyraz**` o długości 10 i wypełnić ją losowymi małymi literami tak, aby powstał <u>łańcuch znaków</u>. Następnie proszę wylosować dowolną małą literę i zapisać jako zmienną `**losowa**`. Korzystając z funkcji `**strchr**` (z biblioteki `**<string.h>**`), proszę sprawdzić czy wylosowana litera znajduje się w łańcuchu `**losuj_wyraz**`. Jeżeli została znaleziona to proszę wypisać na ekranie indeks pierwszego wystąpienia litery `**losowa**` w łańcuchu `**losuj_wyraz**` oraz sprawdzić ile razy występuje w wylosowanym łańcuchu. Cały czas proszę używać funkcji `**strchr**`

9.  ( 3 ) Proszę napisać program, który wypisze:

    ```
    FORMAT %.0lf ->3
    FORMAT %.2lf ->3.14
    FORMAT %.4lf ->3.1416
    FORMAT %.6lf ->3.141593</font> </pre>
```

```
        #include ...............
        #include ................
        #include .................
        int main(){
        char pi_form[6]=.................;
        int i;
        for (i=0; i<7; i+=2){
        	........(pi_form, ".................",i);
        	printf("FORMAT ..........->",pi_form);
        	.......(......,"\n");
        	printf(.......,M_PI); //M_PI stała z biblioteki math.h
        }
        }
      ```

11.  ( 3 ) Proszę napisać funkcję `**zero**` znajdującą miejsce zerowe funkcji <u>metodą bisekcji</u>.

    ```
        int zero(double (*f)(double), double a, double b, double* z, double eps);
        ```

    *   `***f**` wskaźnik do funkcji
    *   `**a, b**` - poczatek i koniec przedziału
    *   `**z**` miejsce zerowe
    *   `**eps**` - dokładność
    *   funkcja zwraca 0 gdy nie znajdzie miejsca zerowego, 1 gdy znajdzieProszę przetestować dla fukcji
    *   `**sin(x)**` w przedziale <-1, 1>
    *   `**-x²+3*x+11**` w przedziale <0, 8 >
    *   `**-x²+3*x+11**` w przedziale <-1, 1 >

14.  ( 2 ) Proszę zdefiniować funkcję, która zwraca różnicę dwóch liczb całkowitych, oraz funkcję, która zwraca sumę liczb całkowitych.
    Niech prototypy funkcji mają postać:

```
        int add2(int * , int *);
        int comp2(int * , int *);
```

    Proszę zdefiniować funkcję

```
        int add2_or_comp2 (.............., ..............., ..............);
```

    której argumenty to:
    *   dwie wartości całkowite,
    *   wskaźnik do funkcji, która pobiera dwa <u>wskaźniki</u> na `**int**`, a zwraca wartość typu `**int**`funkcja `**add2_or_comp2()**` ma zwracać wartość typu `**int**`, która jest wynikiem przekazanej przez wskaźnik funkcji.
    W funkcji main() proszę wczytać dwie wartości całkowite, a nastepnie korzystając z funkcji `**add2_or_comp2()**` wypisać ich sumę oraz różnicę .
