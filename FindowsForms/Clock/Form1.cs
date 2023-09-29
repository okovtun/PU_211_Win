using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Text;
using System.IO;

namespace Clock
{
	public partial class Form1 : Form
	{
		private string[] fonts;
		PrivateFontCollection pfc = new PrivateFontCollection();

		public string[] Fonts
		{
			get { return fonts; }
			set { fonts = value; }
		}

		public Form1()
		{
			InitializeComponent();
			this.Location = new System.Drawing.Point
			(
				System.Windows.Forms.Screen.PrimaryScreen.Bounds.Right - this.Width - 50,
				System.Windows.Forms.Screen.PrimaryScreen.Bounds.Top + 150
			);
			ControlsVisible(false);
			SetFontDirectory();
			CreateCustomLabelFont();
		}

		void SetFontDirectory()
		{
			string currentDirectory = System.IO.Directory.GetCurrentDirectory();
			//MessageBox.Show(this, currentDirectory, "Current directory", MessageBoxButtons.OK);
			string[] currentDirectoryItems = currentDirectory.Split('\\');
			Array.Resize(ref currentDirectoryItems, currentDirectoryItems.Length - 2);
			string newCurrentDirectory = "";
			foreach (string i in currentDirectoryItems)
			{
				newCurrentDirectory += i;
				newCurrentDirectory += "\\";
			}
			newCurrentDirectory += "Fonts";
			//MessageBox.Show(this, $"{currentDirectory}\n{newCurrentDirectory}", "Current directory", MessageBoxButtons.OK);
			Fonts = Directory.GetFiles(newCurrentDirectory);
		}

		void CreateCustomLabelFont()
		{
			//PrivateFontCollection pfc = new PrivateFontCollection();


			//D:\Users\Clayman\Source\Repos\PU_211_Win\FindowsForms\Clock\bin\Debug
			//D:\Users\Clayman\Source\Repos\PU_211_Win\FindowsForms\Clock\Fonts
			//pfc.AddFontFile("..\\..\\Fonts\\digital-7.ttf");
			pfc.AddFontFile("..\\..\\Fonts\\TrueType\\SFDigitalReadout-Heavy.ttf");
			Font font = new Font(pfc.Families[0], label1.Font.Size);
			pfc.Dispose();
			label1.Font = font;

			label1.BackColor = Color.Black;
			label1.ForeColor = Color.Red;
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

			//ControlsVisible(true);
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

		private void cms_lbl1_ItemShowControls_Click(object sender, EventArgs e)
		{
			ControlsVisible(cms_lbl1_ItemShowControls.Checked);
		}

		private void cms_lbl1_ItemFont_Click(object sender, EventArgs e)
		{
			formChooseFont fcf = new formChooseFont();
			fcf.Show(this);
		}

		private void cms_lbl1_ItemFontColor_Click(object sender, EventArgs e)
		{
			//FormColor fc = new FormColor();
			//fc.Show(this);
			if (colorDialog1.ShowDialog() == DialogResult.OK)
				label1.ForeColor = colorDialog1.Color;
		}
	}
}
