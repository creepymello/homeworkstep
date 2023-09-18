
//// 2 
//string word = Console.ReadLine();
//switch (word)
//{
//    case "zero": Console.WriteLine("0"); break;
//    case "one": Console.WriteLine("1"); break;
//    case "two": Console.WriteLine("2"); break;
//    case "three": Console.WriteLine("3"); break;
//    case "four": Console.WriteLine("4"); break;
//    case "five": Console.WriteLine("5"); break;
//    case "six": Console.WriteLine("6"); break;
//    case "seven": Console.WriteLine("7"); break;
//    case "eight": Console.WriteLine("8"); break;
//    case "nine": Console.WriteLine("9"); break;

//    default:
//        Console.WriteLine("error");
//        break;
//}

////// 3

//try
//{
//    Passport passport = null; 

//    while (passport == null) { 
//        Console.Write("Enter your passport number: ");
//        string number = Console.ReadLine();

//        Console.Write("Enter your name: ");
//        string name = Console.ReadLine();

//        Console.Write("Enter your surname: ");
//        string surname = Console.ReadLine();

//        Console.Write("Enter your date of birth (yyyy-mm-dd): ");
//        DateTime birthDate = DateTime.Parse(Console.ReadLine());

//        Console.Write("Enter the date of issue of the passport (yyyy-mm-dd): ");
//        DateTime issueDate = DateTime.Parse(Console.ReadLine());

//        Console.Write("Enter your nationality: ");
//        string nationality = Console.ReadLine();

//        Console.Write("1 - male, 2 - female: ");
//        string gender = Console.ReadLine();

//        try
//        {
//            passport = new Passport(number, name, surname, birthDate, issueDate, nationality, gender);
//        }
//        catch (ArgumentException e)
//        {
//            Console.WriteLine("Passport initialization error: " + e.Message);
//        }
//    }

//    passport.PrintInfo(); 
//}
//catch (Exception ex)
//{
//    Console.WriteLine("An error occurred: " + ex.Message);
//}


//class Passport 
//{
//    public string passportNumber { get; set; }
//    public string passportName { get; set; }
//    public string passportSurname { get; set; }
//    public DateTime passportDate { get; set; }
//    private readonly DateTime PassportBirthDay;
//    public string passportNationality { get; set; }
//    public string passportGender { get; set; }

//    public Passport(string number,string name,string surname,DateTime birthDay, DateTime date,string nationality, string gender)
//    {

//        if (number.Length != 8) throw new ArgumentException("the length of the passport number is incorrect.");

//        if (!validNameSurname(name)) throw new ArgumentException("the name cannot be less than 2 letters and cannot contain a number");

//        if (!validNameSurname(surname)) throw new ArgumentException("the surname cannot be less than 2 letters and cannot contain a number");

//        if (ValidPassDate(birthDay)) throw new ArgumentException("this passport is not intended for persons under 14 years of age");


//        if (!validGender(gender)) throw new ArgumentException("incorrect value, select 1 or 2 ");

//        passportNumber = number;
//        passportName = name;
//        passportSurname = surname;
//        passportDate = date;
//        PassportBirthDay = birthDay;
//        passportNationality = nationality;
//        passportGender = gender;

//    }


//    private bool validNameSurname(string value)
//    {
//        if (value.Length < 2)
//        {
//            return false;
//        }

//        foreach (char a in value)
//        {
//            if (char.IsDigit(a))
//            {
//                return false;
//            }
//        }

//        return true;
//    }
//    private bool ValidPassDate(DateTime birthDay)
//    {
//        DateTime currentDate = DateTime.Now;
//        int ageInYears = currentDate.Year - birthDay.Year;

//        if (currentDate.Month < birthDay.Month || (currentDate.Month == birthDay.Month && currentDate.Day < birthDay.Day))
//        {
//            ageInYears--;
//        }

//        if (ageInYears < 14)
//        {
//            return false;
//        }

//        if (ageInYears >= 14 && ageInYears < 18)
//        {
//            DateTime expirationDate = passportDate.AddYears(4);
//            return currentDate <= expirationDate; 
//        }
//        else if (ageInYears >= 18)
//        {
//            DateTime expirationDate = passportDate.AddYears(10);
//            return currentDate <= expirationDate; 
//        }

//        return true; 
//    }




//    private bool validGender(string value)
//    {
//        if (value != "1" && value != "2")
//        {
//            return false;
//        }
//        return true;
//    }
//    public void PrintInfo()
//    {
//        Console.WriteLine("passport number: " + passportNumber);
//        Console.WriteLine("name: " + passportName);
//        Console.WriteLine("surname: " +passportSurname);
//        Console.WriteLine("date of issue: " + passportDate);
//        Console.WriteLine("birth day: " + PassportBirthDay);
//        Console.WriteLine("nationality: " + passportNationality);
//        Console.WriteLine("gender: " + passportGender);
//        if (!ValidPassDate(PassportBirthDay))
//        {
//            Console.WriteLine("Passport is expired!");
//        }
//    }
//}


//// 4
    
//Console.Write("enter the expression: ");
//string num = Console.ReadLine();

//try
//{
//    bool result = foon(num);
//    Console.WriteLine(result);
//}
//catch (Exception ex)
//{
//    Console.WriteLine("error: " + ex.Message);
//}
    

//static bool foon(string num)
//{
//    num = num.Replace(" ", ""); 

//    int operand1 = 0;
//    int operand2 = 0;
//    char operator_ = ' ';


//    bool rop = false;


//    foreach (char c in num)
//    {
//        if (char.IsDigit(c))
//        {
//            if (rop) operand1 = operand1 * 10 + int.Parse(c.ToString());
//            else operand2 = operand2 * 10 + int.Parse(c.ToString());

//        }
//        else
//        {
//            operator_ = c; 
//            rop = true; 
//        }

//    }

//    if (operator_ == ' ')
//    {
//        throw new FormatException("there is no operator.");
//    }


//    switch (operator_)
//    {
//        case '<':
//            return operand1 < operand2;
//            break;
//        case '>':
//            return operand1 > operand2;
//            break;
//        case '=':
//            return operand1 == operand2;
//            break;
//        case '!':
//            return operand1 != operand2;
//            break;
//        default:
//            throw new FormatException("wrong operator.");
//            break;
//    }
//}

