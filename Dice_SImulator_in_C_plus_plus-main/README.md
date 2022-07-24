
# Dice Simulator in C++

This is a simple project that simulates the rolling of dice. The only mechanism involved is generating random numbers from 1 to 6.

![20220516_185145](https://user-images.githubusercontent.com/84112374/168600349-e76968ac-e11a-4b15-8826-f097349b2ff0.gif)





# Mechanism

## Header files



```bash
    #include <iostream>
    #include <cstdlib>
    #include <ctime>
```

## Random number generation


```bash
    void generateRandomNum()
    {
        srand(time(0));
        diceFaceNum = 1 + rand() % 6; //  rand()%6 gives numbers from 0 to 5 as remainder that is why 1 is added
    }
```
# Authors

 [@sujankoirala](https://github.com/Sujan-Koirala021)
