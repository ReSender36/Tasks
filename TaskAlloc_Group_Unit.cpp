//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "TaskAlloc_Group_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTaskAlloc_Group *TaskAlloc_Group;
//---------------------------------------------------------------------------
__fastcall TTaskAlloc_Group::TTaskAlloc_Group(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_Group::FormClose(TObject *Sender, TCloseAction &Action)

{
	Tasks_MainForm->Enabled = true ;
}
//---------------------------------------------------------------------------

void __fastcall TTaskAlloc_Group::FormCreate(TObject *Sender)
{
/*
TLabel *lb_bill = new TLabel(this) ;
lb_bill->Parent = this ;
lb_bill->Name = "lbBill" ;
lb_bill->Font->Size = 10 ;
lb_bill->Caption = "Сумма счета" ;
lb_bill->Height = 21 ;
lb_bill->Left = 40 ;
lb_bill->Width = 79 ;
lb_bill->Top = 207 ;

type
  TForm1 = class(TForm)
    MyPopupMenu: TPopupMenu;
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    // процедура обработки клика на меню
    procedure OnMyMenuItemClick(Sender: TObject);
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

// у меня это нажатие кнопки, у тебя это может быть другая процедура
procedure TForm1.Button1Click(Sender: TObject);
var
  m: TMenuItem;
begin
  m:= TMenuItem.Create(nil);
  // заголовок, естественно, делаешь свой (из Акцесса или еще откуда)
  m.Caption:= 'текст меню';
  m.OnClick:= OnMyMenuItemClick;
  MyPopupMenu.Items.Add(m);
*/
//	TPopupMenu pop_menu ;
	FDQuery2->Active = false ;
	FDQuery2->SQL->Text = String("select task_source, caption from task_group ;") ;
	FDQuery2->Active = true ;
	short i = 0 ;
	FDQuery2->First() ;
	while(!FDQuery2->Eof){
		i++ ;
		TMenuItem *mi = new TMenuItem(this) ;
//		mi->Parent = PopupMenu1 ;
		mi->Caption = FDQuery2->FieldByName("caption")->AsString ;
		mi->Name = String("Cust" + IntToStr(i)) ;
		switch (i){
			case 1: mi->OnClick = ClickCustN1 ; break ;
			case 2: mi->OnClick = ClickCustN2 ; break ;
			case 3: mi->OnClick = ClickCustN3 ; break ;
			case 4: mi->OnClick = ClickCustN4 ; break ;
			case 5: mi->OnClick = ClickCustN5 ; break ;
			default: mi->OnClick = ClickCustN ; break ;
	}
//		mi->OnClick = ClickCustN ;
		PopupMenu1->Items->Add(mi) ;

		FDQuery2->Next() ;
	}

	FDQuery1->Active = true ;
	DataSource1->Enabled = true ;
	DBGrid1->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_Group::ClickCustN(TObject *Sender)
{
 /*	FDQuery2->Active = false ;
	FDQuery2->Active = true ;
	FDQuery2->First() ;
	while(!FDQuery2->Eof){
		String capt = FDQuery2->FieldByName("caption")->AsString ;
		TMenuItem *mi = PopupMenu1->Items->Find(capt);
		if(NULL != mi){
			Edit1->Text = "def " + IntToStr(mi->MenuIndex) ;
			break ;
		}
		FDQuery2->Next() ;
	}
 */
//	Edit1->Text = "def" ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_Group::ClickCustN1(TObject *Sender)
{
TMenuItem *mi = PopupMenu1->Items->Find("Мое");// >Caption ;
//Edit1->Text = mi->Name ;// >Caption ;
	short t_id = DBGrid1->SelectedField->AsInteger ;
	FDCommand1->CommandText->Clear() ;
//	Application->CreateForm(__classid(TSelectDate_Form), &SelectDate_Form) ;

//	if(SelectDate_Form->ShowModal() == bkOK){
//		TDateTime pl_date = SelectDate_Form->DateTimePicker1->Date ;
//		String pl_date_str, comm ;
//		Tasks_MainForm->conv_date(&pl_date, &pl_date_str) ;
		FDQuery2->Active = false ;
		FDQuery2->Filter = String("caption = '" + mi->Caption + "'") ;
		FDQuery2->Filtered = true ;
		FDQuery2->Active = true ;
		String curr_grp = FDQuery2->FieldByName("task_source")->AsString ;

		String comm = String("update tasks set task_group = " + curr_grp + " where task_id = " + IntToStr(t_id) + " ;") ;
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
void __fastcall TTaskAlloc_Group::ClickCustN2(TObject *Sender)
{
	TMenuItem *mi = PopupMenu1->Items->Find("Агама");// >Caption ;
	short t_id = DBGrid1->SelectedField->AsInteger ;
	FDCommand1->CommandText->Clear() ;
//	Application->CreateForm(__classid(TSelectDate_Form), &SelectDate_Form) ;

//	if(SelectDate_Form->ShowModal() == bkOK){
//		TDateTime pl_date = SelectDate_Form->DateTimePicker1->Date ;
//		String pl_date_str, comm ;
//		Tasks_MainForm->conv_date(&pl_date, &pl_date_str) ;
		FDQuery2->Active = false ;
		FDQuery2->Filter = String("caption = '" + mi->Caption + "'") ;
		FDQuery2->Filtered = true ;
		FDQuery2->Active = true ;
		String curr_grp = FDQuery2->FieldByName("task_source")->AsString ;

		String comm = String("update tasks set task_group = " + curr_grp + " where task_id = " + IntToStr(t_id) + " ;") ;
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
void __fastcall TTaskAlloc_Group::ClickCustN3(TObject *Sender)
{
	TMenuItem *mi = PopupMenu1->Items->Find("Гадасин");// >Caption ;
	short t_id = DBGrid1->SelectedField->AsInteger ;
	FDCommand1->CommandText->Clear() ;
//	Application->CreateForm(__classid(TSelectDate_Form), &SelectDate_Form) ;

//	if(SelectDate_Form->ShowModal() == bkOK){
//		TDateTime pl_date = SelectDate_Form->DateTimePicker1->Date ;
//		String pl_date_str, comm ;
//		Tasks_MainForm->conv_date(&pl_date, &pl_date_str) ;
		FDQuery2->Active = false ;
		FDQuery2->Filter = String("caption = '" + mi->Caption + "'") ;
		FDQuery2->Filtered = true ;
		FDQuery2->Active = true ;
		String curr_grp = FDQuery2->FieldByName("task_source")->AsString ;

		String comm = String("update tasks set task_group = " + curr_grp + " where task_id = " + IntToStr(t_id) + " ;") ;
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
void __fastcall TTaskAlloc_Group::ClickCustN4(TObject *Sender)
{
//for (int i = 0; i < PopupMenu1->Items->Count; i++)
//		if (PopupMenu1->ComponentIndex[i])
//		{
//		String str = String("phone_number = '" + ListBox1->Items->Strings[i] + "'") ;
//		}
// Edit1->Text = "4" ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_Group::ClickCustN5(TObject *Sender)
{
//for (int i = 0; i < PopupMenu1->Items->Count; i++)
//		if (PopupMenu1->ComponentIndex[i])
//		{
//		String str = String("phone_number = '" + ListBox1->Items->Strings[i] + "'") ;
//		}
// Edit1->Text = "5" ;
}
//---------------------------------------------------------------------------
void __fastcall TTaskAlloc_Group::DBGrid1TitleClick(TColumn *Column)
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

