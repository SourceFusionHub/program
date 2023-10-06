public class TrafficLightSimulator {
    public static void main(String[] args) {
        simulateTrafficLight();
    }

    public static void simulateTrafficLight() {
        int duration = 2000; // Duration of each light in milliseconds (2 seconds)

        while (true) {
            // Red light
            System.out.println("Red Light");
            sleep(duration);

            // Yellow light
            System.out.println("Yellow Light");
            sleep(duration);

            // Green light
            System.out.println("Green Light");
            sleep(duration);
        }
    }

    public static void sleep(int milliseconds) {
        try {
            Thread.sleep(milliseconds);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
