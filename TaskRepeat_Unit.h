//---------------------------------------------------------------------------

#ifndef TaskRepeat_UnitH
#define TaskRepeat_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TTaskRepeat_Form : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *btbOK;
	TDateTimePicker *dtpTaskRepeat;
	TEdit *edTask;
	TLabel *lbTitle;
	TLabel *lbTaskLength;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall edTaskChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTaskRepeat_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTaskRepeat_Form *TaskRepeat_Form;
//---------------------------------------------------------------------------
#endif
