import java.io.File;
import java.io.FilePermission;
import java.security.Permission;

public class CustomSecurityManager extends SecurityManager {

    @Override
    public void checkPermission(Permission perm) {
        // Check if the permission is a FilePermission
        if (perm instanceof FilePermission) {
            String actions = perm.getActions();
            if (actions.contains("read")) {
                // Check if the file read action is allowed
                if (!isFileAllowed(((FilePermission) perm).getName(), "read")) {
                    throw new SecurityException("File read access not allowed: " + perm.getName());
                }
            } else if (actions.contains("write")) {
                // Check if the file write action is allowed
                if (!isFileAllowed(((FilePermission) perm).getName(), "write")) {
                    throw new SecurityException("File write access not allowed: " + perm.getName());
                }
            }
        }
    }

    private boolean isFileAllowed(String filename, String action) {
        
        return filename.startsWith("/tmp/") || filename.startsWith("C:/temp/");
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
