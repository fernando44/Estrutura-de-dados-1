//declara��o das bibliotecas usadas no programa
#include<stdio.h>
#include<stdlib.h>
//fim das declara�oes de bibliotecas

struct tabela //cria��o do struct para usar ponteiros
{
    int valor; //guarda o valor escolido pelo usuario

    struct tabela *prox; //utiliza�ao do prox em apontamentos
    struct tabela *ant; //utiliza�ao do ant em apontamentos
};
typedef struct tabela lista;

//declara�ao das variaveis globais
int add=0;
//fim da declara�ao das variaveis globais

// *******************************************************************************************************************

/*
*inicio das informa�oes principais do programa
*/

// *******************************************************************************************************************

//fun�ao void ordenarLista(coloca em ordem a lista toda por meio do selection sort)
void ordenarLista(lista *ordenar)
{
    //inicio das declara��es de variaveis locais
    lista *referencia;
    lista *temp;
    lista *auxiliarDoReferencia;
    lista *auxiliarDotemp;
    lista *tempanterior;
    lista *fim;

    //fim das declara��es de variaveis locais(ordenarLista)

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

//fun�ao void visualizar(visualiza a lista inteira adicionada do inicio ao fim)
void visualizar(lista *visualizar)
{
    system("cls");
    lista *temp; //cria��o do temp(movimenta sobre as caixas e printa o conteudo)

    temp=visualizar; //coloca o temp junto � primeira caixa
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

//fun�ao void adicionarNumeros(adiciona valores na fila por meio da entrada de numeros escolidos pelo usuario)
void adicionarNumero(lista*addicionar)
{
    system("cls");
    add++; //aumento na quantidade de itens na fila

    lista *temp; //cria��o do temp
    temp = addicionar; //localiza�ao do temp no programa

    lista *aux; //cria�ao do aux para auxiliar o temp->ant
    aux = addicionar;

    lista *novo =(lista*) malloc(sizeof(lista)); //cria��o do novo(guardar valor escolido pelo usuario)
    novo->prox = NULL;
    novo->ant = NULL;

    printf("informe um numero para adicionar: "); //mensagem visivel para o usuario
    scanf(" %i", &novo->valor); //guarda o valor digitado pelo usuario no novo (linha22)

    if(addicionar->prox!=NULL) //condi��o para caso o proximo da lista existir
    {
         while(temp->prox!=NULL) //levar o temp para o fim da lista
        {
            temp=temp->prox;
        }

    }
    temp->prox=novo; //inser�ao do novo na sequencia existente
    novo->ant=temp; //liga��o do novo ao anterior da sequencia
    novo->prox=NULL; //liga��o do proximo do novo no null

}
/*
*fim do void adicionarNumero
*/

//fun�ao void escolha(switch das op�oes do void menu)
void escolha(lista *esc)
{
    int numero = 0; //cria��o do int numero(guarda o valor da escolha das op�oes)
    scanf("%i",&numero);

    switch(numero) //usa o int numero para ver qual op��o do usuario sera escolida
    {
    case 1:
        {
            adicionarNumero(esc); //fun��o para adicionar numero
            break;
        }
    case 2:
        {
            visualizar(esc); //fun�ao para visualizar a lista
            break;
        }
    case 3:
        {
            ordenarLista(esc); //fun�ao para colocar a lista em ordem
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
            //erroCategoria(1); //fun�ao para informar o tipo do erro ao usuario
            break;
        }
    }
    menu(esc); //chama a fun�ao menu para continuar em loop
}
/*
*fim do void escolha
*/

//fun�ao void menu(print das op�poes na tela)
void menu(lista *esco)
{
    system("cls");
    printf("Digite\n1-para adicionar um numero\n2-para ver a lista\n3-para organizar a lista\n0-para sair do programa\nDigite:");
    escolha(esco); //chama a fun��o escolha para ver qual fun�ao o usuario ira escolher
}
/*
*fim do void menu
*/

//fun�ao principal do programa (assecivel apenas 1 vez na inicializa��o do programa
main()
{
    lista *Lista =(lista*) malloc(sizeof(lista)); //cria�ao da lista (caixa principal da sequncia)
    Lista->prox=NULL;
    Lista->ant=NULL;

    menu(Lista); ////chama a fun�ao menu para continuar em loop
}
/*
*fim do main /fim do programa
*/
