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
    public partial class RegisterForm : Form
    {
        byte[] imageData;
        public RegisterForm()
        {
            InitializeComponent();
        }

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

            // Check that the first digit represents the gender (1-2 for male, 3-4 for female)
            int genderDigit = int.Parse(ssn.Substring(0, 1));
            if (genderDigit < 1 || genderDigit > 4)
            {
                MessageBox.Show("Invalid SSN: First digit must be 1-4.");
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
            if (genderDigit == 1 || genderDigit == 2)
            {
                gender = "Male";
            }
            else if (genderDigit == 3 || genderDigit == 4)
            {
                gender = "Female";
            }

            // If all checks pass, the SSN is valid
            return true;
        }


        private void pictureBox1_DragDrop(object sender, DragEventArgs e)
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

            private void pictureBox1_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string ssn = textBox8.Text;
            DateTime dateOfBirth;
            string gender;

            if (ValidateRomanianSSN(ssn, out dateOfBirth, out gender))
            {
                // The SSN is valid, use the date of birth and gender as needed
                MessageBox.Show($"Date of birth: {dateOfBirth:dd/MM/yyyy}\nGender: {gender}");
            }
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
                byte[] imageData = (byte[])converter.ConvertTo(bmp, typeof(byte[]));
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
