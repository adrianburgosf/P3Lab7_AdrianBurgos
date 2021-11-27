#include "Tienda.h"

Tienda::Tienda() {
}

void Tienda::agregarCategoria(Categoria* categoria) {
	this->categorias.push_back(categoria);
}

void Tienda::agregarArticulo(Articulo* articulo, int categ) {
	articulo->setCategoria(categorias[categ]);
	this->articulos.push_back(articulo);
}

void Tienda::mostrarCategorias() {
	cout << "===Categorias===" << endl;
	for (int i = 0; i < categorias.size(); i++) {
		cout << i << ") " << categorias[i]->toString() << endl;
	}
}

void Tienda::mostrarArticulos() {
	cout << "===Articulos===" << endl;
	for (int i = 0; i < articulos.size(); i++) {
		cout << i << ") " << articulos[i]->toString() << endl;
	}
}

void Tienda::eliminarArticulo(int index) {
    articulos.erase(articulos.begin()+index);
}

void Tienda::estadisticas() {
	
	int precioTienda = 0;
	int totalUnidadesTienda = 0;
	int totalProdUnicos = articulos.size();
	
	for (int i = 0; i < this->categorias.size(); i++) {
		int totalUnidades = 0;
		double precioTotal = 0;
		cout << categorias[i]->toString() << ":" << endl;
		for (int j = 0; j < this->articulos.size(); j++) {
			if (categorias[i]->toString().compare(articulos[j]->getCategoria()) == 0) {
				cout << " - " << articulos[j]->toString() << endl;
				totalUnidades += articulos[j]->getCantidad();
				precioTotal += articulos[j]->getPrecio();
				totalUnidadesTienda += articulos[j]->getCantidad();
				precioTienda += articulos[j]->getPrecio();
			}
		}
		cout << " - Total de unidades en la categoria: " << totalUnidades << endl;
		cout << " - Precio total de la categoria: " << precioTotal << endl << endl;
	}
	cout << "Total de unidades en la Tienda: " << totalUnidadesTienda << endl;
	cout << "Precio total de la tienda: " << precioTienda << endl;
}

void Tienda::busqueda() {
	char filtroC;
	char filtroT;
	
	cout << "Desea filtrar categorias?[S/N]: ";
	cin >> filtroC;
	
	if (filtroC == 'S' || filtroC == 's') {
		int index = 0;
		string categoria = "";
		mostrarCategorias();
		cout << "Ingrese el index de la categoria: ";
		cin >> index;
		categoria = this->categorias[index]->toString();
		for (int i = 0; i < articulos.size(); i++) {
			if (articulos[i]->getCategoria().compare(categoria) == 0) {
				this->temp.push_back(articulos[i]);
			}
		}
	}
	else {
		this->temp = this->articulos;
	}
	
	cout << "Desea filtrar tallas?[S/N]: ";
	cin >> filtroT;
	
	if (filtroT == 'S' || filtroT == 's') {
		char talla;
		cout << "Ingrese la talla: ";
		cin >> talla;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i]->verTalla(talla)) {
				cout << temp[i]->toString();
			}
		}
	}
}

Tienda::~Tienda() {
	for(int i = 0; i < articulos.size();i++){
        delete articulos[i];
    }
    for(int i = 0 ; i < categorias.size() ; i++){
        delete categorias[i];
    }
    for(int i = 0 ; i < temp.size() ; i++){
        delete temp[i];
    }
}