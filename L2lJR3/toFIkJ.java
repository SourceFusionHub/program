import java.util.*;

class TextEditor {
    private StringBuilder text;
    private Stack<String> undoStack;
    private Stack<String> redoStack;

    public TextEditor() {
        text = new StringBuilder();
        undoStack = new Stack<>();
        redoStack = new Stack<>();
    }

    public void insertText(String newText) {
        undoStack.push(text.toString());
        text.append(newText);
        redoStack.clear();
    }

    public void deleteText(int numChars) {
        if (numChars > 0 && numChars <= text.length()) {
            undoStack.push(text.toString());
            text.delete(text.length() - numChars, text.length());
            redoStack.clear();
        } else {
            System.out.println("Invalid deletion operation.");
        }
    }

    public void undo() {
        if (!undoStack.isEmpty()) {
            redoStack.push(text.toString());
            text = new StringBuilder(undoStack.pop());
        } else {
            System.out.println("Nothing to undo.");
        }
    }

    public void redo() {
        if (!redoStack.isEmpty()) {
            undoStack.push(text.toString());
            text = new StringBuilder(redoStack.pop());
        } else {
            System.out.println("Nothing to redo.");
        }
    }

    public String getText() {
        return text.toString();
    }

    public static void main(String[] args) {
        TextEditor editor = new TextEditor();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Current Text: " + editor.getText());
            System.out.println("Menu:");
            System.out.println("1. Insert Text");
            System.out.println("2. Delete Text");
            System.out.println("3. Undo");
            System.out.println("4. Redo");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline

            switch (choice) {
                case 1:
                    System.out.print("Enter text to insert: ");
                    String insertText = scanner.nextLine();
                    editor.insertText(insertText);
                    break;
                case 2:
                    System.out.print("Enter the number of characters to delete: ");
                    int numCharsToDelete = scanner.nextInt();
                    editor.deleteText(numCharsToDelete);
                    break;
                case 3:
                    editor.undo();
                    break;
                case 4:
                    editor.redo();
                    break;
                case 5:
                    System.out.println("Exiting the text editor.");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
                      }
