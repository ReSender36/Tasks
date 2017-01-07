//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "Project_Unit.h"
#include "ProjectDet_Unit.h"
#include "TaskToProj_Unit.h"
#include "TaskWrk_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProjectDet_Form *ProjectDet_Form;
short par_id, prior ;
//---------------------------------------------------------------------------
__fastcall TProjectDet_Form::TProjectDet_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TProjectDet_Form::FormClose(TObject *Sender, TCloseAction &Action)

{
	Projects_Form->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TProjectDet_Form::FormCreate(TObject *Sender)
{
	FDQuery1->Active = false ;
	FDQuery1->SQL->Text = String("select orig_id, caption from originates ;") ;
	FDQuery1->Active = true ;

	FDQuery1->First() ;
	while(!FDQuery1->Eof){
		ComboBox2->AddItem(FDQuery1->FieldByName("caption")->AsString,
			(TObject*)FDQuery1->FieldByName("orig_id")->AsInteger) ;
		FDQuery1->Next() ;
	}

	FDQuery1->Active = false ;
	FDQuery1->SQL->Text = String("select kind, caption from task_state ;") ;
	FDQuery1->Active = true ;

	FDQuery1->First() ;
	while(!FDQuery1->Eof){
		ComboBox1->AddItem(FDQuery1->FieldByName("caption")->AsString,
			(TObject*)FDQuery1->FieldByName("kind")->AsInteger) ;
		FDQuery1->Next() ;
	}

	FDQuery1->Active = false ;
	FDQuery1->SQL->Text = String("SELECT  p.pr_id, p.pr_task_id, t.task, p.pr_state, ts.caption AS pr_state_capt, p.originate, \
	o.caption, p.pr_priority, p.auto_calc_udweight, p.note, p.need_exp_sd, p.id_sd, p.short_pr_name \
	FROM projects p \
	inner JOIN tasks t ON t.task_id = p.pr_task_id \
	inner JOIN originates o ON o.orig_id = p.originate \
	inner JOIN task_state ts ON ts.kind = p.pr_state \
	where p.pr_id = " + IntToStr(p_id) + ";") ;
	FDQuery1->Active = true ;
//	String pr_task_id = FDQuery1->FieldByName("pr_task_id")->AsString ;
	par_id = FDQuery1->FieldByName("pr_task_id")->AsInteger ;
	Edit1->Text = FDQuery1->FieldByName("pr_id")->AsString ;
	edShortPrName->Text = FDQuery1->FieldByName("short_pr_name")->AsString ;
	Edit2->Text = FDQuery1->FieldByName("task")->AsString ;
	ComboBox1->Text = FDQuery1->FieldByName("pr_state_capt")->AsString ;
	ComboBox2->Text = FDQuery1->FieldByName("caption")->AsString ;
	prior = FDQuery1->FieldByName("pr_priority")->AsInteger ;
	if (NULL == prior) prior = 1 ;
	switch (prior){
		case 1: RadioButton1->Checked = true ; break ;
		case 2: RadioButton2->Checked = true ; break ;
		case 3: RadioButton3->Checked = true ; break ;
		default: RadioButton1->Checked = true ; break ;
	}
	CheckBox2->State = FDQuery1->FieldByName("auto_calc_udweight")->AsBoolean ;

	short task_len = Tasks_MainForm->check_length(Edit2->Text) ;
	Label5->Caption = String("Длина записи: " + IntToStr(task_len) + " из 80") ;
	if (80 < task_len){
		Label5->Font->Color = clRed ;
		Edit2->Font->Color = clRed ;
	}
	else{
		Label5->Font->Color = clWindowText ;
		Edit2->Font->Color = clWindowText ;
	}

	FDQuery1->Active = false ;
	FDQuery1->SQL->Text = String("SELECT COUNT(t.task_id) cnt_exec \
	FROM tasks t \
	where t.parent = " + IntToStr(par_id) + " and t.task_complete = 1 ;") ;
	FDQuery1->Active = true ;
	short cnt_exec = FDQuery1->FieldByName("cnt_exec")->AsInteger ;

	FDQuery1->Active = false ;
	FDQuery1->SQL->Text = String("SELECT COUNT(t.task_id) cnt_total \
	FROM tasks t \
	where t.parent = " + IntToStr(par_id) + " ;") ;
	FDQuery1->Active = true ;
	short cnt_total = FDQuery1->FieldByName("cnt_total")->AsInteger ;
	Edit6->Text = String(IntToStr(cnt_total) + "/" + IntToStr(cnt_exec)) ;

	fdqTasksInProj->Active = false ;
	fdqTasksInProj->Filtered = false ;
	fdqTasksInProj->Filter = String("parent = " + IntToStr(par_id) + "") ;
	fdqTasksInProj->Filtered = true ;
	fdqTasksInProj->Active = true ;
//	fdqTasksInProj->First() ;
//	while(!fdqTasksInProj->Eof){
//		if (fdqTasksInProj->FieldByName("task_complete")->AsBoolean) {
//			DBGrid1->Canvas->Font->Color = clRed ;
//		}
//		fdqTasksInProj->Next() ;
//	}
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;

}
//---------------------------------------------------------------------------

void __fastcall TProjectDet_Form::Edit2Change(TObject *Sender)
{
	short task_len = Tasks_MainForm->check_length(Edit2->Text) ;
	Label5->Caption = String("Длина записи: " + IntToStr(task_len) + " из 80") ;
	if (80 < task_len){
		Label5->Font->Color = clRed ;
		Edit2->Font->Color = clRed ;
	}
	else{
		Label5->Font->Color = clWindowText ;
		Edit2->Font->Color = clWindowText ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TProjectDet_Form::ToolButton1Click(TObject *Sender)
{
//	par_id = DBGrid1->SelectedField->AsInteger ;
	Application->CreateForm(__classid(TTaskToProj_Form), &TaskToProj_Form) ;

//	task_id = StrToInt(Edit1->Text) ;
	TaskToProj_Form->Visible = true ;
	ProjectDet_Form->Enabled = false ;
}
//---------------------------------------------------------------------------

void __fastcall TProjectDet_Form::ToolButton4Click(TObject *Sender)
{
	short t_id = DBGrid1->SelectedField->AsInteger ;
    FDCommand1->CommandText->Clear()  ;
	String comm = String("update tasks set parent = '-1' where task_id = " + IntToStr(t_id) + " ;") ;
	FDCommand1->CommandText->Add(comm) ;
	FDCommand1->Execute() ;

	DBGrid1->Enabled = false ;
	DataSource1->Enabled = false ;
	fdqTasksInProj->Active = false ;
	fdqTasksInProj->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TProjectDet_Form::DBGrid1EditButtonClick(TObject *Sender)
{
//	Edit6->Text = DBGrid1->SelectedField->AsString ;
//	Edit6->Text = DBGrid1->SelectedField->DisplayName ;
	if ("task_id" == DBGrid1->SelectedField->DisplayName) {
		String t_id = DBGrid1->SelectedField->AsString ;
        FDQuery1->Active = false ;
		FDQuery1->Filtered = false ;
		FDQuery1->SQL->Text = String("select task_percent from tasks t where t.task_id = " + t_id + " ;") ;
		FDQuery1->Active = true ;
		String perc_comp = FDQuery1->FieldByName("task_percent")->AsString ;

		Application->CreateForm(__classid(TTaskWrk_Form), &TaskWrk_Form) ;
//		TaskWrk_Form->Visible = true ;
//		Tasks_MainForm->Enabled = false ;
		TaskWrk_Form->Edit1->Text = perc_comp ;
		TaskWrk_Form->DateTimePicker1->Date = TDateTime::CurrentDate() ;
		if(TaskWrk_Form->ShowModal() == bkOK){

			String perc = TaskWrk_Form->Edit1->Text ;
			TDateTime task_exec = TaskWrk_Form->DateTimePicker1->Date ;
			String task_exec_str = "" ;
			String t_id_str = t_id ;
			Tasks_MainForm->conv_date(&task_exec, &task_exec_str) ;
			String comm = String("insert into task_execdate(task_id,exec_date,percent_complete) values(" + t_id + "," + task_exec_str + ",'" + perc + "') ;") ;
			FDCommand1->CommandText->Add(comm) ;
// 			FDCommand1->Execute() ;
			if ("100" == perc)
				comm = String("update tasks set planned_date = '2009-01-01', complete_date = " + task_exec_str + ", task_percent = " + perc + ", task_complete = 1 where task_id = " + t_id + " ;") ;
			else
				comm = String("update tasks set planned_date = ADDDATE(CURRENT_DATE(),1), task_percent = " + perc + ", task_complete = 0 where task_id = " + t_id + " ;") ;

			FDCommand1->CommandText->Add(comm) ;
			FDCommand1->Execute() ;

		}
		DBGrid1->Enabled = false ;
		DataSource1->Enabled = false ;
		DataSource1->Enabled = true ;
        DBGrid1->Enabled = true ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TProjectDet_Form::BitBtn1Click(TObject *Sender)
{
	String str_comm ;
// статус задачи
	FDQuery1->Active = false ;
	FDQuery1->Filtered = false ;
	FDQuery1->SQL->Text = String("select kind, caption from task_state ;") ;
	FDQuery1->Filter = String("caption = '" + ComboBox1->Text + "'") ;
	FDQuery1->Filtered = true ;
	FDQuery1->Active = true ;
	short task_state = FDQuery1->FieldByName("kind")->AsInteger ;

// источник задачи
	FDQuery1->Active = false ;
	FDQuery1->Filtered = false ;
	FDQuery1->SQL->Text = String("select orig_id, caption from originates ;") ;
	FDQuery1->Filter = String("caption = '" + ComboBox2->Text + "'") ;
	FDQuery1->Filtered = true ;
	FDQuery1->Active = true ;
	short task_orig = FDQuery1->FieldByName("orig_id")->AsInteger ;
//    prior ;
	String note = Memo1->Lines->Text ;
	short pr_toSD = CheckBox1->State ;
	String id_inSD = Edit4->Text ;
	if ("" == id_inSD) {
		id_inSD = "0" ;
	}
	String prShortName = edShortPrName->Text ;
/*
pr_id,
pr_task_id,
pr_state,
originate,
pr_priority,
auto_calc_udweight,
note,
need_exp_sd,
id_sd
*/
	short autoCalcWeight = CheckBox2->State ;
	if (0 != p_id) {
		str_comm = String("update projects set \
		pr_state = " + IntToStr(task_state) + ",\
		originate = " + IntToStr(task_orig) + ",\
		pr_priority = " + IntToStr(prior) + ",\
		auto_calc_udweight = " + IntToStr(autoCalcWeight) + ",\
		note = '" + note + "',\
		need_exp_sd = " + pr_toSD + ",\
		id_sd = " + id_inSD + ", \
		short_pr_name = '" + prShortName + "' \
		where pr_id = " + IntToStr(p_id) + " ;") ;
		FDCommand1->CommandText->Clear() ;
		FDCommand1->CommandText->Add(str_comm) ;
		try{
			FDCommand1->Execute() ;
			ProjectDet_Form->Close() ;

        }
		catch(...){

		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TProjectDet_Form::RadioButtonClick(TObject *Sender)
{
	if(RadioButton1->Checked)
		prior = 1 ;
	if(RadioButton2->Checked)
		prior = 2 ;
	if(RadioButton3->Checked)
		prior = 3 ;
}
//---------------------------------------------------------------------------

void __fastcall TProjectDet_Form::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)
		Edit4->Enabled = true ;
	else
		Edit4->Enabled = false ;
}
//---------------------------------------------------------------------------

void __fastcall TProjectDet_Form::ToolButton3Click(TObject *Sender)
{
	short pers_rd = 0 ;
	double uw = 0 ;
	double pr_ready = 0 ;
	fdqTasksInProj->Active = false ;
	fdqTasksInProj->Filter = String("parent = " + IntToStr(par_id) + "") ;
	fdqTasksInProj->Filtered = true ;
	fdqTasksInProj->Active = true ;
	fdqTasksInProj->First() ;
	while(!fdqTasksInProj->Eof){
		uw = fdqTasksInProj->FieldByName("ud_weight_in_project")->AsFloat ;
		pers_rd = fdqTasksInProj->FieldByName("task_percent")->AsInteger ;
		pr_ready = pr_ready + (uw / 100) * pers_rd ;
		fdqTasksInProj->Next() ;
	}
	Edit5->Text = String(pr_ready) ;

	FDQuery1->Filtered = false ;
	FDQuery1->Active = false ;
	FDQuery1->SQL->Text = String("SELECT COUNT(t.task_id) cnt_exec \
	FROM tasks t \
	where t.parent = " + IntToStr(par_id) + " and t.task_complete = 1 ;") ;
	FDQuery1->Active = true ;
	short cnt_exec = FDQuery1->FieldByName("cnt_exec")->AsInteger ;

	FDQuery1->Active = false ;
	FDQuery1->SQL->Text = String("SELECT COUNT(t.task_id) cnt_total \
	FROM tasks t \
	where t.parent = " + IntToStr(par_id) + " ;") ;
	FDQuery1->Active = true ;
	short cnt_total = FDQuery1->FieldByName("cnt_total")->AsInteger ;
	Edit6->Text = String(IntToStr(cnt_total) + "/" + IntToStr(cnt_exec)) ;
}
//---------------------------------------------------------------------------

void __fastcall TProjectDet_Form::DBGrid1CellClick(TColumn *Column)
{
 //	Edit6->Text = DBGrid1->SelectedRows-> ;// >DisplayName ;//()->AsString ;// >AsString ;
}
//---------------------------------------------------------------------------


void __fastcall TProjectDet_Form::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
	if (fdqTasksInProj->FieldByName("task_complete")->AsBoolean/* && Column->FieldName == "task_complete"*/) {
		DBGrid1->Canvas->Font->Color = clRed ;
//		DBGrid1->Canvas->FillRect(Rect) ;
//		DBGrid1->Canvas->TextOut(Rect.Left + 7 , Rect.Top + 2, Column->Field->Text) ;
//		DBGrid1->Canvas->TextOutW(Rect.Right - 7 - DBGrid1->Canvas->TextWidth(Column->Field->Text), Rect.Top + 2, Column->Field->Text) ;
        DBGrid1->DefaultDrawColumnCell(Rect,DataCol,Column,State) ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TProjectDet_Form::edShortPrNameChange(TObject *Sender)
{
	short task_len = Tasks_MainForm->check_length(edShortPrName->Text) ;
	Label11->Caption = String("Длина записи: " + IntToStr(task_len) + " из 40") ;
	if (40 < task_len){
		Label11->Font->Color = clRed ;
		edShortPrName->Font->Color = clRed ;
	}
	else{
		Label11->Font->Color = clWindowText ;
		edShortPrName->Font->Color = clWindowText ;
	}
}
//---------------------------------------------------------------------------


