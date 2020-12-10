#include "libro.h"

Libro::Libro() { titolo = ""; } // costruttore default

Libro::Libro(string t) { setTitolo(t); } // costruttore per utente

void Libro::setTitolo(string t) { titolo = t; }  // per inserire un titolo

string Libro::getTitolo() const { return(titolo); } // per stampare un titolo

bool Libro::operator==(Libro l) {
	return (getTitolo() == l.getTitolo());
} // sovraccarico == (per oggetti Libro)