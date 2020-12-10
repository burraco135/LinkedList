#ifndef _LIBRO_H
#define _LIBRO_H

#include <iostream>
#include <string>

using namespace std;

class Libro {
	public:
		Libro(); // costruttore default
		Libro(string); // costruttore per utente
		void setTitolo(string); // per inserire un titolo
		string getTitolo() const; // per stampare un titolo
		bool operator==(Libro); // sovraccarico == per oggetti Libro
	private:
		string titolo; // ogni oggetto libro ha un titolo
}; // chiudere sempre la classe con il ;

#endif //_LIBRO_H