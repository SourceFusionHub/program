import javax.crypto.Cipher;
import javax.crypto.CipherSpi;
import javax.crypto.NoSuchPaddingException;
import java.security.*;
import java.security.spec.AlgorithmParameterSpec;

// Custom XOR Cipher
class XORCipher extends CipherSpi {
    private byte[] keyBytes;

    @Override
    protected void engineSetMode(String mode) throws NoSuchAlgorithmException {
        // Do nothing (we don't support different modes)
    }

    @Override
    protected void engineSetPadding(String padding) throws NoSuchPaddingException {
        // Do nothing (we don't support padding)
    }

    @Override
    protected int engineGetBlockSize() {
        return 0;  // Stream cipher
    }

    @Override
    protected int engineGetOutputSize(int inputLen) {
        return inputLen;
    }

    @Override
    protected byte[] engineGetIV() {
        return null;
    }

    @Override
    protected AlgorithmParameters engineGetParameters() {
        return null;
    }

    @Override
    protected void engineInit(int opmode, Key key, SecureRandom random) throws InvalidKeyException {
        keyBytes = key.getEncoded();
    }

    @Override
    protected void engineInit(int opmode, Key key, AlgorithmParameterSpec params, SecureRandom random) throws InvalidKeyException, InvalidAlgorithmParameterException {
        engineInit(opmode, key, random);
    }

    @Override
    protected void engineInit(int opmode, Key key, AlgorithmParameters params, SecureRandom random) throws InvalidKeyException, InvalidAlgorithmParameterException {
        engineInit(opmode, key, random);
    }

    @Override
    protected byte[] engineUpdate(byte[] input, int inputOffset, int inputLen) {
        byte[] output = new byte[inputLen];
        for (int i = 0; i < inputLen; i++) {
            output[i] = (byte) (input[i + inputOffset] ^ keyBytes[i % keyBytes.length]);
        }
        return output;
    }

    @Override
    protected int engineUpdate(byte[] input, int inputOffset, int inputLen, byte[] output, int outputOffset) throws ShortBufferException {
        byte[] result = engineUpdate(input, inputOffset, inputLen);
        System.arraycopy(result, 0, output, outputOffset, result.length);
        return result.length;
    }

    @Override
    protected byte[] engineDoFinal(byte[] input, int inputOffset, int inputLen) {
        return engineUpdate(input, inputOffset, inputLen);
    }

    @Override
    protected int engineDoFinal(byte[] input, int inputOffset, int inputLen, byte[] output, int outputOffset) throws ShortBufferException {
        return engineUpdate(input, inputOffset, inputLen, output, outputOffset);
    }
}

// XOR Key
class XORKey implements Key {
    private final byte[] keyBytes;

    public XORKey(byte[] keyBytes) {
        this.keyBytes = keyBytes;
    }

    @Override
    public String getAlgorithm() {
        return "XOR";
    }

    @Override
    public String getFormat() {
        return "RAW";
    }

    @Override
    public byte[] getEncoded() {
        return keyBytes;
    }
}

// Testing the XOR Cipher
public class CustomCryptoExample {
    public static void main(String[] args) throws Exception {
        byte[] keyData = "12345678".getBytes();  // Example key
        XORKey key = new XORKey(keyData);

        Cipher cipher = Cipher.getInstance("XOR");
        cipher.init(Cipher.ENCRYPT_MODE, key);

        byte[] plaintext = "Hello, World!".getBytes();
        byte[] ciphertext = cipher.doFinal(plaintext);

        System.out.println(new String(ciphertext));  // Prints scrambled text

        cipher.init(Cipher.DECRYPT_MODE, key);
        byte[] decryptedText = cipher.doFinal(ciphertext);

        System.out.println(new String(decryptedText));  // Should print "Hello, World!"
    }
}
