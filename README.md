# Projects
|S.No|Projects|
|:--:|:------:|
|1|Tic Tac Toe Game(Without Graphics)|

## Description ##
### 1.Tic Tac Toe ###
|S.No|Return Type|Function Name|Argument Type|Arguments/Parameters(Actual Parameters)|Purpose|
|:--:|:---------:|:-----------:|:------------|:-------------------------------------:|-----|
| 1  |   void    |   menu()    |    int \*   |     &choice        |To Print Menu|
| 2  |   void    |function_calls()| int      |      choice        |To Handle Different Function Calls|
| 3  |   void    |  new_game() |    void     |       N.A.         |To Start A New Game|
| 4  |   void    |  name_input()|  char \*\*, char \*\*, char \*\* | &player1\_name, &player2\_name, &sym | To take input player names and symbol |
| 5  |   int     |  \_toss()   | char \*, char \* | player1_name, player2_name | This functions generates a random number based on which head/tails is determined and prints which player has won the toss |
| 6 |    void  | initialize_array() | char \*\*\* | &game_array  | This initialises the array with underscores(\_)|
| 7 |    void  | print_game_array() | char \*\*  | game_array   | This prints the game array |
| 8 |    void  |   run_game()      | char \*\*\*, char , int, char \*, char \* | &game_array , \*sym, chance, player1_name, player2_name|This function lets the player decide on which positon to play their next move on and inserts it into the game array|
| 9|     int   |   check_end()     |  char \*\* | | |
| 10|    char  |   check_win()     |  char \*\*, int) | | |
| 11|    int   |   check()         | char \*\*, char | | |
