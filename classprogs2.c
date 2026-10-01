// Online C compiler to run C program online
#include<stdio.h>

int main()
{ 
    int i;
    struct student
    {
    int marks;
    char name[10];
    float percentage;
    }s[2];

    printf("Enter the student details:\n");
    for (i=0;i<2;i++)
        {
            printf("Enter the student details % d\n",i+1);
            scanf("%d %s %f", &s[i].marks, s[i].name, &s[i].percentage);
        }
    printf("The student details:\n");
    for (i=0;i<2;i++)
        {
            printf("%d\n %s\n %f\n", s[i].marks, s[i].name, s[i].percentage);
        }
return 0;
}