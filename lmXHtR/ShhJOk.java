import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

public class WebScraper {

    public static void main(String[] args) throws ExecutionException, InterruptedException {
        List<String> urls = List.of(
            "https://example.com",
            "https://example.org",
            "https://example.net"
        );

        List<CompletableFuture<String>> completableFutureList = new ArrayList<>();

        for (String url : urls) {
            CompletableFuture<String> completableFuture = CompletableFuture.supplyAsync(() -> scrapeWebsite(url));
            completableFutureList.add(completableFuture);
        }

        CompletableFuture<Void> allOf = CompletableFuture.allOf(
            completableFutureList.toArray(new CompletableFuture[0])
        );

        allOf.join();

        for (CompletableFuture<String> completableFuture : completableFutureList) {
            String result = completableFuture.get();
            System.out.println(result);
        }
    }

    public static String scrapeWebsite(String url) {
        try {
            Document document = Jsoup.connect(url).get();
            Element body = document.body();
            Elements paragraphs = body.getElementsByTag("p");

            StringBuilder result = new StringBuilder();
            result.append("Scraping data from: ").append(url).append("\n");

            for (Element paragraph : paragraphs) {
                result.append(paragraph.text()).append("\n");
            }

            return result.toString();
        } catch (IOException e) {
            return "Error scraping data from " + url + ": " + e.getMessage();
        }
    }
}
