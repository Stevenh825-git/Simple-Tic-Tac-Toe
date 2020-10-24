#include <iostream>
#include <ctype.h>

using namespace std;

const int row = 3;
const int col = 3;

enum STATUS {EMPTY, INVALID, VICTORY, UNDECIDED, TIE};

class Position{
	public:
	int x;
	int y;
};

void set_board(char a[][col])
{
	for (int i = 0; i < row; i ++)
	{
		for(int k =0; k < col; k++)
		{
			a[i][k] = ' ';
		}
	}
}

void print_board(char a[][col])
{
	cout << "   0    1    2"<<endl;
	for (int i = 0; i < row; i ++)
	{
		cout << i << " ";
		for(int k =0; k < col; k++)
		{
			cout <<" "<<	a[i][k] <<"  ";
			if(k < col-1)
			{
				cout <<"|";
			}
		}
		cout << endl;
		if(i < row -1)
		{
				cout << "  --------------" <<endl;
		}
	}
}

STATUS valid_move(char a[][col], Position input)
{
	if(input.x >= row or input.y >= col)
	{
		return INVALID;
	}
	if(a[input.x][input.y] != ' ')
	{
		return INVALID;
	}
	return EMPTY;
}

bool check_all_positions(char a[][col])
{
	for (int i = 0; i < row; i ++)
	{
		for(int k =0; k < col; k++)
		{
			if(a[i][k] == ' ')
			{
				return true;
			}
		}
	}
	return false;
}

void move (char a[][col], Position input, char symbol)
{
	if(valid_move(a, input) == EMPTY)
	{
		a[input.x][input.y] = symbol;
	}
	else 
	{
		cout << "Invalid move. Try again." << endl;
	}
}

STATUS check_progress(char a[][col], char & winner)
{
	if(a[0][0] == a[0][1] and a[0][1] == a[0][2])
	{
		if(a[0][0] != ' ')
		{
			if(a[0][0] == 'X')
			{
				winner = 'X';
			}
			else
			{
				winner = 'O';
			}
			return VICTORY;
		}
	}
	 if(a[0][0] == a[1][1] and a[1][1]==a[2][2])
	{
		if(a[0][0] != ' ')
		{
			if(a[0][0] == 'X')
			{
				winner = 'X';
			}
			else
			{
				winner = 'O';
			}
			return VICTORY;
		}
	}
	if(a[0][2] == a[1][1] and a[1][1]==a[2][0])
	{
		if(a[0][2] != ' ')
		{
			if(a[0][2] == 'X')
			{
				winner = 'X';
			}
			else
			{
				winner = 'O';
			}
			return VICTORY;
		}
	}
	
 if(a[0][0] == a[1][0] and a[1][0]==a[2][0])
	{
		if(a[0][0] != ' ')
		{
			if(a[0][0] == 'X')
			{
				winner = 'X';
			}
			else
			{
				winner = 'O';
			}
			return VICTORY;
		}
	}
 if(a[0][1] == a[1][1] and a[1][1]==a[2][1])
	{
		if(a[0][1] != ' ')
		{
			if(a[0][1] == 'X')
			{
				winner = 'X';
			}
			else
			{
				winner = 'O';
			}
			return VICTORY;
		}
	}
	if(a[0][2] == a[1][2] and a[1][2]==a[2][2])
	{
		if(a[0][2] != ' ')
		{
			if(a[0][2] == 'X')
			{
				winner = 'X';
			}
			else
			{
				winner = 'O';
			}
			return VICTORY;
		}
	}
	
	if(a[1][0] == a[1][1] and a[1][1]==a[1][2])
	{
		if(a[1][0] != ' ')
		{
			if(a[1][0] == 'X')
			{
				winner = 'X';
			}
			else
			{
				winner = 'O';
			}
			return VICTORY;
		}
	}
	
	
 if(a[2][0] == a[2][1] and a[2][1] == a[2][2])
	{
		if(a[2][0] != ' ')
		{
			if(a[2][0] == 'X')
			{
				winner = 'X';
			}
			else
			{
				winner = 'O';
			}
			return VICTORY;
		}
	}
		return UNDECIDED;

	
}


void start_game(char &symbol, Position & input, STATUS &game, char & winner, char board[][col])
{
	int error_counter = 0;
		do{
			if(check_all_positions(board))
			{
				cout << endl << endl;
				cout << "Enter a position by ROW  & COL.  " << endl;
				do{
					if(error_counter > 0)
					{
						cout << "Keep it between 0 - 2." << endl;
					}
					cin >> input.x >> input.y;
					
					while(cin.fail())
					{
						cin.clear();
						cin.ignore(100000, '\n');
						
						cout<< "You have entered wrong input. Enter valid ROW & COL" <<endl;

						cin >> input.x >> input.y;
					}
					
					error_counter++;
					
				}while(input.x >= row or input.y >= col);
				error_counter = 0;  
				do{
					cout << "Enter X or O: " << endl;
					cin >> symbol;
								
					symbol = toupper(symbol);
				
					}while(symbol != 'X' and symbol != 'O');
					
					move(board,input, symbol);
					cout << endl;
					print_board(board);
					game = check_progress(board,winner);
			}
			else
			{
				game = TIE;
				winner = TIE;
			}
	
		}while(game==UNDECIDED);	
}

int greater_count(int &x,int & o,int & greater)
{
	if(x>o)
	{
		greater = x;
	}
	else
	{
		greater = o;
	}
	return greater;
}

int symbol_count(char a[][col])
{
	int x = 0;
	int o = 0;
	int greater;
	for(int i = 0;i < row; i++)
	{
		for(int k =0; k < col; k++)
		{
			if(a[i][k] == 'X')
			{
				x++;
			}
			else if(a[i][k] =='O')
			{
				o++;
			}
		}
	}
	return greater_count(x,o,greater);
}



int main()
{
	char board[row][col];
	set_board(board);
	print_board(board);
	
	STATUS game = UNDECIDED;
	char symbol;
	Position input;
	
	char winner = ' ';
	
	
	start_game(symbol,input,game, winner, board);
	
	int turns = symbol_count(board);

	
	if(winner == TIE)
	{
		cout << "A tie! There are no valid moves left. The game lasted " << turns << " turns. " << endl;
	}
	else
	{
		cout << "Game complete! " << winner << " won the game in " << turns <<" turns." << endl;
	}
	
	
}