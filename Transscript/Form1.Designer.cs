
namespace Transscript
{
    partial class Form1
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.bttn_entschlüsseln = new System.Windows.Forms.Button();
            this.bttn_verschlüsseln = new System.Windows.Forms.Button();
            this.bttn_pubexp = new System.Windows.Forms.Button();
            this.bttn_pubinp = new System.Windows.Forms.Button();
            this.bttn_asmkey = new System.Windows.Forms.Button();
            this.bttn_privkey = new System.Windows.Forms.Button();
            this.webBrowser1 = new System.Windows.Forms.WebBrowser();
            this.brow_ver = new System.Windows.Forms.WebBrowser();
            this.tab = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.openFileDialog2 = new System.Windows.Forms.OpenFileDialog();
            this.tab.SuspendLayout();
            this.SuspendLayout();
            // 
            // bttn_entschlüsseln
            // 
            this.bttn_entschlüsseln.Location = new System.Drawing.Point(13, 64);
            this.bttn_entschlüsseln.Name = "bttn_entschlüsseln";
            this.bttn_entschlüsseln.Size = new System.Drawing.Size(154, 49);
            this.bttn_entschlüsseln.TabIndex = 0;
            this.bttn_entschlüsseln.Text = "Entschlüsseln";
            this.bttn_entschlüsseln.UseVisualStyleBackColor = true;
            this.bttn_entschlüsseln.Click += new System.EventHandler(this.bttn_entschlüsseln_Click);
            // 
            // bttn_verschlüsseln
            // 
            this.bttn_verschlüsseln.Location = new System.Drawing.Point(13, 119);
            this.bttn_verschlüsseln.Name = "bttn_verschlüsseln";
            this.bttn_verschlüsseln.Size = new System.Drawing.Size(154, 49);
            this.bttn_verschlüsseln.TabIndex = 1;
            this.bttn_verschlüsseln.Text = "Verschlüsseln";
            this.bttn_verschlüsseln.UseVisualStyleBackColor = true;
            this.bttn_verschlüsseln.Click += new System.EventHandler(this.bttn_verschlüsseln_Click);
            // 
            // bttn_pubexp
            // 
            this.bttn_pubexp.Location = new System.Drawing.Point(13, 194);
            this.bttn_pubexp.Name = "bttn_pubexp";
            this.bttn_pubexp.Size = new System.Drawing.Size(154, 27);
            this.bttn_pubexp.TabIndex = 2;
            this.bttn_pubexp.Text = "Public Key Exportieren";
            this.bttn_pubexp.UseVisualStyleBackColor = true;
            this.bttn_pubexp.Click += new System.EventHandler(this.bttn_pubexp_Click);
            // 
            // bttn_pubinp
            // 
            this.bttn_pubinp.Location = new System.Drawing.Point(13, 227);
            this.bttn_pubinp.Name = "bttn_pubinp";
            this.bttn_pubinp.Size = new System.Drawing.Size(154, 27);
            this.bttn_pubinp.TabIndex = 3;
            this.bttn_pubinp.Text = "Public Key Importieren";
            this.bttn_pubinp.UseVisualStyleBackColor = true;
            this.bttn_pubinp.Click += new System.EventHandler(this.bttn_pubinp_Click);
            // 
            // bttn_asmkey
            // 
            this.bttn_asmkey.Location = new System.Drawing.Point(12, 284);
            this.bttn_asmkey.Name = "bttn_asmkey";
            this.bttn_asmkey.Size = new System.Drawing.Size(155, 22);
            this.bttn_asmkey.TabIndex = 4;
            this.bttn_asmkey.Text = "ASM Schlüssel erstellen";
            this.bttn_asmkey.UseVisualStyleBackColor = true;
            this.bttn_asmkey.Click += new System.EventHandler(this.bttn_asmkey_Click);
            // 
            // bttn_privkey
            // 
            this.bttn_privkey.Location = new System.Drawing.Point(13, 312);
            this.bttn_privkey.Name = "bttn_privkey";
            this.bttn_privkey.Size = new System.Drawing.Size(155, 22);
            this.bttn_privkey.TabIndex = 5;
            this.bttn_privkey.Text = "Privaten Schlüssel laden";
            this.bttn_privkey.UseVisualStyleBackColor = true;
            this.bttn_privkey.Click += new System.EventHandler(this.bttn_privkey_Click);
            // 
            // webBrowser1
            // 
            this.webBrowser1.Location = new System.Drawing.Point(240, 64);
            this.webBrowser1.MinimumSize = new System.Drawing.Size(20, 20);
            this.webBrowser1.Name = "webBrowser1";
            this.webBrowser1.Size = new System.Drawing.Size(448, 283);
            this.webBrowser1.TabIndex = 8;
            // 
            // brow_ver
            // 
            this.brow_ver.Location = new System.Drawing.Point(234, 66);
            this.brow_ver.MinimumSize = new System.Drawing.Size(20, 20);
            this.brow_ver.Name = "brow_ver";
            this.brow_ver.Size = new System.Drawing.Size(449, 282);
            this.brow_ver.TabIndex = 9;
            // 
            // tab
            // 
            this.tab.Controls.Add(this.tabPage1);
            this.tab.Controls.Add(this.tabPage2);
            this.tab.Location = new System.Drawing.Point(239, 35);
            this.tab.Name = "tab";
            this.tab.SelectedIndex = 0;
            this.tab.Size = new System.Drawing.Size(448, 29);
            this.tab.TabIndex = 10;
            // 
            // tabPage1
            // 
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(440, 3);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "tabPage1";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(440, 3);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "tabPage2";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            this.openFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog1_FileOk);
            // 
            // openFileDialog2
            // 
            this.openFileDialog2.FileName = "openFileDialog2";
            this.openFileDialog2.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog2_FileOk);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tab);
            this.Controls.Add(this.brow_ver);
            this.Controls.Add(this.webBrowser1);
            this.Controls.Add(this.bttn_privkey);
            this.Controls.Add(this.bttn_asmkey);
            this.Controls.Add(this.bttn_pubinp);
            this.Controls.Add(this.bttn_pubexp);
            this.Controls.Add(this.bttn_verschlüsseln);
            this.Controls.Add(this.bttn_entschlüsseln);
            this.Name = "Form1";
            this.Text = "Form1";
            this.tab.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button bttn_entschlüsseln;
        private System.Windows.Forms.Button bttn_verschlüsseln;
        private System.Windows.Forms.Button bttn_pubexp;
        private System.Windows.Forms.Button bttn_pubinp;
        private System.Windows.Forms.Button bttn_asmkey;
        private System.Windows.Forms.Button bttn_privkey;
        private System.Windows.Forms.WebBrowser webBrowser1;
        private System.Windows.Forms.WebBrowser brow_ver;
        private System.Windows.Forms.TabControl tab;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog2;
    }
}

