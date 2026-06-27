#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct {
	int game_number;
	int attempts;
	int max_limit;
} GameResult;

GameResult *initialize_game(int num, int att, int max)
{	
	GameResult *g = malloc(sizeof(GameResult));
	g->game_number = num;
	g->attempts = att;
	g->max_limit = max;
	return g;
}
void print_leaderboard(const GameResult **g, const int *arr1, int k)
{
	printf("Score(s) of the last %d game(s):\n", k);
	printf("\n");
    for (int i=0;i<k;i++)
    {
    	if(g[i]->attempts == *(arr1))
    	printf("Game %d: %d    [1st]\n",i+1,g[i]->attempts);
		else if(k > 1 && g[i]->attempts == *(arr1+1))
    	printf("Game %d: %d    [2nd]\n",i+1,g[i]->attempts);
		else if(g[i]->attempts == *(arr1+2))
    	printf("Game %d: %d    [3rd]\n",i+1,g[i]->attempts);
		else
		printf("Game %d: %d\n",i+1,g[i]->attempts);	
	}
}

int main() {
    srand(time(0));
    int n = 1;
    int k = 0;
    int *arr = NULL;
    GameResult **my_game = NULL;
	while (n != 0) {
    int choice,max,guess,attempts = 0;
    
    printf("Game %d:\n",k+1);
    printf("\n");
    printf("Difficulty levels - (1-10, 1-100, 1-1000)\n");
    printf("Enter the highest number: \n");
    scanf("%d", &max);
    choice = (rand() % max) + 1;
    
    printf("I have chosen a random number between 1-%d!\n",max);
    printf("Try and guess it!\n");
    do 
    {
		
        scanf("%d", &guess);
        ++attempts;
        
        if(guess > choice) {
            printf("Too high! Try lower.\n");
        }
        else if(guess < choice) {
            printf("Too low! Try higher.\n");
        }
        else {
        	printf("Fantastic job! You have correctly guessed the number in %d attempts!\n", attempts);
        	printf("\n");
        }
    } 
    while (guess != choice);
    
    my_game = realloc(my_game, (k+1)*sizeof(GameResult*));
    
    my_game[k] = initialize_game(k+1,attempts,max);
    
    arr = realloc(arr, sizeof(int) * (k+1));
    
    arr[k] = attempts;
    ++k;
    
    int min = 0;
    int ind = 0;
    for(int i=0;i<k;i++)
    {
    	min = arr[i];
    	ind = i;
    	for(int j=i;j<k;j++)
    	{
    		if(min>arr[j]) {
    		min = arr[j];
    		ind = j;
    		}
		}
		int temp = arr[i];
		arr[i] = min;
		arr[ind] = temp;
		
	}
	printf("==========================================\n");
	printf("==========================================\n");
    print_leaderboard(my_game, arr, k);
    printf("==========================================\n");
	printf("==========================================\n");
	printf("\n");
	printf("Do you wish to play again?\n");
    printf("Press 1 to play again or 0 to terminate the session!\n");
    scanf("%d", &n);
    printf("\n");
    printf("\n");
    printf("\n");
}
free(arr);
free(my_game);

return 0;
}
