using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MTP_lab4
{
   
    public partial class Form2 : Form
    {
        string num, tst;
        public Form2(string nume, string test)
        {
            num = nume;
            tst = test;
            InitializeComponent();
        }
        List<Intrebari> TestGila = new List<Intrebari>();
        public int total_intrebari;
        public int punctaj = 0;
        public int intrebare_curenta = 0;

        private void Incarca_variante_raspuns(int x)
        {
            flowLayoutPanel1.Controls.Clear();
            flowLayoutPanel1.FlowDirection = FlowDirection.TopDown;
            if (TestGila[x].Tip_intrebare == "multiple")
            {
                for (int i = 0; i < TestGila[x].Nr_variante_rasp; i++)
                {
                    CheckBox ck = new CheckBox();
                    ck.Text = TestGila[x].Variante_rasp[i];
                    ck.Name = "ck" + (i + 1).ToString();
                    flowLayoutPanel1.Controls.Add(ck);
                }
            }
            else if (TestGila[x].Tip_intrebare == "single")
            {
                for (int i = 0; i < TestGila[x].Nr_variante_rasp; i++)
                {
                    RadioButton rb = new RadioButton();
                    rb.Text = TestGila[x].Variante_rasp[i];
                    rb.Name = "rb" + (i + 1).ToString();
                    flowLayoutPanel1.Controls.Add(rb);
                }
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string[] raspunsuri_corect = textBox3.Text.Split(',');
            int nr_variante = flowLayoutPanel1.Controls.Count;
            for (int i = 1; i <= nr_variante; i++)
            {
                if (flowLayoutPanel1.Controls[i - 1].Name.Contains("ck"))
                {
                    CheckBox ck = (CheckBox)flowLayoutPanel1.Controls[i - 1];
                    if (ck.Checked == true && raspunsuri_corect.Contains(i.ToString()))
                        punctaj++;
                }
                else
                {
                    RadioButton rb = (RadioButton)flowLayoutPanel1.Controls[i - 1];
                    if (rb.Checked == true && raspunsuri_corect.Contains(i.ToString()))
                        punctaj++;
                }
            }
            textBox4.Text = punctaj.ToString();
            if (intrebare_curenta < total_intrebari - 1)
            {
                intrebare_curenta++;
                label4.Text = TestGila[intrebare_curenta].Intrebare;
                Incarca_variante_raspuns(intrebare_curenta);
                string link = TestGila[intrebare_curenta].LinkPoza;
                if (!link.Equals("0"))
                    pictureBox1.Image = Image.FromFile(link);
                textBox3.Text = TestGila[0].Raspuns_corect;
            }
            else
            {
                MessageBox.Show("Testul s-a incheiat");
                button1.Enabled = false;
            }
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            textBox1.Text = num;
            string line;
            int nr_intrebare;
            string tip_intrebare;
            string intrebare;
            int nr_variante_rasp;
            string[] variante_rasp;
            string linkPoza;
            string raspuns_corect;
            // Citeste fișierul linie cu linie
            System.IO.StreamReader file = new System.IO.StreamReader( tst + ".txt");
            while ((line = file.ReadLine()) != null)
            {
                //citim cate o intrebare cu variante de raspuns
                //numar intrebare
                nr_intrebare = Convert.ToInt16(line);

                //tip intrebare
                line = file.ReadLine();
                tip_intrebare = line;

                //text intrebare
                line = file.ReadLine();
                intrebare = line;
                //numar variante de raspuns
                line = file.ReadLine();
                nr_variante_rasp = Convert.ToByte(line);
                //variante de raspuns
                variante_rasp = new string[nr_variante_rasp];
                for (int i = 0; i < nr_variante_rasp; i++)
                {
                    //var i
                    line = file.ReadLine();
                    variante_rasp[i] = line;
                }
                //link
                line = file.ReadLine();
                linkPoza = line;
                //raspuns corect
                line = file.ReadLine();
                raspuns_corect = line;
                //spatiu
                line = file.ReadLine();
                //adaug intrebarea in lista de intrebari
                Intrebari intreb = new Intrebari(nr_intrebare, tip_intrebare, intrebare,
               nr_variante_rasp, variante_rasp, linkPoza, raspuns_corect);
                TestGila.Add(intreb);
            }
            file.Close();
            total_intrebari = TestGila.Count;
            textBox2.Text = total_intrebari.ToString();
            label4.Text = TestGila[0].Intrebare;
            Incarca_variante_raspuns(0);

            string link = TestGila[0].LinkPoza;
            if (!link.Equals("0"))
                pictureBox1.Image = Image.FromFile(link);
            textBox3.Text = TestGila[0].Raspuns_corect;
        }
    }
}
