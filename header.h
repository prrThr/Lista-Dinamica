#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;

template<typename T>
struct nodo1
{
    T aluno;
    struct nodo1* proximo;
};

template<typename T>
struct nodo2
{
    T disciplina;
    int quantidadeAlunos;
    struct nodo2* proximo;
};

template<typename T>
using NodoAluno = struct nodo1<T>;

template<typename T>
using NodoDisciplina = struct nodo2<T>;

// ----------------------------------------------------------------------------- //

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

template<typename T>
using ListaDisciplina = struct listaDisciplina<T>;

// ------------------------- Verifica se lista vazia ------------------------- //
template<typename T>
bool verificarSeListaVazia(ListaAluno<T> alunos)
{
    if (alunos.cardinalidade == 0)
        return true;
    else
        return false;
}

// --------------------------- Cria as duas listas --------------------------- //
template<typename T>
void criarListas(ListaAluno<T> &alunos, ListaDisciplina<T> &disciplinas)
{
    alunos.cardinalidade = 0;
    alunos.inicio = NULL;
    disciplinas.cardinalidade = 0;
    disciplinas.inicio = NULL;
}

// ----------------------- Verifica se o aluno existe ----------------------- //
template<typename T>
bool alunoExistente(ListaAluno<T> alunos, string nome)
{
    // Insert code here...
}

// ----------------------------- Insere um aluno ----------------------------- //
template<typename T>
void inserirAluno(ListaAluno<T> &alunos, string nome)
{
    // Insert code here...
}

// --------------------- Verifica se a disciplina existe --------------------- //
template<typename T>
bool disciplinaExistente(ListaAluno<T> alunos)
{
    // Insert code here...
}

// ----------------------------- Exclui um aluno ----------------------------- //
template<typename T>
void excluirAluno(ListaAluno<T> &alunos, string nome)
{
    // Insert code here...
}

// -------------------------- Exclui uma disciplina -------------------------- //
template<typename T>
void excluirDisciplina(ListaDisciplina<T> &disciplinas, string disciplina)
{
    // Insert code here...
}

// -------------------- Mostra os alunos e as disciplinas -------------------- //
template<typename T>
mostrarTodos(ListaAluno<T> alunos, ListaDisciplina<T> disciplinas)
{
    // Insert code here...
}

// -------------------- Mostra um aluno e suas disciplinas -------------------- //
template<typename T>
mostrarUm(ListaAluno<T> alunos, ListaDisciplina<T> disciplinas, string nome)
{
    // Insert code here...
}

// -------------------------- Destrói as duas listas -------------------------- //
template<typename T>
void destroi(Lista???<T> &lista)
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
