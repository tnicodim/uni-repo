package SI_LAB7.ex1;
import java.math.BigInteger;
import java.security.*;
import javax.crypto.Cipher;
import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.ShortBufferException;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
// import javax.rmi.CORBA.Util;

public class Main {
    public static void main(String[] args) throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidKeyException, ShortBufferException, IllegalBlockSizeException, BadPaddingException, InvalidAlgorithmParameterException {
        byte[] keyBytes = new byte[16];
        String plain = "1111222233334444";
// declare secure PRNG
        SecureRandom myPRNG = new SecureRandom();
// seed the key
        myPRNG.nextBytes(keyBytes);
// build the key from random key bytes
        SecretKeySpec myKey = new SecretKeySpec(keyBytes, "AES");
        // instantiate AES object for CCB with padding
        Cipher myAES = Cipher.getInstance("AES/CBC/PKCS5Padding");
// initialize AES objecy to encrypt mode
        myAES.init(Cipher.ENCRYPT_MODE, myKey, new IvParameterSpec(new byte[16]));
// initialize plaintext
        byte[] plaintext = plain.getBytes();
//initialize ciphertext
        byte[] ciphertext = new byte[32];
// update cipher with the plaintext
        int cLength = myAES.update(plaintext, 0, plaintext.length, ciphertext, 0);
// process remaining blocks of plaintext
        cLength += myAES.doFinal(ciphertext, cLength);
// print plaintext and ciphertext
        System.out.println("plaintext: " + new BigInteger(1,plaintext).toString(16));
        System.out.println("ciphertext: " + new BigInteger(1,ciphertext).toString(16));
// initialize AES for decryption
        myAES.init(Cipher.DECRYPT_MODE, myKey, new IvParameterSpec(new byte[16]));
// initialize a new array of bytes to place the decryption
        byte[] dec_plaintext = new byte[16];
        cLength = myAES.update(ciphertext, 0, ciphertext.length, dec_plaintext, 0);
// process remaining blocks of ciphertext
        cLength += myAES.doFinal(dec_plaintext, cLength);
// print the new plaintext (hopefully identical to the initial one)
        System.out.println("decrypted: " + new BigInteger(1,dec_plaintext).toString(16));
    }
}
