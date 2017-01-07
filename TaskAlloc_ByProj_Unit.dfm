object TaskAlloc_ByProj_Form: TTaskAlloc_ByProj_Form
  Left = 0
  Top = 0
  Caption = #1042#1099#1073#1086#1088' '#1079#1072#1076#1072#1095#1080' - '#1082#1086#1088#1085#1103' '#1087#1088#1086#1077#1082#1090#1072
  ClientHeight = 373
  ClientWidth = 752
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
    AlignWithMargins = True
    Left = 3
    Top = 25
    Width = 746
    Height = 326
    Align = alClient
    DataSource = DataSource1
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
        Alignment = taCenter
        Expanded = False
        FieldName = 'task_id'
        Title.Alignment = taCenter
        Title.Caption = 'id '#1079#1072#1076#1072#1095#1080
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
        Alignment = taCenter
        Expanded = False
        FieldName = 'parent'
        Title.Alignment = taCenter
        Title.Caption = #1056#1086#1076#1080#1090#1077#1083#1100
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'task_group'
        Title.Alignment = taCenter
        Title.Caption = #1043#1088#1091#1087#1087#1072' '#1079#1072#1076#1072#1095
        Width = 72
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'planned_date'
        Title.Alignment = taCenter
        Title.Caption = #1055#1083#1072#1085#1080#1088#1091#1077#1084#1072#1103' '#1076#1072#1090#1072
        Width = 108
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'task_percent'
        Title.Alignment = taCenter
        Title.Caption = #1055#1088#1086#1094#1077#1085#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103
        Width = 115
        Visible = True
      end>
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 752
    Height = 22
    Caption = 'ToolBar1'
    Images = Tasks_MainForm.ImageList1
    TabOrder = 1
    object tbtShowCompleted: TToolButton
      Left = 0
      Top = 0
      Caption = 'tbtShowCompleted'
      ImageIndex = 14
      OnClick = tbtShowCompletedClick
    end
    object ToolButton2: TToolButton
      Left = 23
      Top = 0
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 1
      Style = tbsSeparator
    end
    object edTaskID: TEdit
      Left = 31
      Top = 0
      Width = 121
      Height = 22
      TabOrder = 0
      OnChange = edTaskIDChange
    end
    object ToolButton1: TToolButton
      Left = 152
      Top = 0
      Width = 8
      Caption = 'ToolButton1'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object cbxFilterTaskGroup: TComboBox
      Left = 160
      Top = 0
      Width = 145
      Height = 21
      TabOrder = 1
      OnSelect = cbxFilterTaskGroupSelect
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 354
    Width = 752
    Height = 19
    Panels = <
      item
        Width = 300
      end
      item
        Width = 150
      end>
  end
  object FDQuery1: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    SQL.Strings = (
      
        'select task_id,task,parent,taskGrpID,task_group,planned_date,tas' +
        'k_percent'
      'from tasks_allocation ;')
    Left = 312
    Top = 96
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Enabled = False
    Left = 192
    Top = 192
  end
end
