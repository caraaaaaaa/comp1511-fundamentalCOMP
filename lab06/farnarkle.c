// COMP1511 Farnarkling lab exercises
//
// This program by Zixuan Guo (z5173593) on 28-03-2019

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define N_TILES 4
#define MAX_TILE 8
#define MAX_TURNS 100

// ADD YOUR #defines (if any) here
#define TRUE 1
#define FALSE 0

// You have to write these functions
int count_farnarkles(int tiles1[N_TILES], int tiles2[N_TILES]);
int count_arkles(int tiles1[N_TILES], int tiles2[N_TILES]);
void play_farnarkle(int hidden_tiles[]);
void farnarkle_ai(int turn, int previous_guesses[MAX_TURNS][N_TILES],
                  int farnarkles[MAX_TURNS], int arkles[MAX_TURNS],
                  int guess[N_TILES]);

// Don't change these functions
int test_farnarkle_ai(int hidden_tiles[]);
void print_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]);
void read_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]);
int read_tiles(int tiles[N_TILES]);
void print_tiles(int tiles[N_TILES]);
void set_tiles_to_pseudo_random_values(int tiles[N_TILES]);

// ADD PROTOTYPES FOR ANY FUNCTIONS YOU CREATE HERE

// DO NOT CHANGE THIS FUNCTION
// This main function won't be marked as part of the lab
// It tests the functions you have to write.
// Do not change this main function.  If it does not work with
// your functions you have misunderstood the lab.

int main(void) {
    int call_which_function = 0;

    printf("Enter 0 to call count_farnarkles()\n");
    printf("Enter 1 to call count_arkles()\n");
    printf("Enter 2 to call play_farnarkle()\n");
    printf("Enter 3 to call test_ai_farnarkle_player()\n");
    printf("Call which function: ");
    scanf("%d", &call_which_function);

    if (call_which_function == 0) {
        int tiles1[N_TILES], tiles2[N_TILES];
        read_two_tile_sequences(tiles1, tiles2);
        int farnarkles = count_farnarkles(tiles1, tiles2);
        printf("count_farnarkles returned %d for\n", farnarkles);
        print_two_tile_sequences(tiles1, tiles2);
    } else if (call_which_function == 1) {
        int tiles1[N_TILES], tiles2[N_TILES];
        read_two_tile_sequences(tiles1, tiles2);
        int arkles = count_arkles(tiles1, tiles2);
        printf("count_arkles returned %d for\n", arkles);
        print_two_tile_sequences(tiles1, tiles2);
    } else if (call_which_function == 2) {
        int hidden_tiles[N_TILES];
        set_tiles_to_pseudo_random_values(hidden_tiles);
        play_farnarkle(hidden_tiles);
    } else if (call_which_function == 3) {
        int hidden_tiles[N_TILES];
        printf("Enter hidden tiles: ");
        assert(read_tiles(hidden_tiles) == N_TILES);
        test_farnarkle_ai(hidden_tiles);
    }

    return 0;
}

// return number of farnarkles
int count_farnarkles(int tiles1[N_TILES], int tiles2[N_TILES]) {
    int i = 0;
    int j = 0;
    int counter = 0;
    while (i < N_TILES) {
        while (j < N_TILES) {
            if (tiles1[i] == tiles2[j]) {
                counter++;
            } 
            j++;
            i++;
        }   
    }
    return counter;
}

// return number of arkles
int count_arkles(int tiles1[N_TILES], int tiles2[N_TILES]) {
    int i = 0;
    int j = 0;
    int counter = 0;
    int ex1[N_TILES] = {0};
    int ex2[N_TILES] = {0};
    
    int isT1Farnarkle = (tiles1[i] == tiles2[i]);
    int isT2Farnarkle = (tiles1[j] == tiles2[j]);
    while (i < N_TILES) { 
        while (j < N_TILES) {
            int isT1Farnarkle = (tiles1[i] == tiles2[i]);
            int isT2Farnarkle = (tiles1[j] == tiles2[j]);
        
            if (tiles1[i] == tiles2[j] &&
                isT1Farnarkle == FALSE &&
                isT2Farnarkle == FALSE &&
                ex1[i] == FALSE && ex2[j] == FALSE) {
                
                counter++;
                ex1[i] = TRUE;
                ex2[j] = TRUE;
                j = N_TILES;
            } 
            j++;
        }
        i++;
        j = 0;
    }
    return counter;
}

// play_farnarkle is given a sequence of hidden tiles.
// It reads guesses from a human player,
// printing the number of farnarkles and arkles for each guess,
// until the human player guesses the sequence.

void play_farnarkle(int hidden_tiles[N_TILES]) {
    int tiles[N_TILES] = {0};
    int turn = 1;
    while (count_farnarkles(hidden_tiles, tiles) != N_TILES) {
        printf("Enter guess for turn %d:", turn);
        int z = 0;
        while (z < N_TILES) {
            scanf("%d", &tiles[z]);
            z++;
        }
        int far = count_farnarkles(hidden_tiles, tiles);
        int ark = count_arkles(hidden_tiles, tiles);
        printf("%d farnarkles, %d arkles\n", far, ark);
        
        if (far == 4) {
            turn = MAX_TURNS;
        } 
            turn++;
    
    }
    printf("You win\n");
}

// farnarkle_ai is given
//
// turn: the turn number
// previous_guesses: an array of turn - 1 previous guesses
// farnarkles: an array of turn - 1 farnarkle counts for previous guesses
// arkles: an array of turn - 1 arkle counts for previous guesses
//
// it should choose a suitable guess and store it in the array guess

void farnarkle_ai(int turn, int previous_guesses[MAX_TURNS][N_TILES],
                  int farnarkles[MAX_TURNS], int arkles[MAX_TURNS],
                  int guess[N_TILES]) {

    // PUT YOUR CODE HERE
}

// DO NOT CHANGE THE FUNCTIONS BELOW HERE

// DO NOT CHANGE THIS FUNCTION
void print_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]) {
    printf("Sequence 1: ");
    print_tiles(tiles1);
    printf("\n");
    printf("Sequence 2: ");
    print_tiles(tiles2);
    printf("\n");
}

// DO NOT CHANGE THIS FUNCTION
void read_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]) {
    printf("Enter tile sequence 1: ");
    assert(read_tiles(tiles1) == N_TILES);
    printf("Enter tile sequence 2: ");
    assert(read_tiles(tiles2) == N_TILES);
}

// DO NOT CHANGE THIS FUNCTION
// read N_TILES tiles into array tiles
// returns number of tiles successfully read
int read_tiles(int tiles[N_TILES]) {
    int i = 0;
    while (i < N_TILES) {
        if (scanf("%d", &tiles[i]) != 1) {
            return i;
        }
        if (tiles[i] < 1 || tiles[i] > MAX_TILE) {
            return i;
        }
        i = i + 1;
    }
    return i;
}

// DO NOT CHANGE THIS FUNCTION
// print tiles on a single line
void print_tiles(int tiles[N_TILES]) {
    int i = 0;
    while (i < N_TILES) {
        printf("%d", tiles[i]);
        if (i < N_TILES - 1) {
            printf(" ");
        }
        i = i + 1;
    }
}

// DO NOT CHANGE THIS FUNCTION
void set_tiles_to_pseudo_random_values(int tiles[N_TILES]) {
    // seed (initialize) pseudo-random number generate with current time in seconds
    srand(time(NULL));

    int i = 0;
    while (i < N_TILES) {
        // rand() returns a pseudo-random integer in ranger 0 to RAND_MAX inclusive
        // convert to an integer in the range 1..MAX_TILE_template
        tiles[i] = rand() % MAX_TILE + 1;
        i = i + 1;
    }
}

// DO NOT CHANGE THIS FUNCTION

// test_farnarkle_ai is given a sequence of hidden tiles
// It calls the function farnarkle_ai to make a guess
// printing the number of farnarkles and arkles for each guess,
// until farnarkle_ai guesses the sequence.
// number of turns taken is returned

int test_farnarkle_ai(int hidden_tiles[N_TILES]) {
    int guesses[MAX_TURNS][N_TILES] = {{0}};
    int farnarkles[MAX_TURNS] = {0};
    int arkles[MAX_TURNS] = {0};
    int turn_limit = MAX_TILE * N_TILES;

    int turn = 0;
    while (turn <= turn_limit) {

        int i = 0;
        while (i < N_TILES) {
            guesses[turn][i] = -1;
            i = i + 1;
        }

        printf("Turn %d: farnarkle AI guess is: ", turn + 1);
        fflush(stdout); // help debugging

        farnarkle_ai(turn + 1, guesses, farnarkles, arkles, guesses[turn]);

        print_tiles(guesses[turn]);
        printf(" = ");

        int j = 0;
        while (j < N_TILES) {
            if (guesses[turn][j] < 1 || guesses[turn][j] > MAX_TILE) {
                printf("Invalid guess\nGame ended\n");
                return 0;
            }
            j = j + 1;
        }

        farnarkles[turn] = count_farnarkles(hidden_tiles, guesses[turn]);
        arkles[turn] = count_arkles(hidden_tiles, guesses[turn]);

        printf("%d farnarkles, %d arkles\n", farnarkles[turn], arkles[turn]);

        if (farnarkles[turn] == N_TILES) {
            printf("Farnarkle AI took %d turns to guess the tiles\n", turn + 1);
            return turn + 1;
        }
        turn = turn + 1;
    }
    printf("Turn limit of %d turns exceeded\nGame ended\n", turn_limit);
    return turn + 1;
}
