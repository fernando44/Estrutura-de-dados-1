//declaração das bibliotecas usadas no programa
#include<stdio.h>
#include<stdlib.h>
//fim das declaraçoes de bibliotecas

struct tabela //criação do struct para usar ponteiros
{
    int valor; //guarda o valor escolido pelo usuario

    struct tabela *prox; //utilizaçao do prox em apontamentos
    struct tabela *ant; //utilizaçao do ant em apontamentos
};
typedef struct tabela lista;

//declaraçao das variaveis globais
int add=0;
//fim da declaraçao das variaveis globais

// *******************************************************************************************************************

/*
*inicio das informaçoes principais do programa
*/

// *******************************************************************************************************************

//funçao void ordenarLista(coloca em ordem a lista toda por meio do selection sort)
void ordenarLista(lista *ordenar)
{
    //inicio das declarações de variaveis locais
    lista *referencia;
    lista *temp;
    lista *auxiliarDoReferencia;
    lista *auxiliarDotemp;
    lista *tempanterior;
    lista *fim;

    //fim das declarações de variaveis locais(ordenarLista)

    referencia=ordenar->prox;
    temp=referencia;

    while(referencia!=NULL)
    {
       while(temp!= NULL) //temp ate temp ser null
        {
            if(temp->valor < referencia->valor) //se encontrar um valor menor
            {
                if(referencia->prox==temp)
                {
                    auxiliarDoReferencia=referencia->ant;
                    auxiliarDotemp=temp->prox;

                    auxiliarDoReferencia->prox=temp;

                    if(auxiliarDotemp!=NULL)
                    {
                        auxiliarDotemp->ant=referencia;
                    }

                    temp->ant=auxiliarDoReferencia;
                    temp->prox=referencia;


                    referencia->prox=auxiliarDotemp;
                    referencia->ant=temp;

                    referencia=temp;
                }

                else{
                    tempanterior=temp->ant;
                    auxiliarDoReferencia=referencia->ant;
                    auxiliarDotemp=temp->prox;

                    temp->ant=auxiliarDoReferencia;
                    auxiliarDoReferencia->prox=temp;

                    tempanterior->prox=auxiliarDotemp;

                    referencia->ant=temp;
                    temp->prox=referencia;

                    referencia=temp;
                }
                //fim da troca do referencia com o menor
            }
            temp=temp->prox; //movimenta o temp uma caixa a frente
        }
        referencia=referencia->prox; //movimenta o referencia uma caixa a frente
        temp=referencia;
    }


    temp=ordenar->prox;
    fim = temp;

    while(fim->prox!=NULL)
    {
        fim=fim->prox;
    }

    while(temp->prox!=NULL)
    {
        printf("1 \n%i",temp->valor);
        system("pause");
        if(temp->valor %2 == 1 && temp!=fim)
        {

            auxiliarDotemp=temp;
            while(auxiliarDotemp->prox!=NULL)
            {
                auxiliarDotemp=auxiliarDotemp->prox;
            }

            referencia = temp->ant;
            auxiliarDoReferencia=temp->prox;


            referencia->prox=auxiliarDoReferencia;
            auxiliarDoReferencia->ant=referencia;


            temp->prox=NULL;
            temp->ant=auxiliarDotemp;
            auxiliarDotemp->prox=temp;
            temp=auxiliarDoReferencia;

        }
        else{
            if(temp==fim)
            {
                if(temp->valor %2 == 1)
                {

                    auxiliarDotemp=temp;
                    while(auxiliarDotemp->prox!=NULL)
                    {
                        auxiliarDotemp=auxiliarDotemp->prox;
                    }

                    referencia = temp->ant;
                    auxiliarDoReferencia=temp->prox;


                    referencia->prox=auxiliarDoReferencia;
                    auxiliarDoReferencia->ant=referencia;


                    temp->prox=NULL;
                    temp->ant=auxiliarDotemp;
                    auxiliarDotemp->prox=temp;
                    temp=auxiliarDoReferencia;

                }
                while(temp->prox!=NULL)
                {
                    temp=temp->prox;
                }
            }
            else if(temp != fim)
            {
                temp=temp->prox;
            }
        }
    }
}
/*
*fim do void ordenarLista
*/

void visuant(lista *vidu)
{
    lista *temp;
    temp=vidu;
    while(temp->prox!=NULL)
    {
        temp=temp->prox;
    }
    while(temp->ant!=NULL)
    {
        printf("\nNumero: %i\n\n",temp->valor); //printa o conteudo das caixas
        temp=temp->ant;
    }
    system("pause");
}

//funçao void visualizar(visualiza a lista inteira adicionada do inicio ao fim)
void visualizar(lista *visualizar)
{
    system("cls");
    lista *temp; //criação do temp(movimenta sobre as caixas e printa o conteudo)

    temp=visualizar; //coloca o temp junto à primeira caixa
    while(temp->prox != NULL)
    {
        temp=temp->prox; //anda com o temp nas caixas
        printf("\nNumero: %i\n\n",temp->valor); //printa o conteudo das caixas
    }
    system("pause"); //pausa para ver a lista
}
/*
*fim do void visualizar
*/

//funçao void adicionarNumeros(adiciona valores na fila por meio da entrada de numeros escolidos pelo usuario)
void adicionarNumero(lista*addicionar)
{
    system("cls");
    add++; //aumento na quantidade de itens na fila

    lista *temp; //criação do temp
    temp = addicionar; //localizaçao do temp no programa

    lista *aux; //criaçao do aux para auxiliar o temp->ant
    aux = addicionar;

    lista *novo =(lista*) malloc(sizeof(lista)); //criação do novo(guardar valor escolido pelo usuario)
    novo->prox = NULL;
    novo->ant = NULL;

    printf("informe um numero para adicionar: "); //mensagem visivel para o usuario
    scanf(" %i", &novo->valor); //guarda o valor digitado pelo usuario no novo (linha22)

    if(addicionar->prox!=NULL) //condição para caso o proximo da lista existir
    {
         while(temp->prox!=NULL) //levar o temp para o fim da lista
        {
            temp=temp->prox;
        }

    }
    temp->prox=novo; //inserçao do novo na sequencia existente
    novo->ant=temp; //ligação do novo ao anterior da sequencia
    novo->prox=NULL; //ligação do proximo do novo no null

}
/*
*fim do void adicionarNumero
*/

//funçao void escolha(switch das opçoes do void menu)
void escolha(lista *esc)
{
    int numero = 0; //criação do int numero(guarda o valor da escolha das opçoes)
    scanf("%i",&numero);

    switch(numero) //usa o int numero para ver qual opção do usuario sera escolida
    {
    case 1:
        {
            adicionarNumero(esc); //função para adicionar numero
            break;
        }
    case 2:
        {
            visualizar(esc); //funçao para visualizar a lista
            break;
        }
    case 3:
        {
            ordenarLista(esc); //funçao para colocar a lista em ordem
            break;
        }
    case 4:
        {
            visuant(esc);
            break;
        }
    case 0:
        {
            exit(0); //sair do programa
        }
    default:
        {
            //erroCategoria(1); //funçao para informar o tipo do erro ao usuario
            break;
        }
    }
    menu(esc); //chama a funçao menu para continuar em loop
}
/*
*fim do void escolha
*/

//funçao void menu(print das opçpoes na tela)
void menu(lista *esco)
{
    system("cls");
    printf("Digite\n1-para adicionar um numero\n2-para ver a lista\n3-para organizar a lista\n0-para sair do programa\nDigite:");
    escolha(esco); //chama a função escolha para ver qual funçao o usuario ira escolher
}
/*
*fim do void menu
*/

//funçao principal do programa (assecivel apenas 1 vez na inicialização do programa
main()
{
    lista *Lista =(lista*) malloc(sizeof(lista)); //criaçao da lista (caixa principal da sequncia)
    Lista->prox=NULL;
    Lista->ant=NULL;

    menu(Lista); ////chama a funçao menu para continuar em loop
}
/*
*fim do main /fim do programa
*/
