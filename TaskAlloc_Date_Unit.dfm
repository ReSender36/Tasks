object TaskAlloc_Date: TTaskAlloc_Date
  Left = 0
  Top = 0
  Caption = #1056#1072#1089#1087#1088#1077#1076#1077#1083#1103#1077#1084' '#1079#1072#1076#1072#1095#1080' '#1087#1086' '#1076#1072#1090#1072#1084
  ClientHeight = 373
  ClientWidth = 754
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 0
    Top = 24
    Width = 753
    Height = 329
    DataSource = DataSource1
    Enabled = False
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    PopupMenu = PopupMenu1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
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
  object StatusBar1: TStatusBar
    Left = 0
    Top = 354
    Width = 754
    Height = 19
    Panels = <>
    ExplicitLeft = 392
    ExplicitTop = 352
    ExplicitWidth = 0
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 754
    Height = 25
    Caption = 'ToolBar1'
    Images = Tasks_MainForm.ImageList1
    TabOrder = 2
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Width = 8
      Caption = 'ToolButton1'
      Style = tbsSeparator
    end
    object edTaskID: TEdit
      Left = 8
      Top = 0
      Width = 121
      Height = 22
      Hint = #1042#1074#1077#1076#1080#1090#1077' ID '#1079#1072#1076#1072#1095#1080
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
    end
    object ToolButton2: TToolButton
      Left = 129
      Top = 0
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 0
      Style = tbsSeparator
    end
    object tbtShowCompleted: TToolButton
      Left = 137
      Top = 0
      Hint = #1057#1082#1088#1099#1090#1100'/'#1055#1086#1082#1072#1079#1072#1090#1100' '#1079#1072#1074#1077#1088#1096#1077#1085#1085#1099#1077
      Caption = 'tbtShowCompleted'
      ImageIndex = 14
      ParentShowHint = False
      ShowHint = True
      OnClick = tbtShowCompletedClick
    end
  end
  object FDQuery1: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    SQL.Strings = (
      'select * from tasks_allocation ;')
    Left = 256
    Top = 40
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Enabled = False
    Left = 128
    Top = 48
  end
  object PopupMenu1: TPopupMenu
    Left = 240
    Top = 104
    object N1: TMenuItem
      Caption = #1053#1072' '#1089#1077#1075#1086#1076#1085#1103
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1053#1072' '#1079#1072#1074#1090#1088#1072
      OnClick = N2Click
    end
    object N4: TMenuItem
      Caption = #1053#1072' '#1082#1086#1085#1077#1094' '#1090#1077#1082#1091#1097#1077#1075#1086' '#1075#1086#1076#1072
      OnClick = N4Click
    end
    object N3: TMenuItem
      Caption = #1053#1072' '#1087#1088#1086#1080#1079#1074#1086#1083#1100#1085#1091#1102' '#1076#1072#1090#1091
      OnClick = N3Click
    end
  end
  object FDCommand1: TFDCommand
    Connection = Tasks_MainForm.FDConnection1
    Left = 400
    Top = 152
  end
end
