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
        public LoginForm()
        {
            InitializeComponent();
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
                await Task.Delay(1000);
                MainMenu mainMenu = new MainMenu(columnName);
                this.Hide();
                mainMenu.Show();
            }
            else
            {
                // Invalid login
                label3.Location = new Point(110, 100);
                label3.Text = "Invalid username or password.";
                label3.ForeColor = Color.Red;
                label3.Visible = true;
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
