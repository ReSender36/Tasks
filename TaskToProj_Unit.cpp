//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "ProjectDet_Unit.h"
#include "TaskToProj_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTaskToProj_Form *TaskToProj_Form;
//---------------------------------------------------------------------------
__fastcall TTaskToProj_Form::TTaskToProj_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void RefreshForm()
{
	TaskToProj_Form->DBGrid1->Enabled = false ;
	TaskToProj_Form->DataSource1->Enabled = false ;
	TaskToProj_Form->FDQuery1->Active = false ;
	TaskToProj_Form->FDQuery1->Active = true ;
	TaskToProj_Form->DataSource1->Enabled = true ;
	TaskToProj_Form->DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskToProj_Form::DBGrid1DblClick(TObject *Sender)
{
	short t_id = DBGrid1->SelectedField->AsInteger ;
    FDCommand1->CommandText->Clear()  ;
	String comm = String("update tasks set parent = " + IntToStr(par_id) + " where task_id = " + IntToStr(t_id) + " ;") ;
	FDCommand1->CommandText->Add(comm) ;
	FDCommand1->Execute() ;

 //	RefreshForm() ;

	DBGrid1->SelectedIndex = 215 ; // >Refresh() ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskToProj_Form::FormClose(TObject *Sender, TCloseAction &Action)

{
	ProjectDet_Form->DBGrid1->Enabled = false ;
	ProjectDet_Form->DataSource1->Enabled = false ;
	ProjectDet_Form->fdqTasksInProj->Active = false ;
	ProjectDet_Form->fdqTasksInProj->Active = true ;
	ProjectDet_Form->DataSource1->Enabled = true ;
	ProjectDet_Form->DBGrid1->Enabled = true ;

	ProjectDet_Form->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskToProj_Form::FormCreate(TObject *Sender)
{
	TaskToProj_Form->Caption = String("Задача в проект " + IntToStr(par_id)) ;

//	FDQuery1->Active = true ;
	FDTable1->SQL->Text = String("SELECT t.task_id, t.parent, t.task, t.task_percent  FROM tasks t where project = 0 ;") ;
	FDTable1->TableName = "tasks" ;
	FDTable1->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskToProj_Form::ToolButton2Click(TObject *Sender)
{
	RefreshForm() ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskToProj_Form::edTaskIDChange(TObject *Sender)
{
	if ("" != edTaskID->Text) {
		DBGrid1->Enabled = false ;
		DataSource1->Enabled = false ;
		FDQuery1->Active = false ;
		String str_filter = String("task_id = " + edTaskID->Text) ;
		TLocateOptions SOptions;
		SOptions<<loCaseInsensitive<<loPartialKey;
//		Variant locvalues[3];
		AnsiString t_id = edTaskID->Text ;
//		locvalues[0] = Variant(t_id.c_str());
		FDTable1->Locate("task_id",t_id,SOptions) ;
//		FDQuery1->Active = true ;
		DataSource1->Enabled = true ;
		DBGrid1->Enabled = true ;
	}
	else{
		DBGrid1->Enabled = false ;
		DataSource1->Enabled = false ;
		FDQuery1->Active = false ;
		FDQuery1->Filtered = false ;
		FDQuery1->Active = true ;
		DataSource1->Enabled = true ;
		DBGrid1->Enabled = true ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TTaskToProj_Form::DBGrid1TitleClick(TColumn *Column)
{
	if (Column->FieldName == SortField){
		if (SortUp)
			FDTable1->IndexFieldNames = Column->FieldName + ":D" ;
		else
			FDTable1->IndexFieldNames = Column->FieldName ;
	}
	else{
		FDTable1->IndexFieldNames = Column->FieldName ;
	}
	if (FDTable1->IndexFieldNames == Column->FieldName)
		SortUp = true ;
	else
		SortUp = false ;

	SortField = Column->FieldName ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskToProj_Form::tbtShowCompletedClick(TObject *Sender)
{
// пишем фильтр показывать или нет завершенные задачи
	if(!tbtShowCompleted->Marked){
		FDTable1->Active = false ;
		FDTable1->Filtered = false ;
		FDTable1->Filter = String("task_percent != 100") ;
		FDTable1->Filtered = true ;
		FDTable1->Active = true ;
		tbtShowCompleted->Marked = true ;
		StatusBar1->Panels->Items[0]->Text = String("Фильтр: Показывать только незавершенные задачи") ;
	}
	else{
		FDTable1->Active = false ;
		FDTable1->Filtered = false ;
//		FDTable1->Filter = String("task_percent = 100") ;
//		FDTable1->Filtered = true ;
		FDTable1->Active = true ;
		tbtShowCompleted->Marked = false ;
		StatusBar1->Panels->Items[0]->Text = String("Фильтр: Показывать все задачи") ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TTaskToProj_Form::FormResize(TObject *Sender)
{
//	DBGrid1->Width = TaskToProj_Form->Width - 5 ;
}
//---------------------------------------------------------------------------

