#include <stdio.h>
#include <conio.h>
#include <string.h>
#define DATA_FILE "books.dat"
#define Export_FILE "books.txt"

struct Book
{
    int id;
    char genre[50];
    char title[50];
    char author[50];
};

struct Book books[100];
int bookCount = 0;
int idDecider = 1000;
int maxBooks = 100;

// declaring all functions

void menu();
void loadBooks();
void addBook();
void saveBooks();
void viewBook();
void searchBook();
void searchById();
void searchByTitle();
void searchByAuthor();
void deleteBook();
void updateBook();
void sortBooks();
void sortId();
void sortTitle();
void sortAuthor();

// main function

void main()
{
    loadBooks();
    menu();
}

// defining functions of all the body

void menu()
{
    int userChoice;

    printf("========= LIBRARY MANAGEMENT SYSTEM =========\n\n");

    do
    {
        printf("\nSelect an Option to Proceed\n\n");

        printf("1) Add a Book\n");
        printf("2) View All Books\n");
        printf("3) Search Book\n");
        printf("4) Delete a Book(ID Required)\n");
        printf("5) Update a Book Credentials(ID Required)\n");
        printf("6) Sort Books\n");
        printf("0) EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        if (userChoice == 1)
        {
            addBook();
        }
        else if (userChoice == 2)
        {
            viewBook();
        }

        else if (userChoice == 3)
        {
            searchBook();
        }

        else if (userChoice == 4)
        {
            deleteBook();
        }

        else if (userChoice == 5)
        {
            updateBook();
        }

        else if (userChoice == 6)
        {
            sortBooks();
        }

    } while (userChoice);
}

void loadBooks()
{
    FILE *fp = fopen(DATA_FILE, "rb");

    if (fp == NULL)
    {
        printf("File error.\n");
        return;
    }

    fread(&bookCount, sizeof(int), 1, fp);
    fread(&idDecider, sizeof(int), 1, fp);
    fread(books, sizeof(struct Book), bookCount, fp);

    fclose(fp);
}

void addBook()
{

    if (bookCount == maxBooks)
    {
        printf("Maximum Number of storage for book has been reached, NO more books can be added at this point\nplease Delete a book or increase storage to add a book!");
    }
    else
    {

        printf("Enter the following credentials regarding the book:- \n");

        getchar();
        printf("Title:- ");
        fgets(books[bookCount].title, 50, stdin);
        books[bookCount].title[strcspn(books[bookCount].title, "\n")] = '\0'; // removing the extra line added by user as input

        printf("Author:- ");
        fgets(books[bookCount].author, 50, stdin);
        books[bookCount].author[strcspn(books[bookCount].author, "\n")] = '\0';

        printf("Genre:- ");
        fgets(books[bookCount].genre, 50, stdin);
        books[bookCount].genre[strcspn(books[bookCount].genre, "\n")] = '\0';

        printf("Your Books Has been added succesfully\n");

        books[bookCount].id = bookCount + idDecider;

        bookCount++;
        idDecider++;
        saveBooks();
    }
}

void saveBooks()
{
    FILE *fp = fopen(DATA_FILE, "wb");

    if (fp == NULL)
    {
        printf("File error.\n");
        return;
    }

    fwrite(&bookCount, sizeof(int), 1, fp);
    fwrite(&idDecider, sizeof(int), 1, fp);
    fwrite(&books, sizeof(struct Book), bookCount, fp);

    fclose(fp);

    FILE *ft = fopen(Export_FILE, "w");
    if (ft == NULL)
    {
        printf("File error(text/backup file).\n");
        return;
    }

    fprintf(ft, "Here is the complete List of our Book  Inventory:- \n\n");
    for (int i = 0; i < 120; i++)
    {
        fprintf(ft, "-");
    }
    fprintf(ft, "\n%s |%-10s | %-30s | %-30s | %-30s\n\n", "Serial NO. ", "ID", "TITLE", "AUTHOR", "GENRE");

    for (int i = 0; i < bookCount; i++)
    {
        fprintf(ft, "%-11d |%-10d | %-30s | %-30s | %-30s\n", i + 1, books[i].id, books[i].title, books[i].author, books[i].genre);
    }
    for (int i = 0; i < 120; i++)
    {
        fprintf(ft, "-");
    }

    fclose(ft);
}

void viewBook()
{
    printf("Here is the complete List of our Book  Inventory:- \n\n");
    for (int i = 0; i < 120; i++)
    {
        printf("-");
    }
    printf("\n%s |%-10s | %-30s | %-30s | %-30s\n\n", "Serial NO. ", "ID", "TITLE", "AUTHOR", "GENRE");

    for (int i = 0; i < bookCount; i++)
    {
        printf("%-11d |%-10d | %-30s | %-30s | %-30s\n", i + 1, books[i].id, books[i].title, books[i].author, books[i].genre);
    }
    for (int i = 0; i < 120; i++)
    {
        printf("-");
    }
}

void searchBook()
{
    int opt;

    printf("1) By Title\n");
    printf("2) By Author\n");
    printf("3) By ID\n");
    printf("Which Method of Sorting do you prefer: ");
    scanf("%d", &opt);

    if (opt == 1)
    {
        searchByTitle();
    }
    else if (opt == 2)
    {
        searchByAuthor();
    }
    else if (opt == 3)
    {
        searchById();
    }
    else
    {
        printf("Invalid Option");
    }
}

void searchById()
{
    int searchId;
    int found = 0;

    printf("\nEnter the Id for the Book:- ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == searchId)
        {
            printf("\nID:-%d\nTitle:-%s\nAuthor:-%s\nGenre:-%s\n", books[i].id, books[i].title, books[i].author, books[i].genre);
            found = 1;
            break;
        }
    }

    if (found != 1)
    {
        printf("\nNO Book is avaiable with this ID %d", searchId);
    }
}

void searchByTitle()
{

    char searchTitle[50];
    int found = 0;

    getchar();
    printf("Enter the Book Title:- ");
    fgets(searchTitle, 50, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    printf("\nHere are the Books that match your search:- \n");

    for (int i = 0; i < bookCount; i++)
    {
        if ((strncmp(books[i].title, searchTitle, strlen(searchTitle))) == 0)
        {
            printf("\nID:-%d\nTitle:-%s\nAuthor:-%s\nGenre:-%s\n", books[i].id, books[i].title, books[i].author, books[i].genre);
            found = 1;
            printf("\n");
        }
    }

    if (found != 1)
    {
        printf("\nNONE");
    }
}

void searchByAuthor()
{

    char searchAuthor[50];
    int found = 0;

    getchar();
    printf("Enter the Book Author's Name:- ");
    fgets(searchAuthor, 50, stdin);
    searchAuthor[strcspn(searchAuthor, "\n")] = '\0';

    printf("\nHere are the Books that match your search:- \n");

    for (int i = 0; i < bookCount; i++)
    {
        if ((strncmp(books[i].author, searchAuthor, strlen(searchAuthor))) == 0)
        {
            printf("\nID:-%d\nTitle:-%s\nAuthor:-%s\nGenre:-%s\n", books[i].id, books[i].title, books[i].author, books[i].genre);
            found = 1;
            printf("\n");
        }
    }

    if (found != 1)
    {
        printf("\nNONE");
    }
}

void deleteBook()
{

    int deleteId;
    int found = 0;
    char ask;

    printf("\nEnter the Id for the Book:- ");
    scanf("%d", &deleteId);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == deleteId)
        {
            getchar();
            printf("Are you sure you want to Delete the Book(Press (y/Y) to Confirm or any other key to reject)");
            scanf("%c", &ask);

            if (ask == 'Y' || ask == 'y')
            {
                for (int t = i; t < bookCount - 1; t++)
                {
                    books[t] = books[t + 1];
                }
                printf("\nBook Deleted Succesfully");
                bookCount = bookCount - 1;
                saveBooks();
            }

            else
            {
                printf("Book Not Deleted!");
            }

            found = 1;
            break;
        }
    }

    if (found != 1)
    {
        printf("\nNO Book is avaiable with this ID %d", deleteId);
    }
}

void updateBook()
{
    int updateId, temp;
    int found = 0;
    char ask;
    struct Book sample;

    printf("\nEnter the Id for the Book:- ");
    scanf("%d", &updateId);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == updateId)
        {
            printf("\nPrevious Credentials:-");
            printf("\nTitle:-%s\nAuthor:-%s\nGenre:-%s\n\n", books[i].title, books[i].author, books[i].genre);

            printf("Enter New Credentials:- \n");

            getchar();
            printf("New Title:- ");
            fgets(sample.title, 50, stdin);
            books[i].title[strcspn(sample.title, "\n")] = '\0'; // removing the extra line added by user as input

            printf("New Author:- ");
            fgets(sample.author, 50, stdin);
            books[i].author[strcspn(sample.author, "\n")] = '\0';

            printf("New Genre:- ");
            fgets(sample.genre, 50, stdin);
            books[i].genre[strcspn(sample.genre, "\n")] = '\0';

            getchar();
            printf("Are you sure you want to Update the Books details(Press (y/Y) to Confirm or any other key to reject):-");
            scanf("%c", &ask);

            if (ask == 'Y' || ask == 'y')
            {
                temp = books[i].id;
                books[i] = sample;
                books[i].id = temp;
                saveBooks();
                printf("\nBook Credentials Updated Succesfully");
            }
            else
            {
                printf("\nBook Credentials Updation Aborted");
            }

            found = 1;
            break;
        }
        if (found != 0)
        {
            printf("\nNO Book Found with this ID number");
        }
    }
}

void sortBooks()
{
    int opt;

    printf("1) By Title\n");
    printf("2) By Author\n");
    printf("3) By ID\n");
    printf("Which Method of Sorting do you prefer: ");
    scanf("%d", &opt);

    if (opt == 1)
    {
        sortTitle();
        saveBooks();
        viewBook();
    }
    else if (opt == 2)
    {
        sortAuthor();
        saveBooks();
        viewBook();
    }
    else if (opt == 3)
    {
        sortId();
        saveBooks();
        viewBook();
    }
    else
    {
        printf("Invalid Option");
    }
}

void sortId()
{
    struct Book temp;
    for (int i = 0; i < bookCount - 1; i++)
    {
        for (int j = i + 1; j < bookCount; j++)
        {
            if (books[i].id > books[j].id)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void sortTitle()
{
    struct Book temp;
    for (int i = 0; i < bookCount - 1; i++)
    {
        for (int j = i + 1; j < bookCount; j++)
        {
            if (strcmp(books[i].title, books[j].title) > 0)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void sortAuthor()
{
    struct Book temp;
    for (int i = 0; i < bookCount - 1; i++)
    {
        for (int j = i + 1; j < bookCount; j++)
        {
            if (strcmp(books[i].author, books[j].author) > 0)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

