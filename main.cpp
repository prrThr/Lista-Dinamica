#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    setlocale(LC_ALL,"portuguese");

    ListaAluno<string> alunos;
    int opcao;
    string nome, disc;

    do
    {
        cout << "1 - Inserir aluno" << endl;
        cout << "2 - Inserir disciplina de um aluno" << endl;
        cout << "3 - Retirar um aluno" << endl;
        cout << "4 - Retirar disciplina de um aluno" << endl;
        cout << "5 - Mostrar todos os alunos e todas as disciplinas" << endl;
        cout << "6 - Mostar aluno e suas disciplinas" << endl;
        cout << "7 - Mostrar disciplinas" << endl;
        cout << "8 - Sair" << endl;
        do
        {
            cin >> opcao;
            if (opcao < 1 or opcao > 8)
                cout << "Digite uma opção entre 1 e 8!" << endl;
        }
        while(opcao < 1 or opcao > 8);

        switch(opcao)
        {
        case 1:
            if (verificarSeListaVazia(alunos))
                criarListas(alunos);
            else
            {
                cout << "Digite o nome do aluno para inserir: ";
                cin.ignore();
                getline(cin,nome);
                if (!alunoExistente(alunos, nome))
                    inserirAluno(alunos, nome);
                else
                    cout << "Aluno já existente." << endl;
            }
            break;

        case 2:
            cout << "Digite o aluno para que deseja inserir uma disciplina: ";
            cin.ignore();
            getline(cin,nome);
            if (alunoExistente(alunos, nome))
            {
                cout << "Digite a disciplina que deseja inserir:";
                getline(cin, disc);
                if (!disciplinaExistente(alunos, disc))
                    inserirDisciplina(alunos, disc);
                else
                    cout << "O aluno " << nome << "já está matriculado na disciplina" << endl;
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
                if (disciplinaExistente(alunos, disc))
                    excluirDisciplina(alunos, disc);
                else
                    cout << "Disciplina não existe ou o aluno não está matriculado";
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

        case 7:
            if (verificarSeListaVazia(alunos))
                mostrarTodos(alunos);
            else
                cout << "Nenhum aluno cadastrado." << endl;
            break;

        case 8:
            cout << "Saindo..." << endl;
        //    destroi(alunos); //disciplinas ta dentro do "alunos"
            break;
        }
    }
    while(opcao != 8);
    return 0;
}
