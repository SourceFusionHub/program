using System;
using System.Collections.Generic;

// Define token types
enum TokenType
{
    Number,
    Plus,
    Minus,
    Multiply,
    Divide,
    LParen,
    RParen,
    EndOfInput
}

// Define a token structure
struct Token
{
    public TokenType Type;
    public string Value;
}

// Define the AST node types
abstract class AstNode
{
    public abstract int Evaluate();
}

class NumberNode : AstNode
{
    public int Value;

    public NumberNode(int value)
    {
        Value = value;
    }

    public override int Evaluate()
    {
        return Value;
    }
}

class BinaryOperationNode : AstNode
{
    public TokenType Operator;
    public AstNode Left;
    public AstNode Right;

    public BinaryOperationNode(TokenType op, AstNode left, AstNode right)
    {
        Operator = op;
        Left = left;
        Right = right;
    }

    public override int Evaluate()
    {
        int leftValue = Left.Evaluate();
        int rightValue = Right.Evaluate();

        switch (Operator)
        {
            case TokenType.Plus:
                return leftValue + rightValue;
            case TokenType.Minus:
                return leftValue - rightValue;
            case TokenType.Multiply:
                return leftValue * rightValue;
            case TokenType.Divide:
                if (rightValue == 0)
                {
                    throw new DivideByZeroException();
                }
                return leftValue / rightValue;
            default:
                throw new ArgumentException("Invalid operator");
        }
    }
}

class Lexer
{
    private string input;
    private int position;

    public Lexer(string input)
    {
        this.input = input;
        position = 0;
    }

    public Token GetNextToken()
    {
        if (position >= input.Length)
        {
            return new Token { Type = TokenType.EndOfInput, Value = "" };
        }

        char currentChar = input[position];

        if (char.IsDigit(currentChar))
        {
            string number = currentChar.ToString();
            while (position + 1 < input.Length && char.IsDigit(input[position + 1]))
            {
                position++;
                number += input[position];
            }
            position++;
            return new Token { Type = TokenType.Number, Value = number };
        }

        switch (currentChar)
        {
            case '+':
                position++;
                return new Token { Type = TokenType.Plus, Value = "+" };
            case '-':
                position++;
                return new Token { Type = TokenType.Minus, Value = "-" };
            case '*':
                position++;
                return new Token { Type = TokenType.Multiply, Value = "*" };
            case '/':
                position++;
                return new Token { Type = TokenType.Divide, Value = "/" };
            case '(':
                position++;
                return new Token { Type = TokenType.LParen, Value = "(" };
            case ')':
                position++;
                return new Token { Type = TokenType.RParen, Value = ")" };
            default:
                throw new ArgumentException("Invalid character: " + currentChar);
        }
    }
}

class Parser
{
    private Lexer lexer;
    private Token currentToken;

    public Parser(Lexer lexer)
    {
        this.lexer = lexer;
        currentToken = lexer.GetNextToken();
    }

    private void Eat(TokenType tokenType)
    {
        if (currentToken.Type == tokenType)
        {
            currentToken = lexer.GetNextToken();
        }
        else
        {
            throw new ArgumentException("Unexpected token: " + currentToken.Type);
        }
    }

    public AstNode Parse()
    {
        return ParseExpression();
    }

    private AstNode ParseExpression()
    {
        AstNode left = ParseTerm();

        while (currentToken.Type == TokenType.Plus || currentToken.Type == TokenType.Minus)
        {
            Token op = currentToken;
            if (op.Type == TokenType.Plus)
            {
                Eat(TokenType.Plus);
            }
            else
            {
                Eat(TokenType.Minus);
            }

            AstNode right = ParseTerm();
            left = new BinaryOperationNode(op.Type, left, right);
        }

        return left;
    }

    private AstNode ParseTerm()
    {
        AstNode left = ParseFactor();

        while (currentToken.Type == TokenType.Multiply || currentToken.Type == TokenType.Divide)
        {
            Token op = currentToken;
            if (op.Type == TokenType.Multiply)
            {
                Eat(TokenType.Multiply);
            }
            else
            {
                Eat(TokenType.Divide);
            }

            AstNode right = ParseFactor();
            left = new BinaryOperationNode(op.Type, left, right);
        }

        return left;
    }

    private AstNode ParseFactor()
    {
        if (currentToken.Type == TokenType.Number)
        {
            int value = int.Parse(currentToken.Value);
            Eat(TokenType.Number);
            return new NumberNode(value);
        }
        else if (currentToken.Type == TokenType.LParen)
        {
            Eat(TokenType.LParen);
            AstNode node = ParseExpression();
            Eat(TokenType.RParen);
            return node;
        }
        else
        {
            throw new ArgumentException("Invalid factor: " + currentToken.Type);
        }
    }
}

class Compiler
{
    public static int Compile(string input)
    {
        Lexer lexer = new Lexer(input);
        Parser parser = new Parser(lexer);
        AstNode ast = parser.Parse();
        return ast.Evaluate();
    }
}

class Program
{
    static void Main(string[] args)
    {
        while (true)
        {
            Console.Write("Enter an expression (or 'exit' to quit): ");
            string input = Console.ReadLine();
            if (input == "exit")
            {
                break;
            }

            try
            {
                int result = Compiler.Compile(input);
                Console.WriteLine("Result: " + result);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
        }
    }
}
