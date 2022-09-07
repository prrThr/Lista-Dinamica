#include <iostream>
using namespace std;

template<typename T>
struct NodoDisciplina
{
    T disciplina;
    int cardinalidade; //Quantidade de alunos que cursam a disciplina
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
    int cardinalidade; //Quantidade de disciplinas no total
    NodoDisciplina<T> *inicioLD;
};

// --------------------------- Cria as duas listas --------------------------- //
template<typename T>
void criarListas(Lista<T> &lista, ListaDisciplinas<T> &lista2)
{
    lista.cardinalidade = 0;
    lista.inicioA = NULL;
    lista2.cardinalidade = 0;
    lista2.inicioLD = NULL;
}

// -------------------------- Destroi a lista 1 (Alunos) --------------------------- //
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
template<typename T>
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
template <typename T>
int numeroDisciplinas(Lista<T> lista, T nome)
{
    NodoAluno<T> *p = lista.inicioA;

    while(p != NULL)
    {
        if(p->aluno == nome)
            break;
        p = p->proximo;
    }
    return p->cardinalidadeD;
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
template<typename T>
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
template<typename T>
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
template<typename T>
void adicionaListaDisciplinas(ListaDisciplinas<T> &lista2, string disc)
{
    NodoDisciplina<T> *p, *p_aux, *p_aux2, *p2;
    bool trava = true;
    if(lista2.cardinalidade == 0)
    {
        p = new NodoDisciplina<T>;
        lista2.inicioLD = p;
        p->cardinalidade = 1;
        p->disciplina = disc;
        p->proximo = NULL;
        lista2.cardinalidade++;
    }
    else
    {
        p = lista2.inicioLD;
        while(p != NULL)
        {

            if (p->disciplina == disc)
            {
                p->cardinalidade++;
                return;
            }
            else
            {
                p2 = lista2.inicioLD;
                while (p2 != NULL)
                {
                    if (p2->disciplina == disc)
                    {
                        trava = false;
                        break;
                    }
                    p2 = p2->proximo;
                }

                if(trava == true)
                {
                    p_aux = new NodoDisciplina<T>;
                    p_aux->disciplina = disc;
                    p_aux->cardinalidade = 1;
                    p_aux->proximo = NULL;
                    lista2.cardinalidade++;
                    p_aux2 = lista2.inicioLD;
                    while (p_aux2->proximo != NULL)
                        p_aux2 = p_aux2->proximo;
                    p_aux2->proximo = p_aux;
                    return;
                }
                p = p->proximo;
            }
        }
    }
}
// ----------------------------- Insere uma disciplina de um aluno ----------- //
template<typename T>
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
            adicionaListaDisciplinas(lista2, disc);
            return;
        }
        p = p->proximo;
    }
}

// ----------------------------- Exclui um aluno ----------------------------- //
template<typename T>
void excluirAluno(Lista<T> &lista, ListaDisciplinas<T> &lista2, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoAluno<T> *p_ant = lista.inicioA;
    int contador = 1;
    excluirLista2Aluno(lista2, lista, nome);
    while(p != NULL)
    {
        if (p->aluno == nome)
        {
            if (contador == 1)
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
template<typename T>
void excluirDisciplina(Lista<T> &lista, T disc, T nome, ListaDisciplinas<T> &lista2)
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
                    if (contador == 1) //Caso for o primeiro da lista
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
                }
                else
                    contador++;

                p2 = p2->proximo;
            }
        }
        p = p->proximo;
    }
    excluirlista2(lista2, disc);
}

// -------------------- Excluir disciplina da lista 2 -------------------- //
template<typename T>
void excluirlista2(ListaDisciplinas<T> &lista, T nome)
{
    NodoDisciplina<T> *p = lista.inicioLD, *p_aux;
    NodoDisciplina<T> *p_ant = lista.inicioLD;
    int contador = 1;
    while(p != NULL)
    {
        if (p->disciplina == nome)
        {
            if (contador == 1)//Caso for o primeiro da lista
            {
                lista.inicioLD->cardinalidade--;
                if(lista.inicioLD->cardinalidade == 0)
                {
                    p_aux = lista.inicioLD;
                    lista.inicioLD = lista.inicioLD->proximo;
                    delete p_aux;
                    lista.cardinalidade--;
                }
                return;
            }
            else
            {
                while(p_ant->proximo != p)
                    p_ant = p_ant->proximo;
                p_ant->proximo = p->proximo;
                p->cardinalidade--;
                if(p->cardinalidade == 0)
                {
                    lista.cardinalidade--;
                    delete p;
                }
                return;
            }
        }
        contador++;
        p = p->proximo;
    }
}


// ------------------- Excluir Lista2 quando excluir o aluno ------------------- //
template<typename T>
void excluirLista2Aluno(ListaDisciplinas<T> &lista2, Lista<T> lista, T nome)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p3, *p2, *p_ant;
    while(p != NULL)
    {
        if (p->aluno == nome)
        {
            p2 = p->inicioD;
            while(p2 != NULL)
            {
                p3 = lista2.inicioLD;
                while(p3 != NULL)
                {
                    if (p3->disciplina == p2->disciplina)
                    {
                        p3->cardinalidade--;
                        if(p3->cardinalidade == 0)
                        {
                            if (lista2.inicioLD == p3)
                                lista2.inicioLD = p3->proximo;
                            else
                            {
                                while(p_ant->proximo != p3)
                                    p_ant = p_ant->proximo;
                                p_ant->proximo = p3->proximo;
                                lista2.inicioLD->cardinalidade--;
                            }
                            lista2.cardinalidade--;
                            delete p3;
                        }
                    }
                    p3 = p3->proximo;
                }
                p2 = p2->proximo;
            }
        }
        p = p->proximo;
    }
}
// -------------------- Mostra os alunos e as disciplinas -------------------- //
template<typename T>
void mostrarTodos(Lista<T> lista)
{
    NodoAluno<T> *p = lista.inicioA;
    NodoDisciplina<T> *p2;

    while(p != NULL)
    {
        p2 = p->inicioD;
        cout << "Aluno: " << p->aluno << endl;
        if (p2 == NULL)
            cout << "O aluno não esta cadastrado em nenhuma disciplina" << endl << endl;
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
template<typename T>
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

// -------------------- Mostra a Lista 2 (disciplinas) -------------------- //
template<typename T>
void mostrarLista2(ListaDisciplinas<T> lista2)
{
    if (lista2.cardinalidade == 0)
        cout << "Lista vazia!";
    else
    {
        NodoDisciplina<T> *p;
        p = lista2.inicioLD;

        while (p != NULL)
        {
            cout << p->disciplina << endl;
            cout << "Alunos matriculados: " << p->cardinalidade << endl;
            p = p->proximo;
        }
    }
}

// -------------------------  ------------------------- //
string inserirNome(string texto)
{
    string nome;
    cout << texto;
    cin.ignore();
    getline(cin,nome);

    return nome;
}
