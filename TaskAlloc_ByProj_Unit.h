//---------------------------------------------------------------------------

#ifndef TaskAlloc_ByProj_UnitH
#define TaskAlloc_ByProj_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
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
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TTaskAlloc_ByProj_Form : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TFDQuery *FDQuery1;
	TDataSource *DataSource1;
	TToolBar *ToolBar1;
	TToolButton *tbtShowCompleted;
	TToolButton *ToolButton2;
	TEdit *edTaskID;
	TStatusBar *StatusBar1;
	TComboBox *cbxFilterTaskGroup;
	TToolButton *ToolButton1;
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tbtShowCompletedClick(TObject *Sender);
	void __fastcall edTaskIDChange(TObject *Sender);
	void __fastcall cbxFilterTaskGroupSelect(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
private:	// User declarations
public:		// User declarations
	__fastcall TTaskAlloc_ByProj_Form(TComponent* Owner);
protected:
	bool SortUp ;
	String SortField ;
};
//---------------------------------------------------------------------------
extern PACKAGE TTaskAlloc_ByProj_Form *TaskAlloc_ByProj_Form;
//---------------------------------------------------------------------------
#endif
