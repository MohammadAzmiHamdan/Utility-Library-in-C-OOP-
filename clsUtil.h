#pragma once
#include<iostream>
#include "clsDate.h"
using namespace std;

class clsUtil
{

public:
    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        SpecialCharacter = 4
    };
    static void InitializeRandom()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomIntNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    static int RandomZeroOrOne()
    {
        return RandomIntNumber(0, 1);
    }


    static bool RandomBool()
    {
        return (bool)RandomIntNumber(0, 1);
    }
    static int RollDice()
    {
        return RandomIntNumber(1, 6);
    }
    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case SmallLetter:
            return char(RandomIntNumber(97, 122)); // a-z

        case CapitalLetter:
            return char(RandomIntNumber(65, 90)); // A-Z

        case Digit:
            return char(RandomIntNumber(48, 57)); // 0-9

        case SpecialCharacter:
            return char(RandomIntNumber(33, 47)); //          

        default:
            return 'A'; //       
        }
    }

    static std::string GenerateWord(enCharType type, int Length)
    {
        std::string word = "";
        for (int i = 0; i < Length; i++)
        {
            word += GetRandomCharacter(type); //                   
        }
        return word;
    }
    static std::string GenerateKey()
    {
        std::string Key = "";
        Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

        return Key;
    }


    static void GenerateKeys(short NumberOfKeys)
    {

        for (int i = 1; i <= NumberOfKeys; i++)
        {

            std::cout << "Key [" << i << "] : ";
            std::cout << GenerateKey() << std::endl;
        }
    }

    static bool IsEven(int Number)
    {
        return Number % 2 == 0;
    }

    static bool IsOdd(int Number)
    {
        return Number % 2 != 0;
    }

    static bool IsPrime(int Number)
    {
        if (Number <= 1)
            return false;



        for (int i = 2; i <= Number / 2; i++)
        {
            if (Number % i == 0)
                return false;
        }

        return true;
    }
    static int Factorial(int Number)
    {
        if (Number < 0)
            return -1;

        int result = 1;
        for (int i = 1; i <= Number; i++)
        {
            result *= i;
        }

        return result;
    }
    static bool IsPerfect(int Number)
    {
        if (Number <= 1)
            return false;

        int sum = 0;

        for (int i = 1; i <= Number / 2; i++)
        {
            if (Number % i == 0)
                sum += i;
        }

        return sum == Number;
    }
    static int ReverseNumber(int Number)
    {
        int reversed = 0;

        while (Number != 0)
        {
            int digit = Number % 10;
            reversed = reversed * 10 + digit;
            Number /= 10;
        }

        return reversed;
    }
    static int SumDigits(int Number)
    {
        int sum = 0;

        while (Number != 0)
        {
            sum += Number % 10;
            Number /= 10;
        }

        return sum;
    }
    static bool IsPalindrome(int Number)
    {
        return Number == ReverseNumber(Number);
    }
    static bool IsDivisible(int Number, int Divisor)
    {
        if (Divisor == 0)
            return false;

        return Number % Divisor == 0;
    }
    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static float MyABS(float Number)
    {

        if (Number > 0)
            return Number;
        else
            return Number * -1;
    }
    static float GetFractionPart(float Number)
    {
        return Number - int(Number);
    }
    static int MyRound(float Number)
    {
        int IntPart;
        IntPart = int(Number);


        float FractionsPart = GetFractionPart(Number);

        if (abs(FractionsPart) >= 0.5)
        {
            if (Number > 0)
                return ++IntPart;
            else
                return --IntPart;
        }
        else
        {
            return IntPart;
        }
    }
    static int MyFloor(float Number)
    {
        if (Number > 0)
            return int(Number);
        else
            return int(Number) - 1;
    }
    static int MyCeil(float Number)
    {
        if (abs(GetFractionPart(Number)) > 0)
        {
            if (Number > 0)
                return int(Number) + 1;
            else
                return int(Number);
        }
        else
            return Number;
    }
    static float MySqrt(float Number)
    {
        return pow(Number, 0.5);
    }

    static void ReadArray(int arr[100], int& arrLength)
    {
        std::cout << "\nEnter number of elements:\n";
        std::cin >> arrLength;
        std::cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            std::cout << "Element [" << i + 1 << "] : ";
            std::cin >> arr[i];
        }
        std::cout << std::endl;
    }


    static void PrintArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
            std::cout << arr[i] << " ";

        std::cout << "\n";
    }

    static void FillArrayWithRandomNumbersFromUser(int arr[100], int arrLength)
    {
        InitializeRandom();
        std::cout << "\nEnter number of elements:\n";
        std::cin >> arrLength;
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomIntNumber(1, 100);
    }
    static void FillArrayWithRandomNumbers(int arr[100], int arrLength)
    {
        InitializeRandom();

        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomIntNumber(1, 100);
    }
    static int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max;
    }
    static int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = arr[0];
        for (int i = 0; i < arrLength; i++)
        {

            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;
    }
    static int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;


        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }

        return Sum;
    }
    static float ArrayAverage(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }
    static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
    }
    static void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (IsPrime(arrSource[i]))
            {
                arrDestination[Counter] = arrSource[i];
                Counter++;
            }
        }


        arr2Lenght = Counter;
    }
    static void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];
        }
    }

    static void FillArrayWith1toN(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;
    }
    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {

            int index1 = RandomIntNumber(0, arrLength - 1);
            int index2 = RandomIntNumber(0, arrLength - 1);
            Swap(arr[index1], arr[index2]);
        }
    }
    static void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[arrLength - 1 - i];
    }
    static void PrintStringArray(std::string arr[100], int arrLength)
    {
        std::cout << "\nArray elements:\n\n";

        for (int i = 0; i < arrLength; i++)
        {
            std::cout << "Array[" << i << "] : ";
            std::cout << arr[i] << "\n";
        }
        std::cout << "\n";
    }
    static void FillArrayWithKeys(std::string arr[100], int arrLength)
    {
        // Loop through the array indices and generate a key for each element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey();
    }
    static short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i;
        }

        return -1;
    }
    static bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }
    static void AddArrayElement(int Number, int arr[100], int& arrLength)
    {
        arr[arrLength++] = Number;
    }

    static void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arrSource[i] % 2 != 0)
            {
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }
    static void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (IsPrime(arrSource[i]))
            {
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }
    static void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
    {
        for (int i = 0; i < SourceLength; i++)
        {
            if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
            {
                AddArrayElement(arrSource[i], arrDestination, DestinationLength);
            }
        }
    }
    static bool IsPalindromeArray(int arr[100], int Length)
    {

        for (int i = 0; i < Length; i++)
        {

            if (arr[i] != arr[Length - i - 1])
            {
                return false;
            }
        }

        return true;
    }
    static int OddCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 != 0)
            {
                Counter++;
            }
        }

        return Counter;
    }
    static int EvenCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0)
            {
                Counter++;
            }
        }
        return Counter;
    }
    static int PositiveCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] >= 0)
            {
                Counter++;
            }
        }

        return Counter;
    }
    static int NegativeCount(int arr[100], int arrLength)
    {
        int Counter = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < 0)
            {
                Counter++;
            }
        }

        return Counter;
    }
    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

    static string  EncryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }



};