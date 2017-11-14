using Castle.Core.Logging;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TestStack.Seleno.Configuration;

namespace PesquiseJá
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //REQUISITO 1
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            //REQUISITO 2
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //REQUISITOS 3 E 4
            Process.Start(string.Format("www.google.com/search?q={0}&oq={0}", textBox1.Text));
            var texto = GetTextFromUrl(string.Format("http://www.google.com/search?q={0}&oq={0}", textBox1.Text));
            texto.IndexOf("div id=\"search\"");
            {
                var novoTexto = texto.Substring(texto.IndexOf("div id=\"search\""));
                var novoTexto2 = novoTexto.Substring(novoTexto.IndexOf("div class=\"g\""), 500);
                //REQUISITO 5
                MessageBox.Show(novoTexto2);
            }
        }
        private string GetTextFromUrl(string url)
        {
            try
            {
                string htmlCode;
                using (WebClient client = new WebClient())
                {
                    htmlCode = client.DownloadString(url);
                }
                return htmlCode;
            }
            catch (Exception exception)
            {
                //Log Exception
                return null;
            }
        }
    public static class Host
    {
        public static readonly SelenoHost Instance = new SelenoHost();

        static Host()
        {
            Instance.Run("PesquiseJá", 1392, c => c.UsingLoggerFactory(new ConsoleFactory()));
        }
    }
    
    }
}

