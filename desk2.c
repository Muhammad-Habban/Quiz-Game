#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
void show_record();
void reset_score();
void help();
void showSpecificRecord();
void game();
void edit_score();
void score();
int countr, r, r1, count, i, n, indexOfStruct = 0, countForRecs = 0, randomCount = 0;
float scoreSet;
char choice;
char playername[20];
struct scoreOfPlayer
{
    int id;
    char name[100];
    float money;
};
struct scoreOfPlayer s1[20],s2[20],s3[20],s4[20];
int main()
{
    FILE *fptr;
    fptr = fopen("score.txt", "r");
    int p = 0;
    
    while (!feof(fptr))
    {
        fscanf(fptr, "%d\t%s\t%f", &s2[p].id, s2[p].name, &s2[p].money);
        p++;
        countForRecs++;
    }

    
    int flag = 1;
    system("cls");
    printf("\t\t\tC PROGRAM QUIZ GAME\n");
    printf("\n\t\t________________________________________");

    printf("\n\t\t\t   WELCOME ");
    printf("\n\t\t\t      to ");
    printf("\n\t\t\t   THE GAME ");
    printf("\n\t\t________________________________________");
    printf("\n\t\t________________________________________");
    printf("\n\t\t   BECOME A MILLIONAIRE!!!!!!!!!!!    ");
    printf("\n\t\t________________________________________");
    printf("\n\t\t________________________________________");
    printf("\n\t\t > Press S to start the game");
    printf("\n\t\t > Press V to view the highest score  ");
    printf("\n\t\t > Press R to reset score");
    printf("\n\t\t > press P to Show a specific record             ");
    printf("\n\t\t > press H for help            ");
    printf("\n\t\t > press Q to quit             ");
    printf("\n\t\t________________________________________\n\n");
    choice = toupper(getch());
    if (choice == 'V')
    {
        show_record();
        main();
    }
    else if (choice == 'H')
    {
        help();
        getch();
        main();
    }
    else if (choice == 'R')
    {
        reset_score();
        getch();
        main();
    }else if(choice == 'P')
	{
		showSpecificRecord();
	}
    else if (choice == 'Q')
        exit(1);
    else if (choice == 'S')
    {
        system("cls");
        printf("Enter an ID number.\n");
        scanf("%d", &s1[indexOfStruct].id);
        for (int k = 0; k < countForRecs+randomCount; k++)
        {
                if (s2[k].id == s1[indexOfStruct].id)
                {
                    flag = 0;
                    while (flag == 0)
                    {
                        printf("Please Enter a valid Input.\n");
                        scanf(" %d", &s1[indexOfStruct].id);
                        if (s2[k].id != s1[indexOfStruct].id)
                        {
                            flag = 1;
                        }
                    }
                }
        }
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\tResister your name:");
        scanf(" %[^\n]s", s1[indexOfStruct].name);

        system("cls");
        printf("\n ------------------  Welcome %s to C Program Quiz Game --------------------------", s1[indexOfStruct].name);
        printf("\n\n Here are some tips you might wanna know before playing:");
        printf("\n -------------------------------------------------------------------------");
        printf("\n >> Your game starts with CHALLANGE ROUND. In this round you will be asked a");
        printf("\n    total of 10 questions. Each right answer will be awarded $100,000!");
        printf("\n    By this way you can win upto ONE MILLION cash prize!!!!!..........");
        printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
        printf("\n    right option.");
        printf("\n >> You will be asked questions continuously, till right answers are given");
        printf("\n >> No negative marking for wrong answers!");
        printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
        printf("\n\n\n Press Y  to start the game!\n");
        printf("\n Press any other key to return to the main menu!");
        if (toupper(getch()) == 'Y')
        {
            game();
        }
        else
        {
            main();
            system("cls");
        }
    }
    indexOfStruct++;
    countForRecs++;
}

void show_record()
{
    system("cls");
    char name[20];
    float scr;
    
    // fscanf(f, "%s%f", &name, &scr);
    // printf("\n\n\t\t*************************************************************");
    // printf("\n\n\t\t %s has secured the Highest Score %0.2f", name, scr);
    // printf("\n\n\t\t*************************************************************");
    // fclose(f);
    // getch();
    int p = 0;
    int simpleCount = 0;
    int check;
    FILE *fptr;
    fptr = fopen("score.txt", "r");
    while (!feof(fptr))
    {
        fscanf(fptr, "%d\t%s\t%f", &s3[p].id, s3[p].name, &s3[p].money);
        //printf("%d\t%s\t%f\n", s1[p].id, s1[p].name, s1[p].money);
        p++;
        simpleCount++;
    }
    fclose(fptr);
    int min = -1;
    for(int i=0;i<simpleCount;i++)
    {
        if(s3[i].money>min)
        {
            min = s3[i].money;
            check = i;
        }
    }
    printf("\n\n\t\t*************************************************************");
    printf("\n\n\t\t %s has secured the Highest Score %0.2f",s3[check].name,s3[check].money);
    printf("\n\n\t\t*************************************************************");
    system("pause");
}

void reset_score()
{
    system("cls");
    float sc;
    char nm[20];
    FILE *f;
    f = fopen("score.txt", "r+");
    fscanf(f, "%s%f", &nm, &sc);
    sc = 0;
    fprintf(f, "%s,%.2f", nm, sc);
    fclose(f);
}

void help()
{
    system("cls");
    printf("\n\n                              HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ......................... C program Quiz Game...........");
    printf("\n >> There are two rounds in the game, WARMUP ROUND & CHALLANGE ROUND");
    printf("\n >> In warmup round you will be asked a total of 3 questions to test your general");
    printf("\n    knowledge. You will be eligible to play the game if you can give atleast 2");
    printf("\n    right answers otherwise you can't play the Game...........");
    printf("\n >> Your game starts with the CHALLANGE ROUND. In this round you will be asked");
    printf("\n    total 10 questions each right answer will be awarded $100,000.");
    printf("\n    By this way you can win upto ONE MILLION cash prize in USD...............");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option");
    printf("\n >> You will be asked questions continuously if you keep giving the right answers.");
    printf("\n >> No negative marking for wrong answers");

    printf("\n\n\t*********************BEST OF LUCK*********************************");
    printf("\n\n\t*****C PROGRAM QUIZ GAME is developed by CODE WITH C TEAM********");
}

void edit_score()
{
    system("cls");
    // float sc;
    // char nm[20];
    // FILE *f;
    // f = fopen("score.txt", "r");
    // fscanf(f, "%s%f", &nm, &sc);
    // if (scoreSet >= sc)
    // {
    // 	sc = scoreSet;
    // 	fclose(f);
    // 	f = fopen("score.txt", "w");
    // 	fprintf(f, "%s\n%.2f", plnm, sc);
    // 	fclose(f);
    // }
    FILE *f;
    f = fopen("score.txt", "a");
    fprintf(f, "%d\t%s\t%.2f\n", s1[indexOfStruct].id, s1[indexOfStruct].name, s1[indexOfStruct].money);
    fclose(f);
}

void game()
{
    printf("*****WLECOME*****\n");
    countr = 0;
    srand(time(0));
    int x = rand() % 10;
    r = x;
    for (i = 1; i <= 10; i++)
    {
        system("cls");
        r++;
        switch (r)
        {
        case 1:
            printf("\n\nWhat is the National Game of England?");
            printf("\n\nA.Football\t\tB.Basketball\n\nC.Cricket\t\tD.Baseball");
            if (toupper(getch()) == 'C')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is C.Cricket");
                getch();
                score();
                break;
            }

        case 2:
            printf("\n\n\nWho was the first Prime Minister of Pakistan.");
            printf("\n\nA.Liaqat Ali Khan\t\tB.Quaid-e-Azam\n\nC.Allama Iqbal\t\tD.Khawaja Nazimuddin");
            if (toupper(getch()) == 'A')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is A.Liaqat Ali Khan");
                getch();
                score();
                break;
            }

        case 3:
            printf("\n\n\nWhihc is the highest mountain peek situated in Pakistan.");
            printf("\n\nA.Mount Everest\t\tB.Nanga Parbat\n\nC.K-2\t\tD.Himalayas");
            if (toupper(getch()) == 'C')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is C.K-2");
                getch();
                score();
                break;
            }

        case 4:
            printf("\n\n\nWHo Invented Electricity?");
            printf("\n\nA.Nikola Tesla\t\tB.Thomas Edison\n\nC.Maxwell\t\tD.Coulomb");
            if (toupper(getch()) == 'A')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is A.Nikola Tesla");
                getch();
                score();
                break;
            }

        case 5:
            printf("\n\n\nIn what unit is electric power measured?");
            printf("\n\nA.Coulomb\t\tB.Watt\n\nC.Power\t\tD.Units");
            if (toupper(getch()) == 'B')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is B.Watt");
                getch();
                score();
                break;
            }

        case 6:
            printf("\n\n\nHow many colors in the flag of Pakistan?");
            printf("\n\nA.3\t\tB.2\n\nC.1\t\tD.4");
            if (toupper(getch()) == 'B')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is B.2");
                score();
                getch();
                break;
            }

        case 7:
            printf("\n\n\nWhat is the capitol of Japan?");
            printf("\n\nA.Nagoya\t\tB.Osaka\n\nC.Yokohama\t\tD.Tokyo");
            if (toupper(getch()) == 'D')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is D.Tokyo");
                getch();
                score();
                break;
            }

        case 8:
            printf("\n\n\nHow many times a stranded piece of paper (A4) can be folded at the most?");
            printf("\n\nA.6\t\tB.7\n\nC.8\t\tD.9");
            if (toupper(getch()) == 'B')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is B.7");
                getch();
                score();
                break;
            }

        case 9:
            printf("\n\n\nWhat was the original capital of Pakistan?");
            printf("\n\nA.Karachi\t\tB.Lahore\n\nC.Islamabad\t\tD.Faislabad");
            if (toupper(getch()) == 'A')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is A.Karachi");
                getch();
                score();
                break;
            }

        case 10:
            printf("\n\n\nWhich is the longest River in the world?");
            printf("\n\nA.Nile\t\tB.Koshi\n\nC.Ganga\t\tD.Amazon");
            if (toupper(getch()) == 'A')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is A.Nile");
                getch();
                break;
                score();
            }

        case 11:
            printf("\n\n\nWhat is the color of the Black Box in aeroplanes?");
            printf("\n\nA.White\t\tB.Black\n\nC.Orange\t\tD.Red");
            if (toupper(getch()) == 'C')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is C.Orange");
                getch();
                break;
                score();
            }

        case 12:
            printf("\n\n\nWhich country has the famous Colosseum of Rome?");
            printf("\n\nA.Italy\t\tB.Paris\n\nC.Spain\t\tD.Germany");
            if (toupper(getch()) == 'A')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is A.Italy");
                getch();
                break;
                score();
            }

        case 13:
            printf("\n\n\nWorld War 2 started in what year?");
            printf("\n\nA.1914\t\tB.1919\n\nC.1935\t\tD.1939");
            if (toupper(getch()) == 'D')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is D.1939");
                getch();
                break;
                score();
            }

        case 14:
            printf("\n\n\nWho is the author of 'Harry Potter'?");
            printf("\n\nA.J.K.Rowling\t\tB.Stephen King\n\nC.B.P. Koirala\t\tD.Alex Michaelides");
            if (toupper(getch()) == 'A')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is A.J.K.Rowling");
                getch();
                break;
                score();
            }

        case 15:
            printf("\n\n\nWhich Blood Group is known as the Universal Recipient?");
            printf("\n\nA.A\t\tB.AB\n\nC.B\t\tD.O");
            if (toupper(getch()) == 'B')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is B.AB");
                getch();
                score();
                break;
            }

        case 16:
            printf("\n\n\nWhat is the unit of measurement of distance between Stars?");
            printf("\n\nA.Light Year\t\tB.Coulomb\n\nC.Nautical Mile\t\tD.Kilometer");
            if (toupper(getch()) == 'A')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is A.Light Year");
                getch();
                score();
                break;
            }

        case 17:
            printf("\n\n\nThe country famous for Samba Dance is......");
            printf("\n\nA.Brazil\t\tB.Venezuela\n\nC.Nigeria\t\tD.Bolivia");
            if (toupper(getch()) == 'A')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is A.Brazil");
                getch();
                score();
                break;
            }

        case 18:
            printf("\n\n\nWhich of the following films is directed by the Christopher Nolan__________?");
            printf("\n\nA.Inception\t\tB.Tenet\n\nC.Interstellar\t\tD.All of above mentioned\n\n");
            if (toupper(getch()) == 'D')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is D.All of above mentioned");
                getch();
                score();
                break;
            }

        case 19:
            printf("\n\n\nWhich city in the world is popularly known as The City of Lights?");
            printf("\n\nA.Delhi\tB.Lahore\n\nC.Karachi\tD.Islamabad\n\n");
            if (toupper(getch()) == 'C')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is C.Karachi");
                getch();
                score();
                break;
            }

        case 20:
            printf("\n\n\nWhich of the following Tennis Player has won the most Wimbeldon Championship?");
            printf("\n\nA.Rafay Nadal\t\tB.Roger Fedrer\n\nC.Novak Djokovic\t\tD.Serena Williams");
            if (toupper(getch()) == 'B')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is B.Roger Fedrer");
                getch();
                score();
                break;
            }

        case 21:
            printf("\n\n\nOzone plate is being destroyed regularly because of____ ?");
            printf("\n\nA.L.P.G\t\tB.Nitrogen\n\nC.Methane\t\tD. C.F.C");
            if (toupper(getch()) == 'D')
            {
                printf("\n\nCorrect!!!");
                countr++;
                getch();
                break;
            }
            else
            {
                printf("\n\nWrong!!! The correct answer is D. C.F.C");
                getch();
                score();
                break;
            }
        }
    }
    if(countr == 10)
    {
        score();
    }else
    {
        main();
    }
}

void score()
{
    system("cls");
    scoreSet = (float)countr * 100000;
    s1[indexOfStruct].money = scoreSet;
    if (scoreSet > 0.00 && scoreSet < 1000000)
    {
        printf("\n\n\t\t**************** CONGRATULATION *****************");
        printf("\n\t You won $%.2f\n", scoreSet);\
        system("pause");
        edit_score();
        main();
    }

    else if (scoreSet == 1000000.00)
    {
        printf("\n\n\n \t\t**************** CONGRATULATION ****************");
        printf("\n\t\t\t\t YOU ARE A MILLIONAIRE!!!!!!!!!");
        printf("\n\t\t You won $%.2f", scoreSet);
        printf("\t\t Thank You!!\n");
        system("pause");
    }
    else
    {
        printf("\n\n\t******** SORRY YOU DIDN'T WIN ANY CASH ********");
        printf("\n\t\t Thanks for your participation");
        printf("\n\t\t TRY AGAIN\n");
        system("pause");
        edit_score();
        main();
    }
}
void showSpecificRecord()
{
	int p = 0;
    int simpleCount = 0;
    int check,idNum,flag=0;
    FILE *fptr;
    fptr = fopen("score.txt", "r");
    while (!feof(fptr))
    {
        fscanf(fptr, "%d\t%s\t%f", &s4[p].id, s4[p].name, &s4[p].money);
        //printf("%d\t%s\t%f\n", s1[p].id, s1[p].name, s1[p].money);
        p++;
        simpleCount++;
    }
    fclose(fptr);
	printf("Enter an ID number.\n");
	scanf("%d", &idNum);
	for(int i=0;i<simpleCount;i++)
	{
		if(idNum==s4[i].id)
		{
			flag=1;
			check=i;
			break;
		}
	}
	if(flag==1)
	{
		system("cls");
		printf("The record is following:\n");
		printf("%d\t%s\t%.2f\n", s4[check].id, s4[check].name, s4[check].money);
		system("pause");
		main();
	}else{
		system("cls");
		printf("ID WAS NOT FOUND.\n");
		system("pause");
		main();
	}
}

