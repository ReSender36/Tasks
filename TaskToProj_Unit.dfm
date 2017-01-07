object TaskToProj_Form: TTaskToProj_Form
  Left = 0
  Top = 0
  Caption = #1047#1072#1076#1072#1095#1072' '#1074' '#1087#1088#1086#1077#1082#1090
  ClientHeight = 316
  ClientWidth = 772
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    AlignWithMargins = True
    Left = 3
    Top = 25
    Width = 766
    Height = 269
    Align = alClient
    DataSource = DataSource1
    Enabled = False
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDblClick = DBGrid1DblClick
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'task_id'
        Title.Caption = 'ID '#1079#1072#1076#1072#1095#1080
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'parent'
        Title.Caption = 'ID '#1087#1088#1086#1077#1082#1090#1072
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'task'
        Title.Caption = #1058#1077#1082#1089#1090' '#1079#1072#1076#1072#1095#1080
        Width = 498
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'task_percent'
        Title.Caption = #1055#1088#1086#1094#1077#1085#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103
        Width = 112
        Visible = True
      end>
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 772
    Height = 22
    Caption = 'ToolBar1'
    Images = Tasks_MainForm.ImageList1
    TabOrder = 1
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1076#1072#1095#1091' '#1074' '#1087#1088#1086#1077#1082#1090
      Caption = 'ToolButton1'
      ImageIndex = 60
      ParentShowHint = False
      ShowHint = True
      OnClick = DBGrid1DblClick
    end
    object ToolButton3: TToolButton
      Left = 23
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object ToolButton2: TToolButton
      Left = 31
      Top = 0
      Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1092#1086#1088#1084#1091
      Caption = 'ToolButton2'
      ImageIndex = 55
      OnClick = ToolButton2Click
    end
    object edTaskID: TEdit
      Left = 54
      Top = 0
      Width = 121
      Height = 22
      Hint = #1042#1074#1077#1076#1080#1090#1077' ID '#1079#1072#1076#1072#1095#1080
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnChange = edTaskIDChange
    end
    object ToolButton5: TToolButton
      Left = 175
      Top = 0
      Width = 8
      Caption = 'ToolButton5'
      ImageIndex = 57
      Style = tbsSeparator
    end
    object tbtShowCompleted: TToolButton
      Left = 183
      Top = 0
      Hint = #1057#1082#1088#1099#1090#1100'/'#1055#1086#1082#1072#1079#1072#1090#1100' '#1079#1072#1074#1077#1088#1096#1077#1085#1085#1099#1077
      Caption = 'tbtShowCompleted'
      ImageIndex = 14
      ParentShowHint = False
      ShowHint = True
      OnClick = tbtShowCompletedClick
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 297
    Width = 772
    Height = 19
    Panels = <
      item
        Width = 50
      end>
  end
  object FDQuery1: TFDQuery
    FieldOptions.PositionMode = poFieldNo
    FieldOptions.UpdatePersistent = True
    Connection = Tasks_MainForm.FDConnection1
    SQL.Strings = (
      'SELECT t.task_id, t.parent, t.task  FROM tasks t'
      'where project = 0 ;')
    Left = 328
    Top = 88
  end
  object DataSource1: TDataSource
    DataSet = FDTable1
    Enabled = False
    Left = 200
    Top = 112
  end
  object FDCommand1: TFDCommand
    Connection = Tasks_MainForm.FDConnection1
    Left = 552
    Top = 120
  end
  object FDTable1: TFDTable
    FieldOptions.UpdatePersistent = True
    Connection = Tasks_MainForm.FDConnection1
    FormatOptions.AssignedValues = [fvSortOptions]
    FormatOptions.SortOptions = [soDescNullLast]
    Left = 96
    Top = 72
  end
end
