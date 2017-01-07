object TaskWrk_Form: TTaskWrk_Form
  Left = 0
  Top = 0
  Caption = #1056#1072#1073#1086#1090#1072' '#1085#1072#1076' '#1079#1072#1076#1072#1095#1077#1081
  ClientHeight = 114
  ClientWidth = 269
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
  object Label1: TLabel
    Left = 8
    Top = 11
    Width = 134
    Height = 13
    Caption = #1044#1072#1090#1072' '#1088#1072#1073#1086#1090#1099' '#1085#1072#1076' '#1079#1072#1076#1072#1095#1077#1081
  end
  object Label2: TLabel
    Left = 8
    Top = 61
    Width = 108
    Height = 13
    Caption = #1055#1088#1086#1094#1077#1085#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103
  end
  object DateTimePicker1: TDateTimePicker
    Left = 148
    Top = 8
    Width = 117
    Height = 21
    Date = 42073.354010162040000000
    Time = 42073.354010162040000000
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 148
    Top = 58
    Width = 117
    Height = 21
    TabOrder = 2
    OnChange = Edit1Change
  end
  object BitBtn1: TBitBtn
    Left = 186
    Top = 85
    Width = 75
    Height = 25
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 3
  end
  object CheckBox1: TCheckBox
    Left = 148
    Top = 35
    Width = 81
    Height = 17
    Caption = #1042#1099#1087#1086#1083#1085#1077#1085#1086
    TabOrder = 1
    OnClick = CheckBox1Click
  end
end
