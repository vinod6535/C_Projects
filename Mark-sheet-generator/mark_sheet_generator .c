#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[20], fa_name[20], mo_name[20], s_name[40], dob[15];

int roll_number, class, hi_marks, eng_marks, san_marks, math_marks, sci_marks, so_sci_marks;

void generate_marksheet()
{
    int grand_total;
    float presentage;
    grand_total = hi_marks + eng_marks + san_marks + math_marks + sci_marks + so_sci_marks;
    presentage = grand_total / 6;

    printf("\n------------------------------------------------------------------------------------\n");
    printf("|                 CBSE EXAMINATION CERTIFICATE		    |\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("|Your name: %s\tclass: %dth\tRoll Number: %d\n", name, class, roll_number);
    printf("|Father name: %s\n", fa_name);
    printf("|Date of birth: %s\n", dob);
    printf("|School name: %s\n", s_name);
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\tSUBJECTS      \tMAX MARKS\tMIN MARKS\tTHEORY MARKS\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\tHINDI         \t  100      \t   33       \t    %d\n", hi_marks);
    printf("|\tENGLISH       \t  100      \t   33       \t    %d\n", eng_marks);
    printf("|\tSANSKRIT      \t  100      \t   33       \t    %d\n", san_marks);
    printf("|\tMATHEMATICs   \t  100      \t   33       \t    %d\n", math_marks);
    printf("|\tSCIENCE       \t  100      \t   33       \t    %d\n", sci_marks);
    printf("|\tSOCIAL SCIENCE\t  100      \t   33       \t    %d\n", so_sci_marks);
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\t              \t  600    |    GRAND TOTAL\t    %d\n", grand_total);
    printf("|------------------------------------------------------------------------------------\n");
    if (presentage >= 81 && presentage <= 100)
    {
        printf("|RESULT : PASS IN FIRST DIVISION\n");
        printf("|GRADE  : A+\n");
    }
    if (presentage >= 60 && presentage <= 80)
    {
        printf("|RESULT : PASS IN SECOND DIVISION\n");
        printf("|GRADE  : A\n");
    }
    else if (presentage >= 33 && presentage <= 59)
    {
        printf("|RESULT : PASS IN THIRD DIVISION\n");
        printf("|GRADE  : B\n");
    }
    else if (presentage >= 1 && presentage <= 32)
    {
        printf("|RESULT : Fail\n");
        printf("|GRADE  : D\n");
    }
    printf("|------------------------------------------------------------------------------------\n\n");
}

void take_user_info()
{
    char yesNo;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter father name: ");
    scanf("%s", fa_name);

    
    printf("Enter school name: ");
    scanf("%s", s_name);

    printf("Enter date of birth: ");
    scanf("%s", dob);

    printf("Enter class: ");
    scanf("%d", &class);

    printf("Enter roll No.: ");
    scanf("%d", &roll_number);

    printf("Enter subject marks\n");

repeate:
    printf("Hindi marks: ");
    scanf("%d", &hi_marks);
    if (hi_marks > 100 || hi_marks < 1)
    {
        printf("invalid marks enter valid marks\n");
        goto repeate;
    }
repeate1:
    printf("English marks: ");
    scanf("%d", &eng_marks);
    if (eng_marks > 100 || eng_marks < 1)
    {
        printf("invalid marks enter valid marks\n");
        goto repeate1;
    }
repeate2:
    printf("Sanskrit marks: ");
    scanf("%d", &san_marks);
    if (san_marks > 100 || san_marks < 1)
    {
        printf("invalid marks enter valid marks\n");
        goto repeate2;
    }
repeate3:
    printf("Mathematics marks: ");
    scanf("%d", &math_marks);
    if (math_marks > 100 || math_marks < 1)
    {
        printf("invalid marks enter valid marks\n");
        goto repeate3;
    }
repeate4:
    printf("Science marks: ");
    scanf("%d", &sci_marks);
    if (sci_marks > 100 || sci_marks < 1)
    {
        printf("invalid marks enter valid marks\n");
        goto repeate4;
    }
repeate5:
    printf("Social science marks: ");
    scanf("%d", &so_sci_marks);
    if (so_sci_marks > 100 || so_sci_marks < 1)
    {
        printf("invalid marks enter valid marks\n");
        goto repeate5;
    }

    printf("\nIf you want to generate your marksheet then press 'Y' otherwise 'N': ");

    scanf(" %c", &yesNo);
    if (yesNo == 'y' || yesNo == 'Y')
    {
        generate_marksheet();
    }
    else
    {
        exit(0);
    }
}

void main()
{
    char yesNo;
    printf("\n             **Welcome to marksheet generation project**               \n\n");
    printf("If you want to generate your marksheet, ");
    printf("you have to provide some information\n");
    printf("If you want to provide information then press 'Y', otherwise 'N': ");
    scanf(" %c", &yesNo);
    if (yesNo == 'y' || yesNo == 'Y')
    {
        take_user_info();
    }
    else
    {
        exit(0);
    }
}
