/*
    Created by Peter Seger
    I used this stackoverflow answer to help me figure out how to empty a buffer
    when longer than specified amount to prevent overflow and flow-over to next
    cycle of loop.
    https://stackoverflow.com/a/30811326
*/

#import <stdio.h>
#import <stdlib.h>
#import <string.h>

#define MAX_NUM_LEN 5       // arbitrary choice for max number length
#define COUNTER_BUFFER_LEN 5        // arbitrary choice for numbers kept to add


int compute_total(int numbers[]) {
    int total = 0;
    for(int i =0; i < sizeof(*numbers); i++) {
        total += numbers[i];
    }
    return total;
}


/* counter manages the capture of the input, EOF, checking length
   of input number, and max counter buffer.
*/
int counter() {
    int cur_pos = 0;                                // used to keep track of number of items in counter buffer
    int numbers_to_add[COUNTER_BUFFER_LEN];         // array for number to be tabulated
    char curr_number[MAX_NUM_LEN];                  // buffer for taking inputted number                              

    while (1)
    {
        // check if counter buffer full
        if(cur_pos + 1 >= COUNTER_BUFFER_LEN) {
            printf("You've reached the counter buffer. Exiting.\n");
            break;
        }

        printf("Enter number: \n");
        if (fgets(curr_number, MAX_NUM_LEN, stdin) == NULL) {
            if(feof(stdin)) {
                break;
            } else {
                printf("Error reading from stdin\n");
                break;
            }
        } else if (strchr(curr_number, '\n') == NULL) {
            int c;
            while((c = getc(stdin)) != '\n' && c != EOF);
            printf("Input too long!\n");
            continue;
        }

        int num_to_add = atoi(curr_number);
        numbers_to_add[cur_pos] = num_to_add;
        cur_pos++;
    }
    return compute_total(numbers_to_add);
}


int main() {
    int res = counter();
    printf("Result is: %d\n", res);
}