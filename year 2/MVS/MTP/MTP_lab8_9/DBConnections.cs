using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace MTP_lab8_9
{
    public class DBConnections
    {
        public static SqlConnection conn = new SqlConnection("Data Source=WIN-ML823RPOAOR\SQLEXPRESS" + ";InitialCatalog = Firma; Integrated Security = True");
    }
}