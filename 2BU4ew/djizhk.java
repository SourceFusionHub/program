import java.security.*;
import java.security.spec.X509EncodedKeySpec;
import java.util.Base64;

import javax.crypto.Cipher;

public class HealthcareIoT {

    public static void main(String[] args) throws Exception {
        // Simulate IoT device and server
        IoTDevice device = new IoTDevice();
        Server server = new Server();

        // IoT device generates keys and sends its public key to the server
        String publicKeyBase64 = Base64.getEncoder().encodeToString(device.getPublicKey().getEncoded());
        server.receiveDevicePublicKey(publicKeyBase64);

        // IoT device encrypts and sends sensitive data to the server
        String data = "Patient's vital signs: BPM 75, BP 120/80";
        String encryptedData = device.encryptData(data);
        server.receiveEncryptedData(encryptedData);

        // Server decrypts and processes data
        String decryptedData = server.decryptData(encryptedData);
        System.out.println("Server received and decrypted data: " + decryptedData);
    }
}

class IoTDevice {
    private PublicKey publicKey;
    private PrivateKey privateKey;

    public IoTDevice() throws NoSuchAlgorithmException {
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
        keyPairGenerator.initialize(2048);
        KeyPair keyPair = keyPairGenerator.generateKeyPair();
        this.publicKey = keyPair.getPublic();
        this.privateKey = keyPair.getPrivate();
    }

    public PublicKey getPublicKey() {
        return publicKey;
    }

    public String encryptData(String data) throws Exception {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedBytes = cipher.doFinal(data.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }
}

class Server {
    private PublicKey devicePublicKey;
    private PrivateKey serverPrivateKey;

    public void receiveDevicePublicKey(String publicKeyBase64) throws Exception {
        byte[] publicKeyBytes = Base64.getDecoder().decode(publicKeyBase64);
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");
        X509EncodedKeySpec publicKeySpec = new X509EncodedKeySpec(publicKeyBytes);
        this.devicePublicKey = keyFactory.generatePublic(publicKeySpec);
    }

    public void receiveEncryptedData(String encryptedData) {
        // Simulate data reception and storage on the server
    }

    public String decryptData(String encryptedData) throws Exception {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.DECRYPT_MODE, serverPrivateKey);
        byte[] encryptedBytes = Base64.getDecoder().decode(encryptedData);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        return new String(decryptedBytes);
    }
}
