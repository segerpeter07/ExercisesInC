## Stack allocated data
1. It's supposed to build an int array with all indecies with the value 42, however this array is just a local array, so when `*array` gets assigned, it will point to something that no longer exists. Then, similarly it's supposed to build another array of the same size but with indecises as the values (i.e. 0,1,2,3,4). Then it should go through the array and print the values. If the program worked as expected, the output would just be:
```
42
42
42
42
42
```

2. Yes, I got a warning. It was an incorrect return type warning since the `foo` fiunction currently returns the full array, not a pointer.

3. I didn't get a segmentation fault, like I would have expected. However it didn't return the correct values (which was expected). The `array` is made both times in the stack which means that after the first one is used, it gets removed from the stack so that those memory addresses can be overriden by any other functions. When `bar` gets run and allocates an array in memory, it doesn't necessarily need to include the memory addresses used by `foo` (however I suspect it did re-use some of them based off the output). Then, when we go to print the array in the `main` func, we get some of the correct values, and some bogus values that were overwritten. My output looked like this:
```
0
48
-373503872
32766
-373504096
```

4. When the print statements are removed, the results are basically the same as before which showed that both `foo` and `bar` were run before anything started to go wrong. 