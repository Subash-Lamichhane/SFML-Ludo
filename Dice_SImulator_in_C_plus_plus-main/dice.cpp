//  Dice Simulator in C++

#include <iostream>
#include <cstdlib>
#include <ctime>

class Dice
{

public:
    int diceFaceNum;
    bool toQuit = false;

    void askToRollDice()
    {
        char ans;
        std::cout << "\nWanna roll dice?(y/n)" << std::endl;
        std::cin >> ans;
        if (ans == 'y')
        {
            clearScreen();
            generateRandomNum();
            showDiceFaces();
        }
        else if (ans == 'n')
        {
            toQuit = true;
        }
        else
        {
            clearScreen();
            std::cout << "\nInvalid resonse. Try 'y' for yes and 'n' for no" << std::endl;
            askToRollDice(); //  Recursion
        }
    }
    void generateRandomNum()
    {
        srand(time(0));
        diceFaceNum = 1 + rand() % 6; //  rand()%6 gives numbers from 0 to 5 that's why 1 isadded
    }

    void clearScreen()
    {
        system("cls"); // Clear screen
    }

    void showDiceFaces() // Etching dice faces
    {
        switch (diceFaceNum)
        {
        case 1:
            std::cout << " ___________" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|     *     |" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|___________|" << std::endl;
            break;

        case 2:
            std::cout << " ___________" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|   *   *   |" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|___________|" << std::endl;
            break;

        case 3:
            std::cout << " ___________" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|        *  |" << std::endl;
            std::cout << "|     *     |" << std::endl;
            std::cout << "|  *        |" << std::endl;
            std::cout << "|___________|" << std::endl;
            break;

        case 4:
            std::cout << " ___________" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|  *     *  |" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|  *     *  |" << std::endl;
            std::cout << "|___________|" << std::endl;
            break;

        case 5:
            std::cout << " ___________" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|  *     *  |" << std::endl;
            std::cout << "|     *     |" << std::endl;
            std::cout << "|  *     *  |" << std::endl;
            std::cout << "|___________|" << std::endl;
            break;

        case 6:
            std::cout << " ___________" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|  *  *  *  |" << std::endl;
            std::cout << "|           |" << std::endl;
            std::cout << "|  *  *  *  |" << std::endl;
            std::cout << "|___________|" << std::endl;
            break;
        }
    }
    
    void endUserMessage()
    {
        clearScreen();
        std::cout << "\n\nHope you enjoyed!!" << std::endl;
        std::cout << "Have a good day!!" << std::endl;
    }
};

int main()
{
    Dice d;
    while (1)
    {
        d.askToRollDice();
        if (d.toQuit)
        {
            d.endUserMessage();
            break;
        }
    }
}
