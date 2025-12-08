#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COLLECTION_LENGTH 20

struct Book
{
    int code;
    char title[50];
    char author[30];
    char genre[30];
    int year;
    char publisher[30];
};

/*
    registerBooks:
    - Percorre o array de livros procurando uma posição ainda não utilizada,
      indicada pelo vetor "verifier".
    - Quando encontra uma posição livre, solicita ao usuário todas as
      informações do livro (código, título, autor, gênero, ano, editora).
    - Copia os dados para o vetor 'books' na posição encontrada.
    - Marca essa posição como ocupada em 'verifier'.
    - Incrementa a variável 'registeredBooks' para indicar quantos livros já
      foram cadastrados no total.
*/
void registerBooks(struct Book books[], bool verifier[], int *registeredBooks)
{

    for (int i = 0; i < sizeof(books); i++)
        {
            if (verifier[i] == false)
            {

                struct Book book;

                printf("Informe o codigo do livro: \n");
                scanf("%d", &book.code);
                fflush(stdin);

                printf("Informe o titulo do livro: \n");
                scanf("%s", &book.title);
                fflush(stdin);

                printf("Informe o autor do livro: \n");
                scanf("%s", &book.author);
                fflush(stdin);

                printf("Informe o genero do livro: \n");
                scanf("%s", &book.genre);
                fflush(stdin);

                printf("Informe o ano do livro: \n");
                scanf("%d", &book.year);
                fflush(stdin);

                printf("Informe a editora do livro: \n");
                scanf("%s", &book.publisher);
                fflush(stdin);

                books[i] = book;
                *registeredBooks = *registeredBooks + 1;
                verifier[i] = true;
                break;
            }
        }
}

/*
    printBooks:
    - Limpa a tela.
    - Percorre o array até o número de livros registrados.
    - Imprime, para cada livro, todos os seus campos (código, título, autor, etc.).
*/
void printBooks(struct Book books[], int *registeredBooks)
{

    system("cls");

    for (int i = 0; i < *registeredBooks; i++)
    {

        struct Book book = books[i];
        printf("%d : \n codigo: %d \n titulo: %s \n autor: %s \n genero: %s \n ano: %d \n editora: %s \n", i + 1, book.code, book.title, book.author, book.genre, book.year, book.publisher);
    }
}

/*
    searchBook:
    - Procura um livro no vetor comparando o campo 'code'.
    - Caso encontre, imprime todos os dados do livro.
    - Caso não encontre, imprime "Livro nao encontrado".
    - A variável 'found' serve para saber se algum livro foi encontrado
      durante o laço.
*/
void searchBook(struct Book books[], int code)
{

    bool found = false;

    for (int i = 0; i < sizeof(books); i++)
    {

        struct Book book;
        book = books[i];

        if (book.code == code)
        {
            found = true;
            printf("resultado : \n codigo: %d \n titulo: %s \n autor: %s \n genero: %s \n ano: %d \n editora: %s \n", book.code, book.title, book.author, book.genre, book.year, book.publisher);
        }
    }

    if (!found)
    {
        printf("Livro nao encontrado! \n");
    }
}

/*
    sortBooks:
    - Ordena os livros pelo campo 'year' em ordem decrescente.
    - Utiliza dois loops para comparar todos os pares possíveis.
    - Troca as posições quando o ano do livro atual é menor que o do próximo.
*/
void sortBooks(struct Book books[], int *registeredBooks)
{

    struct Book book;

    for (int i = 0; i < *registeredBooks; i++)
    {
        for (int j = i + 1; j < *registeredBooks; j++)
        {
            if (books[i].year < books[j].year)
            {
                book = books[i];
                books[i] = books[j];
                books[j] = book;
            }
        }
    }
}

int main(void)
{

    /*
        books:
        - Vetor que armazena os livros cadastrados.

        verifier:
        - Vetor de controle indicando quais posições do vetor "books" já foram usadas.
        - false = posição livre, true = ocupada.

        registeredBooks:
        - Contador de quantos livros já foram cadastrados até agora.
        - Evita percorrer posições ainda não preenchidas.

        option:
        - Armazena a escolha do usuário no menu.
    */
    struct Book books[COLLECTION_LENGTH];
    bool verifier[COLLECTION_LENGTH] = {false};
    int registeredBooks = 0;
    int option;

    do
    {
        printf("================BIBLIOTECA================ \n 1 - Cadastrar Livros \n 2 - Imprimir todos os livros \n 3 - Buscar livro \n 4 - Ordenar Livros (Ano publicacao) \n 5 - Sair \n");
        scanf("%d", &option);
        fflush(stdin);

        switch (option)
        {
        case 1:
            system("cls");
            registerBooks(books, verifier, &registeredBooks);

            break;

        case 2:
            system("cls");
            if (registeredBooks > 0)
            {
                printBooks(books, &registeredBooks);
            }
            else
            {
                printf("Ainda nao ha livros registrados! \n");
            }
            break;

        case 3:
            system("cls");
            if (registeredBooks > 0)
            {
                int code;
                printf("Digite o codigo do livro: ");
                scanf("%d", &code);
                searchBook(books, code);
            }
            else
            {
                printf("Ainda nao ha livros registrados! \n");
            }
            break;

        case 4:
            system("cls");
            if (registeredBooks > 0)
            {
                sortBooks(books, &registeredBooks);
            }
            else
            {
                printf("Ainda nao ha livros registrados! \n");
            }
            break;

        case 5:
            break;

        default:
            printf("Opcao invalida, apenas opcoes do menu sao validas \n");
        }
    } while (option != 5);

    return 0;
}