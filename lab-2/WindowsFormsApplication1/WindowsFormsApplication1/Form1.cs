using System;
using System.Data;
using System.Linq;
using System.Windows.Forms;
using System.IO.Ports;
using System.Drawing;
using System.Threading;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }
        
        private void comboBox1_Click(object sender, EventArgs e)
        {
            int num;
            comboBox1.Items.Clear();
            string[] ports = SerialPort.GetPortNames().OrderBy(a => a.Length > 3 && int.TryParse(a.Substring(3), out num) ? num : 0).ToArray();
            comboBox1.Items.AddRange(ports);
        }

        private void buttonOpenPort_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
                try
                {
                    serialPort1.PortName = comboBox1.Text;
                    serialPort1.Open();
                    buttonOpenPort.Text = "Close";
                    comboBox1.Enabled = false;
                    button1.Visible = true;
                    button2.Visible = true;
                }
                catch
                {
                    MessageBox.Show("Port " + comboBox1.Text + " is invalid!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            else
            {
                serialPort1.Close();
                buttonOpenPort.Text = "Open";
                comboBox1.Enabled = true;
                button1.Visible = false;
                button2.Visible = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            byte[] b1 = new byte[1];
            b1[0] = 1;
            serialPort1.Write(b1, 0, 1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            byte[] b1 = new byte[1];
            b1[0] = 2;
            serialPort1.Write(b1, 0, 1);
        }

        private void clearAllLed()
        {
            panel1.BackColor = Color.SkyBlue;
            panel2.BackColor = Color.SkyBlue;
            panel3.BackColor = Color.SkyBlue;
            panel4.BackColor = Color.SkyBlue;
            panel5.BackColor = Color.SkyBlue;
            panel6.BackColor = Color.SkyBlue;
            panel7.BackColor = Color.SkyBlue;
            panel8.BackColor = Color.SkyBlue;

            panel9.BackColor = Color.SkyBlue;
            panel10.BackColor = Color.SkyBlue;
            panel11.BackColor = Color.SkyBlue;
            panel12.BackColor = Color.SkyBlue;
            panel13.BackColor = Color.SkyBlue;
            panel14.BackColor = Color.SkyBlue;
            panel15.BackColor = Color.SkyBlue;
            panel16.BackColor = Color.SkyBlue;
        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            byte commandFromArduino = (byte)serialPort1.ReadByte();
            if (commandFromArduino == 2)
            {
                algo2();
            }
            if (commandFromArduino == 1) {
                algo1();
            }
        }


        public void algo1 ()
        {
            for (int number = 0; number < 9; number++)
            {
                switch (number)
                {
                        case 1:
                        panel9.BackColor = Color.Red;
                            break;
                        case 2:
                            panel10.BackColor = Color.Red;
                            break;
                        case 3:
                            panel11.BackColor = Color.Red;
                            break;
                        case 4:
                            panel12.BackColor = Color.Red;
                            break;
                        case 5:
                            panel13.BackColor = Color.Red;
                            break;
                        case 6:
                            panel14.BackColor = Color.Red;
                            break;
                        case 7:
                            panel15.BackColor = Color.Red;
                            break;
                        case 8:
                            panel16.BackColor = Color.Red;
                            break;
                }
                Thread.Sleep(700);
                clearAllLed();
            }
        }

        public void algo2()
        {
            for (int number = 0; number < 9; number++)
            {
                switch (number)
                {
                    case 1:
                        panel1.BackColor = Color.Red;
                        break;
                    case 2:
                        panel8.BackColor = Color.Red;
                        break;
                    case 3:
                        panel2.BackColor = Color.Red;
                        break;
                    case 4:
                        panel7.BackColor = Color.Red;
                        break;
                    case 5:
                        panel3.BackColor = Color.Red;
                        break;
                    case 6:
                        panel6.BackColor = Color.Red;
                        break;
                    case 7:
                        panel4.BackColor = Color.Red;
                        break;
                    case 8:
                        panel5.BackColor = Color.Red;
                        break;
                }
                Thread.Sleep(700);
                clearAllLed();
            }
        }
    }
}
