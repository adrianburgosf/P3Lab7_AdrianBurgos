#include <iostream>
#include "Tienda.h"
#include "Categoria.h"
#include "Articulo.h"
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//TALLA EN MAYUSCULA PLS :)

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

int menu();

int main(int argc, char** argv) {
	Tienda* tienda = new Tienda();
	
	int opcion = menu();
	while (opcion != 5) {
		switch (opcion) {
			case 1: {
				string categoria = "";
				cout << "Ingrese el nombre de la categoria que desea agregar: ";
				cin >> categoria;
				tienda->agregarCategoria(new Categoria(categoria));
				break;
			}
			case 2: {
				int subopcion = 0;
				cout <<"=========Sub-Menu=========" << endl
				     << "1) Agregar Articulo" << endl
				     << "2) Modificar Articulo" << endl
				     << "3) Eliminar Articulo"<< endl
				     << "4) Listar Articulos"<< endl;
				cout << "Ingrese la opcion: ";
				cin >> subopcion;
				cout << endl;
				switch (subopcion) {
					case 1: {
						string nombre;
						vector<char> tallas;
						double precio;
						int cantidad;
						int descuento;
						int index;
						//Agregar articulo
						cout << "Ingrese nombre de articulo: ";
						cin >> nombre;
						char flag = 'S';
						char talla;
						while (flag == 's' || flag == 'S') {
							cout << "Ingrese talla: ";
							cin >> talla;
							tallas.push_back(talla);
							cout << "Desea agregar otra talla [S/N]: ";
							cin >> flag;
						}
						cout << "Ingrese el precio: ";
						cin >> precio;
						cout << "Ingrese cantidad: ";
						cin >> cantidad;
						cout << "Ingrese descuento: ";
						cin >> descuento;
						tienda->mostrarCategorias();
						cout << "Ingrese el index de la categoria de su articulo: ";
						cin >> index;
						tienda->agregarArticulo(new Articulo(nombre, tallas, precio, cantidad, descuento), index);
						break;
					}
					case 2: {
						
						break;
					}
					case 3: {
						int index = 0;
						tienda->mostrarArticulos();
						cout << "Seleccione que articulo desea eliminar: ";
						cin >> index;
						tienda->eliminarArticulo(index);
						break;
					}
					case 4: {
						tienda->mostrarArticulos();
						break;
					}
					default:
						cout << "Opcion no valida";
				}
				break;
			}
			case 3: {
				tienda->estadisticas();
				break;
			}
			case 4: {
				tienda->busqueda();
				break;
			}
			case 5: {
				break;
			}
			default:
				cout << "Opcion no valida";
		}
		opcion = menu();
	}
	delete tienda;
	return 0;
}

int menu() {
	int opcion = 0;
	cout << endl << "===========Menu===========" << endl
	     << "1) Agregar Categorias" << endl
	     << "2) Mantenimiento de Articulos" << endl
	     << "3) Estadisticas Generales"<< endl
	     << "4) Busqueda por categoria y talla" << endl
	     << "5) Salir" << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	cout << endl;
	return opcion;
}