#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Definindo a estrutura da lista

struct no{
    int dado;
    struct no *proximo;
 
};



// definindo as variáveis

typedef no *ptr_no;
ptr_no lista;
int op;

//prototipação

void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remover (ptr_no lista);
void lista_mostrar(ptr_no lista);

//função principal 

int main (){
    //inicializando máquina de números randômicos 
    srand(time(NULL));
    op = 1;
    //CRIANDO O PRIMEIRO NÓ DA LISTA
    lista= (ptr_no) malloc(sizeof(no));
    lista-> dado = 0;
    lista->proximo = NULL;
//LAÇO PRINCIPAL
while (op!=0){
    system ("cls");
    menu_mostrar();
    scanf( "%d", &op);
    menu_selecionar(op);
}
system ("Pause");
return(0);
}
//mostra o menu de opções

void menu_mostrar(){
    lista_mostrar (lista);
    printf("\n Escolha umas das opcoes");
    printf("\n 1- Inserir no final da lista");
    printf("\n 2- Remover um item da lista");
    printf("0-Sair");
}

//Executa a opção escolhida do menu
void menu_selecionar(int op){
    switch (op){
        case 1 :
        lista_inserir(lista);
        break;
        case 2 : 
        lista_remover(lista);
        break;
    }
}

//insere um elemento no final da lista

void lista_inserir(ptr_no lista){
    while(lista-> proximo != NULL){
        lista = lista-> proximo;
    }
    lista-> proximo = (ptr_no)malloc(sizeof(no));
    lista= lista-> proximo;
    lista-> dado = rand()%100;
    lista-> proximo = NULL;
}
//REMOVE UM ELEMENTO DA LISTA
void lista_remover(ptr_no lista){
    int dado;
    ptr_no atual;
    atual = (ptr_no)malloc(sizeof(no));
    printf("\n \n Escolha um dos itens : \n");
    scanf("%d", &dado);
    while ((lista -> dado != dado)){
        if (lista -> proximo == NULL){
            break;
        }
        atual = lista;
        lista = lista -> proximo;
    }
    if (lista -> dado == dado){
        atual -> proximo = lista -> proximo;
    }
}
//Desenha o conteúdo da lista na tela

void lista_mostrar(ptr_no lista){
    system("cls");
    while(1){
        printf("%d, ", lista-> dado);
        if(lista-> proximo == NULL){
            break;
        }
        lista = lista -> proximo;
    }
}

//desenha o conteúdo da lista na tela
void lista_mostrar_2(ptr_no lista){
    system ("cls");
    while(lista-> proximo != NULL){
        printf("%d, ", lista-> dado);
        lista = lista-> proximo;
    }
    printf("%d,", lista-> dado);
}





  