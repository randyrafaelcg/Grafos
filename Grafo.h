#pragma once

#ifndef GRAFO_H
#define GRAFO_H
#include"Tripla2.h"
#include<list>
#include<queue>

class Grafo
{
private:
	Tripla2* vec;
	int tam;
	list<int> camino;
public:
	Grafo();
	Grafo(int tam);
	~Grafo();
	void InsertarArista(int v1, int v2);
	void MostrarCamino(int destino);
	Tripla2*& getVec();
	list<int> GuardarCamino(int destino);
	bool BFS(int origen,int destino);//busqueda en amplitud
	bool DFS(int origen, int destino);//busqueda en profundidad
	void BFS_Origen(int origen);
	void LeerDeArch(string archivo);
	void MostrarTodo();
};

#endif
