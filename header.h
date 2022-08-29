#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;

template<typename T>
struct nodo1
{
    T aluno;
    struct nodo* proximo;
};

template<typename T>
struct nodo2
{
    T disciplina;
    int quantidadeAlunos;
    struct nodo* proximo;
};

template<typename T>
using NodoAluno = struct nodo1<T>;

template<typename T>
using NodoDisciplina = struct nodo2<T>;


template<typename T>
struct listaAluno
{
    int cardinalidade;
    NodoAluno<T>* inicio;
};

template<typename T>
struct listaDisciplina
{
    int cardinalidade;
    NodoDisciplina<T>* inicio;
};


template<typename T>
using ListaAluno = struct listaAluno<T>;
using ListaDisciplina = struct listaDisciplina<T>;

// ---------------------------------------------------------------------//

template<typename T>
void verificarSeListaVazia(ListaAluno<T> alunos)
{
    if (alunos.cardinalidade == 0)
        return true;
    else
        return false;
}

template<typename T>
void inserirAluno(ListaAluno<T> &alunos)
{

}

template<typename T>
void criarListas(ListaAluno<T> &alunos, ListaDisciplina<T> &disciplinas)
{
    alunos.cardinalidade = 0;
    alunos.inicio = NULL;
    disciplinas.cardinalidade = 0;
    disciplinas.inicio = NULL;
}


template<typename T>
void destroi(ListaSimplesmenteEncadeada<T> &lista)
{
    Nodo<T> *p;
    while (lista.inicio != NULL)
    {
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}

#endif // HEADER_H_INCLUDED
