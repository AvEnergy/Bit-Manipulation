// Bit Manipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
void Print(unsigned int x);
unsigned int bitField = 0;
void TurnOn(unsigned int bit);
void TurnOff(int bit);
void Toggle(int bit);
void Negate();
void LeftShift();
void RightShift();
void SetOfBits();
int ValidateIntInput();
int ValidateMenuInput();

int main()
{
    bool leaveProgram = true;
    int choice;
    int x = 0;
    std::cout << "input a number to change the bitset." << std::endl;
    std::cout << "1) TurnOn\n2) TurnOff\n3) Toggle\n4) Negate\n5) LeftShift\n6) RightShift\n7) Exit" <<std::endl;
    Print(bitField);
    while (leaveProgram == true)
    {
        choice = ValidateMenuInput();
        switch (choice)
        {
            case 1:
                std::cout << "Choose bit index: ";
                x = ValidateIntInput();
                TurnOn(x);
                break;
            case 2:
                std::cout << "Choose bit index: ";
                x = ValidateIntInput();
                TurnOff(x);
                break;
            case 3:
                std::cout << "Choose bit index: ";
                x = ValidateIntInput();
                Toggle(x);
                break;
            case 4:
                Negate();
                break;
            case 5:
                LeftShift();
                break;
            case 6:
                RightShift();
                break;
            case 7:
                leaveProgram = false;
                break;
        }

    }

}

void Print(unsigned int x)
{
    std::cout << "DEC = " << x << '\t';
    SetOfBits();
}

void SetOfBits()
{
    std::cout << "BIT = ";
    for (int i = 31, y = 0; i >= 0; i--, y++) 
    {
        if (y % 4 == 0)
        {
            std::cout << " ";
        }
        unsigned int x = bitField & (1 << i);
        if (x != 0)
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }
    std::cout << std::endl;
}

void TurnOn(unsigned int bit)
{
    bitField = bitField | 1 << bit;
    Print(bitField);
}

void TurnOff(int bit)
{
    bitField = bitField & ~(1 << bit);
    Print(bitField);
}

void Toggle(int bit)
{
    bitField = bitField ^ (1 << bit);
    Print(bitField);
}

void Negate() 
{
    bitField = ~bitField;
    Print(bitField);
}

void LeftShift()
{
    bitField = bitField << 1;
    Print(bitField);
}

void RightShift()
{
    bitField = bitField >> 1;
    Print(bitField);
}

int ValidateIntInput()

{

    int input;

    bool good = false;

    while (true)

    {

        std::cout << "";

        if (std::cin >> input)
        {
            if (input <= 31)
            {
                good = true;
            }
        }

        std::cin.clear();

        std::cin.ignore(INT_MAX, '\n');

        if (good)
        {
            return input;
        }
        else
        {
            std::cout << "Invalid input. Please put a whole number(0-31) : ";
        }

    }
}

int ValidateMenuInput()

{

    int input;

    bool good = false;

    while (true)

    {

        std::cout << "";

        if (std::cin >> input)
        {
            if (input <= 7)
            {
                good = true;
            }
        }

        std::cin.clear();

        std::cin.ignore(INT_MAX, '\n');

        if (good)
        {
            return input;
        }
        else
        {
            std::cout << "Invalid input. Please pick a menu option(1-7) : ";
        }

    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
