//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Stan.StorageJSON.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ActnMenus.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
#include <Vcl.StdActns.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTasks_MainForm : public TForm
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection1;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
	TFDQuery *FDQuery1;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	TToolBar *ToolBar1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TComboBox *ComboBox1;
	TToolButton *ToolButton3;
	TFDTable *FDTable1;
	TFDQuery *fdqMainTasks;
	TImageList *ImageList1;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TActionManager *ActionManager1;
	TEditCopy *EditCopy1;
	TEditCopy *EditCopy2;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TEditCut *EditCut1;
	TEditPaste *EditPaste1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N20;
	TMenuItem *N21;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TFDCommand *FDCommand1;
	TADOCommand *ADOCommand1;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TMenuItem *N25;
	TMenuItem *N26;
	TMenuItem *N27;
	TToolButton *ToolButton14;
	TEdit *edAddTask;
	TLabel *Label2;
	TStatusBar *StatusBar1;
	TSpeedButton *SpeedButton1;
	TPanel *Panel1;
	TListBox *ListBox1;
	TLabel *Label1;
	TFDQuery *fdqAssistant;
	TToolBar *ToolBar2;
	TEdit *edFindTasks;
	TLabel *lbTasksType;
	TListBox *lbxTasksType;
	TMenuItem *N28;
	TMenuItem *Copy1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall ComboBox1Select(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N21Click(TObject *Sender);
	void __fastcall ToolButton8Click(TObject *Sender);
	void __fastcall N23Click(TObject *Sender);
	void __fastcall N24Click(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall ToolButton12Click(TObject *Sender);
	void __fastcall ToolButton9Click(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall ToolButton13Click(TObject *Sender);
	void __fastcall N26Click(TObject *Sender);
	void __fastcall N27Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall edAddTaskClick(TObject *Sender);
	void __fastcall edAddTaskExit(TObject *Sender);
	void __fastcall edFindTasksClick(TObject *Sender);
	void __fastcall edFindTasksExit(TObject *Sender);
	void __fastcall edFindTasksChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTasks_MainForm(TComponent* Owner);
//---------------------------------------------------------------------------
// Функция декодирования даты-времени в американский стандарт запроса MySQL
void conv_date(TDateTime *op1, String *dts )
{
unsigned short Year ;
unsigned short Month ;
unsigned short Day ;
TDateTime o ;
//String dt ;

	op1->DecodeDate(&Year,&Month,&Day) ;

	String ys = String(Year) ;
	String ms = String(Month) ;
	String ds = String(Day) ;
//	String dts ;

	switch (Month)
	{
		case 1: ms = String("0" + ms) ; break ;
		case 2: ms = String("0" + ms) ; break ;
		case 3: ms = String("0" + ms) ; break ;
		case 4: ms = String("0" + ms) ; break ;
		case 5: ms = String("0" + ms) ; break ;
		case 6: ms = String("0" + ms) ; break ;
		case 7: ms = String("0" + ms) ; break ;
		case 8: ms = String("0" + ms) ; break ;
		case 9: ms = String("0" + ms) ; break ;
	default:
		ms ;
	}
	switch (Day)
	{
		case 1: ds = String("0" + ds) ; break ;
		case 2: ds = String("0" + ds) ; break ;
		case 3: ds = String("0" + ds) ; break ;
		case 4: ds = String("0" + ds) ; break ;
		case 5: ds = String("0" + ds) ; break ;
		case 6: ds = String("0" + ds) ; break ;
		case 7: ds = String("0" + ds) ; break ;
		case 8: ds = String("0" + ds) ; break ;
		case 9: ds = String("0" + ds) ; break ;
	default:
		ds ;
	}
	*dts = String("'" + ys + "-" + ms + "-" + ds + "'") ;
 //	*dts = dt ;
}
//---------------------------------------------------------------------------
short check_length(AnsiString row)
{
	char *str_row = row.c_str() ;
	int q = strlen(str_row) ;
	return q ;
}
//---------------------------------------------------------------------------
protected:
	bool SortUp ;
	String SortField ;
};
//---------------------------------------------------------------------------
extern PACKAGE TTasks_MainForm *Tasks_MainForm;
//extern short t_id ;
//---------------------------------------------------------------------------
#endif
