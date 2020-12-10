#ifndef _LISTA_H
#define _LISTA_H

using namespace std;

// permette di creare oggetti della classe di tipo T (int, double, float, struct)
// il numero massimo di tali oggetti è indicato da max
template <class T, int max> 
class Lista
{
  public:
    typedef int posizione;
    typedef T tipoelem; // il tipo di variabile tipoelem viene deciso nel main
    
    Lista(); //costruttore
    Lista(const Lista<T, max>&); //costruttore di copia
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
    T elementi[max]; // elementi è un array di variabili del tipo T
    int lunghezza; // lunghezza della lista
};

// ----- Implementazione della classe Lista ----- //
// costruttore
template<class T, int max> 
Lista<T, max>::Lista() { creaLista(); }
// costruttore di copia
template<class T, int max> 
Lista<T, max>::Lista(const Lista<T, max>& l) {
  lunghezza = l.lunghezza;
  for (int i = 0; i < lunghezza + 1; i++) {
    elementi[i] = l.elementi[i];
  }
}
// distruttore
template<class T, int max> 
Lista<T, max>::~Lista() {}

// operatori
template<class T, int max> 
void Lista<T, max>::creaLista() { lunghezza = 0; } // crea una lista vuota

template<class T, int max> 
bool Lista<T, max>::listaVuota() const { return lunghezza == 0; }
// 1 se la lista è vuota, 0 altrimenti

template<class T, int max> 
T Lista<T, max>::leggiLista(posizione p) const {
  if ( (p > 0) && (p < lunghezza + 1) ) {
    return (elementi[p-1]);
  }
}

template<class T, int max> 
void Lista<T, max>::scriviLista(tipoelem a, posizione p) {
  if ( (p > 0) && (p < lunghezza + 1) ) {
    elementi[p-1] = a;
  }
}

template<class T, int max> 
int Lista<T, max>::primoLista() const { return (1); }

template<class T, int max> bool Lista<T, max>::fineLista(posizione p) const {
  if ( (p > 0) && (p < lunghezza + 1) ) {
    return (p == lunghezza + 1);
  } else {
    return (false);
  }
}

template<class T, int max> 
int Lista<T, max>::succLista(posizione p) const {
  if ( (p > 0) && (p < lunghezza + 1) ) {
    return (p + 1);
  } else {
    return (p);
  }
}

template<class T, int max> 
int Lista<T, max>::predLista(posizione p) const {
  if ( (p > 0) && (p < lunghezza + 1) ) {
    return (p - 1);
  } else {
    return (p);
  }
}

template<class T, int max> 
void Lista<T, max>::insLista(tipoelem a, posizione p) {
  if ( (p > 0) && (p < lunghezza + 1) ) {
    for (int i = lunghezza; i >= p; i--) {
      elementi[i] = elementi[i-1];
    }
    
    elementi[p-1] = a;
    lunghezza++;
  }
}

template<class T, int max> 
void Lista<T, max>::cancLista(posizione p) {
  if ( (p > 0) && (p < lunghezza + 1) ) {
    if ( !listaVuota() ) {
      for (int i = p - 1; i < lunghezza + 1; i++) {
        elementi[i] = elementi[i+1];
      }
      
      lunghezza--;
    }
  }
}



#endif // _LISTA_H