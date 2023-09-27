using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Clock
{
	public partial class formChooseFont : Form
	{
		public formChooseFont()
		{
			InitializeComponent();
			SetFontDirectory();
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
			string[] fonts = Directory.GetFiles(newCurrentDirectory, "*.ttf");
			for (int i = 0; i < fonts.Length; i++)
			{
				string[] items = fonts[i].Split('\\');
				fonts[i] = items[items.Length - 1];
			}
			this.cbFont.Items.AddRange(fonts);
		}
	}
}
