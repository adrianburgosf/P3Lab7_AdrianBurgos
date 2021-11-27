#include "Articulo.h"

Articulo::Articulo(string nombre, vector<char> tallas, double precio, int cantidad, int descuento) {
	this->nombre = nombre;
	this->tallas = tallas;
	this->precio = precio;
	this->cantidad = cantidad;
	this->descuento = descuento;
}

void Articulo::setCategoria(Categoria* categ) {
	this->categoria = categ;
}

string Articulo::toString() {
	string articulo = "[Nombres: ";
	articulo += this->nombre+", Tallas: (";
	for (int i = 0; i < this->tallas.size(); i++) {
		articulo += this->tallas[i];
		if (i != this->tallas.size()-1) {
			articulo += ", ";
		}
	}
	articulo += "), Precio: "+ to_string(this->precio)+", ";
	articulo += "Cantidad: "+ to_string(this->cantidad)+", ";
	articulo += "Descuento: "+ to_string(this->descuento)+ ", ";
	articulo += "Categoria: "+ this->categoria->toString()+"]";
	return articulo;
}

string Articulo::getCategoria() {
	return categoria->toString();
}

int Articulo::getCantidad() {
	return this->cantidad;
}

double Articulo::getPrecio() {
	return this->precio;
}

bool Articulo::verTalla(char talla) {
	for (int i = 0; i < tallas.size(); i++) {
		if (tallas[i] == talla) {
			return true;
		}
	}
	return false;
}

Articulo::~Articulo() {
	delete[] categoria;
}