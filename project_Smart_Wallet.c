#include <stdio.h>
#include <stdlib.h>
#include <string.h>              //Libraries used

typedef struct{
    long  int day;
    long int month;             //Defining the structure for the dates
    long int year;
} Date;

typedef struct {
    int len;
    char name;                  //Defining the structure for the categories
} Category [100];

typedef struct {
    char type [100];
    float value;                //Defining the structure by dividing it into 2 different types
    Category cat;              //and including the category and date structures.
    Date d;
} record;

void header();              //Function that returns the header.
void insert_record ();      //Function used to insert the data on the program.
void list_record();        //Function used to list all the data read by the file.
void add_category();       //Function to add the categories.
void search_records();     //Function used to search data on the file.
void sum_values();         //Function used to calculate and return a overview of the data.

int main(){

     int op;                    //Auxiliary variable used to receive the user's choice in one of the options.
    do{                         //Command that executes what is inside of it while the user does not enter the exit option.
        header();
        printf("\n1 - Insert the data \n2 - Records \n3 - Add Categories \n4 - Search \n5 - Overview \n6 - Exit\n"); //Used to print the main menu options in the program.
        scanf("%i",&op);

        switch(op){             //Command used to execute the various options for choosing the main menu.
        case 1:                 //Command that is executed after receiving the user's option, which in this case is number 1.
            insert_record();    //Calls the function that inserts data into the program.
            break;              //Break used indicating to the program that after the condition is true that it does not execute the other options.
        case 2:                 //Same sequence within the entire switch command.
            list_record();
            break;
        case 3:
        add_category();
            break;
        case 4:
        search_records();
            break;
        case 5:
        sum_values();
            break;
            case 6:
            system("exit"); //Command that terminates the program upon receiving the true entry condition, which in this case is 6.
            break;
        default: //If the user enters a different option, the program returns showing the invalid entry in the menu.
            printf("Invalid option!");
            break;
        }
    }while(op!=6); //If the user option is 6, the program is terminated.

return 0;
}

void header(){ //Function that presents a header to the program, in order to present a good design to the user.
    system("cls"); //Command that "cleans" the screen, used in this function so that the header is presented in a "new screen" to the user.
    printf("*------------------------------------------------*\n");
    printf("                  MENU WALLET                        ");
    printf("\n*------------------------------------------------*\n");
}

void insert_record (){                          //Function that allows to insert the data in the program.
    system("cls");
    int op;                                     //Auxiliary variable used to receive the user's choice in one of the options.
    record *tmp;                              // Defining as a pointer.
    tmp = (record*)malloc(5*sizeof(record)); // Performing memory allocation.
    if(tmp == NULL){                         // Verifying if the memory was allocated
        printf("Invalid");
    }   else {
            FILE* fp;                           // Defining as a pointer to FILE.
            fp = fopen("data.txt", "a");        // Defining the file opening.
            if(fp == NULL){                     //Verifying if the file was open.
            printf("Error  opening file!");     // Printing a message to the user if the opening is not successful.
        }   else{
                do{
                    header();
                    fflush(stdin);              //Cleaning the buffer of the keyboard.
                    printf("Write the type(income/expense): ");
                    gets( tmp[0].type);         //Reading the entry as a string.
                    printf("\nWrite the value in forints: ");
                    scanf("%f", &tmp[0].value);    //Reading the entry as a float and assigned to the pointer at position 0.
                    fflush(stdin);
                    printf("\nWrite the category: ");
                    gets(tmp[0].cat);
                    printf("\nWrite the date(yyyy.mm.dd): ");
                    scanf("%d.%d.%d", &tmp[0].d.year,&tmp[0].d.month,&tmp[0].d.day);

                for(int i = 0; i < 1; i++){   //Repeating loop to cycle through the vector.
                    fwrite(&tmp[i],sizeof(record), 1, fp);   //Writing in the file all the values previously read.
            }
                printf("Write 1 to continue or any to Exit: ");
                scanf("%d", &op);
            }   while(op == 1);
                fclose(fp);     //Closing the file after all execution.
                free(tmp);      //Freeing allocated memory.
            }
        }
    }

void list_record(){
    system("cls");
    int op;
    record *tmp;
    tmp = (record*)malloc(5*sizeof(record));
    if(tmp == NULL){
            printf("Invalid");
    }    else {
            FILE *fp;
            fp = fopen("data.txt", "r"); //Open the file to read.
            if(fp == NULL){
            printf("Error  opening file!");
        }   else{
                header();
                    do{
                    for(int i = 0; i < 1 ; i++){        //Repeating loop going through all the data in the vector.
                    while(fread(&tmp[i],sizeof(record), 1, fp) != NULL ){ //Reading all data stored in the file.
                    printf("Type: %s \n", tmp[i].type);
                    printf("Value: %.2f \n", tmp[i].value);             //Printing the read data.
                    printf("Category: %s \n", tmp[i].cat);
                    printf("Date: %d.%d.%d \n", tmp[i].d.year,tmp[i].d.month,tmp[i].d.day);
                    printf("----------------------------------------------------");
                    printf(" \n");
                }
            }
                fflush(stdin);
                printf("\nPress 0 to return.");
                scanf("%d", &op);

            }   while(op == 1);
        }
            free(tmp);          //Freeing allocated memory.
            fclose(fp);       //Closing the file after all execution.
    }

}

void add_category(){
    system("cls");
    int op;
    char name [60]; //Auxiliary variable using to read the category giving by the user.
    record *Category;  //Defining with a pointer
    Category = (record*)malloc(1*sizeof(record));  //Allocating memory the size of the record structure
    if(Category == NULL){
        printf("Invalid");
    }   else {
            FILE* fp;
            fp = fopen("category.txt", "a");
            if(fp == NULL){
                printf("Error  opening file!");
        }   else{
                do{
                header();
                fflush(stdin);
                printf("Write the category: ");
                gets(name);
                for(int i = 0; i < 1; i++){
                fwrite(&Category[i],sizeof(record), 1, fp); //Writing on the file the categories giving by the user.
            }
                fflush(stdin);
                printf("Write 1 to continue or any to Exit: ");
                scanf("%d", &op);
            }   while(op == 1);
                fclose(fp);
                free(Category);
        }
    }
}

void search_records(){
        system("cls");
       int op;
       int day, month, year;
       int day2, month2, year2;
       int sum1,sum2;
       float max_value = 0;
       float max_value2 = 0;        //Auxiliary variables used for some operations.
       char most_cat[100];
       char most_cat2[100];
        record *tmp;
        tmp = (record*)malloc(5*sizeof(record));
    if(tmp == NULL){
        printf("Invalid");
    }   else {
            FILE *fp;
            fp = fopen("data.txt", "r");
        if(fp == NULL){
            printf("Error  opening file!");
        }   else{
                do{
                header();
                printf("Write the first date(yyyy.mm.dd): ");
                scanf("%d.%d.%d", &year,&month,&day);

                printf("Write the second date(yyyy.mm.dd): ");
                scanf("%d.%d.%d", &year2,&month2,&day2);

                for(int i = 0; i < 1 ; i++){
                    while(fread(&tmp[i],sizeof(record), 1, fp) != NULL ){       // Reading the data of the file.
                        if( year <= tmp[i].d.year && month <= tmp[i].d.month && day <= tmp[i].d.day){   // Condition that determines the period of time to be searched.
                        if(year2 >= tmp[i].d.year && month2 >= tmp[i].d.month && day2 >= tmp[i].d.day){
                            if(strcmp("income", tmp[i].type) == 0){        //Comparing strings to return only the values of incomes
                                for(int i = 0; i < 1; i++){
                                    sum1 = sum1 + tmp[i].value;         //Adding the amounts
                                if(tmp[i].value > max_value2){
                                    max_value2 = tmp[i].value;          //Calculating the maximum value
                                    strcpy(most_cat2, tmp[i].cat);
                                    if(tmp[i].value != 0){
                                    printf("\n-----------------------");
                                    printf("\n      MOST INCOME      ");
                                    printf("\n-----------------------\n");
                                    printf("\nCategory: %s", most_cat2);
                                    printf("\nValue: %.2f\n",max_value2);
                                }
                            }
                        }
                }
                                    if(strcmp("expense", tmp[i].type) == 0){//Comparing strings to return only the values of incomes
                                        for(int i = 0; i < 1; i++){
                                            sum2 = sum2 + tmp[i].value;     //Adding the amounts
                                        if(tmp[i].value > max_value){
                                            max_value = tmp[i].value;       //Calculating the maximum value
                                            strcpy(most_cat, tmp[i].cat);   //Using the auxiliary variable to return the categories.
                                        if(tmp[i].value != 0){
                                            printf("\n-----------------------");
                                            printf("\n      MOST EXPENSE      ");
                                            printf("\n-----------------------");
                                            printf("\nCategory: %s", most_cat);
                                            printf("\nValue: %.2f\n",max_value);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
                printf("\nWrite 1 to continue or any to Exit: ");
                scanf("%d", &op);
            }   while(op == 1);
        }
                free(tmp);
                fclose(fp);
                getchar();
    }
}

void sum_values(){
    system("cls");
    int op;
    float sum1,sum2;
    float max_value = 0;
    char most_cat [100];
    record *tmp;
    tmp = (record*)malloc(5*sizeof(record));
    if(tmp == NULL){
        printf("Invalid");
    }   else {
            FILE *fp;
            fp = fopen("data.txt", "r");
        if(fp == NULL){
            printf("Error  opening file!");
        }   else{
                header();
                printf("                   OVERVIEW\n");
                    do{
                    for(int i = 0; i < 1 ; i++){
                    while(fread(&tmp[i],sizeof(record), 1, fp) != NULL){
                    if(strcmp("income", tmp[i].type) == 0){
                    for(int i = 0; i < 1; i++){
                     sum1 = sum1 + tmp[i].value;
                }
            }
                if(strcmp("expense", tmp[i].type) == 0){
                   for(int i = 0; i < 1; i++){
                     sum2 = sum2 + tmp[i].value;
                     if(tmp[i].value > max_value){
                        max_value = tmp[i].value;
                        strcpy(most_cat,tmp[i].cat);
                     }
                }
            }
        }
                printf("\nMost expense category: %s  -  %.2f HUF  /  %.2f EUR", most_cat, max_value, (max_value)*0.0028);
                printf("\nTotal incomes: %.2f HUF / %.2f EUR", sum1, sum1*0.0028);
                printf("\nTotal expenses: %.2f HUF / %.2f EUR", sum2, sum2*0.0028);
                printf("\nTotal available in wallet: %.2f HUF / %.2f EUR\n", sum1-sum2, (sum1-sum2)*0.0028);
    }
                fflush(stdin);
                printf("\nPress 0 to return.");
                scanf("%d", &op);
            }while(op == 1);
        }
            free(tmp);
            fclose(fp);
    }
}
