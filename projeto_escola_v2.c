#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_ALUNO 3
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
    char [11]; 
    char troca;//para fazer a Exclusao.

     
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
                if(matricula < 0 ){
                printf("Matricula Inválida\n");
                return MATRICULA_INVALIDA;
                }else{
                    lista_aluno[qtdAluno].matricula = matricula;
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
            if(lista_aluno[i].ativo == 1)    
                printf("matricula: %d\n",lista_aluno[i].matricula);
                /*printf("\n--- Aluno %d ---\n", i + 1);
                printf("Matricula: %d\n", lista_aluno[i].matricula);
                printf("Nome: %s\n", lista_aluno[i].nome);
                printf("CPF: %s\n", lista_aluno[i].cpf);
                printf("Data de Nascimento: %s\n", lista_aluno[i].dataNascimento);
                printf("Sexo: %c\n", lista_aluno[i].sexo);*/
                }
    }

}

int atualizarAluno(Aluno lista_aluno[], int qtdAluno){
    
    printf("Atualizar Aluno\n");
    printf("Digite a matricula\n");
    int matricula;
    scanf("%d",&matricula);
    int achou = 0;
    if(matricula < 0 ){
        return MATRICULA_INVALIDA;
    }else{for(int i=0; i<TAM_ALUNO; i++){
        if(matricula == lista_aluno[i].matricula && lista_aluno[i].ativo){
            printf("Digite a nova matricula\n");
            int novamatricula;
            scanf("%d",&novamatricula);
            if(novamatricula < 0 ){
                return MATRICULA_INVALIDA;
            }

            lista_aluno[i].matricula = novamatricula;
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
    int achou = 0;
    if(matricula < 0 ){
        return MATRICULA_INVALIDA;
    }else{for(int i=0; i<TAM_ALUNO; i++){
        if(matricula == lista_aluno[i].matricula){
            lista_aluno[i].ativo = -1;
            for(int j = i; j<qtdAluno -1 ; j++){
                lista_aluno[j].matricula = lista_aluno[j+1].matricula;
                lista_aluno[j].troca = lista_aluno[j+1].troca;
                lista_aluno[j].ativo = lista_aluno[j+1].ativo;
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
