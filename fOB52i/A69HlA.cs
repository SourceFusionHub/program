using System;

class NewtonRaphsonSolver
{
    static void Main()
    {
        Console.WriteLine("Newton-Raphson Method for Solving a System of Nonlinear Equations");

        Console.Write("Enter the number of equations: ");
        int numEquations = int.Parse(Console.ReadLine());

        Console.WriteLine("Enter the system of equations in the form f(x) = 0:");

        // To initialize an array to store the equations
        string[] equations = new string[numEquations];

        for (int i = 0; i < numEquations; i++)
        {
            Console.Write($"Equation {i + 1}: ");
            equations[i] = Console.ReadLine();
        }

        Console.WriteLine("\nEnter initial guesses for the variables:");

        // To initialize an array to store the initial guesses
        double[] initialGuesses = new double[numEquations];

        for (int i = 0; i < numEquations; i++)
        {
            Console.Write($"Variable {i + 1}: ");
            initialGuesses[i] = double.Parse(Console.ReadLine());
        }

        Console.WriteLine("\nEnter the tolerance for convergence (e.g., 0.0001): ");
        double tolerance = double.Parse(Console.ReadLine());

        // Solve\ing the system of equations using the Newton-Raphson method
        double[] solutions = SolveSystem(equations, initialGuesses, tolerance);

        // To display the solutions
        Console.WriteLine("\nSolutions:");
        for (int i = 0; i < numEquations; i++)
        {
            Console.WriteLine($"Variable {i + 1}: {solutions[i]}");
        }
    }

    static double[] SolveSystem(string[] equations, double[] initialGuesses, double tolerance)
    {
        int numEquations = equations.Length;
        int maxIterations = 1000;

        // To initialize the solutions array with the initial guesses
        double[] solutions = new double[numEquations];
        Array.Copy(initialGuesses, solutions, numEquations);

        // To initialize an array to store the partial derivatives
        double[,] partialDerivatives = new double[numEquations, numEquations];

        // For performing iterations
        for (int iteration = 0; iteration < maxIterations; iteration++)
        {
            // Evaluate the system of equations and partial derivatives at the current solutions
            double[] values = new double[numEquations];
            EvaluateSystem(equations, solutions, values, partialDerivatives);

            // Check for convergence
            double maxResidual = GetMaxResidual(values);
            if (maxResidual < tolerance)
            {
                Console.WriteLine($"Converged in {iteration + 1} iterations.");
                return solutions;
            }

            // Update the solutions using the Newton-Raphson formula
            double[] update = SolveLinearSystem(partialDerivatives, values);
            for (int i = 0; i < numEquations; i++)
            {
                solutions[i] -= update[i];
            }
        }

        Console.WriteLine("Did not converge within the maximum number of iterations.");
        return solutions;
    }

    static void EvaluateSystem(string[] equations, double[] values, double[] partialDerivatives, double[,] matrix)
    {
        int numEquations = equations.Length;

        for (int i = 0; i < numEquations; i++)
        {
            string equation = equations[i];

            // Evaluate the equation at the current solutions
            values[i] = EvaluateExpression(equation, values);

            // Compute the partial derivatives
            for (int j = 0; j < numEquations; j++)
            {
                double h = 0.0001; // Small perturbation for numerical differentiation
                double xPlusH = values[j] + h;
                double xMinusH = values[j] - h;

                // Compute the partial derivative using central differencing
                double partialDerivative = (EvaluateExpression(equation, ReplaceVariable(values, j, xPlusH)) -
                                            EvaluateExpression(equation, ReplaceVariable(values, j, xMinusH))) / (2 * h);

                matrix[i, j] = partialDerivative;
            }
        }
    }

    static double EvaluateExpression(string expression, double[] values)
    {
        int numValues = values.Length;

         for (int i = 0; i < numValues; i++)
        {
            string variable = $"x{i + 1}";
            expression = expression.Replace(variable, values[i].ToString());
        }

        return EvaluateMathExpression(expression);
    }

    static double EvaluateMathExpression(string expression)
    {
        return Convert.ToDouble(new System.Data.DataTable().Compute(expression, string.Empty));
    }

    static double[] ReplaceVariable(double[] values, int index, double newValue)
    {
        // Create a new array with the specified value replaced
        double[] newArray = new double[values.Length];
        Array.Copy(values, newArray, values.Length);
        newArray[index] = newValue;
        return newArray;
    }

    static double[] SolveLinearSystem(double[,] coefficients, double[] constants)
    {
        int numEquations = constants.Length;

        // Solve the system of linear equations using matrix inversion
        double[] solution = new double[numEquations];

        for (int i = 0; i < numEquations; i++)
        {
            double sum = 0.0;

            for (int j = 0; j < numEquations; j++)
            {
                sum += coefficients[i, j] * constants[j];
            }

            solution[i] = sum;
        }

        return solution;
    }

    static double GetMaxResidual(double[] values)
    {
        double maxResidual = Math.Abs(values[0]);

        foreach (double value in values)
        {
            maxResidual = Math.Max(maxResidual, Math.Abs(value));
        }

        return maxResidual;
    }
}






           
