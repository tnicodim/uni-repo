using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MTP_project
{
    public partial class MainMenu : Form
    {

        public MainMenu()
        {

        }

        public MainMenu(string columnName)
        { 
           InitializeComponent();
            label1.Text = "Welcome back, " + columnName;
            int labelTop = (this.ClientSize.Height - label1.Height) / 10;
            label1.Location = new Point((this.ClientSize.Width - label1.Width) / 2, labelTop);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Hide();
            UserSearchForm searchForm = new UserSearchForm();
            searchForm.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
           
        }
    }

}
