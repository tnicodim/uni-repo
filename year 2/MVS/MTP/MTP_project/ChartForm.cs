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
using System.Windows.Forms.DataVisualization.Charting;
using ScottPlot;

namespace MTP_project
{
    public partial class ChartForm : Form
    {
        private const int WM_NCHITTEST = 0x84;
        private const int HTCLIENT = 0x1;
        private const int HTCAPTION = 0x2;
        private FormsPlot formsPlot1 = new FormsPlot();
        protected override void WndProc(ref Message message)
        {
            base.WndProc(ref message);

            if (message.Msg == WM_NCHITTEST && (int)message.Result == HTCLIENT)
                message.Result = (IntPtr)HTCAPTION;
        }
        public ChartForm()
        {
            InitializeComponent();
            this.ControlBox = false;
            this.Text = String.Empty;
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            GenerateBookBorrowingPlot(formsPlot1, 30);
        }

        private void GenerateBookBorrowingPlot(FormsPlot formsPlot, int range)
        {
            try
            {
                DBConnection.conn.Open();

                // Calculate the start and end dates for the past 30 days
                DateTime startDate = DateTime.Now.AddDays(-range);
                DateTime endDate = DateTime.Now;

                string query = "SELECT " +
                               "DATEADD(WEEK, DATEDIFF(WEEK, 0, borrow_date), 0) AS WeekStart, " +
                               "DATEADD(WEEK, DATEDIFF(WEEK, 0, borrow_date) + 1, -1) AS WeekEnd, " +
                               "COUNT(*) AS BookCount " +
                               "FROM History " +
                               "WHERE borrow_date >= @StartDate AND borrow_date <= @EndDate " +
                               "GROUP BY DATEADD(WEEK, DATEDIFF(WEEK, 0, borrow_date), 0), DATEADD(WEEK, DATEDIFF(WEEK, 0, borrow_date) + 1, -1) " +
                               "ORDER BY DATEADD(WEEK, DATEDIFF(WEEK, 0, borrow_date), 0)";

                SqlCommand command = new SqlCommand(query, DBConnection.conn);
                command.Parameters.AddWithValue("@StartDate", startDate);
                command.Parameters.AddWithValue("@EndDate", endDate);
                SqlDataReader reader = command.ExecuteReader();

                List<DateTime> weekStarts = new List<DateTime>();
                List<DateTime> weekEnds = new List<DateTime>();
                List<double> bookCounts = new List<double>();

                while (reader.Read())
                {
                    DateTime weekStart = reader.GetDateTime(0);
                    DateTime weekEnd = reader.GetDateTime(1);
                    double bookCount = Convert.ToDouble(reader.GetValue(2));

                    weekStarts.Add(weekStart);
                    weekEnds.Add(weekEnd);
                    bookCounts.Add(bookCount);
                }

                reader.Close();
                DBConnection.conn.Close();

                formsPlot.Plot.Clear();
                formsPlot.Plot.Title("Number of Books Borrowed Each Week");
                formsPlot.Plot.YLabel("Book Count");
                formsPlot.Plot.XLabel("Week Range");

                double[] xs = weekStarts.Select(x => x.ToOADate()).ToArray();
                double[] ys = bookCounts.ToArray();

                formsPlot.Plot.AddScatter(xs, ys);

                formsPlot.Plot.XAxis.DateTimeFormat(true);

                formsPlot.Render();
                Controls.Add(formsPlot1);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }



        private void ChartForm_Load(object sender, EventArgs e)
        {

        }

        private void GenerateBorrowedBooksBarChart(FormsPlot formsPlot)
        {
            try
            {
                DBConnection.conn.Open();

                string query = "SELECT book, COUNT(*) AS BorrowCount FROM History GROUP BY book";

                SqlCommand command = new SqlCommand(query, DBConnection.conn);
                SqlDataReader reader = command.ExecuteReader();

                List<string> bookNames = new List<string>();
                List<double> borrowCounts = new List<double>();

                while (reader.Read())
                {
                    string bookName = reader.GetString(0);
                    double borrowCount = Convert.ToDouble(reader.GetValue(1));

                    bookNames.Add(bookName);
                    borrowCounts.Add(borrowCount);
                }

                reader.Close();
                DBConnection.conn.Close();

                formsPlot.Plot.AddBar(borrowCounts.ToArray(), Enumerable.Range(0, bookNames.Count).Select(Convert.ToDouble).ToArray());
                formsPlot.Plot.XTicks(Enumerable.Range(0, bookNames.Count).Select(Convert.ToDouble).ToArray(), bookNames.ToArray());
                formsPlot.Plot.SetAxisLimits(yMin: 0);

                formsPlot.Plot.Title("Borrowed Books");
                formsPlot.Plot.YLabel("Borrow Count");
                formsPlot.Plot.XLabel("Book");

                formsPlot.Render();
                Controls.Add(formsPlot1);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }


        private void button3_Click(object sender, EventArgs e)
        {
            formsPlot1.Plot.Clear();
            formsPlot1.Refresh();
            GenerateBookBorrowingPlot(formsPlot1, 90);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            formsPlot1.Plot.Clear();
            formsPlot1.Refresh();
            GenerateBookBorrowingPlot(formsPlot1, 30);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            formsPlot1.Plot.Clear();
            formsPlot1.Refresh();
            GenerateBookBorrowingPlot(formsPlot1, 720);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            formsPlot1.Plot.Clear();
            formsPlot1.Refresh();
            GenerateBorrowedBooksBarChart(formsPlot1);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            MainMenu mainMenu = new MainMenu(LoginForm.user_name);
            this.Hide();
            mainMenu.Show();
        }
    }
}
