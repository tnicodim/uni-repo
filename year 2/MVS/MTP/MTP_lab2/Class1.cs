using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MTP_lab2
{
    class Person
    {
        string cnp;
        string name;
        string address;
        public Person(string cnp, string name, string address)
        {
            this.Cnp = cnp;
            this.Name = name;
            this.Address = address;
        }
        public string Cnp { get => cnp; set => cnp = value; }
        public string Name { get => name; set => name = value; }
        public string Address { get => address; set => address = value; }
    }
}
