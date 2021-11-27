#include <iostream>
#include "Articulo.h"
#include "Categoria.h"
#include <vector>
#ifndef TIENDA_H
#define TIENDA_H
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;

class Tienda
{
	public:
		Tienda();
		~Tienda();
		void agregarCategoria(Categoria*);
		void agregarArticulo(Articulo*, int);
		void mostrarCategorias();
		void mostrarArticulos();
		void eliminarArticulo(int);
		void estadisticas();
		void busqueda();
	private: 
		vector<Articulo*> articulos;
		vector<Categoria*> categorias;
		vector<Articulo*> temp;
	protected:
};

#endif