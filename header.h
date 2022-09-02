#ifndef HESF_H_INCLUDED
#define HESF_H_INCLUDED
#include <iostream>
using namespace std;

template<typename T>
struct NodoDisciplina
{
    T disciplina;
    int cardinalidade;
    int quantidadeAlunos;
    struct NodoDisciplina *proximo;
};

template<typename T>
struct NodoAluno
{
    T aluno;
    NodoDisciplina<T> *disciplinas;
    struct NodoAluno *proximo;
};

template<typename T>
struct Lista
{
    int cardinalidade;
    NodoAluno<T>* inicioA;
};

/*template<typename T>
struct ListaDisciplina
{
    int cardinalidade;
    NodoDisciplina<T>* inicioA;
};*/

// --------------------------- Cria as duas listas --------------------------- //
template<typename T>
void criarListas(Lista<T> &alunos)
{
    alunos.cardinalidade = 0;
    alunos.inicioA->proximo = NULL;
    alunos.inicioA->disciplinas->quantidadeAlunos = 0;
    alunos.inicioA->disciplinas->cardinalidade = 0;
    alunos.inicioA->disciplinas->proximo = NULL;
}

// -------------------------- Destrói lista Alunos --------------------------- //
template<typename T>
void destroi(Lista<T> &lista)
{
    Lista<T> p;
    while (lista.inicioA != NULL)
    {
        p = lista;
        lista.inicioA = lista.inicioA->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}
// ------------------------- Verifica se lista vazia ------------------------- //
template<typename T>
bool verificarSeListaVazia(Lista<T> alunos)
{
    if (alunos.cardinalidade == 0)
        return true;
    else
        return false;
}

// ----------------------- Verifica o numero de alunos da lista -------------- //


// ----------------------- Verifica o numero de disciplinas de um aluno ------ //


// ----------------------- Verifica se o aluno existe ------------------------ //
template<typename T>
bool alunoExistente(Lista<T> lista, T nome)
{
    NodoAluno<T> *p = lista.inicioA;

    while(p != NULL)
    {
        if (lista.inicioA->aluno == nome)
            return true;
        p = p->proximo;
    }
    return false;
}

// --------------------- Verifica se a disciplina de um aluno existe --------- //
template<typename T>
bool disciplinaExistente(Lista<T> lista, T disc, T nome)
{
    NodoAluno<T> *p;
    p = lista.inicioA;

    while(p != NULL)
    {
        if (lista.inicioD->disciplina == disc)
            return true;
        p = p->proximo;
    }
    return false;
}

// ----------------------------- Insere um aluno ----------------------------- //
template<typename T>
void inserirAluno(Lista<T> &lista, string nome)
{
    NodoAluno<T> *p = new NodoAluno<T>;
    NodoAluno<T> *p_aux = lista.inicioA;
    p->aluno = nome;

    while(p_aux != NULL)
        p_aux = p_aux->proximo;
    p_aux->aluno = p->aluno;
    p_aux->proximo = NULL;
}

// ----------------------------- Insere uma disciplina de um aluno ----------- //
template<typename T>
void inserirDisciplina(Lista<T> &lista, string disc)
{
    // Insert code here...
}

// ----------------------------- Exclui um aluno ----------------------------- //
template<typename T>
void excluirAluno(Lista<T> &lista, string nome)
{
    // Insert code here...
}

// -------------------------- Exclui uma disciplina de um aluno -------------- //
template<typename T>
void excluirDisciplina(Lista<T> &disciplinas, string disciplina)
{
    // Insert code here...
}

// -------------------- Mostra os alunos e as disciplinas -------------------- //
template<typename T>
void mostrarTodos(Lista<T> lista)
{
    NodoAluno<T> *p;
    p = lista.inicioA;

    while (p != NULL)
    {
        cout << p->aluno << endl;
        //cout << << endl;
        p = p->proximo;
    }
}

// -------------------- Mostra um aluno e suas disciplinas -------------------- //
template<typename T>
void mostrarUm(Lista<T> alunos, string nome)
{
    // Insert code here...
}

#endif // HESF_H_INCLUDED
