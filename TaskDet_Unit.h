//---------------------------------------------------------------------------

#ifndef TaskDet_UnitH
#define TaskDet_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TTask_Detail : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TBitBtn *BitBtn1;
	TCheckBox *CheckBox1;
	TEdit *Edit1;
	TCheckBox *cbTaskRepeat;
	TComboBox *ComboBox1;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TRadioGroup *RadioGroup1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TRadioButton *RadioButton5;
	TComboBox *ComboBox2;
	TDateTimePicker *DateTimePicker1;
	TGroupBox *GroupBox2;
	TFDQuery *FDQuery1;
	TFDCommand *FDCommand1;
	TBitBtn *BitBtn2;
	TGroupBox *GroupBox1;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
	TFDQuery *fdqTasksExec;
	TLabel *Label3;
	TComboBox *ComboBox3;
	TCheckBox *CheckBox3;
	TMemo *Memo1;
	TCheckBox *CheckBox4;
	TLabel *Label14;
	TDateTimePicker *DateTimePicker2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall RadioButtonClick(TObject *Sender);
	void __fastcall Edit6Change(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTask_Detail(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTask_Detail *Task_Detail;
extern short t_id ;
//---------------------------------------------------------------------------
#endif
