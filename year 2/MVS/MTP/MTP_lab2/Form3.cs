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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
            IncarcareClase();
        }
        private void IncarcareClase()
        {
            flowLayoutPanel1.Controls.Clear();
            comboBox1.Items.Clear();
            foreach (string dirPath in Directory.EnumerateDirectories(Application.StartupPath))
            {
                // adauga numele directorului, fara cale
                DirectoryInfo dirName = new DirectoryInfo(dirPath);
                comboBox1.Items.Add(dirName.Name);
            }
        }
        private void IncarcaEleviClasa(string clasa)
        {
            flowLayoutPanel1.Controls.Clear();
            string path = Application.StartupPath + "\\" + clasa;
            foreach (string fileName in Directory.EnumerateFiles(path, "*.cls"))
            {
                using (StreamReader sr = new StreamReader(fileName))
                {
                    string cnp = Path.GetFileNameWithoutExtension(fileName);
                    string nume = sr.ReadLine();
                    string adresa = sr.ReadLine();
                    Person j = new Person(cnp, nume, adresa);
                    Button btn = new Button();
                    btn.Text = j.Name;
                    btn.Width = 200;
                    btn.Tag = j;
                    flowLayoutPanel1.Controls.Add(btn);
                    btn.Click += Btn_Click;
                }
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            IncarcaEleviClasa(comboBox1.Text);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        private void Btn_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            Button btn = (Button)sender;
            Person j = (Person)btn.Tag;
            listBox1.Items.Add("Name: " + j.Name);
            listBox1.Items.Add("CNP: " + j.Cnp);
            listBox1.Items.Add("Address: " + j.Address);
        }
    }
}
