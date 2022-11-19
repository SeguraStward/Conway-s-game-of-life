#include <iostream>
#include <stdlib.h> 
#include <Windows.h>
#include <conio.h>

#define viva  1
#define muerta 0
#define N 7//filas
#define H 40 //columnas
//para volver al menu cuando se estan mostrando las celulas apretar boton tecla s
using namespace std;

class Conway {
	int arr[N][H];
	int aux[N][H];
public:
	Conway();
	void aleatorio();
	void rellenar();
	void imprimir(int generacion);
	void analisis();
	void intercambio();
	void reinicio();
	
}; 
