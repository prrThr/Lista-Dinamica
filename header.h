#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;

"*disciplinas" ALTERADO PARA "inicioD"
"p_aux" ALTERADO PARA "p2" quando se refere a lista de disciplinas
"alunos" ALTERADO PARA "lista"

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
    NodoDisciplina<T> *inicioD;
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
template<typename T> //OK
void criarListas(Lista<T> &lista)
{
    lista.cardinalidade = 0;
    lista.inicioA = NULL;
}

// -------------------------- Destrói lista Alunos --------------------------- //
template<typename T>
void destroi(Lista<T> &lista)
{
    NodoAluno<T> *p;
    while (lista.inicioA != NULL)
    {
        p = lista.inicioA;
        lista.inicioA = lista.inicioA->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}
// ------------------------- Verifica se lista vazia ------------------------- //
template<typename T> //OK
bool verificarSeListaVazia(Lista<T> lista)
{
    if (lista.cardinalidade == 0)
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
    NodoDisciplina<T> *p2;

    while(p != NULL)
    {
        if(p->aluno == nome)
        {
            while(p2 != NULL)
            {
                if (p2->disciplina == disc)
                    return p2->cardinalidade;
                p2 = p2->proximo;
            }
        }
        p = p->proximo;
    }
}

// ----------------------- Verifica se o aluno existe ------------------------ //
template<typename T> //OK
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
template<typename T> //OK
bool disciplinaExistente(Lista<T> lista, T disc, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p2;
    while (p != NULL)
    {
        if(p->aluno == nome)
        {
            p2 = p->inicioD;
            while(p2 != NULL)
            {
                if (p2->disciplina == disc)
                    return true;

                p2 = p2->proximo;
            }
            return false;
        }
        p = p->proximo;
    }
    return false; //Só pra não dar warning
}
// ----------------------------- Insere um aluno ----------------------------- //
template<typename T> //OK
void inserirAluno(Lista<T> &lista, T nome)
{
    NodoAluno<T> *p, *p_ant;
    NodoDisciplina<T> *p2;
    p = new NodoAluno<T>;
    p->aluno = nome;
    p->proximo = NULL;

    p2 = new NodoDisciplina<T>;
    p2->cardinalidade = 0;
    p2->quantidadeAlunos = 0;
    p2->proximo = NULL;

    p->inicioD = p2; //Linka o aluno com o inicio lista de disciplinas
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
template<typename T> // OK
void inserirDisciplina(Lista<T> &lista, T disc, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p2, *p2_ant;

    while(p != NULL)
    {
        if(p->aluno == nome)
        {
            p2 = p->inicioD;
            if (p2->cardinalidade > 0)
            {
                p2 = new NodoDisciplina<T>;
                p2_ant = p->inicioD;
                while(p2_ant->proximo != NULL)
                    p2_ant = p2_ant->proximo;
                p2_ant->proximo = p2;
            }
            p2->disciplina = disc;
            p2->cardinalidade++;
            p2->quantidadeAlunos++;
            p2->proximo = NULL;


            cout << "Disciplina " << p2->disciplina << " inserida." << endl;
        }
        p = p->proximo;
    }
    return; //Só pra não dar warning
}

// ----------------------------- Exclui um aluno ----------------------------- //
template<typename T> //APARENTEMENTE FUNCIONANDO
void excluirAluno(Lista<T> &lista, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoAluno<T> *p_ant = lista.inicioA;
    int contador = 1;
    while(p != NULL)
    {
        if (p->aluno == nome)
        {
            if (contador == 1) //caso for o primeiro da lista
            {
                lista.inicioA = lista.inicioA->proximo;
                cout << "chegou aqui" << endl;
                delete p;
            }
            else
            {
                while(p_ant->proximo != p)
                    p_ant = p_ant->proximo;
                cout << "chegou aqui" << endl;
                p_ant->proximo = p->proximo;
                delete p;
                cout << "Aluno excluido!" << endl;
                return;
            }
        }
        contador++;
        p = p->proximo;
    }
}
//1010 1020 1030
//p = 1020 pProx = 1030
//p_ant = 1010 paProx = 1020;
//paProx = pProx, 1020 = 1030
//delete p(1020)

// -------------------------- Exclui uma disciplina de um aluno -------------- //
template<typename T>
void excluirDisciplina(Lista<T> &lista, T disciplina, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p2_ant, *p2;
    int contador = 1;

    while(p != NULL)
    {
        if (p->aluno == nome)
        {
            p2 = p->inicioD;
            p2_ant = p->inicioD;
            cout << "chegou aqui" << endl;
            while(p2 != NULL)
            {
                cout << "chegou aqui" << endl;

                if (contador == 1) //caso for o primeiro da lista
                {
                    p2 = p2->proximo;
                    cout << "chegou aqui" << endl;
                    delete p2;
                }
                else
                {
                    while(p2_ant->proximo != p2)
                        p2_ant = p2_ant->proximo;
                    cout << "chegou aqui" << endl;
                    p2_ant->proximo = p2->proximo;
                    delete p2;
                    cout << "Disciplina excluida!" << endl;
                    return;
                }
                contador++;
                p2 = p2->proximo;
            }
        }
        p = p->proximo;
    }
}

// -------------------- Mostra os alunos e as disciplinas -------------------- //
template<typename T> //OK
void mostrarTodos(Lista<T> lista)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p2;

    while(p != NULL)
    {
        p2 = p->inicioD;
        cout << "Aluno: " << p->aluno << endl;
        if (p2 == NULL)
            cout << "O aluno não esta cadastrado em nenhuma disciplina" << endl;
        else
        {
            cout << "Disciplinas: ";
            while(p2 != NULL)
            {
                cout << p2->disciplina << " ";
                p2 = p2->proximo;
            }
            cout << endl;
        }
        p = p->proximo;
    }
}

// -------------------- Mostra um aluno e suas disciplinas -------------------- //
template<typename T> //APARENTEMENTE FUNCIONANDO
void mostrarUm(Lista<T> lista, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p2;


    while (p != NULL)
    {
        if (p->aluno == nome)
        {
            p2 = p->inicioD;
            cout << "Aluno: " << p->aluno << endl;
            if (p2 == NULL)
            {
                cout << "O aluno não esta cadastrado em nenhuma disciplina" << endl;
                return;
            }
            cout << "Disciplinas: ";
            while(p2 != NULL)
            {
                cout << p2->disciplina << " ";
                p2 = p2->proximo;
            }
            cout << endl;
            return;
        }
        p = p->proximo;
    }
}
#endif // HEADER_H_INCLUDED
