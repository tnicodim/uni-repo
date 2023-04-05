using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MTP_lab4
{
   public class Intrebari
    {
            int nr_intrebare;
            string tip_intrebare;
            string intrebare;
            int nr_variante_rasp;
            string[] variante_rasp;
            string linkPoza;
            string raspuns_corect;
            public int Nr_intrebare { get => nr_intrebare; set => nr_intrebare = value; }
            public string Tip_intrebare { get => tip_intrebare; set => tip_intrebare = value; }
            public string Intrebare { get => intrebare; set => intrebare = value; }
            public int Nr_variante_rasp { get => nr_variante_rasp; set => nr_variante_rasp = value; }
            public string[] Variante_rasp { get => variante_rasp; set => variante_rasp = value; }
            public string LinkPoza { get => linkPoza; set => linkPoza = value; }
            public string Raspuns_corect { get => raspuns_corect; set => raspuns_corect = value; }
            public Intrebari(int nr_intrebare, string tip_intrebare, string intrebare, int
           nr_variante_rasp, string[] variante_rasp, string linkPoza, string raspuns_corect)
            {
                this.Nr_intrebare = nr_intrebare;
                this.Tip_intrebare = tip_intrebare;
                this.Intrebare = intrebare;
                this.Nr_variante_rasp = nr_variante_rasp;
                this.Variante_rasp = variante_rasp;
                this.LinkPoza = linkPoza;
                this.Raspuns_corect = raspuns_corect;
            }
        }

}
