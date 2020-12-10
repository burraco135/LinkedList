#include "funzioni.h"
#include "lista.h"
#include <iostream>

using namespace std;

void stampaLista(Lista &l) {
	cout << "[";
	Lista::posizione pos;
	for (pos = l.primoLista(); !l.fineLista(pos); pos = l.succLista(pos)) {
		cout << l.leggiLista(pos);
		if (!l.fineLista(l.succLista(pos))) {
			cout << ", ";
		}
	}
	cout << "]\n";
}

void epurazioneLista(Lista &l) {
	Lista::posizione p, q, r;

	p = l.primoLista();
	while (!l.fineLista(p)) {
		q = l.succLista(p);
		while (!l.fineLista(q)) {
			if (l.leggiLista(p) == l.leggiLista(q)) {
				r = l.succLista(q);
				l.cancLista(q);
				q = r;
			} else {
				q = l.succLista(q);
			}
			p = l.succLista(p);
		}
	}
}