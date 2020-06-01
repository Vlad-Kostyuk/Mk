using System;
using System.Data;
using System.IO.Ports;
using System.Linq;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        int numberOfMessage = 0;
        int message;
        int pointerInMessage = 0;
        bool isFirstMessage = false;
        bool firstDataState = true;
        bool secondDataState = true;

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
            Console.WriteLine("--- Number of Message = " + ++numberOfMessage + " ---");
            isFirstMessage = true;
            pointerInMessage = -1;
            byte[] b1 = new byte[1];
            b1[0] = 0xC1;
            serialPort1.Write(b1, 0, 1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
        }


        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {

            byte dataFromArduino = (byte)serialPort1.ReadByte();


            if (dataFromArduino == 0b10100101)
            {
                pointerInMessage = -1;
                isFirstMessage = false;
                byte[] b1 = new byte[1];
                b1[0] = 0xD1;
                serialPort1.Write(b1, 0, 1);
            }
            else
            {
                pointerInMessage++;
            }

            if (isFirstMessage)
            {
                String res = "";
                if (pointerInMessage == 0)
                {
                    message = dataFromArduino;
                }
                else if (pointerInMessage == 1)
                {
                    if (message > 128)
                    {
                        message -= 256;
                    }
                    Console.WriteLine("Temperature in Slave_A is " + (int)message + " degrees");
                    checkData(dataFromArduino, (byte)message);
                    if (firstDataState)
                    {
                        Console.WriteLine("Message is not broken");
                    }
                    else
                    {
                        Console.WriteLine("Message is broken");
                    }
                }
            }
            else
            {
                if (pointerInMessage == 0)
                {
                    message = dataFromArduino;
                }
                else if (pointerInMessage == 1)
                {
                    Console.WriteLine("Temperature in Slave_B is " + (int)message + " degrees");
                    checkData(dataFromArduino, (byte)message);
                    if (secondDataState)
                    {
                        Console.WriteLine("Message is not broken");
                    }
                    else
                    {
                        Console.WriteLine("Message is broken");
                    }
                }
            }
        }



        private void checkData(byte oldCRC, byte arr)
        {

            byte newCRC = calculateCRC(arr, 0x1D, 0xFF, 0x00);

            if (newCRC != oldCRC)
            {
                if (isFirstMessage)
                {
                    firstDataState = false;
                }
                else
                {
                    secondDataState = false;
                }

            }
        }

        private byte calculateCRC(byte b, byte poly, byte crcStart, byte finalXOR)
        {
            byte crc = crcStart;
            int i;
            b = reflect8(b);
            crc ^= b;

            for (i = 0; i < 8; i++)
            {
                if ((crc & 0x80) != 0)
                {
                    crc = (byte)((crc << 1) ^ poly);
                }
                else
                {
                    crc <<= 1;
                }

            }

            crc = reflect8(crc);
            crc ^= finalXOR;
            return crc;
        }

        private byte reflect8(byte x)
        {
            byte result = 0;
            int c;
            for (c = 0; c < 8; c++)
            {
                result <<= 1;
                if ((x & 1) == 1)
                    result++;
                x >>= 1;
            }
            return result;
        }

        private void panelM_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
