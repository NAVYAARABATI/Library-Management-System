#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for a book
struct library {
    int id;
    char title[100];
    char author[100];
    int quantity;
};

// Global book array and counter
struct library book[MAX];
int count = 0;

// Function declarations
void addbook();
void displaybook();
void searchbook();
void issuebook();
void deletebook();

int main() {
    int choice;

    while (1) {
        // Display menu
        printf("\n-- LIBRARY MANAGEMENT SYSTEM --\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1: addbook(); break;
            case 2: displaybook(); break;
            case 3: searchbook(); break;
            case 4: issuebook(); break;
            case 5: deletebook(); break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a new book
void addbook() {
    printf("\n-- Add Book --\n");

    if (count >= MAX) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &book[count].id);
    getchar(); // To consume newline after ID input

    printf("Enter book title: ");
    scanf("%[^\n]", book[count].title);
    getchar(); // Consume newline

    printf("Enter author name: ");
    scanf("%[^\n]", book[count].author);

    printf("Enter quantity: ");
    scanf("%d", &book[count].quantity);

    count++;
    printf("Book added successfully.\n");
}

// Function to display all books
void displaybook() {
    printf("\n-- Display Books --\n");

    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nBook %d\n", i + 1);
        printf("ID      : %d\n", book[i].id);
        printf("Title   : %s\n", book[i].title);
        printf("Author  : %s\n", book[i].author);
        printf("Quantity: %d\n", book[i].quantity);
    }
}

// Function to search for a book by ID
void searchbook() {
    int bookid, found = 0;
    printf("\n-- Search Book --\n");
    printf("Enter book ID to search: ");
    scanf("%d", &bookid);

    for (int i = 0; i < count; i++) {
        if (book[i].id == bookid) {
            printf("\nBook Found:\n");
            printf("ID      : %d\n", book[i].id);
            printf("Title   : %s\n", book[i].title);
            printf("Author  : %s\n", book[i].author);
            printf("Quantity: %d\n", book[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to issue a book by ID
void issuebook() {
    int bookid, found = 0;
    printf("\n-- Issue Book --\n");
    printf("Enter book ID to issue: ");
    scanf("%d", &bookid);

    for (int i = 0; i < count; i++) {
        if (book[i].id == bookid) {
            if (book[i].quantity > 0) {
                printf("\nBook Details:\n");
                printf("Title   : %s\n", book[i].title);
                printf("Author  : %s\n", book[i].author);
                printf("Quantity before issue: %d\n", book[i].quantity);
                book[i].quantity--;
                printf("Book issued successfully. Remaining quantity: %d\n", book[i].quantity);
            } else {
                printf("Book is currently out of stock.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to delete a book by ID
void deletebook() {
    int bookid, found = 0;
    printf("\n-- Delete Book --\n");
    printf("Enter book ID to delete: ");
    scanf("%d", &bookid);

    for (int i = 0; i < count; i++) {
        if (book[i].id == bookid) {
            printf("\nBook Deleted:\n");
            printf("Title   : %s\n", book[i].title);
            printf("Author  : %s\n", book[i].author);
            printf("Quantity: %d\n", book[i].quantity);

            // Shift remaining books
            for (int j = i; j < count - 1; j++) {
                book[j] = book[j + 1];
            }

            count--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Book deleted successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}
