#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int menu(void); 
void function_calls(int);
void new_game(void);
void name_input(char **,char **,char **);
int _toss(char *,char *);
void initialize_array(char ***);
void print_game_array(char **);
void run_game(char ***,char,int,char *,char *);
int check_end(char **);
void check_win(char **);

int main()
{
	int choice=0;
	while(choice!=4)
	{
		choice=menu();
		function_calls(choice);
	}
	printf("Thank You for Playing the Game!!!\n");
	printf("Developed By BizzareKumar\n\n");
	return 0;
}

int menu(void)
{
	int choice;
	printf("\n************************************MENU*****************************************************\n");
	printf("1. Start A New Game\n");
	printf("2. Resume a Previous Game\n");
	printf("3. Leaderboard\n");
	printf("4. Exit\n");
	printf("\nYour Choice : ");
	scanf(" %d",&choice);
	return choice;
}

void function_calls(int choice)
{
	switch(choice)
	{
		case 1:new_game();
		       break;
		case 2:printf("Under Construction!!!\n");//resume_game();
			   return;
		case 3:printf("Under Construction!!!\n");//leaderboard();
			   return;
		case 4:return;
	}
}

void new_game(void)
{
	char *player1_name,*player2_name,*sym;
	int chance;
	player1_name=(char *)malloc(sizeof(char)*100);
	player2_name=(char *)malloc(sizeof(char)*100);
	name_input(&player1_name,&player2_name,&sym);
	//game_starts
	int toss=_toss(player1_name,player2_name);
	chance=toss;
	char **game_array=NULL;
	initialize_array(&game_array);
	printf("\nThe Initial Game Array is\n");
	print_game_array(game_array);
	while(check_end(game_array)!=1)
	{
		run_game(&game_array,*sym,chance,player1_name,player2_name);
		print_game_array(game_array);
		switch(chance)
		{
			case 0:chance=1;
					break;
			case 1:chance=0;
					break;
		}
		printf("\nNow the State of the game is\n");
		print_game_array(game_array);
	}
	return;
}

void name_input(char **player1_name,char **player2_name,char **sym)
{
	printf("\nPlayer 1, Please Enter your Name : ");
	scanf(" %s",*player1_name);
	*player1_name=realloc(*player1_name,strlen(*player1_name));
	//printf("%s, Please enter your game symbol (O or X) : ",*player1_name);
	//scanf(" %c",*sym);
	printf("\nPlayer 2, Please Enter your Name : ");
	scanf(" %s",*player2_name);
	*player2_name=realloc(*player2_name,strlen(*player2_name));
	return;
}

int _toss(char* player1_name,char* player2_name)
{
	int result;
	srand(time(0));
	result=(rand()%2)+1;
	printf("\n\nThe Result of the Toss : ");
	switch(result)
	{
		case 0:printf("%s wins the toss!!!\n",player1_name);
			   break;
		case 1:printf("%s wins the toss!!!\n",player2_name);
			   break;
	}
	return result;
}

void initialize_array(char ***game_array)
{
	*game_array=(char **)malloc(sizeof(char *)*3);
	int i;
	for(i=0;i<3;i++)
	{
		*((*game_array)+i)=(char *)malloc(sizeof(char)*3);
	}
	int j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			*(*((*game_array)+i)+j)='_';
		}
	}
	return;
}

void print_game_array(char **game_array)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("%c ",*(*(game_array+i)+j));
		}
	}
	printf("\n");
	return;
}

void run_game(char ***game_array,char sym,int chance,char *player1_name,char *player2_name)
{
	int i,j;
	char player1_sym=sym,player2_sym;
	switch(sym)
	{
		case 'O':player2_sym='X';
		        break;
		case '0':player2_sym='X';
				break;
		case 'X':player2_sym='O';
				break;
	}
	switch(chance)
	{
		case 0: printf("\n%s, Please enter the position where you want make your next move\n",player1_name);
				printf("Please enter row number : ");
				scanf(" %d",&i);
				printf("Please enter column number : ");
				scanf(" %d",&j);
				*(*((*game_array)+i)+j)=player1_sym;
				return;
		case 1: printf("\n%s, Please enter the position where you want make your next move\n",player2_name);
				printf("Please enter row number : ");
				scanf(" %d",&i);
				printf("Please enter column number : ");
				scanf(" %d",&j);
				*(*((*game_array)+i)+j)=player2_sym;
				return;
	}
	return;
}

int check_end(char **game_array)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(*(*(game_array+i)+j)=='_')
			{
				return 0;
			}
		}
	}
	return 1;
}