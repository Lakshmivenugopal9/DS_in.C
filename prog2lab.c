#include <stdio.h>
#include <string.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isFull(void)  { return top == MAX - 1; }
int isEmpty(void) { return top == -1; }

void push(int item)
{
    if (isFull())
        printf("Stack Overflow! Cannot push %d\n", item);
    else
    {
        stack[++top] = item;
        printf("%d pushed onto the stack\n", item);
    }
}

int pop(void)
{
    if (isEmpty())
    {
        printf("Stack Underflow! Nothing to pop\n");
        return -1;
    }
    return stack[top--];
}

void display(void)
{
    int i;
    if (isEmpty())
    {
        printf("Stack is EMPTY (top = %d)\n", top);
        return;
    }
    printf("Stack contents (top to bottom):\n");
    for (i = top; i >= 0; i--)
        printf("| %3d |%s\n", stack[i],
               (i == top) ? " <-- TOP" : "");
    printf("Top = %d, Elements = %d, Free = %d\n",
           top, top + 1, MAX - 1 - top);
}

void checkPalindrome(void)
{
    char str[100], cstack[100];
    int ctop = -1, i, len, isPal = 1;

    printf("Enter a number or string: ");
    scanf("%s", str);
    len = strlen(str);

    for (i = 0; i < len; i++)          /* push every character */
        cstack[++ctop] = str[i];

    for (i = 0; i < len; i++)          /* pop and compare      */
        if (str[i] != cstack[ctop--])
        {
            isPal = 0;
            break;
        }

    if (isPal) printf("%s is a PALINDROME\n", str);
    else       printf("%s is NOT a palindrome\n", str);
}

void demoOverflowUnderflow(void)
{
    int i, val;
    top = -1;                     /* start with an empty stack */
    printf("--- Overflow demo ---\n");
    for (i = 1; i <= MAX + 1; i++)
        push(i * 10);             /* last push fails */
    printf("--- Underflow demo ---\n");
    for (i = 1; i <= MAX + 1; i++)
    {
        val = pop();              /* last pop fails */
        if (val != -1)
            printf("Popped: %d\n", val);
    }
}

int main(void)
{
    int choice, item, val;
    while (1)
    {
        printf("\n===== STACK MENU (MAX = %d) =====\n", MAX);
        printf("1. Push\n2. Pop\n3. Palindrome check\n");
        printf("4. Demo overflow & underflow\n");
        printf("5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter element to push: ");
                    scanf("%d", &item);
                    push(item);
                    break;
            case 2: val = pop();
                    if (val != -1)
                        printf("Popped element = %d\n", val);
                    break;
            case 3: checkPalindrome();       break;
            case 4: demoOverflowUnderflow(); break;
            case 5: display();               break;
            case 6: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}