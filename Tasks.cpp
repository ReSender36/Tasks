//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("TaskDet_Unit.cpp", Task_Detail);
USEFORM("TaskAlloc_Group_Unit.cpp", TaskAlloc_Group);
USEFORM("TaskWrk_Unit.cpp", TaskWrk_Form);
USEFORM("TaskToProj_Unit.cpp", TaskToProj_Form);
USEFORM("TaskAlloc_Date_Unit.cpp", TaskAlloc_Date);
USEFORM("ProjectSel_Unit.cpp", ProjectSel_Form);
USEFORM("ProjectDet_Unit.cpp", ProjectDet_Form);
USEFORM("MainUnit.cpp", Tasks_MainForm);
USEFORM("TaskAlloc_ByProj_Unit.cpp", TaskAlloc_ByProj_Form);
USEFORM("SelectDate_Unit.cpp", SelectDate_Form);
USEFORM("Project_Unit.cpp", Projects_Form);
USEFORM("TaskRepeat_Unit.cpp", TaskRepeat_Form);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Emerald Light Slate");
		Application->CreateForm(__classid(TTasks_MainForm), &Tasks_MainForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
