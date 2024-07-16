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
    public partial class ExpiredForm : Form
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
        public ExpiredForm()
        {
            InitializeComponent();
            this.ControlBox = false;
            this.Text = String.Empty;
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        private void ExpiredForm_Load(object sender, EventArgs e)
        {
            try
            {
                DBConnection.conn.Open();

                string query = "SELECT first_name, last_name, email, book, borrow_date_start, borrow_date_end FROM users WHERE borrow_date_end < @today";
                SqlCommand command = new SqlCommand(query, DBConnection.conn);
                command.Parameters.AddWithValue("@today", DateTime.Today);

                SqlDataAdapter adapter = new SqlDataAdapter(command);
                DataTable dataTable = new DataTable();
                adapter.Fill(dataTable);

                usersDataGridView.Columns.Clear();

                usersDataGridView.Columns.Add("FirstNameColumn", "First Name");
                usersDataGridView.Columns["FirstNameColumn"].DataPropertyName = "first_name";

                usersDataGridView.Columns.Add("LastNameColumn", "Last Name");
                usersDataGridView.Columns["LastNameColumn"].DataPropertyName = "last_name";

                usersDataGridView.Columns.Add("EmailColumn", "Email");
                usersDataGridView.Columns["EmailColumn"].DataPropertyName = "email";

                usersDataGridView.Columns.Add("BookColumn", "Book");
                usersDataGridView.Columns["BookColumn"].DataPropertyName = "book";

                usersDataGridView.Columns.Add("BorrowStartDateColumn", "Borrow Start");
                usersDataGridView.Columns["BorrowStartDateColumn"].DataPropertyName = "borrow_date_start";

                usersDataGridView.Columns.Add("BorrowEndDateColumn", "Borrow End");
                usersDataGridView.Columns["BorrowEndDateColumn"].DataPropertyName = "borrow_date_end";

                usersDataGridView.DataSource = dataTable;

                DBConnection.conn.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MainMenu mainMenu = new MainMenu(LoginForm.user_name);
            this.Hide();
            mainMenu.Show();
        }

        private void usersDataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
