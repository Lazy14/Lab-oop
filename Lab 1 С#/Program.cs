using System;

class Program
{
    static double CalculateFirstTask()
    {
        //данні типу double
        double inputX = 0, inputC = 0, inputB = 0, resultY = 0;
        //інтрфейс
        //ввід данних
        Console.WriteLine("Enter x: ");
        inputX = double.Parse(Console.ReadLine());
        
        Console.WriteLine("Enter c: ");
        inputC = double.Parse(Console.ReadLine());
       
        Console.WriteLine("Enter b: ");
        inputB = double.Parse(Console.ReadLine());
        // тут формула
        resultY = ((2 * inputX - inputC) / (Math.Sqrt(inputX - inputB))) + Math.Abs(inputX - inputC);
        //вивід ркзцльтату
        Console.Write("Value of y: " + resultY);

        return resultY;
    }

    static void CalculateSecondTask() // друге завдання
    {
        // інтерфейс ввід даних
        Console.WriteLine("Enter the number of rows (n): ");
        int numRows = int.Parse(Console.ReadLine());

        Console.WriteLine("Enter the number of columns (m): ");
        int numCols = int.Parse(Console.ReadLine());
        // масив вести два значення стовпці і рядки
        double[,] matrix = new double[numRows, numCols];
        //заповняє матрицю числами вединими компютором
        FillMatrixWithRandomValues(matrix, numRows, numCols);
        // заповняє матрицю числами вединими користувачем
        PrintMatrix(matrix, numRows, numCols);

        double product = 1;
        List<double> resultList = new List<double>();

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                double element = matrix[i, j];
                //Обчислюється добуток квадратів тих елементів матриці які задовольняють умову
                if (Math.Abs(element) >= 1 && Math.Abs(element) <= 1.5)
                    product *= Math.Pow(element, 2);
            }
            resultList.Add(product);
        }

        Console.Write("\n(If all values = 1, then no such elements were found that satisfy the condition)\nResulting: ");

        foreach (double elem in resultList)
            Console.Write(elem + " ");
    }

    static void CalculateThirdTask()// третє завдання
    {
        //інтефейс
        Console.WriteLine("Do you want to enter the numbers yourself (enter 1) or let the computer do it (enter 2)");
        int choice = int.Parse(Console.ReadLine());
        //масиви данних
        double[] xCoordinates = new double[10];
        double[] yCoordinates = new double[10];
        double perimeter = 0;
        // введення данних
        if (choice == 1)
        {
            Console.WriteLine("Enter x values:");
            EnterNumbersManually(xCoordinates, 10);

            Console.WriteLine("Enter y values:");
            EnterNumbersManually(yCoordinates, 10);
        }
        //якщо вибір 2 матриця заповнюється самостійно
        else if (choice == 2)
        {
            GenerateRandomNumbers(xCoordinates, 10);
            GenerateRandomNumbers(yCoordinates, 10);
        }
        // цикл який рахує дистанцю між точками
        for (int i = 0; i < 9; i++)
        {
            double side = CalculateDistance(xCoordinates[i], xCoordinates[i + 1], yCoordinates[i], yCoordinates[i + 1]);
            perimeter += side;
        }

        Console.WriteLine("\nPerimeter = " + perimeter);
    }
    // функція яка заповняє самостійно
    static void FillMatrixWithRandomValues(double[,] matrix, int numRows, int numCols)
    {
        Random random = new Random();
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                matrix[i, j] = random.NextDouble();
            }
        }
    }
    //вивід матриці
    static void PrintMatrix(double[,] matrix, int numRows, int numCols)
    {
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                Console.Write(matrix[i, j] + " ");
            }
            Console.WriteLine();
        }
    }
    // ввід користувачем
    static void EnterNumbersManually(double[] array, int count)
    {
        for (int i = 0; i < count; i++)
        {
            Console.Write("Enter a value at index " + i + ": ");
            array[i] = double.Parse(Console.ReadLine());
        }
    }
    //генератор рандомних чисел
    static void GenerateRandomNumbers(double[] array, int count)
    {
        Random random = new Random();
        for (int i = 0; i < count; i++)
        {
            array[i] = random.NextDouble();
        }
    }
    //обчисення
    static double CalculateDistance(double x1, double x2, double y1, double y2)
    {
        return Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2));
    }
    // меню
    static void Main(string[] args)
    {
        bool exit = false;
        while (!exit)
        {
            Console.WriteLine("Choose a task:");
            Console.WriteLine("1. First task");
            Console.WriteLine("2. Second task");
            Console.WriteLine("3. Third task");
            Console.WriteLine("0. Exit");

            int choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    CalculateFirstTask();
                    break;
                case 2:
                    CalculateSecondTask();
                    break;
                case 3:
                    CalculateThirdTask();
                    break;
                case 0:
                    exit = true;
                    break;
                default:
                    Console.WriteLine("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}
