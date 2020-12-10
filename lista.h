#ifndef _LISTA_H
#define _LISTA_H

#include <iostream>
using namespace std;

// permette di creare oggetti della classe di tipo T (int, double, float, struct)
// il numero massimo di tali oggetti è indicato da max
template <class T, int max> 
class Lista
{
  public:
		typedef T tipoelem; // il tipo di variabile tipoelem viene deciso nel main
    typedef int posizione; // la lista ha come posizione un intero
    
    Lista(); //costruttore
		Lista(const Lista<T, max>&); // costruttore copia
    ~Lista(); //distruttore
    
    // operatori
    void creaLista();
    bool listaVuota() const;
    tipoelem leggiLista(posizione) const;
    void scriviLista(tipoelem, posizione);
    posizione primoLista() const;
    bool fineLista(posizione) const;
    posizione succLista(posizione) const;
    posizione predLista(posizione) const;
    void insLista(tipoelem, posizione);
    void cancLista(posizione);
		void stampa();

  private:
    tipoelem elementi[max]; // elementi è un array di variabili del tipo T
    int lunghezza; // lunghezza della lista
};

// ----- Implementazione della classe Lista | Costruttori/Distruttore ----- //
// costruttore
template <class T, int max> 
Lista<T, max>::Lista() { creaLista(); }

// costruttore copia
template <class T, int max> 
Lista<T,max>::Lista(const Lista<T, max>& l)
{
	lunghezza = l.lunghezza;
	for (int i = 0; i < lunghezza; i++) {
		elementi[i] = l.elementi[i]; // copia gli elementi di una lista in un'altra
	}
}

// distruttore
template <class T, int max> 
Lista<T, max>::~Lista() {}

// ----- Implementazione della classe Lista | Operatori ----- //
template <class T, int max> 
void Lista<T, max>::creaLista() { lunghezza = 0; } // crea una lista vuota

template <class T, int max> 
bool Lista<T, max>::listaVuota() const { return lunghezza == 0; }
// 1 se la lista è vuota, 0 altrimenti

template <class T, int max> 
typename Lista<T,max>::tipoelem Lista<T, max>::leggiLista(posizione p) const {
  if ( (p > 0) && (p < lunghezza + 1)) { // PRE: 0 < p < lunghezza + 1
		return (elementi[p-1]); // restituisce l'elemento letto (se trovato)
	} else {
		return (0); // altrimenti restituisce 0
	}
}

template <class T, int max> 
void Lista<T, max>::scriviLista(tipoelem a, posizione p) {
  if ( (p > 0) && (p < lunghezza + 1) ) { // PRE: 0 < p < lunghezza + 1
    elementi[p-1] = a; // inserisce il valore di a nella lista
  }
}

template <class T, int max> 
typename Lista<T,max>::posizione Lista<T, max>::primoLista() const { return (1); }
// restituisce 1 come posizione iniziale della lista

template <class T, int max>
bool Lista<T, max>::fineLista(posizione p) const {
  if ( (p > 0) && (p < lunghezza + 1) ) {	// PRE: 0 < p < lunghezza + 1
    return (p == lunghezza + 1); // 1 se la lista è finita
  } else {
    return (false); // 0 altrimenti
  }
}

template <class T, int max> 
typename Lista<T,max>::posizione Lista<T, max>::succLista(posizione p) const {
  if ( (p > 0) && (p < lunghezza + 1) ) { // PRE: 0 < p < lunghezza + 1
    return (p + 1); // restituisce la posizione dell'elemento successivo
  } else {
    return (p); // altrimenti se stesso se la lista è di un solo elemento
  }
}

template <class T, int max> 
typename Lista<T,max>::posizione Lista<T, max>::predLista(posizione p) const {
  if ( (p > 1) && (p < lunghezza + 1) ) { // PRE: 1 < p < lunghezza + 1
    return (p - 1); // restituisce la posizione dell'elemento precedente
  } else {
    return (p); // altrimenti se stesso se la lista è di un solo elemento
  }
}

template <class T, int max> 
void Lista<T, max>::insLista(tipoelem a, posizione p) {
  if ( (p > 0) && (p <= lunghezza + 1) ) { // PRE: 0 < p < lunghezza + 1
    for (int i = lunghezza; i >= p; i--) { // inizia dall'ultimo elemento della lista
			elementi[i] = elementi[i-1]; // effettua uno shift a destra
		}

		elementi[p-1] = a; // inserisce l'elemento fornito in input
		lunghezza++; // incrementa la lunghezza della lista di un elemento
  }
}

template <class T, int max> 
void Lista<T, max>::cancLista(posizione p) {
  if ( (p > 0) && (p <= lunghezza + 1) ) { // PRE: 0 < p < lunghezza + 1
    elementi[p-1] = 0; // elimina l'elemento nella posizione fornita in input
      for (int i = p - 1; i < lunghezza + 1; i++) { // a partire dalla posizione fornita
        elementi[p-1] = elementi[p]; // effettua uno shift a sinistra
				elementi[p] = 0; // e cancella l'elemento spostato
      }
      
      lunghezza--; // diminuisce di una unità la lunghezza della lista
  }
}

template <class T, int max>
void Lista<T, max>::stampa() {
	for(int i = 0; i < lunghezza; i++) {
		cout << elementi[i] << endl; // stampa gli elementi della lista come un vettore
	}
}

#endif // _LISTA_H