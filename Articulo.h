#include <iostream>
#ifndef ARTICULO_H
#define ARTICULO_H
#include "Categoria.h"
#include <vector>

using std::string;
using std::vector;
using std::to_string;

class Articulo
{
	public:
		Articulo(string, vector<char>, double, int, int);
		~Articulo();
		void setNombre(string);
        string getNombre();
        void setPrecio(double);
        double getPrecio();
        void setCantidad(int);
        int getCantidad();
        void setDescuento(int);
        int getDescuento();
        void setCategoria(Categoria*);
        string getCategoria();
        string toString();
        bool verTalla(char);
	private: 
		string nombre;
		vector<char> tallas;
		double precio;
		int cantidad;
		int descuento;
		Categoria* categoria;
	protected:
};

#endif