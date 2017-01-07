//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "TaskRepeat_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTaskRepeat_Form *TaskRepeat_Form;
//---------------------------------------------------------------------------
__fastcall TTaskRepeat_Form::TTaskRepeat_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTaskRepeat_Form::FormCreate(TObject *Sender)
{
	short task_len = Tasks_MainForm->check_length(edTask->Text);
	lbTaskLength->Caption = String("Длина записи: " + IntToStr(task_len) + " из 80");
	if (80 < task_len) {
		lbTaskLength->Font->Color = clRed;
		edTask->Font->Color = clRed;
		// sscanf(str, "%254s", str) ;
		// char *str_row = AnsiString(Edit6->Text).c_str() ;
		// char *str2_row = "" ;
		// strncpy(str2_row,str_row,80) ;
		// edTask->Text = String(str2_row) ;
		}
}
//---------------------------------------------------------------------------
void __fastcall TTaskRepeat_Form::edTaskChange(TObject *Sender)
{
	short task_len = Tasks_MainForm->check_length(edTask->Text) ;
	lbTaskLength->Caption = String("Длина записи: " + IntToStr(task_len) + " из 80") ;
	if (80 < task_len){
		lbTaskLength->Font->Color = clRed ;
		edTask->Font->Color = clRed ;
	}
	else{
		lbTaskLength->Font->Color = clWindowText ;
		edTask->Font->Color = clWindowText ;
	}
}
//---------------------------------------------------------------------------
