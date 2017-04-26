# Programowanie proceduralne

## Laboratorium 8
## Zadania

1.  ( 4 ) Proszę utworzyć strukturę `**Klient**`, zawierającą pola: `**f_name**` i `**l_name** `do przechowywania imienia i nazwiska, pole `**code**` do przechowywania kodu pocztowego w rzeczywistym formacie oraz pole `**age**`.  
    Następnie,proszę utworzyć tablicę 5 elementową struktur i wypełnić danymi wczytanymi z pliku tekstowego **dane.txt** - proszę wcześniej je przygotować.  
    Tablicę proszę posortować według **nazwiska** (pierwszy klucz sortowania), a następnie według **imienia** (drugi klucz sortowania).

4.  ( 4 ) Proszę skonstruować strukturę `**liczba**`, która ma dwa pola: `**zmienną znakową**` oraz `**unię**`.  
    Unia ma dwa pola: `**zmienną całkowitą**` oraz `**zmienną rzeczywistą**` podwójnej precyzji.  
    Zmienna znakowa przyjmuje jedną z dwóch wartosci **'i'** lub **'d'** oznaczającą typ zmiennej przechowywanej w unii.  
    Zaalokuj tablicę 20 struktur typu `**liczba**`, z prawdopodobieństwem 1/2 wypełnij ją liczbami całkowitymi i rzeczywistymi.  
    Napisz funkcję, która wypisze elementy tablicy (wartość i typ). Zapisz tablicę do pliku binarnego. Sprawdź ile danych jest zapisanych w pliku binarnym i wczytaj je do odpowiednio dużej dynamicznej tablicy.

8.  ( 2 ) Proszę napisać <u>jedną funkcję sortującą</u>, która jednocześnie posortuje elementy całkowite niemalejąco, a elementy rzeczywiste nierosnąco. Jednocześnie przestawiając elementy całkowite do pierwszej połówki tablicy, a elementy rzeczywiste do drugiej połówki tablicy. Proszę przetestować działanie na tablicy z poprzedniego zadania.

11.  ( 2 ) [Do zadania 9-tego z poprzednich zajęć](vector.c) - utworzoną tablicę proszę posortować według długości wektora (` **qsort**`) i znaleźć wektor o wczytanej długości (` **bsearch**`).

14.  ( 6 ) W zadaniu proszę użyć funkcji **memcpy, memset, memcmp, malloc, free**.  
    Tablica `**tab**` przechowuje stan początkowy automatu komórkowego   "- - - - - - - - - - x- - - - - - - - - - ".  
    Tablica `**tab_p**` to tablica pomocnicza.   "- - - - - - - - - - - - - - - - - - - - - "  
    Proszę zaimplementować poniższą regułę ewolucji automatu komórkowego:  

    Czarne pole w programie oznaczamy znakiem `**'x'**`, a białe pole znakiem `**'-'**`.  
    Reguła z pierwszej ramki ![ak_2](ak_2.PNG) oznacza:  

    Jeżeli w tablicy `**tab**` badane pole jest czarne **'x'** i jeżeli jego sąsiad po lewej stronie jest czarny **'x'** i jeżeli jego sąsiad po prawej stronie jest czarny **'x'** to w tablicy `**tab_p**` odpowiednie pole będzie białe **'  '**.

        int main(void){
        //utwórz tablicę tab i wypełnij "-----------------x----------------"
        //utwórz tablicę tab_p i wypełnij "---------------------------------"
        //wypisz na ekran tablicę tab.
        //Przypisz zmiennej całkowitej roz rozmiar tablicy tab.
        //Przeanalizuj każdy element tablicy tab i na podstawie reguł automatu
        //przypisz wartość odpowiedniemu elementowi tablicy tab_p.
        //Wykorzystaj pętlę for, if-else oraz if-else-if.
        //Skopiuj tablicę tab_p do tablicy tab.
        //wypisz tab.
        //zwolnij pamięć
        return 0;
        }

    *   Proszę dodać pętlę `**(while)**`, która odpowiedzialną za ewolucję czasową i proszępowtórzyć ją 100 razy za każdym razem wyświetlająć wynik na ekran.
    *   Proszę zakończyć pętlę, gdy automat osiagnie stan stabilny.
    *   Proszę zaimplementować periodyczne warunki brzegowe.
