import java.io.File;

public class FileExistsExample {
    public static void main(String[] args) {
        // Specify the file path
        String filePath = "path/to/your/file.txt";

        // Create a File object
        File file = new File(filePath);

        // Check if the file exists
        if (file.exists()) {
            System.out.println("The file exists.");
        } else {
            System.out.println("The file does not exist.");
        }
    }
}
//Make sure to replace "path/to/your/file.txt" with the actual file path you want to check.
