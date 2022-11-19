#include "Header.h"

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos{};
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
// llenando los vectores con 0 en todas sus casillas
Conway::Conway()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < H; j++)
		{
			this->arr[i][j] = 0;
			this->aux[i][j] = 0;
		}
	}
}

// muestra la matriz
void Conway::imprimir(int generacio)
{
	gotoxy(1, 1);
	int celulas = 0;

	for (int i = 0; i < N; i++)
	{

		cout << "\n";
		for (int j = 0; j < H; j++)
		{

			if (this->arr[i][j] == viva)
			{

				printf("%c", 02);

				++celulas;

			}
			else
			{

				printf("%c",01); // Aqui se puede agregar la otra cara solo que se ve mejor sin esta cara
			}
		}
	}
	gotoxy(40, 0);

	cout << "Generacion: " << generacio << " vivas: " << celulas << "." << endl;


}
// rellena la matriz a como quiera el usuario
void Conway::rellenar()
{

	int fila{}, columna{};
	int stop = 0;
	int stop1 = 0;
	cout << "digite cuantas celulas quiere que esten vivas" << endl;
	cin >> stop;
	cout << "Matriz de "
		<< "Filas: " << N - 1 << " columnas: " << H - 1 << endl;
	cout << "Digite la posicion de la celula que quiere viva" << endl
		<< endl;


	for (int j = 0; j < stop; j++)
	{
		stop1++;

		cout << "fila: ";
		cin >> fila;
		cout << "columna: ";
		cin >> columna;
		cout << endl;
		this->arr[fila][columna] = 1;
		
	}
	


}

// rellena la matriz aleatoriamente
void Conway::aleatorio()
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < H; j++)
		{

			this->arr[i][j] = rand() % 2;
		}
	}
}

// Analiza las celulas, si deben estar vivas o muertas en la siguiente generacion
void Conway::analisis()
{

	int cellsAlive = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < H; j++)
		{

			cellsAlive = 0;
			// Analizan los vecinos de cada esquina

			if (i == 0 && j == 0)
			{ // evaluacion de la esquina superior izquierda
				if (this->arr[i][j + 1] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j + 1] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j] == 1)
					++cellsAlive;
			}

			if (i == 0 && j == H - 1)
			{ // evaluacion de la esquina superior derecha
				if (this->arr[i][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j] == 1)
					++cellsAlive;
			}

			if (i == N - 1 && j == 0)
			{ // evaluacion de la esquina inferior izquierda
				if (this->arr[i - 1][j] == 1)
					++cellsAlive;
				if (this->arr[i - 1][j + 1] == 1)
					++cellsAlive;
				if (this->arr[i][j + 1] == 1)
					++cellsAlive;
			}

			if (i == N - 1 && j == H - 1)
			{ // evaluacion de la esquina inferior derecha
				if (this->arr[i][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i - 1][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i - 1][j] == 1)
					++cellsAlive;
			}

			// Analizan las filas de los bordes

			if (i == 0 && j != 0 && j != H - 1)
			{ // Analiza la fila superior

				if (this->arr[i][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j + 1] == 1)
					++cellsAlive;
				if (this->arr[i][j + 1] == 1)
					++cellsAlive;
			}

			if (j == 0 && i != N - 1 && i != 0)
			{ // Analiza la fila izquierda

				if (this->arr[i - 1][j] == 1)
					++cellsAlive;
				if (this->arr[i][j + 1] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j + 1] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j] == 1)
					++cellsAlive;
				if (this->arr[i - 1][j + 1] == 1)
					++cellsAlive;
			}

			if (j == H - 1 && i != N - 1 && i != 0)
			{ // Analiza la fila derecha

				if (this->arr[i - 1][j] == 1)
					++cellsAlive;
				if (this->arr[i][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i - 1][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j] == 1)
					++cellsAlive;
				if (this->arr[i + 1][j - 1] == 1)
					++cellsAlive;
			}

			if (i == N - 1 && j != 0 && j != H - 1)
			{ // Analiza la fila inferior

				if (this->arr[i][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i - 1][j - 1] == 1)
					++cellsAlive;
				if (this->arr[i - 1][j] == 1)
					++cellsAlive;
				if (this->arr[i - 1][j + 1] == 1)
					++cellsAlive;
				if (this->arr[i][j + 1] == 1)
					++cellsAlive;
			}

			// Se analizan las restantes
			if (i != 0 && i != N - 1 && j != 0 && j != H - 1)
			{

				if (this->arr[i + 1][j + 1] == 1)
				{
					++cellsAlive;
				}
				if (this->arr[i - 1][j - 1] == 1)
				{
					++cellsAlive;
				}
				if (this->arr[i + 1][j] == 1)
				{
					++cellsAlive;
				}
				if (this->arr[i - 1][j] == 1)
				{
					++cellsAlive;
				}
				if (this->arr[i + 1][j - 1] == 1)
				{
					++cellsAlive;
				}
				if (this->arr[i - 1][j + 1] == 1)
				{
					++cellsAlive;
				}
				if (this->arr[i][j - 1] == 1)
				{
					++cellsAlive;
				}
				if (this->arr[i][j + 1] == 1)
				{
					++cellsAlive;
				}
			}

			// analiza cual celula sobrevive, muere o nace
			if (this->arr[i][j] == viva && cellsAlive == 2)
			{

				this->aux[i][j] = viva;
			}
			if (this->arr[i][j] == viva && cellsAlive == 3)
			{
				this->aux[i][j] = viva;
			}

			if (this->arr[i][j] == muerta && cellsAlive == 3)
			{
				this->aux[i][j] = viva;
			}
			if (this->arr[i][j] == viva && cellsAlive < 2)
			{
				this->aux[i][j] = muerta;
			}
			if (this->arr[i][j] == viva && cellsAlive >= 4)
			{
				this->aux[i][j] = muerta;
			}
		}
	}
}
// aux tiene a la siguiente generacion pero para que esa siguiente generacion se
// evalue y despues se imprima como la anterior se tiene que pasar a arr
void Conway::intercambio()
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < H; j++)
		{
			this->arr[i][j] = this->aux[i][j];
		}
	}
}
// reinicia los valores de la matriz en 0
void Conway::reinicio() {

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < H; j++)
		{
			this->arr[i][j] = 0;
			this->aux[i][j] = 0;
		}
	}




}








