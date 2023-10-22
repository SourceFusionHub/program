import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Tile {
    private char letter;

    public Tile(char letter) {
        this.letter = letter;
    }

    public char getLetter() {
        return letter;
    }
}

class Board {
    private char[][] board;

    public Board(int rows, int cols) {
        board = new char[rows][cols];
    }

    public void displayBoard() {
        for (char[] row : board) {
            for (char cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }

    public void placeTile(int row, int col, char letter) {
        board[row][col] = letter;
    }
}

public class WordGame {
    private static List<Tile> letterTiles = new ArrayList<>();

    static {
        // Add letter tiles (A-Z) to the letterTiles list
        for (char c = 'A'; c <= 'Z'; c++) {
            letterTiles.add(new Tile(c));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create a 5x5 board
        Board board = new Board(5, 5);

        // Display the empty board
        board.displayBoard();

        // Simulate placing a tile on the board
        board.placeTile(1, 2, 'A');

        // Display the updated board
        System.out.println("Board after placing a tile:");
        board.displayBoard();

        // Simulate adding a word to the board
        System.out.println("Enter a word to place on the board:");
        String word = scanner.nextLine();
        char[] letters = word.toCharArray();

        int row = 2;
        int col = 1;
        for (char letter : letters) {
            board.placeTile(row, col, letter);
            col++;
        }

        // Display the final board
        System.out.println("Board after placing the word:");
        board.displayBoard();
    }
}
