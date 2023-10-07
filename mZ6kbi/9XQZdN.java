import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class WordCount {
    public static void main(String[] args) {
        String filePath = "myfile.txt"; // myfile.txt should be replace with the actual file path
        
        try {
            FileReader fileReader = new FileReader(filePath);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            int wordCount = 0;

            while ((line = bufferedReader.readLine()) != null) {
                // Split the line into words using space as the delimiter
                String[] words = line.split("\\s+");
                wordCount += words.length;
            }

            bufferedReader.close();
            System.out.println("Number of words in the file: " + wordCount);
        } catch (IOException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
    }
}
