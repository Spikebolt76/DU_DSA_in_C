#include "Stack_using_array.h"

int main () {
    Stack* s;
    initStack(s);

    push(s, 31);
    push(s, 20);
    push(s, 0);
    push(s, 1);
    pop(s);
    pop(s);
    display(s);

    return 0;
}