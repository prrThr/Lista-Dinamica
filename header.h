#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;

template<typename T>
struct NodoDisciplina
{
    T disciplina;
    int cardinalidade; // Quantidade de alunos que cursam a disciplina
    struct NodoDisciplina *proximo;
};

template<typename T>
struct NodoAluno
{
    T aluno;
    int cardinalidadeD; //Quantidade de disciplinas que o aluno esta matriculado
    NodoDisciplina<T> *inicioD;
    struct NodoAluno *proximo;
};

template<typename T>
struct Lista
{
    int cardinalidade; //Quantidade de alunos no total
    NodoAluno<T> *inicioA;
};

template<typename T>
struct ListaDisciplinas
{
    int cardinalidade; //Quantidade total de disciplinas
    NodoDisciplina<T> *inicioLD;
};

// --------------------------- Cria as duas listas --------------------------- //
template<typename T> //OK
void criarListas(Lista<T> &lista)
{
    lista.cardinalidade = 0;
    lista.inicioA = NULL;
}

template<typename T> //OK
void criarLista2(ListaDisciplinas<T> &lista2)
{
    lista2.cardinalidade = 0;
    lista2.inicioLD = NULL;
}

// -------------------------- Destrói lista Alunos --------------------------- //
template<typename T> //OK
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
template<typename T> //OK
int numeroAlunos(Lista<T> lista)
{
    return lista.cardinalidade;
}

// ----------------------- Verifica o numero de disciplinas de um aluno ------ //
template <typename T> // OK
int numeroDisciplinas(Lista<T> lista, T nome)
{
    NodoAluno<T> *p = lista.inicioA;

    while(p != NULL)
    {
        if(p->aluno == nome)
            break; //O return foi pra baixo para não dar o warning de "função int sem retorno"
        p = p->proximo;
    }
    return p->cardinalidadeD;
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
            break;
        }
        p = p->proximo;
    }
    return false;
}
// ----------------------------- Insere um aluno ----------------------------- //
template<typename T> //OK
void inserirAluno(Lista<T> &lista, T nome)
{
    NodoAluno<T> *p, *p_ant;
    p = new NodoAluno<T>;
    p->aluno = nome;
    p->cardinalidadeD = 0;
    p->proximo = NULL;
    p->inicioD = NULL;

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
    lista.cardinalidade++;

    cout << "Aluno " << p->aluno << " inserido." << endl;
}
// ------------- Adicionar cardinalidade na lista de disciplinas ------------- //

// ----------------------------- Insere uma disciplina de um aluno ----------- //
template<typename T> // OK
void inserirDisciplina(Lista<T> &lista, ListaDisciplinas<T> &lista2,T disc, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p2, *p2_ant;
    p2 = new NodoDisciplina<T>;

    while(p != NULL)
    {
        if(p->aluno == nome)
        {
            if (p->cardinalidadeD > 0)
            {
                p2_ant = p->inicioD;
                while(p2_ant->proximo != NULL)
                    p2_ant = p2_ant->proximo;
                p2_ant->proximo = p2;
            }
            else
                p->inicioD = p2;

            p->cardinalidadeD++;
            p2->disciplina = disc;
            p2->proximo = NULL;

            cout << "Disciplina " << p2->disciplina << " inserida." << endl;
            return;
        }
        p = p->proximo;
    }
}

// ----------------------------- Exclui um aluno ----------------------------- //
template<typename T> //OK
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
                lista.inicioA = lista.inicioA->proximo;
            else
            {
                while(p_ant->proximo != p)
                    p_ant = p_ant->proximo;
                p_ant->proximo = p->proximo;
            }
            delete p;
            cout << "Aluno excluido!" << endl;
            lista.cardinalidade--;
            return;
        }
        contador++;
        p = p->proximo;
    }
}

// -------------------------- Exclui uma disciplina de um aluno -------------- //
template<typename T> //OK
void excluirDisciplina(Lista<T> &lista, T disc, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p2_ant, *p2;
    int contador = 1;

    while(p != NULL)
    {
        if (p->aluno == nome)
        {
            p2 = p->inicioD;
            while(p2 != NULL)
            {
                if(p2->disciplina == disc)
                {
                    if (contador == 1) //caso for o primeiro da lista
                        p->inicioD = p->inicioD->proximo;
                    else
                    {
                        p2_ant = p->inicioD;
                        while(p2_ant->proximo != p2)
                            p2_ant = p2_ant->proximo;
                        p2_ant->proximo = p2->proximo;
                    }
                    delete p2;
                    p->cardinalidadeD--;
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
            cout << "Disciplinas (" << p->cardinalidadeD << "): " << endl;
            while(p2 != NULL)
            {
                cout << "-" << p2->disciplina << endl;
                p2 = p2->proximo;
            }
            cout << endl;
        }
        p = p->proximo;
    }
}

// -------------------- Mostra um aluno e suas disciplinas -------------------- //
template<typename T> //OK
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
            cout << "Disciplinas: " << endl;
            while(p2 != NULL)
            {
                cout << "-" << p2->disciplina << endl;
                p2 = p2->proximo;
            }
            cout << endl;
            return;
        }
        p = p->proximo;
    }
}


template<typename T>
void preencherlista2(ListaDisciplinas<T> &lista2, Lista<T> lista)
{
    NodoAluno<T> *p;
    NodoDisciplina<T> *p2, *p3, *p3_ant;
    p = lista.inicioA;
    p3 = new NodoDisciplina<T>;

    while(p != NULL)
    {
        cout << "chegou aqui 1" << endl;
        p2 = p->inicioD;
        //cout << "Lista2 cardinalidade" << lista2.cardinalidade << endl;
        //cout << "Lista2 cardinalidade" << lista2.cardinalidade << endl;
        while(p2 != NULL)//todas as disciplinas do aluno
        {
            cout << "chegou aqui 2" << endl;
            while(p3 != NULL)//todas as disciplinas da lista2
            {
                cout << "chegou aqui 3" << endl;
                if (lista2.cardinalidade == 0)
                {
                    cout << "chegou aqui cardinalidade = 0" << endl;
                    p3->disciplina = p2->disciplina;
                    p3->cardinalidade = 1;
                    p3->proximo = NULL;
                    lista2.cardinalidade = 1;
                }
                else
                {
                    cout << "chegou aqui ELSE" << endl;
                    if(p2->disciplina != p3->disciplina)
                    {
                        cout << "chegou aqui else1" << endl;
                        p3 = new NodoDisciplina<T>;
                        p3->cardinalidade = 0;

                        p3_ant = lista2.inicioLD;
                        while(p3_ant->proximo != NULL)
                            p3_ant = p3_ant->proximo;
                        p3_ant = p3_ant->proximo;
                        p3_ant->proximo = p3;

                        p3->proximo = NULL;
                        p3->cardinalidade++;
                        p3->disciplina = p2->disciplina;
                        lista2.cardinalidade++;
                    }
                    else
                        p3->cardinalidade++;//aumenta a quantidade do nodo atual
                }
                p3 = p3->proximo;
            }
            p2 = p2->proximo;
            p3 = lista2.inicioLD;
        }

        p = p->proximo;
    }
}

template<typename T>
void mostrarLista2(ListaDisciplinas<T> lista2)
{
    if (lista2.cardinalidade == 0)
        cout << "Lista vazia!";
    else
    {
        NodoDisciplina<T> *p;
        p = lista2.inicioLD;
        cout << "listainicioD " << lista2.inicioLD << endl;
        while (p != NULL)
        {
            cout << p->disciplina << endl;
            cout << "Alunos matriculados: " << p->cardinalidade << endl;
            p = p->proximo;
        }
    }
}

string inserirNome(string texto)
{
    string nome;
    cout << texto;
    cin.ignore();
    getline(cin,nome);

    return nome;
}
#endif // HEADER_H_INCLUDED
