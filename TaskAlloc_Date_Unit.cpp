//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "TaskAlloc_Date_Unit.h"
#include "SelectDate_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTaskAlloc_Date *TaskAlloc_Date;
//---------------------------------------------------------------------------
__fastcall TTaskAlloc_Date::TTaskAlloc_Date(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_Date::FormClose(TObject *Sender, TCloseAction &Action)

{
	Tasks_MainForm->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_Date::FormCreate(TObject *Sender)
{
	FDQuery1->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskAlloc_Date::N3Click(TObject *Sender)
{
	short t_id = DBGrid1->SelectedField->AsInteger ;
	FDCommand1->CommandText->Clear() ;
	Application->CreateForm(__classid(TSelectDate_Form), &SelectDate_Form) ;

	if(SelectDate_Form->ShowModal() == bkOK){
		TDateTime pl_date = SelectDate_Form->DateTimePicker1->Date ;
		String pl_date_str, comm ;
		Tasks_MainForm->conv_date(&pl_date, &pl_date_str) ;
		comm = String("update tasks set planned_date = " + pl_date_str + " where task_id = " + IntToStr(t_id) + " ;") ;
		FDCommand1->CommandText->Add(comm) ;
		try{
			FDCommand1->Execute() ;
        }
		catch(...){
		}
		FDQuery1->Active = false ;
		DataSource1->Enabled = false ;
		DBGrid1->Enabled = false ;
		FDQuery1->Active = true ;
		DataSource1->Enabled = true ;
		DBGrid1->Enabled = true ;
	}
}
//---------------------------------------------------------------------------


void __fastcall TTaskAlloc_Date::DBGrid1CellClick(TColumn *Column)
{
//	Edit1->Text = DBGrid1->SelectedField->AsString ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskAlloc_Date::N1Click(TObject *Sender)
{
	short t_id = DBGrid1->SelectedField->AsInteger ;
	FDCommand1->CommandText->Clear() ;
	String comm = String("update tasks set planned_date = current_date() where task_id = " + IntToStr(t_id) + " ;") ;
	FDCommand1->CommandText->Add(comm) ;
	try{
		FDCommand1->Execute() ;
	}
	catch(...){
	}
	FDQuery1->Active = false ;
	DataSource1->Enabled = false ;
	DBGrid1->Enabled = false ;
	FDQuery1->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskAlloc_Date::N2Click(TObject *Sender)
{
	short t_id = DBGrid1->SelectedField->AsInteger ;
	FDCommand1->CommandText->Clear() ;
	String comm = String("update tasks set planned_date = ADDDATE(CURRENT_DATE(),1) where task_id = " + IntToStr(t_id) + " ;") ;
	FDCommand1->CommandText->Add(comm) ;
	try{
		FDCommand1->Execute() ;
   }
	catch(...){
	}
	FDQuery1->Active = false ;
	DataSource1->Enabled = false ;
	DBGrid1->Enabled = false ;
	FDQuery1->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskAlloc_Date::N4Click(TObject *Sender)
{
	short t_id = DBGrid1->SelectedField->AsInteger ;
	FDCommand1->CommandText->Clear() ;
	String comm = String("update tasks set planned_date = DATE(CONCAT(EXTRACT(YEAR FROM CURRENT_DATE()),""-12-31"")) where task_id = " + IntToStr(t_id) + " ;") ;
	FDCommand1->CommandText->Add(comm) ;
	try{
		FDCommand1->Execute() ;
   }
	catch(...){
	}
	FDQuery1->Active = false ;
	DataSource1->Enabled = false ;
	DBGrid1->Enabled = false ;
	FDQuery1->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskAlloc_Date::DBGrid1TitleClick(TColumn *Column)
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

void __fastcall TTaskAlloc_Date::tbtShowCompletedClick(TObject *Sender)
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
	}
	else{
		FDQuery1->Active = false ;
		FDQuery1->Filtered = false ;
//		FDTable1->Filter = String("task_percent = 100") ;
//		FDTable1->Filtered = true ;
		FDQuery1->Active = true ;
		tbtShowCompleted->Marked = false ;
		StatusBar1->Panels->Items[0]->Text = String("Фильтр: Показывать все задачи") ;
	}
}
//---------------------------------------------------------------------------

