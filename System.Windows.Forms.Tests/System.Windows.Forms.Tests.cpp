// System.Windows.Forms.Tests.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Switch/Switch.Core"
#include "Switch/Switch.System"
#include "Switch/Switch.System.Core"
#include "Switch/Switch.System.Drawing"
#include "Switch/Switch.System.ServiceModel"
#include "Switch/Switch.System.Windows.Forms"
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Net::WebSockets;
using namespace System::Collections::Generic;
int main()
{
    Application::EnableVisualStyles();

    Button button;
    button.Text = "Click Me";
    button.Location = Point(10, 10);
    button.Click += delegate_(const object & sender, const EventArgs & e) {
        MessageBox::Show("Hello, World!");
        for (Int32 i = 0; i < 1024000; i++)
        {
            File::AppendAllText("aa.txt",i+"\r\n");
            button.Text = i+"";
        }
    };

    TextBox textbox;
    textbox.Text = "文本";
    textbox.Location = Point(10, 35);

    Form form;
    form.Text = "Hello World Form";
    form.Controls().Add(button);
    form.Controls().Add(textbox);

    Application::Run(form);
}