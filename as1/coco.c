// Assignment 1 19T1 COMP1511 Coco
// This program was written by Zixuan Guo (z5173593)
// on 26-03-2019

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49

// IF YOU NEED MORE #defines ADD THEM HERE
#define MINI                  0
#define TRUE                  1
#define FALSE                 0
#define CARD_IN_ONE_ROUND     3
#define HISTORY_PLAYED       39
#define N_CARD_RECEIVED       3
#define DOUGLAS              42


void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
int find_max (int array[]);

int check_prime (int num);
int check_coco (int num1, int num2);
int check_valid_max (int array[], int size, int value);

int round_max2 (int num1, int num2);
int round_max3 (int num1, int num2, int num3);

int round_max_p2 (int num1, int num2);
int round_max_p3 (int num1, int num2, int num3);

// main function
int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {

    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME

    printf("Carry Harry\n");

}

void choose_discards(void) {
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
    // NOTE: THE PROVIDED CODE PROBABLY DISCARDS CARDS NOT IN YOUR HAND
    // WHICH IS NOT LEGAL AND WILL RECEIVE PENALTY POINTS
    // YOU MUST CHANGE IT TO DISCARD CARDS FROM YOUR HAND.
    
    //scan cards in hands
    int card_array[N_CARDS_INITIAL_HAND];
    for (int i = 0;i < N_CARDS_INITIAL_HAND;i++) {
        int card;
        scanf("%d\n",&card);
        card_array[i] = card;          
    }                                           
    
    //store prime number and count the amount of prime number
    // amountOfPrime is the amount of prime number
    int n = 0;
    int numberOfPrime = 0;
    int prime_num[N_CARDS_INITIAL_HAND] = {0};
    for (int i = 0;i < N_CARDS_INITIAL_HAND;i++) {
        if (check_prime(card_array[i]) == TRUE) {
            prime_num[n] = card_array[i];
                // printf("%d ", prime_num[n]);
            n++;
            numberOfPrime++;
        }
    }
    
    n = 0;
    int non_prime[N_CARDS_INITIAL_HAND] = {0};
    for (int i = 0; i < N_CARDS_INITIAL_HAND; i++) {
        if (check_prime(card_array[i]) == FALSE) {
            non_prime[n] = card_array[i];
                // printf("%d ", non_prime[n]); 
            n++;
        }
    }
    
    //store cards which is going to be discard
    int discard_list[N_CARDS_DISCARDED] = {0};
    //check if it has 42 in list, discard it first
    for (int i = 0;i < N_CARDS_INITIAL_HAND;i++) {
        if (card_array[i] == DOUGLAS) {
            discard_list[0] = DOUGLAS;
        }
    }
    
    //three max_prime number in the list
    //delete the maximu number in prime list
    int max_prime = find_max(prime_num);
    int second_prime = find_max(prime_num);
    int third_prime = find_max(prime_num);
    
    int max_nonprime = find_max(non_prime);
    int second_nonprime = find_max(non_prime);
    int third_nonprime = find_max(non_prime);
    
    // check if 42 in the discard_list
    // if 42 is in the list, discard 42 and two larger prime
    if (discard_list[0] == DOUGLAS) {
        if (numberOfPrime >= 2) {
            discard_list[1] = max_prime;
            discard_list[2] = second_prime;
        } 
        if (numberOfPrime == 1) {
            discard_list[1] = max_prime;
            discard_list[2] = max_nonprime;
        } 
        if (numberOfPrime == 0) {
            discard_list[1] = max_nonprime;
            discard_list[2] = second_nonprime;
            
        } 
    // if 42 is not in the list, discard three large prime
    } else {
        if (numberOfPrime >= 3) {
            discard_list[0] = max_prime;
            discard_list[1] = second_prime;
            discard_list[2] = third_prime;
        }
        if (numberOfPrime == 2) {
            discard_list[0] = max_nonprime;
            discard_list[1] = max_prime;
            discard_list[2] = second_prime;
        } 
        if (numberOfPrime == 1) {
            discard_list[0] = max_nonprime;
            discard_list[1] = max_prime;
            discard_list[2] = second_nonprime;
        }
    }
    
    printf("%d %d %d \n",discard_list[0], discard_list[1], discard_list[2]);
}


void choose_card_to_play(void) {

    // ADD CODE TO READ THE FIRST THREE NUMBERS WHICH ARE:
    // NUMBER OF CARDS IN YOUR HAND,  NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION
    int number_of_card;
    int number_played;
    int position;
    scanf("%d %d %d", &number_of_card, &number_played, &position);
    
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int i = 0;
    // check if i have the DOUGLAS
    int forty_two = 0;
    // name of cards of hand is "card_in_hand"
    int card_in_hand[N_CARDS_INITIAL_HAND];
    while (i < number_of_card) {
        scanf("%d", &card_in_hand[i]);
        if (card_in_hand[i] == DOUGLAS) {
            forty_two = 1;
        }
        i++;
    }
    
    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int n = 0;
    // name of cards played this round is "this_round"
    int this_round[CARD_IN_ONE_ROUND];
    while (n < CARD_IN_ONE_ROUND) {
        scanf("%d", &this_round[n]);
        n++;
    }
    
    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int history = 0;
    int history_card[HISTORY_PLAYED];
    while (history < HISTORY_PLAYED) {
        scanf("%d", &history_card[history]);
        history++;
    }
    
    // discard list
    int discard = 0;
    int card_discard[N_CARDS_DISCARDED];
    while (discard < N_CARDS_DISCARDED) {
        scanf("%d", &card_discard[discard]);
        discard++;
    }
    
    // received list
    int received = 0;
    int card_received[N_CARD_RECEIVED];
    while (received < N_CARD_RECEIVED) {
        scanf("%d", &card_received[received]);
        received++;
    }
    
    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
    
    // printf("42\n");
    //printf("%d", card_in_hand[0]);
    
    // sort card_in_hand in 'prime' array and 'non_prime' array
    int pri = 0;
    int non = 0;
    int prime[N_CARDS_INITIAL_HAND] = {0};
    int non_prime[N_CARDS_INITIAL_HAND] = {0};

    i = 0;
    while (i < number_of_card) {
        if (check_prime(card_in_hand[i]) == TRUE) {
            prime[pri] = card_in_hand[i];
            pri++;
        } else {
            non_prime[non] = card_in_hand[i];
            non++;
        }
        i++;
    }
    

    // when i am not the first one to play card
    if (number_played != 0) {
        int coco_array[N_CARDS_INITIAL_HAND];
        int c = 0;
        int general[N_CARDS_INITIAL_HAND];
        int gen = 0;
        i = 0;
        // int an coco array
        while (i < number_of_card) {
            if (check_coco (this_round[0], card_in_hand[i]) == TRUE 
                && check_prime (card_in_hand[i]) == FALSE) {
                coco_array[c] = card_in_hand[i];
                // to check if the coco array has correct card
                // printf("%d", coco_array[c]);
                c++;
            } else if (check_prime (card_in_hand[i]) == FALSE 
                      && check_coco (this_round[0], card_in_hand[i]) == FALSE) {
                // when card is not cocomposite with the first card
                // and it is non-prime, put it into "general" array
                general[gen] = card_in_hand[i];
                gen++;
            }
            i++;
        }
        
        // if number_played 0 played a prime
        if (check_prime (this_round[0]) == TRUE) {
            //if i have prime
            if (pri > 0) {
                // when i am the second player
                // play the largest prime less than the first card
                if (number_played == 1) {
                    int result = check_valid_max (prime, pri, this_round[0]);
                    printf("%d", result);
                // when i am the third player
                // play the largest prime less than the largest vaild number
                } else if (number_played == 2) {
                    int max = round_max_p2 (this_round[0], this_round[1]);
                    int result = check_valid_max (prime, pri, max);
                    printf("%d", result);
                // when i am the 4th player
                // play the largest prime less than the largest vaild number
                } else {
                    int max = round_max_p3 
                        (this_round[0], this_round[1], this_round[2]);
                    int result = check_valid_max (prime, pri, max);
                    printf("%d", result);
                }

            // if i only have non-prime
            } else {
                // when i have 42, play it
                if (forty_two == 1) {
                    printf("42");
                // or play the largest non-prime
                } else {
                    printf("%d", non_prime[non-1]);
                }
            }
            
        // if this_round 0 played a non-prime card
        } else {
            // when i have cocomposite number
            if (c > 0) {
                // when i am the second player
                // play the largest coco number less than the first card
                if (number_played == 1) {
                    int result = check_valid_max (coco_array, c, this_round[0]);
                    printf("%d", result);
                // when i am the third player
                // play the largest coco number less than the largest prime
                } else if (number_played == 2) {
                    int max = round_max2 (this_round[0], this_round[1]);
                    int result = check_valid_max (coco_array, c, max);
                    printf("%d", result);
                // when i am the 4th player
                // play the largest coco number less than the largest prime
                } else {
                    int max = round_max3
                        (this_round[0], this_round[1], this_round[2]);
                    printf("%d", check_valid_max (coco_array, c, max));
                } 
            // when i dont have coco number and i have 42, play 42
            } else if (c == 0 && forty_two == 1) {
                printf("42");
            // when i dont have coco number and i have prime number
            // play the largest prime number
            } else if (c == 0 && pri > 0) {
                printf("%d", prime[pri-1]);
            // when i dont have coco number nor prime number
            // play the largest non-prime number
            } else if (c == 0 && pri == 0) {
                printf("%d", non_prime[non-1]);
            }
        }
        
    // when i am the first player
    } else if (number_played == 0) {
        // when i have non-prime number, play the smallest non-prime number
        if (non > 0) {
            printf("%d", non_prime[0]);
        // when i only have prime number, play the smallest prime
        } else {
            printf("%d", prime[0]);
        }
    }
        

    printf("\n");
}

// ADD YOUR FUNCTIONS HERE

//return MAX value in array and set it to zero
int find_max (int array[]) {
    int max = 0;
    int i = 0;
    while (i < N_CARDS_INITIAL_HAND) {
        if (array[i] > max) {
            max = array[i];
        } 
        i++;
    }
    int result = max;
    i = 0;
    while (i < N_CARDS_INITIAL_HAND) {
        if (max == array[i]) {
            array[i] = 0;
        }
        i++;
    }
    return result;
}

// Check if the number is prime
// if is prime return TRUE
// if not, return FALSE
int check_prime (int num) {
    int i = 2;
    while (i < num) {
        if (num % i == 0) {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

// Check if is cocomposite with the card of number_played 0
// if it if cocomposite, return TRUE 
// if is not, return FLASE
int check_coco (int num1, int num2) {
    int i = 2;
    while (i < num1 || i < num2) {
        if (num1 % i == 0 && num2 % i == 0) {
            return TRUE;
        } else {
            i++;
        }
    }
    return FALSE;
}

// Check the maximum number which smaller than largest this round
// and return the number
int check_valid_max (int array[], int size, int value) {
    int i = 0;
    int max = array[0];
    while (i < size) {
        if (array[i] < value) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        i++;
    }
    return max;
}

// when the first card of this round is non-prime
// and card played is two, check the larger number and return it
int round_max2 (int num1, int num2) {
    if (check_coco(num1, num2) == TRUE) {
        if (num1 > num2) {
            return num1;
        } else {
            return num2;
        }
    } else {
        return num1;
    }
}

// when the first card of this round is non-prime
// and card played is three, check the largest number and return it
int round_max3 (int num1, int num2, int num3) {
    if (check_coco(num1, num2) == TRUE && check_coco(num1, num3) == TRUE) {
        if (num1 > num2 && num1 > num3) {
            return num1;
        } else if (num2 > num1 && num2 > num3) {
            return num2;
        } else {
            return num3;
        }
    } else if (check_coco(num1, num2) == TRUE 
               && check_coco(num1, num3) == FALSE) {
        if (num1 > num2) {
            return num1;
        } else {
            return num2;
        }
    } else if (check_coco(num1, num2) == FALSE 
               && check_coco(num1, num3) == TRUE) {
        if (num1 > num3) {
            return num1;
        } else {
            return num3;
        }
    } else {
        return num1;
    }
}

// when the first card of this round is prime
// and card played is two, check the larger number and return it
int round_max_p2 (int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

// when the first card of this round is prime
// and card played is three, check the largest number and return it
int round_max_p3 (int num1, int num2, int num3) {
    if (num1 > num2 && num1 > num3) {
        return num1;
    } else if (num2 > num1 && num2 > num3) {
        return num2;
    } else {
        return num3;
    }
}
