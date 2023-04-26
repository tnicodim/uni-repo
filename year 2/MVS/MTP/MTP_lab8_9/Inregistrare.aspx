<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Inregistrare.aspx.cs" Inherits="MTP_lab8_9.Inregistrare" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style3 {
            text-align: center;
        }
        .auto-style4 {
            height: 31px;
            text-align: right;
            width: 492px;
        }
        .auto-style5 {
            text-align: right;
            height: 33px;
            width: 492px;
        }
        .auto-style6 {
            height: 33px;
            text-align: left;
        }
        .auto-style7 {
            text-align: center;
            height: 31px;
        }
        .auto-style8 {
            text-align: left;
            height: 31px;
        }
        .auto-style9 {
            width: 492px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        </div>
        <table class="auto-style1">
            <tr>
                <td class="auto-style3" colspan="2">Inregistrare</td>
            </tr>
            <tr>
                <td class="auto-style7" colspan="2"></td>
            </tr>
            <tr>
                <td class="auto-style4">Utilizator</td>
                <td class="auto-style8">
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style5">Parola</td>
                <td class="auto-style6">
                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style9">&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style9">&nbsp;</td>
                <td>
                    <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Inregistrare" Width="187px" />
                </td>
            </tr>
        </table>
    </form>
</body>
</html>
