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

template<typename T>
struct ListaAluno
{
    int cardinalidade;
    NodoAluno<T>* inicio;
    //NodoDisciplina<T> *disciplina ?? pq do jeito que estamos fazendo não esta sendo uma lista dentro da outra
};

template<typename T>
struct ListaDisciplina
{
    int cardinalidade;
    NodoDisciplina<T>* inicio;
};

//template<typename T>
//using ListaAluno = struct listaAluno<T>;
//template<typename T>
//using ListaDisciplina = struct listaDisciplina<T>;

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
bool alunoExistente(ListaAluno<T> lista, string nome)
{
    ListaAluno<T> p;
    p.inicio = lista.inicio;

    while(p.inicio != NULL)
    {
        if (lista.inicio->aluno == nome)
            return true;
        p.inicio = p.inicio->proximo;
    }
    return false;
}

// --------------------- Verifica se a disciplina existe --------------------- //
template<typename T>
bool disciplinaExistente(ListaDisciplina<T> lista, string disc)
{
    ListaDisciplina<T> p;
    p.inicio = lista.inicio;

    while(p.inicio != NULL)
    {
        if (lista.inicio->disciplina == disc)
            return true;
        p.inicio = p.inicio->proximo;
    }
    return false;
}

// ----------------------------- Insere um aluno ----------------------------- //
template<typename T>
void inserirAluno(ListaAluno<T> &lista, string nome)
{
    // Insert code here...
}

// ----------------------------- Insere uma disciplina ----------------------- //
template<typename T>
void inserirDisciplina(ListaDisciplina<T> &lista, string disc)
{
    // Insert code here...
}

// ----------------------------- Exclui um aluno ----------------------------- //
template<typename T>
void excluirAluno(ListaAluno<T> &lista, string nome)
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
void mostrarTodos(ListaAluno<T> alunos, ListaDisciplina<T> disciplinas)
{
    // Insert code here...
}

// -------------------- Mostra um aluno e suas disciplinas -------------------- //
template<typename T>
void mostrarUm(ListaAluno<T> alunos, ListaDisciplina<T> disciplinas, string nome)
{
    // Insert code here...
}

// -------------------------- Destrói lista Alunos -------------------------- //
template<typename T>
void destroiAlunos(ListaAluno<T> &lista)
{
    ListaAluno<T> p;
    while (lista.inicio != NULL)
    {
        p.inicio = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p.inicio;
    }
    lista.cardinalidade = 0;
}

// -------------------------- Destrói lista Disciplinas -------------------------- //
template<typename T>
void destroiDisciplinas(ListaDisciplina<T> &lista)
{
    ListaDisciplina<T> p;
    while (lista.inicio != NULL)
    {
        p.inicio = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p.inicio;
    }
    lista.cardinalidade = 0;
}
#endif // HEADER_H_INCLUDED
