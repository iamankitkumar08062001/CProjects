# Projects
|S.No|Projects|Comments|
|:--:|:------:|:------:|
|1|Tic Tac Toe Game|Without Graphics|
|2|Matrix Rotation Layer-wise|None|
|3|Text Editor|Without any Data Structure|
|4|Text Editor|Using Hash Tables|

## Description ##
## 1.Tic Tac Toe ##
<!--============================================ TABLE ====================================================-->
|S.No|Return Type|Function Name|Argument Type|Arguments/Parameters(Actual Parameters)|Purpose|
|:--:|:---------:|:-----------:|:------------|:-------------------------------------:|-----|
| 1  |   void    |   menu()    |    int \*   |     &choice        |To Print Menu.|
| 2  |   void    |function_calls()| int      |      choice        |To Handle Different Function Calls.|
| 3  |   void    |  new_game() |    void     |       N.A.         |To Start A New Game.|
| 4  |   void    |  name_input()|  char \*\*, char \*\*, char \*\* | &player1\_name, &player2\_name, &sym | To take input player names and symbol. |
| 5  |   int     |  \_toss()   | char \*, char \* | player1_name, player2_name | This functions generates a random number based on which head/tails is determined and prints which player has won the toss. |
| 6 |    void  | initialize_array() | char \*\*\* | &game_array  | This initialises the array with underscores(\_).|
| 7 |    void  | print_game_array() | char \*\*  | game_array   | This prints the game array. |
| 8 |    void  |   run_game()      | char \*\*\*, char , int, char \*, char \* | &game_array , \*sym, chance, player1_name, player2_name|This function lets the player decide on which positon to play their next move on and inserts it into the game array.|
| 9|     int   |   check_end()     |  char \*\* | game_array | This function check if the game array is full or not to detect a draw situation. |
| 10|    char  |   check_win()     |  char \*\*, int | game_array, Option(A Number)| This function checks for a win situtation</br>check() functions contains the actual code to check for a win situation.</br>Options are:-</br>1. 1 to trigger to check who has won, and</br>2. Any other number to check if there is a win situation|
| 11|    int   |   check()         | char \*\*, char | game_array, sym | This function contains the actual code to check for a win situation. |
<!--============================================ TABLE END ====================================================-->
#### NOTES ####
1. check() and check_win() is kept separate to make the code more readable, check() contains the actual code.
2. Due to high probability of 0 than 1 in rand()%2, most of the times 2nd player will win the toss.
#### Features to be Added ####
1. Leaderboard
2. Save Game Feature
3. Resume Game
## 2. Matrix Rotation Layer-wise ##
