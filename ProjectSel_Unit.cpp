//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProjectSel_Unit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProjectSel_Form *ProjectSel_Form;
//---------------------------------------------------------------------------
__fastcall TProjectSel_Form::TProjectSel_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void RefreshForm()
{
	ProjectSel_Form->DBGrid1->Enabled = false ;
	ProjectSel_Form->DataSource1->Enabled = false ;
	ProjectSel_Form->FDQuery1->Active = false ;
	ProjectSel_Form->FDQuery1->Active = true ;
	ProjectSel_Form->DataSource1->Enabled = true ;
	ProjectSel_Form->DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TProjectSel_Form::DBGrid1DblClick(TObject *Sender)
{
	pr_id = DBGrid1->SelectedField->AsInteger ;

//    FDCommand1->CommandText->Clear()  ;
//	String comm = String("update tasks set parent = " + IntToStr(pr_id) + " where task_id = " + IntToStr(t_id) + " ;") ;
//	FDCommand1->CommandText->Add(comm) ;
//	FDCommand1->Execute() ;

	RefreshForm() ;
//	Edit1->Text = IntToStr(pr_id) ;
//	ProjectSel_Form->Visible = false ;
//	ProjectSel_Form->Close() ;
}
//---------------------------------------------------------------------------
void __fastcall TProjectSel_Form::FormClose(TObject *Sender, TCloseAction &Action)

{
	Tasks_MainForm->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TProjectSel_Form::FormCreate(TObject *Sender)
{
	FDQuery1->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
//	Edit1->Text = pr_id ;
}
//---------------------------------------------------------------------------
void __fastcall TProjectSel_Form::DBGrid1CellClick(TColumn *Column)
{
	pr_id = DBGrid1->SelectedField->AsInteger ;
 //	StatusBar1->Panels->Items[0]->Text = String("Выбран проект: ") + IntToStr(cnt) ;
}
//---------------------------------------------------------------------------

