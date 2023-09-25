// вроде не надо было делать отдельный выбор операции 
Calculator calculator = new Calculator();

MathOperation Add = calculator.Add;
MathOperation Subtract = calculator.Subtract;
MathOperation Multiply = calculator.Multiply;
MathOperation Divide = calculator.Divide;

Console.Write("enter the first number: ");
double a = double.Parse(Console.ReadLine());

Console.Write("enter the second number: ");
double b = double.Parse(Console.ReadLine());

Console.WriteLine($"Add: {Add(a,b)}");
Console.WriteLine($"Subtract: {Subtract(a,b)}");
Console.WriteLine($"Multiply: {Multiply(a,b)}");
Console.WriteLine($"Divide: {Divide(a,b)}");

delegate double MathOperation(double a,double b);


class Calculator
{
    public double Add(double a,double b) 
    {
        return a + b;
    }

    public double Subtract(double a,double b) 
    { 
        return a - b; 
    }

    public double Multiply(double a,double b)
    {
        return a * b;
    }

    public double Divide(double a,double b)
    {
        if (b == 0)
        {
            throw new DivideByZeroException("zero division error ");

        }
       else return a / b;
    }
}


