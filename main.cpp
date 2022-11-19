#include "Header.h"
//Ángel Stward segura Méndez


int main() {

		int stop = 0;
		int opcion = 0;
		string tecla = "";
	Conway a;
	
	while (opcion != 3) {
		cout << "\tMenu" << endl << endl;
		cout << "1-matriz aleatoria" <<endl;
		cout << "2-matriz definida" <<endl;
		cout << "3-salir" << endl;
		cin >> opcion;
		if (opcion == 1) {
			a.aleatorio();
			system("cls");
		}
		if (opcion == 2) {
			a.rellenar();
			system("cls");
		}
		if (opcion == 3) {
			break;
		}
	
		while (stop < 1000) {
			stop++;
	
			if (_kbhit()) {
				tecla = _getch();
				if (tecla == "s")break;//en este compilador ese break solo funciona con matriz definida, con aleatorio se sale de todo el programa
			}
	
			a.imprimir(stop);
			a.analisis();
			a.intercambio();
	
			Sleep(1000);
	
		}
		
		stop = 0;
		a.reinicio();
		system("cls");
	}



	
	return 0;
};