using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Net;
using System.Threading;
using SerialPortListener.Serial;
using System.IO;
using System.Windows.Forms.DataVisualization.Charting;

namespace SerialPortListener
{
    public partial class MainForm : Form
    {
        SerialPortManager _spManager;
        public MainForm()
        {
            InitializeComponent();

            UserInitialization();
        }

      
        private void UserInitialization()
        {
            _spManager = new SerialPortManager();
            SerialSettings mySerialSettings = _spManager.CurrentSerialSettings;
            serialSettingsBindingSource.DataSource = mySerialSettings;
            portNameComboBox.DataSource = mySerialSettings.PortNameCollection;
            baudRateComboBox.DataSource = mySerialSettings.BaudRateCollection;
            dataBitsComboBox.DataSource = mySerialSettings.DataBitsCollection;
            parityComboBox.DataSource = Enum.GetValues(typeof(System.IO.Ports.Parity));
            stopBitsComboBox.DataSource = Enum.GetValues(typeof(System.IO.Ports.StopBits));
			
            _spManager.NewSerialDataRecieved += new EventHandler<SerialDataEventArgs>(_spManager_NewSerialDataRecieved);
            this.FormClosing += new FormClosingEventHandler(MainForm_FormClosing);
		}

        
        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            _spManager.Dispose();   
        }

        void _spManager_NewSerialDataRecieved(object sender, SerialDataEventArgs e)
        {
            if (this.InvokeRequired)
            {
                // Using this.Invoke causes deadlock when closing serial port, and BeginInvoke is good practice anyway.
                this.BeginInvoke(new EventHandler<SerialDataEventArgs>(_spManager_NewSerialDataRecieved), new object[] { sender, e });
                return;
            }

            int maxTextLength = 1000; // maximum text length in text box
            if (tbData.TextLength > maxTextLength)
                tbData.Text = tbData.Text.Remove(0, tbData.TextLength - maxTextLength);

            // This application is connected to a GPS sending ASCCI characters, so data is converted to text
            string str = Encoding.Default.GetString(e.Data);
			tbData.AppendText(str);
            tbData.ScrollToCaret();
		}

        // Handles the "Start Listening"-buttom click event
        private void btnStart_Click(object sender, EventArgs e)
        {
			_spManager.StartListening();
        }

        // Handles the "Stop Listening"-buttom click event
        private void btnStop_Click(object sender, EventArgs e)
        {
            _spManager.StopListening();
        }

		private void btnSend_Click(object sender, EventArgs e)
		{
			OpenFileDialog dialog = new OpenFileDialog();
			dialog.Multiselect = false; //该值确定是否可以选择多个文件
			dialog.Title = "IAP：请选择要发送的代码文件";
			dialog.Filter = "所有文件(*.*)|*.*";
			if (dialog.ShowDialog() != System.Windows.Forms.DialogResult.OK) return;
			
			string file = dialog.FileName;
			byte[] sendData = System.IO.File.ReadAllBytes(file);
			_spManager.ClosePassiveReceive();
			_spManager.Send(sendData);

			//读取返回数据并校验
			byte[] sendBackData = _spManager.Receive(sendData.Length);
			// if (Enumerable.SequenceEqual(sendData, sendBackData) == false)
				// MessageBox.Show("回传数据与发送数据不匹配，请重启设备重试！", "警告", MessageBoxButtons.OK, MessageBoxIcon.Warning);
			_spManager.ResumePassiveReceive();
		}

		//定义回调
		private delegate void SetTextCallBack(string strValue);
		//声明
		private SetTextCallBack setCallBack;

		//定义接收服务端发送消息的回调
		private delegate void ReceiveMsgCallBack(string strMsg);
		//声明
		private ReceiveMsgCallBack receiveCallBack;

		//创建连接的Socket
		Socket socketSend;
		//创建接收客户端发送消息的线程
		// Thread threadReceive;

		/// <summary>
		/// 连接
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void btnConnect_Click(object sender, EventArgs e)
		{
			try
			{
				socketSend = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
				IPAddress ip = IPAddress.Parse(this.txt_IP.Text.Trim());  // 192.168.0.231
				socketSend.Connect(ip, Convert.ToInt32(this.txt_Port.Text.Trim()));  // 5000
																						//实例化回调
				setCallBack = new SetTextCallBack(SetValue);
				receiveCallBack = new ReceiveMsgCallBack(SetValue);
				this.txt_Log.Invoke(setCallBack, "连接成功");

				// 因为在IAP程序中，TCP仅仅用于传输要升级的代码文件和接收回传校验信息，所以
				// 不需要启动线程实时接收。

				////开启一个新的线程不停的接收服务器发送消息的线程
				//threadReceive = new Thread(new ThreadStart(Receive));
				////设置为后台线程
				//threadReceive.IsBackground = true;
				//threadReceive.Start();
			}
			catch (Exception ex)
			{
				MessageBox.Show("连接出错:" + ex.ToString());
			}
		}

		/// <summary>
		/// 接口服务器发送的消息
		/// </summary>
		private byte[] Receive(int len)
		{
			try
			{
				while (true)
				{
					byte[] buffer = new byte[len+1];
					//实际接收到的字节数
					int r = socketSend.Receive(buffer);
					if (r < len) continue;
					string str = Encoding.Default.GetString(buffer, 0, r - 1);  // buffer, 1, r-1
					this.txt_Log.Invoke(receiveCallBack, "收到远程服务器:" + socketSend.RemoteEndPoint + "发送的消息, 长度:" + str.Length);
					return buffer;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show("接收服务端发送的消息出错:" + ex.ToString());
				return null;
			}
		}


		private void SetValue(string strValue)
		{
			this.txt_Log.AppendText(strValue + "\r \n");
		}

		/// <summary>
		/// 客户端给服务器发送消息
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void btnTCPSend_Click(object sender, EventArgs e)
		{
			OpenFileDialog dialog = new OpenFileDialog();
			dialog.Multiselect = false; //该值确定是否可以选择多个文件
			dialog.Title = "IAP：请选择要发送的代码文件";
			dialog.Filter = "所有文件(*.*)|*.*";
			if (dialog.ShowDialog() != System.Windows.Forms.DialogResult.OK) return;

			string file = dialog.FileName;
			byte[] sendData = System.IO.File.ReadAllBytes(file);

			try
			{
				byte[] curSendData = new byte[1025];
				byte[] sendBackData0, sendBackData = new byte[1025];
				int retryCount = 0;
				for (int i = 0; i < sendData.Length; i += 1024)
				{
					curSendData.Initialize();
					Array.Copy(sendData, i, curSendData, 0, Math.Min(1024, sendData.Length - i));
					// curSendData[1] = 0x00;  // for debug
					socketSend.Send(sendData, i, Math.Min(1024, sendData.Length - i), SocketFlags.None);
					Thread.Sleep(200);
					sendBackData0 = Receive(Math.Min(1024, sendData.Length - i));
					sendBackData.Initialize();
					Array.Copy(sendBackData0, 0, sendBackData, 0, Math.Min(1024, sendData.Length - i));
					Thread.Sleep(100);
					if (Enumerable.SequenceEqual(curSendData, sendBackData))
					{
						socketSend.Send(new byte[2] { 0x55, 0xaa }, 0, 2, SocketFlags.None); // Receive(2);
						retryCount = 0;
					}
					else
					{
						retryCount++; i -= 1024;
						if (retryCount == 3)
						{
							socketSend.Send(new byte[2] { 0xaa, 0xaa }); // Receive(2);
							this.txt_Log.AppendText("重试次数超限，失败 \r \n");
							this.txt_Log.AppendText("升级取消 \r \n");
							return;
						}
						else
						{
							socketSend.Send(new byte[2] { 0x55, 0x55 }); // Receive(2);
						}
						this.txt_Log.AppendText(String.Format("第{0:D}段数据发送失败，重试({1:D}/3)... \r \n", 1+(i+1)/1024, retryCount));
					}
				}
				byte[] endSymbol = new byte[2] { 0xaa, 0x55 };
				socketSend.Send(endSymbol);
				Thread.Sleep(200);
				// Receive(2);  // 接收并抛弃数据（这两个数据的回传无意义）
			}
			catch (Exception ex)
			{
				MessageBox.Show("发送消息出错:" + ex.Message);
			}
		}

		//private void FrmClient_Load(object sender, EventArgs e)
		//{
		//	Control.CheckForIllegalCrossThreadCalls = false;
		//}

		/// <summary>
		/// 断开连接
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void btnCloseConnect_Click(object sender, EventArgs e)
		{
			//关闭socket
			socketSend.Close();
			// 终止线程
			// threadReceive.Abort();
		}
	}
}
