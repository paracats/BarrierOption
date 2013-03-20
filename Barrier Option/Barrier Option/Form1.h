#pragma once

double* down_and_out(double s0, double k,double x, double sigma, double T, double r);
double* down_and_in(double s0, double k, double x, double sigma, double T, double r);
double* up_and_out(double s0, double k, double x, double sigma, double T, double r);
double* up_and_in(double s0, double k, double x, double sigma, double T, double r);



namespace BarrierOption {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  S;
	protected: 
	private: System::Windows::Forms::Label^  sigma;
	private: System::Windows::Forms::Label^  T;
	private: System::Windows::Forms::Label^  X;
	private: System::Windows::Forms::Label^  K;
	private: System::Windows::Forms::Label^  r;
	private: System::Windows::Forms::TextBox^  S_text;
	private: System::Windows::Forms::TextBox^  K_text;
	private: System::Windows::Forms::TextBox^  X_text;
	private: System::Windows::Forms::TextBox^  T_text;
	private: System::Windows::Forms::TextBox^  r_text;
	private: System::Windows::Forms::TextBox^  sigma_text;
	private: System::Windows::Forms::RadioButton^  up_n_out;
	private: System::Windows::Forms::RadioButton^  up_n_in;
	private: System::Windows::Forms::RadioButton^  down_n_out;
	private: System::Windows::Forms::RadioButton^  down_n_in;


	private: System::Windows::Forms::Button^  btn_calculate;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Call;
	private: System::Windows::Forms::MaskedTextBox^  Put;





	protected: 






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->S = (gcnew System::Windows::Forms::Label());
			this->sigma = (gcnew System::Windows::Forms::Label());
			this->T = (gcnew System::Windows::Forms::Label());
			this->X = (gcnew System::Windows::Forms::Label());
			this->K = (gcnew System::Windows::Forms::Label());
			this->r = (gcnew System::Windows::Forms::Label());
			this->S_text = (gcnew System::Windows::Forms::TextBox());
			this->K_text = (gcnew System::Windows::Forms::TextBox());
			this->X_text = (gcnew System::Windows::Forms::TextBox());
			this->T_text = (gcnew System::Windows::Forms::TextBox());
			this->r_text = (gcnew System::Windows::Forms::TextBox());
			this->sigma_text = (gcnew System::Windows::Forms::TextBox());
			this->up_n_out = (gcnew System::Windows::Forms::RadioButton());
			this->up_n_in = (gcnew System::Windows::Forms::RadioButton());
			this->down_n_out = (gcnew System::Windows::Forms::RadioButton());
			this->down_n_in = (gcnew System::Windows::Forms::RadioButton());
			this->btn_calculate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Call = (gcnew System::Windows::Forms::TextBox());
			this->Put = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SuspendLayout();
			// 
			// S
			// 
			this->S->AutoSize = true;
			this->S->Location = System::Drawing::Point(10, 19);
			this->S->Name = L"S";
			this->S->Size = System::Drawing::Size(62, 13);
			this->S->TabIndex = 0;
			this->S->Text = L"Stock Price";
			// 
			// sigma
			// 
			this->sigma->AutoSize = true;
			this->sigma->Location = System::Drawing::Point(10, 139);
			this->sigma->Name = L"sigma";
			this->sigma->Size = System::Drawing::Size(45, 13);
			this->sigma->TabIndex = 1;
			this->sigma->Text = L"Volatility";
			// 
			// T
			// 
			this->T->AutoSize = true;
			this->T->Location = System::Drawing::Point(10, 109);
			this->T->Name = L"T";
			this->T->Size = System::Drawing::Size(91, 13);
			this->T->TabIndex = 2;
			this->T->Text = L"Time to Expiration";
			// 
			// X
			// 
			this->X->AutoSize = true;
			this->X->Location = System::Drawing::Point(10, 79);
			this->X->Name = L"X";
			this->X->Size = System::Drawing::Size(64, 13);
			this->X->TabIndex = 3;
			this->X->Text = L"Barrier Price";
			// 
			// K
			// 
			this->K->AutoSize = true;
			this->K->Location = System::Drawing::Point(10, 49);
			this->K->Name = L"K";
			this->K->Size = System::Drawing::Size(61, 13);
			this->K->TabIndex = 4;
			this->K->Text = L"Strike Price";
			// 
			// r
			// 
			this->r->AutoSize = true;
			this->r->Location = System::Drawing::Point(10, 169);
			this->r->Name = L"r";
			this->r->Size = System::Drawing::Size(75, 13);
			this->r->TabIndex = 5;
			this->r->Text = L"Risk-free Rate";
			// 
			// S_text
			// 
			this->S_text->Location = System::Drawing::Point(178, 19);
			this->S_text->Name = L"S_text";
			this->S_text->Size = System::Drawing::Size(169, 20);
			this->S_text->TabIndex = 6;
			// 
			// K_text
			// 
			this->K_text->Location = System::Drawing::Point(178, 49);
			this->K_text->Name = L"K_text";
			this->K_text->Size = System::Drawing::Size(169, 20);
			this->K_text->TabIndex = 7;
			// 
			// X_text
			// 
			this->X_text->Location = System::Drawing::Point(178, 79);
			this->X_text->Name = L"X_text";
			this->X_text->Size = System::Drawing::Size(169, 20);
			this->X_text->TabIndex = 8;
			// 
			// T_text
			// 
			this->T_text->Location = System::Drawing::Point(178, 109);
			this->T_text->Name = L"T_text";
			this->T_text->Size = System::Drawing::Size(169, 20);
			this->T_text->TabIndex = 9;
			// 
			// r_text
			// 
			this->r_text->Location = System::Drawing::Point(178, 169);
			this->r_text->Name = L"r_text";
			this->r_text->Size = System::Drawing::Size(169, 20);
			this->r_text->TabIndex = 11;
			// 
			// sigma_text
			// 
			this->sigma_text->Location = System::Drawing::Point(178, 139);
			this->sigma_text->Name = L"sigma_text";
			this->sigma_text->Size = System::Drawing::Size(169, 20);
			this->sigma_text->TabIndex = 10;
			// 
			// up_n_out
			// 
			this->up_n_out->AutoSize = true;
			this->up_n_out->Location = System::Drawing::Point(15, 213);
			this->up_n_out->Name = L"up_n_out";
			this->up_n_out->Size = System::Drawing::Size(80, 17);
			this->up_n_out->TabIndex = 12;
			this->up_n_out->TabStop = true;
			this->up_n_out->Text = L"Up and Out";
			this->up_n_out->UseVisualStyleBackColor = true;
			// 
			// up_n_in
			// 
			this->up_n_in->AutoSize = true;
			this->up_n_in->Location = System::Drawing::Point(15, 238);
			this->up_n_in->Name = L"up_n_in";
			this->up_n_in->Size = System::Drawing::Size(72, 17);
			this->up_n_in->TabIndex = 13;
			this->up_n_in->TabStop = true;
			this->up_n_in->Text = L"Up and In";
			this->up_n_in->UseVisualStyleBackColor = true;
			// 
			// down_n_out
			// 
			this->down_n_out->AutoSize = true;
			this->down_n_out->Location = System::Drawing::Point(15, 263);
			this->down_n_out->Name = L"down_n_out";
			this->down_n_out->Size = System::Drawing::Size(94, 17);
			this->down_n_out->TabIndex = 14;
			this->down_n_out->TabStop = true;
			this->down_n_out->Text = L"Down and Out";
			this->down_n_out->UseVisualStyleBackColor = true;
			// 
			// down_n_in
			// 
			this->down_n_in->AutoSize = true;
			this->down_n_in->Location = System::Drawing::Point(15, 288);
			this->down_n_in->Name = L"down_n_in";
			this->down_n_in->Size = System::Drawing::Size(86, 17);
			this->down_n_in->TabIndex = 15;
			this->down_n_in->TabStop = true;
			this->down_n_in->Text = L"Down and In";
			this->down_n_in->UseVisualStyleBackColor = true;
			// 
			// btn_calculate
			// 
			this->btn_calculate->Location = System::Drawing::Point(15, 317);
			this->btn_calculate->Name = L"btn_calculate";
			this->btn_calculate->Size = System::Drawing::Size(145, 25);
			this->btn_calculate->TabIndex = 16;
			this->btn_calculate->Text = L"Calculate";
			this->btn_calculate->UseVisualStyleBackColor = true;
			this->btn_calculate->Click += gcnew System::EventHandler(this, &Form1::btn_calculate_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(176, 347);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(248, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Application by Parkin Furia (parkinfuria@gmail.com)";
			// 
			// Call
			// 
			this->Call->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->Call->ForeColor = System::Drawing::SystemColors::WindowText;
			this->Call->Location = System::Drawing::Point(178, 199);
			this->Call->Name = L"Call";
			this->Call->Size = System::Drawing::Size(169, 20);
			this->Call->TabIndex = 19;
			// 
			// Put
			// 
			this->Put->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->Put->Location = System::Drawing::Point(179, 229);
			this->Put->Name = L"Put";
			this->Put->Size = System::Drawing::Size(169, 20);
			this->Put->TabIndex = 20;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 369);
			this->Controls->Add(this->Put);
			this->Controls->Add(this->Call);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_calculate);
			this->Controls->Add(this->down_n_in);
			this->Controls->Add(this->down_n_out);
			this->Controls->Add(this->up_n_in);
			this->Controls->Add(this->up_n_out);
			this->Controls->Add(this->sigma_text);
			this->Controls->Add(this->r_text);
			this->Controls->Add(this->T_text);
			this->Controls->Add(this->X_text);
			this->Controls->Add(this->K_text);
			this->Controls->Add(this->S_text);
			this->Controls->Add(this->r);
			this->Controls->Add(this->K);
			this->Controls->Add(this->X);
			this->Controls->Add(this->T);
			this->Controls->Add(this->sigma);
			this->Controls->Add(this->S);
			this->Name = L"Form1";
			this->Text = L"Barrier Option Pricing using Monte Carlo Simulations";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_calculate_Click(System::Object^  sender, System::EventArgs^  e) {
				 String ^ S_1_str = S_text->Text;
				 String ^ K_1_str = K_text->Text;
				 String ^ X_1_str = X_text->Text;
				 String ^ T_1_str = T_text->Text;
				 String ^ sigma_1_str = sigma_text->Text;
				 String ^ r_1_str = r_text->Text;		
				 
				 
				 double S_1 = System::Convert::ToDouble(S_1_str); 
				 double K_1 = System::Convert::ToDouble(K_1_str); 
				 double X_1 = System::Convert::ToDouble(X_1_str); 
				 double T_1 = System::Convert::ToDouble(T_1_str); 
				 double sigma_1 = System::Convert::ToDouble(sigma_1_str);
				 double r_1 = System::Convert::ToDouble(r_1_str);

				 if (this->down_n_out->Checked)
					 {this->Call->Text="Call Option: "+System::Convert::ToString(*(down_and_out(S_1,K_1,X_1,sigma_1,T_1,r_1)));
					this->Put->Text="Put Option: "+System::Convert::ToString(*(down_and_out(S_1,K_1,X_1,sigma_1,T_1,r_1)+1));
					}
				 else if (this->down_n_in->Checked)
					  {this->Call->Text="Call Option: "+System::Convert::ToString(*(down_and_in(S_1,K_1,X_1,sigma_1,T_1,r_1)));
				 this->Put->Text="Put Option: "+System::Convert::ToString(*(down_and_in(S_1,K_1,X_1,sigma_1,T_1,r_1)+1));
					}
				 else if (this->up_n_out->Checked)
					  {this->Call->Text="Call Option: "+System::Convert::ToString(*(up_and_out(S_1,K_1,X_1,sigma_1,T_1,r_1)));
				 this->Put->Text="Put Option: "+System::Convert::ToString(*(up_and_out(S_1,K_1,X_1,sigma_1,T_1,r_1)+1));
					}
				 else if (this->up_n_in->Checked)
					  {this->Call->Text="Call Option: "+System::Convert::ToString(*(up_and_in(S_1,K_1,X_1,sigma_1,T_1,r_1)));
				 this->Put->Text="Put Option: "+System::Convert::ToString(*(up_and_in(S_1,K_1,X_1,sigma_1,T_1,r_1)+1));
					}
				 else {}
			}
};
}

