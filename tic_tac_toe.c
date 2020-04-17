
//For more detailed documentation visit https://github.com/iamankitkumar08062001/Projects
//
//Standard Libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//
//Function prototypes
//
//1. Prints the Menu
void menu(int *);
//
//2. Manages Function calls 
void function_calls(int);
//
//3. Functiont to start a new game
void new_game(void);
//
//4. This function inputs player names and symbol(O or X)
void name_input(char **,char **,char *);
//
//5. This functions generates a random number based on 
//which head/tails is determined and 
//prints which player has won the toss.
int _toss(char *,char *);
//
//6. This function initialises the game_array with underscores(_).
void initialize_array(char ***);
//
//7. This prints the game array.
void print_game_array(char **);
//
//8. This function lets the player decide on which positon 
//to play their next move on and 
//inserts the symbol into the game array based on the choice.
void run_game(char ***,char,int,char *,char *);
//
//9. This function check if the game array is full or not.
int check_end(char **);
//
//10. This function checks for a win situtation
//check() functions contains the actual code to 
//check for a win situation.
char check_win(char **,int);
//
//11. This function contains the actual code to check for a win situation.
int check(char **,char);
//
//
//main() driver function
int main()
{
	//This block calls menu() and function_calls() functions
	//till user inputs 4
	int choice=0;
	while(choice!=4)
	{
		//calls menu() function and passes "choice" variable by 
		//"call by reference" method to be changed directly
		menu(&choice);
		//calls function_calls() and passes "choice" variable by
		//"call by value" method
		function_calls(choice);
	}
	//End Credits
	printf("Thank You for Playing the Game!!!\n");
	printf("Developed By BizzareKumar\n\n");
	//return 0 as a signature of successful termination
	return 0;
}
//
//This function prints menu
void menu(int *choice)
{
	printf("\n************************************MENU*****************************************************\n");
	printf("1. Start A New Game\n");
	printf("2. Resume a Previous Game\n");
	printf("3. Leaderboard\n");
	printf("4. Exit\n");
	printf("\nYour Choice : ");
	scanf(" %d",choice);
	return;
}
//
//This function calls different functions
//based on user's descision
void function_calls(int choice)
{
	switch(choice)
	{
		//Calls the new_game() function to start a new game
		case 1:new_game();
		       break;
		//Calls the resume_game() game function to continue a previously saved
		//game
		case 2:printf("Under Construction!!!\n");//resume_game();
			   return;
		//Calls the leaderboard() function and shows the Leaderboard
		case 3:printf("Under Construction!!!\n");//leaderboard();
			   return;
		//Upon returning to the main() function will end the program
		case 4:return;
		//Wrong Choice
		default:printf("\nWrong Choice!!!\n");
				return;
	}
	//End of the function
	//The program will never reach the end
	return;
}
//
void new_game(void)
{
	//Declaration of player name variables, symbol and chance variable which will 
	//test whose player turn is occuring
	char *player1_name,*player2_name,sym;
	int chance;
	//memory allocation of player name strings
	player1_name=(char *)malloc(sizeof(char)*100);
	player2_name=(char *)malloc(sizeof(char)*100);
	//name_input() function call to take 
	//player input names
	name_input(&player1_name,&player2_name,sym);
	//game_starts
	//toss() function is called to decide which player will
	//start the game and assigned to "chance" variable
	//for further use
	int chance=_toss(player1_name,player2_name);
	//game array is initialized and assigned a NULL pointer 
	//as to avoid a wild pointer
	char **game_array=NULL;
	//initialize_array() function is called to initialize the array with
	//underscores(_)
	initialize_array(&game_array);
	//Initial state of game_array is printed
	printf("\nThe Initial Game Array is\n");
	print_game_array(game_array);
	//The actual game starts here where while loop
	//will run till either someone wins or there is a draw
	//---------------------while loop----------------------------------
	while(check_win(game_array,1)!='1' && check_end(game_array)!=1)
	{
		//run_game() function is called to input player choice to make 
		//a move
		run_game(&game_array,*sym,chance,player1_name,player2_name);
		//This switch-case statement changes the chance
		//to allow each player to take his/her turn
		switch(chance)
		{
			case 0:chance=1;
					break;
			case 1:chance=0;
					break;
		}
		//print_game_array() function is called to print the current state of the array
		//after a move has been made
		printf("\nNow the State of the game is\n");
		print_game_array(game_array);
	}
	//----------------------while loop end--------------------------
	//check_win() function is called to check which player has won the match
	//when there is not a draw
	/*switch(check_win(game_array,0) && check_end(game_array)!=1)
	{
		case 'O':
				printf("Congratulations, %s has won the game!!!");
				break;
		case 'X':printf("Congratulations, %s has won the game!!!");
				break;
	}*/
	//calls check_end() function to print a DRAW message
	/*
	if(check_end(game_array)==1)
	{
		printf("\nThe match was a DRAW.!!!\n");
	}*/
	return;
}
//
//name_input() function defination
void name_input(char **player1_name,char **player2_name,char *sym)
{
	//Inputs Player 1 name
	printf("\nPlayer 1, Please Enter your Name : ");
	scanf(" %s",*player1_name);
	//player1_name string is reallocated to save space
	*player1_name=realloc(*player1_name,strlen(*player1_name));
	printf("%s, Please enter your game symbol (O or X) : ",*player1_name);
	scanf(" %c",sym);
	//If the user has entered 0 will convert 
	//sym to O to avoid problems elsewhere in
	//the code
	if((**sym)=='0')
	{
		**sym='O';
	}
	//Inputs Player 2 name
	printf("\nPlayer 2, Please Enter your Name : ");
	scanf(" %s",*player2_name);
	//player2_name string is reallocated to save space
	*player2_name=realloc(*player2_name,strlen(*player2_name));
	return;
}
//
//_toss() function defination
int _toss(char* player1_name,char* player2_name)
{
	int result;
	//a seed is generated
	srand(time(0));
	result=rand()%2;
	//result of toss is printed
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

char check_win(char **game_array,int option)
{
	if(option==0)
	{
		if(check(game_array,'X')==1)
		{
			return 'X';
		}
		if(check(game_array,'O')==1)
		{
			return 'O';
		}
	}
	else
	{
		if(check(game_array,'X')==1 || check(game_array,'O')==1)
		{
			return '1';
		}
		else
		{
			return '0';
		}
	}
}

int check(char **game_array,char sym)
{
	// --> i is used for row
	// --> j is used for columns
	// --> flag is used to detect a win situtation
	//     either of the below combinations lie on a single line
	int i,j,flag;
	//Below is the code for checking a win situtation
	//The left-most column
	// |X| X X
	// |X| X X
	// |X| X X
	flag=0;
	for(j=0;j<3;j++)
	{
		if(*(*(game_array+0)+j)==sym)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		return 1;
	}
	//The right-most column
	// X X |X|
	// X X |X|
	// X X |X|
	flag=0;
	for(j=0;j<3;j++)
	{
		if(*(*(game_array+2)+j)==sym)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		return 1;
	}
	//The top row
	// |X X X|
	//  X X X
	//  X X X
	flag=0;
	for(i=0;i<3;i++)
	{
		if(*(*(game_array+i)+0)==sym)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		return 1;
	}
	//The middle row
	//  X X X
	// |X X X|
	//  X X X
	flag=0;
	for(i=0;i<3;i++)
	{
		if(*(*(game_array+i)+1)==sym)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		return 1;
	}
	//The bottom row
	//  X X X
	//  X X X
	// |X X X|
	flag=0;
	for(i=0;i<3;i++)
	{
		if(*(*(game_array+i)+2)==sym)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		return 1;
	}
	//The left diagonal
	// |X| X X
	//  X |X| X
	//  X X |X|
	flag=0;
	for(i=0;i<3;i++)
	{
		if(*(*(game_array+i)+i)==sym)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		return 1;
	}
	//The right diagonal
	//  X X |X|
	//  X |X| X
	// |X| X X
	flag=0;
	for(i=0;i<3;i++)
	{
		if(*(*(game_array+i)+(2-i))==sym)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		return 1;
	}
	//When all of the above conditions fails
	//is a indication of no-win situtation so the
	//the function return 0 which indicates no-win
	return 0;
}
