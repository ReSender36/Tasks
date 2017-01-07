//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "Project_Unit.h"
#include "TaskAlloc_ByProj_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTaskAlloc_ByProj_Form *TaskAlloc_ByProj_Form;
//---------------------------------------------------------------------------
__fastcall TTaskAlloc_ByProj_Form::TTaskAlloc_ByProj_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_ByProj_Form::DBGrid1DblClick(TObject *Sender)
{
	String pr_task_id = DBGrid1->SelectedField->AsString ;
	Projects_Form->FDCommand1->CommandText->Clear() ;
	String str_comm = String("update tasks set project = 1 where task_id = " + pr_task_id + " ;") ;
	Projects_Form->FDCommand1->CommandText->Add(str_comm) ;
	Projects_Form->FDCommand1->Execute() ;
	TaskAlloc_ByProj_Form->Close() ;// >Free() ;

}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_ByProj_Form::FormClose(TObject *Sender, TCloseAction &Action)

{
	Projects_Form->Enabled = true ;

	Projects_Form->DBGrid1->Enabled = false ;
	Projects_Form->DataSource1->Enabled = false ;
	Projects_Form->fdqMainDBG->Active = false ;

	Projects_Form->fdqMainDBG->Active = true ;
	Projects_Form->DataSource1->Enabled = true ;
	Projects_Form->DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_ByProj_Form::FormCreate(TObject *Sender)
{
	FDQuery1->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
	if(!tbtShowCompleted->Marked)
		StatusBar1->Panels->Items[0]->Text = String("Фильтр: Показывать все задачи") ;
	else
		StatusBar1->Panels->Items[0]->Text = String("Фильтр: Показывать только незавершенные задачи") ;

	Tasks_MainForm->FDQuery1->Active = false ;
	Tasks_MainForm->FDQuery1->SQL->Text = String("select task_source, caption from task_group ;") ;
	Tasks_MainForm->FDQuery1->Active = true ;

	Tasks_MainForm->FDQuery1->First() ;
	while(!Tasks_MainForm->FDQuery1->Eof){
		cbxFilterTaskGroup->AddItem(Tasks_MainForm->FDQuery1->FieldByName("caption")->AsString,
			(TObject*)Tasks_MainForm->FDQuery1->FieldByName("task_source")->AsInteger) ;
		Tasks_MainForm->FDQuery1->Next() ;
	}
	StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(FDQuery1->RecordCount) ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_ByProj_Form::tbtShowCompletedClick(TObject *Sender)
{
// пишем фильтр показывать или нет завершенные задачи
	if(!tbtShowCompleted->Marked){
		FDQuery1->Active = false ;
		FDQuery1->Filtered = false ;
		FDQuery1->Filter = String("task_percent != 100") ;
		FDQuery1->Filtered = true ;
		FDQuery1->Active = true ;
		tbtShowCompleted->Marked = true ;
		StatusBar1->Panels->Items[0]->Text = String("Фильтр: Показывать только незавершенные задачи") ;
		StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(FDQuery1->RecordCount) ;
	}
	else{
		FDQuery1->Active = false ;
		FDQuery1->Filtered = false ;
		FDQuery1->Active = true ;
		tbtShowCompleted->Marked = false ;
		StatusBar1->Panels->Items[0]->Text = String("Фильтр: Показывать все задачи") ;
		StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(FDQuery1->RecordCount) ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TTaskAlloc_ByProj_Form::edTaskIDChange(TObject *Sender)
{
	if ("" != edTaskID->Text) {
		DBGrid1->Enabled = false ;
		DataSource1->Enabled = false ;
		FDQuery1->Active = false ;
		String str_filter = String("task_id = " + edTaskID->Text) ;
		TLocateOptions SOptions;
		SOptions<<loCaseInsensitive<<loPartialKey;
		AnsiString t_id = edTaskID->Text ;
		FDQuery1->Active = true ;
		FDQuery1->Locate("task_id",t_id,SOptions) ;
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

void __fastcall TTaskAlloc_ByProj_Form::cbxFilterTaskGroupSelect(TObject *Sender)

{
	Tasks_MainForm->FDQuery1->Active = false ;
	Tasks_MainForm->FDQuery1->Filtered = false ;
	Tasks_MainForm->FDQuery1->SQL->Text = String("select task_source, caption from task_group ;") ;
	String task_source = String("caption = '"+cbxFilterTaskGroup->Text+"'") ;
	Tasks_MainForm->FDQuery1->Filter = task_source ;
	Tasks_MainForm->FDQuery1->Filtered = true ;
	Tasks_MainForm->FDQuery1->Active = true ;
	short ts = Tasks_MainForm->FDQuery1->FieldByName("task_source")->AsInteger ;

	FDQuery1->Active = false ;
 	FDQuery1->Filtered = false ;
	String task_filter = String("taskGrpID = " + String(ts) + "") ;
	FDQuery1->Filter = task_filter ;
	FDQuery1->Filtered = true ;
	FDQuery1->Active = true ;
	StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(FDQuery1->RecordCount) ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskAlloc_ByProj_Form::DBGrid1TitleClick(TColumn *Column)
{
	if (Column->FieldName == SortField){
		if (SortUp)
			FDQuery1->IndexFieldNames = Column->FieldName + ":D" ;
		else
			FDQuery1->IndexFieldNames = Column->FieldName ;
	}
	else{
		FDQuery1->IndexFieldNames = Column->FieldName ;
	}
	if (FDQuery1->IndexFieldNames == Column->FieldName)
		SortUp = true ;
	else
		SortUp = false ;

	SortField = Column->FieldName ;
}
//---------------------------------------------------------------------------

