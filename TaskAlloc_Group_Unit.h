//---------------------------------------------------------------------------

#ifndef TaskAlloc_Group_UnitH
#define TaskAlloc_Group_UnitH
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
//---------------------------------------------------------------------------
class TTaskAlloc_Group : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TBitBtn *BitBtn1;
	TDataSource *DataSource1;
	TFDQuery *FDQuery1;
	TFDCommand *FDCommand1;
	TPopupMenu *PopupMenu1;
	TFDQuery *FDQuery2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
private:	// User declarations
public:		// User declarations
	__fastcall TTaskAlloc_Group(TComponent* Owner);
	void __fastcall ClickCustN(TObject *Sender);
	void __fastcall ClickCustN1(TObject *Sender);
	void __fastcall ClickCustN2(TObject *Sender);
	void __fastcall ClickCustN3(TObject *Sender);
	void __fastcall ClickCustN4(TObject *Sender);
	void __fastcall ClickCustN5(TObject *Sender);
protected:
	bool SortUp ;
	String SortField ;
};
//---------------------------------------------------------------------------
extern PACKAGE TTaskAlloc_Group *TaskAlloc_Group;
//---------------------------------------------------------------------------
#endif
