//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TaskWrk_Unit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTaskWrk_Form *TaskWrk_Form;
String pers_complete ;
//---------------------------------------------------------------------------
__fastcall TTaskWrk_Form::TTaskWrk_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTaskWrk_Form::FormClose(TObject *Sender, TCloseAction &Action)
{
	Tasks_MainForm->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskWrk_Form::FormCreate(TObject *Sender)
{
//	Edit1->Text = perc_comp ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskWrk_Form::CheckBox1Click(TObject *Sender)
{
	if (true == CheckBox1->Checked) {
		Edit1->Text = "100" ;
		Edit1->ReadOnly = true ;
	}
	else{
		Edit1->Text = pers_complete ;
		Edit1->ReadOnly = false ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TTaskWrk_Form::Edit1Change(TObject *Sender)
{
	pers_complete = Edit1->Text;
}
//---------------------------------------------------------------------------

