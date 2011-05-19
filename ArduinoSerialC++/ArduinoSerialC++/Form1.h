#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//openCV includes
#include <cv.h>
#include <highgui.h>

using namespace std;

#pragma once


namespace ArduinoSerialC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
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
	private: System::IO::Ports::SerialPort^  ArduinoSerial;
	private: System::Windows::Forms::Button^  SendSerial;
	private: System::Windows::Forms::TrackBar^  servoX;
	private: System::Windows::Forms::TrackBar^  servoY;






	protected: 

	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->ArduinoSerial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->SendSerial = (gcnew System::Windows::Forms::Button());
			this->servoX = (gcnew System::Windows::Forms::TrackBar());
			this->servoY = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->servoX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->servoY))->BeginInit();
			this->SuspendLayout();
			// 
			// SendSerial
			// 
			this->SendSerial->Location = System::Drawing::Point(195, 12);
			this->SendSerial->Name = L"SendSerial";
			this->SendSerial->Size = System::Drawing::Size(75, 23);
			this->SendSerial->TabIndex = 0;
			this->SendSerial->Text = L"SendData!";
			this->SendSerial->UseVisualStyleBackColor = true;
			this->SendSerial->Click += gcnew System::EventHandler(this, &Form1::SendSerial_Click);
			// 
			// servoX
			// 
			this->servoX->Location = System::Drawing::Point(12, 12);
			this->servoX->Maximum = 180;
			this->servoX->Name = L"servoX";
			this->servoX->Size = System::Drawing::Size(177, 45);
			this->servoX->TabIndex = 1;
			this->servoX->TickStyle = System::Windows::Forms::TickStyle::None;
			// 
			// servoY
			// 
			this->servoY->Location = System::Drawing::Point(12, 40);
			this->servoY->Maximum = 180;
			this->servoY->Name = L"servoY";
			this->servoY->Size = System::Drawing::Size(177, 45);
			this->servoY->TabIndex = 2;
			this->servoY->TickStyle = System::Windows::Forms::TickStyle::None;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(295, 75);
			this->Controls->Add(this->servoY);
			this->Controls->Add(this->servoX);
			this->Controls->Add(this->SendSerial);
			this->MinimumSize = System::Drawing::Size(207, 82);
			this->Name = L"Form1";
			this->Text = L"The Program!";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->servoX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->servoY))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SendSerial_Click(System::Object^  sender, System::EventArgs^  e) {      
				this->ArduinoSerial->PortName = "COM7";  // Replace with your COM port!
				this->ArduinoSerial->Open();
				this->ArduinoSerial->Write((this->servoX->Value));
				this->ArduinoSerial->Write((this->servoY->Value));
				this->ArduinoSerial->Close();
				//declare for the height and width of the image
				int height = 320;
				int width = 240;
				//specify the point to place the text
				CvPoint pt = cvPoint( height/4, width/2 );
				//Create an 8 bit, 3 plane image
				IplImage* hw = cvCreateImage(cvSize(height, width), 8, 3);
				//initialize the font
				CvFont font;
				cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,
					1.0, 1.0, 0, 1, CV_AA);
				//place the text on the image using the font
				cvPutText(hw, "Hello World", pt, &font, CV_RGB(150, 0, 0) );
				//create the window container
				cvNamedWindow("Hello World", 0);
				//display the image in the container
				cvShowImage("Hello World", hw);
				//hold the output windows
				cvWaitKey(0);
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}

