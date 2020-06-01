namespace WindowsFormsApplication1
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
            this.components = new System.ComponentModel.Container();
            this.panelM = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.buttonOpenPort = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.buttonFromSlave1 = new System.Windows.Forms.Button();
            this.buttonFromSlave2 = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.panelM.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelM
            // 
            this.panelM.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.panelM.Controls.Add(this.label1);
            this.panelM.Controls.Add(this.comboBox1);
            this.panelM.Controls.Add(this.buttonOpenPort);
            this.panelM.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelM.Location = new System.Drawing.Point(0, 0);
            this.panelM.Name = "panelM";
            this.panelM.Size = new System.Drawing.Size(441, 39);
            this.panelM.TabIndex = 19;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(17, 10);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 18);
            this.label1.TabIndex = 7;
            this.label1.Text = "COM порт";
            // 
            // comboBox1
            // 
            this.comboBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.comboBox1.Location = new System.Drawing.Point(173, 7);
            this.comboBox1.MaxDropDownItems = 10;
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(88, 26);
            this.comboBox1.TabIndex = 6;
            this.comboBox1.Click += new System.EventHandler(this.comboBox1_Click);
            // 
            // buttonOpenPort
            // 
            this.buttonOpenPort.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonOpenPort.Location = new System.Drawing.Point(330, 7);
            this.buttonOpenPort.Name = "buttonOpenPort";
            this.buttonOpenPort.Size = new System.Drawing.Size(88, 25);
            this.buttonOpenPort.TabIndex = 5;
            this.buttonOpenPort.Tag = "1";
            this.buttonOpenPort.Text = "Відкрити";
            this.buttonOpenPort.UseVisualStyleBackColor = true;
            this.buttonOpenPort.Click += new System.EventHandler(this.buttonOpenPort_Click);
            // 
            // buttonFromSlave1
            // 
            this.buttonFromSlave1.BackColor = System.Drawing.Color.Gold;
            this.buttonFromSlave1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonFromSlave1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonFromSlave1.ForeColor = System.Drawing.Color.Blue;
            this.buttonFromSlave1.Location = new System.Drawing.Point(20, 159);
            this.buttonFromSlave1.Name = "buttonFromSlave1";
            this.buttonFromSlave1.Size = new System.Drawing.Size(116, 49);
            this.buttonFromSlave1.TabIndex = 22;
            this.buttonFromSlave1.Text = "Ім\'я";
            this.buttonFromSlave1.UseVisualStyleBackColor = false;
            this.buttonFromSlave1.Visible = false;
            this.buttonFromSlave1.Click += new System.EventHandler(this.buttonFromSlave1_Click);
            // 
            // buttonFromSlave2
            // 
            this.buttonFromSlave2.BackColor = System.Drawing.Color.Gold;
            this.buttonFromSlave2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonFromSlave2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonFromSlave2.ForeColor = System.Drawing.Color.Blue;
            this.buttonFromSlave2.Location = new System.Drawing.Point(302, 159);
            this.buttonFromSlave2.Name = "buttonFromSlave2";
            this.buttonFromSlave2.Size = new System.Drawing.Size(116, 49);
            this.buttonFromSlave2.TabIndex = 23;
            this.buttonFromSlave2.Text = "День народження";
            this.buttonFromSlave2.UseVisualStyleBackColor = false;
            this.buttonFromSlave2.Visible = false;
            this.buttonFromSlave2.Click += new System.EventHandler(this.buttonFromSlave2_Click);
            // 
            // textBox2
            // 
            this.textBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBox2.Location = new System.Drawing.Point(20, 375);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(398, 26);
            this.textBox2.TabIndex = 24;
            this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(441, 415);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.buttonFromSlave2);
            this.Controls.Add(this.buttonFromSlave1);
            this.Controls.Add(this.panelM);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.panelM.ResumeLayout(false);
            this.panelM.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Panel panelM;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button buttonOpenPort;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Button buttonFromSlave1;
        //private System.Windows.Forms.Button buttonFromSlave1Corruption1;
        //private System.Windows.Forms.Button buttonFromSlave1Corruption2;
        private System.Windows.Forms.Button buttonFromSlave2;
        //private System.Windows.Forms.Button buttonFromSlave2Corruption1;
        //private System.Windows.Forms.Button buttonFromSlave2Corruption2;
        private System.Windows.Forms.TextBox textBox2;
    }
}

