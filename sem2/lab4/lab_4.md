# Programowanie proceduralne

## Laboratorium 4


<div align="center">

## Zadania

</div>

1.  ( 2 ) W funkcji `**main**` proszę utworzyć tablicę dwuwymiarową, `**T_A[4][4]**`, zainicjalizowac ją liczbami losowymi z przedziału od 10.0 do 20.0 i wypisać na ekran:
    1.  zawartość tablicy `**T_A** `wierszami
    2.  sumę elementów na przekątnej tablicy `**T_A**`
    3.  sumę elementów pod przekątną tablicy `**T_A**`
    4.  sumę elementów w poszczególnych kolumnach tablicy `**T_A**`
    5.  przetransponowaną tablicę `**T_A** `- (bez użycia dodatkowej tablicy)

3.  ( 1 ) Proszę napisać, zgodne ze schematem, procedury wypisującą w jednym wierszu elementów tablic jednowymiarowych :
    Tablica `**double** void wypisz (double *poczatek, double *koniec) {
       while (poczatek < koniec)
        printf ("%6.2f", .............);
      return;}`

    Tablica `**int** void wypisz_int (int *poczatek, int *koniec) {
       while (poczatek < koniec)
        printf ("%4d", .............);
      return;}`

<div align="center">

## W KOLEJNYCH ZADANIACH DO WYPISYWANIA TABLIC PROSZĘ WYKORZYSTYWAĆ PROCDURY
`**wypisz**` lub `**wypisz_int**`

</div>

6.  *   ( 1 ) W funkcji **main** proszę utworzyć dwuwymiarową tablicę liczb całkowitych `**abc**` o rozmiarze [5][4], i zainicjować ją wartościami z przedziału od -10 do 10\.
        Tablicę proszę wypiasać wierszami (procedura `**wypisz**`).

    *   ( 1 ) Proszę napisać funkcję zgodną z prototypem `double srednia (int *tab, int ile);`, która liczy wartość średnią z przekazanej tablicy `**tab**` i sprawdzić jej działanie na tablicy
        `int test[6] = {1,3,5,7,-8,-11}`

    *   ( 2 ) Wykorzystując funkcję `**srednia**`, proszę policzyć średnie z poszczególnych wierszy tablicy `**abc**`. Wyliczone wartości należy zapisać do tablicy `**avg_abc**`, która jest zadeklarowana w funkcji `**main**`

    *   ( 1 ) Wykorzystując funkcję `**srednia**`, proszę policzyć średnią z całej tablicy `**abc**`.
        `  double avg_all = srednia (..............., ............);`

7.  ( 1 ) Proszę napisać i przetestować na odpowiedniej tablicy funkcję sumującą elementy tablicy `  float suma (float (*)[5], int);`

10.  Proszę zaalokować i wyzerować zawartość (`**calloc**`) cztery tablice `**array_1, array_2, array_3, array_4**`
    Każdą tablicę należy wypisać, a następnie zwolnić pamięć :
    *   ( 2 ) tablica dwuwymiarowa `**array_1**` o rozmiarach `**rows x columns**`, tak aby organizacja wygladała jak na rysunku:
        ![](./array_1.png)

    *   ( 2 ) tablica dwuwymiarowa `**array_2**` o rozmiarach `**rows x columns**`, tak aby organizacja wygladała jak na rysunku:
        ![](./array_2.png)

    *   ( 2 ) tablica dwuwymiarowa `**array_3**` o rozmiarach `**rows x columns**` "przypięta" do wskaźnika `**int (* array_3)[columns]**`

    *   ( 2 ) tablica jednowymiarowa `**array_4**`, która ma `**rows*columns** `elementów
