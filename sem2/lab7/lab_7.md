# Programowanie proceduralne

## Laboratorium 7

## Zadania

</div>

1.  ( 4 ) Proszę uzupełnić program

    <pre><tt>#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int double_cmp(const void *a, const void *b); <small>//komparator dla double</small>  

    int cstring_cmp(const void *a, const void *b);   <small>//komparator dla stringów</small>  

    void print_dounle_array(double*,int); <small>//wypisywanie tablicy double</small>  

    void print_cstring_array(char**,int); <small>//wypisywanie tablicy string'ów</small>  

    void sort_double_example()   <small>//sortowanie tablicy double</small>
    {
        double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1,2, 43.0, 2.0, -4.7, 5.8 };
        size_t numbers_len = _____________________________;  <small>//określenie długości tablicy</small>

        puts("*** Double sorting...");

          print_double_array(_______, ________);   <small>//wypisanie tablicy przed sortowaniem </small>
       qsort(_______, ________, ________, _________);   <small>//sortowanie tablicy integer</small>

        print_double_array(_______, ________);  <small>//wypisanie tablicy po sortowaniu </small>
    }

    void sort_cstrings_example() <small> //sortowanie tablicy stringów</small>
    {
        char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
        size_t strings_len = ________________________________;   <small>//okreslenie długości tablicy</small>

        puts("*** String sorting...");

        print_cstring_array(_______, ________);   <small>//wypisanie tablicy przed sortowaniem </small>

        qsort(____________, _________________, ________________, ___________________);  <small>//sortowanie tablicy stringów</small>

        print_cstring_array(_______, ________);   <small>//wypisanie tablicy po sortowaniu </small>
    }

     <small>// MAIN program (wywołanie funkcji sortujacych) </small>
    int main()
    {

        sort_double_example();
        sort_cstrings_example();

        return 0;
    } </tt></pre>

2.  ( 2 ) Proszę rozbudować poprzedni program :
    *   wczytanie łańcucha znaków i sprawdzenie, czy znajduje się on w tablicy `**strings**` i pod jakim indeksem.
    *   wczytanie liczby i sprawdzenie, czy znajduje się on w tablicy `**double numbers**`i pod jakim indeksem.

5.  ( 3 ) W programie mamy zdefiniowane następujące funkcje oraz tablicę stringów :

    <pre> double fun0(double x) { return log(x); }
    double fun1(double x) { return x*x;    }
    double fun2(double x) { return tan(x); }
    double fun3(double x) { return sin(x); }
    double fun4(double x) { return cos(x); }
    char* nazwy[]={"log", "pow", "tan","sin","cos"}; </pre>

    Proszę stworzyć 5-cio elementową tablicę wskaźników do funkcji **TAB_FUN**, tak aby można było dokonać podstawień:

    <pre> TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = fun4; </pre>

    Następnie proszę napisać funkcję zwracającą wskaźnik do funkcji , która dla argumentu typu double ma największą wartość. Proszę wypisać <u>nazwę funkcji i wartość funkcji</u>.  
    _Najwieksza wartosc dla x=1 ma funkcja tan. Wartosc wynosi 1.557_ _Najwieksza wartosc dla x=0.05 ma funkcja cos. Wartosc wynosi 0.998_

8.  ( 1 ) Proszę skonstruować strukturę, która posłuży do przechowywania wektora 3D. W funkcji `**main()**` proszę utworzyć dwie zmienne, które będą przechowywały dwa wektory. Korzystając z funkcji **scanf()** proszę nadać im wartości i wypisać wektory na ekran w postaci

    <pre> _w1 = [1.0, 3.0, 6.0]
    w2 = [4.5, 4.0, 7.0]_ </pre>

9.  ( 1 ) Proszę napisać funkcję, która oblicza długość wektora. Do funkcji przekazujemy pola struktury. Proszę wywołać funkcję dla wektora `**w1**` z zadania 4.

12.  ( 1 ) Proszę napisać funkcję, która oblicza sumę dwóch wektorów. Do funkcji przekazujemy dwie struktury <font size="4">przez wartość. Funkcja ma zwracać <font size="4">strukturę przez wartość. Proszę wywołać funkcję dla wektorów `**w1**` oraz `**w2**` z zadania 1 i wypisać wyniki na ekran.

15.  ( 1 ) Proszę napisać <font size="4">procedurę, która obliczy iloczyn skalarny dwóch wektorów 3D. Do procedury przekazujemy dwie struktury <font size="4">przez adres. Proszę wywołać procedurę dla wektorów `**w1**` oraz `**w2**` z zadania 4 i wypisać wyniki na ekran.
_  

*   ( 1 ) Proszę napisać <font size="4">procedurę, która obliczy iloczyn wektorowy dwóch wektorów 3D. Do procedury przekazujemy dwie struktury <font size="4">przez wartość i trzecią <font size="4">przez adres. Proszę wywołać procedurę dla wektorów `**w1**` oraz `**w2**` z zadania 4 i wypisać wyniki na ekran.  

_  

*   ( 2 ) W programie proszę utworzyć strukturę `**struct wektor**` do przechowywania współrzędnych wektora 3D, oraz strukturę `**abc**`, która ma dwa pola: `**vect**` typu `**struct wektor**` oraz `**dlugosc**` typu **double**, gdzie zapisana jest długość wektora z pola `**vect**`.  
    Proszę zaalokować tablicę struktur `**abc**` o rozmiarze podanym jako <font size="4">parametr wywołania programu, wypełnić liczbami losowymi pola `**vect**` w elemantach tablicy.  
    Proszę napisać funkcję `**f_d** `zgodną z podanym prototypem

         double f_d (struct abc *);

    która wykorzystując funkcję z zadania 5 uzupełnia pole `**dlugosc**` we wszystkich elementach tablicy.</div>

</div>
