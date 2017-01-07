//---------------------------------------------------------------------------

#ifndef TaskToProj_UnitH
#define TaskToProj_UnitH
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
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TTaskToProj_Form : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TFDQuery *FDQuery1;
	TDataSource *DataSource1;
	TToolButton *ToolButton3;
	TFDCommand *FDCommand1;
	TEdit *edTaskID;
	TFDTable *FDTable1;
	TToolButton *tbtShowCompleted;
	TToolButton *ToolButton5;
	TStatusBar *StatusBar1;
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall edTaskIDChange(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall tbtShowCompletedClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTaskToProj_Form(TComponent* Owner);

protected:
	bool SortUp ;
	String SortField ;
};
//---------------------------------------------------------------------------
extern PACKAGE TTaskToProj_Form *TaskToProj_Form;
extern short par_id ;
//---------------------------------------------------------------------------
#endif
