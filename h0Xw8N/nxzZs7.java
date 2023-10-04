import javax.management.*;
import java.lang.management.ManagementFactory;

public class CustomMBeanExample {

    public static void main(String[] args) throws Exception {
        // Create an instance of the MBeanServer
        MBeanServer mbs = ManagementFactory.getPlatformMBeanServer();

        // Create custom MBean
        CustomMBean customMBean = new CustomMBean();

        // Create object name for the MBean
        ObjectName mbeanName = new ObjectName("com.example:type=CustomMBean");

        // Register the MBean with the MBeanServer
        mbs.registerMBean(customMBean, mbeanName);

        // Start the application (simulated)
        customMBean.startApplication();

        // Allow the application to run for some time (simulated)
        Thread.sleep(5000);

        // Retrieve and display attribute values
        System.out.println("Application Name: " + mbs.getAttribute(mbeanName, "ApplicationName"));
        System.out.println("Number of Requests: " + mbs.getAttribute(mbeanName, "NumberOfRequests"));

        // Perform operations on the MBean
        mbs.invoke(mbeanName, "resetStatistics", null, null);

        // Retrieve and display updated attribute values
        System.out.println("Number of Requests (After Reset): " + mbs.getAttribute(mbeanName, "NumberOfRequests"));

        // Unregister the MBean when done
        mbs.unregisterMBean(mbeanName);
    }
}

// Custom MBean implementation
class CustomMBean implements CustomMBeanMXBean {
    private String applicationName = "MyApplication";
    private int numberOfRequests = 0;

    @Override
    public String getApplicationName() {
        return applicationName;
    }

    @Override
    public int getNumberOfRequests() {
        return numberOfRequests;
    }

    @Override
    public void startApplication() {
        // Simulated application logic
        for (int i = 0; i < 10; i++) {
            numberOfRequests++;
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public void resetStatistics() {
        numberOfRequests = 0;
    }
}

// Custom MBean interface
interface CustomMBeanMXBean {
    String getApplicationName();
    int getNumberOfRequests();
    void startApplication();
    void resetStatistics();
}
