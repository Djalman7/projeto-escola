#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_ALUNO 12
#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZACAO_ALUNO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_ALUNO_SUCESSO -6

typedef struct aluno{
    int matricula;
    char sexo;
    int ativo;
    char Nome[50];
    char CPF[15];
    char dataNascimento[11]; 
}Aluno;

int menugeral();
int menualuno();
int cadastrarAluno(Aluno lista_aluno[], int qtdAluno);
void listarAluno(Aluno lista_aluno[], int qtdAluno);
int atualizarAluno(Aluno lista_aluno[], int qtdAluno);
int excluirAluno(Aluno lista_aluno[], int qtdAluno);

int main(){

    int opcao;
    int sair = 0;
    int qtdAluno = 0;
    Aluno lista_aluno[TAM_ALUNO];

    while(!sair){

        opcao = menugeral();
 
        switch(opcao){
            case 0:{
                sair = 1;
                break; 
            }
             case 1:{
                printf("Modulo Aluno\n");
                int sairAluno = 0;
                int opcaoAluno;
                while(!sairAluno){
                    opcaoAluno =menualuno();
                switch (opcaoAluno){
                    case 0:{
                        sairAluno = 1;
                        break;
                    }
                    case 1:{
                        int retorno = cadastrarAluno(lista_aluno, qtdAluno);
                        if(retorno == LISTA_CHEIA){
                            printf("Lista de alunos cheia!\n");
                        }
                        else if(retorno == MATRICULA_INVALIDA){
                            printf("Matricula invalida\n");
                        }else{
                            printf("Cadastrado com sucesso!\n");
                            qtdAluno ++;
                        }
                        

                        break;
                    }
                    case 2:{
                        int retorno = atualizarAluno(lista_aluno, qtdAluno);
                        if(retorno==ATUALIZACAO_ALUNO_SUCESSO){
                            printf("Aluno atualizado com sucesso!\n");
                            }
                        else if(retorno == MATRICULA_INEXISTENTE){
                            printf("Matricula inexistente!\n");
                                }
                        else{
                            printf("Matricula invalida\n");
                            }
                        break;
                    }
                    case 3:{
                        listarAluno(lista_aluno, qtdAluno);
                        break;
                    }
                    case 4:{
                        int retorno = excluirAluno(lista_aluno, qtdAluno); 

                        if(retorno == EXCLUSAO_ALUNO_SUCESSO){
                            printf("Aluno excluido com sucesso\n");
                            qtdAluno --;
                        }
                        else if(retorno == MATRICULA_INVALIDA){
                            printf("Matricula invalida\n");
                        }else{
                            printf("Matricula inexistente!\n");
                        }

                        break;
                    }
                    default:{
                        printf("Opção invalida!\n");
                    }
                }
                
            
            }
            break;
            }
             case 2:{
                printf("Modulo Professor\n");
                break;
            }
             case 3:{
                printf("Modulo Disciplina\n");
                break; 
            }
            default:{
                printf("Opção invalida!\n");
            }
        }
    }

return 0;
}



int menugeral(){
    int opcao;
           
        printf("Projeto Escola\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");
        printf("0 - Sair\n");

        scanf("%d",  &opcao);
    return opcao;
}

int menualuno(){
    int opcaoAluno;
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Atualizar Aluno\n");
    printf("3 - Listar Aluno\n");
    printf("4 - Excluir Aluno\n");   
    printf("0 - Sair\n");
    scanf("%d",&opcaoAluno);
    return opcaoAluno;
                

}

int cadastrarAluno(Aluno lista_aluno[], int qtdAluno){

    printf("Cadastrar aluno\n");
    if(qtdAluno == TAM_ALUNO){
    return LISTA_CHEIA;
        }else{
            printf("Digite a matricula\n");
            int matricula;
            scanf("%d",&matricula);
            getchar();
                if(matricula < 0 ){
                printf("Matricula Inválida\n");
                return MATRICULA_INVALIDA;
                }else{
                    lista_aluno[qtdAluno].matricula = matricula;

                    printf("Digite o nome do aluno: ");
                    fgets(lista_aluno[qtdAluno].Nome, sizeof(lista_aluno[qtdAluno].Nome), stdin);
                    lista_aluno[qtdAluno].Nome[strcspn(lista_aluno[qtdAluno].Nome, "\n")] = '\0';

                    printf("Digite o CPF: ");
                    fgets(lista_aluno[qtdAluno].CPF, sizeof(lista_aluno[qtdAluno].CPF), stdin);
                    lista_aluno[qtdAluno].CPF[strcspn(lista_aluno[qtdAluno].CPF, "\n")] = '\0';

                    printf("Digite a data de nascimento (dd/mm/aaaa): ");
                    fgets(lista_aluno[qtdAluno].dataNascimento, sizeof(lista_aluno[qtdAluno].dataNascimento), stdin);
                    lista_aluno[qtdAluno].dataNascimento[strcspn(lista_aluno[qtdAluno].dataNascimento, "\n")] = '\0';

                    printf("Digite o sexo (M/F): ");
                    scanf(" %c", &lista_aluno[qtdAluno].sexo);
                    getchar();



                    lista_aluno[qtdAluno].ativo  = 1; 
                    return CAD_ALUNO_SUCESSO;
                }
        }


}

void listarAluno(Aluno lista_aluno[], int qtdAluno){

    printf("Listar aluno\n");
    if(qtdAluno == 0){
        printf("Lista de alunos vazia!\n");
        }else{for(int i=0; i<qtdAluno; i++){
            if(lista_aluno[i].ativo == 1){
                printf("\n--- Aluno %d ---\n", i + 1);
                printf("Matricula: %d\n", lista_aluno[i].matricula);
                printf("Nome: %s\n", lista_aluno[i].Nome);
                printf("CPF: %s\n", lista_aluno[i].CPF);
                printf("Data de Nascimento: %s\n", lista_aluno[i].dataNascimento);
                printf("Sexo: %c\n", lista_aluno[i].sexo);
            }
        }

    }
}

int atualizarAluno(Aluno lista_aluno[], int qtdAluno){
    
    printf("Atualizar Aluno\n");
    printf("Digite a matricula\n");
    int matricula;
    scanf("%d",&matricula);
    getchar();
    int achou = 0;
    if(matricula < 0 ){
        return MATRICULA_INVALIDA;
    }else{for(int i=0; i<TAM_ALUNO; i++){
        if(matricula == lista_aluno[i].matricula && lista_aluno[i].ativo){
            printf("Digite a nova matricula\n");
            int novamatricula;
            scanf("%d",&novamatricula);
            getchar();
            if(novamatricula < 0 ){
                return MATRICULA_INVALIDA;
            }

            lista_aluno[i].matricula = novamatricula;
            
            printf("Digite o novo nome: ");
            fgets(lista_aluno[i].Nome, sizeof(lista_aluno[i].Nome), stdin);
            lista_aluno[i].Nome[strcspn(lista_aluno[i].Nome,"\n")] = '\0';

            printf("Digite o novo CPF: ");
            fgets(lista_aluno[i].CPF, sizeof(lista_aluno[i].CPF), stdin);
            lista_aluno[i].CPF[strcspn(lista_aluno[i].CPF,"\n")] = '\0';

            printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
            fgets(lista_aluno[i].dataNascimento, sizeof(lista_aluno[i].dataNascimento), stdin);
            lista_aluno[i].dataNascimento[strcspn(lista_aluno[i].dataNascimento,"\n")] = '\0';

            printf("Digite o novo sexo (M/F): ");
            scanf(" %c", &lista_aluno[i].sexo);
            getchar();

            achou =1;
            break;
                }
            }
            if(achou){
                return ATUALIZACAO_ALUNO_SUCESSO;

            }else{
                return MATRICULA_INEXISTENTE;
                
                }
    }

}

int excluirAluno(Aluno lista_aluno[], int qtdAluno){
    printf("Excluir Aluno\n");
    printf("Digite a matricula\n");
    int matricula;
    scanf("%d",&matricula);
    getchar();
    int achou = 0;
    if(matricula < 0 ){
        return MATRICULA_INVALIDA;
    }else{for(int i=0; i<TAM_ALUNO; i++){
        if(matricula == lista_aluno[i].matricula && lista_aluno[i].ativo == 1){
            lista_aluno[i].ativo = -1;
            for(int j = i; j<qtdAluno -1 ; j++){

                lista_aluno[j] = lista_aluno[j+1];
                
                }
                achou =1;
                break;  
            }
        }
        if(achou){
        return EXCLUSAO_ALUNO_SUCESSO;
        }else{
            return MATRICULA_INEXISTENTE;
        }     
    }


}