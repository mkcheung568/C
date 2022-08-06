

#include <stdio.h>
#include <string.h>

#define EMPTY 0
#define CIRCLE 1
#define CROSS 2

/* Initialize the game board by setting all nine squares to EMPTY */
void initGameBoard(int gameBoard[3][3]) {

    
    for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
        gameBoard[i][j]=EMPTY; //set each row and col to EMPTY =0;
    }


}
}




void printGameBoard(int gameBoard[3][3]){
int RowZero=7;
    printf("=========\n");
    /**loop for label the square array in {7,8,9},{4,5,6},{1,2,3} but the value inside array are all 0 **/
    for (int i=2;i>=0;i--){ 
        for(int j=0;j<=2;j++){
                printf("|");
                if(gameBoard[i][j]==EMPTY){
                    printf("%d", RowZero);
                }else{
                    printf("%c", gameBoard[i][j]);//if not EMPTY 0 in the array, than print O or X
                }
                
                printf("|");
                RowZero++;
                if(RowZero%3==1){
                    RowZero=RowZero-6;
                }
            
        }
        
        printf("\n");

    }
    printf("=========\n");
}

void cleanbuffer(){ // clear the buffer of input character in integer type
    int n; 
    while((n = getchar()) != EOF && n != '\n'); 
} 

/* Ask the human player to place the mark.
   In Part 1, you can assume that the user input must be valid (i.e, an empty space between 1 and 9).
   You are welcome to perform error checking in Part 2. */
void placeMarkByHumanPlayer(int gameBoard[3][3], int mark) {

   
    int input,n; //input 1-9 from user
    int RowZero=7;
 //loop for scan the user input number in the array label and replace with O or X
    
scanf("%d",&input);

while(input<1 || input>9){// user input mark and make validation
    printf("Your mark is not between 1-9 please input again! \n");
    scanf("%d",&input);
    cleanbuffer();
}
 
    for(int i=2;i>=0;i--){
        for(int j=0;j<=2;j++){
            if(input==RowZero){ //RowZero is a keep changing variable,if user input 5,first  RowZero= 7 if input not =7  RowZero will change until 5 

                if(mark==CIRCLE){

                gameBoard[i][j]= 'O';

                }else{
                    
                   gameBoard[i][j]= 'X'; 
                }
            }

            RowZero++;
            if(RowZero%3==1){
                    RowZero=RowZero-6;
            }
        }
    }
    
 printGameBoard(gameBoard); //display the latest change of the gameboard

}


/* Return 1 if there is a winner in the game, otherwise return 0 */
/* Note: the winner is the current player indicated in main() */
int hasWinner(int gameBoard[3][3]) {

     int countO=0,countX=0;
     
     //loop for scan each row for 3 'O'
      for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
              if(gameBoard[i][j]=='O'){
                  countO++;
                 
              }else if(gameBoard[i][j]=='X'){
                  countX++;
              }
          }
          if(countO==3 || countX==3){
              return 1;
              break;
          }
          countO=0;
          countX=0;
          }
        
        //loop for scan each column for 3 'O'
         for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
              if(gameBoard[j][i]=='O' ){
                  countO++;
                 
              }else if (gameBoard[j][i]=='X'){
                  countX++;
              }
          }
          
          if(countO==3 || countX==3){
              return 1;
              
              break;
          }
          countO=0;
          countX=0;
          }

          //loop for X direction from top right corner to down left corner
          if(gameBoard[2][2]=='O' && gameBoard[1][1]=='O'&& gameBoard[0][0]=='O' ){
              return 1;
              
          }else if(gameBoard[2][2]=='X' && gameBoard[1][1]=='X'&& gameBoard[0][0]=='X' ){
              return 1;
          }
         
          //loop for X direction from top Left corner to down right corner

         if(gameBoard[2][0]=='O' && gameBoard[1][1]=='O'&& gameBoard[0][2]=='O' ){
              return 1;
              
          }else if(gameBoard[2][0]=='X' && gameBoard[1][1]=='X'&& gameBoard[0][2]=='X' ){
              return 1;
          }
              

        return 0;
}
      


   
   
/* Return 1 if the game board is full, otherwise return 0 */

// TODO: Complete the isFull(...) function here

int isFull(int gameBoard[3][3]){

  for(int i=2;i>=0;i--){
        for(int j=0;j<=2;j++){
            if(gameBoard[i][j]==0){

                return 0;

            }
          }
      }
     printf("Draw game!\n");
    return 1;

   

  }





void placeMarkByComputerPlayer(int gameBoard[3][3]){

     
     if(gameBoard[1][1]==0){ 
      gameBoard[1][1]='X';
      return  printGameBoard(gameBoard);
     }

     if(gameBoard[0][0]==0){ 
      gameBoard[0][0]='X';
      return  printGameBoard(gameBoard);
     }
     if(gameBoard[2][0]==0){ 
      gameBoard[2][0]='X';
      return  printGameBoard(gameBoard);
     }
     if(gameBoard[0][2]==0){ 
      gameBoard[0][2]='X';
      return  printGameBoard(gameBoard);
     }


     for(int i=2; i>=0;i--){
         for(int j=2;j>=0;j-- ){
             if(gameBoard[i][j]==0){
                 gameBoard[i][j]='X';
                 return  printGameBoard(gameBoard);
             }
            
            
             
         }
     }
        
         

}

int numberPlayerValidation(){ // function for input the num of human player and make validation
   char charOfHumanPlayers[64];
    int numOfHumanPlayer;

    while(1){
        printf("How many human players [1-2]?\n");
        scanf("%s", charOfHumanPlayers);
        int isOne = strcmp(charOfHumanPlayers, "1"); //compare two string if two are equal return 0
        int isTwo = strcmp(charOfHumanPlayers, "2");

        if( isOne == 0){
            numOfHumanPlayer = 1;
            break;
        }else if(isTwo == 0){
            numOfHumanPlayer = 2;
            break;
        }else{
            printf("Your input is not between 1-2 please input again! \n\n");
            continue;
        }
    }


    return numOfHumanPlayer ;
}



/* The main function */
int main() {
    /* Local variables */
    int gameBoard[3][3];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1 (Human)   2: Player 2 (Human) or Computer Player
    int gameEnds;           // 0: The game continues   1: The game ends
    int numOfHumanPlayers;  // 1 or 2
    

    /* Initialize the local variables by invoking a function, using assignment statements, and reading the user input */
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameEnds = 0;

   
    numOfHumanPlayers=numberPlayerValidation();// function calling for input the no. of player

    
    if(numOfHumanPlayers==2){

    int full= isFull(gameBoard);

    printGameBoard(gameBoard);

    while(full!=1){
    
    printf("Player 1, please place your mark [1-9]:\n");
    placeMarkByHumanPlayer(gameBoard, CIRCLE);
    if(hasWinner(gameBoard)==1){
        printf("Player 1 wins! Congratulations!\n");
        break;
    }
    
    full=isFull(gameBoard); //tell if the loop that circle is full and stop
    


    if(full!=1){
    
    printf("Player 2, please place your mark [1-9]:\n");
    placeMarkByHumanPlayer(gameBoard, CROSS);
     if(hasWinner(gameBoard)==1){//if the calling function hasWinner(gameBoard) = 1  print message
        printf("Player 2 wins! Congratulations!\n");
        break;
    }
   
    }

    
     
    }

    }else if(numOfHumanPlayers==1){
     
     int full= isFull(gameBoard);

     printGameBoard(gameBoard);

       while(full!=1){
    
    printf("Player 1, please place your mark [1-9]:\n");
    placeMarkByHumanPlayer(gameBoard, CIRCLE);
    if(hasWinner(gameBoard)==1){
        printf("Player 1 wins! Congratulations!\n");
        break;
    }
    
    full=isFull(gameBoard); //tell if the loop that circle is full and stop
    


    if(full!=1){
     printf("Computer place the mark:\n");
     placeMarkByComputerPlayer(gameBoard);
    
     if(hasWinner(gameBoard)==1){//if the calling function hasWinner(gameBoard) = 1  print message
        printf("computer wins!\n");
        break;
      }
    
    }
        }
    }
    
    
    



    return 0;
}
