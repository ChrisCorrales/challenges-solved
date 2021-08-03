using System;

class URI
{
    static void Main(string[] args)
    {
        int L, C;
        string Output;
        L = int.Parse(Console.ReadLine());
        C = int.Parse(Console.ReadLine());
        Output = ((L + C) % 2 == 0) ? "1" : "0";
        Console.WriteLine($"{Output}");
    }
}