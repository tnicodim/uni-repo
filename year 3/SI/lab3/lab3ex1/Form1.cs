using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Security.Cryptography;

namespace lab3ex1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MACHandler mh = new MACHandler(comboBoxMAC.Text);
            ConversionHandler myConverter = new ConversionHandler();
            byte[] mac = mh.ComputeMAC(myConverter.StringToByteArray(textBoxPlain.Text), myConverter.StringToByteArray(textBoxKey.Text));
            textBoxMAC.Text = myConverter.ByteArrayToString(mac);
            textBoxMACHEX.Text = myConverter.ByteArrayToHexString(mac);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MACHandler mh = new MACHandler(comboBoxMAC.Text);
            ConversionHandler myConverter = new ConversionHandler();
            if (mh.CheckAuthenticity(myConverter.StringToByteArray(textBoxPlain.Text),myConverter.HexStringToByteArray(textBoxMACHEX.Text), myConverter.StringToByteArray(textBoxKey.Text)) == true)
            {
                System.Windows.Forms.MessageBox.Show("MAC OK !!!");
            }
            else
            {
                System.Windows.Forms.MessageBox.Show("MAC NOT OK !!!");
            }
    }

        private void button3_Click(object sender, EventArgs e)
        {
            MACHandler mh = new MACHandler(comboBoxMAC.Text);
            ConversionHandler myConverter = new ConversionHandler();
            byte[] hash = mh.ComputeHASH(myConverter.StringToByteArray(textBoxPlain.Text));
            textBoxHASH.Text = myConverter.ByteArrayToString(hash);
            textBoxHASHHEX.Text = myConverter.ByteArrayToHexString(hash);
        }
    }
}
