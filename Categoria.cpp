#include "Categoria.h"

Categoria::Categoria(string catego) {
	this->categoria = catego;
}

string Categoria::toString() {
	return this->categoria;
}

Categoria::~Categoria()
{
}