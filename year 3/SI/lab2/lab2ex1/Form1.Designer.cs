
namespace lab2ex1
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
            this.comboBoxCipher = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.textBoxKey = new System.Windows.Forms.TextBox();
            this.textBoxIV = new System.Windows.Forms.TextBox();
            this.textBoxPlain = new System.Windows.Forms.TextBox();
            this.textBoxPlainHex = new System.Windows.Forms.TextBox();
            this.textBoxCipher = new System.Windows.Forms.TextBox();
            this.textBoxCipherHex = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.labelEncTimeDef = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.labelEncTime = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // comboBoxCipher
            // 
            this.comboBoxCipher.FormattingEnabled = true;
            this.comboBoxCipher.Items.AddRange(new object[] {
            "DES",
            "3DES",
            "Rijndael"});
            this.comboBoxCipher.Location = new System.Drawing.Point(54, 32);
            this.comboBoxCipher.Name = "comboBoxCipher";
            this.comboBoxCipher.Size = new System.Drawing.Size(170, 24);
            this.comboBoxCipher.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(54, 79);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(170, 33);
            this.button1.TabIndex = 1;
            this.button1.Text = " Generate Key and IV";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(54, 185);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(170, 33);
            this.button2.TabIndex = 2;
            this.button2.Text = "Encrypt";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(54, 307);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(170, 33);
            this.button3.TabIndex = 4;
            this.button3.Text = "Decrypt";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(54, 394);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(170, 33);
            this.button4.TabIndex = 3;
            this.button4.Text = "Get Encrypt Time";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(54, 458);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(170, 33);
            this.button5.TabIndex = 5;
            this.button5.Text = "Get Decrypt Time";
            this.button5.UseVisualStyleBackColor = true;
            // 
            // textBoxKey
            // 
            this.textBoxKey.Location = new System.Drawing.Point(324, 34);
            this.textBoxKey.Name = "textBoxKey";
            this.textBoxKey.Size = new System.Drawing.Size(251, 22);
            this.textBoxKey.TabIndex = 6;
            // 
            // textBoxIV
            // 
            this.textBoxIV.Location = new System.Drawing.Point(324, 84);
            this.textBoxIV.Name = "textBoxIV";
            this.textBoxIV.Size = new System.Drawing.Size(251, 22);
            this.textBoxIV.TabIndex = 7;
            // 
            // textBoxPlain
            // 
            this.textBoxPlain.Location = new System.Drawing.Point(324, 160);
            this.textBoxPlain.Name = "textBoxPlain";
            this.textBoxPlain.Size = new System.Drawing.Size(251, 22);
            this.textBoxPlain.TabIndex = 8;
            // 
            // textBoxPlainHex
            // 
            this.textBoxPlainHex.Enabled = false;
            this.textBoxPlainHex.Location = new System.Drawing.Point(324, 212);
            this.textBoxPlainHex.Name = "textBoxPlainHex";
            this.textBoxPlainHex.Size = new System.Drawing.Size(251, 22);
            this.textBoxPlainHex.TabIndex = 9;
            // 
            // textBoxCipher
            // 
            this.textBoxCipher.Enabled = false;
            this.textBoxCipher.Location = new System.Drawing.Point(324, 288);
            this.textBoxCipher.Name = "textBoxCipher";
            this.textBoxCipher.Size = new System.Drawing.Size(251, 22);
            this.textBoxCipher.TabIndex = 10;
            // 
            // textBoxCipherHex
            // 
            this.textBoxCipherHex.Enabled = false;
            this.textBoxCipherHex.Location = new System.Drawing.Point(324, 337);
            this.textBoxCipherHex.Name = "textBoxCipherHex";
            this.textBoxCipherHex.Size = new System.Drawing.Size(251, 22);
            this.textBoxCipherHex.TabIndex = 11;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(324, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(32, 17);
            this.label1.TabIndex = 12;
            this.label1.Text = "Key";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(324, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(24, 17);
            this.label2.TabIndex = 13;
            this.label2.Text = " IV";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(324, 140);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(66, 17);
            this.label3.TabIndex = 14;
            this.label3.Text = "PlainText";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(324, 268);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(80, 17);
            this.label4.TabIndex = 15;
            this.label4.Text = " CipherText";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(277, 163);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(41, 17);
            this.label5.TabIndex = 16;
            this.label5.Text = "ASCII";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(282, 215);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(36, 17);
            this.label6.TabIndex = 17;
            this.label6.Text = "HEX";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(282, 340);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(36, 17);
            this.label7.TabIndex = 19;
            this.label7.Text = "HEX";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(277, 288);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(41, 17);
            this.label8.TabIndex = 18;
            this.label8.Text = "ASCII";
            // 
            // labelEncTimeDef
            // 
            this.labelEncTimeDef.AutoSize = true;
            this.labelEncTimeDef.Location = new System.Drawing.Point(282, 402);
            this.labelEncTimeDef.Name = "labelEncTimeDef";
            this.labelEncTimeDef.Size = new System.Drawing.Size(194, 17);
            this.labelEncTimeDef.TabIndex = 20;
            this.labelEncTimeDef.Text = " Time/message at encryption:";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(282, 466);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(194, 17);
            this.label10.TabIndex = 21;
            this.label10.Text = " Time/message at decryption:";
            // 
            // labelEncTime
            // 
            this.labelEncTime.AutoSize = true;
            this.labelEncTime.Location = new System.Drawing.Point(482, 402);
            this.labelEncTime.Name = "labelEncTime";
            this.labelEncTime.Size = new System.Drawing.Size(0, 17);
            this.labelEncTime.TabIndex = 22;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(679, 511);
            this.Controls.Add(this.labelEncTime);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.labelEncTimeDef);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxCipherHex);
            this.Controls.Add(this.textBoxCipher);
            this.Controls.Add(this.textBoxPlainHex);
            this.Controls.Add(this.textBoxPlain);
            this.Controls.Add(this.textBoxIV);
            this.Controls.Add(this.textBoxKey);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.comboBoxCipher);
            this.Name = "Form1";
            this.Text = "HEX";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboBoxCipher;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.TextBox textBoxKey;
        private System.Windows.Forms.TextBox textBoxIV;
        private System.Windows.Forms.TextBox textBoxPlain;
        private System.Windows.Forms.TextBox textBoxPlainHex;
        private System.Windows.Forms.TextBox textBoxCipher;
        private System.Windows.Forms.TextBox textBoxCipherHex;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label labelEncTimeDef;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label labelEncTime;
    }
}

