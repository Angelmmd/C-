// Angela Magoola M24B38/150
//inventory management

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 5

typedef struct {
    char name[50];
    int quantity;
    float costprice;
} Item;

Item inventory[MAX_ITEMS] = {
    {"juice", 0, 0.0},
    {"rice", 0, 0.0},
    {"water", 0, 0.0},
    {"milk", 0, 0.0},
    {"cereal", 0, 0.0}
};

int item_count = 5;

void display_inventory() {
    for (int i = 0; i < item_count; i++) {
        float total_price = inventory[i].quantity * inventory[i].costprice;
        printf("%s (%d) - $%.2f\n", inventory[i].name, inventory[i].quantity, total_price);
    }
}

void update_item(char name[], int new_quantity) {
    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = new_quantity;
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void calculate_total_value() {
    float total_value = 0.0;
    for (int i = 0; i < item_count; i++) {
        total_value += inventory[i].quantity * inventory[i].costprice;
    }
    printf("Total inventory value: $%.2f\n", total_value);
}

int main() {
    int choice;
    char name[50];
    int quantity;
    float costprice;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add item\n");
        printf("2. Display inventory\n");
        printf("3. Update item\n");
        printf("4. Calculate total value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Item name: ");
                scanf("%s", name);
                printf("Quantity: ");
                scanf("%d", &quantity);
                printf("Price per unit: ");
                scanf("%f", &costprice);
                
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                printf("Item name to update: ");
                scanf("%s", name);
                printf("New quantity: ");
                scanf("%d", &quantity);
                update_item(name, quantity);
                break;
            case 4:
                calculate_total_value();
                break;
            case 5:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}