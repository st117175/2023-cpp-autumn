#pragma once
#include <stdio.h>
#include <string>
#include "Header_Forms.h"
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button_draw;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button_draw = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->MarkerSize = 10;
			series1->Name = L"Series1";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series1->YValuesPerPoint = 2;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(534, 332);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// button_draw
			// 
			this->button_draw->Location = System::Drawing::Point(421, 52);
			this->button_draw->Name = L"button_draw";
			this->button_draw->Size = System::Drawing::Size(101, 65);
			this->button_draw->TabIndex = 1;
			this->button_draw->Text = L"Построить график";
			this->button_draw->UseVisualStyleBackColor = true;
			this->button_draw->Click += gcnew System::EventHandler(this, &MyForm2::button_draw_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 332);
			this->Controls->Add(this->button_draw);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button_draw_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->chart1->Series[0]->Points->Clear();
		int value = 0;
		this->chart1->Series[0]->CustomProperties = "IsXAxisQuantitative=True";
		value = Check_count();
		double** Points = new double* [value];
		for (int i = 0; i < value; ++i)
		{
			Points[i] = new double[2] { 0 };
		}
		ReadPoints(Points);
		for (int i = 0; i < value; ++i)
		{
			this->chart1->Series[0]->Points->AddXY(Points[i][0], Points[i][1]);
		}
	}
	};
}
