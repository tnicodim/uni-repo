
namespace lab3ex1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxMACHEX = new System.Windows.Forms.TextBox();
            this.textBoxMAC = new System.Windows.Forms.TextBox();
            this.textBoxPlain = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.comboBoxMAC = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxKey = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.textBoxHASH = new System.Windows.Forms.TextBox();
            this.textBoxHASHHEX = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.button3 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(275, 204);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(36, 17);
            this.label7.TabIndex = 30;
            this.label7.Text = "HEX";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(271, 173);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(41, 17);
            this.label8.TabIndex = 29;
            this.label8.Text = "ASCII";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(271, 103);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(41, 17);
            this.label5.TabIndex = 28;
            this.label5.Text = "ASCII";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(318, 153);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 17);
            this.label4.TabIndex = 27;
            this.label4.Text = " MAC";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(318, 80);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(66, 17);
            this.label3.TabIndex = 26;
            this.label3.Text = "PlainText";
            // 
            // textBoxMACHEX
            // 
            this.textBoxMACHEX.Enabled = false;
            this.textBoxMACHEX.Location = new System.Drawing.Point(317, 201);
            this.textBoxMACHEX.Name = "textBoxMACHEX";
            this.textBoxMACHEX.Size = new System.Drawing.Size(251, 22);
            this.textBoxMACHEX.TabIndex = 25;
            // 
            // textBoxMAC
            // 
            this.textBoxMAC.Enabled = false;
            this.textBoxMAC.Location = new System.Drawing.Point(318, 173);
            this.textBoxMAC.Name = "textBoxMAC";
            this.textBoxMAC.Size = new System.Drawing.Size(251, 22);
            this.textBoxMAC.TabIndex = 24;
            // 
            // textBoxPlain
            // 
            this.textBoxPlain.Location = new System.Drawing.Point(318, 100);
            this.textBoxPlain.Name = "textBoxPlain";
            this.textBoxPlain.Size = new System.Drawing.Size(251, 22);
            this.textBoxPlain.TabIndex = 23;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(46, 197);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(170, 33);
            this.button2.TabIndex = 22;
            this.button2.Text = " Verify MAC";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(46, 132);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(170, 33);
            this.button1.TabIndex = 21;
            this.button1.Text = " Compute MAC";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // comboBoxMAC
            // 
            this.comboBoxMAC.FormattingEnabled = true;
            this.comboBoxMAC.Items.AddRange(new object[] {
            "SHA1",
            "MD5",
            "RIPEMD",
            "SHA256",
            "SHA384",
            "SHA512"});
            this.comboBoxMAC.Location = new System.Drawing.Point(46, 69);
            this.comboBoxMAC.Name = "comboBoxMAC";
            this.comboBoxMAC.Size = new System.Drawing.Size(170, 24);
            this.comboBoxMAC.TabIndex = 20;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(271, 39);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 17);
            this.label1.TabIndex = 33;
            this.label1.Text = "ASCII";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(318, 16);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(36, 17);
            this.label2.TabIndex = 32;
            this.label2.Text = " Key";
            // 
            // textBoxKey
            // 
            this.textBoxKey.Location = new System.Drawing.Point(318, 36);
            this.textBoxKey.Name = "textBoxKey";
            this.textBoxKey.Size = new System.Drawing.Size(251, 22);
            this.textBoxKey.TabIndex = 31;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(318, 248);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(45, 17);
            this.label10.TabIndex = 36;
            this.label10.Text = " Hash";
            // 
            // textBoxHASH
            // 
            this.textBoxHASH.Enabled = false;
            this.textBoxHASH.Location = new System.Drawing.Point(318, 268);
            this.textBoxHASH.Name = "textBoxHASH";
            this.textBoxHASH.Size = new System.Drawing.Size(251, 22);
            this.textBoxHASH.TabIndex = 34;
            // 
            // textBoxHASHHEX
            // 
            this.textBoxHASHHEX.Enabled = false;
            this.textBoxHASHHEX.Location = new System.Drawing.Point(318, 296);
            this.textBoxHASHHEX.Name = "textBoxHASHHEX";
            this.textBoxHASHHEX.Size = new System.Drawing.Size(251, 22);
            this.textBoxHASHHEX.TabIndex = 35;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(276, 299);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(36, 17);
            this.label6.TabIndex = 38;
            this.label6.Text = "HEX";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(271, 268);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(41, 17);
            this.label9.TabIndex = 37;
            this.label9.Text = "ASCII";
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(46, 260);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(170, 33);
            this.button3.TabIndex = 39;
            this.button3.Text = " Compute HASH";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(677, 355);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.textBoxHASHHEX);
            this.Controls.Add(this.textBoxHASH);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBoxKey);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxMACHEX);
            this.Controls.Add(this.textBoxMAC);
            this.Controls.Add(this.textBoxPlain);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.comboBoxMAC);
            this.Name = "Form1";
            this.Text = "MAC Test";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxMACHEX;
        private System.Windows.Forms.TextBox textBoxMAC;
        private System.Windows.Forms.TextBox textBoxPlain;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ComboBox comboBoxMAC;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxKey;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox textBoxHASH;
        private System.Windows.Forms.TextBox textBoxHASHHEX;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button button3;
    }
}

