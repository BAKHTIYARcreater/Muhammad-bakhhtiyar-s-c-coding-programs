#include <stdio.h>

struct Book {
    char title[50];
    char author[50];
    float price;
};

int main() {
    struct Book books[3];
    int i;

    // Taking input
    for (i = 0; i < 3; i++) {
        printf("\nEnter details for Book %d:\n", i + 1);

        printf("Enter Title: ");
        fflush(stdin);
        fgets(books[i].title, sizeof(books[i].title), stdin);

        printf("Enter Author: ");
        fflush(stdin);
        fgets(books[i].author, sizeof(books[i].author), stdin);

        printf("Enter Price: ");
        scanf("%f", &books[i].price);
        getchar(); // clear leftover newline
    }

    // Displaying all books
    printf("\n\n--- All Book Details ---\n");
    for (i = 0; i < 3; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title : %s", books[i].title);
        printf("Author: %s", books[i].author);
        printf("Price : %.2f\n", books[i].price);
    }

    return 0;
}

