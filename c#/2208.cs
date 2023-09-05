using System;

//// 1
//Console.Write("enter a number between 1-100: ");
//int num = Int32.Parse(Console.ReadLine());

//if (num < 1 || num > 100) Console.WriteLine("range error, enter a number between 1-100");

//else if (num % 3 == 0) Console.WriteLine("Fizz");

//else if (num % 5 == 0) Console.WriteLine("Buzz");

//else if ((num % 3 == 0) & (num % 5 == 0)) Console.WriteLine("Fizz Buzz");

//else if (!(num % 3 == 0 & num % 5 == 0)) Console.WriteLine(num);


//// 2

//Console.Write("enter a number: ");
//int num = Int32.Parse(Console.ReadLine());

//Console.WriteLine("enter the percentage: ");
//string percentage = Console.ReadLine();
//int percentage2 = Convert.ToInt16(percentage);

//Console.WriteLine(num * percentage2 / 100);


//// 3

//Console.Write("enter the first number: ");
//int firstNum2 = Int32.Parse(Console.ReadLine());
//Console.Write("enter the second number: ");
//int secondNum2 = Int32.Parse(Console.ReadLine());
//Console.Write("enter the third number: ");
//int thirdNum2 = Int32.Parse(Console.ReadLine());
//Console.Write("enter the fourht number: ");
//int fourthNum2 = Int32.Parse(Console.ReadLine());
//Console.Write(firstNum2 * 1000 + secondNum2 * 100 + thirdNum2 * 10 + fourthNum2);

//// 4
//Console.Write("enter a number: ");
//int num = Int32.Parse(Console.ReadLine());
//if (num >= 100000 & num <= 999999)
//{
//    Console.Write("enter the first position (1-6): ");
//    int position1 = Int32.Parse(Console.ReadLine());
//    Console.Write("enter the second position (1-6): ");
//    int position2 = Int32.Parse(Console.ReadLine());
//    if (position1 >= 1 & position1 <= 6 & position2 >= 1 & position2 <= 6)
//    {
//        int tempNumber = num;
//        int[] digits = new int[6];

//        for (int i = 5; i >= 0; i--)
//        {
//            digits[i] = tempNumber % 10;
//            tempNumber /= 10;
//        }

//        int temp = digits[position1 - 1];
//        digits[position1 - 1] = digits[position2 - 1];
//        digits[position2 - 1] = temp;


//        int newNumber = 0;
//        for (int i = 0; i < 6; i++)
//        {
//            newNumber = newNumber * 10 + digits[i];
//        }

//        Console.Write("changed number: " + newNumber);
//    }
//    else Console.Write("please enter the number in the range 1-6");
//}
//else Console.Write("please enter a six-digit number");


//// 6

//Console.Write("1. convert from celsius to fahrenheit " + '\n' +
//    "2. convert from fahrenheit to celsius: ");
//int choise = Int32.Parse(Console.ReadLine());

//if (choise == 1)
//{
//    Console.Write("enter the temperature in degrees celsius: ");
//    double celsius = double.Parse(Console.ReadLine());
//    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
//    Console.Write("temperature in degrees fahrenheit: " + fahrenheit);
//}
//else if (choise == 2)
//{
//    Console.Write("enter the temperature in degrees fahrenheit: ");
//    double fahrenheit = double.Parse(Console.ReadLine());
//    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
//    Console.Write("temperature in degrees celsius: " + celsius);
//}

//else Console.WriteLine("incorrect selection input.");

// 7

//Console.Write("enter the first number: ");
//int num = Int32.Parse(Console.ReadLine());
//Console.Write("enter the second number: ");
//int num2 = Int32.Parse(Console.ReadLine());

//if (num > num2)
//{
//    int temp = num;
//    num = num2; 
//    num2 = temp;
//}

//for (int i = num;i <= num2; i++)
//{
//       if (i % 2 == 0)
//           Console.WriteLine(i);
//}
