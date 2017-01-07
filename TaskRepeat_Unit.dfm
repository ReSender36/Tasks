object TaskRepeat_Form: TTaskRepeat_Form
  Left = 0
  Top = 0
  Caption = #1055#1086#1074#1090#1086#1088' '#1079#1072#1076#1072#1095#1080
  ClientHeight = 101
  ClientWidth = 500
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object lbTitle: TLabel
    Left = 8
    Top = 8
    Width = 477
    Height = 19
    Caption = #1059#1082#1072#1078#1080#1090#1077' '#1090#1077#1082#1089#1090' '#1079#1072#1076#1072#1095#1080' '#1080' '#1087#1083#1072#1085#1080#1088#1091#1077#1084#1091#1102' '#1076#1072#1090#1091' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbTaskLength: TLabel
    Left = 22
    Top = 67
    Width = 11
    Height = 13
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -8
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object btbOK: TBitBtn
    Left = 410
    Top = 67
    Width = 75
    Height = 25
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 0
  end
  object dtpTaskRepeat: TDateTimePicker
    Left = 248
    Top = 67
    Width = 130
    Height = 21
    Date = 42444.841778391200000000
    Time = 42444.841778391200000000
    TabOrder = 1
  end
  object edTask: TEdit
    Left = 8
    Top = 40
    Width = 477
    Height = 21
    TabOrder = 2
    OnChange = edTaskChange
  end
end
