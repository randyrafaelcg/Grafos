#include "Grafo.h"

Grafo::Grafo()
{
}

Grafo::Grafo(int tam)
{
	this->tam = tam;
	vec = new Tripla2[tam];
}

Grafo::~Grafo()
{

}

void Grafo::InsertarArista(int v1, int v2)
{
	vec[v1].getLista8().insertar_final(v2);
}

void Grafo::MostrarCamino(int destino)
{
	GuardarCamino(destino);
	for (int elem : camino)
	{
		cout << elem << " ";
	}
	cout << endl << endl;
	camino.clear();
}

Tripla2*& Grafo::getVec()
{
	return vec;
}

list<int> Grafo::GuardarCamino(int destino)
{
	if (vec[destino].getPadre() == -1)
	{
		camino.push_back(destino);
		return camino;
	}
	else
	{
		camino = GuardarCamino(vec[destino].getPadre());
		camino.push_back(destino);
	}
	return camino;
}

bool Grafo::BFS(int origen, int destino)
{
	bool encontre = false;
	queue<int> cola;
	int i_esimo;
	int vert;
	int adya;
	cola.push(origen);
	vec[origen].setMarca(true);
	while (!cola.empty() && encontre==false)
	{
		i_esimo = 1;
		vert = cola.front();
		cola.pop();
		adya = vec[vert].getLista8().getElemPos(i_esimo);
		while (adya!=-1 && encontre==false)
		{
			if (vec[adya].getMarca() == false)
			{
				vec[adya].setPadre(vert);
				if (adya==destino)
					encontre = true;
				else
				{
					vec[adya].setMarca(true);
					cola.push(adya);
				}
			}
			i_esimo++;
			adya = vec[vert].getLista8().getElemPos(i_esimo);
		}
	}
	return encontre;
}

bool Grafo::DFS(int origen, int destino)
{
	int i_esimo = 1;
	int adya=-1;
	bool encontre = false;
	vec[origen].setMarca(true);
	adya = vec[origen].getLista8().getElemPos(i_esimo);
	while (adya!=-1)
	{
		if (!encontre && !vec[adya].getMarca())
		{
			vec[adya].setPadre(origen);
			if (adya == destino)
				encontre = true;
			else
				encontre = DFS(adya, destino);
		}
		i_esimo++;
		adya = vec[origen].getLista8().getElemPos(i_esimo);
	}
	return encontre;
}

void Grafo::BFS_Origen(int origen)
{
	queue<int> cola;
	int i_esimo;
	int vert;
	int adya;
	cola.push(origen);
	vec[origen].setMarca(true);
	while (!cola.empty())
	{
		i_esimo = 1;
		vert = cola.front();
		//cout << vert << " ";
		cola.pop();
		adya = vec[vert].getLista8().getElemPos(i_esimo);
		while (adya != -1)
		{
			if (vec[adya].getMarca() == false)
			{
				vec[adya].setPadre(vert);
				vec[adya].setMarca(true);
				cola.push(adya);
				
			}
			i_esimo++;
			adya = vec[vert].getLista8().getElemPos(i_esimo);
		}
	}
}

void Grafo::LeerDeArch(string Archivo)
{
	ifstream archivo(Archivo);
	string linea, v1, v2;
	char delimitador = ',';
	//getline(archivo, linea);
	while (getline(archivo, linea))
	{
		stringstream stream(linea);
		getline(stream, v1, delimitador);
		getline(stream, v2, delimitador);
		InsertarArista(stoi(v1), stoi(v2));
	}
	cout << "ARCHIVO LEIDO CORRECTAMENTE" << endl;
}

void Grafo::MostrarTodo()
{
	for (int i = 0; i < tam; i++)
	{
		cout << i << " ";
		vec[i].getLista8().mostrar();
		cout << endl;
	}
}
