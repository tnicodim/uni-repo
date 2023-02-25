using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace exemplu1
{
    public partial class form_1 : Form
    {
        public form_1()
        {
            InitializeComponent();
        }

        private void form_1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void btnAuth_Click(object sender, EventArgs e)
        {
            if ((txtUser.Text == "user") && (txtPassword.Text == "pass"))
            {
                Form f = new form_main();
                f.ShowDialog();
            }
            else
                MessageBox.Show("Incorrect user or password !");
        }
    }
}
