#include <iostream>
#include "libro.h"
#include "lista.h"

using namespace std;

int main() {
	Lista<Libro,10> lista_libro;
	

	Lista<Libro, 10>::posizione indice_libro = lista_libro.primoLista();
	Libro libro;
	
	libro.setTitolo("Libro 1");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
	libro.setTitolo("Libro 2");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
	libro.setTitolo("Libro 3");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
	libro.setTitolo("Libro 4");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
	libro.setTitolo("Libro 5");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
	libro.setTitolo("Libro 6");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
	// stampa lista libro (il template non funziona)
	lista_libro.stampa();

	/*
	cout <<"\nInserimento nuovo elemento in seconda posizione...\n";
	libro.setTitolo("Libro inserito!");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(lista_libro.primoLista()));
	// stampa lista libro (il template non funziona)
	lista_libro.stampaLista();

	cout << "Lista di interi: " << endl;
	
	Lista<int, 5> lista_interi;
	Lista<int, 5>::posizione indice_interi = lista_interi.primoLista();
	lista_interi.insLista(10, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(1, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(5, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(5, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(1, indice_interi = lista_interi.succLista(indice_interi));
	// stampa lista interi (il template non funziona)
	lista_interi.stampaLista();
	*/

	return 0;
}