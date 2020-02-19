/* 
    Implementation of `tee` command.

    Peter Seger 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFERSIZE 512      // Can change to any size

void appendFile(char* filename, char content[]) {
    FILE* outputtedFile = fopen(filename, "a");
    fputs(content, outputtedFile);
    fclose(outputtedFile);
}

void writeFile(char* filename, char content[]) {
    FILE* outputtedFile = fopen(filename, "w");
    fputs(content, outputtedFile);
    fclose(outputtedFile);
}

int main(int argc, char *argv[]) {
    char ch;
    char inputs[BUFFERSIZE];
    int appendFlag = 0;
    
    while((ch = getopt(argc, argv, "a")) != EOF) {
        switch (ch)
        {
            case 'a':
                appendFlag = 1;
                continue;
            default:
                fprintf(stderr, "Sorry, that's not a valid option flag\n");
                return 1;
        }
    };

    argc -= optind;
    argv += optind;

    while(fgets(inputs, BUFFERSIZE, stdin)){
        for(int i=0; i<argc; i++) {
            if(appendFlag) {
                appendFile(argv[i], inputs);
            } else {
                writeFile(argv[i], inputs);
            }
        }
        fprintf(stdout, "%s", inputs);
    }

    return 0;
}

/*

3. Once I re-read the section of chapter 3 in HFC it definitely helped the problem.
The biggest thing I was confused about was how the program was actually supposed
to work. At first I thought it should act like `tee` from the time it was called
(i.e. takes the command, flags, and output files). After looking at how they did
the pizza problem in HFC I realized that was probably not how it was supposed to
work, so I changed to then take the "commands" while the program was running. 
This made it quite a bit easier. Other than that, I needed a few googles to
fully understand file pointers for reading/writing to files. 

4. The first thing I noticed was how much larger their input buffer was (8*1024).
The next thing I noticed was that they actually check to make sure the buffer
was allocated all its memory before proceeding to populate it. This is sort of
a general trend where they check things a lot more before proceeding assuming it
was done correctly, like mine. They chose to use `read` instead of `fgets`. The
biggest change was in the actual look of reading "commands" where they use a lot
of different syntax to iterate over the inputs buffer. Their loop also supports
writing to multiple (>1) files which mine doesn't support.

*/