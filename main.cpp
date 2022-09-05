/*
[x]Criar uma lista
[x]Destruir uma lista
[x]Verificar se a lista está vazia
[x]Recuperar o número de elementos da lista
[x]Recuperar o número de elementos associado a outro elemento da lista
[x]Verificar se um elemento existe na lista
[x]Verificar se um elemento associado a outro elemento existe na lista
[x]Inserir um elemento na lista
[x]Inserir um elemento associado a outro elemento da lista
[x]Retirar um elemento da lista
[x]Retirar um elemento associado a outro elemento da lista
[x]Mostrar uma lista
[x]Mostrar os elementos associados a outro elemento da lista

[x]Inserção de um aluno
[x]Inserção de disciplina de um aluno
[x]Retirar um aluno
[x]Retirar disciplina de um aluno
[x]Mostrar todos os alunos e suas disciplinas
[x]Mostrar um aluno e suas disciplinas
[ ]Gerar uma lista de listas com todas as disciplinas e o número de alunos que a cursam
*/

#include <iostream>
#include "header.h"
#include <stdlib.h>
using namespace std;
int main()
{
    setlocale(LC_ALL,"Portuguese");

    Lista<string> alunos;
    int opcao;
    string nome, disc;

    criarListas(alunos);
    do
    {
        cout << "1 - Inserir aluno" << endl;
        cout << "2 - Inserir disciplina de um aluno" << endl;
        cout << "3 - Retirar um aluno" << endl;
        cout << "4 - Retirar disciplina de um aluno" << endl;
        cout << "5 - Mostrar todos os alunos e todas as disciplinas" << endl;
        cout << "6 - Mostar aluno e suas disciplinas" << endl;
        cout << "7 - (Depois transformar em -Mostrar lista 2-)" << endl;
        cout << "8 - Sair" << endl;
        cout << "\n----- Área de testes - deletar funções seguintes ao terminar o programa -----" << endl;
        cout << "9 - Retorna o numero de disciplinas de um aluno" << endl;
        cout << "10 - Retorna o numero de alunos" << endl;
        //do
        //{
            cin >> opcao;
            //if (opcao < 1 or opcao > 8)
                //cout << "Digite uma opção entre 1 e 8!" << endl;
        //}
        //while(opcao < 1 or opcao > 8);
        system("cls");
        switch(opcao)
        {
        case 1:
            cout << "Digite o nome do aluno para inserir: ";
            cin.ignore();
            getline(cin,nome);
            if (!alunoExistente(alunos, nome))
                inserirAluno(alunos, nome);
            else
                cout << "Aluno já existente." << endl;
            break;

        case 2:
            cout << "Digite o aluno para que deseja inserir uma disciplina: ";
            cin.ignore();
            getline(cin,nome);
            if (alunoExistente(alunos, nome))
            {
                cout << "Digite a disciplina que deseja inserir:";
                getline(cin, disc);
                if (!disciplinaExistente(alunos, disc, nome))
                    inserirDisciplina(alunos, disc, nome);
                else
                    cout << "O aluno " << nome << " já está matriculado na disciplina" << endl;
            }
            else
                cout << "Aluno não existente." << endl;
            break;

        case 3:
            cout << "Digite o aluno que deseja excluir: ";
            cin.ignore();
            getline(cin,nome);
            if (alunoExistente(alunos, nome))
                excluirAluno(alunos, nome);
            else
                cout << "Aluno não existente." << endl;
            break;

        case 4:
            cout << "Digite o nome do aluno que deseja excluir a disciplina: ";
            cin.ignore();
            getline(cin,nome);
            if (alunoExistente(alunos, nome))
            {
                cout << "Informe a disciplina que deseja excluir: ";
                getline(cin, disc);
                if (disciplinaExistente(alunos, disc, nome))
                    excluirDisciplina(alunos, disc, nome);
                else
                    cout << "Disciplina não existe ou o aluno não está matriculado" << endl;
            }
            else
                cout << "Aluno não existente." << endl;
            break;

        case 5:
            if (!verificarSeListaVazia(alunos))
                mostrarTodos(alunos);
            else
                cout << "Nenhum aluno cadastrado." << endl;
            break;

        case 6:
            cout << "Digite o nome do aluno: ";
            cin.ignore();
            getline(cin,nome);
            if (alunoExistente(alunos, nome))
                mostrarUm(alunos, nome);
            else
                cout << "Aluno inexistente." << endl;
            break;

        //case 7:
        //    break;

        case 8:
            cout << "Saindo..." << endl;
            destroi(alunos); //A lista de disciplinas está dentro da lista "alunos"
            break;

        case 9:
            cout << "Digite o nome do aluno que deseja verificar a quantidade de disciplinas: ";
            cin.ignore();
            getline(cin,nome);
            if (alunoExistente(alunos,nome))
                cout << "Numero de disciplinas do aluno " << nome << ": " << numeroDisciplinas(alunos, nome) << endl;
            else
                cout << "Aluno não existente" << endl;
            break;

        case 10:
            cout << "Quantidade de alunos: " << numeroAlunos(alunos) << endl;
            break;
        }
        cout << endl;
    }
    while(opcao != 8);
    return 0;
}
