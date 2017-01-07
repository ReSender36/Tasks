//---------------------------------------------------------------------------

#ifndef ProjectSel_UnitH
#define ProjectSel_UnitH
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
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TProjectSel_Form : public TForm
{
__published:	// IDE-managed Components
	TFDQuery *FDQuery1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TBitBtn *BitBtn1;
	TFDCommand *FDCommand1;
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
private:	// User declarations
public:		// User declarations
	__fastcall TProjectSel_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProjectSel_Form *ProjectSel_Form;
extern short pr_id ;
//---------------------------------------------------------------------------
#endif
