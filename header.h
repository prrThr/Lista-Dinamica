#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
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
    alunos.inicioA = NULL;
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
template<typename T>
int numeroAlunos(Lista<T> lista)
{
    return lista.cardinalidade;
}

// ----------------------- Verifica o numero de disciplinas de um aluno ------ //
template <typename T> // TESTAR PQ PROVAVELMENTE NAO ESTA CERTO
int numeroDisciplinas(Lista<T> lista, T nome, T disc)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p_aux;

    while(p != NULL)
    {
        if(p->aluno == nome)
        {
            while(p_aux != NULL)
            {
                if (p_aux->disciplina == disc)
                    return p_aux->cardinalidade;
                p_aux = p_aux->proximo;
            }
        }
        p = p->proximo;
    }
}

// ----------------------- Verifica se o aluno existe ------------------------ //
template<typename T>
bool alunoExistente(Lista<T> lista, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    while(p != NULL)
    {
        if (p->aluno == nome)
            return true;
        p = p->proximo;
    }
    return false;
}

// --------------------- Verifica se a disciplina de um aluno existe --------- //
template<typename T> // TESTAR PQ PROVAVELMENTE NAO ESTA CERTO
bool disciplinaExistente(Lista<T> lista, T disc, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p_aux;
    while (p != NULL)
    {
        if(p->aluno == nome)
        {
            p_aux = p->disciplinas;
            while(p_aux != NULL)
            {
                if (p_aux->disciplina == disc)
                {
                    cout << "chegou aqui" << endl;
                    return true;
                }
                p_aux = p_aux->proximo;
            }
            return false;
            cout << "chegou aqui" << endl;
        }
        cout << "chegou aqui" << endl;
        p = p->proximo;
    }
}
// ----------------------------- Insere um aluno ----------------------------- //
template<typename T>
void inserirAluno(Lista<T> &lista, string nome)
{
    NodoAluno<T> *p, *p_ant;
    NodoDisciplina<T> *p2;
    p = new NodoAluno<T>;
    p2 = new NodoDisciplina<T>;
    p->aluno = nome;
    p->proximo = NULL;

    p2->cardinalidade = 0;
    p2->quantidadeAlunos = 0;

    p->disciplinas = p2;
    if(lista.cardinalidade == 0)
    {
        lista.inicioA = p;
        lista.cardinalidade++;
        cout << "Aluno " << p->aluno << " inserido." << endl;
        return;
    }

    p_ant = lista.inicioA;
    while(p_ant->proximo != NULL)
        p_ant = p_ant->proximo;
    p_ant->proximo = p;

    cout << "Aluno " << p->aluno << " inserido." << endl;
}

// ----------------------------- Insere uma disciplina de um aluno ----------- //
template<typename T>
void inserirDisciplina(Lista<T> &lista, string disc, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p_aux, *p_aux_ant;
    //p_aux = new NodoDisciplina<T>;
    p_aux->proximo = NULL;
    while(p != NULL)
    {
        if(p->aluno == nome)
        {
            p->disciplinas = p_aux;
            if (p_aux->cardinalidade == 0)
            {
                p_aux->disciplina = disc;
                p_aux->cardinalidade++;
                p_aux->quantidadeAlunos++;
                cout << "Disciplina " << p_aux->disciplina << " inserida." << endl;
                return;
            }
            p_aux_ant = p->disciplinas;
            while(p_aux_ant->proximo != NULL)
                p_aux_ant = p_aux_ant->proximo;
            p_aux_ant->proximo = p_aux;

            cout << "Disciplina" << p_aux->disciplina << " inserida." << endl;
        }
        p = p->proximo;
    }
    delete p_aux;
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
template<typename T> // FALTA MOSTRAR DISCIPLINA
void mostrarTodos(Lista<T> lista)
{
    NodoAluno<T> *p = lista.inicioA;

    while (p != NULL)
    {
        cout << p->aluno << endl;
        p = p->proximo;
    }
}

// -------------------- Mostra um aluno e suas disciplinas -------------------- //
template<typename T>
void mostrarUm(Lista<T> alunos, string nome)
{
    // Insert code here...
}
#endif // HEADER_H_INCLUDED
