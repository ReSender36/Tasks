//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "Project_Unit.h"
#include "ProjectDet_Unit.h"
#include "TaskAlloc_ByProj_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProjects_Form *Projects_Form;
short p_id = 0 ;
//---------------------------------------------------------------------------
__fastcall TProjects_Form::TProjects_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TProjects_Form::FormClose(TObject *Sender, TCloseAction &Action)
{
	Tasks_MainForm->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TProjects_Form::FormCreate(TObject *Sender)
{
	fdqMainDBG->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TProjects_Form::DBGrid1DblClick(TObject *Sender)
{
	p_id = DBGrid1->SelectedField->AsInteger ;
	Application->CreateForm(__classid(TProjectDet_Form), &ProjectDet_Form) ;
	ProjectDet_Form->Visible = true ;
	Projects_Form->Enabled = false ;
}
//---------------------------------------------------------------------------
void __fastcall TProjects_Form::ToolButton3Click(TObject *Sender)
{
	String det_task_id, str_comm = "" ;
	// прописать функцию вывода списка задач и назначения одной из них проектом
	p_id = DBGrid1->SelectedField->AsInteger ;
	String str = String("select pr_task_id from projects where pr_id = " + IntToStr(p_id) + " ;") ;
	fdqFindEnv->Active = false ;
	fdqFindEnv->SQL->Text = str ;
	fdqFindEnv->Active = true ;
	String pr_task_id = fdqFindEnv->FieldByName("pr_task_id")->AsString ;
	// очищаем задачи проекта
	fdqFindEnv->Active = false ;
	str = String("select task_id from tasks where parent = " + pr_task_id + " ;") ;
    fdqFindEnv->SQL->Text = str ;
	fdqFindEnv->Active = true ;

	fdqFindEnv->First() ;
	while(!fdqFindEnv->Eof){
		det_task_id = fdqFindEnv->FieldByName("task_id")->AsString ;
		FDCommand1->CommandText->Clear() ;
		str_comm = String("update tasks set parent = -1 where task_id = " + det_task_id + "") ;
		FDCommand1->CommandText->Add(str_comm) ;
		FDCommand1->Execute() ;
		fdqFindEnv->Next() ;
	}
	// удаляем задачу-проект из таблицы Projects
	str_comm = String("delete from projects where pr_id = " + IntToStr(p_id) + " ;") ;
	FDCommand1->CommandText->Clear() ;
	FDCommand1->CommandText->Add(str_comm) ;
//	FDCommand1->Execute() ;
	// устанавливаем в таблице tasks поле project = 0 у задачи проекта
	str_comm = String("update tasks set project = 0 where task_id = " + pr_task_id + " ;") ;
//	FDCommand1->CommandText->Clear() ;
	FDCommand1->CommandText->Add(str_comm) ;
	FDCommand1->Execute() ;
}
//---------------------------------------------------------------------------

void __fastcall TProjects_Form::ToolButton1Click(TObject *Sender)
{
	Application->CreateForm(__classid(TTaskAlloc_ByProj_Form), &TaskAlloc_ByProj_Form) ;
	TaskAlloc_ByProj_Form->Visible = true ;
	Projects_Form->Enabled = false ;
}
//---------------------------------------------------------------------------

void __fastcall TProjects_Form::DBGrid1TitleClick(TColumn *Column)
{
	if (Column->FieldName == SortField){
		if (SortUp)
			fdqMainDBG->IndexFieldNames = Column->FieldName + ":D" ;
		else
			fdqMainDBG->IndexFieldNames = Column->FieldName ;
	}
	else{
		fdqMainDBG->IndexFieldNames = Column->FieldName ;
	}
	if (fdqMainDBG->IndexFieldNames == Column->FieldName)
		SortUp = true ;
	else
		SortUp = false ;

	SortField = Column->FieldName ;
}
//---------------------------------------------------------------------------

