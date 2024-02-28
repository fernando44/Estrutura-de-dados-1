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

/*
*inicio das informa�oes principais do programa
*/

void ordenarLista(lista *buble)
{
    int codigo=0;
    lista *aux;
    lista *temp;
    lista *ref;
    lista *tras;
    lista *fim;

    temp = buble;
    ref = buble;

    while(ref->prox != NULL)
    {
        temp=temp->prox;
        ref=temp->prox;


        if(temp->valor < ref->valor)
        {

            tras = temp->ant;
            aux = ref->prox ;


            temp->prox=aux;
            ref->ant=tras;
            ref->prox=temp;
            temp->ant = ref;

            aux->ant=temp;

            tras->prox=ref;
            codigo=1;
        }

        else
        {
            if(ref->prox !=NULL)
            {

            }
            else
            {

                break;

            }

        }

        if(codigo == 0 &&ref->prox ==NULL)
        {

        }
        else if(codigo == 1 && ref->prox != NULL)
        {

            temp = buble;
            ref = buble;
            codigo = 0;
        }
    }


}


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
void adicionarNumero(lista *addicionar)
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
    case 5:
        {
            exit(0); //sair do programa
        }
    case 4:
        {
            visuant(esc);
            break;
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
    printf("Digite\n1-para adicionar um numero\n2-para ver a lista\n3-para organizar a lista\n4-para ver a lista ao contrario\n5-para sair\nDigite: ");
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

