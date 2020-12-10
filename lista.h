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
    typedef int posizione;  
    
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

// ----- Implementazione della classe Lista ----- //
// costruttore
template <class T, int max> 
Lista<T, max>::Lista() { creaLista(); }

// costruttore copia
template <class T, int max> 
Lista<T,max>::Lista(const Lista<T,max>& l)
{
	lunghezza = l.lunghezza;
	for (int i = 0; i < lunghezza; i++) {
		elementi[i] = l.elementi[i];
	}
}

// distruttore
template <class T, int max> 
Lista<T, max>::~Lista() {}

// operatori
template <class T, int max> 
void Lista<T, max>::creaLista() { lunghezza = 0; } // crea una lista vuota

template <class T, int max> 
bool Lista<T, max>::listaVuota() const { return lunghezza == 0; }
// 1 se la lista è vuota, 0 altrimenti

template <class T, int max> 
typename Lista<T,max>::tipoelem Lista<T, max>::leggiLista(posizione p) const {
  if ( (0 < p) && (p < lunghezza + 1)) { // precondizione
		return(elementi[p-1]);
	} else {
		return(0); //qui ci dovrebbe essere un eccezione al post dell'if
	}
}

template <class T, int max> 
void Lista<T, max>::scriviLista(tipoelem a, posizione p) {
  if ( (0 < p) && (p <= lunghezza) ) {
    elementi[p-1] = a;
  }
}

template <class T, int max> 
typename Lista<T,max>::posizione Lista<T, max>::primoLista() const { return (1); }

template <class T, int max>
bool Lista<T, max>::fineLista(posizione p) const {
  if ( (p > 0) && (p < lunghezza + 1) ) {
    return (p == lunghezza + 1);
  } else {
    return (false);
  }
}

template <class T, int max> 
typename Lista<T,max>::posizione Lista<T, max>::succLista(posizione p) const {
  if ( (0 < p) && (p <= lunghezza) ) {
    return (p + 1);
  } else {
    return (p);
  }
}

template <class T, int max> 
typename Lista<T,max>::posizione Lista<T, max>::predLista(posizione p) const {
  if ( (1 < p) && (p <= lunghezza) ) {
    return (p - 1);
  } else {
    return (p);
  }
}

template <class T, int max> 
void Lista<T, max>::insLista(tipoelem a, posizione p) {
  if ( (0 < p) && (p <= lunghezza + 1) ) {
    for (int i = lunghezza; i >= p; i--) {
			elementi[i] = elementi[i-1];
		}

		elementi[p-1] = a;
		lunghezza++;
  }
}

template <class T, int max> 
void Lista<T, max>::cancLista(posizione p) {
  if ( (p > 0) && (p <= lunghezza + 1) ) {
    elementi[p-1] = 0;
      for (int i = p - 1; i < lunghezza + 1; i++) {
        elementi[p-1] = elementi[p];
				elementi[p] = 0;
      }
      
      lunghezza--;
  }
}

template <class T, int max>
void Lista<T,max>::stampa(){
	for(int i = 0; i < lunghezza; i++){
		cout << elementi[i] << endl;
	}
}

#endif // _LISTA_H