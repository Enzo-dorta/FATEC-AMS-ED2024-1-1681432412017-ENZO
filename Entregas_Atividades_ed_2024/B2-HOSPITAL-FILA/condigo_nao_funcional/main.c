/*    Enzo Dorta Stevanato de Brito        profº Verissimo
      Estrutura de Dados                    13/05/2024
      Fatec Antonio Russo                    SCS,SP*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIMIT 50

// Definição das estruturas

typedef struct paciente {
    int inicio;
    int fim;
    int idPaciente;
    int idMedico;
    char nomePaciente[MAXLIMIT];
    char nomeMedico[MAXLIMIT];
    int idadePaciente;
    int estadoClinico;
    int especialidade;
    struct paciente *prox;
} PACIENTE;

/*typedef struct consulta {
    int inicio;
    int fim;
    int idPaciente;
    int idMedico;
    char nomePaciente[MAXLIMIT];
    char nomeMedico[MAXLIMIT];
    int idadePaciente;
    int estadoClinico;
    int especialidade;
    struct consulta *prox;
} CONSULTA;*/

// Funções para criação de estruturas
PACIENTE* criaFila(void);
//CONSULTA* criaConsulta(void);


// Funções para manipulação da fila de pacientes
void adicionarPaciente(PACIENTE** fila);
void listarFila(PACIENTE* fila);
void chamarPaciente(PACIENTE* fila);


int main(void) {
    int opcao;
    PACIENTE *fila = NULL; // Inicializa a fila como vazia
    //CONSULTA *consulta = NULL; // Inicializa a consulta como vazia

    do {
        printf("Selecione a opção:\n");
        printf("1 - Adicionar paciente\n");
        printf("2 - Listar pacientes\n");
        printf("3 - Chamar pacientes\n");
        printf("4 - Ver atendimento nos consultórios\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarPaciente(&fila);
                break;
            case 2:
                listarFila(fila);
                break;
            case 3:
                chamarPaciente(fila);
                break;
            case 4:
                // listarConsultas()
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}


PACIENTE* criaFila(void) {
    return NULL; // Retorna NULL para indicar que a fila está vazia
}


/*CONSULTA* criaConsulta(void) {
    // Implemente conforme necessário
    return NULL;
}*/


void adicionarPaciente(PACIENTE** fila) {
    PACIENTE* novoPaciente = (PACIENTE*)malloc(sizeof(PACIENTE));
    if (novoPaciente == NULL) {
        printf("Erro ao alocar memória para o novo paciente\n");
        return;
    }
    novoPaciente->idPaciente +=1;

    printf("Qual o nome do paciente? ");
    scanf("%s", novoPaciente->nomePaciente);

    printf("Qual a idade do paciente? ");
    scanf("%d", &novoPaciente->idadePaciente);

    printf("Qual o estado clínico do paciente?\n");
    printf("1 - Quadro viral/doente\n");
    printf("2 - Grávida\n");
    printf("3 - Urgência\n");
    printf("4 - COVID\n");
    printf("5 - Autista/TDAH\n");
    printf("6 - Outro\n");
    scanf("%d", &novoPaciente->estadoClinico);

    if (novoPaciente->estadoClinico == 4) {
        printf("Paciente indicado para quarentena\n");
        free(novoPaciente);
        return;
    }

    printf("Qual a especialidade necessária?\n");
    printf("1 - Cardiologista\n");
    printf("2 - Clínico geral\n");
    printf("3 - Ortopedista\n");
    printf("4 - Pediatra\n");
    printf("5 - Obstetra\n");
    printf("6 - Geriatra\n");
    printf("7 - Urgência\n");
    scanf("%d", &novoPaciente->especialidade);

    if (novoPaciente->estadoClinico != 2 && novoPaciente->especialidade == 5) {
        printf("Paciente indicado invalido para especialista, tente novamente\n");
        free(novoPaciente);
        return;
    }

    if (novoPaciente->idadePaciente < 60 && novoPaciente->especialidade == 6){
        printf("Paciente indicado invalido para especialista, tente novamente\n");
        free(novoPaciente);
        return;
    }

    switch(novoPaciente->especialidade){
        case 1:
            novoPaciente-> idMedico = 1;
                strcpy(novoPaciente ->nomeMedico, "Dr. João");
        break;
        case 2:
            novoPaciente -> idMedico = 2;
                strcpy(novoPaciente -> nomeMedico, "Dra. Maria");
        break;
        case 3:
            novoPaciente -> idMedico = 3;
                strcpy(novoPaciente-> nomeMedico, "Dr. Osvaldo");
        break;
        case 4: 
            novoPaciente -> idMedico = 4;
                strcpy(novoPaciente -> nomeMedico, "Dra. Heloisa ");
        break;
        case 5:
            novoPaciente -> idMedico = 5;  
                strcpy(novoPaciente -> nomeMedico, "Dra. Clara");
        break;
        case 6:
            novoPaciente -> idMedico = 6;
                strcpy(novoPaciente -> nomeMedico, "Dr. Fabio");
        break;
        case 7: 
            novoPaciente -> idMedico = 7;
                strcpy(novoPaciente -> nomeMedico, "Equipe de urgencia");
        break;

      }

    // Adiciona o novo paciente ao final da fila
    novoPaciente->prox = NULL;
    if (*fila == NULL) {
        *fila = novoPaciente;
        novoPaciente->fim ++;
    } else {
        PACIENTE* temp = *fila;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoPaciente;
        temp->fim ++;
    }
}



void chamarPaciente(PACIENTE* fila){
PACIENTE* temp = fila;
    static int count = 0;
    if (fila == NULL)
    {
        printf("Não há pacientes na fila.\n");
    }
    for(int i =0;i<sizeof(temp);i++){
    if(temp->estadoClinico == 3){
        printf("Paciente chamado: %s\n Sala: %d\n Nome do Medico: %s\n  ", temp->nomePaciente, temp->idMedico,temp->nomeMedico);
        free(temp);
        temp->inicio ++;
    }
    if(sizeof(temp)>=5){
    switch(count){
        case 0:
            if(temp->estadoClinico != 2|| temp->estadoClinico != 5|| temp->idadePaciente <60){
            printf("Paciente chamado: %s\n Sala: %d\n Nome do Medico: %s\n  ", temp->nomePaciente, temp->idMedico,temp->nomeMedico);
            free(temp);
            temp->inicio ++;
                count ++;}
            break;
        case 1:
            if(temp->estadoClinico != 2|| temp->estadoClinico != 5|| temp->idadePaciente <60){
                printf("Paciente chamado: %s\n Sala: %d\n Nome do Medico: %s\n  ", temp->nomePaciente, temp->idMedico,temp->nomeMedico);
                free(temp);
                temp->inicio ++;
                count ++;}
            break;
        case 2:
                if(temp->estadoClinico == 2|| temp->estadoClinico == 5|| temp->idadePaciente >=60){
                    printf("Paciente chamado: %s\n Sala: %d\n Nome do Medico: %s\n  ", temp->nomePaciente, temp->idMedico,temp->nomeMedico);
                    free(temp);
                    temp->inicio ++;
                    count -= 2;}
            break;
    }
            }
    else{
        printf("Paciente chamado: %s\n Sala: %d\n Nome do Medico: %s\n  ", temp->nomePaciente, temp->idMedico,temp->nomeMedico);
        free(temp);
        temp->inicio ++;
    }
    }
    //if(fila->prox == NULL)temp-> prox = NULL;
}



void listarFila(PACIENTE* fila) {
    if (fila == NULL) {
        printf("Fila vazia!\n");
    } else {
        printf("Pacientes na fila:\n");
        int posicao = 1;
        while (fila != NULL) {
            printf("%d. Nome: %s, Idade: %d, Estado clínico: %d, Especialidade: %d\n",
                posicao, fila->nomePaciente, fila->idadePaciente, fila->estadoClinico, fila->especialidade);
            fila = fila->prox;
            posicao++;
        }
    }
}
