using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MTP_lab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] utilizatori = File.ReadAllLines("users.txt");
            foreach (var line in utilizatori)
            {
                string[] inregistrare = line.Split(',');
                comboBox1.Items.Add(inregistrare[0]);
            }
        }

        private int tries = 0;
        private void button1_Click(object sender, EventArgs e)
        {
            string[] users = File.ReadAllLines("users.txt");

            foreach (var line in users)
            {
                string[] inregistrare = line.Split(',');
                if ((comboBox1.Text).Equals(inregistrare[0]))
                {
                    if ((textBox1.Text.Trim()).Equals(inregistrare[1].Trim()))
                    {
                        Form3 f = new Form3();
                        f.ShowDialog();
                    }
                    else
                    {
                        tries++;
                        MessageBox.Show("Wrong password! You have " + (3 -
                        tries).ToString() + " tries remaining.");
                    }
                }
                if (tries == 3)
                    Application.Exit();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2();
            f.ShowDialog();
        }
    }
}
