import javax.management.Attribute;
import javax.management.AttributeList;
import javax.management.MBeanServerConnection;
import javax.management.ObjectName;

public class JMXMonitor {

    public static void main(String[] args) throws Exception {
        // Create a connection to the MBean server.
        MBeanServerConnection mbsc = JMXConnectorFactory.connect(new JMXServiceURL("service:jmx:rmi:///jndi/rmi://localhost:9010/jmxrmi"));

        // Get the ObjectName of the MBean that you want to monitor.
        ObjectName objectName = ObjectName.getInstance("java.lang:type=GarbageCollector,name=PS MarkSweep");

        // Get the attributes of the MBean that you want to monitor.
        AttributeList attributeList = mbsc.getAttributes(objectName, new String[]{"CollectionCount", "CollectionTime"});

        // Process the attribute values.
        Attribute collectionCountAttribute = attributeList.get(0);
        Attribute collectionTimeAttribute = attributeList.get(1);

        int collectionCount = (Integer) collectionCountAttribute.getValue();
        long collectionTime = (Long) collectionTimeAttribute.getValue();

        // Manage the application performance metrics.
        System.out.println("Garbage collection count: " + collectionCount);
        System.out.println("Garbage collection time: " + collectionTime);
    }
}
