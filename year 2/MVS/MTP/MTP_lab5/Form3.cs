using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MTP_lab5
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        public static bool verificCNP(string cnp)
        {
            int s, a1, a2, l1, l2, z1, z2, j1, j2, n1, n2, n3, cifc, u;
            if (cnp.Trim().Length != 13)
                return false;
            else
            {
                s =  Convert.ToInt16(cnp.Substring(0, 1));
                a1 = Convert.ToInt16(cnp.Substring(1, 1));
                a2 = Convert.ToInt16(cnp.Substring(2, 1));
                l1 = Convert.ToInt16(cnp.Substring(3, 1));
                l2 = Convert.ToInt16(cnp.Substring(4, 1));
                z1 = Convert.ToInt16(cnp.Substring(5, 1));
                z2 = Convert.ToInt16(cnp.Substring(6, 1));
                j1 = Convert.ToInt16(cnp.Substring(7, 1));
                j2 = Convert.ToInt16(cnp.Substring(8, 1));
                n1 = Convert.ToInt16(cnp.Substring(9, 1));
                n2 = Convert.ToInt16(cnp.Substring(10, 1));
                n3 = Convert.ToInt16(cnp.Substring(11, 1));
                cifc = Convert.ToInt16(((s * 2 + a1 * 7 + a2 * 9 + l1 * 1 + l2 * 4 + z1 * 6 + z2 * 3 + j1 * 5 + j2 * 8 + n1 * 2 + n2 * 7 + n3 * 9) % 11));
                if (cifc == 10)
                {
                    cifc = 1;
                }
                u = Convert.ToInt16(cnp.Substring(12, 1));
                if (cifc == u)
                    return true;
                else
                    return false;
            }
        }

        private void textBox1_Leave(object sender, EventArgs e)
        {
            string cnp = textBox1.Text;
            if (verificCNP(cnp) == false)
            {
                MessageBox.Show("ERROR!");
            }
            else
            {
                MessageBox.Show("SUCCESS!");
                DateTime date = Convert.ToDateTime(cnp.Substring(5, 2) + "/" + cnp.Substring(3, 2) + "/20" + cnp.Substring(1, 2));
                dateTimePicker1.Value = Convert.ToDateTime(cnp.Substring(5, 2) + "/" + cnp.Substring(3, 2) + "/20" + cnp.Substring(1, 2));
                textBox10.Text = (DateTime.Now.Year - date.Year).ToString();

            }
        }
    }
}
