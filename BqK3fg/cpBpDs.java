import java.io.File;
import java.io.FilePermission;
import java.security.Permission;
import java.util.logging.Level;
import java.util.logging.Logger;

public class CustomSecurityManager extends SecurityManager {

    private static final Logger LOGGER = Logger.getLogger(CustomSecurityManager.class.getName());

    @Override
    public void checkPermission(Permission perm) {
        if (perm instanceof FilePermission) {
            String actions = perm.getActions();
            String filePath = ((FilePermission) perm).getName();
            if (actions.contains("read") && !isFileAllowed(filePath, "read")) {
                logAccessDenied("File read access not allowed: " + filePath);
                throw new SecurityException("File read access not allowed: " + filePath);
            } else if (actions.contains("write") && !isFileAllowed(filePath, "write")) {
                logAccessDenied("File write access not allowed: " + filePath);
                throw new SecurityException("File write access not allowed: " + filePath);
            }
        }
    }

    private boolean isFileAllowed(String filename, String action) {
        return filename.startsWith("/tmp/") || filename.startsWith("C:/temp/");
    }

    private void logAccessDenied(String message) {
        LOGGER.log(Level.WARNING, message);
    }

    public static void main(String[] args) {
        System.setSecurityManager(new CustomSecurityManager());

        try {
            File file = new File("/home/user/sensitive.txt");
            if (file.exists()) {
                System.out.println("File exists.");
            } else {
                System.out.println("File does not exist.");
            }
        } catch (SecurityException e) {
            System.out.println("Security Exception: " + e.getMessage());
        }
    }
}
