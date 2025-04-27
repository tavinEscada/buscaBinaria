#include <stdio.h>
#include <string.h>

typedef struct{
    int n;
    char nome[40];
    int pos;
} Livro;

typedef struct{
    char nome[40];
    int pos;
}Pacote;


void insertionSortLivro(Livro vet[], int tam){

    for(int i = 1; i < tam; i++){
        Livro chave = vet[i];
        
        int j = i - 1;

        while ((j >= 0) && (vet[j].n > chave.n)){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = chave;
    }
}

void InsertionSortPacote(Pacote lista[], int t){
    for(int i = 1; i < t; i++){
        Pacote chave = lista[i];
        
        int j = i - 1;

        while ((j >= 0) && strcmp(chave.nome, lista[j].nome) < 0){
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = chave;
    }
}

int buscaBiLivros(Livro vet[], int n, int max, int min){

    int meio = (min + max) / 2;

    if(vet[meio].n == n){
        return meio;
    }else{
        if(vet[meio].n > n){
            max = meio - 1;

        }
        if(vet[meio].n < n){
            min = meio + 1;
        }
        return buscaBiLivros(vet, n, max, min);
    }
}

int verificaVetorLivros(Livro vetorLivros[], int t, int num){
    for(int i = 0; i < t; i++){
        if(vetorLivros[i].n == num){
            return 1;
        }
    }
    return 0;
}

int buscaBiPacote(Pacote vet[], char *nome, int max, int min){

    int meio = (min + max) / 2;
    
    //nome igual ao presente no meio
    if(strcmp(nome, vet[meio].nome) == 0){
        return meio;
    }else{
        //nome antes do presente no meio
        if(strcmp(nome, vet[meio].nome) < 0){
            max = meio - 1;
        }
        //nome depois do presente no meio
        if(strcmp(nome, vet[meio].nome) > 0){
            min = meio + 1;
        }
    
        return buscaBiPacote(vet, nome, max, min);
    }
    
}

int verificaVetorPacotes(Pacote vetorPacotes[], int t, char nome[]){
    for(int i = 0; i < t; i++){
        if(strcmp(vetorPacotes[i].nome, nome) == 0){
            return 1;
        }
    }
    return 0;
}


int main(){

    int tipoOperacao = 0;

    printf("Digite o numero de acordo com a operacao desejada:\n");
    printf("1 - Aplicacao no exemplo de livros\n2 - Aplicacao no exemplo de pacotes\n");

    scanf("%d", &tipoOperacao);

    if(tipoOperacao == 1){
        int nLivros, nDesejado;
        printf("Insira o numero de livros:\n");
        scanf("%d", &nLivros);
        Livro livros[nLivros];

        for(int i = 0; i < nLivros; i++){
            int n;
            char nome[40];

            printf("Insira o numero seguido do nome do livro %d:\n", i+1);
            scanf("%d %s", &n, nome);
            Livro tal;
            tal.n = n;
            tal.pos = i;
            strcpy(tal.nome, nome);

            livros[i] = tal;

        }
        
        insertionSortLivro(livros, nLivros);

        printf("Insira o numero do livro desejado: ");
        scanf("%d", &nDesejado);

        if(verificaVetorLivros(livros, nLivros, nDesejado)){
            Livro livroDesejado = livros[buscaBiLivros(livros, nDesejado, nLivros, 0)];

            printf("Posicao no vetor (considerando 1 como o primeiro indice): %d, Livro: %s", livroDesejado.pos+1, livroDesejado.nome);
        }else{
            printf("Nao ha livro com esse numero");
        }
    }else{
        if(tipoOperacao != 2){
            printf("Operacao invalida.");
        }else{
            
            int n;
            printf("Informe o numero de pacotes:\n");
            scanf("%d", &n);
            Pacote lista[n];

            for(int i = 0; i < n; i++){
                Pacote p;
                p.pos = i;
                char ent[n];
                printf("Informe o nome do pacote %d:\n", i+1);
                scanf("%s", ent);
                strcpy(p.nome, ent);
                lista[i] = p;
            }

            InsertionSortPacote(lista, n);

            char nomeDesejado[40];
            printf("Informe o nome do pacote desejado: ");
            scanf("%s", nomeDesejado);

            if(verificaVetorPacotes(lista, n, nomeDesejado) == 1){
                Pacote pDesejado = lista[buscaBiPacote(lista, nomeDesejado, n, 0)];

                printf("Posicao (considerando 1 como primeiro indice): %d", pDesejado.pos+1);
            }else{
                printf("Nome nao encontrado.");
            }

        }
    }

    return 0;
}