import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class WordCount {
    public static void main(String[] args) {
        String filePath = "your_file_path_here.txt"; // Replace with the path to your file

        try {
            int wordCount = countWords(filePath);
            System.out.println("The file contains " + wordCount + " words.");
        } catch (IOException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
    }

    public static int countWords(String filePath) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            int wordCount = 0;
            String line;
            
            while ((line = reader.readLine()) != null) {
                String[] words = line.split("\\s+");
                wordCount += words.length;
            }
            
            return wordCount;
        }
    }
}
