//---------------------------------------------------------------------------

#ifndef ProjectDet_UnitH
#define ProjectDet_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ToolWin.hpp>
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
//---------------------------------------------------------------------------
class TProjectDet_Form : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TEdit *Edit2;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TEdit *Edit4;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TRadioGroup *RadioGroup1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TMemo *Memo1;
	TEdit *Edit5;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit6;
	TGridPanel *GridPanel1;
	TToolBar *ToolBar1;
	TDBGrid *DBGrid1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TFDQuery *fdqTasksInProj;
	TDataSource *DataSource1;
	TFDQuery *FDQuery1;
	TFDQuery *fdqProjDet;
	TCheckBox *CheckBox2;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TFDCommand *FDCommand1;
	TEdit *edShortPrName;
	TLabel *Label8;
	TLabel *Label11;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton4Click(TObject *Sender);
	void __fastcall DBGrid1EditButtonClick(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall RadioButtonClick(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall edShortPrNameChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TProjectDet_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProjectDet_Form *ProjectDet_Form;
extern short p_id ;
//---------------------------------------------------------------------------
#endif
