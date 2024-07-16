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
        private string firstName;
        private string lastName;
        private const int WM_NCHITTEST = 0x84;
        private const int HTCLIENT = 0x1;
        private const int HTCAPTION = 0x2;
        protected override void WndProc(ref Message message)
        {
            base.WndProc(ref message);

            if (message.Msg == WM_NCHITTEST && (int)message.Result == HTCLIENT)
                message.Result = (IntPtr)HTCAPTION;
        }
        public UserSearchForm()
        {
            InitializeComponent();
            this.ControlBox = false;
            this.Text = String.Empty;
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        private void searchButton_Click_1(object sender, EventArgs e)
        {
            firstName = firstNameTextBox.Text.Trim();
            lastName = lastNameTextBox.Text.Trim();

            if (string.IsNullOrEmpty(firstName) || string.IsNullOrEmpty(lastName))
            {
                MessageBox.Show("Please enter both first name and last name.");
                return;
            }
            timer1.Start();
        }

        private List<User> SearchUsers()
        {
            List<User> users = new List<User>();

            string query = "SELECT * FROM Users WHERE first_name = @FirstName AND last_name = @LastName";
            SqlCommand command = new SqlCommand(query, DBConnection.conn);
            command.Parameters.AddWithValue("@FirstName", firstName);
            command.Parameters.AddWithValue("@LastName", lastName);

            try
            {
                DBConnection.conn.Open();
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
                DBConnection.conn.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }

            return users;
        }

        private void DisplayUserDetails(List<User> users)
        {
            User user = users[0];

            ClearUserDetails();

            Button backButton = new Button();
            backButton.Text = "Back";
            backButton.Size = new Size(80, 30);
            backButton.Location = new Point(20, 250);
            backButton.Click += (sender, e) =>
            {
                MainMenu mainMenu = new MainMenu(LoginForm.user_name);
                this.Hide();
                mainMenu.Show();
            };
            Button deleteButton = new Button();
            deleteButton.Text = "Delete";
            deleteButton.Size = new Size(80, 30);
            deleteButton.Location = new Point(130, 250);
            deleteButton.Click += (sender, e) =>
            {
                string query = "DELETE FROM users WHERE email = @email";
                try
                {
                    SqlCommand command = new SqlCommand(query, DBConnection.conn);
                    command.Parameters.AddWithValue("@email", user.Email);
                    DBConnection.conn.Open();
                    command.ExecuteNonQuery();
                    MessageBox.Show("User deleted!");
                    DBConnection.conn.Close();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("An error occurred: " + ex.Message);
                }
                this.Hide();
                UserSearchForm searchForm = new UserSearchForm();
                searchForm.Show();
            };
            Controls.Add(deleteButton);
            Controls.Add(backButton);


            int labelLeftColumn1 = 20;
            int valueLeftColumn1 = 180;
            int labelLeftColumn2 = 400;
            int valueLeftColumn2 = 560;
            int top = 20;
            int spacing = 30;

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

                Label propertyValueLabel1 = new Label();
                propertyValueLabel1.AutoSize = true;
                propertyValueControl = propertyValueLabel1;

                propertyValueControl.Left = valueLeftColumn1;
                propertyValueControl.Top = top;

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

                }

                Controls.Add(label);
                Controls.Add(propertyValueControl);

                propertyCount++;
                top += spacing;
            }

            top = 20;

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
                    PictureBox pictureBox = new PictureBox();
                    pictureBox.Width = 150;
                    pictureBox.Height = 150;
                    pictureBox.SizeMode = PictureBoxSizeMode.Zoom;
                    propertyValueControl = pictureBox;

                    pictureBox.Left = label.Left;
                    pictureBox.Top = label.Bottom;
                }
                else
                {
                    Label propertyValueLabel = new Label();
                    propertyValueLabel.AutoSize = true;
                    propertyValueControl = propertyValueLabel;
                }
                if (!(propertyValueControl is PictureBox))
                {
                    propertyValueControl.Left = valueLeftColumn2;
                    propertyValueControl.Top = top;
                }
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


                Controls.Add(label);
                Controls.Add(propertyValueControl);

                propertyCount++;
                top += spacing;
            }
        }
        private void ClearUserDetails()
        {
            Controls.Clear();
        }

        private void UserSearchForm_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            MainMenu mainMenu = new MainMenu(LoginForm.user_name);
            this.Hide();
            mainMenu.Show();
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            progressBar1.Value += 10;
            progressBar1.Value -= 1;
            progressBar1.Value += 1;
            if (progressBar1.Value == progressBar1.Maximum)
            {
                timer1.Stop();

                List<User> users = SearchUsers();

                if (users.Count > 0)
                {
                    this.Size = new Size(700, 300);
                    DisplayUserDetails(users);
                }
                else
                {
                    MessageBox.Show("User not found.");
                    progressBar1.Value = 0;
                }
            }
        }
    }
}

