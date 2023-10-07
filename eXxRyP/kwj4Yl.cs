using System;
public class Prism {

	static void Calculate_vol()
	{
		// Initialization
      double width, height, length, Vol; //declaring variables
      Console.WriteLine("Enter width:");
      width = Convert.ToDouble(Console.Read());//taking input
      Console.WriteLine("Enter height:");
      height = Convert.ToDouble(Console.Read());//taking input
      Console.WriteLine("Enter height:");
      length = Convert.ToDouble(Console.Read());//taking input

		// Formula for calculating the area
		Vol=width*height*length;

		// Displaying the area
	Console.WriteLine("The volume of rectangular prism is : " + Vol);
	Console.ReadKey();
	}
	static public void Main(String[] args)
	{
		Calculate_vol();
	}
}
