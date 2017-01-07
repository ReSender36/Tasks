//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "TaskDet_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTask_Detail *Task_Detail;
short t_priority ;
//---------------------------------------------------------------------------
__fastcall TTask_Detail::TTask_Detail(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
short check_length(AnsiString row)
{
//	AnsiString row = Edit2->Text ;
	char *str_row = row.c_str() ;
	int q = strlen(str_row) ;
//	Label8->Caption = "Заметка (длина " + IntToStr(q) + ") из 254" ;

	return q ;
}
//---------------------------------------------------------------------------
void __fastcall TTask_Detail::FormClose(TObject *Sender, TCloseAction &Action)
{
	Tasks_MainForm->Enabled = true ;
}
//---------------------------------------------------------------------------
void submit_combs()
{
	Task_Detail->FDQuery1->Active = false ;
	Task_Detail->FDQuery1->SQL->Text = String("select task_source, caption from task_group ;") ;
	Task_Detail->FDQuery1->Active = true ;

	Task_Detail->FDQuery1->First() ;
	while(!Task_Detail->FDQuery1->Eof){
		Task_Detail->ComboBox1->AddItem(Task_Detail->FDQuery1->FieldByName("caption")->AsString,
			(TObject*)Task_Detail->FDQuery1->FieldByName("task_source")->AsInteger) ;
		Task_Detail->FDQuery1->Next() ;
	}

	Task_Detail->FDQuery1->Active = false ;
	Task_Detail->FDQuery1->SQL->Text = String("select orig_id, caption from originates ;") ;
	Task_Detail->FDQuery1->Active = true ;

	Task_Detail->FDQuery1->First() ;
	while(!Task_Detail->FDQuery1->Eof){
		Task_Detail->ComboBox2->AddItem(Task_Detail->FDQuery1->FieldByName("caption")->AsString,
			(TObject*)Task_Detail->FDQuery1->FieldByName("orig_id")->AsInteger) ;
		Task_Detail->FDQuery1->Next() ;
	}

	Task_Detail->FDQuery1->Active = false ;
	Task_Detail->FDQuery1->SQL->Text = String("select kind, caption from task_state ;") ;
	Task_Detail->FDQuery1->Active = true ;

	Task_Detail->FDQuery1->First() ;
	while(!Task_Detail->FDQuery1->Eof){
		Task_Detail->ComboBox3->AddItem(Task_Detail->FDQuery1->FieldByName("caption")->AsString,
			(TObject*)Task_Detail->FDQuery1->FieldByName("kind")->AsInteger) ;
		Task_Detail->FDQuery1->Next() ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TTask_Detail::FormCreate(TObject *Sender) {
	if (0 != t_id) {
		submit_combs();
		// short t_id = 131 ;
		FDQuery1->Active = false;
		FDQuery1->SQL->Text = String("select bt.task_id, bt.priority, bt.task, bt.task_grp, bt.caption, bt.note, \
	bt.need_exp_sd, bt.id_sd, bt.project, bt.task_st, bt.parent, bt.task_percent, bt.task_complete, bt.task_repeat, \
	bt.task_started, bt.planned_date, bt.project_name, bt.ud_weight_in_project, bt.order_in_project, bt.extend_mission \
	FROM base_taskview bt \
	WHERE bt.task_id = " + String(t_id) + " ;");
		FDQuery1->Active = true;

		Edit5->Text = FDQuery1->FieldByName("task_id")->AsInteger;
		Edit6->Text = FDQuery1->FieldByName("task")->AsString;
		short parent = FDQuery1->FieldByName("parent")->AsInteger ;
		short task_len = check_length(Edit6->Text);
		Label10->Caption =
			String("Длина записи: " + IntToStr(task_len) + " из 80");
		if (80 < task_len) {
			Label10->Font->Color = clRed;
			Edit6->Font->Color = clRed;
			// sscanf(str, "%254s", str) ;

			// char *str_row = AnsiString(Edit6->Text).c_str() ;
			// char *str2_row = "" ;
			// strncpy(str2_row,str_row,80) ;
			// Edit6->Text = String(str2_row) ;
		}
		short prior = FDQuery1->FieldByName("priority")->AsInteger;
		if (NULL == prior)
			prior = 1;

		switch (prior) {
		case 1:
			RadioButton1->Checked = true;
			break;
		case 2:
			RadioButton2->Checked = true;
			break;
		case 3:
			RadioButton3->Checked = true;
			break;
		case 4:
			RadioButton4->Checked = true;
			break;
		case 5:
			RadioButton5->Checked = true;
			break;
		default:
			RadioButton1->Checked = true;
			break;
		}
		ComboBox1->Text = FDQuery1->FieldByName("task_grp")->AsString;
		ComboBox2->Text = FDQuery1->FieldByName("caption")->AsString;
		ComboBox3->Text = FDQuery1->FieldByName("task_st")->AsString;
		Edit7->Text = FDQuery1->FieldByName("task_percent")->AsString;

		Memo1->Lines->Add(FDQuery1->FieldByName("note")->AsString);
		Edit1->Text = FDQuery1->FieldByName("id_sd")->AsString;
		DateTimePicker1->Date = FDQuery1->FieldByName("planned_date")->AsDateTime;
		DateTimePicker2->Date = FDQuery1->FieldByName("task_started")->AsDateTime;
		CheckBox1->State = FDQuery1->FieldByName("need_exp_sd")->AsBoolean;
		cbTaskRepeat->State = FDQuery1->FieldByName("task_repeat")->AsBoolean ;
		CheckBox3->State = FDQuery1->FieldByName("project")->AsBoolean;
		CheckBox4->State = FDQuery1->FieldByName("extend_mission")->AsBoolean;
		if (-1 == parent){
			GroupBox1->Enabled = false ;
		}
		else
			CheckBox1->Checked = 1 ;
		if (CheckBox1->Checked)
			Edit1->Enabled = true ;
		else
			Edit1->Enabled = false ;
		Edit2->Text = FDQuery1->FieldByName("project_name")->AsString ;
		Edit3->Text = FDQuery1->FieldByName("order_in_project")->AsString ;
		Edit4->Text = FDQuery1->FieldByName("ud_weight_in_project")->AsString ;

		fdqTasksExec->Active = false;
		fdqTasksExec->SQL->Text =
			String("SELECT te.task_id, te.exec_date, te.percent_complete from task_execdate te where te.task_id = " +
			String(t_id) + " ;");
		fdqTasksExec->Active = true;
		DataSource1->Enabled = true;
		DBGrid1->Enabled = true;
	}
	else {
		submit_combs();
		Edit5->Enabled = false ;
		DateTimePicker1->Date = TDateTime::CurrentDate() ;
        DateTimePicker2->Date = TDateTime::CurrentDate() ;
	}
}
// ---------------------------------------------------------------------------
void __fastcall TTask_Detail::RadioButtonClick(TObject *Sender)
{
	if(RadioButton1->Checked) t_priority = 1 ;
	if(RadioButton2->Checked) t_priority = 2 ;
	if(RadioButton3->Checked) t_priority = 3 ;
	if(RadioButton4->Checked) t_priority = 4 ;
	if(RadioButton5->Checked) t_priority = 5 ;
}
//---------------------------------------------------------------------------

void __fastcall TTask_Detail::Edit6Change(TObject *Sender)
{
	short task_len = check_length(Edit6->Text) ;
	Label10->Caption = String("Длина записи: " + IntToStr(task_len) + " из 80") ;
	if (80 < task_len){
		Label10->Font->Color = clRed ;
		Edit6->Font->Color = clRed ;
	}
	else{
		Label10->Font->Color = clWindowText ;
		Edit6->Font->Color = clWindowText ;

	}
}
//---------------------------------------------------------------------------
void __fastcall TTask_Detail::BitBtn1Click(TObject *Sender)
{
	String str_comm ;
	String task_txt = Edit6->Text ;

// группа задачи
	FDQuery1->Active = false ;
	FDQuery1->Filtered = false ;
	FDQuery1->SQL->Text = String("select task_source, caption from task_group ;") ;
	FDQuery1->Filter = String("caption = '" + ComboBox1->Text + "'") ;
	FDQuery1->Filtered = true ;
	FDQuery1->Active = true ;
	short task_group = FDQuery1->FieldByName("task_source")->AsInteger ;

// статус задачи
	FDQuery1->Active = false ;
	FDQuery1->Filtered = false ;
	FDQuery1->SQL->Text = String("select kind, caption from task_state ;") ;
	FDQuery1->Filter = String("caption = '" + ComboBox3->Text + "'") ;
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

//	t_priority //приоритет задачи
	String note = Memo1->Lines->Text ;
	String plan_date, start_date ;
	TDateTime planned_date = DateTimePicker1->Date ;
	Tasks_MainForm->conv_date(&planned_date, &plan_date) ;
	TDateTime started_date = DateTimePicker2->Date ;
	Tasks_MainForm->conv_date(&started_date, &start_date) ;
	short task_repeat = cbTaskRepeat->State ;
	String pers_complete = Edit7->Text ;
	short task_toSD = CheckBox1->State ;
	String id_inSD = Edit1->Text ;
	if ("" == id_inSD) {
    	id_inSD = "0" ;
	}
	short task_proj = CheckBox3->State ;
	short ext_mission = CheckBox4->State ;
/*
  task,
  task_group,
  parent, не меняем из формы Задача
  task_category, пока не используем
  originate,
  priority,
  tags, пока не используем
  Note,
  need_exp_sd,
  id_sd,
  project, не меняем из формы Задача
  task_state,
  task_percent, не меняем из формы Задача
  task_complete, не меняем из формы Задача
  task_repeat,
  task_started,
  planned_date,
  complete_date, не меняем из формы Задача
  new_task, не меняем из формы Задача
  ud_weight_in_project, не меняем из формы Задача
  order_in_project, не меняем из формы Задача
  extend_mission
*/
//	Edit2->Text = IntToStr(task_repeat) ;//plan_date ;//IntToStr(task_group) ;

	if (0 != t_id) {
		str_comm = String("update tasks set task = '" + task_txt + "',\
		task_group = " + IntToStr(task_group) + ", originate = " + IntToStr(task_orig) + ",\
		priority = " + IntToStr(t_priority) + ", Note = '" + note + "',\
		need_exp_sd = " + IntToStr(task_toSD) + ", id_sd = " + id_inSD + ",\
		task_state = " + IntToStr(task_state) + ", task_repeat = " + IntToStr(task_repeat) + ",\
		task_started = " + start_date + ", planned_date = " + plan_date + ",\
		new_task = 0, extend_mission = " + IntToStr(ext_mission) + " \
		where task_id = " + IntToStr(t_id) + " ;") ;
		FDCommand1->CommandText->Clear() ;
		FDCommand1->CommandText->Add(str_comm) ;
		try{
			FDCommand1->Execute() ;
			Task_Detail->Close() ;

        }
		catch(...){
		}

	}
	else{
		str_comm = String("insert into tasks(task,task_group,originate,priority,Note,need_exp_sd,id_sd, \
		task_state,task_repeat,task_started,planned_date,new_task,extend_mission) values('" + task_txt + "',\
		" + IntToStr(task_group) + "," + IntToStr(task_orig) + "," + IntToStr(t_priority) + ",\
		'" + note + "'," + IntToStr(task_toSD) + "," + id_inSD + "," + IntToStr(task_state) + ",\
		" + IntToStr(task_repeat) + "," + start_date + "," + plan_date + ",0," + IntToStr(ext_mission) + ") ;") ;
		FDCommand1->CommandText->Clear() ;
		FDCommand1->CommandText->Add(str_comm) ;
//		Edit6->Text = str_comm ;
		try{
			FDCommand1->Execute() ;
			Task_Detail->Close() ;
        }
		catch(...){
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TTask_Detail::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)
		Edit1->Enabled = true ;
	else
		Edit1->Enabled = false ;
}
//---------------------------------------------------------------------------



