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
        
        public RegisterForm()
        {
            InitializeComponent();
        }

        public byte[] imageData;

        private bool ValidateRomanianSSN(string ssn, out DateTime dateOfBirth, out string gender)
        {
            dateOfBirth = new DateTime();
            gender = "";

            // Check that the SSN is 13 characters long
            if (ssn.Length != 13)
            {
                MessageBox.Show("Invalid SSN: SSN must be 13 characters long.");
                return false;
            }

            // Check that the SSN only contains digits
            if (!ssn.All(char.IsDigit))
            {
                MessageBox.Show("Invalid SSN: SSN must only contain digits.");
                return false;
            }

            // Check that the first digit represents the gender (1,5 for male, 2,6 for female)
            int genderDigit = int.Parse(ssn.Substring(0, 1));
            if (!(genderDigit == 1 || genderDigit == 2 || genderDigit == 5 || genderDigit == 6))
            {
                MessageBox.Show("Invalid SSN: First digit must be 1-2 or 5-6.");
                return false;
            }

            // Check that the next six digits represent a valid date of birth
            string dateOfBirthString = ssn.Substring(1, 6);
            if (!DateTime.TryParseExact(dateOfBirthString, "yyMMdd", null, System.Globalization.DateTimeStyles.None, out dateOfBirth))
            {
                MessageBox.Show("Invalid SSN: Invalid date of birth.");
                return false;
            }

            // Check that the last three digits represent a valid identification number
            int identificationNumber = int.Parse(ssn.Substring(7, 3));
            if (identificationNumber == 0 || identificationNumber > 999)
            {
                MessageBox.Show("Invalid SSN: Invalid identification number.");
                return false;
            }

            // Determine the gender based on the first digit
            if (genderDigit == 1 || genderDigit == 5)
            {
                gender = "Male";
            }
            else if (genderDigit == 2 || genderDigit == 6)
            {
                gender = "Female";
            }

            // If all checks pass, the SSN is valid
            return true;
        }

        public bool IsValidEmail(string email)
        {
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

            if (!IsValidEmail(textBox4.Text))
            {
                MessageBox.Show("Invalid email address!");
                return;
            }
            if (!ValidateRomanianSSN(ssn, out dateOfBirth, out gender))
            {
                MessageBox.Show("Invalid SSN!");
                return;
            }
            if (imageData == null){
                MessageBox.Show("Please provide a profile picture!");
                return;
            }
            // Step 1: Connect to the database
                DBConnection.conn.Open();

                // Step 2: Prepare the SQL statement
                string insertQuery = "INSERT INTO Users (Email, Account_Creation_Date, Gender, Date_Of_Birth, First_Name, Last_Name, SSN, Profile_Picture ) VALUES (@email, @creationDate, @gender, @dof, @fname, @lname, @ssn, @pfp)";

                using (SqlCommand command = new SqlCommand(insertQuery, DBConnection.conn))
                {
                    // Step 3: Set parameter values
                    command.Parameters.AddWithValue("@email", email);
                    command.Parameters.AddWithValue("@creationDate", creationDate);
                    command.Parameters.AddWithValue("@pfp", imageData);
                    command.Parameters.AddWithValue("@gender", gender);
                    command.Parameters.AddWithValue("@dof", dateOfBirth);
                    command.Parameters.AddWithValue("@fname", fname);
                    command.Parameters.AddWithValue("@lname", lname);
                    command.Parameters.AddWithValue("@ssn", ssn);

                    // Step 4: Execute the SQL statement
                    command.ExecuteNonQuery();
                }
            MessageBox.Show("Success!");
            DBConnection.conn.Close();
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
    }
}
