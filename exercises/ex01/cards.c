#include <stdio.h>
#include <stdlib.h>


int det_val(char card_name[]) {
    /*
        det_val() determines the value of the card just played.

        card_name: array containing the card "name"
    */
    int val = 0;
    switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        default:
            val = atoi(card_name);
            if((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
                return 0;
            }
    }
    return val;
}

int det_count(char card_name[], int count) {
    /* 
        det_counter() determines the counter increase/decrease based off the
        game parameters.

        card_name: array containing the card "name"
        count: int containing the current game counter value
    */
    int val = det_val(card_name);
    if((val > 2) && (val < 7)) {
        count++;
    } else if(val == 10) {
        count--;
    }
    return (count);
}

void card_counter() {
    /*
        card_counter() is the main function that handles getting user input,
        checking for quit input, and keeping track and printing the count.
    */
    char card_name[3];
    int start_count = 0;
    int updated_count = start_count;
    while (card_name[0] != 'X')
    {
        puts("Enter the card_name: ");
        scanf("%2s", card_name);
        if(card_name[0] == 'X') {
            break;
        }
        updated_count = det_count(card_name, updated_count);
        printf("Current count: %d\n", updated_count);
    }   
}


int main() {
    card_counter();
    return 0;
}
