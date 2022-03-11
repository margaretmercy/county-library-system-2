#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patron {
    char name[100];
    char pass[30];
    char email[50];
    int is_staff;
};
int save_patron(struct Patron patron){
    FILE *fp;
    fp = fopen("patrons","ab");
    fwrite(&patron,sizeof(struct Patron),1,fp);
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
    printf("Initial Password: ");
    gets(patron.pass);
    printf("Enter 1 if staff 0 otherwise: ");
    scanf("%d",&patron.is_staff);
    if(save_patron(patron))
    printf("Patron %s successfully added\n",patron.name);
    else
        printf("unsuccessfully");

}

int menu()
{
  int action;
  printf("Select an action:\n");
  printf("1. Add new patron\n");
  printf("2. View Patrons\n");
  printf("3. View Books\n");
  printf("4. Add New Book\n");
  printf("Your Action: ");
  scanf("%d",&action);
  if(action < 1 || action > 4) {
    printf("Invalid action. Try again\n");
  }
  return action;
}

void execute_action(int action) {
    switch(action) {
    case 1:
        add_patron();
        break;
    case 2:
        printf("Here is a list of patrons\n");
        break;
    case 3:
        printf("Here is a list of all books");
        break;
    case 4:
        printf("adding a new Book\n");
        break;
    default:
        printf("Invalid action.\n");
    }
}



int main()
{
    printf("COUNTY LIBRARY SYSTEM!\n");
    printf("Welcome MERCY!\n");
    execute_action(menu());
    return 0;
}
