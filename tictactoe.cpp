// A C++ Program to play tic-tac-toe

#include<bits/stdc++.h>
using namespace std;


// show the current status of board
void showBoard(char board[][3])
{
    printf("\n\n");
      
    printf("\t\t\t  %c | %c  | %c  \n", board[0][0],
                             board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0],
                             board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0],
                             board[2][1], board[2][2]);
   
    return;
}


// function to show instruction of game
void DrawTicTacToe()
{
	cout<<"\t\t\t  Tic-Tac-Toe\n"<<endl;
	cout<<"Choose a cell numbered from 1 to 9 as below and play\n"<<endl;
    cout<<"\t\t\t  1 | 2  | 3  "<<endl;
    cout<<"\t\t\t--------------"<<endl;
    cout<<"\t\t\t  4 | 5  | 6  "<<endl;
    cout<<"\t\t\t--------------"<<endl;
    cout<<"\t\t\t  7 | 8  | 9  \n"<<endl;
      
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
  
    return;
}

// declare the winner
void declareWinner(int Turn)
{
    if (Turn == 1)
        printf("COMPUTER has won\n");
    else
        printf("You won\n");
    return;
}

// check if row is crossed or not
bool rowCrossed(char board[][3])
{
    for (int i=0; i<3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] && 
            board[i][0] != ' ')
            return (true);
    }
    return(false);
}

// check if column is crossed or not
bool columnCrossed(char board[][3])
{
    for (int i=0; i<3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] && 
            board[0][i] != ' ')
            return (true);
    }
    return(false);
}

// check if diagonal is crossed or not
bool diagonalCrossed(char board[][3])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] && 
        board[0][0] != ' ')
        return(true);
          
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
         board[0][2] != ' ')
        return(true);
  
    return(false);
}


// to check if game is over or not
bool gameOver(char board[][3])
{
    return(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board) );
}

// function to start the game
void startGame(char board[][3], int moves[]){
	srand(time(0));

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j] = ' ';
		}
	}
	for(int i=0; i<9; i++){
		moves[i] = i;
	}
	random_shuffle(moves,moves + 9);

	return;	
}

void playTicTacToe(int Turn){
	//Tic Tac TOe Board of side 3*3
	char board[3][3];
	int moves[9];

	startGame(board,moves);

	DrawTicTacToe();

	int moveIndex =0, x, y;

	while (gameOver(board) == false && moveIndex != 9)
    {
        if (Turn == 1)
        {
            cout<<"COMPUTER TURN";
            x = moves[moveIndex] / 3;
            y = moves[moveIndex] % 3;
            board[x][y] = 'O';
            cout<<"COMPUTER has put a "<<board[x][y]<<" in cell "<<moves[moveIndex]+1<<endl;
            showBoard(board);
            moveIndex ++;
            Turn = 0;
        }
          
        else if (Turn == 0)
        {	
        	cout<<"YOUR TURN";
        	int input;
        	cin>>input;
            x = input / 3;
            y = input % 3;
            
            //cin>>x>>y;
            board[x][y] = 'X';
            cout<<"You put a "<<board[x][y]<<" in cell "<<input+1<<endl;
            showBoard(board);
            moveIndex ++;
            Turn = 1;
        }
    }

    
    if (gameOver(board) == false && moveIndex == 9) // if draw
        cout<<"It's a draw"<<endl;
    else
    {
        // winner declare
        if (Turn == 1)
            Turn = 0;
        else if (Turn == 0)
            Turn = 1;
          
        // Declare the winner
        declareWinner(Turn);
    }
    return;



}

// Driver Program
int main()
{
	srand(time(0));
	int start = rand()%2; // generate random number 0 or 1
	playTicTacToe(start);
	
	return (0);
}
