import java.util.ArrayList;
import java.util.List;

public class CalendarApplication {
    private List<String> events;

    public CalendarApplication() {
        events = new ArrayList<>();
    }

    public void addEvent(String event) {
        events.add(event);
    }

    public void viewEvents() {
        if (events.isEmpty()) {
            System.out.println("No events found.");
        } else {
            System.out.println("Events:");
            for (String event : events) {
                System.out.println("- " + event);
            }
        }
    }

    public static void main(String[] args) {
        CalendarApplication calendar = new CalendarApplication();
        
        // Adding events
        calendar.addEvent("Meeting with client");
        calendar.addEvent("Lunch with colleagues");
        
        // Viewing events
        calendar.viewEvents();
    }
}
