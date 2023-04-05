
namespace MTP_lab5
{
    partial class Form2
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
            this.label1 = new System.Windows.Forms.Label();
            this.cautaNumeTB = new System.Windows.Forms.TextBox();
            this.cautaNumeBTN = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.label2 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(400, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(138, 29);
            this.label1.TabIndex = 0;
            this.label1.Text = " PACIENTI";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // cautaNumeTB
            // 
            this.cautaNumeTB.Location = new System.Drawing.Point(347, 81);
            this.cautaNumeTB.Name = "cautaNumeTB";
            this.cautaNumeTB.Size = new System.Drawing.Size(238, 26);
            this.cautaNumeTB.TabIndex = 1;
            // 
            // cautaNumeBTN
            // 
            this.cautaNumeBTN.Location = new System.Drawing.Point(657, 72);
            this.cautaNumeBTN.Name = "cautaNumeBTN";
            this.cautaNumeBTN.Size = new System.Drawing.Size(107, 44);
            this.cautaNumeBTN.TabIndex = 2;
            this.cautaNumeBTN.Text = " Search";
            this.cautaNumeBTN.UseVisualStyleBackColor = true;
            this.cautaNumeBTN.Click += new System.EventHandler(this.cautaNumeBTN_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(57, 133);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 62;
            this.dataGridView1.RowTemplate.Height = 28;
            this.dataGridView1.Size = new System.Drawing.Size(852, 199);
            this.dataGridView1.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(186, 84);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(128, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "Search by name:";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(232, 380);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(134, 58);
            this.button1.TabIndex = 5;
            this.button1.Text = " Add Patient";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(451, 380);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(134, 58);
            this.button2.TabIndex = 6;
            this.button2.Text = "Add Visit";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(657, 380);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(134, 58);
            this.button3.TabIndex = 7;
            this.button3.Text = " Add X-Ray";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(347, 466);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(134, 58);
            this.button4.TabIndex = 8;
            this.button4.Text = "View Medical Record";
            this.button4.UseVisualStyleBackColor = true;
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(567, 466);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(134, 58);
            this.button5.TabIndex = 9;
            this.button5.Text = "Close";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(993, 565);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.cautaNumeBTN);
            this.Controls.Add(this.cautaNumeTB);
            this.Controls.Add(this.label1);
            this.Name = "Form2";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox cautaNumeTB;
        private System.Windows.Forms.Button cautaNumeBTN;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
    }
}