#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define TAM_ALUNO 10
#define TAM_PROFESSOR 10
#define TAM_DISCIPLINA 10
#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZACAO_ALUNO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_ALUNO_SUCESSO -6
#define BISSEXTO -7
#define NAO_BISSEXTO -8
#define CAD_PROFESSOR_SUCESSO -9
#define ATUALIZACAO_PROFESSOR_SUCESSO -10
#define EXCLUSAO_PROFESSOR_SUCESSO -11
#define CAD_DISCIPLINA_SUCESSO -12
#define ATUALIZACAO_DISCIPLINA_SUCESSO -13
#define EXCLUSAO_DISCIPLINA_SUCESSO -14
#define COD_INVALIDO -15
#define COD_JA_EXISTE -16
#define DISCIPLINA_INE -17
typedef struct aluno{
    int matricula;
    char sexo;
    int ativo;
    char Nome[50];
    char CPF[15];
    char dataNascimento[11]; 
}Aluno;

typedef struct Professor{
    int matricula;
    int ativo;
    char Nome[50];
    char CPF[15];
    char dataNascimento[11];
    char sexo;
}Professor;

typedef struct Disciplina{
    int codigo;
    int semestre;
    int ativo;
    int matriculaProfessor;
    char Nome[50];
}Disciplina;

int menugeral();
int menuProfessor();
int menualuno();
int menuDisciplina();
int cadastrarAluno(Aluno lista_aluno[], int qtdAluno);
int cadastrarProfessor(Professor lista_professor[], int qtdProfessor);
int cadastrarDisciplina(Disciplina lista_disciplina[], int qtdDisciplina);
void listarAluno(Aluno lista_aluno[], int qtdAluno);
void listarProfessor(Professor lista_professor[], int qtdProfessor);
void listarDisciplina(Disciplina lista_disciplina[], int qtdDisciplina);
int atualizarAluno(Aluno lista_aluno[], int qtdAluno);
int atualizarProfessor(Professor lista_professor[], int qtdProfessor);
int atualizarDisciplina(Disciplina lista_disciplina[], int qtdDisciplina);
int excluirAluno(Aluno lista_aluno[], int qtdAluno);
int excluirProfessor(Professor lista_professor[], int qtdProfessor);
int excluirDisciplina(Disciplina lista_disciplina[], int qtdDisciplina);
int bissexto(int ano);
int validarData(char *data);
int validarCPF(char *cpf);
int validadorSEXO(char sexo);

int main(){


    int opcao;
    int sair = 0;
    int qtdAluno = 0;
    int qtdprofessor = 0;
    int qtdDisciplina = 0;
    Aluno lista_aluno[TAM_ALUNO];
    Professor lista_professor[TAM_PROFESSOR];
    Disciplina lista_disciplina[TAM_DISCIPLINA];

    while(!sair){

        opcao = menugeral();
 
        switch(opcao){
            case 0:{
                sair = 1;
                break; 
            }
             case 1:{
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
                int sairProfessor = 0;
                int opcaoProfessor;

                while(!sairProfessor){
                    opcaoProfessor = menuProfessor();

                    switch(opcaoProfessor){

                        case 0:{
                            sairProfessor = 1;
                            break;
                        }

                        case 1:{
                            int retorno = cadastrarProfessor(lista_professor, qtdprofessor);
                            if(retorno == LISTA_CHEIA){
                                printf("Lista de professores cheia!\n");
                            }else if(retorno == MATRICULA_INVALIDA){
                                printf("Matricula inválida!");
                            }else printf("Professor cadastrado com sucesso!\n");
                            qtdprofessor++;
                            break;
                        }

                        case 2:{
                            int retorno = atualizarProfessor(lista_professor, qtdprofessor);
                            if(retorno == MATRICULA_INVALIDA){
                                printf("Matricula inválida!\n");
                            }else if(retorno == MATRICULA_INEXISTENTE){
                                printf("Matricula inexistente!\n");
                            }else printf("Professor atualizado com sucesso!\n");

                            break;
                        }

                        case 3:{

                            listarProfessor(lista_professor, qtdprofessor);
                            break;
                        }

                        case 4:{
                        int retorno = excluirProfessor(lista_professor, qtdprofessor); 

                        if(retorno == EXCLUSAO_PROFESSOR_SUCESSO){
                            printf("Excluindo....\n");
                            printf("Professor excluido com sucesso\n");
                            qtdprofessor --;
                            }
                            else if(retorno == MATRICULA_INVALIDA){
                            printf("Matricula invalida\n");
                            }else{
                            printf("Matricula inexistente!\n");
                            }
                            break;
                        }
                        
                        default:{
                            printf("Opção inválida!");
                        }

                    }

                }

                break;
            }
             case 3:{              
                printf("Modulo Disciplina\n");
                int opcaoDisciplina;
                int sairDisciplina = 0;

                

                while(!sairDisciplina){

                    opcaoDisciplina = menuDisciplina();
                    switch (opcaoDisciplina){
                    case 0:{

                        sairDisciplina= 1;

                        break;
                    }
                    case 1:{

                        int retorno = cadastrarDisciplina(lista_disciplina, qtdDisciplina);
                        if(retorno == LISTA_CHEIA){
                            printf("Lista de disciplina cheia!\n");
                            }else if(retorno == COD_INVALIDO){
                            printf("Codigo invalido.\n");
                            }
                            
                            else{
                                printf("Disciplina cadastrada com sucesso!\n");
                            qtdDisciplina ++;
                            }
                        break;
                    }
                    case 2:{

                         int retorno = atualizarDisciplina(lista_disciplina, qtdDisciplina);
                        if (retorno == COD_INVALIDO){
                            printf("codigo inválido!\n");
                        }else if(retorno == DISCIPLINA_INE){
                            printf("Disciplina inexistente!\n");
                        }else{
                            printf("Disciplina atualizado com sucesso!\n");
                        }
                        break;
                    }
                    case 3:{

                            listarDisciplina(lista_disciplina, qtdDisciplina);
                        break;
                    }
                    case 4:{
                        int retorno = excluirDisciplina(lista_disciplina, qtdDisciplina);
                        if(retorno == COD_INVALIDO){
                            printf("Codigo invalido!\n");
                        }else if(retorno == DISCIPLINA_INE){
                            printf("Disciplina inexistente!\n");
                        }else{
                            printf("Disciplina excluida com sucesso\n");
                            qtdDisciplina --;
                        }
                        
                        break;
                    }

                    default:{
                        printf("Opcao inválida!\n");
                    }
                        
                }


                break; 
            }
                


        }
    }
}

return 0;
}



int menugeral(){
    int opcao;
           
        printf("Projeto Escola\n");
        printf("*****Escolha um Módulo*****\n");
        printf("1 - Módulo Aluno\n");
        printf("2 - Módulo Professor\n");
        printf("3 - Módulo Disciplina\n");
        printf("0 - Sair\n");
        printf("***************************\n");
        scanf("%d",  &opcao);
    return opcao;
}

int menualuno(){
    int opcaoAluno;
    printf("*****Menu aluno*****\n");
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

                    while(1){
                        printf("Digite o CPF: ");
                        fgets(lista_aluno[qtdAluno].CPF, sizeof(lista_aluno[qtdAluno].CPF), stdin);
                        lista_aluno[qtdAluno].CPF[strcspn(lista_aluno[qtdAluno].CPF, "\n")] = '\0';

                        if(validarCPF(lista_aluno[qtdAluno].CPF)){
                            break;
                        }else{
                            printf("CPF inválido! Tente novamente!\n");
                        }


                    }
                    while(1){

                        printf("Digite a data de nascimento (dd/mm/aaaa): ");
                        fgets(lista_aluno[qtdAluno].dataNascimento, sizeof(lista_aluno[qtdAluno].dataNascimento), stdin);
                        lista_aluno[qtdAluno].dataNascimento[strcspn(lista_aluno[qtdAluno].dataNascimento, "\n")] = '\0';

                        if(validarData(lista_aluno[qtdAluno].dataNascimento)){
                            break;
                        }else{
                            printf("Data inválda ou formato incorreto tente novamente.\n");
                        }


                    }

                    while(1){
                        printf("Digite o sexo (M/F): ");
                        scanf(" %c", &lista_aluno[qtdAluno].sexo);
                        getchar();

                        if(validadorSEXO(lista_aluno[qtdAluno].sexo)){
                            break;
                        }
                        printf("Sexo inválido! Tente novamente!\n");
                    }


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
    
    printf("Atualizando Aluno...\n");
    printf("Digite a matricula\n");
    int matricula;
    scanf("%d",&matricula);
    getchar();
    int achou = 0;
    if(matricula < 0 ){
        return MATRICULA_INVALIDA;
    }else{for(int i=0; i<qtdAluno; i++){
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
            
            while(1){
                printf("Digite o novo CPF: ");
                fgets(lista_aluno[i].CPF, sizeof(lista_aluno[i].CPF), stdin);
                lista_aluno[i].CPF[strcspn(lista_aluno[i].CPF,"\n")] = '\0';

                if(validarCPF(lista_aluno[i].CPF)){
                    break;
                }else{
                    printf("CPF inválido! Tente novamente!\n");
                }
            }

            while(1){
                printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
                fgets(lista_aluno[i].dataNascimento, sizeof(lista_aluno[i].dataNascimento), stdin);
                lista_aluno[i].dataNascimento[strcspn(lista_aluno[i].dataNascimento, "\n")] = '\0';
                
                if(validarData(lista_aluno[i].dataNascimento)){
                    break;
                }else{
                    printf("Data inválida ou formato incorreto! Tente novamente.\n");
                }
            
            }

            while(1){

                printf("Digite o novo sexo (M/F): ");
                scanf(" %c", &lista_aluno[i].sexo);
                getchar();

                if(validadorSEXO(lista_aluno[i].sexo)){
                break;    
                }
                printf("Sexo inválido! Tente novamente!");
            }
            achou =1;
            break;
    }
        }
            if(achou){
                return ATUALIZACAO_ALUNO_SUCESSO;

            }
            else{
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
    }else{for(int i=0; i<qtdAluno; i++){
        if(matricula == lista_aluno[i].matricula && lista_aluno[i].ativo == 1){
            lista_aluno[i].ativo = -1;
            for(int j = i; j< qtdAluno -1 ; j++){

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

int bissexto(int ano){

    if((ano%4 == 0 && ano % 100 != 0) || (ano% 400 == 0)){
        return BISSEXTO;
    }
    return NAO_BISSEXTO;
}

int validarData(char *data){
    int dia, mes, ano;

    if(strlen(data) != 10){
        return 0;
    }
    for(int i=0; i<10;i++){
        if(i==2 || i==5){
            if(data[i] != '/'){
                return 0;
            }
        }else{
            if(!isdigit(data[i])){
                return 0;
            }
        }
    }
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    if(ano<1900||ano>2025){
        return 0;
    }
    if(mes<1|| mes > 12){
        return 0;
    }

    int dia_no_mes;

    if(mes == 2){
        dia_no_mes = (bissexto(ano) == BISSEXTO) ? 29:28;
    }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        dia_no_mes = 30;
    }else{
        dia_no_mes = 31;
    }

    if(dia < 1 || dia> dia_no_mes){
        return 0;
    }

    return 1;


}

int validarCPF(char *cpf){

    char cpf_limpo[12];
    int j = 0;
    for(int i = 0; cpf[i]!='\0';i++){
        if(isdigit(cpf[i])){
            if( j < 11){
                cpf_limpo[j] = cpf[i];
                j++;
            }
        }
    }

    cpf_limpo[j] = '\0';
    
    if(j != 11 || strlen(cpf_limpo) != 11){
        return 0;
    }
    int todos_iguais = 1;
    for(int i = 1; i < 11; i++){
        if(cpf_limpo[i] != cpf_limpo[0]){
            todos_iguais = 0;
            break;
        }
    }

    if(todos_iguais){
        return 0;
    }

    int soma = 0;
    for(int i = 0; i < 9; i++){
        soma += (cpf_limpo[i]- '0') * (10-i); 
    }
    
    int dv1 = (soma *10) %11;
    if(dv1 == 10){
        dv1 = 0;
    }

    if(dv1 != (cpf_limpo[9] - '0')){
        return 0;
    }

    soma = 0;
    for(int i = 0; i < 10; i++){
        soma +=(cpf_limpo[i] - '0') * (11 - i);
    }

    int dv2 = (soma * 10) % 11;
    if(dv2 == 10){
        dv2 = 0;
    }

    if(dv2 != (cpf_limpo[10] - '0')){
        return 0;
    }

    return 1;
}

int validadorSEXO(char sexo){

    sexo = toupper(sexo);
    if(sexo =='M' || sexo == 'F'){
        return 1;
    }
    return 0;
}

//modulo professor 

int menuProfessor(){
    int opcaoProfessor;
    printf("*****Menu Professor*****\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Atualizar Professor\n");
    printf("3 - Listar Professor\n");
    printf("4 - Excluir Professor\n");   
    printf("0 - Voltar ao menu principal.\n");
    scanf("%d",&opcaoProfessor);
    return opcaoProfessor;
}

int cadastrarProfessor(Professor lista_professor[], int qtdProfessor){
     printf("Cadastrar Professor\n");
    if(qtdProfessor == TAM_PROFESSOR){
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
                    lista_professor[qtdProfessor].matricula = matricula;

                    printf("Digite o nome do Professor: ");
                    fgets(lista_professor[qtdProfessor].Nome, sizeof(lista_professor[qtdProfessor].Nome), stdin);
                    lista_professor[qtdProfessor].Nome[strcspn(lista_professor[qtdProfessor].Nome, "\n")] = '\0';

                    while(1){
                        printf("Digite o CPF: ");
                        fgets(lista_professor[qtdProfessor].CPF, sizeof(lista_professor[qtdProfessor].CPF), stdin);
                        lista_professor[qtdProfessor].CPF[strcspn(lista_professor[qtdProfessor].CPF, "\n")] = '\0';

                        if(validarCPF(lista_professor[qtdProfessor].CPF)){
                            break;
                        }else{
                            printf("CPF inválido! Tente novamente!\n");
                        }


                    }
                    while(1){

                        printf("Digite a data de nascimento (dd/mm/aaaa): ");
                        fgets(lista_professor[qtdProfessor].dataNascimento, sizeof(lista_professor[qtdProfessor].dataNascimento), stdin);
                        lista_professor[qtdProfessor].dataNascimento[strcspn(lista_professor[qtdProfessor].dataNascimento, "\n")] = '\0';

                        if(validarData(lista_professor[qtdProfessor].dataNascimento)){
                            break;
                        }else{
                            printf("Data inválda ou formato incorreto tente novamente.\n");
                        }


                    }

                    while(1){
                        printf("Digite o sexo (M/F): ");
                        scanf(" %c", &lista_professor[qtdProfessor].sexo);
                        getchar();

                        if(validadorSEXO(lista_professor[qtdProfessor].sexo)){
                            break;
                        }
                        printf("Sexo inválido! Tente novamente!\n");
                    }


                    lista_professor[qtdProfessor].ativo  = 1; 
                    return CAD_PROFESSOR_SUCESSO;
                }
        }

}


int atualizarProfessor(Professor lista_professor[], int qtdProfessor){
        printf("Atualizando Professor...\n");
    printf("Digite a matricula\n");
    int matricula;
    scanf("%d",&matricula);
    getchar();
    int achou = 0;
    if(matricula < 0 ){
        return MATRICULA_INVALIDA;
    }else{for(int i=0; i<qtdProfessor; i++){
        if(matricula == lista_professor[i].matricula && lista_professor[i].ativo){
            printf("Digite a nova matricula\n");
            int novamatricula;
            scanf("%d",&novamatricula);
            getchar();
            if(novamatricula < 0 ){
                return MATRICULA_INVALIDA;
            }

            lista_professor[i].matricula = novamatricula;
            
            printf("Digite o novo nome: ");
            fgets(lista_professor[i].Nome, sizeof(lista_professor[i].Nome), stdin);
            lista_professor[i].Nome[strcspn(lista_professor[i].Nome,"\n")] = '\0';
            
            while(1){
                printf("Digite o novo CPF: ");
                fgets(lista_professor[i].CPF, sizeof(lista_professor[i].CPF), stdin);
                lista_professor[i].CPF[strcspn(lista_professor[i].CPF,"\n")] = '\0';

                if(validarCPF(lista_professor[i].CPF)){
                    break;
                }else{
                    printf("CPF inválido! Tente novamente!\n");
                }
            }

            while(1){
                printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
                fgets(lista_professor[i].dataNascimento, sizeof(lista_professor[i].dataNascimento), stdin);
                lista_professor[i].dataNascimento[strcspn(lista_professor[i].dataNascimento, "\n")] = '\0';
                
                if(validarData(lista_professor[i].dataNascimento)){
                    break;
                }else{
                    printf("Data inválida ou formato incorreto! Tente novamente.\n");
                }
            
            }

            while(1){

                printf("Digite o novo sexo (M/F): ");
                scanf(" %c", &lista_professor[i].sexo);
                getchar();

                if(validadorSEXO(lista_professor[i].sexo)){
                break;    
                }
                printf("Sexo inválido! Tente novamente!");
            }
            achou =1;
            break;
    }
        }
            if(achou){
                return ATUALIZACAO_PROFESSOR_SUCESSO;

            }
            else{
                return MATRICULA_INEXISTENTE;    
            }
    }
}

void listarProfessor(Professor lista_professor[], int qtdProfessor){

    printf("Listando Pofessores\n");
    if(qtdProfessor == 0){
        printf("Lista de professores vazia!\n");
        }else{for(int i=0; i<qtdProfessor; i++){
            if(lista_professor[i].ativo == 1){
                printf("\n--- Professor %d ---\n", i + 1);
                printf("Matricula: %d\n", lista_professor[i].matricula);
                printf("Nome: %s\n", lista_professor[i].Nome);
                printf("CPF: %s\n", lista_professor[i].CPF);
                printf("Data de Nascimento: %s\n", lista_professor[i].dataNascimento);
                printf("Sexo: %c\n", lista_professor[i].sexo);
            }
        }

    }
}

int excluirProfessor(Professor lista_professor[], int qtdprofessor){

    printf("Excluir Professor\n");
    printf("Digite a matricula\n");
    int matricula;
    scanf("%d",&matricula);
    getchar();
    int achou = 0;
    if(matricula < 0 ){
        return MATRICULA_INVALIDA;
    }else{for(int i=0; i<qtdprofessor; i++){
        if(matricula == lista_professor[i].matricula && lista_professor[i].ativo == 1){
            lista_professor[i].ativo = -1;
            for(int j = i; j< qtdprofessor -1 ; j++){

                lista_professor[j] = lista_professor[j+1];
                
                }
                achou =1;
                break;  
            }
        }
        if(achou){
        return EXCLUSAO_PROFESSOR_SUCESSO;
        }else{
            return MATRICULA_INEXISTENTE;
        }     
    }
}

//modulo Disciplina

int menuDisciplina(){
    int opcaoDisciplina;
    printf("*****Menu Disciplina*****\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Atualizar Disciplina\n");
    printf("3 - Listar Disciplina\n");
    printf("4 - Excluir Disciplina\n");   
    printf("0 - Voltar ao menu principal.\n");
    scanf("%d",&opcaoDisciplina);
    getchar();
    return opcaoDisciplina;
}

int cadastrarDisciplina(Disciplina lista_disciplina[], int qtdDisciplina){

    int codigo;

    if(qtdDisciplina == TAM_DISCIPLINA){
        return LISTA_CHEIA;
    }

    printf("digite o codigo da Disciplina\n");
    scanf("%d", &codigo);
    getchar();

    if(codigo < 0){
        printf("Codigo inválido!\n");
        return COD_INVALIDO;
    }

    for(int i = 0; i< qtdDisciplina; i++){
        if(codigo == lista_disciplina[i].codigo && lista_disciplina[i].ativo == 1){
            printf("Error codigo ja cadastrado!\n");
            return COD_JA_EXISTE;
    
        }
    }

    lista_disciplina[qtdDisciplina].codigo = codigo;

    printf("Digite o nome da disciplina: ");
    fgets(lista_disciplina[qtdDisciplina].Nome, sizeof(lista_disciplina[qtdDisciplina].Nome), stdin);
    lista_disciplina[qtdDisciplina].Nome[strcspn(lista_disciplina[qtdDisciplina].Nome, "\n")] = '\0'; 
    
    printf("Digite o semestre (apenas numeros): ");
    scanf("%d", &lista_disciplina[qtdDisciplina].semestre);
    getchar();
    
    printf("Digite a matricula do professor responsavel: ");
    scanf("%d", &lista_disciplina[qtdDisciplina].matriculaProfessor);
    getchar();

    lista_disciplina[qtdDisciplina].ativo = 1;
    return CAD_DISCIPLINA_SUCESSO;

}

int atualizarDisciplina(Disciplina lista_disciplina[], int qtdDisciplina) {

    printf("Atualizar Disciplina\n");
    printf("Digite o codigo da disciplina a ser atualizada:\n");
    int codigoAtual;
    scanf("%d", &codigoAtual);
    getchar(); 

    int achou = 0;

    if (codigoAtual < 0) {
        printf("Codigo invalido (deve ser positivo).\n");
        return COD_INVALIDO;
    } else {
  
        for (int i = 0; i < qtdDisciplina; i++) {
            
            if (codigoAtual == lista_disciplina[i].codigo && lista_disciplina[i].ativo == 1){

                printf("Disciplina encontrada: %s\n", lista_disciplina[i].Nome);
                printf("--- Insira os novos dados ---\n");

                int novoCodigo;
                printf("Digite o NOVO codigo da disciplina:\n");
                scanf("%d", &novoCodigo);
                getchar();
                if (novoCodigo < 0) {
                    printf("Novo codigo invalido (deve ser positivo).\n");
                    return COD_INVALIDO;
                }

                
                for (int j = 0; j < qtdDisciplina; j++) {
                    if (i != j && novoCodigo == lista_disciplina[j].codigo && lista_disciplina[j].ativo == 1) {
                         printf("Erro: O novo codigo (%d) ja pertence a outra disciplina ativa (%s).\n", novoCodigo, lista_disciplina[j].Nome);
                         return COD_JA_EXISTE;
                    }
                }


                char novoNome[50];
                printf("Digite o NOVO nome da disciplina: ");
                fgets(novoNome, sizeof(novoNome), stdin);
                novoNome[strcspn(novoNome, "\n")] = '\0';

                int novoSemestre;
                printf("Digite o NOVO semestre (apenas numeros): ");
                scanf("%d", &novoSemestre);
                getchar();
                

                int novaMatriculaProfessor;
                printf("Digite a matricula do NOVO professor responsavel: ");
                scanf("%d", &novaMatriculaProfessor);
                getchar();
                
                lista_disciplina[i].codigo = novoCodigo;
                strcpy(lista_disciplina[i].Nome, novoNome);
                lista_disciplina[i].semestre = novoSemestre;
                lista_disciplina[i].matriculaProfessor = novaMatriculaProfessor;
                

                achou = 1;
                break; 
            }
        } 

        if (achou) {
            return ATUALIZACAO_DISCIPLINA_SUCESSO;
        } else {
            printf("Disciplina com codigo %d nao encontrada ou inativa.\n", codigoAtual);
            return DISCIPLINA_INE;
        }
    } 
}


void listarDisciplina(Disciplina lista_disciplina[], int qtdDisciplina){

 printf("Listando Disciplina\n");
    if(qtdDisciplina == 0){
        printf("Lista de disciplina vazia!\n");
        }else{for(int i=0; i<qtdDisciplina; i++){
            if(lista_disciplina[i].ativo == 1){
                printf("\n--- Professor %d ---\n", i + 1);
                printf("Codigo: %d\n", lista_disciplina[i].codigo);
                printf("Nome: %s\n", lista_disciplina[i].Nome);
                printf("Semestre: %d\n", lista_disciplina[i].semestre);
                printf("matricula do professor responsavel: %d\n", lista_disciplina[i].matriculaProfessor);
            
            }
        }

    }

}

int excluirDisciplina(Disciplina lista_disciplina[], int qtdDisciplina){



    printf("Excluir Disciplina\n");
    printf("Digite o codigo da disciplina:\n");
    int codigo;
    scanf("%d",&codigo);
    getchar();
    int achou = 0;
    if(codigo < 0 ){
        return COD_INVALIDO;
    }else{for(int i=0; i<qtdDisciplina; i++){
        if(codigo == lista_disciplina[i].codigo && lista_disciplina[i].ativo == 1){
            lista_disciplina[i].ativo = -1;
            for(int j = i; j< qtdDisciplina -1 ; j++){

                lista_disciplina[j] = lista_disciplina[j+1];
                
                }
                achou =1;
                break;  
            }
        }
        if(achou){
        return EXCLUSAO_PROFESSOR_SUCESSO;
        }else{
            return MATRICULA_INEXISTENTE;
        }     
    }

}