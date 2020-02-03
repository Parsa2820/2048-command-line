#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

void start(void);
void init_board(void);
void print_board(void);
void add_two(void);
void mv_up(void);
void mv_left(void);
void mv_right(void);
void mv_down(void);
bool is_over(void);
int score(void);
void solver(void);

int game_board[4][4];

int main()
{
	srand(time(NULL));
	printf("w = up, s = down, d = right, a = left, x = exit, r = restart\nPress any key to start\n");
	scanf("%*c");
	start();
	return 0;
}

void start (void)
{
	init_board();
	char command;
	while (true)
	{
		if (is_over())
		{
			printf("Game over. You reached %d\n", score());
			break;
		}
		print_board();
		scanf("%c", &command);
		switch (command)
		{
			case 'w':
				mv_up();
				break;
			case 's':
				mv_down();
				break;
			case 'd':
				mv_right();
				break;
			case 'a':
				mv_left();
				break;
			case 'x':
				//goto line(25);
				return;
				break;
			case 'r':
				scanf("%*c");
				start();
				break;
			default:
				printf("Command not found\n\n");
				continue;
				break;
		}
		add_two();
		printf("-------------------------------------\n");
		scanf("%*c");
	}
}

void init_board(void)
{
	for (int l = 0; l<4; l++)
		for (int m = 0; m<4; m++)
			game_board[m][l]=0;
	int i = random()%4, j = random()%4, x = random()%4, y = random()%4;
	if ((i == x) && (j == y))
		init_board();
	else
		game_board[i][j] = game_board[x][y] = 2;
}

void print_board(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%4d   ", game_board[i][j]);
		}
		printf("\n\n");
	}
}

void add_two(void)
{
	int i = random()%4, j = random()%4;
	if (!(game_board[i][j]))
		game_board[i][j] = 2;
	else
		add_two();
}

void mv_up(void)
{
	bool connected = true;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = i+1; k < 4; k++)
			{
				for (int l = i+1; l < k; l++)
					if (game_board[l][j] != 0)
						connected = false;
				if ((connected)&&(game_board[i][j] == game_board[k][j])&&(game_board[k][j])&&(game_board[i][j]))
				{
					game_board[i][j]*=2;
					game_board[k][j] = 0;
					i = k;
					break;
				}
			}
			connected = true;
		}
	}
	for (int x = 0; x<4; x++)
	{
		for (int c = 0; c<3; c++)
		{
			for (int y = 1; y<4; y++)
			{
				if ((game_board[y-1][x] == 0)&&(game_board[y][x]))
				{
					game_board[y-1][x] = game_board[y][x];
					game_board[y][x] = 0;
				}
			}
		}
	}
}

void mv_left(void)
{
	bool connected = true;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = i+1; k < 4; k++)
			{
				for (int l = i+1; l < k; l++)
					if (game_board[j][l] != 0)
						connected = false;
				if ((connected)&&(game_board[j][i] == game_board[j][k])&&(game_board[j][k])&&(game_board[j][i]))
				{
					game_board[j][i]*=2;
					game_board[j][k] = 0;
					i = k;
					break;
				}
			}
			connected = true;
		}
	}
	for (int x = 0; x<4; x++)
	{
		for (int c = 0; c<3; c++)
		{
			for (int y = 1; y<4; y++)
			{
				if ((game_board[x][y-1] == 0)&&(game_board[x][y]))
				{
					game_board[x][y-1] = game_board[x][y];
					game_board[x][y] = 0;
				}
			}
		}
	}
}

void mv_right(void)
{
	bool connected = true;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = i+1; k < 4; k++)
			{
				for (int l = i+1; l < k; l++)
					if (game_board[j][l] != 0)
						connected = false;
				if ((connected)&&(game_board[j][i] == game_board[j][k])&&(game_board[j][k])&&(game_board[j][i]))
				{
					game_board[j][k]*=2;
					game_board[j][i] = 0;
					i = k;
					break;
				}
			}
			connected = true;
		}
	}
	for (int x = 0; x<4; x++)
	{
		for (int c = 0; c<3; c++)
		{
			for (int y = 0; y<3; y++)
			{
				if ((game_board[x][y+1] == 0)&&(game_board[x][y]))
				{
					game_board[x][y+1] = game_board[x][y];
					game_board[x][y] = 0;
				}
			}
		}
	}	
}

void mv_down(void)
{
	bool connected = true;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = i+1; k < 4; k++)
			{
				for (int l = i+1; l < k; l++)
					if (game_board[l][j] != 0)
						connected = false;
				if ((connected)&&(game_board[i][j] == game_board[k][j])&&(game_board[k][j])&&(game_board[i][j]))
				{
					game_board[k][j]*=2;
					game_board[i][j] = 0;
					i = k;
					break;
				}
			}
			connected = true;
		}
	}
	for (int x = 0; x<4; x++)
	{
		for (int c = 0; c<3; c++)
		{
			for (int y = 0; y<3; y++)
			{
				if ((game_board[y+1][x] == 0)&&(game_board[y][x]))
				{
					game_board[y+1][x] = game_board[y][x];
					game_board[y][x] = 0;
				}
			}
		}
	}	
}

bool is_over(void)
{
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			if (game_board[i][j] == 0)
				return (false);
		}
	}
	return (true);
}

int score(void)
{
	int max = 2;
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			if (game_board[i][j]>max)
				max = game_board[i][j];
	return max;
}

void solver(void)
{
	int up = 0, down = 0, left = 0, right = 0;
	bool connected = true;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			for (int k = j+1; k<4; k++)
			{
				for (int l = j+1; l<k; l++)
					if (game_board[i][l])
						connected = false;
				if ((connected)&&(game_board[i][k])&&(game_board[i][j])&&(game_board[i][j]==game_board[i][k]))
				{
					left++;
					right++;
					i=k;
					break;
				}
			}
			connected = true;
		}
	}
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			for (int k = j+1; k<4; k++)
			{
				for (int l = j+1; l<k; l++)
					if (game_board[l][i])
						connected = false;
				if ((connected)&&(game_board[k][i])&&(game_board[j][i])&&(game_board[j][i]==game_board[k][i]))
				{
					up++;
					down++;
					i=k;
					break;
				}
			}
			connected = true;
		}
	}
	printf("\nHint*up:%d*left:%d\n", up, left);
}

