object TaskAlloc_Group: TTaskAlloc_Group
  Left = 0
  Top = 0
  Caption = #1056#1072#1089#1087#1088#1077#1076#1077#1083#1103#1077#1084' '#1079#1072#1076#1072#1095#1080' '#1087#1086' '#1075#1088#1091#1087#1087#1072#1084
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
    Top = 0
    Width = 753
    Height = 338
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
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'task_id'
        Title.Alignment = taCenter
        Title.Caption = 'ID '#1079#1072#1076#1072#1095#1080
        Width = 55
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'task'
        Title.Alignment = taCenter
        Title.Caption = #1047#1072#1076#1072#1095#1072
        Width = 300
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'parent'
        Title.Alignment = taCenter
        Title.Caption = #1056#1086#1076#1080#1090#1077#1083#1100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'task_group'
        Title.Alignment = taCenter
        Title.Caption = #1043#1088#1091#1087#1087#1072' '#1079#1072#1076#1072#1095
        Width = 72
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'planned_date'
        Title.Alignment = taCenter
        Title.Caption = #1055#1083#1072#1085#1080#1088#1091#1077#1084#1072#1103' '#1076#1072#1090#1072
        Width = 108
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'task_percent'
        Title.Alignment = taCenter
        Title.Caption = #1055#1088#1086#1094#1077#1085#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103
        Width = 115
        Visible = True
      end>
  end
  object BitBtn1: TBitBtn
    Left = 671
    Top = 344
    Width = 75
    Height = 25
    Kind = bkClose
    NumGlyphs = 2
    TabOrder = 1
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Enabled = False
    Left = 240
    Top = 168
  end
  object FDQuery1: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    SQL.Strings = (
      
        'select task_id,task,parent,taskGrpID,task_group,planned_date,tas' +
        'k_percent'
      'from tasks_allocation ;')
    Left = 448
    Top = 112
  end
  object FDCommand1: TFDCommand
    Connection = Tasks_MainForm.FDConnection1
    Left = 560
    Top = 152
  end
  object PopupMenu1: TPopupMenu
    OwnerDraw = True
    Left = 368
    Top = 192
  end
  object FDQuery2: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    Left = 376
    Top = 80
  end
end
