import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import java.nio.ByteBuffer;
import java.security.*;

public class 5Oi5Ym {
    //SpaceCommunication
    private static final int AES_KEY_SIZE = 128;
    private static final String AES = "AES";
    private static final String RSA = "RSA";

    public static void main(String[] args) throws Exception {
        // Generate RSA key pair
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance(RSA);
        keyPairGenerator.initialize(2048);
        KeyPair keyPair = keyPairGenerator.generateKeyPair();
        PublicKey publicKey = keyPair.getPublic();
        PrivateKey privateKey = keyPair.getPrivate();

        // Simulate sending a secure message
        byte[] secureMessage = sendSecureMessage("Hello from space!", publicKey);

        // Simulate receiving and decrypting the message
        String receivedMessage = receiveSecureMessage(secureMessage, privateKey);
        System.out.println(receivedMessage);
    }

    public static byte[] sendSecureMessage(String message, PublicKey publicKey) throws Exception {
        // Generate a random AES key
        KeyGenerator keyGen = KeyGenerator.getInstance(AES);
        keyGen.init(AES_KEY_SIZE);
        SecretKey aesKey = keyGen.generateKey();

        // Encrypt the message using AES
        Cipher aesCipher = Cipher.getInstance(AES);
        aesCipher.init(Cipher.ENCRYPT_MODE, aesKey);
        byte[] encryptedMessage = aesCipher.doFinal(message.getBytes());

        // Encrypt the AES key using RSA
        Cipher rsaCipher = Cipher.getInstance(RSA);
        rsaCipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedAesKey = rsaCipher.doFinal(aesKey.getEncoded());

        // Return the combined encrypted AES key and encrypted message
        return ByteBuffer.allocate(encryptedAesKey.length + encryptedMessage.length)
                .put(encryptedAesKey)
                .put(encryptedMessage)
                .array();
    }

    public static String receiveSecureMessage(byte[] secureMessage, PrivateKey privateKey) throws Exception {
        ByteBuffer buffer = ByteBuffer.wrap(secureMessage);

        // Extract the encrypted AES key
        byte[] encryptedAesKey = new byte[256]; // RSA 2048 bits = 256 bytes
        buffer.get(encryptedAesKey);

        // Decrypt the AES key using RSA
        Cipher rsaCipher = Cipher.getInstance(RSA);
        rsaCipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] aesKeyBytes = rsaCipher.doFinal(encryptedAesKey);
        SecretKey aesKey = new SecretKeySpec(aesKeyBytes, AES);

        // Extract and decrypt the message using AES
        byte[] encryptedMessage = new byte[buffer.remaining()];
        buffer.get(encryptedMessage);
        Cipher aesCipher = Cipher.getInstance(AES);
        aesCipher.init(Cipher.DECRYPT_MODE, aesKey);
        byte[] decryptedMessage = aesCipher.doFinal(encryptedMessage);

        return new String(decryptedMessage);
    }
}
