using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MTP_project
{
    public partial class BorrowForm : Form
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
        public BorrowForm()
        {
            InitializeComponent();
            this.ControlBox = false;
            this.Text = String.Empty;
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        private bool checkInputs()
        {
            if (!string.IsNullOrEmpty(textBox1.Text) && !string.IsNullOrEmpty(textBox2.Text) && !string.IsNullOrEmpty(textBox3.Text))
            {
                return true;
            }
            else
            {
                MessageBox.Show("Please complete all textboxes!");
                return false;
            }
        }
        private bool checkInput2()
        {
            if (!string.IsNullOrEmpty(textBox1.Text) && !string.IsNullOrEmpty(textBox2.Text))
            {
                return true;
            }
            else
            {
                MessageBox.Show("Please complete all textboxes!");
                return false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MainMenu mainMenu = new MainMenu(LoginForm.user_name);
            this.Hide();
            mainMenu.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (!checkInput2())
                return;
            string firstName = textBox1.Text;
            string lastName = textBox2.Text;
            bool userExists = CheckUserExists(firstName, lastName);
            if (!userExists)
                MessageBox.Show("User not found!");
            else
                ResetUserData(firstName, lastName);
        }


        private void button2_Click(object sender, EventArgs e)
        {
            if (!checkInputs())
                return;
            string firstName = textBox1.Text;
            string lastName = textBox2.Text;
            string book = textBox3.Text;
            bool userExists = CheckUserExists(firstName, lastName);
            if (!userExists)
                MessageBox.Show("User not found!");
            else
               LogBorrow(firstName, lastName, book);

        }

        private void LogBorrow(string firstName, string lastName, string book)
        {
            try
            {
                DBConnection.conn.Open();
                string checkQuery = "SELECT book FROM users WHERE first_name = @FirstName AND last_name = @LastName";
                SqlCommand checkCommand = new SqlCommand(checkQuery, DBConnection.conn);
                checkCommand.Parameters.AddWithValue("@FirstName", firstName);
                checkCommand.Parameters.AddWithValue("@LastName", lastName);
                object existingBook = checkCommand.ExecuteScalar();

                if (existingBook != null && existingBook != DBNull.Value)
                {
                    MessageBox.Show("The user already has a book borrowed.");
                }
                else
                {
                    string updateQuery = "UPDATE users SET book = @Book, borrow_date_start = @borrow_start, borrow_date_end = @borrow_end WHERE first_name = @FirstName AND last_name = @LastName";
                    SqlCommand updateCommand = new SqlCommand(updateQuery, DBConnection.conn);
                    updateCommand.Parameters.AddWithValue("@borrow_start", DateTime.Today);
                    updateCommand.Parameters.AddWithValue("@borrow_end", DateTime.Today.AddDays(30));
                    updateCommand.Parameters.AddWithValue("@FirstName", firstName);
                    updateCommand.Parameters.AddWithValue("@LastName", lastName);
                    updateCommand.Parameters.AddWithValue("@Book", book);
                    updateCommand.ExecuteNonQuery();

                    string historyQuery = "INSERT INTO History VALUES (@book, @borrow_date)";
                    SqlCommand historyCommand = new SqlCommand(historyQuery, DBConnection.conn);
                    historyCommand.Parameters.AddWithValue("@book", book);
                    historyCommand.Parameters.AddWithValue("@borrow_date", DateTime.Today);
                    historyCommand.ExecuteNonQuery();

                    MessageBox.Show("Borrowing logged successfully.");
                }

                DBConnection.conn.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }

        private void ResetUserData(string firstName, string lastName)
        {
            try
            {
                DBConnection.conn.Open();
                string query = "UPDATE users SET book = NULL, borrow_date_start = NULL, borrow_date_end = NULL WHERE first_name = @FirstName AND last_name = @LastName";
                SqlCommand command = new SqlCommand(query, DBConnection.conn);
                command.Parameters.AddWithValue("@FirstName", firstName);
                command.Parameters.AddWithValue("@LastName", lastName);
                command.ExecuteNonQuery();
                DBConnection.conn.Close();
                MessageBox.Show("Return logged successfully.");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }
        private bool CheckUserExists(string firstName, string lastName)
        {
            bool userExists = false;

            try
            {
                DBConnection.conn.Open();
                string query = "SELECT COUNT(*) FROM users WHERE first_name = @FirstName AND last_name = @LastName";
                SqlCommand command = new SqlCommand(query, DBConnection.conn);
                {
                    command.Parameters.AddWithValue("@FirstName", firstName);
                    command.Parameters.AddWithValue("@LastName", lastName);
                    int count = (int)command.ExecuteScalar();
                    userExists = (count > 0);
                }
                DBConnection.conn.Close();

            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }

            return userExists;
        }
    }
}
