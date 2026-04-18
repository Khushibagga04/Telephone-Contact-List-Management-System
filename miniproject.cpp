#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

struct Contact contacts[100];
int count = 0;

// Add Contact
void addContact() {
    printf("Enter Name: ");
    scanf(" %[^\n]", contacts[count].name);
    
    printf("Enter Phone Number: ");
    scanf("%s", contacts[count].phone);
    
    count++;
    printf("Contact Added Successfully!\n");
}

// View Contacts
void viewContacts() {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Delete Contact
void deleteContact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact Deleted!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

// Search Contact
void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Update Contact
void updateContact() {
    char name[50];
    printf("Enter name to update: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone);
            printf("Contact Updated!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Contact List Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Update Contact\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                updateContact();
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
} 
