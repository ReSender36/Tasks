object Task_Detail: TTask_Detail
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = #1044#1077#1090#1072#1083#1080' '#1079#1072#1076#1072#1095#1080
  ClientHeight = 487
  ClientWidth = 445
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
    Top = 8
    Width = 49
    Height = 13
    Caption = 'Id '#1079#1072#1076#1072#1095#1080
  end
  object Label2: TLabel
    Left = 8
    Top = 35
    Width = 37
    Height = 13
    Caption = #1047#1072#1076#1072#1095#1072
  end
  object Label4: TLabel
    Left = 253
    Top = 8
    Width = 36
    Height = 13
    Caption = #1043#1088#1091#1087#1087#1072
  end
  object Label5: TLabel
    Left = 79
    Top = 72
    Width = 127
    Height = 13
    Caption = #1048#1089#1090#1086#1095#1085#1080#1082' ('#1082#1090#1086' '#1087#1086#1089#1090#1072#1074#1080#1083')'
  end
  object Label6: TLabel
    Left = 79
    Top = 91
    Width = 67
    Height = 13
    Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081
  end
  object Label7: TLabel
    Left = 321
    Top = 359
    Width = 35
    Height = 13
    Caption = 'Id '#1074' SD'
  end
  object Label8: TLabel
    Left = 331
    Top = 218
    Width = 95
    Height = 13
    Caption = #1055#1083#1072#1085#1080#1088#1091#1077#1084#1072#1103' '#1076#1072#1090#1072
  end
  object Label9: TLabel
    Left = 98
    Top = 176
    Width = 108
    Height = 13
    Caption = #1055#1088#1086#1094#1077#1085#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103
  end
  object Label10: TLabel
    Left = 102
    Top = 53
    Width = 3
    Height = 10
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -8
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 100
    Top = 198
    Width = 75
    Height = 13
    Caption = #1057#1090#1072#1090#1091#1089' '#1079#1072#1076#1072#1095#1080
  end
  object Label14: TLabel
    Left = 331
    Top = 176
    Width = 103
    Height = 13
    Caption = #1044#1072#1090#1072' '#1089#1090#1072#1088#1090#1072' '#1079#1072#1076#1072#1095#1080
  end
  object BitBtn1: TBitBtn
    Left = 286
    Top = 397
    Width = 75
    Height = 25
    Kind = bkOK
    NumGlyphs = 2
    Style = bsWin31
    TabOrder = 14
    OnClick = BitBtn1Click
  end
  object CheckBox1: TCheckBox
    Left = 297
    Top = 333
    Width = 145
    Height = 17
    Caption = #1053#1077#1086#1073#1093#1086#1076#1080#1084' '#1101#1082#1089#1087#1086#1088#1090' '#1074' SD'
    TabOrder = 17
    OnClick = CheckBox1Click
  end
  object Edit1: TEdit
    Left = 362
    Top = 356
    Width = 49
    Height = 21
    TabOrder = 18
  end
  object cbTaskRepeat: TCheckBox
    Left = 297
    Top = 314
    Width = 97
    Height = 17
    Caption = #1055#1086#1074#1090#1086#1088' '#1079#1072#1076#1072#1095#1080
    TabOrder = 19
  end
  object ComboBox1: TComboBox
    Left = 295
    Top = 5
    Width = 145
    Height = 21
    TabOrder = 8
  end
  object Edit5: TEdit
    Left = 63
    Top = 5
    Width = 75
    Height = 21
    ReadOnly = True
    TabOrder = 0
  end
  object Edit6: TEdit
    Left = 63
    Top = 32
    Width = 376
    Height = 21
    TabOrder = 1
    OnChange = Edit6Change
  end
  object Edit7: TEdit
    Left = 212
    Top = 168
    Width = 96
    Height = 21
    ReadOnly = True
    TabOrder = 21
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 71
    Width = 65
    Height = 121
    Caption = #1042#1072#1078#1085#1086#1089#1090#1100
    TabOrder = 16
  end
  object RadioButton1: TRadioButton
    Left = 22
    Top = 88
    Width = 33
    Height = 17
    Caption = '1'
    TabOrder = 3
    OnClick = RadioButtonClick
  end
  object RadioButton2: TRadioButton
    Left = 22
    Top = 108
    Width = 33
    Height = 17
    Caption = '2'
    TabOrder = 4
    OnClick = RadioButtonClick
  end
  object RadioButton3: TRadioButton
    Left = 22
    Top = 128
    Width = 33
    Height = 17
    Caption = '3'
    TabOrder = 5
    OnClick = RadioButtonClick
  end
  object RadioButton4: TRadioButton
    Left = 22
    Top = 148
    Width = 33
    Height = 17
    Caption = '4'
    TabOrder = 6
    OnClick = RadioButtonClick
  end
  object RadioButton5: TRadioButton
    Left = 22
    Top = 168
    Width = 33
    Height = 17
    Caption = '5'
    TabOrder = 7
    OnClick = RadioButtonClick
  end
  object ComboBox2: TComboBox
    Left = 212
    Top = 69
    Width = 228
    Height = 21
    TabOrder = 9
  end
  object DateTimePicker1: TDateTimePicker
    Left = 331
    Top = 234
    Width = 106
    Height = 21
    Date = 42072.564999386570000000
    Time = 42072.564999386570000000
    TabOrder = 11
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 428
    Width = 434
    Height = 53
    Caption = #1044#1077#1090#1072#1083#1080' '#1087#1086#1074#1090#1086#1088#1077#1085#1080#1103
    TabOrder = 22
  end
  object BitBtn2: TBitBtn
    Left = 367
    Top = 397
    Width = 75
    Height = 25
    Kind = bkClose
    NumGlyphs = 2
    TabOrder = 15
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 326
    Width = 265
    Height = 105
    Caption = #1055#1088#1086#1077#1082#1090
    TabOrder = 23
    object Label11: TLabel
      Left = 3
      Top = 61
      Width = 151
      Height = 13
      Caption = #1055#1086#1088#1103#1076#1082#1086#1074#1099#1081' '#1085#1086#1084#1077#1088' '#1074' '#1087#1088#1086#1077#1082#1090#1077
    end
    object Label12: TLabel
      Left = 3
      Top = 83
      Width = 126
      Height = 13
      Caption = #1059#1076#1077#1083#1100#1085#1099#1081' '#1074#1077#1089' '#1074' '#1087#1088#1086#1077#1082#1090#1077
    end
    object Label13: TLabel
      Left = 3
      Top = 16
      Width = 115
      Height = 13
      Caption = #1055#1088#1080#1085#1072#1076#1083#1077#1078#1080#1090' '#1087#1088#1086#1077#1082#1090#1091
    end
    object Edit2: TEdit
      Left = 3
      Top = 30
      Width = 254
      Height = 21
      TabOrder = 0
    end
    object Edit3: TEdit
      Left = 160
      Top = 58
      Width = 97
      Height = 21
      TabOrder = 1
    end
    object Edit4: TEdit
      Left = 160
      Top = 80
      Width = 97
      Height = 21
      TabOrder = 2
    end
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 222
    Width = 245
    Height = 98
    DataSource = DataSource1
    Enabled = False
    TabOrder = 24
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'exec_date'
        Title.Caption = #1044#1072#1090#1072' '#1088#1072#1073#1086#1090#1099
        Width = 84
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'percent_complete'
        Title.Caption = #1055#1088#1086#1094#1077#1085#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103
        Width = 115
        Visible = True
      end>
  end
  object ComboBox3: TComboBox
    Left = 212
    Top = 195
    Width = 96
    Height = 21
    TabOrder = 12
  end
  object CheckBox3: TCheckBox
    Left = 297
    Top = 295
    Width = 97
    Height = 17
    Caption = #1069#1090#1086' '#1087#1088#1086#1077#1082#1090
    TabOrder = 20
  end
  object Memo1: TMemo
    Left = 79
    Top = 105
    Width = 361
    Height = 51
    ScrollBars = ssVertical
    TabOrder = 13
  end
  object CheckBox4: TCheckBox
    Left = 297
    Top = 272
    Width = 86
    Height = 17
    Caption = #1053#1072' '#1074#1099#1077#1079#1076#1077
    TabOrder = 2
  end
  object DateTimePicker2: TDateTimePicker
    Left = 331
    Top = 195
    Width = 106
    Height = 21
    Date = 42181.557614930560000000
    Time = 42181.557614930560000000
    TabOrder = 10
  end
  object FDQuery1: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    Left = 96
    Top = 104
  end
  object FDCommand1: TFDCommand
    Connection = Tasks_MainForm.FDConnection1
    Left = 192
    Top = 232
  end
  object DataSource1: TDataSource
    DataSet = fdqTasksExec
    Enabled = False
    Left = 64
    Top = 272
  end
  object fdqTasksExec: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    Left = 152
    Top = 104
  end
end
