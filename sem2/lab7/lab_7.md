# Programowanie proceduralne

## Laboratorium 7

## Zadania

</div>

1.  <font color="#ff0080">( 4 )</font> Proszę uzupełnić program

    <pre><tt> <font color="blue">#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int double_cmp(const void *a, const void *b); <small><font color="#9d9d9d">//komparator dla double</font> </small>  

    int cstring_cmp(const void *a, const void *b);   <small><font color="#9d9d9d">//komparator dla stringów</font></small>  

    void print_dounle_array(double*,int); <small><font color="#9d9d9d">//wypisywanie tablicy double</font></small>  

    void print_cstring_array(char**,int); <small><font color="#9d9d9d">//wypisywanie tablicy string'ów</font></small>  

    void sort_double_example()   <small><font color="#9d9d9d">//sortowanie tablicy double</font></small>
    {
        double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1,2, 43.0, 2.0, -4.7, 5.8 };
        size_t numbers_len = _____________________________;  <small><font color="#9d9d9d">//określenie długości tablicy</font></small>

        puts("*** Double sorting...");

          print_double_array(_______, ________);   <small><font color="#9d9d9d">//wypisanie tablicy przed sortowaniem</font> </small>
       qsort(_______, ________, ________, _________);   <small><font color="#9d9d9d">//sortowanie tablicy integer</font></small>

        print_double_array(_______, ________);  <small><font color="#9d9d9d">//wypisanie tablicy po sortowaniu</font> </small>
    }

    void sort_cstrings_example() <small> <font color="#9d9d9d">//sortowanie tablicy stringów</font></small>
    {
        char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
        size_t strings_len = ________________________________;   <small><font color="#9d9d9d">//okreslenie długości tablicy</font></small>

        puts("*** String sorting...");

        print_cstring_array(_______, ________);   <small><font color="#9d9d9d">//wypisanie tablicy przed sortowaniem</font> </small>

        qsort(____________, _________________, ________________, ___________________);  <small><font color="#9d9d9d">//sortowanie tablicy stringów</font></small>

        print_cstring_array(_______, ________);   <small><font color="#9d9d9d">//wypisanie tablicy po sortowaniu</font> </small>
    }

     <small><font color="#9d9d9d">// MAIN program (wywołanie funkcji sortujacych)</font> </small>
    int main()
    {

        sort_double_example();
        sort_cstrings_example();

        return 0;
    }</font> </tt></pre>

2.  <font color="#ff0080">( 2 )</font> Proszę rozbudować poprzedni program :
    *   wczytanie łańcucha znaków i sprawdzenie, czy znajduje się on w tablicy `**strings**` i pod jakim indeksem.
    *   wczytanie liczby i sprawdzenie, czy znajduje się on w tablicy `**double numbers**`i pod jakim indeksem.

5.  <font color="#ff0080">( 3 )</font> W programie mamy zdefiniowane następujące funkcje oraz tablicę stringów :

    <pre> <font color="blue">double fun0(double x) { return log(x); }
    double fun1(double x) { return x*x;    }
    double fun2(double x) { return tan(x); }
    double fun3(double x) { return sin(x); }
    double fun4(double x) { return cos(x); }
    char* nazwy[]={"log", "pow", "tan","sin","cos"};</font> </pre>

    Proszę stworzyć 5-cio elementową tablicę wskaźników do funkcji **TAB_FUN**, tak aby można było dokonać podstawień:

    <pre> <font color="blue">TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = fun4;</font> </pre>

    Następnie proszę napisać funkcję zwracającą wskaźnik do funkcji , która dla argumentu typu double ma największą wartość. Proszę wypisać <u>nazwę funkcji i wartość funkcji</u>.  
    _Najwieksza wartosc dla x=1 ma funkcja tan. Wartosc wynosi 1.557_ _Najwieksza wartosc dla x=0.05 ma funkcja cos. Wartosc wynosi 0.998_

8.  <font color="#ff0080">( 1 )</font> Proszę skonstruować strukturę, która posłuży do przechowywania wektora 3D. W funkcji `**main()**` proszę utworzyć dwie zmienne, które będą przechowywały dwa wektory. Korzystając z funkcji **scanf()** proszę nadać im wartości i wypisać wektory na ekran w postaci

    <pre> _w1 = [1.0, 3.0, 6.0]
    w2 = [4.5, 4.0, 7.0]_ </pre>

9.  <font color="#ff0080">( 1 )</font> Proszę napisać funkcję, która oblicza długość wektora. Do funkcji przekazujemy pola struktury. Proszę wywołać funkcję dla wektora `**w1**` z zadania 4.

12.  <font color="#ff0080">( 1 )</font> Proszę napisać funkcję, która oblicza sumę dwóch wektorów. Do funkcji przekazujemy dwie struktury <font size="4">przez wartość</font>. Funkcja ma zwracać <font size="4">strukturę przez wartość</font>. Proszę wywołać funkcję dla wektorów `**w1**` oraz `**w2**` z zadania 1 i wypisać wyniki na ekran.

15.  <font color="#ff0080">( 1 )</font> Proszę napisać <font size="4">procedurę</font>, która obliczy iloczyn skalarny dwóch wektorów 3D. Do procedury przekazujemy dwie struktury <font size="4">przez adres</font>. Proszę wywołać procedurę dla wektorów `**w1**` oraz `**w2**` z zadania 4 i wypisać wyniki na ekran.

<div>_iloczyn skalarny:

<div class="math" align:="" baselinekomentarz="">\[\vec{x}\cdot\vec{y}\,=\,|\vec{x}|\,|\vec{y}|\,\cos\alpha\,= \sum_{i\,=\,1}^n x_i y_i \]</div>

_  

*   <font color="#ff0080">( 1 )</font> Proszę napisać <font size="4">procedurę</font>, która obliczy iloczyn wektorowy dwóch wektorów 3D. Do procedury przekazujemy dwie struktury <font size="4">przez wartość</font> i trzecią <font size="4">przez adres</font>. Proszę wywołać procedurę dla wektorów `**w1**` oraz `**w2**` z zadania 4 i wypisać wyniki na ekran.  

<div>_iloczyn wektorowy:

<div class="math" align:="" baselinekomentarz="">\[\vec{x}\times\vec{y}\,=\,( x_2 y_3 + x_3 y_2;\ x_1 y_3 + x_3 y_1;\ x_1 y_2 + x_2 y_1)\]</div>

_  

*   <font color="#ff0080">( 2 )</font> W programie proszę utworzyć strukturę `**struct wektor**` do przechowywania współrzędnych wektora 3D, oraz strukturę `**abc**`, która ma dwa pola: `**vect**` typu `**struct wektor**` oraz `**dlugosc**` typu **double**, gdzie zapisana jest długość wektora z pola `**vect**`.  
    Proszę zaalokować tablicę struktur `**abc**` o rozmiarze podanym jako <font size="4">parametr wywołania programu</font>, wypełnić liczbami losowymi pola `**vect**` w elemantach tablicy.  
    Proszę napisać funkcję `**f_d** `zgodną z podanym prototypem

         double f_d (struct abc *);

    która wykorzystując funkcję z zadania 5 uzupełnia pole `**dlugosc**` we wszystkich elementach tablicy.</div>

</div>
