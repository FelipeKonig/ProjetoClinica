#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct secretario{
    char nomePaciente[30];
    char cpfPaciente[13];
    char cidadePaciente[11];
    char rgPaciente[8];
    int codPaciente;
};
struct agenda{
    char nomeAgenda[30];
    char data[12];
    char hora[8];
    int codAgenda;
};
struct agenda2{
    char nomeAgenda[30];
    char data[12];
    char hora[8];
    int codAgenda;
};
struct medico{
    char nomeConsulta[30];
    char doenca[20];
    char remedio[20];
    char dataConsulta[12];
    int codProntuario;
};
int menuMedico(int funcao){
    int opcao;
        printf("1 - para mostrar lista de pacientes\n");
        printf("2 - para mostrar agenda\n");
        printf("3 - para acessar prontuario\n");
        printf("4 - para sair\n");
        scanf("%d",&opcao);
        if(opcao != 4)
            return opcao;
        else
            system(exit);
}
int menuSecretario(int funcao){
    int opcao;
        printf("1 - para cadastrar um paciente\n");
        printf("2 - para acessar a agenda\n");
        printf("3 - para acessar a lista de pacientes\n");
        printf("4 - para sair\n");
        scanf("%d",&opcao);
        if(opcao != 4)
            return opcao;
        else
            system(exit);
}

int main(){
    int funcao,r,opcao,opcaoAgenda,opcaoProntuario,opcaoPaciente,sair = 0,continuar,i,qtd,codigo;
    int remover,linhainicial = 1;
    char ler[1000];

    struct secretario paciente[50];
    struct secretario paciente2[50];
    struct agenda horario[50];
    struct medico consulta[50];
    struct agenda2 horario2[50];

    int codigoPaciente =1,codigoAgenda =1,codigoProntuario =1;

    printf("Bem vindo\n");

    while(sair != 4){
        printf("1 - para entrar como secretario\n");
        printf("2 - para entrar como medico\n");
        scanf("%d",&funcao);
        system("cls");

        if(funcao == 1){
            r = menuSecretario(opcao);
            system("cls");
            if(r == 1){
                continuar = 0;
                FILE * arquivoCadastro;
                    arquivoCadastro = fopen("cadastroPaciente.txt","a");
                    if(arquivoCadastro == NULL){
                        printf("A lista esta com 0 cadastros \n");
                    }
                    while(continuar != 3){

                        printf("Cadastro do paciente\n");

                        printf("Digite a quantidade que voce deseja: ");
                        scanf("%d",&qtd);
                        for(i=0;i < qtd;i++){

                            printf("Digite o nome do novo paciente(ex: Felipe-Konig): ");
                            scanf("%s",paciente[i].nomePaciente);
                            printf("Digite o cpf do novo paciente: ");
                            scanf("%s",paciente[i].cpfPaciente);
                            printf("Digite o rg do novo paciente: ");
                            scanf("%s",paciente[i].rgPaciente);
                            printf("Digite a cidade do novo paciente(ex: Tres-Barras): ");
                            scanf("%s",paciente[i].cidadePaciente);

                            if(codigoPaciente == 1){
                                paciente[i].codPaciente = codigoPaciente;
                                codigoPaciente++;
                            }
                            else{
                                paciente[i].codPaciente = codigoPaciente;
                                codigoPaciente++;
                            }

                            fprintf(arquivoCadastro," id: %d\t nome: %s\t CPF: %s\t RG: %s\t cidade: %s\n",paciente[i].codPaciente, paciente[i].nomePaciente,paciente[i].cpfPaciente,paciente[i].rgPaciente,paciente[i].cidadePaciente);
                            printf("Cadastro realizado com sucesso\n");
                        }
                        printf("Digite 3 para voltar: ");
                        scanf("%d",&continuar);
                        system("cls");
                }
                funcao = 1;
                system("cls");
                fclose(arquivoCadastro);
            }
            else if(r == 2){
                continuar = 0;
                FILE * arquivoAgenda;
                    if(arquivoAgenda == NULL){
                        printf("criando arquivo\n");
                    }

                while(continuar != 3){
                    printf("1 - para adicionar um novo horario\n");
                    printf("2 - para remover algum horario\n");
                    scanf("%d",&opcaoAgenda);
                    system("cls");

                    if(opcaoAgenda == 1){
                        arquivoAgenda = fopen("agenda.txt","a+");

                        for(i=0;i<1;i++){

                                printf("Digite o nome do paciente(ex: Felipe-Konig): ");
                                scanf("%s",horario[i].nomeAgenda);
                                printf("Digite a data da consulta(ex: 01-01-2019): ");
                                scanf("%s",horario[i].data);
                                printf("Digite o horario da consulta(ex: 08:45): ");
                                scanf("%s",horario[i].hora);

                                if(codigoAgenda == 1){
                                    horario[i].codAgenda = codigoAgenda;
                                    codigoAgenda++;
                                }
                                else{
                                    horario[i].codAgenda = codigoAgenda;
                                    codigoAgenda++;
                                }
                                printf("Agendamento realizado com sucesso\n");

                                fprintf(arquivoAgenda,"id: %d\t nome: %s\t data: %s\t hora: %s\n",horario[i].codAgenda,horario[i].nomeAgenda,horario[i].data,horario[i].hora);

                            fclose(arquivoAgenda);
                        }
                    }else if(opcaoAgenda == 2){

                        arquivoAgenda = fopen("agenda.txt","r");

                        FILE * arquivoAgenda2;
                        arquivoAgenda2 = fopen("agenda2.txt","w");

                        printf("Digite o id que deseja remover: ");
                        scanf("%d",&remover);

                        while(fgets(ler, 1000, arquivoAgenda) != NULL ){
                            if( linhainicial != remover){
                                fputs(ler, arquivoAgenda2);
                            }
                        linhainicial+= 1;
                        }
                        fclose(arquivoAgenda);

                        remove("agenda.txt");

                        fclose(arquivoAgenda2);

                        rename("agenda2.txt","agenda.txt");

                        printf("Removido com sucesso\n");
                    }
                    else{

                        i = 0;
                        while((fscanf(arquivoAgenda,"%d\t %s\t %s\t %s\n",&horario[i].codAgenda,horario[i].nomeAgenda,horario[i].data,horario[i].hora))!= EOF)
                            printf("%d\t %s\t %s\t %s\n",horario[i].codAgenda,horario[i].nomeAgenda,horario[i].data,horario[i].hora);
                        i++;

                    }
                        printf("Digite 3 para voltar: ");
                        scanf("%d",&continuar);
                        system("cls");
                    }
                    funcao = 1;
                    system("cls");
                    fclose(arquivoAgenda);
                }
                else if(r == 3){
                continuar = 0;
                FILE * arquivoCadastro;
                arquivoCadastro = fopen("cadastroPaciente.txt","r");
                while(fgets(paciente,50,arquivoCadastro) != NULL)
                    printf("%s ",paciente);

                while(continuar != 3){

                    printf("Digite 3 para voltar: ");
                    scanf("%d",&continuar);
                    system("cls");
                }
                funcao = 1;
                system("cls");
                fclose(arquivoCadastro);
            }
        }
        else{

            r = menuMedico(opcao);
            system("cls");
            if(r == 1){
                continuar = 0;
                FILE * arquivoCadastro;
                    arquivoCadastro = fopen("cadastroPaciente.txt","r");
                    if(arquivoCadastro == NULL){
                        printf("A lista de cadastramento nao tem nenhum paciente\n");
                    }
                    while(continuar != 3){

                        while(fgets(paciente,50,arquivoCadastro) != NULL)
                            printf("%s ",paciente);

                        printf("Digite 3 para voltar: ");
                        scanf("%d",&continuar);
                        system("cls");
                }

                funcao = 2;
                system("cls");
                fclose(arquivoCadastro);
            }
            else if(r == 2){
                continuar = 0;
                FILE * arquivoAgenda;
                arquivoAgenda = fopen("agenda.txt","r");

                if(arquivoAgenda == NULL){
                    printf("A lista de agendamento esta com 0 horarios\n");
                }
                else{

                while(fgets(horario,50,arquivoAgenda) != NULL)
                    printf("%s ",horario);
                }

                while(continuar != 3){

                    printf("Digite 3 para sair: ");
                    scanf(" %d",&continuar);
                    system("cls");
                }
                funcao = 2;
                system("cls");
                fclose(arquivoAgenda);
            }
            else if(r == 3){
                opcaoProntuario = 0;
                continuar = 0;
                FILE * arquivoProntuario;
                if(arquivoProntuario == NULL){
                    printf("Ainda nao a nenhum prontuario\n");
                }
                while(continuar != 3){

                    arquivoProntuario = fopen("prontuario.txt","r");

                    printf("1 - para buscar prontuario do paciente digite \n");
                    printf("2 - para fazer um prontuario novo digite \n");
                    printf("3 - para mostrar um prontuario\n");
                    scanf("%d",&opcaoProntuario);
                    system("cls");

                    if(opcaoProntuario == 1){

                        printf("Buscar prontuario\n");

                        printf("Digite o id do prontuario: ");
                        scanf("%d",&codigo);

                        int j = 1;
                        while(!feof(arquivoProntuario)){
                            fscanf(arquivoProntuario," id: %d\t nome: %s\t doenca: %s\t remedio: %s\t dataConsulta: %s\n",&consulta[j].codProntuario,consulta[j].nomeConsulta,consulta[j].doenca,consulta[j].remedio,consulta[j].dataConsulta);
                            if(codigo == consulta[j].codProntuario){
                                printf(" id: %d\t nome: %s\t doenca: %s\t remedio: %s\t dataConsulta: %s\n",consulta[j].nomeConsulta, consulta[j].doenca, consulta[j].remedio, consulta[j].dataConsulta);
                            }
                            j++;
                        }
                    }
                    else if(opcaoProntuario == 2){
                        arquivoProntuario = fopen("prontuario.txt","a+");

                        for(i=0;i<1;i++){

                                printf("Digite o nome do paciente(ex: Felipe-Konig): ");
                                scanf("%s",consulta[i].nomeConsulta);
                                printf("Digite a doenca do paciente(ex: Gripe-A): ");
                                scanf("%s",consulta[i].doenca);
                                printf("Digite o remedio que o paciente precisa(ex: Pozato-Uni): ");
                                scanf("%s",consulta[i].remedio);
                                printf("Digite a data da consulta(ex: 01-01-2018): ");
                                scanf("%s",consulta[i].dataConsulta);

                                if(codigoProntuario == 1){
                                consulta[i].codProntuario = codigoProntuario;
                                codigoProntuario++;
                                }
                                else{
                                    consulta[i].codProntuario = codigoProntuario;
                                    codigoProntuario++;
                                }
                                fprintf(arquivoProntuario," id: %d\t nome: %s\t doenca: %s\t remedio: %s\t dataConsulta: %s\n",consulta[i].codProntuario,consulta[i].nomeConsulta,consulta[i].doenca,consulta[i].remedio,consulta[i].dataConsulta);

                                printf("Prontuario cadastrado com sucesso\n");
                        }
                    }
                    else{

                    while(fgets(consulta,50,arquivoProntuario) != NULL)
                        printf("%s ",consulta);

                    }
                printf("Digite 3 para voltar: ");
                scanf("%d",&continuar);
                system("cls");
                }
                funcao = 2;
                system("cls");
                fclose(arquivoProntuario);
            }
        }
    }
    return 0;
}

