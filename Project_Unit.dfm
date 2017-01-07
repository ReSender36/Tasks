object Projects_Form: TProjects_Form
  Left = 0
  Top = 0
  Caption = #1055#1088#1086#1077#1082#1090#1099
  ClientHeight = 399
  ClientWidth = 1017
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
  object BitBtn1: TBitBtn
    Left = 934
    Top = 370
    Width = 75
    Height = 25
    Kind = bkClose
    NumGlyphs = 2
    TabOrder = 0
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 22
    Width = 1017
    Height = 346
    Align = alTop
    DataSource = DataSource1
    Enabled = False
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 1
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
        FieldName = 'pr_id'
        Title.Caption = 'ID '#1087#1088#1086#1077#1082#1090#1072
        Width = 0
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'pr_task_id'
        Title.Caption = 'ID '#1082#1086#1088#1085#1077#1074#1086#1081' '#1079#1072#1076#1072#1095#1080' '#1074' tasks'
        Width = 0
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'pr_priority'
        Title.Alignment = taCenter
        Title.Caption = #1055#1088#1080#1086#1088#1080#1090#1077#1090' '#1087#1088#1086#1077#1082#1090#1072
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'task'
        Title.Alignment = taCenter
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1087#1088#1086#1077#1082#1090#1072
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Visible = True
      end
      item
        Alignment = taCenter
        ButtonStyle = cbsEllipsis
        Expanded = False
        FieldName = 'pr_state_capt'
        PickList.Strings = (
          '123'
          '321')
        Title.Alignment = taCenter
        Title.Caption = #1057#1090#1072#1090#1091#1089' '#1087#1088#1086#1077#1082#1090#1072
        Width = 115
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'caption'
        Title.Alignment = taCenter
        Title.Caption = #1048#1085#1080#1094#1080#1072#1090#1086#1088' '#1087#1088#1086#1077#1082#1090#1072
        Width = 200
        Visible = True
      end>
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1017
    Height = 22
    Caption = 'ToolBar1'
    Images = Tasks_MainForm.ImageList1
    TabOrder = 2
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1088#1086#1077#1082#1090
      Caption = 'ToolButton1'
      ImageIndex = 0
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButton1Click
    end
    object ToolButton2: TToolButton
      Left = 23
      Top = 0
      Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1087#1088#1086#1077#1082#1090
      Caption = 'ToolButton2'
      ImageIndex = 1
      ParentShowHint = False
      ShowHint = True
      OnClick = DBGrid1DblClick
    end
    object ToolButton3: TToolButton
      Left = 46
      Top = 0
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1087#1088#1086#1077#1082#1090
      Caption = 'ToolButton3'
      ImageIndex = 32
      OnClick = ToolButton3Click
    end
  end
  object fdqMainDBG: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    SQL.Strings = (
      'select pr_id,pr_task_id,pr_priority,task,pr_state_capt,caption '
      'from base_projectview '
      'order by 3,4;')
    Left = 432
    Top = 104
  end
  object DataSource1: TDataSource
    DataSet = fdqMainDBG
    Enabled = False
    Left = 200
    Top = 168
  end
  object PopupMenu1: TPopupMenu
    Left = 336
    Top = 184
  end
  object fdqFindEnv: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    Left = 432
    Top = 160
  end
  object FDCommand1: TFDCommand
    Connection = Tasks_MainForm.FDConnection1
    Left = 440
    Top = 224
  end
end
