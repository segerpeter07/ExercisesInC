## Stack allocated data
1. It's supposed to build an int array with all indecies with the value 42, then it's supposed to build another "throwaway" array of the same size but with indecises as the values (i.e. 0,1,2,3,4). Then it should go through the array and print the values. If the program worked as expected, the output would just be:
```
42
42
42
42
42
```

2. Yes, I got a warning. It was an incorrect return type warning since the `foo` fiunction currently returns the full array, not a pointer.

3. I didn't get a segmentation fault however it didn't return the correct values (which was expected). The `array` is made both times in the stack which means that it can be overriden by any other functions. The `foo` function creates the array and populated it with `42`s, however, it returns an `int*` which really is an int pointer to an array pointer. `bar` then creates an array at the same point in the stack as the array used by `foo`. Then when we go to print ever element in the array, we use our `array*` to print the results which are now `int*` to the values in the array.

4. When the print statements are removed, the results are similar however the 3rd and 5th elements of the array are changed to lower values. I'm not really sure why this happens but I think it might have to do with the print statement making `array` pointer a string literal?