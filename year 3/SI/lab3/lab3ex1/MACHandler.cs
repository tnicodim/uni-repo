using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace lab3ex1
{
    class MACHandler
    {
        private HMAC myMAC;
        private HashAlgorithm myHash;
        public MACHandler(string name)
        {
            if (name.CompareTo("SHA1") == 0)
            {
                myMAC = new System.Security.Cryptography.HMACSHA1();
                myHash = new SHA1CryptoServiceProvider();
            }
            if (name.CompareTo("MD5") == 0)
            {
                myMAC = new System.Security.Cryptography.HMACMD5();
                myHash = new MD5CryptoServiceProvider();
            }
            if (name.CompareTo("RIPEMD") == 0)
            {
                myMAC = new System.Security.Cryptography.HMACRIPEMD160();
                myHash = new RIPEMD160Managed();
            }
            if (name.CompareTo("SHA256") == 0)
            {
                myMAC = new System.Security.Cryptography.HMACSHA256();
                myHash = new SHA256CryptoServiceProvider();
            }
            if (name.CompareTo("SHA384") == 0)
            {
                myMAC = new System.Security.Cryptography.HMACSHA384();
                myHash = new SHA384CryptoServiceProvider();
            }
            if (name.CompareTo("SHA512") == 0)

            {
                myMAC = new System.Security.Cryptography.HMACSHA512();
                myHash = new SHA512CryptoServiceProvider();
            }
        }
        public bool CheckAuthenticity(byte[] mes, byte[] mac, byte[] key)
        {
            myMAC.Key = key;
            if (CompareByteArrays(myMAC.ComputeHash(mes), mac, myMAC.HashSize / 8) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public byte[] ComputeMAC(byte[] mes, byte[] key)
        {
            myMAC.Key = key;
            return myMAC.ComputeHash(mes);
        }
        public byte[] ComputeHASH(byte[] mes)
        {
            return myHash.ComputeHash(mes);
        }
        public int MACByteLength()
        {
            return myMAC.HashSize / 8;
        }
        private bool CompareByteArrays(byte[] a, byte[] b, int len)
        {
            for (int i = 0; i < len; i++)
                if (a[i] != b[i]) return false;
            return true;
        }
    }
}
