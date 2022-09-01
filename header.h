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
    NodoDisciplina<T>* disciplinaAluno;
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
void criarListas(ListaAluno<T> &alunos)
{
    alunos.cardinalidade = 0;
    alunos.inicio->proximo = NULL;
    alunos.disciplinaAluno->quantidadeAlunos = 0;
    alunos.disciplinaAluno->proximo = NULL;
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
bool disciplinaExistente(ListaAluno<T> lista, string disc)
{
    ListaAluno<T> p;
    p.inicio = lista.inicio;

    while(p.inicio != NULL)
    {
        if (lista.disciplinaAluno->disciplina == disc)
            return true;
        p.inicio = p.inicio->proximo;
    }
    return false;
}

// ----------------------------- Insere um aluno ----------------------------- //
template<typename T>
void inserirAluno(ListaAluno<T> lista, string nome)
{
    //template<typename T>
    ListaAluno<T> p;

    p = lista;

    while(p.inicio != NULL)
        p.inicio = p.inicio->proximo;

    p.inicio->aluno = nome;
}

// ----------------------------- Insere uma disciplina ----------------------- //
template<typename T>
void inserirDisciplina(ListaAluno<T> &lista, string disc)
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
void excluirDisciplina(ListaAluno<T> &disciplinas, string disciplina)
{
    // Insert code here...
}

// -------------------- Mostra os alunos e as disciplinas -------------------- //
template<typename T>
void mostrarTodos(ListaAluno<T> alunos)
{
    ListaAluno<T> p;

    p = alunos;

    while (p.inicio != NULL)
    {
        cout << p.inicio->aluno << endl;
        p.inicio = p.inicio->proximo;
    }
}

// -------------------- Mostra um aluno e suas disciplinas -------------------- //
template<typename T>
void mostrarUm(ListaAluno<T> alunos, string nome)
{
    // Insert code here...
}

// -------------------------- Destrói lista Alunos -------------------------- //
/*template<typename T>
void destroi(ListaAluno<T> &lista)
{
    ListaAluno<T> p;

    while (lista.inicio != NULL)
    {
        p = lista;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
*/

#endif // HEADER_H_INCLUDED
