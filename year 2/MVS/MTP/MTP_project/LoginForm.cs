using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MTP_project
{
    public partial class LoginForm : Form
    {
        public static string user_name;
        private int tries = 0;
        private const int WM_NCHITTEST = 0x84;
        private const int HTCLIENT = 0x1;
        private const int HTCAPTION = 0x2;
        protected override void WndProc(ref Message message)
        {
            base.WndProc(ref message);

            if (message.Msg == WM_NCHITTEST && (int)message.Result == HTCLIENT)
                message.Result = (IntPtr)HTCAPTION;
        }
        public LoginForm()
        {
            InitializeComponent();
            this.ControlBox = false;
            this.Text = String.Empty;
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        private string connectionString = DBConnection.conn.ToString();


        async private void button1_Click(object sender, EventArgs e)
        {
            string username = textBox1.Text.Trim();
            string password = textBox2.Text;

            if (string.IsNullOrEmpty(username) || string.IsNullOrEmpty(password))
            {
                label3.Location = new Point(70, 100);
                label3.Text = "Please enter both username and password.";
                label3.ForeColor = Color.Red;
                label3.Visible = true;
                return;
            }

            string columnName = CheckPasswordMatch(username, password);

            if (!string.IsNullOrEmpty(columnName))
            {
                // Successful login
                label3.Location = new Point(120, 100);
                label3.Text = "Login Successful";
                label3.ForeColor = Color.ForestGreen;
                label3.Visible = true;
                user_name = columnName;
                await Task.Delay(1000);
                MainMenu mainMenu = new MainMenu(user_name);
                this.Hide();
                mainMenu.Show();
            }
            else
            {
                // Invalid login
                tries++;
                label3.Location = new Point(110, 100);
                label3.Text = "Invalid username or password.";
                label3.ForeColor = Color.Red;
                label3.Visible = true;
                if (tries == 3) {
                    MessageBox.Show("Maximum number of attempts reached!");
                    Application.Exit();
                }
            }
        }

        private string CheckPasswordMatch(string username, string password)
        {
            string columnName = null;

            // Query to check if the username and password match and retrieve the column name
            string query = "SELECT name FROM SysAdmins WHERE Username = @Username AND Password = @Password";

            using (SqlCommand command = new SqlCommand(query, DBConnection.conn))
            {
                command.Parameters.AddWithValue("@Username", username);
                command.Parameters.AddWithValue("@Password", password);

                try
                {
                    DBConnection.conn.Open();
                    var result = command.ExecuteScalar();

                    // Check if a result was obtained
                    if (result != null)
                    {
                        columnName = result.ToString();
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("An error occurred: " + ex.Message);
                }
            }

            DBConnection.conn.Close();
            return columnName;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
