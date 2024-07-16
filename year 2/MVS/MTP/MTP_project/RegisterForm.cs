using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MTP_project
{
    public partial class RegisterForm : Form
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
        public RegisterForm()
        {
            InitializeComponent();
            this.ControlBox = false;
            this.Text = String.Empty;
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        public byte[] imageData;

        private bool ValidateRomanianSSN(string ssn, out DateTime dateOfBirth, out string gender)
        {
            dateOfBirth = new DateTime();
            gender = "";

            if (ssn.Length != 13)
            {
                MessageBox.Show("Invalid SSN: SSN must be 13 characters long.");
                return false;
            }

            if (!ssn.All(char.IsDigit))
            {
                MessageBox.Show("Invalid SSN: SSN must only contain digits.");
                return false;
            }

            int genderDigit = int.Parse(ssn.Substring(0, 1));
            if (!(genderDigit == 1 || genderDigit == 2 || genderDigit == 5 || genderDigit == 6))
            {
                MessageBox.Show("Invalid SSN: First digit must be 1-2 or 5-6.");
                return false;
            }

            string dateOfBirthString = ssn.Substring(1, 6);
            if (!DateTime.TryParseExact(dateOfBirthString, "yyMMdd", null, System.Globalization.DateTimeStyles.None, out dateOfBirth))
            {
                MessageBox.Show("Invalid SSN: Invalid date of birth.");
                return false;
            }

            int identificationNumber = int.Parse(ssn.Substring(7, 3));
            if (identificationNumber == 0 || identificationNumber > 999)
            {
                MessageBox.Show("Invalid SSN: Invalid identification number.");
                return false;
            }

            if (genderDigit == 1 || genderDigit == 5)
            {
                gender = "Male";
            }
            else if (genderDigit == 2 || genderDigit == 6)
            {
                gender = "Female";
            }

            return true;
        }

        public bool IsValidEmail(string email)
        {
            if (string.IsNullOrEmpty(email))
            {
                return false;
            }
            try
            {
                var mailAddress = new MailAddress(email);
                return true;
            }
            catch (FormatException)
            {
                return false;
            }
        }

        private void pictureBox1_DragDrop(object sender, DragEventArgs e)
        {
        }

        private void pictureBox1_DragEnter(object sender, DragEventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string ssn = textBox8.Text;
            string email = textBox4.Text;
            string fname = textBox7.Text;
            string lname = textBox5.Text;
            DateTime dateOfBirth;
            DateTime creationDate = DateTime.Now;
            string gender;

            if (!IsValidEmail(email))
            {
                MessageBox.Show("Invalid email address!");
                return;
            }
            if (!ValidateRomanianSSN(ssn, out dateOfBirth, out gender))
                return;
            if (imageData == null){
                MessageBox.Show("Please provide a profile picture!");
                return;
            }
                DBConnection.conn.Open();

                string insertQuery = "INSERT INTO Users (Email, Account_Creation_Date, Gender, Date_Of_Birth, First_Name, Last_Name, SSN, Profile_Picture ) VALUES (@email, @creationDate, @gender, @dof, @fname, @lname, @ssn, @pfp)";

                using (SqlCommand command = new SqlCommand(insertQuery, DBConnection.conn))
                {
                    command.Parameters.AddWithValue("@email", email);
                    command.Parameters.AddWithValue("@creationDate", creationDate);
                    command.Parameters.AddWithValue("@pfp", imageData);
                    command.Parameters.AddWithValue("@gender", gender);
                    command.Parameters.AddWithValue("@dof", dateOfBirth);
                    command.Parameters.AddWithValue("@fname", fname);
                    command.Parameters.AddWithValue("@lname", lname);
                    command.Parameters.AddWithValue("@ssn", ssn);

                    command.ExecuteNonQuery();
                }
            MessageBox.Show("Success!");
            DBConnection.conn.Close();
            button2_Click(this, EventArgs.Empty);
        }


        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void panel1_DragDrop(object sender, DragEventArgs e)
        {
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            if (files.Length > 0)
            {
                // Load the dropped image file into a Bitmap object
                Bitmap bmp = new Bitmap(files[0]);

                // Display the image in the PictureBox control
                pictureBox1.Image = bmp;

                // Convert the image data to a byte array
                ImageConverter converter = new ImageConverter();
                imageData = (byte[])converter.ConvertTo(bmp, typeof(byte[]));
            }

        }

        private void panel1_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MainMenu mainMenu = new MainMenu(LoginForm.user_name);
            this.Hide();
            mainMenu.Show();
        }
    }
}
