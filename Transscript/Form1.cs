using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Transscript
{
    public partial class Form1 : Form
    {
        #region init
        CspParameters cspp = new CspParameters();
        RSACryptoServiceProvider rsa;

        const string EncrFolder = @"c:\AESDocs\Encrypt\";
        const string DecrFolder = @"c:\AESDocs\Decrypt\";
        const string SrcFolder = @"c:\AESDocs\docs\";

        const string PubKeyFile = @"c:\AESDocs\encrypt\rsaPublicKey.txt";

        const string keyName = "key01";
        #endregion
        public Form1()
        {
            InitializeComponent();
        }

        private void bttn_verschlüsseln_Click(object sender, EventArgs e)
        {
            brow_ver.Refresh();
            if (rsa == null)
                MessageBox.Show("Schlüssel nicht gesetzt");
            else
            {
                openFileDialog1.InitialDirectory = SrcFolder;
                if (openFileDialog1.ShowDialog() == DialogResult.OK)
                {
                    string fname = openFileDialog1.FileName;
                    if (fname != null)
                    {
                        FileInfo finfo = new FileInfo();
                        string name = finfo.FullName;
                        EncryptFile(name);
                    }
                }
            }
        }


        private void bttn_entschlüsseln_Click(object sender, EventArgs e)
        {

        }

        private void bttn_pubexp_Click(object sender, EventArgs e)
        {

        }

        private void bttn_pubinp_Click(object sender, EventArgs e)
        {

        }

        private void bttn_asmkey_Click(object sender, EventArgs e)
        {

        }

        private void bttn_privkey_Click(object sender, EventArgs e)
        {

        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void openFileDialog2_FileOk(object sender, CancelEventArgs e)
        {

        }
        private void EncryptFile(string inFile)
        {
            RijndaelManaged rjndl = new RijndaelManaged();
            rjndl.KeySize = 256;
            rjndl.BlockSize = 256;
            rjndl.Mode = CipherMode.CBC;
            ICryptoTransform transform = rjndl.CreateEncryptor();

            byte[] keyEncrypted = rsa.Encrypt(rjndl.Key, false);
            byte[] lenK = new byte[4];
            byte[] lenIV = new byte[4];

            int IKey = keyEncrypted.Length;
            lenK = BitConverter.GetBytes(IKey);
            int IiV = rjndl.IV.Length;
            lenIV = BitConverter.GetBytes(IiV);

            int startFileName = inFile.LastIndexOf("\\");
            string outfile = EncrFolder + inFile.Substring(startFileName, inFile.LastIndexOf(".") - startFileName) +".d3";
            using (FileStream outFs = new FileStream(outfile, FileMode.Create))
            {
                outFs.Write(lenK, 0, 4);
                outFs.Write(lenIV, 0, 4);
                outFs.Write(keyEncrypted, 0, IKey);
                outFs.Write(rjndl.IV, 0, IiV);

                using (CryptoStream outStreamEncrypted = new CryptoStream(outFs, transform, CryptoStreamMode.Write))
                {
                    int count = 0;
                    int offset = 0;

                    int blockSizeBytes = rjndl.BlockSize / 8;
                    byte[] data = new byte[blockSizeBytes];
                    int bytesRead = 0;

                    using (FileStream inFs = new FileStream(inFile, FileMode.Create))
                    {
                        do
                        {
                            count = inFs.Read(data, 0, blockSizeBytes);
                            offset += count;
                            outStreamEncrypted.Write(data, 0, count);
                            bytesRead += blockSizeBytes;

                        } while (count > 0);
                        inFs.Close();
                    }
                    outStreamEncrypted.FlushFinalBlock();
                    outStreamEncrypted.Close();
            }
                outFs.Close();
            }

            }

        }
    }
}
