# Programowanie proceduralne

## Laboratorium 1

<div align="center">

## Zadania

</div>

1.  ( 3 ) Dokończ program. Nie używaj operatora nawiasowego

    <pre><tt> #include <stdio.h>
        #define N ...........

        .........suma_rek(.........., ..............);

        int main(void){

    	 //deklaracja tablicy 10 liczb całkowitych, użyj N
    //deklaracja wskaźnika p do liczby całkowitej, użyj NULL
    //nie używaj zmiennej int i do indeksowania tablicy
    //przypisz kolejnym elementom tablicy liczby pseudolosowe z przedziału od 7 do 35 i wypisz je na ekran

        for(...=tab; .... <... + N ; ....++){
           ....=rand()......;  //użyj p,  // nie korzystaj z tab

    //korzystając z p oraz tab oblicz wartość indeksu kolejnych elementów tablicy, wypisz wartości kolejnych elementówużywając p

           printf("p[%d]=%d\n", .............., ...............);
    }

    printf("\n");

     //oblicz rekurencyjnie sumę elementów tablicy.

        int su = suma_rek(............., ..............);   //nie używaj N

        printf("su=%d\n",su);
        return 0;
        }

     //funkcja rekurencyjna liczaca sume elementów tablicy
        ..... suma_rek ( ......,  ......){  //nie używaj N
          if (.........................)
       return ....... + ................;
         else
       return .....................;
        } </tt></pre>

2.  Proszę zaimplementować obsługę kolejki (LIFO) - stosu w oparciu o tablicę jednowymiarową o zadanym przed dyrektywę **#define** rozmiarze.
    Należy zdefiniować funkcje

    *   ( 1 ) czytanie stosou "od dna" `void show (int *);`
    *   ( 2 ) dokładania do stosu `void push (int *, int);`
    *   ( 2 ) zbierania ze stosu `int pop (int *);`

4.  Proszę napisać <u>procedurę</u> `..... zamiana(..., ....)` , która zamieni wartości przekazanych jej argumentów.

    1.  ( 1 ) W funkcji **main()**, utwórz dwia zmienne i zamień ich wartości przy użyciu procedury **zamiana())**.
    2.  ( 1 ) Napisz procedurę `..... odwroc(..., ....)` przeznaczoną do odwrócenia jednowymiarowej tablicy. Zastosuj w niej procedurę **zamiana()**.
    3.  ( 1 ) Napisz procedurę `..... wymien_tablice(......., ........, ......) `do wymiany zawartości dwóch jednowymiarowych tablic. Zastosuj w niej procedurę **zamiana()**.

6.  ( 2 ) Proszę napisać funkcję, która będzie zwracać w wyniku **sumę n elementów** tablicy **t[n]** liczb zmiennopozycyjnych, **wartość minimalną i maksymalną, wartość średnią jej elementów, maksymalne i minimalne odchylenie od wartości średniej**.
    Prototyp funkcji `float suma (float *t, int n, ????); `lub `float suma (float t[], int n, ????);. `**Zadanie proszę wykonać w wersji wskażnikowej i indeksowej**

8.  ( 2 )Proszę napisać i przetestować funkcję zamieniającą kolejność elementów tablicy w taki sposób by elementy parzyste znalazły się na początku, a elementy nieparzyste na końcu tablicy. Zero traktujemy jako liczbę parzystą

czwartek

12.  ( 2 ) Proszę napisać program przesuwający tablicę cyklicznie w prawo o zadaną liczbę pozycji (element o indeksie **n-1** wchodzi na pozycję o indeksie **0**).
