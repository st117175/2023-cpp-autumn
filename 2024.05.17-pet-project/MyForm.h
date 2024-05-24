#pragma once
#include <msclr/marshal_cppstd.h>
#include <string>
#include "MyForm2.h"
#include "Header.h"


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::Button^ btn_Solve_quadratic;
	private: System::Windows::Forms::Label^ label_put_abc_quadratic;
	private: System::Windows::Forms::Label^ label_put_abn;
	private: System::Windows::Forms::TextBox^ textBox_n;
	private: System::Windows::Forms::Label^ label_n;
	private: System::Windows::Forms::Button^ button_Solve_root;

	public:

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ btn_lyneal;
	private: System::Windows::Forms::Button^ btn_quadratic;
	private: System::Windows::Forms::Button^ btn_root;


	private: System::Windows::Forms::Label^ label_put_abc;

	private: System::Windows::Forms::Label^ label_a;
	private: System::Windows::Forms::Label^ label_b;
	private: System::Windows::Forms::Label^ label_c;
	private: System::Windows::Forms::Label^ label_d;
	private: System::Windows::Forms::Label^ label_f;
	private: System::Windows::Forms::Label^ label_g;
	private: System::Windows::Forms::TextBox^ textBox_a;
	private: System::Windows::Forms::TextBox^ textBox_b;
	private: System::Windows::Forms::TextBox^ textBox_c;
	private: System::Windows::Forms::TextBox^ textBox_d;
	private: System::Windows::Forms::TextBox^ textBox_f;
	private: System::Windows::Forms::TextBox^ textBox_g;
	private: System::Windows::Forms::Button^ btn_Solve;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_lyneal = (gcnew System::Windows::Forms::Button());
			this->btn_quadratic = (gcnew System::Windows::Forms::Button());
			this->btn_root = (gcnew System::Windows::Forms::Button());
			this->label_put_abc = (gcnew System::Windows::Forms::Label());
			this->label_a = (gcnew System::Windows::Forms::Label());
			this->label_b = (gcnew System::Windows::Forms::Label());
			this->label_c = (gcnew System::Windows::Forms::Label());
			this->label_d = (gcnew System::Windows::Forms::Label());
			this->label_f = (gcnew System::Windows::Forms::Label());
			this->label_g = (gcnew System::Windows::Forms::Label());
			this->textBox_a = (gcnew System::Windows::Forms::TextBox());
			this->textBox_b = (gcnew System::Windows::Forms::TextBox());
			this->textBox_c = (gcnew System::Windows::Forms::TextBox());
			this->textBox_d = (gcnew System::Windows::Forms::TextBox());
			this->textBox_f = (gcnew System::Windows::Forms::TextBox());
			this->textBox_g = (gcnew System::Windows::Forms::TextBox());
			this->btn_Solve = (gcnew System::Windows::Forms::Button());
			this->btn_Solve_quadratic = (gcnew System::Windows::Forms::Button());
			this->label_put_abc_quadratic = (gcnew System::Windows::Forms::Label());
			this->label_put_abn = (gcnew System::Windows::Forms::Label());
			this->textBox_n = (gcnew System::Windows::Forms::TextBox());
			this->label_n = (gcnew System::Windows::Forms::Label());
			this->button_Solve_root = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(237, 41);
			this->label1->MaximumSize = System::Drawing::Size(400, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(398, 50);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выберите тип решаемого уравнения";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_lyneal
			// 
			this->btn_lyneal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_lyneal->Location = System::Drawing::Point(83, 252);
			this->btn_lyneal->Name = L"btn_lyneal";
			this->btn_lyneal->Size = System::Drawing::Size(98, 50);
			this->btn_lyneal->TabIndex = 1;
			this->btn_lyneal->Text = L"Линейное\r\n";
			this->btn_lyneal->UseVisualStyleBackColor = true;
			this->btn_lyneal->Click += gcnew System::EventHandler(this, &MyForm::btn_lyneal_Click);
			// 
			// btn_quadratic
			// 
			this->btn_quadratic->Location = System::Drawing::Point(406, 252);
			this->btn_quadratic->Name = L"btn_quadratic";
			this->btn_quadratic->Size = System::Drawing::Size(108, 50);
			this->btn_quadratic->TabIndex = 2;
			this->btn_quadratic->Text = L"Квадратное";
			this->btn_quadratic->UseVisualStyleBackColor = true;
			this->btn_quadratic->Click += gcnew System::EventHandler(this, &MyForm::btn_quadratic_Click);
			// 
			// btn_root
			// 
			this->btn_root->Location = System::Drawing::Point(768, 252);
			this->btn_root->Name = L"btn_root";
			this->btn_root->Size = System::Drawing::Size(98, 50);
			this->btn_root->TabIndex = 3;
			this->btn_root->Text = L"Корень степени n";
			this->btn_root->UseVisualStyleBackColor = true;
			this->btn_root->Click += gcnew System::EventHandler(this, &MyForm::btn_root_Click);
			// 
			// label_put_abc
			// 
			this->label_put_abc->AutoSize = true;
			this->label_put_abc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_put_abc->Location = System::Drawing::Point(78, 150);
			this->label_put_abc->Name = L"label_put_abc";
			this->label_put_abc->Size = System::Drawing::Size(573, 25);
			this->label_put_abc->TabIndex = 4;
			this->label_put_abc->Text = L"Введите коэффициенты уравнения:(a + bi) + (c + di)x = f + gi";
			this->label_put_abc->Visible = false;
			// 
			// label_a
			// 
			this->label_a->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_a->Location = System::Drawing::Point(40, 330);
			this->label_a->Name = L"label_a";
			this->label_a->Size = System::Drawing::Size(38, 25);
			this->label_a->TabIndex = 8;
			this->label_a->Text = L"a = ";
			this->label_a->Visible = false;
			// 
			// label_b
			// 
			this->label_b->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_b->Location = System::Drawing::Point(160, 330);
			this->label_b->Name = L"label_b";
			this->label_b->Size = System::Drawing::Size(38, 25);
			this->label_b->TabIndex = 13;
			this->label_b->Text = L"b = ";
			this->label_b->Visible = false;
			// 
			// label_c
			// 
			this->label_c->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_c->Location = System::Drawing::Point(280, 330);
			this->label_c->Name = L"label_c";
			this->label_c->Size = System::Drawing::Size(38, 25);
			this->label_c->TabIndex = 16;
			this->label_c->Text = L"c = ";
			this->label_c->Visible = false;
			// 
			// label_d
			// 
			this->label_d->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_d->Location = System::Drawing::Point(400, 330);
			this->label_d->Name = L"label_d";
			this->label_d->Size = System::Drawing::Size(38, 25);
			this->label_d->TabIndex = 18;
			this->label_d->Text = L"d = ";
			this->label_d->Visible = false;
			// 
			// label_f
			// 
			this->label_f->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_f->Location = System::Drawing::Point(520, 330);
			this->label_f->Name = L"label_f";
			this->label_f->Size = System::Drawing::Size(38, 25);
			this->label_f->TabIndex = 20;
			this->label_f->Text = L"f = ";
			this->label_f->Visible = false;
			// 
			// label_g
			// 
			this->label_g->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_g->Location = System::Drawing::Point(640, 330);
			this->label_g->Name = L"label_g";
			this->label_g->Size = System::Drawing::Size(38, 25);
			this->label_g->TabIndex = 22;
			this->label_g->Text = L"g = ";
			this->label_g->Visible = false;
			// 
			// textBox_a
			// 
			this->textBox_a->Location = System::Drawing::Point(90, 330);
			this->textBox_a->Name = L"textBox_a";
			this->textBox_a->Size = System::Drawing::Size(58, 22);
			this->textBox_a->TabIndex = 23;
			this->textBox_a->Visible = false;
			this->textBox_a->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_a_KeyPress);
			// 
			// textBox_b
			// 
			this->textBox_b->Location = System::Drawing::Point(210, 330);
			this->textBox_b->Name = L"textBox_b";
			this->textBox_b->Size = System::Drawing::Size(58, 22);
			this->textBox_b->TabIndex = 24;
			this->textBox_b->Visible = false;
			this->textBox_b->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_b_KeyPress);
			// 
			// textBox_c
			// 
			this->textBox_c->Location = System::Drawing::Point(330, 330);
			this->textBox_c->Name = L"textBox_c";
			this->textBox_c->Size = System::Drawing::Size(58, 22);
			this->textBox_c->TabIndex = 25;
			this->textBox_c->Visible = false;
			this->textBox_c->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_c_KeyPress);
			// 
			// textBox_d
			// 
			this->textBox_d->Location = System::Drawing::Point(450, 330);
			this->textBox_d->Name = L"textBox_d";
			this->textBox_d->Size = System::Drawing::Size(58, 22);
			this->textBox_d->TabIndex = 26;
			this->textBox_d->Visible = false;
			this->textBox_d->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_d_KeyPress);
			// 
			// textBox_f
			// 
			this->textBox_f->Location = System::Drawing::Point(570, 330);
			this->textBox_f->Name = L"textBox_f";
			this->textBox_f->Size = System::Drawing::Size(58, 22);
			this->textBox_f->TabIndex = 27;
			this->textBox_f->Visible = false;
			this->textBox_f->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_f_KeyPress);
			// 
			// textBox_g
			// 
			this->textBox_g->Location = System::Drawing::Point(690, 330);
			this->textBox_g->Name = L"textBox_g";
			this->textBox_g->Size = System::Drawing::Size(58, 22);
			this->textBox_g->TabIndex = 28;
			this->textBox_g->Visible = false;
			this->textBox_g->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_g_KeyPress);
			// 
			// btn_Solve
			// 
			this->btn_Solve->Location = System::Drawing::Point(635, 377);
			this->btn_Solve->Name = L"btn_Solve";
			this->btn_Solve->Size = System::Drawing::Size(73, 23);
			this->btn_Solve->TabIndex = 29;
			this->btn_Solve->Text = L"Solve";
			this->btn_Solve->UseVisualStyleBackColor = true;
			this->btn_Solve->Visible = false;
			this->btn_Solve->Click += gcnew System::EventHandler(this, &MyForm::btn_Solve_Click);
			// 
			// btn_Solve_quadratic
			// 
			this->btn_Solve_quadratic->Location = System::Drawing::Point(635, 377);
			this->btn_Solve_quadratic->Name = L"btn_Solve_quadratic";
			this->btn_Solve_quadratic->Size = System::Drawing::Size(73, 23);
			this->btn_Solve_quadratic->TabIndex = 30;
			this->btn_Solve_quadratic->Text = L"Solve";
			this->btn_Solve_quadratic->UseVisualStyleBackColor = true;
			this->btn_Solve_quadratic->Visible = false;
			this->btn_Solve_quadratic->Click += gcnew System::EventHandler(this, &MyForm::btn_Solve_quadratic_Click);
			// 
			// label_put_abc_quadratic
			// 
			this->label_put_abc_quadratic->AutoSize = true;
			this->label_put_abc_quadratic->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_put_abc_quadratic->Location = System::Drawing::Point(78, 150);
			this->label_put_abc_quadratic->Name = L"label_put_abc_quadratic";
			this->label_put_abc_quadratic->Size = System::Drawing::Size(650, 25);
			this->label_put_abc_quadratic->TabIndex = 31;
			this->label_put_abc_quadratic->Text = L"Введите коэффициенты уравнения:(a + bi)*x^2 + (c + di)*x + f + gi = 0";
			this->label_put_abc_quadratic->Visible = false;
			// 
			// label_put_abn
			// 
			this->label_put_abn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_put_abn->Location = System::Drawing::Point(78, 150);
			this->label_put_abn->Name = L"label_put_abn";
			this->label_put_abn->Size = System::Drawing::Size(699, 25);
			this->label_put_abn->TabIndex = 32;
			this->label_put_abn->Text = L"Введите коэффициенты уравнения: x^n = a + bi,  n - натуральное число";
			this->label_put_abn->Visible = false;
			// 
			// textBox_n
			// 
			this->textBox_n->Location = System::Drawing::Point(330, 330);
			this->textBox_n->Name = L"textBox_n";
			this->textBox_n->Size = System::Drawing::Size(58, 22);
			this->textBox_n->TabIndex = 33;
			this->textBox_n->Visible = false;
			this->textBox_n->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_n_KeyPress);
			// 
			// label_n
			// 
			this->label_n->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_n->Location = System::Drawing::Point(284, 327);
			this->label_n->Name = L"label_n";
			this->label_n->Size = System::Drawing::Size(38, 25);
			this->label_n->TabIndex = 34;
			this->label_n->Text = L"n = ";
			this->label_n->Visible = false;
			// 
			// button_Solve_root
			// 
			this->button_Solve_root->Location = System::Drawing::Point(635, 377);
			this->button_Solve_root->Name = L"button_Solve_root";
			this->button_Solve_root->Size = System::Drawing::Size(73, 23);
			this->button_Solve_root->TabIndex = 35;
			this->button_Solve_root->Text = L"Solve";
			this->button_Solve_root->UseVisualStyleBackColor = true;
			this->button_Solve_root->Visible = false;
			this->button_Solve_root->Click += gcnew System::EventHandler(this, &MyForm::button_Solve_root_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 490);
			this->Controls->Add(this->button_Solve_root);
			this->Controls->Add(this->label_n);
			this->Controls->Add(this->textBox_n);
			this->Controls->Add(this->label_put_abn);
			this->Controls->Add(this->label_put_abc_quadratic);
			this->Controls->Add(this->btn_Solve_quadratic);
			this->Controls->Add(this->btn_Solve);
			this->Controls->Add(this->textBox_g);
			this->Controls->Add(this->textBox_f);
			this->Controls->Add(this->textBox_d);
			this->Controls->Add(this->textBox_c);
			this->Controls->Add(this->textBox_b);
			this->Controls->Add(this->textBox_a);
			this->Controls->Add(this->label_g);
			this->Controls->Add(this->label_f);
			this->Controls->Add(this->label_d);
			this->Controls->Add(this->label_c);
			this->Controls->Add(this->label_b);
			this->Controls->Add(this->label_a);
			this->Controls->Add(this->label_put_abc);
			this->Controls->Add(this->btn_lyneal);
			this->Controls->Add(this->btn_root);
			this->Controls->Add(this->btn_quadratic);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textBox_a_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		char ch = e->KeyChar;
		if (ch == 45 && textBox_f->Text->IndexOf('-') != -1)
		{
			e->Handled = true;
			return;
		}

		if (ch == 46 && textBox_f->Text->IndexOf('.') != -1)
		{
			e->Handled = true;
			return;
		}

		if ((ch <= 47 || ch >= 58) && ch != 8 && ch != 45 && ch != 46)
		{
			e->Handled = true;
		}
	}
	private: System::Void textBox_b_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		char ch = e->KeyChar;
		if (ch == 45 && textBox_f->Text->IndexOf('-') != -1)
		{
			e->Handled = true;
			return;
		}

		if (ch == 46 && textBox_f->Text->IndexOf('.') != -1)
		{
			e->Handled = true;
			return;
		}

		if ((ch <= 47 || ch >= 58) && ch != 8 && ch != 45 && ch != 46)
		{
			e->Handled = true;
		}
	}
	private: System::Void textBox_c_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		char ch = e->KeyChar;
		if (ch == 45 && textBox_f->Text->IndexOf('-') != -1)
		{
			e->Handled = true;
			return;
		}

		if (ch == 46 && textBox_f->Text->IndexOf('.') != -1)
		{
			e->Handled = true;
			return;
		}

		if ((ch <= 47 || ch >= 58) && ch != 8 && ch != 45 && ch != 46)
		{
			e->Handled = true;
		}
	}
	private: System::Void textBox_d_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		char ch = e->KeyChar;
		if (ch == 45 && textBox_f->Text->IndexOf('-') != -1)
		{
			e->Handled = true;
			return;
		}

		if (ch == 46 && textBox_f->Text->IndexOf('.') != -1)
		{
			e->Handled = true;
			return;
		}

		if ((ch <= 47 || ch >= 58) && ch != 8 && ch != 45 && ch != 46)
		{
			e->Handled = true;
		}
	}
	private: System::Void textBox_f_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{		
		char ch = e->KeyChar;
		if (ch == 45 && textBox_f->Text->IndexOf('-') != -1)
		{
			e->Handled = true;
			return;
		}

		if (ch == 46 && textBox_f->Text->IndexOf('.') != -1)
		{
			e->Handled = true;
			return;
		}

		if ((ch <= 47 || ch >= 58) && ch != 8 && ch != 45 && ch != 46)
		{
			e->Handled = true;
		}		
	}
	private: System::Void textBox_g_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		char ch = e->KeyChar;
		if (ch == 45 && textBox_f->Text->IndexOf('-') != -1)
		{
			e->Handled = true;
			return;
		}

		if (ch == 46 && textBox_f->Text->IndexOf('.') != -1)
		{
			e->Handled = true;
			return;
		}

		if ((ch <= 47 || ch >= 58) && ch != 8 && ch != 45 && ch != 46)
		{
			e->Handled = true;
		}
	}
	private: System::Void textBox_n_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		char ch = e->KeyChar;
		if (ch == '.' || ch == '-')
		{
			e->Handled = true;
		}
		if ((ch <= 47 || ch >= 58) && ch != 8)
		{
			e->Handled = true;
		}
	}

	private: System::Void btn_lyneal_Click(System::Object^ sender, System::EventArgs^ e)
	{
		btn_lyneal->Visible = false;
		btn_quadratic->Visible = false;
		btn_root->Visible = false;
		label1->Visible = false;
		label_put_abc->Visible = true;
		label_a->Visible = true;
		label_b->Visible = true;
		label_c->Visible = true;
		label_d->Visible = true;
		label_f->Visible = true;
		label_g->Visible = true;

		textBox_a->Visible = true;
		textBox_b->Visible = true;
		textBox_c->Visible = true;
		textBox_d->Visible = true;
		textBox_f->Visible = true;
		textBox_g->Visible = true;

		btn_Solve->Visible = true;
	}

	private: System::Void btn_Solve_Click(System::Object^ sender, System::EventArgs^ e)
	{
		double* linear_equation = new double[1] { 0 };
		std::string a_str = msclr::interop::marshal_as<std::string>(textBox_a->Text);
		double a = std::stod(a_str);
		std::string b_str = msclr::interop::marshal_as<std::string>(textBox_b->Text);
		double b = std::stod(b_str);
		std::string c_str = msclr::interop::marshal_as<std::string>(textBox_c->Text);
		double c = std::stod(c_str);
		std::string d_str = msclr::interop::marshal_as<std::string>(textBox_d->Text);
		double d = std::stod(d_str);
		std::string f_str = msclr::interop::marshal_as<std::string>(textBox_f->Text);
		double f = std::stod(f_str);
		std::string g_str = msclr::interop::marshal_as<std::string>(textBox_g->Text);
		double g = std::stod(g_str);
		if (c == 0 && d == 0)
		{
			if (a == f && b == g)
			{
				critical_case(1);
			}
			else
			{
				critical_case(0);
			}
		}
		else
		{
			Solution_linear_equation(CComplex(a, b), CComplex(c, d), CComplex(f, g), linear_equation);
			printSolution(linear_equation, 1);
			record_points(linear_equation, 1);

			MyForm2^ MF2 = gcnew MyForm2();
			MF2->Show();
		}
		delete linear_equation;
	}

	private: System::Void btn_quadratic_Click(System::Object^ sender, System::EventArgs^ e)
	{
		btn_lyneal->Visible = false;
		btn_quadratic->Visible = false;
		btn_root->Visible = false;
		label1->Visible = false;
		label_put_abc_quadratic->Visible = true;
		label_a->Visible = true;
		label_b->Visible = true;
		label_c->Visible = true;
		label_d->Visible = true;
		label_f->Visible = true;
		label_g->Visible = true;

		textBox_a->Visible = true;
		textBox_b->Visible = true;
		textBox_c->Visible = true;
		textBox_d->Visible = true;
		textBox_f->Visible = true;
		textBox_g->Visible = true;

		btn_Solve_quadratic->Visible = true;
	}
	private: System::Void btn_Solve_quadratic_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int value_quadratic = 0;
		double* quadratic_equation = new double[4] { 0 };
		double** root_deg_n = new double* [2];
		for (int i = 0; i < 2; ++i)
		{
			root_deg_n[i] = new double[2] { 0 };
		}
		std::string a_str = msclr::interop::marshal_as<std::string>(textBox_a->Text);
		double a = std::stod(a_str);
		std::string b_str = msclr::interop::marshal_as<std::string>(textBox_b->Text);
		double b = std::stod(b_str);
		std::string c_str = msclr::interop::marshal_as<std::string>(textBox_c->Text);
		double c = std::stod(c_str);
		std::string d_str = msclr::interop::marshal_as<std::string>(textBox_d->Text);
		double d = std::stod(d_str);
		std::string f_str = msclr::interop::marshal_as<std::string>(textBox_f->Text);
		double f = std::stod(f_str);
		std::string g_str = msclr::interop::marshal_as<std::string>(textBox_g->Text);
		double g = std::stod(g_str);

		if (a == 0 && b == 0)
		{
			if (c == 0 && d == 0 && f == 0 && g == 0)
			{
				critical_case(1);
			}
			if (c == 0 && d == 0)
			{
				critical_case(0);
			}
		}
		else
		{
			if (c == 0 && d == 0)
			{
				Roots_deg_n(-CComplex(f, g) / CComplex(a, b), 2, root_deg_n);
				printSolutionRoot(root_deg_n, 2);
				record_points_root(root_deg_n, 2);
				MyForm2^ MF1 = gcnew MyForm2();
				MF1->Show();
			}
			else
			{
				if (f == 0 && g == 0)
				{
					quadratic_equation[0] = 0;
					quadratic_equation[1] = 0;
					quadratic_equation[2] = (-CComplex(c, d) / CComplex(a, b)).getRe();
					quadratic_equation[3] = (-CComplex(c, d) / CComplex(a, b)).getIm();
					printSolution(quadratic_equation, 2);
					record_points(quadratic_equation, 2);
					MyForm2^ MF1 = gcnew MyForm2();
					MF1->Show();
				}
				else
				{
					Solution_quadratic_equation(CComplex(a, b), CComplex(c, d), CComplex(f, g), quadratic_equation, value_quadratic);
					printSolution(quadratic_equation, value_quadratic);
					record_points(quadratic_equation, value_quadratic);
					MyForm2^ MF1 = gcnew MyForm2();
					MF1->Show();
				}
			}
		}
		delete quadratic_equation;
		delete root_deg_n;
	}

	private: System::Void btn_root_Click(System::Object^ sender, System::EventArgs^ e)
	{
		btn_lyneal->Visible = false;
		btn_quadratic->Visible = false;
		btn_root->Visible = false;
		label1->Visible = false;

		label_put_abn->Visible = true;

		label_a->Visible = true;
		label_b->Visible = true;
		label_n->Visible = true;

		textBox_a->Visible = true;
		textBox_b->Visible = true;
		textBox_n->Visible = true;

		button_Solve_root->Visible = true;
	}
	private: System::Void button_Solve_root_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::string n_str = msclr::interop::marshal_as<std::string>(textBox_n->Text);
		int n = std::stod(n_str);
		std::string a_str = msclr::interop::marshal_as<std::string>(textBox_a->Text);
		double a = std::stod(a_str);
		std::string b_str = msclr::interop::marshal_as<std::string>(textBox_b->Text);
		double b = std::stod(b_str);

		double** root_deg_n = new double* [abs(n)];
		for (int i = 0; i < abs(n); ++i)
		{
			root_deg_n[i] = new double[2] { 0 };
		}
		if (n == 0)
		{
			if (a == 1 && b == 0)
			{
				critical_case(1);
			}
			else
			{
				critical_case(0);
			}
		}
		else if (n < 0)
		{
			critical_case(-1);
		}
		else
		{
			Roots_deg_n(CComplex(a, b), n, root_deg_n);
			printSolutionRoot(root_deg_n, n);
			record_points_root(root_deg_n, n);

			MyForm2^ MF3 = gcnew MyForm2();
			MF3->Show();
		}
		delete root_deg_n;
	}
	};
}

