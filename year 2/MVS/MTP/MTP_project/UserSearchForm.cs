using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace MTP_project
{
    public partial class UserSearchForm : Form
    {
        private string connectionString = @"Data Source=WIN-ML823RPOAOR\SQLEXPRESS;Initial Catalog=Library;Integrated Security=True"; // Replace with your actual connection string

        public UserSearchForm()
        {
            InitializeComponent();
        }

        private void searchButton_Click_1(object sender, EventArgs e)
        {
            string firstName = firstNameTextBox.Text.Trim();
            string lastName = lastNameTextBox.Text.Trim();

            if (string.IsNullOrEmpty(firstName) || string.IsNullOrEmpty(lastName))
            {
                MessageBox.Show("Please enter both first name and last name.");
                return;
            }

            List<User> users = SearchUsers(firstName, lastName);

            if (users.Count > 0)
            {
                DisplayUserDetails(users);
            }
            else
            {
                MessageBox.Show("User not found.");
                ClearUserDetails();
            }
        }

        private List<User> SearchUsers(string firstName, string lastName)
        {
            List<User> users = new List<User>();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                string query = "SELECT * FROM Users WHERE first_name = @FirstName AND last_name = @LastName";

                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@FirstName", firstName);
                    command.Parameters.AddWithValue("@LastName", lastName);

                    try
                    {
                        connection.Open();
                        SqlDataReader reader = command.ExecuteReader();

                        while (reader.Read())
                        {
                            User user = new User
                            {
                                First_Name = reader["first_name"].ToString(),
                                Last_Name = reader["last_name"].ToString(),
                                Email = reader["email"].ToString(),
                                Account_Creation_Date = Convert.ToDateTime(reader["account_creation_date"]),
                                Gender = reader["gender"].ToString(),
                                Date_Of_Birth = Convert.ToDateTime(reader["date_of_birth"]),
                                Borrow_Date_Start = reader["borrow_date_start"] == DBNull.Value ? null : (DateTime?)reader["borrow_date_start"],
                                Borrow_Date_End = reader["borrow_date_end"] == DBNull.Value ? null : (DateTime?)reader["borrow_date_end"],
                                SSN = reader["ssn"].ToString(),
                                Profile_Picture = reader["profile_picture"] == DBNull.Value ? null : (byte[])reader["profile_picture"]
                            };

                            users.Add(user);
                        }

                        reader.Close();
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("An error occurred: " + ex.Message);
                    }
                }
            }

            return users;
        }

        private void DisplayUserDetails(List<User> users)
        {
            User user = users[0]; // Assuming we only display details of the first matching user

            // Remove existing controls
            ClearUserDetails();

            int labelLeftColumn1 = 20;
            int valueLeftColumn1 = 180;
            int labelLeftColumn2 = 400;
            int valueLeftColumn2 = 560;
            int top = 20;
            int spacing = 30;

            // Create and position labels and values dynamically for the first column
            int propertyCount = 0;
            foreach (var property in typeof(User).GetProperties())
            {
                if (property.Name == "Account_Creation_Date" || property.Name == "Borrow_Date_Start" || property.Name == "Borrow_Date_End" || property.Name == "Profile_Picture")
                    continue;

                Label label = new Label();
                label.Text = property.Name.Replace("_", " ");
                label.AutoSize = true;
                label.Font = new Font(label.Font, FontStyle.Bold);
                label.Left = labelLeftColumn1;
                label.Top = top;

                Control propertyValueControl;

                if (property.PropertyType == typeof(byte[]))
                {
                    // Special case for profile picture
                    PictureBox pictureBox = new PictureBox();
                    pictureBox.Width = 200;
                    pictureBox.Height = 200;
                    pictureBox.SizeMode = PictureBoxSizeMode.Zoom;
                    propertyValueControl = pictureBox;
                }
                else
                {
                    Label propertyValueLabel = new Label();
                    propertyValueLabel.AutoSize = true;
                    propertyValueControl = propertyValueLabel;
                }

                propertyValueControl.Left = valueLeftColumn1;
                propertyValueControl.Top = top;

                // Set the value
                object propertyValue = property.GetValue(user);
                if (propertyValue != null)
                {
                    if (propertyValueControl is Label propertyValueLabel)
                    {
                        if (property.Name == "Date_Of_Birth")
                        {
                            propertyValueLabel.Text = ((DateTime)propertyValue).ToShortDateString();
                        }
                        else
                        {
                            propertyValueLabel.Text = propertyValue.ToString();
                        }
                    }
                    else if (propertyValueControl is PictureBox pictureBox)
                    {
                        byte[] imageBytes = (byte[])propertyValue;
                        using (MemoryStream ms = new MemoryStream(imageBytes))
                        {
                            pictureBox.Image = Image.FromStream(ms);
                        }
                    }
                }

                // Add the controls to the form
                Controls.Add(label);
                Controls.Add(propertyValueControl);

                propertyCount++;
                top += spacing; // Increase the top position for the next row
            }

            top = 20; // Reset top position for the second column

            // Create and position labels and values dynamically for the second column
            foreach (var property in typeof(User).GetProperties())
            {
                if (property.Name == "First_Name" || property.Name == "Last_Name" || property.Name == "Email" || property.Name == "Gender" || property.Name == "SSN" || property.Name == "Date_Of_Birth")
                    continue;

                Label label = new Label();
                label.Text = property.Name.Replace("_", " ");
                label.AutoSize = true;
                label.Font = new Font(label.Font, FontStyle.Bold);
                label.Left = labelLeftColumn2;
                label.Top = top;

                Control propertyValueControl;

                if (property.PropertyType == typeof(byte[]))
                {
                    // Special case for profile picture
                    PictureBox pictureBox = new PictureBox();
                    pictureBox.Width = 200;
                    pictureBox.Height = 200;
                    pictureBox.SizeMode = PictureBoxSizeMode.Zoom;
                    propertyValueControl = pictureBox;

                    // Position the picture box right below the label
                    pictureBox.Left = label.Left;
                    pictureBox.Top = 100;
                }
                else
                {
                    Label propertyValueLabel = new Label();
                    propertyValueLabel.AutoSize = true;
                    propertyValueControl = propertyValueLabel;
                }
                if (!(propertyValueControl is PictureBox)) { 
                propertyValueControl.Left = valueLeftColumn2;
                propertyValueControl.Top = top;
                }
                // Set the value
                object propertyValue = property.GetValue(user);
                if (propertyValue != null)
                {
                    if (propertyValueControl is Label propertyValueLabel)
                    {
                        if (property.Name == "Account_Creation_Date" || property.Name == "Borrow_Date_Start" || property.Name == "Borrow_Date_End")
                        {
                            propertyValueLabel.Text = ((DateTime)propertyValue).ToShortDateString();
                        }
                        else
                        {
                            propertyValueLabel.Text = propertyValue.ToString();
                        }
                    }
                    else if (propertyValueControl is PictureBox pictureBox)
                    {
                        byte[] imageBytes = (byte[])propertyValue;
                        using (MemoryStream ms = new MemoryStream(imageBytes))
                        {
                            pictureBox.Image = Image.FromStream(ms);
                        }
                    }
                }

                this.Height = 340;
                // Add the controls to the form
                Controls.Add(label);
                Controls.Add(propertyValueControl);

                propertyCount++;
                top += spacing; // Increase the top position for the next row
            }
        }

            private void ClearUserDetails()
        {
            Controls.Clear();
        }
    }
}

