#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct Patron {
    char name[100];
    char password[30];
    char email[50];
    int is_staff;
 };
struct Book {
   char name[200];
   char page[100];
   char author[50];
   int is_book;
};


//function prototypes
int  save_patron(struct Patron);
void add_patron();
int menu();
void execute_action(int action);
void view_patron();
void close();

int save_book(struct Book);
void add_book();
int menu();
void execute_action(int action);
void view_book();


int main()
{
    while(1) {
    printf("COUNTY LIBRARY SYSTEM!\n");
    printf("Welcome MERCY!\n");
    execute_action(menu());
    printf("Press any key to continue");
    getch();
    system("cls");

    }

    return 0;



}
int save_patron(struct Patron patron){
    FILE *fp;
    fp = fopen("patrons","ab");
    fwrite(&patron,sizeof(struct Patron),1,fp);
    fclose(fp);
    return 1;
}
int save_book(struct Book book){
    FILE *fp;
    fp = fopen("books","ab");
    fwrite(&book,sizeof(struct Book),1,fp);
    fclose(fp);
    return 1;

}


void add_patron() {
    struct Patron patron;
    printf("Enter name:");
    getchar();
    gets(patron.name);
    printf("Enter Email:");
    gets(patron.email);
    printf("Enter initial password:");
    gets(patron.email);
    printf("Enter 1 if staff 0 otherwise: ");
    scanf("%d",&patron.is_staff);
    printf("Patron %s added\n",patron.name);
}

int menu()
{
  int action;
  printf("Select an action:\n");
  printf("1. Add new patron\n");
  printf("2. View Patrons\n");
  printf("3. View Books\n");
  printf("4. Add New Book\n");
  printf("5. Exit\n");
  printf("Your Action: ");
  scanf("%d",&action);
  if(action < 1 || action > 5) {
    printf("Invalid action. Try again\n");
  }
  return action;
}

void execute_action(int action) {
    switch(action){
     case 1:
        add_patron();
        break;
    case 2:
        view_patron();
        break;
    case 3:
        printf("Here is a list of all books");
        break;
    case 4:
        printf("adding a new Book\n");
    case 5:
        close();
        break;
    default:
        printf("Invalid action.\n");
    }

}

void view_patron(){
   FILE *fp;
   struct Patron patron;
if((fp = fopen("patrons","rb")) == NULL){
      printf(" Unable to open file.\n");
      return;
 }
printf("%-20s%-30s%-10s\n","NAME","EMAIL","IS STAFF");
while(!feof (fp)){
 fread(&patron,sizeof(struct Patron),1,fp);
 printf("%-20s",patron.name);
 printf("%-30s",patron.email);
 printf("%-10d",patron.is_staff);
  }

  fclose(fp);
}
void close(){
    printf("Thank you for using me.\n");
    printf("Created by Mercy\n");
    Sleep(2000);
    exit(0);
}


