#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIENTS_SIZE 5
#define NAME_SIZE 40
#define ZIP_SIZE 6
#define COMMAS 3
#define AGE_SIZE 3
#define PATH "data.txt"

typedef struct client {
    char* first_name;
    char* last_name;
    char* age;
    char* zip_code;
} client;

void make_structs(client** clients, size_t size) {
    for (size_t i = 0; i < size; ++i) {

        clients[i] = (client*)malloc(sizeof(client));
        clients[i]->first_name = malloc(sizeof(char) * NAME_SIZE);
        clients[i]->last_name = malloc(sizeof(char) * NAME_SIZE);
        clients[i]->age = malloc(sizeof(char) * AGE_SIZE);
        clients[i]->zip_code = malloc(sizeof(char) * ZIP_SIZE);

        if (!clients[i] || !clients[i]->first_name || !clients[i]->last_name || !clients[i]->age || !clients[i]->zip_code) {
            perror("Error allocating memory for client!");
            exit(-1);
        }
    }
}

void free_structs(client** clients, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        free(clients[i]->first_name);
        free(clients[i]->last_name);
        free(clients[i]->zip_code);
        free(clients[i]);
    }
}

void store(client** clients, size_t pos, char* line) {
    char* chunk = strtok(line, ",");
    while (chunk != NULL) {
        strcpy(clients[pos]->first_name, chunk);
        chunk = strtok(NULL, ",");
        strcpy(clients[pos]->last_name, chunk);
        chunk = strtok(NULL, ",");
        strcpy(clients[pos]->age, chunk);
        chunk = strtok(NULL, ",");
        strcpy(clients[pos]->zip_code, chunk);
        chunk = strtok(NULL, ",");
    }
}

void print_clients(client** clients, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("-------------------- %lu --------------------\n", i+1);
        printf("Name: %s %s\nAge: %s\nZIP code: %s\n", clients[i]->first_name, clients[i]->last_name, clients[i]->age, clients[i]->zip_code);
    }
}

int cmp_fname(const void* a, const void* b) {
    client* c1 = *(client**)a;
    client* c2 = *(client**)b;
    return strcmp((const char*)c1->first_name, (const char*)c2->first_name);
}

int cmp_lname(const void* a, const void* b) {
    client* c1 = *(client**)a;
    client* c2 = *(client**)b;
    return strcmp((const char*)c1->last_name, (const char*)c2->last_name);
}


int main () {

    // prepare clients of clients
    client* clients[CLIENTS_SIZE];
    make_structs(clients, CLIENTS_SIZE);

    // open file to get the data
    FILE* data = fopen(PATH, "r");
    if (!data) {
        perror("Could not open file!");
        exit(-2);
    }

    // read the file line by line and divide lines into fields by comma
    char line[2 * NAME_SIZE + ZIP_SIZE + AGE_SIZE + COMMAS];

    for (size_t i = 0; i < CLIENTS_SIZE; ++i) {
        if (!feof(data)) {
            if (fgets(line, sizeof(line), data) == NULL)
                break;
            store(clients, i, line);
        }
    }

    // print_clients(clients, CLIENTS_SIZE);
    puts("Compare by first name:");
    qsort(clients, CLIENTS_SIZE, sizeof(clients[0]), cmp_fname);
    print_clients(clients, CLIENTS_SIZE);

    puts("Compare by last name:");
    qsort(clients, CLIENTS_SIZE, sizeof(clients[0]), cmp_lname);
    print_clients(clients, CLIENTS_SIZE);

    free_structs(clients, CLIENTS_SIZE);

    fclose(data);

    return 0;
}
