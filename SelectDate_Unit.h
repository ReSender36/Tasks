//---------------------------------------------------------------------------

#ifndef SelectDate_UnitH
#define SelectDate_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TSelectDate_Form : public TForm
{
__published:	// IDE-managed Components
	TDateTimePicker *DateTimePicker1;
	TBitBtn *BitBtn1;
private:	// User declarations
public:		// User declarations
	__fastcall TSelectDate_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSelectDate_Form *SelectDate_Form;
//---------------------------------------------------------------------------
#endif
