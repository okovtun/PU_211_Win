using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Clock
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
			this.Location = new System.Drawing.Point
			(
				System.Windows.Forms.Screen.PrimaryScreen.Bounds.Right - this.Width - 50,
				System.Windows.Forms.Screen.PrimaryScreen.Bounds.Top + 150
			);
			ControlsVisible(false);
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			label1.Text = DateTime.Now.ToString("HH:mm:ss tt\n");
			if (cbShowDate.Checked)
			{
				label1.Text += DateTime.Now.ToString("dd.MM.yyyy");
			}
		}

		private void btnClose_Click(object sender, EventArgs e)
		{
			this.Close();
		}
		private void ControlsVisible(bool visible)
		{
			if (!visible) this.FormBorderStyle = FormBorderStyle.None;
			else this.FormBorderStyle = FormBorderStyle.FixedDialog;
			this.ShowInTaskbar = visible;
			cbShowDate.Visible = visible;
			btnDateCalculator.Visible = visible;
			btnHideControls.Visible = visible;
			btnClose.Visible = visible;
		}

		private void btnHideControls_Click(object sender, EventArgs e)
		{
			//this.FormBorderStyle = FormBorderStyle.None;
			//this.ShowInTaskbar = false;
			//cbShowDate.Visible = false;
			//btnDateCalculator.Visible = false;
			//btnHideControls.Visible = false;
			//btnClose.Visible = false;
			ControlsVisible(false);
		}

		private void label1_MouseHover(object sender, EventArgs e)
		{
			//this.FormBorderStyle = FormBorderStyle.FixedDialog;
			//cbShowDate.Visible = true;
			//btnDateCalculator.Visible = true;
			//btnHideControls.Visible = true;
			//btnClose.Visible = true;
			ControlsVisible(true);
		}

		private void cmExit_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void cmHideControls_Click(object sender, EventArgs e)
		{
			btnHideControls_Click(sender, e);
		}

		private void cmShowControls_Click(object sender, EventArgs e)
		{
			label1_MouseHover(sender, e);
		}

		private void cmShowDate_Click(object sender, EventArgs e)
		{
			cbShowDate.Checked = !cbShowDate.Checked;
			cmShowDate.Text = cbShowDate.Checked ? "Hide date" : "ShowDate";
		}

		private void cmOverAllWindows_Click(object sender, EventArgs e)
		{
			this.TopMost = !this.TopMost;
			//cmOverAllWindows.Checked = cmOverAllWindows.Checked;
		}
	}
}
