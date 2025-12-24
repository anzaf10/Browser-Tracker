#include <stdio.h>
#include <string.h>
#include "../include/stack.h"

int main() {
    Stack backStack, forwardStack;
    char currentUrl[URL_LENGTH];
    char tempUrl[URL_LENGTH];
    int choice;

    initStack(&backStack);
    initStack(&forwardStack);

    strcpy(currentUrl, "Home");

    while (1) {
        printf("\n[Current Page]: %s\n", currentUrl);
        printf("1. Visit New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", tempUrl);
                push(&backStack, currentUrl);
                strcpy(currentUrl, tempUrl);
                clearStack(&forwardStack);
                break;

            case 2:
                if (isEmpty(&backStack)) {
                    printf("No history available.\n");
                } else {
                    push(&forwardStack, currentUrl);
                    pop(&backStack, currentUrl);
                }
                break;

            case 3:
                if (isEmpty(&forwardStack)) {
                    printf("No forward history.\n");
                } else {
                    push(&backStack, currentUrl);
                    pop(&forwardStack, currentUrl);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}