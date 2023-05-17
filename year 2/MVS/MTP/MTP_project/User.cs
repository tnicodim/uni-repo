using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MTP_project
{
    public class User
    {
        public string First_Name { get; set; }
        public string Last_Name { get; set; }
        public string Email { get; set; }
        public DateTime Account_Creation_Date { get; set; }
        public string Gender { get; set; }
        public DateTime Date_Of_Birth { get; set; }
        public DateTime? Borrow_Date_Start { get; set; }
        public DateTime? Borrow_Date_End { get; set; }
        public string SSN { get; set; }
        public byte[] Profile_Picture { get; set; }
    }
}
