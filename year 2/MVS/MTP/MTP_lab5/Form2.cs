using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;


namespace MTP_lab5
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            string connect = @"Data Source=WIN-ML823RPOAOR\SQLEXPRESS;Initial Catalog=Pediatrie;Integrated Security=True";
            SqlConnection cnn = new SqlConnection(connect);
            cnn.Open();
            string tabel_date = "select * from Pacienti";
            SqlDataAdapter da = new SqlDataAdapter(tabel_date, connect);
            DataSet ds = new DataSet();
            da.Fill(ds, "Pacienti");
            dataGridView1.DataSource = ds.Tables["Pacienti"].DefaultView;
            cnn.Close();
        }

        private void cautaNumeBTN_Click(object sender, EventArgs e)
        {
            string connect = @"Data Source=WIN-ML823RPOAOR\SQLEXPRESS;Initial Catalog=Pediatrie;Integrated Security=True";
            SqlConnection con = new SqlConnection(connect);
            con.Open();
            string stmt = "select * from pacienti where nume='" + cautaNumeTB.Text + "'";
            SqlDataAdapter da = new SqlDataAdapter(stmt, con);
            DataSet ds = new DataSet();
            da.Fill(ds, "Pacienti");
            dataGridView1.DataSource = ds.Tables["Pacienti"].DefaultView;
            con.Close();
            da.Dispose();
            ds.Dispose();
    }

        private void button5_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form3 f = new Form3();
            f.ShowDialog();
        }
    }
}
