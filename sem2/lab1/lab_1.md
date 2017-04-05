# Programowanie proceduralne

## Laboratorium 1

<span style="font-family: 'Lucida Console'">Programy <font color="red">pliki źódłowe</font> proszę wysłać przed końcem zajęć na adres <font color="green">grazyna@fis.agh.edu.pl</font>

W tytule maila proszę napisać - <font color="green">IS_LAB_1</font> , a w treści proszę podać <font color="green">imię i nazwisko</font></span>

<div align="center">

## Zadania

</div>

1.  <font color="#ff0080">( 3 )</font> Dokończ program. Nie używaj operatora nawiasowego

    <pre><tt> <font color="blue">#include <stdio.h>
        #define N ...........

        .........suma_rek(.........., ..............);

        int main(void){

    	 <font color="#808080">//deklaracja tablicy 10 liczb całkowitych, użyj N
    //deklaracja wskaźnika p do liczby całkowitej, użyj NULL
    //nie używaj zmiennej int i do indeksowania tablicy
    //przypisz kolejnym elementom tablicy liczby pseudolosowe z przedziału od 7 do 35 i wypisz je na ekran</font>

        for(...=tab; .... <... + N ; ....++){
           ....=rand()......;  <font color="#808080">//użyj p,  // nie korzystaj z tab

    //korzystając z p oraz tab oblicz wartość indeksu kolejnych elementów tablicy, wypisz wartości kolejnych elementówużywając p</font>

           printf("p[%d]=%d\n", .............., ...............);
    }

    printf("\n");

     <font color="#808080">//oblicz rekurencyjnie sumę elementów tablicy.</font>

        int su = suma_rek(............., ..............);  <font color="#808080"> //nie używaj N</font>

        printf("su=%d\n",su);
        return 0;
        }

     <font color="#808080">//funkcja rekurencyjna liczaca sume elementów tablicy</font>
        ..... suma_rek ( ......,  ......){  <font color="#808080">//nie używaj N</font>
          if (.........................)
       return ....... + ................;
         else
       return .....................;
        }</font> </tt></pre>

2.  Proszę zaimplementować obsługę kolejki (LIFO) - stosu w oparciu o tablicę jednowymiarową o zadanym przed dyrektywę **#define** rozmiarze.
    Należy zdefiniować funkcje

    *   <font color="#ff0080">( 1 )</font> czytanie stosou "od dna" `<font color="blue">void show (int *);</font>`
    *   <font color="#ff0080">( 2 )</font> dokładania do stosu `<font color="blue">void push (int *, int);</font>`
    *   <font color="#ff0080">( 2 )</font> zbierania ze stosu `<font color="blue">int pop (int *);</font>`

4.  Proszę napisać <u>procedurę</u> `<font color="blue">..... zamiana(..., ....)</font>` , która zamieni wartości przekazanych jej argumentów.

    1.  <font color="#ff0080">( 1 )</font> W funkcji **main()**, utwórz dwia zmienne i zamień ich wartości przy użyciu procedury **zamiana())**.
    2.  <font color="#ff0080">( 1 )</font> Napisz procedurę `<font color="blue">..... odwroc(..., ....)</font>` przeznaczoną do odwrócenia jednowymiarowej tablicy. Zastosuj w niej procedurę **zamiana()**.
    3.  <font color="#ff0080">( 1 )</font> Napisz procedurę `<font color="blue">..... wymien_tablice(......., ........, ......)</font> `do wymiany zawartości dwóch jednowymiarowych tablic. Zastosuj w niej procedurę **zamiana()**.

6.  <font color="#ff0080">( 2 )</font> Proszę napisać funkcję, która będzie zwracać w wyniku **sumę n elementów** tablicy **t[n]** liczb zmiennopozycyjnych, **wartość minimalną i maksymalną, wartość średnią jej elementów, maksymalne i minimalne odchylenie od wartości średniej**.
    Prototyp funkcji `<font color="blue">float suma (float *t, int n, ????);</font> `lub `<font color="blue">float suma (float t[], int n, ????);.</font> `**Zadanie proszę wykonać w wersji wskażnikowej i indeksowej**

8.  <font color="#ff0080">( 2 )</font>Proszę napisać i przetestować funkcję zamieniającą kolejność elementów tablicy w taki sposób by elementy parzyste znalazły się na początku, a elementy nieparzyste na końcu tablicy. Zero traktujemy jako liczbę parzystą

<font color="#ff8000">czwartek</font>

12.  <font color="#ff0080">( 2 )</font> Proszę napisać program przesuwający tablicę cyklicznie w prawo o zadaną liczbę pozycji (element o indeksie **n-1** wchodzi na pozycję o indeksie **0**).
