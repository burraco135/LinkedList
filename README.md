# Lista concatenata con template

Contiene le seguenti classi:
* **Libro**
  * Oggetto che ha un titolo
* **Lista**
  * Oggetto vettore di elementi di tipo T con posizione

La classe Lista è implementata mediante l'uso dei **template**.

### Nota sull'uso dei template

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

## Operatori della classe Lista
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

