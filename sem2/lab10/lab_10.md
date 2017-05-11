# Programowanie proceduralne

## Laboratorium 10

* * *

* * *


## Zadania

</div>

1.  Proszę utworzyć strukturę `**struct xyz**`, która ma dwa pola: znak oraz wskaźnik do struktury `**struct xyz**`.  
    Prosze utworzyć 3 zmienne `**a, b, c**` typu `**struct xyz**`.
    *   Niech pole wskaźnikowe zmiennej `**a**` wskazuje na `**b**`, pole wskaźnikowe zmiennej `**b**` wskazuje na `**c**`, a pole wskaźnikowe zmiennej `**c**` wskazuje na `**a**`.
    *   Korzystając ze zmiennej `**a**` i odpowiednich pól proszę nadać wartość pola znakowego zmiennych `**a, b, c**`.
    *   Korzystając ze zmiennej `**b**` i odpowiednich pól proszę wypisać pole znak zmiennych `**a, b, c**`.
    *   Korzystając ze zmiennej `**c**` i odpowiednich pól proszę zamienić małą literę na dużą w polu znak zmiennych `**a, b, c**`.

5.  Dana jest struktura

    <pre>struct tnode {
    char value;
    struct tnode * next;
    };</pre>

    1.  Proszę napisać funkcję, która dodaje element na początek listy jednokierunkowej.

        <pre> ? dodaj_na_poczatek (?,int val){ // alokacja pamięci na jeden element listy
          // uzupełnij obydwa pola utworzonego elementu
          //jezeli lista jest pusta to dodaj element do pustej listy
          // jesli nie jest pusta dodaj element na początek listy
          // pamiętaj o zachowaniu ciągłości pomiędzy kolejnymi elementami
         };</pre>

    2.  Proszę napisać funkcję, która wypisze listę na ekran.
    3.  W funkcji` **mian()**` utwórz wskaźnik do początku listy `**head = NULL**`. Proszę wykorzystać funkcję `**dodaj_na_poczatek**`, aby dodać do pustej listy elementy: 'a', 'c', 'v', 'f', 't'.  
        Wypisz listę na ekran.  

6.  Proszę napisać funkcję, która zwolni pamięć zajmowaną przez listę.

9.  Proszę napisać <u>procedurę</u> `**dodaj_na_koniec**`, która dodaje element na koniec listy. Wykorzystaj ją , aby dodać do pustej listy elementy: 'h', 'l', 'o', 'r', 'w'.  
    Wypisz listę na ekran.

    <pre>void dodaj_na_koniec(?, int val){ // alokacja pamięci na jeden element listy
    // uzupełnij obydwa pola utworzonego elementu
    // jezeli lista jest pusta to dodaj element do pustej listy
    //w przeciwnym razie dodaj element na koniec niepustej listy
     };</pre>

10.  Proszę napisać funkcję, która odwraca listę jednokierunkową.

    <pre>Przed: head -> ['f']-> ['d'] -> ['u'] -> ['i'] -> NULL
    Po: head -> ['i'] -> ['u'] -> ['d'] -> ['f'] -> NULL
    </pre>

11.  Proszę napisać funkcję, która dodaje elementy do listy posortowanej rosnąco.
