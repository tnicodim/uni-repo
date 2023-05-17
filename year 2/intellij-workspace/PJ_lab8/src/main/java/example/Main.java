package example;

import java.sql.*;

public class Main {
    public static void main(String[] args) throws SQLException {
        String url = "jdbc:mysql://localhost:3306/test";
        String sql = "select * from persoane";
        Connection connection= DriverManager.getConnection(url, "root", "whiteeagle441");
        Statement statement = connection.createStatement();
        ResultSet rs = statement.executeQuery(sql);
        while (rs.next())
            System.out.println("id=" + rs.getInt("id") + ", nume= " + rs.getString("nume") + ",varsta=" + rs.getInt("varsta"));
        connection.close();
        statement.close();
        rs.close();
    }
}