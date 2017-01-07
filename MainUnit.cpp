//---------------------------------------------------------------------------
#include <vcl.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "MainUnit.h"
#include "TaskDet_Unit.h"
#include "TaskWrk_Unit.h"
#include "TaskRepeat_Unit.h"
#include "TaskAlloc_Date_Unit.h"
#include "TaskAlloc_Group_Unit.h"
#include "Project_Unit.h"
#include "ProjectDet_Unit.h"
#include "TaskToProj_Unit.h"
#include "ProjectSel_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTasks_MainForm *Tasks_MainForm;
String task_filter ;
short t_id = 0 ;
short pr_id = 0 ;
String perc_comp = "" ;
String main_quest_def = "CALL seach_tasks('',0) ; " ;
//---------------------------------------------------------------------------
__fastcall TTasks_MainForm::TTasks_MainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int srch_lastTask(){
	Tasks_MainForm->FDQuery1->SQL->Text = String("select max(task_id) max_id from tasks ;") ;
	Tasks_MainForm->FDQuery1->Active = false ;
	Tasks_MainForm->FDQuery1->Active = true ;
	return Tasks_MainForm->FDQuery1->FieldByName("max_id")->AsInteger ;
}
//---------------------------------------------------------------------------
String from_caption(short addDate)
{
	Tasks_MainForm->fdqAssistant->Active = false ;
	Tasks_MainForm->fdqAssistant->Filtered = false ;
	if (6 == addDate)
		Tasks_MainForm->fdqAssistant->SQL->Text = String("select weekday(CURRENT_DATE()-1) wDayName from dual ;") ;
	else
		Tasks_MainForm->fdqAssistant->SQL->Text = String("select weekday(CURRENT_DATE()+" + IntToStr(addDate) + ") wDayName from dual ;") ;
	Tasks_MainForm->fdqAssistant->Active = true ;

	short weekdaynum = Tasks_MainForm->fdqAssistant->FieldByName("wDayName")->AsInteger ;
	switch(weekdaynum){
		case 0:
			return "Понедельник" ;
			break ;
		case 1:
			return "Вторник" ;
			break ;
		case 2:
			return "Среда" ;
			break ;
		case 3:
			return "Четверг" ;
			break ;
		case 4:
			return "Пятница" ;
			break ;
		case 5:
			return "Суббота" ;
			break ;
		case 6:
			return "Воскресенье" ;
			break ;
	}
}
//---------------------------------------------------------------------------
String cnt_tasks(String str_fltr)
{
	Tasks_MainForm->fdqAssistant->Active = false ;
	Tasks_MainForm->fdqAssistant->Filtered = false ;
	if ("" == str_fltr)
		Tasks_MainForm->fdqAssistant->SQL->Text = String("SELECT count(task_id) as cnt from base_taskview where task_complete = 0 and project = 0 and task_state in(1,3,5) ;") ;
	else
		Tasks_MainForm->fdqAssistant->SQL->Text = String("select count(task_id) as cnt from base_taskview where task_complete = 0 and project = 0 and task_state in(1,3,5) and " + str_fltr) ;

	Tasks_MainForm->fdqAssistant->Active = true ;
	return Tasks_MainForm->fdqAssistant->FieldByName("cnt")->AsString ;
}
//---------------------------------------------------------------------------
void bildListBoxDate()
{
	Tasks_MainForm->FDQuery1->Active = false ;
	Tasks_MainForm->FDQuery1->SQL->Text = String("SELECT pd.f_id, pd.Caption, pd.fltr_txt, pd.Sort_Order FROM predfilter_dateview pd ;") ;
	Tasks_MainForm->FDQuery1->Filtered = false ;
	Tasks_MainForm->FDQuery1->Active = true ;
	short fltr_id = 0 ;
	String capt = "" ;
	String cnt_tsk = "" ;
	Tasks_MainForm->FDQuery1->First() ;
	while(!Tasks_MainForm->FDQuery1->Eof){
		fltr_id = Tasks_MainForm->FDQuery1->FieldByName("f_id")->AsInteger ;
		capt = Tasks_MainForm->FDQuery1->FieldByName("caption")->AsString ;
		cnt_tsk = cnt_tasks(Tasks_MainForm->FDQuery1->FieldByName("fltr_txt")->AsString) ;
		if (fltr_id > 4 && fltr_id < 9) {
			if(5 == fltr_id)
				capt = from_caption(3) ;
			if(6 == fltr_id)
				capt = from_caption(4) ;
			if(7 == fltr_id)
				capt = from_caption(5) ;
			if(8 == fltr_id)
				capt = from_caption(6) ;
		}
		capt = capt + " (" + cnt_tsk + ")" ;
		Tasks_MainForm->ListBox1->AddItem(capt,(TObject*)fltr_id) ;
		Tasks_MainForm->FDQuery1->Next() ;
	}
}
//---------------------------------------------------------------------------
void update_grid()
{
	Tasks_MainForm->DBGrid1->Enabled = false ;
	Tasks_MainForm->DataSource1->Enabled = false ;
	Tasks_MainForm->fdqMainTasks->Active = false ;

	Tasks_MainForm->fdqMainTasks->Active = true ;
	Tasks_MainForm->fdqMainTasks->First() ;
	while(!Tasks_MainForm->fdqMainTasks->Eof){
		Tasks_MainForm->fdqMainTasks->Next() ;
	}
	Tasks_MainForm->StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(Tasks_MainForm->fdqMainTasks->RecordCount) ; //String("Актуальных задач ") + IntToStr(cnt) ;
	Tasks_MainForm->DataSource1->Enabled = true ;
	Tasks_MainForm->DBGrid1->Enabled = true ;

//	bildListBoxDate() ;
}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::FormCreate(TObject *Sender)
{
	TIniFile *ini ;
	ini = new TIniFile(ChangeFileExt(Application->ExeName, ".ini")) ;
	String vSrv = ini->ReadString("SM","Server", 1) ;
	String vPort = ini->ReadString("SM","Port", 1) ;
	String vLogin = ini->ReadString("SM","Login","default") ;
	String vPassword = ini->ReadString("SM", "Password",1) ;
	String vDB = ini->ReadString("SM", "DB",1) ;
	String vCodepage = ini->ReadString("SM", "Codepage",1) ;
	ini->Free() ;

	FDConnection1->Params->UserName = vLogin ;
	FDConnection1->Params->Password = vPassword ;
	FDConnection1->Params->Add("Server = vSrv") ;
	FDConnection1->Params->Add("Port = vPort") ;
	FDConnection1->Params->Add("CharacterSet = vCodepage") ;
	FDConnection1->Params->Database = vDB ;

	short cnt = 0 ;
// тут нужна функция подсоединения к БД по аналогии с SM из XE
	try{
		FDConnection1->Connected = true ;

		StatusBar1->Panels->Items[0]->Text = String("Подключена БД: ") + FDConnection1->Params->Database ;
	}
	catch(...){
	}
	FDQuery1->SQL->Text = String("select task_source, caption from task_group ;") ;
	FDQuery1->Active = true ;

	FDQuery1->First() ;
	while(!FDQuery1->Eof){
		ComboBox1->AddItem(FDQuery1->FieldByName("caption")->AsString,
			(TObject*)FDQuery1->FieldByName("task_source")->AsInteger) ;
		FDQuery1->Next() ;
	}
	fdqMainTasks->SQL->Text = main_quest_def ;
	fdqMainTasks->Active = true ;
	fdqMainTasks->First() ;
	while(!fdqMainTasks->Eof){
//		cnt++ ;
		fdqMainTasks->Next() ;
	}
	StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(fdqMainTasks->RecordCount) ; //String("Актуальных задач ") + IntToStr(cnt) ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
    bildListBoxDate() ;
	if ("" == edFindTasks->Text)
		edFindTasks->Text = "Введите ID или текст задачи" ;
	if ("" == edAddTask->Text)
		edAddTask->Text = "Введите задачу (не более 80 символов)" ;

}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::N2Click(TObject *Sender)
{
	Application->Terminate() ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::ToolButton1Click(TObject *Sender)
{
	Application->Terminate() ;
}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::ToolButton3Click(TObject *Sender)
{
	short cnt = 0 ;
	if (!ToolButton3->Marked){
		fdqMainTasks->Active = false ;
		fdqMainTasks->Filtered = false ;
		TDateTime dt_CurrDate = (TDateTime::CurrentDate()) ;
		String str_CurrDate = dt_CurrDate.DateString() ;
		if ("" != task_filter)
			task_filter = task_filter + String(" and planned_date = '" + str_CurrDate + "'") ;
		else
			task_filter = String("planned_date = '" + str_CurrDate + "'") ;

		fdqMainTasks->Filter = task_filter ;
		fdqMainTasks->Filtered = true ;
		fdqMainTasks->Active = true ;
		fdqMainTasks->First() ;
		while(!fdqMainTasks->Eof){
			cnt++ ;
			fdqMainTasks->Next() ;
		}
		StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(cnt) ;
		ToolButton3->Marked = true ;
		task_filter = "" ;
	}
	else{
		fdqMainTasks->Active = false ;
		fdqMainTasks->Filtered = false ;
		fdqMainTasks->Active = true ;
		DataSource1->Enabled = true ;
		DBGrid1->Enabled = true ;
		ToolButton3->Marked = false ;
		ComboBox1->Text = "" ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::ComboBox1Select(TObject *Sender)
{
	short cnt = 0 ;
	FDQuery1->Active = false ;
	FDQuery1->Filtered = false ;
	FDQuery1->SQL->Text = String("select task_source, caption from task_group ;") ;
	String task_source = String("caption = '"+ComboBox1->Text+"'") ;
	FDQuery1->Filter = task_source ;
	FDQuery1->Filtered = true ;
	FDQuery1->Active = true ;
	short ts = FDQuery1->FieldByName("task_source")->AsInteger ;

	fdqMainTasks->Active = false ;
//    task_filter = "" ;
	task_filter = String("task_group = "+String(ts)+"") ;
	fdqMainTasks->Filter = task_filter ;
	fdqMainTasks->Filtered = true ;
	fdqMainTasks->Active = true ;
	fdqMainTasks->First() ;
	while(!fdqMainTasks->Eof){
		cnt++ ;
		fdqMainTasks->Next() ;
	}
	StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(cnt) ;
}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::DBGrid1CellClick(TColumn *Column)
{
//	Edit1->Text = DBGrid1->SelectedField->AsString ;
	StatusBar1->Panels->Items[2]->Text = String("Выбрана задача с ID: ") + DBGrid1->SelectedField->AsString ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::N11Click(TObject *Sender)
{
	t_id = DBGrid1->SelectedField->AsInteger ;
	Application->CreateForm(__classid(TTask_Detail), &Task_Detail) ;

//	task_id = StrToInt(Edit1->Text) ;
	Task_Detail->Visible = true ;
	Tasks_MainForm->Enabled = false ;
}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::N21Click(TObject *Sender)
{
	short cnt = 0 ;
	bool blTaslkMustRepeat = false ;
	t_id = DBGrid1->SelectedField->AsInteger ; //>AsString ;
	FDQuery1->Active = false ;
	FDQuery1->Filtered = false ;
	FDQuery1->SQL->Text = String("select task, task_percent, task_repeat from tasks t where t.task_id = " + IntToStr(t_id) + " ;") ;
	FDQuery1->Active = true ;
	String task_text = FDQuery1->FieldByName("task")->AsString ;
	String perc_comp = FDQuery1->FieldByName("task_percent")->AsString ;
	blTaslkMustRepeat = FDQuery1->FieldByName("task_repeat")->AsBoolean ;

	Application->CreateForm(__classid(TTaskWrk_Form), &TaskWrk_Form) ;
//	TaskWrk_Form->Visible = true ;
//	Tasks_MainForm->Enabled = false ;
	TaskWrk_Form->Edit1->Text = perc_comp ;
	TaskWrk_Form->DateTimePicker1->Date = TDateTime::CurrentDate() ;
	String perc = "0" ;
	if(TaskWrk_Form->ShowModal() == bkOK){

		perc = TaskWrk_Form->Edit1->Text ;
		TDateTime task_exec = TaskWrk_Form->DateTimePicker1->Date ;
		String task_exec_str = "" ;
		String t_id_str = IntToStr(t_id) ;
		conv_date(&task_exec, &task_exec_str) ;
		String comm = String("insert into task_execdate(task_id,exec_date,percent_complete) values(" + IntToStr(t_id) + "," + task_exec_str + ",'" + perc + "') ;") ;
		FDCommand1->CommandText->Add(comm) ;
// 		FDCommand1->Execute() ;
		if ("100" == perc)
//			comm = String("update tasks set planned_date = '2009-01-01', complete_date = " + task_exec_str + ", task_percent = " + perc + ", task_complete = 1 where task_id = " + IntToStr(t_id) + " ;") ;
			comm = String("update tasks set complete_date = " + task_exec_str + ", task_percent = " + perc + ", task_state = 4, task_complete = 1 where task_id = " + IntToStr(t_id) + " ;") ;
		else
			comm = String("update tasks set planned_date = ADDDATE(CURRENT_DATE(),1), task_percent = " + perc + ", task_complete = 0 where task_id = " + IntToStr(t_id) + " ;") ;

		FDCommand1->CommandText->Add(comm) ;
		FDCommand1->Execute() ;
		FDCommand1->CommandText->Clear() ;
	}

	if ("100" == perc && blTaslkMustRepeat){
		Application->CreateForm(__classid(TTaskRepeat_Form), &TaskRepeat_Form) ;
		TaskRepeat_Form->edTask->Text = task_text ;
		TaskRepeat_Form->dtpTaskRepeat->Date = TDateTime::CurrentDate() ;
		if(TaskRepeat_Form->ShowModal() == bkOK){
			task_text = TaskRepeat_Form->edTask->Text ;
			TDateTime TaskRepeatDate = TaskRepeat_Form->dtpTaskRepeat->Date ;
			String plan_date, start_date ;
			Tasks_MainForm->conv_date(&TaskRepeatDate, &plan_date) ;

			FDQuery1->Active = false ;
			FDQuery1->Filtered = false ;
			FDQuery1->SQL->Text = String("SELECT t.task_group, t.parent, t.originate, t.priority,t.note,t.need_exp_sd,t.id_sd,\
				t.task_state, t.task_complete, t.task_repeat,t.extend_mission\
				FROM tasks t\
				WHERE t.task_id = " + IntToStr(t_id) + " ;") ;
			FDQuery1->Active = true ;

			short tg = FDQuery1->FieldByName("task_group")->AsInteger;
			short parent = FDQuery1->FieldByName("parent")->AsInteger ;
			short to = FDQuery1->FieldByName("originate")->AsInteger;
			short prior = FDQuery1->FieldByName("priority")->AsInteger;
			String note = FDQuery1->FieldByName("note")->AsString;
			short task_toSD = FDQuery1->FieldByName("need_exp_sd")->AsBoolean;
			String id_inSD = FDQuery1->FieldByName("id_sd")->AsString;
            short task_repeat = FDQuery1->FieldByName("task_repeat")->AsBoolean ;
			short ext_mission = FDQuery1->FieldByName("extend_mission")->AsBoolean;

			String str_comm = String("insert into tasks(task,task_group,parent,originate,priority,Note,need_exp_sd,id_sd, \
		task_repeat,task_started,planned_date,new_task,extend_mission) values('" + task_text + "',\
		" + IntToStr(tg) + "," + IntToStr(parent) + "," + IntToStr(to) + "," + IntToStr(prior) + ",\
		'" + note + "'," + IntToStr(task_toSD) + "," + id_inSD + ",\
		" + IntToStr(task_repeat) + "," + plan_date + "," + plan_date + ",1," + IntToStr(ext_mission) + ") ;") ;
		FDCommand1->CommandText->Clear() ;
		FDCommand1->CommandText->Add(str_comm) ;
		FDCommand1->Execute() ;
		FDCommand1->CommandText->Clear() ;
		}
	}

	update_grid() ;

//	DBGrid1->Enabled = false ;
//	DataSource1->Enabled = false ;
	fdqMainTasks->Active = false ;

	fdqMainTasks->Active = true ;
//	DataSource1->Enabled = true ;
//	DBGrid1->Enabled = true ;
//	fdqMainTasks->First() ;
//	while(!fdqMainTasks->Eof){
//		cnt++ ;
//		fdqMainTasks-> >Next() ;
		fdqMainTasks->Last() ;
		cnt = fdqMainTasks->RecordCount ;
//	}

//	fdqMainTasks->First() ;
	StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(cnt) ;
}
//---------------------------------------------------------------------------


void __fastcall TTasks_MainForm::ToolButton8Click(TObject *Sender)
{
	update_grid() ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::N23Click(TObject *Sender)
{
//	t_id = DBGrid1->SelectedField->AsInteger ; //>AsString ;
	Application->CreateForm(__classid(TTaskAlloc_Date), &TaskAlloc_Date) ;
	TaskAlloc_Date->Visible = true ;
	Tasks_MainForm->Enabled = false ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::N24Click(TObject *Sender)
{
	Application->CreateForm(__classid(TTaskAlloc_Group), &TaskAlloc_Group) ;
	TaskAlloc_Group->Visible = true ;
	Tasks_MainForm->Enabled = false ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::N12Click(TObject *Sender)
{
	Application->CreateForm(__classid(TProjects_Form), &Projects_Form) ;
	Projects_Form->Visible = true ;
	Tasks_MainForm->Enabled = false ;
}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::DBGrid1TitleClick(TColumn *Column)
{
	if (Column->FieldName == SortField){
		if (SortUp)
			fdqMainTasks->IndexFieldNames = Column->FieldName + ":D" ;
		else
			fdqMainTasks->IndexFieldNames = Column->FieldName ;
	}
	else{
		fdqMainTasks->IndexFieldNames = Column->FieldName ;
	}
	if (fdqMainTasks->IndexFieldNames == Column->FieldName)
		SortUp = true ;
	else
		SortUp = false ;

	SortField = Column->FieldName ;
}
//---------------------------------------------------------------------------
short cnt_execdates(String task_id)
{
	Tasks_MainForm->fdqAssistant->Active = false ;
	Tasks_MainForm->fdqAssistant->Filtered = false ;
	String str_quest = String("select count(row_id) cnt from task_execdate where task_id = " + task_id + " ;") ;
	Tasks_MainForm->fdqAssistant->SQL->Text = str_quest ;
	Tasks_MainForm->fdqAssistant->Active = true ;
	return Tasks_MainForm->fdqAssistant->FieldByName("cnt")->AsInteger ;
}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::ToolButton12Click(TObject *Sender)
{
int q_delTask = Application->MessageBoxW(String("Удалить текущую задачу?").w_str(),String("Вопрос").w_str(),MB_YESNO + MB_ICONQUESTION) ;
		switch(q_delTask){
			case IDYES:{
				FDCommand1->CommandText->Clear() ;
				String t_id = DBGrid1->SelectedField->AsString ;
				String cmd ;
				if (0 != cnt_execdates(t_id)) {
					cmd = String("delete from task_execdate where task_id = " + t_id + " ;") ;
					FDCommand1->CommandText->Add(cmd) ;
//					FDCommand1->Execute() ;
				}
				cmd = String("delete from tasks where task_id = " + t_id + " ;") ;
				FDCommand1->CommandText->Add(cmd) ;
				FDCommand1->Execute() ;
				update_grid() ;
			}
			case IDNO: break ;
		}
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::ToolButton9Click(TObject *Sender)
{
	t_id = 0 ;
	Application->CreateForm(__classid(TTask_Detail), &Task_Detail) ;

//	task_id = StrToInt(Edit1->Text) ;
	Task_Detail->Visible = true ;
	Tasks_MainForm->Enabled = false ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
	if (-1 != fdqMainTasks->FieldByName("parent")->AsInteger /* && Column->FieldName == "task_complete"*/) {
		DBGrid1->Canvas->Font->Color = clHotLight ;
		DBGrid1->Canvas->Font->Style = (TFontStyles)fsBold ;

//		DBGrid1->Canvas->FillRect(Rect) ;
//		DBGrid1->Canvas->TextOut(Rect.Left + 7 , Rect.Top + 2, Column->Field->Text) ;
//		DBGrid1->Canvas->TextOutW(Rect.Right - 7 - DBGrid1->Canvas->TextWidth(Column->Field->Text), Rect.Top + 2, Column->Field->Text) ;
		DBGrid1->DefaultDrawColumnCell(Rect,DataCol,Column,State) ;
	}
	if(State.Contains(Grids::gdSelected) && -1 != fdqMainTasks->FieldByName("parent")->AsInteger){
 //		DBGrid1->Canvas->Font->Color = clHotLight ;
 //		DBGrid1->Canvas->Font->Style = (TFontStyles)fsBold ;
	}
	if(DBGrid1->SelectedRows->CurrentRowSelected)
		DBGrid1->Canvas->Font->Color = clWindowFrame ;
//	DBGrid1->DefaultDrawColumnCell(Rect,DataCol,Column,State) ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::ToolButton13Click(TObject *Sender)
{
	short cnt = 0 ;
	if (!ToolButton13->Marked){
		fdqMainTasks->Active = false ;
		fdqMainTasks->Filtered = false ;
		TDateTime dt_CurrDate = (TDateTime::CurrentDate()) ;
		String str_CurrDate = dt_CurrDate.DateString() ;
		if ("" != task_filter)
			task_filter = task_filter + String(" and extend_mission = '1'") ;
		else
			task_filter = String("extend_mission = '1'") ;

		fdqMainTasks->Filter = task_filter ;
		fdqMainTasks->Filtered = true ;
		fdqMainTasks->Active = true ;
		fdqMainTasks->First() ;
		while(!fdqMainTasks->Eof){
			cnt++ ;
			fdqMainTasks->Next() ;
		}
 		StatusBar1->Panels->Items[1]->Text = String("Актуальных задач ") + IntToStr(cnt) ;
		ToolButton13->Marked = true ;
		task_filter = "" ;
	}
	else{
		fdqMainTasks->Active = false ;
		fdqMainTasks->Filtered = false ;
		fdqMainTasks->Active = true ;
		DataSource1->Enabled = true ;
		DBGrid1->Enabled = true ;
		ToolButton13->Marked = false ;
		ComboBox1->Text = "" ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::N26Click(TObject *Sender)
{
	t_id = DBGrid1->SelectedField->AsInteger ;
	FDCommand1->CommandText->Clear() ;
	String command = String("update tasks set project = 1 where task_id = " + IntToStr(t_id) + " ;") ;
	FDCommand1->CommandText->Add(command) ;
	FDCommand1->Execute() ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::N27Click(TObject *Sender)
{

	t_id = DBGrid1->SelectedField->AsInteger ;

	Application->CreateForm(__classid(TProjectSel_Form), &ProjectSel_Form) ;
	ProjectSel_Form->Caption = String("Выбрать проект для привязки задачи " + IntToStr(t_id)) ;
//	ProjectSel_Form->Visible = true ;
	Tasks_MainForm->Enabled = false ;
	if(ProjectSel_Form->ShowModal() == bkOK){
		String pr_id = ProjectSel_Form->DBGrid1->SelectedField->AsString ;
		FDQuery1->Active = false ;
		FDQuery1->Filtered = false ;
		FDQuery1->SQL->Text = String("select pr_task_id from projects where pr_id = " + pr_id + " ;") ;
		FDQuery1->Active = true ;

		String comm = String("update tasks set parent = " + FDQuery1->FieldByName("pr_task_id")->AsString + " where task_id = " + IntToStr(t_id) + " ;") ;
		FDCommand1->CommandText->Add(comm) ;
		FDCommand1->Execute() ;
	}
//	ComboBox1->Text = IntToStr(pr_id) ;
}
//---------------------------------------------------------------------------
int chk_field_length(String Str_fName)
{
	Tasks_MainForm->FDQuery1->SQL->Text = String("SELECT CHARACTER_MAXIMUM_LENGTH FROM information_schema.COLUMNS WHERE TABLE_SCHEMA='sm' AND TABLE_NAME='tasks' AND COLUMN_NAME='" + Str_fName + "'; ") ;
	Tasks_MainForm->FDQuery1->Filtered = false ;
	Tasks_MainForm->FDQuery1->Active = true ;
	return Tasks_MainForm->FDQuery1->FieldByName("CHARACTER_MAXIMUM_LENGTH")->AsInteger ;
}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::SpeedButton1Click(TObject *Sender)
{
	int fieldNameLen = chk_field_length("task") ;
	int task_legth = check_length(edAddTask->Text) ;
	if (fieldNameLen > task_legth) {
		FDCommand1->CommandText->Clear() ;
		String str_comm = String("insert into tasks(task,task_group,parent,task_category,originate,priority,\
		tags,Note,need_exp_sd,id_sd,project,task_state,task_percent,task_complete,task_repeat,task_started,\
		planned_date,new_task) \
		values('" + edAddTask->Text + "',1,-1,1,1,3,'','',0,0,0,1,0,0,0,current_Date(),current_Date(),1)") ;
		FDCommand1->CommandText->Add(str_comm) ;
		try{
			FDCommand1->Execute() ;
			edAddTask->Clear() ;
			update_grid() ;
			int max_num = srch_lastTask() ;
			TLocateOptions SOptions;
			SOptions<<loCaseInsensitive<<loPartialKey;
			fdqMainTasks->Locate("task_id",IntToStr(max_num),SOptions) ;
		}
		catch(...){

		}
	}
	else
		int q_delTask = Application->MessageBoxW(String("Длина введенной строки больше максимально возможной. Уменьшите с " + IntToStr(task_legth) + " до " + IntToStr(fieldNameLen) + "!").w_str(),String("Внимание!").w_str(),MB_OK + MB_ICONEXCLAMATION) ;
}
//---------------------------------------------------------------------------
String extract_year(TDateTime *str_dt)
{
	unsigned short Year ;
	unsigned short Month ;
	unsigned short Day ;
	str_dt->DecodeDate(&Year,&Month,&Day) ;
	String ys = String(Year) ;
	String ms = String(Month) ;
	String ds = String(Day) ;
	return ys ;
}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::ListBox1Click(TObject *Sender)
{
	if (main_quest_def != fdqMainTasks->SQL->Text) {
		fdqMainTasks->Active = false ;
		fdqMainTasks->SQL->Text = main_quest_def ;
		fdqMainTasks->Filtered = false ;
		fdqMainTasks->Active = true ;
    }
	for (int i = 0; i < ListBox1->Items->Count; i++)
		if (ListBox1->Selected[i]){
			short o_id = (short)(ListBox1->Items->Objects[i]) ;
			String str = String("f_id = '" + IntToStr(o_id)  + "'") ;
			String str_query = String("SELECT pd.f_id, pd.Caption, pd.fltr_txt, pd.Sort_Order FROM predfilter_dateview pd ; ") ;
			fdqAssistant->Active = false ;
			fdqAssistant->SQL->Text = str_query ;
			fdqAssistant->Filtered = false ;
			fdqAssistant->Filter = str ;
			fdqAssistant->Active = true ;
			fdqAssistant->Filtered = true ;
			TDateTime dt_CurrDate = (TDateTime::CurrentDate()) ;
			short ftlr_id = fdqAssistant->FieldByName("f_id")->AsInteger ;
			String ftlr_txt = fdqAssistant->FieldByName("fltr_txt")->AsString ;
			ftlr_txt = "planned_date = " ;
			if (0 == ftlr_id) {
				ftlr_txt = "" ;
			}
			if (1 == ftlr_id) {
				String str_CurrDate = (dt_CurrDate - 1).DateString() ;
				ftlr_txt = ftlr_txt + "'" + str_CurrDate + "'" ;
			}
			if (2 == ftlr_id) {
				String str_CurrDate = (dt_CurrDate).DateString() ;
				ftlr_txt = ftlr_txt + "'" + str_CurrDate + "'" ;
			}
			if (3 == ftlr_id) {
				String str_CurrDate = (dt_CurrDate + 1).DateString() ;
				ftlr_txt = ftlr_txt + "'" + str_CurrDate + "'" ;
			}
			if (4 == ftlr_id) {
				String str_CurrDate = (dt_CurrDate + 2).DateString() ;
				ftlr_txt = ftlr_txt + "'" + str_CurrDate + "'" ;
			}
			if (5 == ftlr_id) {
				String str_CurrDate = (dt_CurrDate + 3).DateString() ;
				ftlr_txt = ftlr_txt + "'" + str_CurrDate + "'" ;
			}
			if (6 == ftlr_id) {
				String str_CurrDate = (dt_CurrDate + 4).DateString() ;
				ftlr_txt = ftlr_txt + "'" + str_CurrDate + "'" ;
			}
			if (7 == ftlr_id) {
				String str_CurrDate = (dt_CurrDate + 5).DateString() ;
				ftlr_txt = ftlr_txt + "'" + str_CurrDate + "'" ;
			}
			if (8 == ftlr_id) {
				String str_CurrDate = (dt_CurrDate + 6).DateString() ;
				ftlr_txt = ftlr_txt + "'" + str_CurrDate + "'" ;
			}

			if (10 == ftlr_id) {
				String str_CurrDate = (dt_CurrDate).DateString() ;
				ftlr_txt = "planned_date < '" + str_CurrDate + "'" ;
			}
			if (11 == ftlr_id) {
				TDateTime dt_EndDate = (TDateTime::CurrentDate()) ;
				String year = extract_year(&dt_EndDate) ;
				ftlr_txt = ftlr_txt + "'31.12." + year + "'" ;
			}
			if (13 == ftlr_id) {
				ftlr_txt = "planned_date is null" ;
			}
			fdqMainTasks->Active = false ;
			fdqMainTasks->Filtered = false ;
			fdqMainTasks->Filter = ftlr_txt ;
			fdqMainTasks->Filtered = true ;
			fdqMainTasks->Active = true ;

			update_grid() ;
		}

}
//---------------------------------------------------------------------------
void __fastcall TTasks_MainForm::edAddTaskClick(TObject *Sender)
{
if ("Введите задачу (не более 80 символов)" == edAddTask->Text)
	edAddTask->Text = "" ;


}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::edAddTaskExit(TObject *Sender)
{
if ("" == edAddTask->Text)
	edAddTask->Text = "Введите задачу (не более 80 символов)" ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::edFindTasksClick(TObject *Sender)
{
if ("Введите ID или текст задачи" == edFindTasks->Text)
	edFindTasks->Text = "" ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::edFindTasksExit(TObject *Sender)
{
if ("" == edFindTasks->Text)
	edFindTasks->Text = "Введите ID или текст задачи" ;
}
//---------------------------------------------------------------------------

void __fastcall TTasks_MainForm::edFindTasksChange(TObject *Sender)
{
	if ("Введите ID или текст задачи" != edFindTasks->Text) {
		String find_txt = edFindTasks->Text ;
		fdqMainTasks->Active = false ;
		fdqMainTasks->SQL->Text = String("CALL seach_tasks('%" + find_txt + "%',1) ;") ;
		fdqMainTasks->Filtered = false ;
		fdqMainTasks->Active = true ;
//		update_grid() ;
	}
	else{
		if ("" == edFindTasks->Text || "Введите ID или текст задачи" == edFindTasks->Text){
			fdqMainTasks->Active = false ;
			fdqMainTasks->SQL->Text = main_quest_def ;
			fdqMainTasks->Filtered = false ;
			fdqMainTasks->Active = true ;
		}
	}
}
//---------------------------------------------------------------------------


