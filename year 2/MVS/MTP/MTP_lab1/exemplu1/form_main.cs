using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace exemplu1
{
    public partial class form_main : Form
    {
        public form_main()
        {
            InitializeComponent();
        }

        private void txtFName_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (!System.Text.RegularExpressions.Regex.IsMatch(txtAge.Text, @"^[0-9]*$"))
            {
                MessageBox.Show("Write a valid age");
                txtAge.Text = txtAge.Text.Remove(txtAge.Text.Length - 1);
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void form_main_Load(object sender, EventArgs e)
        {
            label5.Text = System.DateTime.Today.ToLongDateString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string nume = txtFName.Text;
            string prenume = txtLName.Text;
            string varsta = txtAge.Text;
            //verificare campuri goale
            if ((txtFName.Text == "") || (txtLName.Text == "") || (txtAge.Text == ""))
                MessageBox.Show("Completati toate campurile!");
            else
            {
                //alta metoda de verificare camp - sa contina doar litere
                if (!Regex.Match(txtFName.Text, "^[A-Z][a-zA-Z]*$").Success)
                {
                    // numele este incorect
                    MessageBox.Show("Invalid Last Name", "Message", MessageBoxButtons.OK,MessageBoxIcon.Error);
                    txtFName.Focus();
                    return;
                }
                string judet = listBox1.SelectedItem.ToString();

                string gen;
                if (radioButton1.Checked == true)
                    gen = radioButton1.Text;
                else
                    gen = radioButton2.Text;
                //cream lista de limbaje de programare
                string lp = "";
                if (checkBox1.Checked)
                    lp = lp + " " + checkBox1.Text;
                if (checkBox2.Checked)
                    lp = lp + " " + checkBox2.Text;
                if (checkBox3.Checked)
                    lp = lp + " " + checkBox3.Text;
                if (checkBox4.Checked)
                    lp = lp + " " + checkBox4.Text;
                if (checkBox4.Checked)
                    lp = lp + " " + checkBox4.Text;
                string linie = nume + " " + prenume + " " + judet + " " + gen + " " + lp;
                listBox2.Items.Add(linie);
            }
        }
    }
}
