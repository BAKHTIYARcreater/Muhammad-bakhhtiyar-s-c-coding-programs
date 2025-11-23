#include<stdio.h>
#include<conio.h>

struct book
{
	char title[50];
	char author[40];
	float prize;
	
};

int main()
{

struct book b1;
printf("enter book title");
    fgets(b1 . title, sizeof(b1.title), stdin);
    printf("enter author name");
    fgets(b1.author, sizeof(b1.author), stdin);
    
printf("enter book prize");
scanf("%f", &b1.prize);
printf("book information\n");
printf("book title: %s\n", b1.title);
printf("book author: %s\n", b1.author);
printf("book prize: %2f\n", b1.prize);
return 0;
}
