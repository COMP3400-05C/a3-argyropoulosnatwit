#include "list.h"
#include <stdlib.h>

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * Returns the tail of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The tail of the linked list.
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if(head == NULL){
        return NULL;
    }

    while(head->next != NULL){
        head = head -> next;
    }
    return head;
}

/**
 * Returns the number of elements in the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The size of the linked list.
 */
int ll_size(struct ll_node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/**
 * Searches through the linked list for a specific value.
 * 
 * @param head Pointer to the first node of the linked list.
 * @param value The value to search for in the linked list.
 * @return The node containing the value. Returns NULL if the value is not found.
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    while (head != NULL) {
        if (head->data == value){
            return head;
        }
        head = head->next;
    }
    return NULL;   
}

/**
 * Converts the linked list into an array.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The created array.
 */
int *ll_toarray(struct ll_node *head) {
    int size = ll_size(head);
    if (size == 0){
        return NULL;
    } 

    int *array = malloc(size * sizeof(int));
    if (array == NULL){
        return NULL;
    } 

    for (int i = 0; i < size; i++) {
        array[i] = head->data;
        head = head->next;
    }
    return array;
}

/**
 * Creates a linked list node.
 * 
 * @param data The data to add to the newly created node.
 * @return The newly created node.
 */
struct ll_node *ll_create(int data) {
    struct ll_node *node = malloc(sizeof(struct ll_node));
    if (node == NULL){
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * Frees all of the nodes in the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 */
void ll_destroy(struct ll_node *head) {
    while (head != NULL) {
        struct ll_node *temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * Appends a new node to the tail of the list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @param data The data contained in the appended node.
 */
void ll_append(struct ll_node *head, int data) {
    struct ll_node *new_node = ll_create(data);
    if (head == NULL) return; // cannot append to NULL head safely
    struct ll_node *tail = ll_tail(head);
    tail->next = new_node;
}

/**
 * Converts an array into a linked list.
 * 
 * @param data The array to be converted.
 * @param len The length of the array.
 * @return The pointer to the first node of the created linked list.
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if (data == NULL || len <= 0) return NULL;

    struct ll_node *head = ll_create(data[0]);
    struct ll_node *tail = head;

    for (int i = 1; i < len; i++) {
        struct ll_node *node = ll_create(data[i]);
        tail->next = node;
        tail = node;
    }

    return head;
}

/**
 * Destroys the first node with a specific value.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the updated linked list.
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if (head == NULL) return NULL;

    if (head->data == value) {
        struct ll_node *next = head->next;
        free(head);
        return next;
    }

    struct ll_node *prev = head;
    struct ll_node *curr = head->next;

    while (curr != NULL) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

