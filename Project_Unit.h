//---------------------------------------------------------------------------

#ifndef Project_UnitH
#define Project_UnitH
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
class TProjects_Form : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *BitBtn1;
	TDBGrid *DBGrid1;
	TFDQuery *fdqMainDBG;
	TDataSource *DataSource1;
	TPopupMenu *PopupMenu1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TFDQuery *fdqFindEnv;
	TFDCommand *FDCommand1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
private:	// User declarations
public:		// User declarations
	__fastcall TProjects_Form(TComponent* Owner);
protected:
	bool SortUp ;
	String SortField ;
};
//---------------------------------------------------------------------------
extern PACKAGE TProjects_Form *Projects_Form;
extern short pr_id ;
//---------------------------------------------------------------------------
#endif
