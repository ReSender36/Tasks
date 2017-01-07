//---------------------------------------------------------------------------

#ifndef TaskWrk_UnitH
#define TaskWrk_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TTaskWrk_Form : public TForm
{
__published:	// IDE-managed Components
	TDateTimePicker *DateTimePicker1;
	TEdit *Edit1;
	TLabel *Label1;
	TLabel *Label2;
	TBitBtn *BitBtn1;
	TCheckBox *CheckBox1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTaskWrk_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTaskWrk_Form *TaskWrk_Form;
//extern String perc_comp ;
//---------------------------------------------------------------------------
#endif
