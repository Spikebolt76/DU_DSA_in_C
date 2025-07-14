#include "doublyList.h"

void *deleteAltNodes(DoublyLinkedList *list) {
    if (is_empty(list) || !list->head->next) {
        return list;
    }

    Node *curr = list->head;
    while (curr && curr->next) {
        Node *temp = curr->next;

        if (temp->next){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            curr = curr->next;
            free(temp);
        } else {
            temp->prev->next = NULL;
            temp->prev = NULL;
        }
        list->size--;
    }
}

int main() {
    DoublyLinkedList *list;
    list = init_DoublyList();

    insertAtTail(list, 45);
    insertAtTail(list, 67);
    insertAtTail(list, 0);
    insertAtTail(list, 23);

    print_list_forward(list);
    deleteAltNodes(list);
    print_list_forward(list);
}