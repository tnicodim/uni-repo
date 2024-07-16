package SI_LAB7.ex2;
import java.math.BigInteger;
import java.security.*;
import java.security.spec.InvalidKeySpecException;
import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
// import javax.rmi.CORBA.Util;

public class Main {
    public static void main(String[] args) throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidKeyException, ShortBufferException, IllegalBlockSizeException, BadPaddingException, InvalidAlgorithmParameterException, InvalidKeySpecException {
        // declare secure PRNG
        SecureRandom myPRNG = new SecureRandom();
        byte[] keyBytes = new byte[16];
        char[] password = "qwerty".toCharArray();
        byte[] salt = new byte[16];
        int iteration_count = 10000;
        int key_size = 128;
        myPRNG.nextBytes(salt);
        String plain = "1111222233334444";
// seed the key
        myPRNG.nextBytes(keyBytes);
        // initialize key factory for HMAC-SHA1 derivation
        SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");
// set key specification
        PBEKeySpec pbekSpec = new PBEKeySpec(password, salt, iteration_count, key_size);
// generate the key
        SecretKey myAESPBKey = new SecretKeySpec(keyFactory.generateSecret(pbekSpec).getEncoded(), "AES");
// print the key
        System.out.println("AES key: " +  new BigInteger(1,myAESPBKey.getEncoded()).toString(16));
// build the key from random key bytes
   //     SecretKeySpec myKey = new SecretKeySpec(keyBytes, "AES");
        SecretKey myKey = myAESPBKey;
        // instantiate AES object for ECB with no padding
        Cipher myAES = Cipher.getInstance("AES/CBC/PKCS5Padding");
// initialize AES objecy to encrypt mode
        myAES.init(Cipher.ENCRYPT_MODE, myAESPBKey, new IvParameterSpec(new byte[16]));
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
        myAES.init(Cipher.DECRYPT_MODE, myAESPBKey, new IvParameterSpec(new byte[16]));
// initialize a new array of bytes to place the decryption
        byte[] dec_plaintext = new byte[16];
        cLength = myAES.update(ciphertext, 0, ciphertext.length, dec_plaintext, 0);
// process remaining blocks of ciphertext
        cLength += myAES.doFinal(dec_plaintext, cLength);
// print the new plaintext (hopefully identical to the initial one)
        System.out.println("decrypted: " + new BigInteger(1,dec_plaintext).toString(16));
        // get a Cipher instance for RSA with PKCS1 padding
        Cipher myRSA = Cipher.getInstance("RSA/ECB/PKCS1Padding");
// get an instance for the Key Generator
        KeyPairGenerator myRSAKeyGen = KeyPairGenerator.getInstance("RSA");
// generate an 1024 bit key
        myRSAKeyGen.initialize(1024, myPRNG);
        KeyPair myRSAKeyPair= myRSAKeyGen.generateKeyPair();
// store the public and private key individually
        Key pbKey = myRSAKeyPair.getPublic();
        Key pvKey = myRSAKeyPair.getPrivate();
// init cipher for encryption
        myRSA.init(Cipher.ENCRYPT_MODE, pbKey, myPRNG);
// encrypt, as expected we encrypt a symmetric key with RSA rather than a file or some longer stream which should be encrypted with AES
        ciphertext = myRSA.doFinal(keyBytes);
// init cipher for decryption
        myRSA.init(Cipher.DECRYPT_MODE, pvKey);
// decrypt
        plaintext = myRSA.doFinal(ciphertext);
        System.out.println("plaintext: " + new BigInteger(1,plaintext).toString(16));
        System.out.println("ciphertext: " + new BigInteger(1,ciphertext).toString(16));
      //  System.out.println("keybytes: " + new BigInteger(1,keyBytes).toString(16));

    }
}
