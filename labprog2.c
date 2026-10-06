#include <stdio.h>
#define MAX 16 /* syllabus requires MAX > 15 */
int stack[MAX];
int top = -1;
void push(int value)
{
if (top == MAX - 1) {
printf("Stack Overflow! Cannot push %d.\n", value);
return;
}
stack[++top] = value;
printf("%d pushed onto the stack.\n", value);
}
void pop()
{
if (top == -1) { printf("Stack Underflow! Stack is empty.\n"); return; }
printf("%d popped from the stack.\n", stack[top--]);
}
/* fill the stack until it overflows, then empty it until it underflows */
void demonstrate()
{
int value = 100;
printf("--- Pushing until the stack overflows ---\n");
while (top != MAX - 1)
push(value++);
push(value); /* one push too many -> Overflow */
printf("--- Popping until the stack underflows ---\n");
while (top != -1)
pop();
pop(); /* one pop too many -> Underflow */
}
void displayStatus()
{
int i;
printf("Stack status: %d of %d slots used", top + 1, MAX);
if (top == -1) { printf(" (EMPTY)\n"); return; }
if (top == MAX - 1) printf(" (FULL)");
printf("\nTop element: %d (index %d)\n", stack[top], top);
printf("Elements (top -> bottom): ");
for (i = top; i >= 0; i--) printf("%d ", stack[i]);
printf("\n");
}
int main()
{
int choice, value;
do {
printf("\n--- Stack Menu (MAX=%d) ---\n", MAX);
printf("1.Push 2.Pop 3.Demonstrate Overflow/Underflow ");
printf("4.Display Status 5.Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value: ");
scanf("%d", &value);
push(value);
break;
case 2: pop(); break;
case 3: demonstrate(); break;
case 4: displayStatus(); break;
case 5: printf("Exiting...\n"); break;
default: printf("Invalid choice.\n");
}
} while (choice != 5);
return 0;
}