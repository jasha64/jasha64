namespace SerialPortListener
{
    partial class MainForm
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
			System.Windows.Forms.Label baudRateLabel;
			System.Windows.Forms.Label dataBitsLabel;
			System.Windows.Forms.Label parityLabel;
			System.Windows.Forms.Label portNameLabel;
			System.Windows.Forms.Label stopBitsLabel;
			System.Windows.Forms.Label label1;
			System.Windows.Forms.Label label4;
			System.Windows.Forms.Label label2;
			System.Windows.Forms.Label label3;
			this.baudRateComboBox = new System.Windows.Forms.ComboBox();
			this.serialSettingsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.dataBitsComboBox = new System.Windows.Forms.ComboBox();
			this.parityComboBox = new System.Windows.Forms.ComboBox();
			this.portNameComboBox = new System.Windows.Forms.ComboBox();
			this.stopBitsComboBox = new System.Windows.Forms.ComboBox();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.btnStart = new System.Windows.Forms.Button();
			this.btnStop = new System.Windows.Forms.Button();
			this.tbData = new System.Windows.Forms.TextBox();
			this.btnSend = new System.Windows.Forms.Button();
			this.txt_Log = new System.Windows.Forms.TextBox();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.txt_Port = new System.Windows.Forms.TextBox();
			this.txt_IP = new System.Windows.Forms.TextBox();
			this.btnConnect = new System.Windows.Forms.Button();
			this.btnCloseConnect = new System.Windows.Forms.Button();
			this.btnTCPSend = new System.Windows.Forms.Button();
			baudRateLabel = new System.Windows.Forms.Label();
			dataBitsLabel = new System.Windows.Forms.Label();
			parityLabel = new System.Windows.Forms.Label();
			portNameLabel = new System.Windows.Forms.Label();
			stopBitsLabel = new System.Windows.Forms.Label();
			label1 = new System.Windows.Forms.Label();
			label4 = new System.Windows.Forms.Label();
			label2 = new System.Windows.Forms.Label();
			label3 = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.serialSettingsBindingSource)).BeginInit();
			this.groupBox1.SuspendLayout();
			this.groupBox2.SuspendLayout();
			this.SuspendLayout();
			// 
			// baudRateLabel
			// 
			baudRateLabel.AutoSize = true;
			baudRateLabel.Location = new System.Drawing.Point(13, 68);
			baudRateLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			baudRateLabel.Name = "baudRateLabel";
			baudRateLabel.Size = new System.Drawing.Size(60, 15);
			baudRateLabel.TabIndex = 1;
			baudRateLabel.Text = "波特率:";
			// 
			// dataBitsLabel
			// 
			dataBitsLabel.AutoSize = true;
			dataBitsLabel.Location = new System.Drawing.Point(13, 99);
			dataBitsLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			dataBitsLabel.Name = "dataBitsLabel";
			dataBitsLabel.Size = new System.Drawing.Size(60, 15);
			dataBitsLabel.TabIndex = 3;
			dataBitsLabel.Text = "数据位:";
			// 
			// parityLabel
			// 
			parityLabel.AutoSize = true;
			parityLabel.Location = new System.Drawing.Point(13, 130);
			parityLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			parityLabel.Name = "parityLabel";
			parityLabel.Size = new System.Drawing.Size(60, 15);
			parityLabel.TabIndex = 5;
			parityLabel.Text = "校验位:";
			// 
			// portNameLabel
			// 
			portNameLabel.AutoSize = true;
			portNameLabel.Location = new System.Drawing.Point(13, 37);
			portNameLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			portNameLabel.Name = "portNameLabel";
			portNameLabel.Size = new System.Drawing.Size(60, 15);
			portNameLabel.TabIndex = 7;
			portNameLabel.Text = "串口号:";
			// 
			// stopBitsLabel
			// 
			stopBitsLabel.AutoSize = true;
			stopBitsLabel.Location = new System.Drawing.Point(13, 162);
			stopBitsLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			stopBitsLabel.Name = "stopBitsLabel";
			stopBitsLabel.Size = new System.Drawing.Size(60, 15);
			stopBitsLabel.TabIndex = 9;
			stopBitsLabel.Text = "停止位:";
			// 
			// label1
			// 
			label1.AutoSize = true;
			label1.Location = new System.Drawing.Point(13, 68);
			label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			label1.Name = "label1";
			label1.Size = new System.Drawing.Size(60, 15);
			label1.TabIndex = 1;
			label1.Text = "端口号:";
			// 
			// label4
			// 
			label4.AutoSize = true;
			label4.Location = new System.Drawing.Point(13, 36);
			label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			label4.Name = "label4";
			label4.Size = new System.Drawing.Size(61, 15);
			label4.TabIndex = 7;
			label4.Text = "IP地址:";
			// 
			// label2
			// 
			label2.AutoSize = true;
			label2.Location = new System.Drawing.Point(222, 14);
			label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			label2.Name = "label2";
			label2.Size = new System.Drawing.Size(67, 15);
			label2.TabIndex = 11;
			label2.Text = "串口数据";
			// 
			// label3
			// 
			label3.AutoSize = true;
			label3.Location = new System.Drawing.Point(742, 14);
			label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			label3.Name = "label3";
			label3.Size = new System.Drawing.Size(63, 15);
			label3.TabIndex = 10;
			label3.Text = "TCP log";
			// 
			// baudRateComboBox
			// 
			this.baudRateComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "BaudRate", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.baudRateComboBox.FormattingEnabled = true;
			this.baudRateComboBox.Location = new System.Drawing.Point(79, 65);
			this.baudRateComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.baudRateComboBox.Name = "baudRateComboBox";
			this.baudRateComboBox.Size = new System.Drawing.Size(101, 23);
			this.baudRateComboBox.TabIndex = 2;
			// 
			// serialSettingsBindingSource
			// 
			this.serialSettingsBindingSource.DataSource = typeof(SerialPortListener.Serial.SerialSettings);
			// 
			// dataBitsComboBox
			// 
			this.dataBitsComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "DataBits", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.dataBitsComboBox.FormattingEnabled = true;
			this.dataBitsComboBox.Location = new System.Drawing.Point(79, 96);
			this.dataBitsComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.dataBitsComboBox.Name = "dataBitsComboBox";
			this.dataBitsComboBox.Size = new System.Drawing.Size(101, 23);
			this.dataBitsComboBox.TabIndex = 4;
			// 
			// parityComboBox
			// 
			this.parityComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "Parity", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.parityComboBox.FormattingEnabled = true;
			this.parityComboBox.Location = new System.Drawing.Point(79, 127);
			this.parityComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.parityComboBox.Name = "parityComboBox";
			this.parityComboBox.Size = new System.Drawing.Size(101, 23);
			this.parityComboBox.TabIndex = 6;
			// 
			// portNameComboBox
			// 
			this.portNameComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "PortName", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.portNameComboBox.FormattingEnabled = true;
			this.portNameComboBox.Location = new System.Drawing.Point(79, 33);
			this.portNameComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.portNameComboBox.Name = "portNameComboBox";
			this.portNameComboBox.Size = new System.Drawing.Size(101, 23);
			this.portNameComboBox.TabIndex = 8;
			// 
			// stopBitsComboBox
			// 
			this.stopBitsComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "StopBits", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.stopBitsComboBox.FormattingEnabled = true;
			this.stopBitsComboBox.Location = new System.Drawing.Point(79, 158);
			this.stopBitsComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.stopBitsComboBox.Name = "stopBitsComboBox";
			this.stopBitsComboBox.Size = new System.Drawing.Size(101, 23);
			this.stopBitsComboBox.TabIndex = 10;
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.baudRateComboBox);
			this.groupBox1.Controls.Add(baudRateLabel);
			this.groupBox1.Controls.Add(this.stopBitsComboBox);
			this.groupBox1.Controls.Add(stopBitsLabel);
			this.groupBox1.Controls.Add(dataBitsLabel);
			this.groupBox1.Controls.Add(this.portNameComboBox);
			this.groupBox1.Controls.Add(this.dataBitsComboBox);
			this.groupBox1.Controls.Add(portNameLabel);
			this.groupBox1.Controls.Add(parityLabel);
			this.groupBox1.Controls.Add(this.parityComboBox);
			this.groupBox1.Location = new System.Drawing.Point(15, 14);
			this.groupBox1.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Padding = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.groupBox1.Size = new System.Drawing.Size(199, 197);
			this.groupBox1.TabIndex = 11;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "串口设置";
			// 
			// btnStart
			// 
			this.btnStart.Location = new System.Drawing.Point(53, 217);
			this.btnStart.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.btnStart.Name = "btnStart";
			this.btnStart.Size = new System.Drawing.Size(113, 27);
			this.btnStart.TabIndex = 12;
			this.btnStart.Text = "开始监听串口";
			this.btnStart.UseVisualStyleBackColor = true;
			this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
			// 
			// btnStop
			// 
			this.btnStop.Location = new System.Drawing.Point(53, 250);
			this.btnStop.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.btnStop.Name = "btnStop";
			this.btnStop.Size = new System.Drawing.Size(113, 27);
			this.btnStop.TabIndex = 12;
			this.btnStop.Text = "停止监听串口";
			this.btnStop.UseVisualStyleBackColor = true;
			this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
			// 
			// tbData
			// 
			this.tbData.Location = new System.Drawing.Point(222, 32);
			this.tbData.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.tbData.Multiline = true;
			this.tbData.Name = "tbData";
			this.tbData.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.tbData.Size = new System.Drawing.Size(504, 627);
			this.tbData.TabIndex = 13;
			// 
			// btnSend
			// 
			this.btnSend.Location = new System.Drawing.Point(53, 283);
			this.btnSend.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.btnSend.Name = "btnSend";
			this.btnSend.Size = new System.Drawing.Size(113, 27);
			this.btnSend.TabIndex = 14;
			this.btnSend.Text = "选择发送文件";
			this.btnSend.UseVisualStyleBackColor = true;
			this.btnSend.Click += new System.EventHandler(this.btnSend_Click);
			// 
			// txt_Log
			// 
			this.txt_Log.Location = new System.Drawing.Point(745, 32);
			this.txt_Log.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.txt_Log.Multiline = true;
			this.txt_Log.Name = "txt_Log";
			this.txt_Log.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.txt_Log.Size = new System.Drawing.Size(504, 627);
			this.txt_Log.TabIndex = 15;
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.txt_Port);
			this.groupBox2.Controls.Add(this.txt_IP);
			this.groupBox2.Controls.Add(label1);
			this.groupBox2.Controls.Add(label4);
			this.groupBox2.Location = new System.Drawing.Point(15, 388);
			this.groupBox2.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Padding = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.groupBox2.Size = new System.Drawing.Size(199, 99);
			this.groupBox2.TabIndex = 12;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "TCP设置";
			// 
			// txt_Port
			// 
			this.txt_Port.Location = new System.Drawing.Point(79, 63);
			this.txt_Port.Name = "txt_Port";
			this.txt_Port.Size = new System.Drawing.Size(113, 25);
			this.txt_Port.TabIndex = 9;
			this.txt_Port.Text = "5000";
			// 
			// txt_IP
			// 
			this.txt_IP.Location = new System.Drawing.Point(79, 31);
			this.txt_IP.Name = "txt_IP";
			this.txt_IP.Size = new System.Drawing.Size(113, 25);
			this.txt_IP.TabIndex = 8;
			this.txt_IP.Text = "192.168.0.231";
			// 
			// btnConnect
			// 
			this.btnConnect.Location = new System.Drawing.Point(53, 493);
			this.btnConnect.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.btnConnect.Name = "btnConnect";
			this.btnConnect.Size = new System.Drawing.Size(113, 27);
			this.btnConnect.TabIndex = 16;
			this.btnConnect.Text = "打开TCP连接";
			this.btnConnect.UseVisualStyleBackColor = true;
			this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
			// 
			// btnCloseConnect
			// 
			this.btnCloseConnect.Location = new System.Drawing.Point(53, 526);
			this.btnCloseConnect.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.btnCloseConnect.Name = "btnCloseConnect";
			this.btnCloseConnect.Size = new System.Drawing.Size(113, 27);
			this.btnCloseConnect.TabIndex = 17;
			this.btnCloseConnect.Text = "关闭TCP连接";
			this.btnCloseConnect.UseVisualStyleBackColor = true;
			this.btnCloseConnect.Click += new System.EventHandler(this.btnCloseConnect_Click);
			// 
			// btnTCPSend
			// 
			this.btnTCPSend.Location = new System.Drawing.Point(53, 559);
			this.btnTCPSend.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.btnTCPSend.Name = "btnTCPSend";
			this.btnTCPSend.Size = new System.Drawing.Size(113, 27);
			this.btnTCPSend.TabIndex = 18;
			this.btnTCPSend.Text = "选择发送文件";
			this.btnTCPSend.UseVisualStyleBackColor = true;
			this.btnTCPSend.Click += new System.EventHandler(this.btnTCPSend_Click);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1262, 673);
			this.Controls.Add(this.btnTCPSend);
			this.Controls.Add(this.btnCloseConnect);
			this.Controls.Add(this.btnConnect);
			this.Controls.Add(label3);
			this.Controls.Add(label2);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.txt_Log);
			this.Controls.Add(this.btnSend);
			this.Controls.Add(this.tbData);
			this.Controls.Add(this.btnStop);
			this.Controls.Add(this.btnStart);
			this.Controls.Add(this.groupBox1);
			this.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.Name = "MainForm";
			this.Text = "IAP";
			((System.ComponentModel.ISupportInitialize)(this.serialSettingsBindingSource)).EndInit();
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.groupBox2.ResumeLayout(false);
			this.groupBox2.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.BindingSource serialSettingsBindingSource;
        private System.Windows.Forms.ComboBox baudRateComboBox;
        private System.Windows.Forms.ComboBox dataBitsComboBox;
        private System.Windows.Forms.ComboBox parityComboBox;
        private System.Windows.Forms.ComboBox portNameComboBox;
        private System.Windows.Forms.ComboBox stopBitsComboBox;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
		private System.Windows.Forms.TextBox tbData;
		private System.Windows.Forms.Button btnSend;
		private System.Windows.Forms.TextBox txt_Log;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.TextBox txt_Port;
		private System.Windows.Forms.TextBox txt_IP;
		private System.Windows.Forms.Button btnConnect;
		private System.Windows.Forms.Button btnCloseConnect;
		private System.Windows.Forms.Button btnTCPSend;
	}
}

