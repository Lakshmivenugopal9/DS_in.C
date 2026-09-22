#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book
{
	int bookId;
	char title[50];
	char author[30];
	float price;
	char status;
};
void create (struct Book * books, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter details for book%d:\n",i+1);
		printf("Book ID:");
		scanf("%d",&books[i].bookId);
		printf("Title:");
		scanf(" %[^\n]",books[i].title);
		printf("Author:");
		scanf(" %[^\n]",books[i].author);
		printf("price:");
		scanf("%f",&books[i].price);
		books[i].status='A';
	}
}
void display(struct Book*books, int n)
{
	int i;
	printf("\n%-8s%-22s%-18s%-10s%-10s%\n","ID","Title","Author","Price","status");
	for(i=0;i<n;i++)
	printf("\n%-8d%-22s%-18s%-10.2f%-10s%\n", books[i].bookId, books[i].title, books[i].author, books[i].price, books[i].status=='A'?"Available":"Issued");
}
int findindex(struct Book*books,int n, int id)
{
	int i;
	for(i=0;i<n;i++)
	if(books[i].bookId==id) return i;
	return -1;
}
void search(struct Book*books, int n,int id)
{
	int idx = findindex(books,n,id);
	if(idx==-1)
	{
		printf("BookID%d not found\n",id);
		return;
	}
	printf("found:%d|%s|%s|%2f|%s\n",books[idx].bookId,books[idx].title,books[idx].author,books[idx].price,books[idx].status=='A'?
	"Available":"Issued");
}
void issueBook(struct Book*books,int n,int id)
{
	int idx = findindex(books,n,id);
	if(idx==-1)
	{
		printf("Book is already issued\n");
		return;
	}
if(books[idx].status=='I')
	{
		printf("Book is already issued.\n");
		return;
	}
books[idx].status='I';
printf("Book '%s' issued successfully.\n", books[idx].title);
}
void returnBook(struct Book * books,int n, int id)
{
	int idx = findindex(books,n,id);
	if(idx==-1)
	{
		printf("Book Id %d not found.\n",id);
		return;
	}
if(books[idx].status=='A')
{
	printf("book was not issued\n");
	return;
}
books[idx].status='A';
printf("Book'%s'returned successfully.\n", books[idx].title);
}
int main()
{
	int n,choice,id;
	struct Book*books;
	printf("Enter number of books:");
	scanf("%d",&n);
	books = (struct Book*)malloc(n*sizeof(struct Book));
	if(books == NULL)
	{
		printf("Memory allocation failed,\n");
		return 1;
	}
create (books,n);
do
{
printf("---Library Menu--\n");
printf("1.Display 2.search 3.Issue 4.Return 5.Exit\n");
printf("Enter choice:");
scanf("%d",&choice);
switch(choice)
{
  case 1: display(books,n);
  break;
  case 2: printf("Enter Book ID:");
  scanf("%d",&id);
  search(books,n,id);break;
  case 3: printf("Enter Book ID:");
  scanf("%d",&id);
  issueBook(books,n,id);
  break;
  case 4: printf("Enter Book Id:");
  scanf("%d",&id);
  returnBook(books,n,id);
  break;
  case 5: printf("Exiting---\n");
  break;
  default: printf("Invalid choice\n");
  }
  }
  while(choice!=5);
  free(books);
  return 0;
}