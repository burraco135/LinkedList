# Lista concatenata con template

[Implementazione del codice su Repl](https://repl.it/@EsterMolinari/LinkedList#main.cpp)

Contenuto del programma:
* **`main.cpp`**
  * Contiene il main
* **`libro.cpp`**
  * Contiene l'implementazione della classe `class Libro`
* **`libro.h`**
  * Contiene la dichiarazione della classe `class Libro` (senza template)
* **`lista.h`**
  * Contiene la dichiarazione e l'implementazione della classe `class Lista`

La classe `class Lista` è implementata mediante l'uso dei **template**.

###### Se dovesse essere presente un file `main`, è stato generato in automatico da Repl ed è un file binario non utile ai fini del funzionamento del programma.

## Nota sull'uso dei template

La scrittura 

`template <class T, int max> Lista<T, max>::Lista() { creaLista(); }`

è equivalente alla seguente (quando si usano le classi senza template)

`Lista::Lista() { creaLista(); }`

Infatti per le funzioni che ritornano dei valori, la scrittura diventa

`template <class T, int max> bool Lista<T, max>::listaVuota() { ... }`

che è equivalente alla seguente (quando si usano le classi senza template)

`bool Lista::listaVuota() { ... }`

## Nota sull'uso della espressione finale `const`
La dicitura `<nome_funzione> () const` viene utilizzata quando non si desidera modificare i dati della struttura in uso.
Nel programma, questa viene usata nei metodi:
* `bool listaVuota const;`
* `tipoelem leggiLista(posizione) const;`
* `posizione primoLista() const;`
* `bool fineLista(posizione) const;`
* `posizione succLista(posizione) const;`
* `posizione predLista(posizione) const;`
* `string getTitolo() const`

## Nota sul sovraccarico degli operatori
In questo programma c'è il sovraccarico dell'operatore `<<` e dell'operatore `==`.
Entrambi si trovano in `libro.h` e servono per la classe `Libro`.
* `std::ostream& operator<<(std::ostream&, const Libro&);`
  * Si occupa di permettere la stampa degli elementi di tipo Libro come se fossero dati normali
    * In questo modo quando viene utilizzato `cout <<` non ci saranno problemi se l'oggetto da stampare ha un tipo definito dall'utente
* `bool operator==(Libro);`
  * Si occupa di permettere il confronto tra due elementi di tipo Libro come se fossero dati normali
    * In questo modo posso utilizzare `==` anche con oggetti di tipo definito dall'utente

In generale, per sovraccaricare un operatore del tipo `<<` si scrive:

`std::ostream& operator<<(std::ostream&, const <nome_classe> <nome_oggetto>);`

Invece, per sovraccaricare un operatore del tipo `==` si scrive:

`bool operator==(<nome_classe> <nome_oggetto>);`

## Operatori della classe `class Libro`
1. Costruttori
    1. Default
        * `Libro()`
    2. Distruttore
        * `~Libro()`
2. `void setTitolo(string)`
    * Inserisce un elemento di tipo stringa nella lista
3. `string getTitolo() const`
    * Restituisce il titolo di un elemento
4. `bool operator==(Libro)`
    * Sovraccarica l'operatore == per permetterne l'output

## Operatori della classe `class Lista`
1. Costruttori
    1. Default
        * `Lista()`
    2. Copia
        * `Lista(const Lista<T, max>&)`
    3. Distruttore
        * `~Lista()`
2. `bool listaVuota()`
    * Se la lista è vuota restituisce 1, altrimenti 0
3. `tipoelem leggiLista(posizione)`
    * Restituisce un elemento di tipo T preso dalla lista
4. `void scriviLista(tipoelem, posizione)`
    * Inserisce un elemento di tipo T nella lista
5. `posizione primoLista()`
    * Restituisce la posizione del primo elemento
6. `bool fineLista(posizione)`
    * Se la posizione inserita è quella finale restituisce 1, altrimenti 0
7. `posizione succLista(posizione) const`
    * Restituisce la posizione successiva a quella inserita
8. `posizione predLista(posizione) const`
    * Restituisce la posizione precedente a quella inserita
9. `void insLista(tipoelem, posizione)`
    * Inserisce un elemento di tipo T in una posizione fornita in input
10. `void cancLista(posizione)`
    * Cancella un elemento in una posizione fornita in input
11. `void stampa()`
    * Stampa in colonna tutti gli elementi della lista

