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

        private const int WM_NCHITTEST = 0x84;
        private const int HTCLIENT = 0x1;
        private const int HTCAPTION = 0x2;
        protected override void WndProc(ref Message message)
        {
            base.WndProc(ref message);

            if (message.Msg == WM_NCHITTEST && (int)message.Result == HTCLIENT)
                message.Result = (IntPtr)HTCAPTION;
        }

        public MainMenu(string columnName)
        { 
           InitializeComponent();
            label1.Text = "Welcome back, " + columnName;
            int labelTop = (this.ClientSize.Height - label1.Height) / 10;
            label1.Location = new Point((this.ClientSize.Width - label1.Width) / 2, labelTop);
            this.ControlBox = false;
            this.Text = String.Empty;
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
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

        private void button8_Click(object sender, EventArgs e)
        {
            LoginForm loginForm = new LoginForm();
            this.Hide();
            loginForm.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            BorrowForm borrowForm = new BorrowForm();
            this.Hide();
            borrowForm.Show();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            ExpiredForm expiredForm = new ExpiredForm();
            this.Hide();
            expiredForm.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            RegisterForm regForm = new RegisterForm();
            this.Hide();
            regForm.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            ChartForm chartForm = new ChartForm();
            this.Hide();
            chartForm.Show();
        }
    }

}
