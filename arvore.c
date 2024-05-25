#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *direita, *esquerda;
} NoArv;

NoArv *criar() {
    NoArv *no;
    no = malloc(sizeof(NoArv));//altera o conte�do da raiz direto da main
    no->valor = 0;
    no->direita = NULL;
    no->esquerda = NULL;

    return no;
    
}

void inserir(NoArv **raiz, int num) {
    
    if(*raiz == NULL) {//verificando se o conteudo do ponteiro � nulo
        *raiz = criar();
        (*raiz)->valor = num;
    }
    else if ((*raiz)->valor != num){
        if(num < (*raiz)->valor) {
            inserir(&((*raiz)->esquerda), num); 
        } else {
            inserir(&((*raiz)->direita), num);
        }
    } 
    else {
        printf("\n\tNo pode inserir numero repetido\n");
    }
}

NoArv* buscar_v1(NoArv *raiz, int num) {
    if(raiz) {
        if (num == raiz->valor) 
            return raiz;
        else if(num < raiz->valor)
            return buscar_v1(raiz->esquerda, num);
        else
            return buscar_v1(raiz->direita, num);
    }
    return NULL;
}

void mostrar_v2 (NoArv *raiz) { //mostra arvore ordenada
    if(raiz) {
        mostrar_v2(raiz->esquerda);
        printf("\t%d ", raiz->valor);
        mostrar_v2(raiz->direita);
    }
}

void esvaziar(NoArv **raiz) { //esvazia a arvore
    if (*raiz != NULL) {
        esvaziar(&((*raiz)->esquerda));
        esvaziar(&((*raiz)->direita));
        free(*raiz);
        *raiz = NULL;
    }
}

int main () {

    NoArv *busca, *raiz = NULL;
    int opcao,valor;

    do {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\n\tDigite um valor:");
                scanf("%d",&valor);
                inserir(&raiz, valor);//o & pega o endere�o da variavel raiz, como a variavel raiz � um ponteiro, da certinho com o parametro **raiz
                break;
            case 2:
                printf("\n\tImpressao da arvore:\n");
                mostrar_v2(raiz);
                break;
            case 3:
                printf("\n\tDigite um valor a ser pesquisado:");
                scanf("%d", &valor);
                busca = buscar_v1(raiz, valor);
                         
                if(busca) {
                    printf("\n\tValor encontrado: %d\n", busca->valor);
                } else {
                    printf("\n\tValor no encontrado :/\n");
                }

                break;
            case 4:
                esvaziar(&raiz);
                printf("\n\tArvore esvaziada!\n");
                break;
            default:
                if (opcao != 0) {
                    printf("Digite uma opcao valida");
                }
        }
    } while (opcao != 0);

    return 0;
}