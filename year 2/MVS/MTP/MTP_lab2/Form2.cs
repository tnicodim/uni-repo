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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            progressBar1.Value += 5;
            progressBar1.Value -= 1;
            progressBar1.Value += 1;
            if (progressBar1.Value == progressBar1.Maximum)
            {
                timer1.Stop();
                MessageBox.Show("Registration successfull!");
                Application.Restart();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Start();
            using (StreamWriter w = File.AppendText("users.txt"))
            {
                w.WriteLine(textBox1.Text + "," + textBox2.Text);
            }
        }
    }
}
