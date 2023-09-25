namespace Clock
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
			this.label1 = new System.Windows.Forms.Label();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.cbShowDate = new System.Windows.Forms.CheckBox();
			this.btnHideControls = new System.Windows.Forms.Button();
			this.btnClose = new System.Windows.Forms.Button();
			this.btnDateCalculator = new System.Windows.Forms.Button();
			this.notifyIcon = new System.Windows.Forms.NotifyIcon(this.components);
			this.contextMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
			this.cmShowDate = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
			this.cmShowControls = new System.Windows.Forms.ToolStripMenuItem();
			this.cmHideControls = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.cmExit = new System.Windows.Forms.ToolStripMenuItem();
			this.cmOverAllWindows = new System.Windows.Forms.ToolStripMenuItem();
			this.contextMenuStrip.SuspendLayout();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.BackColor = System.Drawing.SystemColors.ControlLight;
			this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.label1.Location = new System.Drawing.Point(28, 28);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(204, 73);
			this.label1.TabIndex = 0;
			this.label1.Text = "label1";
			this.label1.MouseHover += new System.EventHandler(this.label1_MouseHover);
			// 
			// timer1
			// 
			this.timer1.Enabled = true;
			this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
			// 
			// cbShowDate
			// 
			this.cbShowDate.AutoSize = true;
			this.cbShowDate.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.cbShowDate.Location = new System.Drawing.Point(41, 176);
			this.cbShowDate.Name = "cbShowDate";
			this.cbShowDate.Size = new System.Drawing.Size(187, 41);
			this.cbShowDate.TabIndex = 1;
			this.cbShowDate.Text = "Show date";
			this.cbShowDate.UseVisualStyleBackColor = true;
			// 
			// btnHideControls
			// 
			this.btnHideControls.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.btnHideControls.Location = new System.Drawing.Point(12, 311);
			this.btnHideControls.Name = "btnHideControls";
			this.btnHideControls.Size = new System.Drawing.Size(448, 61);
			this.btnHideControls.TabIndex = 2;
			this.btnHideControls.Text = "Hide controls";
			this.btnHideControls.UseVisualStyleBackColor = true;
			this.btnHideControls.Click += new System.EventHandler(this.btnHideControls_Click);
			// 
			// btnClose
			// 
			this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.btnClose.Location = new System.Drawing.Point(12, 378);
			this.btnClose.Name = "btnClose";
			this.btnClose.Size = new System.Drawing.Size(448, 61);
			this.btnClose.TabIndex = 3;
			this.btnClose.Text = "Close";
			this.btnClose.UseVisualStyleBackColor = true;
			this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
			// 
			// btnDateCalculator
			// 
			this.btnDateCalculator.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.btnDateCalculator.Location = new System.Drawing.Point(12, 244);
			this.btnDateCalculator.Name = "btnDateCalculator";
			this.btnDateCalculator.Size = new System.Drawing.Size(448, 61);
			this.btnDateCalculator.TabIndex = 4;
			this.btnDateCalculator.Text = "Date calculator";
			this.btnDateCalculator.UseVisualStyleBackColor = true;
			// 
			// notifyIcon
			// 
			this.notifyIcon.ContextMenuStrip = this.contextMenuStrip;
			this.notifyIcon.Icon = ((System.Drawing.Icon)(resources.GetObject("notifyIcon.Icon")));
			this.notifyIcon.Text = "MyClock";
			this.notifyIcon.Visible = true;
			// 
			// contextMenuStrip
			// 
			this.contextMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.cmOverAllWindows,
            this.cmShowDate,
            this.toolStripSeparator2,
            this.cmShowControls,
            this.cmHideControls,
            this.toolStripSeparator1,
            this.cmExit});
			this.contextMenuStrip.Name = "contextMenuStrip";
			this.contextMenuStrip.Size = new System.Drawing.Size(181, 148);
			// 
			// cmShowDate
			// 
			this.cmShowDate.Name = "cmShowDate";
			this.cmShowDate.Size = new System.Drawing.Size(180, 22);
			this.cmShowDate.Text = "Show date";
			this.cmShowDate.Click += new System.EventHandler(this.cmShowDate_Click);
			// 
			// toolStripSeparator2
			// 
			this.toolStripSeparator2.Name = "toolStripSeparator2";
			this.toolStripSeparator2.Size = new System.Drawing.Size(177, 6);
			// 
			// cmShowControls
			// 
			this.cmShowControls.Name = "cmShowControls";
			this.cmShowControls.Size = new System.Drawing.Size(180, 22);
			this.cmShowControls.Text = "Show controls";
			this.cmShowControls.Click += new System.EventHandler(this.cmShowControls_Click);
			// 
			// cmHideControls
			// 
			this.cmHideControls.Name = "cmHideControls";
			this.cmHideControls.Size = new System.Drawing.Size(180, 22);
			this.cmHideControls.Text = "Hide controls";
			this.cmHideControls.Click += new System.EventHandler(this.cmHideControls_Click);
			// 
			// toolStripSeparator1
			// 
			this.toolStripSeparator1.Name = "toolStripSeparator1";
			this.toolStripSeparator1.Size = new System.Drawing.Size(177, 6);
			// 
			// cmExit
			// 
			this.cmExit.Name = "cmExit";
			this.cmExit.Size = new System.Drawing.Size(180, 22);
			this.cmExit.Text = "Exit";
			this.cmExit.Click += new System.EventHandler(this.cmExit_Click);
			// 
			// cmOverAllWindows
			// 
			this.cmOverAllWindows.CheckOnClick = true;
			this.cmOverAllWindows.Name = "cmOverAllWindows";
			this.cmOverAllWindows.Size = new System.Drawing.Size(180, 22);
			this.cmOverAllWindows.Text = "Over all Windows";
			this.cmOverAllWindows.Click += new System.EventHandler(this.cmOverAllWindows_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(472, 450);
			this.Controls.Add(this.btnDateCalculator);
			this.Controls.Add(this.btnClose);
			this.Controls.Add(this.btnHideControls);
			this.Controls.Add(this.cbShowDate);
			this.Controls.Add(this.label1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "Form1";
			this.ShowInTaskbar = false;
			this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
			this.Text = "MyClock";
			this.TransparencyKey = System.Drawing.SystemColors.Control;
			this.contextMenuStrip.ResumeLayout(false);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Timer timer1;
		private System.Windows.Forms.CheckBox cbShowDate;
		private System.Windows.Forms.Button btnHideControls;
		private System.Windows.Forms.Button btnClose;
		private System.Windows.Forms.Button btnDateCalculator;
		private System.Windows.Forms.NotifyIcon notifyIcon;
		private System.Windows.Forms.ContextMenuStrip contextMenuStrip;
		private System.Windows.Forms.ToolStripMenuItem cmShowControls;
		private System.Windows.Forms.ToolStripMenuItem cmHideControls;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
		private System.Windows.Forms.ToolStripMenuItem cmExit;
		private System.Windows.Forms.ToolStripMenuItem cmShowDate;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
		private System.Windows.Forms.ToolStripMenuItem cmOverAllWindows;
	}
}

