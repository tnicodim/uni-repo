using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MTP_project
{
    class DBConnection
    {
        public static SqlConnection conn = new SqlConnection(@"Data Source=WIN-ML823RPOAOR\SQLEXPRESS;Initial Catalog=Library;Integrated Security=True");
    }
}
