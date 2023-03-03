#include"stdio.h"
#include"string.h"
#include"math.h"
#include"stdlib.h"

#define SIZE 6      /*the size of chessboard*/
#define TRUE 1
#define FLASE 0
char player_c='o';  /*the symbol of player's chess pieces*/
char comp_c='x';    /*the symbol of computer's chess pieces*/
char board[SIZE][SIZE]={0}; /*the chess board*/
typedef int BOOL;


void show(char board[][SIZE]);
int valid_move(char board[][SIZE],int x,int y,char player,BOOL move_or_not);
int end_judge(char player);
void winner();
int get_comp_score(char board[][SIZE]);
void comp_play();
void array_copy(char new_board[][SIZE],char board[][SIZE]);

int main()
{
	int  x,y;
	int  size;
	int  i,j;
	int temp=0;
	char player=comp_c;
//	char board2[SIZE][SIZE]={0};
	printf("/*这是一个6*6的黑白棋游戏，玩家和电脑进行对决玩家是o，电脑是x；每次下棋时，只能将棋子放置在对手旁，使对手在对角线，水平线或垂直线上的棋子被自己的棋子围住，这样对手的棋子就变成自己的棋子了，游戏结束时棋子多的玩家获胜。如果所有的方格都放置了棋子，或者没有玩家在放下棋子后能将对方的棋子变成自己的，那么游戏结束*/\n\n");
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			board[i][j]=' ';
	size=SIZE/2;
	board[size][size]=board[size-1][size-1]=player_c;
	board[size][size-1]=board[size-1][size]=comp_c;   /*initialize the board*/
	show(board);

	while(1)
	{
		player=player==player_c?comp_c:player_c;  /*通过player实现依次下棋*/
		if(player==player_c)                      /*player 下棋*/
		{
			if(!end_judge(player_c))
			{
			    printf("the game is over\n");  /*如果无棋可下，则比赛终结*/
				winner();                      /*who is the winner*/
			    break;
			}                   
		    printf("please play input the position you want to put(format: x y): ");
		    scanf("%d",&x);
		    getchar();
		    scanf("%d",&y);
		    x-=1; y-=1;           /* get the real pisition in array board*/
	        temp=valid_move(board,x,y,player_c,1);
		    if(temp)
			{
			    show(board);      /*if position is valid,show the board*/
			}
		    else
			{
			    printf("violate the rule,please try again\n");
				player=comp_c;    /*使下一次仍旧由player下棋*/
			}
		}
		else                      /*电脑下棋*/
		{
			if(!end_judge(comp_c))
			{
			    printf("the game is over\n");  /*如果无棋可下，则比赛终结*/
				winner();
			    break;
			} 
			comp_play();
			show(board);
		}
	}
	return 0;
}

void comp_play()
{
	int i=0,j=0;
	int temp=0;
	int score=0;
	int best_score=0;
	int best_row=0,best_col=0;
	int temp2=0;
	char new_board[SIZE][SIZE]={0};
	array_copy(new_board,board);  /*copy the board*/
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
		{
			if(board[i][j]==' ')
			{
				temp=valid_move(board,i,j,comp_c,0);
			    if(temp)
				{
					temp=valid_move(new_board,i,j,comp_c,1);
					score=get_comp_score(new_board);
					if(best_score<score)
					{
						best_score=score;
						best_row=i;
						best_col=j;
					}
					array_copy(new_board,board);            /*令改变了的new_board重新等于board*/				
				}
			}
		}
	temp2=valid_move(board,best_row,best_col,comp_c,1);
	printf("the position computer put is %d,%d\n",best_row+1,best_col+1);

}
void array_copy(char new_board[][SIZE],char board[][SIZE])
{
	int i=0,j=0;
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			new_board[i][j]=board[i][j];
}
int get_comp_score(char board[][SIZE])
{
	int i,j;
	int score=0;
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			if(board[i][j]==comp_c)
				score++;
	return score;
}

/*who is the winner*/
void winner()     
{
	int player=0,comp=0,i=0,j=0;
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
		{
			if(board[i][j]==player_c)
				player++;
			else if(board[i][j]==comp_c)
				comp++;
		}
	printf("the score of player is %d\n",player);
    printf("the score of computer is %d\n",comp);
	if(player==comp)
		printf("the game ended in a DRAW\n");
	else if(player>comp)
		printf("the winner is PLAYER\n");
	else 
		printf("the winner is COMPUTER\n");
}

int end_judge(char player)
{
	int count=0,i=0,j=0;
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
		{
			if(board[i][j]==' ')
				count+=valid_move(board,i,j,player,0);
			if(count)
				goto ex;
		}
ex: if(count)
		return 1;
	else
		return 0;
}

void show(char board[][SIZE]) /*show the chessboard*/
{
	int row,col;
	printf("  ");
	for(col=0;col<SIZE;col++)
		printf("  %d ",col+1);  /*在棋盘的最顶端显示列的下标*/
	printf("\n");
	for(row=0;row<SIZE;row++)
	{
		printf("  +");
		for(col=0;col<SIZE;col++)
			printf("---+");
		printf("\n");
		printf("%2d|",row+1);
		for(col=0;col<SIZE;col++)
			printf(" %c |",board[row][col]);
		printf("\n");
	}
	printf("  +");             /*the last line*/
	for(col=0;col<SIZE;col++)
		printf("---+");
	printf("\n\n");
}

/*判断下棋位置是否正确有效,如果有效再根据move_or_not的值判断是否
放置棋子于此，若放置则按规则将符合要求的对方的棋子变成我方的*/
int valid_move(char board[][SIZE],int x,int y,char player,BOOL move_or_not)
{
	int row=x,col=y;
	char opponent=player_c;
	int i=0,j=0;
	int num_of_valid=0; 
	/*int valid[SIZE][SIZE];
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			valid[i][j]=FLASE;*/
	opponent=player==player_c?comp_c:player_c;/*获得对手的棋子符号*/
	if(board[row][col]!=' ')
		return 0;
	for(i=-1;i<2;i++)
		for(j=-1;j<2;j++)
		{
			if(x+i<0||x+i>=SIZE||y+j<0||y+j>=SIZE)
				continue;
			if(board[x+i][y+j]!=opponent)
				continue;
			else
			{
				row=x;
				col=y;
				for(;;)
				{
					row+=i;
					col+=j;
					if(row<0||row>=SIZE||col<0||col>=SIZE)
						break;
					if(board[row][col]==player)
					{
	                    
						if(move_or_not)/*如果move_or_not为1，在此放置棋子并且，按规则将对方的棋子变为我方的*/
						{              /*如果move_or_not为0，则仅仅进行是否为有效位置的判断*/
						board[x][y]=player;
						for(;;)
						{
							row-=i;
							col-=j;
							if(board[row][col]==player)
								break;
							else
								board[row][col]=player;
						}
						}
						//valid[x][y]=TRUE;
						num_of_valid++;
				        break;
					}
				}
			}
		}
	return num_of_valid;

}