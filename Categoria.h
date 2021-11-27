#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <iostream>

using std::string;

class Categoria
{
	public:
		Categoria(string);
		~Categoria();
		string getCategoria();
		void setCategoria(string);
		string toString();
	private: 
		string categoria;
	protected:
};

#endif