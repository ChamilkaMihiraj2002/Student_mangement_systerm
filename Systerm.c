#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int i=0;//studnet_Possision_count

//Data base for student ->
struct Student_database
{
    char name[10];
    int age;
    char address[10];
    int Telephone_number;
    char grade[3];
    int index_number;
};

//Student Count ->
struct Student_database user[1000];

int check_data(int index){
    for (int j = 0; j < i; j++)
    {
        if (user[j].index_number == index)
        {
            return j;//conform index number
        }
        
    }    
}

int defualt_data(){
    char *names[10]  = {"Chamilka","Kaveesha","Anjana","Dilkini","Navoda","Kalana","Amayaa","Gagulel"};
    int ages[10]    = {21,21,21,21,22,22,22,19};
    char *addre[10]  = {"Dankotuwa","Kaluthara","Kadawatha","Mawanalla","Kurunagala","Kurunagala","Wennappuw","Rathnapura"};
    int tel[10]    = {772326005,771370593,760917653,764837547,716320032,702018278,766110121,726016098};
    char *grades[10] = {"13","13","13","13","13","13","13","13"};
    int indexes[10] = {2250,2253,2263,2269,2232,2245,2211,2210};

    for (int z = 0; z < 8; z++)
    {
        strcpy(user[z].name,names[z]);
        user[z].age = ages[z];
        strcpy(user[z].address,addre[z]);
        user[z].Telephone_number = tel[z];
        strcpy(user[z].grade,grades[z]);
        user[z].index_number = indexes[z];
    }
    
    i = 8;
}


int Add_Student(){
    printf("Name (10 Leters)    : ");
    scanf("%10s",&user[i].name);
    printf("Age                 : ");
    scanf("%d",&user[i].age);
    printf("Address (10 Leters) : ");
    scanf("%10s",&user[i].address);
    printf("Telephone Number    : ");
    scanf("%d",&user[i].Telephone_number);
    printf("Grade               : ");
    scanf("%s",&user[i].grade);
    printf("Index  (4 Numbers)  : ");
    scanf("%4d",&user[i].index_number);
    i++;
}

int Change_student_Details(){
    int check_index;
    printf("Index Number : ");
    scanf("%d",&check_index);

    int confrom_index = check_data(check_index);
    int number_entered;
    printf("\n What want to Change : Name[1] Age[2] Address[3] Telephone Number[4] Grade[5] Index[6] : ");
    scanf("%d",&number_entered);

    switch (number_entered)
    {
    case 1:
        printf("Name (10 Letters) : ");
        scanf("%10s",&user[confrom_index].name);
        break;
    
    case 2:
        printf("Age  : ");
        scanf("%d",&user[confrom_index].age);
        break;
    
    case 3:
        printf("Address (10 Letters) : ");
        scanf("%10s",&user[confrom_index].address);
        break;
    
    case 4:
        printf("Telephone Number : ");
        scanf("%d",&user[confrom_index].Telephone_number);
        break;
    
    case 5:
        printf("Grade : ");
        scanf("%s",&user[confrom_index].grade);
        break;
    
    case 6:
        printf("Index  : ");
        scanf("%4d",&user[confrom_index].index_number);
        break;
    
    default:
        printf("##SYSTERM ERRORR##");
        break;
    }

}

int Show_All(){
    printf("\n| Name\t\t| Age | Index | Grade | Address  |      Telephone |\n\n");
    
    for (int x = 0; x < i; x++)
    {
        printf("  %s\t   %d\t%d\t%s\t%s\t%d\n",user[x].name,user[x].age,user[x].index_number,user[x].grade,user[x].address,user[x].Telephone_number);
    }
    
    
}


int Delete_Student_Details(){
    int check_index;
    printf("Index Number : ");
    scanf("%d",&check_index);

    int confrom_index = check_data(check_index);

    strcpy(user[confrom_index].name," ");
    user[confrom_index].age = 0;
    strcpy(user[confrom_index].address," ");
    user[confrom_index].Telephone_number =  0;
    strcpy(user[confrom_index].grade," ");
    user[confrom_index].index_number =  0;

}


int print_details(){
    FILE * fpointer = fopen("FILE.txt","a");
    fprintf(fpointer,"--------------------------------------------------------\n");

    for (int x = 0; x < i; x++)
    {
        fprintf(fpointer,"Name         : %s\t\t| Age       : %d\n",user[x].name,user[x].age);
        fprintf(fpointer,"Index Number : %d  \t    | Grade     : %s\n",user[x].index_number,user[x].grade);
        fprintf(fpointer,"Address      : %s\t| Telephone : %d\n\n",user[x].address,user[x].Telephone_number);
    }

    fprintf(fpointer,"--------------------------------------------------------\n\n");
    fclose(fpointer);

    return 0;
}


//Selcted_the_Function
int filter_selection(int number){
    switch (number)
    {
    case 1:
        Add_Student();
        break;
    
    case 2:
        Change_student_Details();
        break;

    case 3:
        Show_All();
        break;

    case 4:
        Delete_Student_Details();
        break;
    
    case 5:
        defualt_data();
        break;

    case 6:
        print_details();
        exit(EXIT_FAILURE);
        break;
    
    default:
        break;
    }
}


int Systerm_Dispaly(){
    printf("\n\t\t\tSTUDENT MANGEMENT SYSTERM\n");
    printf("\n***********************************************************************************\n");

    printf("\t\tAdd Student  [1]\tChange student Details [2]\n");
    printf("\t\tShow All     [3]\tDelete Student Details [4]\n");
    printf("\t\tDefault Data [5]\tExit (Print Details)   [6]\n");

    printf("\n***********************************************************************************\n\n");

    int select_number;
    printf("Enter Number :");
    scanf("%d",&select_number);

    filter_selection(select_number);
}



int main()
{
    while (1)
    {
        Systerm_Dispaly();
    }
    
    return 0;
}
