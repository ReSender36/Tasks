//---------------------------------------------------------------------------

#ifndef TaskAlloc_Date_UnitH
#define TaskAlloc_Date_UnitH
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
#include <Vcl.Buttons.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TTaskAlloc_Date : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TFDQuery *FDQuery1;
	TDataSource *DataSource1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TFDCommand *FDCommand1;
	TMenuItem *N4;
	TStatusBar *StatusBar1;
	TToolBar *ToolBar1;
	TEdit *edTaskID;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *tbtShowCompleted;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall tbtShowCompletedClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTaskAlloc_Date(TComponent* Owner);
protected:
	bool SortUp ;
	String SortField ;
};
//---------------------------------------------------------------------------
extern PACKAGE TTaskAlloc_Date *TaskAlloc_Date;
//---------------------------------------------------------------------------
#endif
