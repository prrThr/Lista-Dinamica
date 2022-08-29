/*
[ ]inser��o de um aluno
[ ]inser��o de disciplina de um aluno
[ ]retirar um aluno
[ ]retirar disciplina de um aluno
[ ]mostrar todos os alunos
[ ]mostrar disciplinas
[ ]mostrar um aluno e suas disciplinas.
*/

#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    setlocale(LC_ALL,"portuguese");

    ListaAluno<string> alunos;
    ListaDisciplina<string> disciplinas;

    char resp;
    int opcao;
    string nome;

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
            if (opcao < 1 or opcao > 7)
                cout << "Digite uma op��o entre 1 e 7!" << endl;
        }
        while(opcao < 1 or opcao > 7)

            switch(opcao)
            {
            case 1:
                if (verificarSeListaVazia(alunos))
                    criarListas();
                else
                    cout << "Digite o nome do aluno para inserir: ";
                cin.ignore();
                getline(cin,nome);
                if (!alunoExistente)
                    inserirAluno();
                else
                    cout << "Aluno j� existente." << endl;
                break;

            case 2:
                cout << "Digite o aluno para que deseja inserir uma disciplina: ";
                cin.ignore();
                getline(cin,nome);
                if (alunoExistente)
                {
                    cout << "Digite a disciplina que deseja inserir:";
                    getline(cin, disciplina);
                    if (!disciplinaExistente)
                        inserirDisciplina();
                    else
                        cout << "O aluno j� est� matriculado na disciplina" << endl;
                }
                else
                    cout << "Aluno n�o existente." << endl;
                break;

            case 3:
                cout << "Digite o aluno que deseja excluir: ";
                cin.ignore();
                getline(cin,nome);
                if (alunoExistente)
                    excluirAluno(nome);
                else
                    cout << "Aluno n�o existente." << endl;
                break;

            case 4:
                cout << "Digite o nome do aluno que deseja excluir a disciplina: ";
                cin.ignore();
                getline(cin,nome);
                if (alunoExistente())
                {
                    cout << "Informe a disciplina que deseja excluir: ";
                    getline(cin,disciplina);
                    if (disciplinaExistente)
                        excluirDisciplina();
                    else
                        cout << "Disciplina n�o existe ou o aluno n�o est� matriculado";
                }
                else
                    cout << "Aluno n�o existente." << endl;
                break;

            case 5:
                if (verificarSeListaVazia(alunos))
                    mostrarTodos(alunos, disciplinas);
                else
                    cout << "Nenhum aluno cadastrado." << endl;
                break;

            case 6:
                cout << "Digite o nome do aluno: ";
                cin.ignore();
                getline(cin,nome);
                if (alunoExistente(alunos))
                    mostrarUm(alunos, disciplinas, nome);
                else
                    cout << "Aluno inexistente." << endl;
                break;

            case 7:
                if (verificarSeListaVazia(alunos))
                    mostrarTodos(alunos, disciplinas);
                else
                    cout << "Nenhum aluno cadastrado." << endl;
                break;

            case 8:
                cout << "Saindo..." << endl;
                destroi(alunos);
                destroi(disciplinas);
                exit(1);
                break;
            }
    }
    while(opcao != 7)

        return 0;
}
