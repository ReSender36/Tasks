object ProjectDet_Form: TProjectDet_Form
  Left = 0
  Top = 0
  Caption = #1044#1077#1090#1072#1083#1080' '#1087#1088#1086#1077#1082#1090#1072
  ClientHeight = 496
  ClientWidth = 976
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 8
    Top = 16
    Width = 56
    Height = 13
    Caption = 'ID '#1087#1088#1086#1077#1082#1090#1072
  end
  object Label3: TLabel
    Left = 248
    Top = 16
    Width = 73
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
  end
  object Label4: TLabel
    Left = 703
    Top = 56
    Width = 81
    Height = 13
    Caption = #1057#1090#1072#1090#1091#1089' '#1087#1088#1086#1077#1082#1090#1072
  end
  object Label5: TLabel
    Left = 327
    Top = 32
    Width = 2
    Height = 10
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -8
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 703
    Top = 95
    Width = 48
    Height = 13
    Caption = #1048#1089#1090#1086#1095#1085#1080#1082
  end
  object Label7: TLabel
    Left = 248
    Top = 76
    Width = 67
    Height = 13
    Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081
  end
  object Label9: TLabel
    Left = 687
    Top = 150
    Width = 108
    Height = 13
    Caption = #1055#1088#1086#1094#1077#1085#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103
  end
  object Label10: TLabel
    Left = 687
    Top = 123
    Width = 177
    Height = 13
    Caption = #1063#1080#1089#1083#1086' '#1079#1072#1076#1072#1095' '#1074' '#1087#1088#1086#1077#1082#1090#1077'/'#1074#1099#1087#1086#1083#1085#1077#1085#1086
  end
  object Label8: TLabel
    Left = 200
    Top = 48
    Width = 122
    Height = 13
    Caption = #1050#1088#1072#1090#1082#1086#1077' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label11: TLabel
    Left = 328
    Top = 66
    Width = 2
    Height = 10
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -8
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 87
    Top = 13
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 0
  end
  object ComboBox1: TComboBox
    Left = 790
    Top = 53
    Width = 169
    Height = 21
    TabOrder = 2
  end
  object ComboBox2: TComboBox
    Left = 757
    Top = 93
    Width = 202
    Height = 21
    TabOrder = 3
  end
  object BitBtn1: TBitBtn
    Left = 782
    Top = 463
    Width = 75
    Height = 25
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 6
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 884
    Top = 463
    Width = 75
    Height = 25
    Kind = bkClose
    NumGlyphs = 2
    TabOrder = 7
  end
  object Edit2: TEdit
    Left = 327
    Top = 13
    Width = 632
    Height = 21
    ReadOnly = True
    TabOrder = 1
    OnChange = Edit2Change
  end
  object GroupBox1: TGroupBox
    Left = 534
    Top = 95
    Width = 153
    Height = 81
    Caption = #1069#1082#1089#1087#1086#1088#1090' '#1074' SD'
    TabOrder = 8
    object Label1: TLabel
      Left = 9
      Top = 50
      Width = 36
      Height = 13
      Caption = 'ID '#1074' SD'
    end
    object CheckBox1: TCheckBox
      Left = 9
      Top = 24
      Width = 129
      Height = 17
      Caption = #1053#1091#1078#1077#1085' '#1101#1082#1089#1087#1086#1088#1090' '#1074' SD'
      TabOrder = 0
      OnClick = CheckBox1Click
    end
    object Edit4: TEdit
      Left = 51
      Top = 47
      Width = 87
      Height = 21
      TabOrder = 1
    end
  end
  object RadioGroup1: TRadioGroup
    Left = 3
    Top = 55
    Width = 113
    Height = 85
    Caption = #1055#1088#1080#1086#1088#1080#1090#1077#1090' '#1087#1088#1086#1077#1082#1090#1072
    TabOrder = 4
  end
  object RadioButton1: TRadioButton
    Left = 41
    Top = 70
    Width = 40
    Height = 17
    Caption = '1'
    TabOrder = 9
    OnClick = RadioButtonClick
  end
  object RadioButton2: TRadioButton
    Left = 41
    Top = 93
    Width = 40
    Height = 17
    Caption = '2'
    TabOrder = 10
  end
  object RadioButton3: TRadioButton
    Left = 41
    Top = 115
    Width = 40
    Height = 17
    Caption = '3'
    TabOrder = 11
  end
  object Memo1: TMemo
    Left = 248
    Top = 95
    Width = 272
    Height = 81
    TabOrder = 5
  end
  object Edit5: TEdit
    Left = 889
    Top = 147
    Width = 70
    Height = 21
    ReadOnly = True
    TabOrder = 12
  end
  object Edit6: TEdit
    Left = 889
    Top = 120
    Width = 70
    Height = 21
    TabOrder = 13
  end
  object GridPanel1: TGridPanel
    Left = 6
    Top = 182
    Width = 971
    Height = 275
    Align = alCustom
    Caption = 'GridPanel1'
    ColumnCollection = <
      item
        Value = 100.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = ToolBar1
        Row = 0
      end
      item
        Column = 0
        Control = DBGrid1
        Row = 1
        RowSpan = 2
      end>
    FullRepaint = False
    RowCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 22.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 409.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
      end>
    TabOrder = 14
    object ToolBar1: TToolBar
      Left = 1
      Top = 1
      Width = 969
      Height = 22
      Anchors = []
      Caption = 'ToolBar1'
      Images = Tasks_MainForm.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1076#1072#1095#1091' '#1074' '#1087#1088#1086#1077#1082#1090
        Caption = 'ToolButton1'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton1Click
      end
      object ToolButton4: TToolButton
        Left = 23
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1076#1072#1095#1091' '#1080#1079' '#1087#1088#1086#1077#1082#1090#1072
        Caption = 'ToolButton4'
        ImageIndex = 3
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton4Click
      end
      object ToolButton5: TToolButton
        Left = 46
        Top = 0
        Width = 8
        Caption = 'ToolButton5'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton2: TToolButton
        Left = 54
        Top = 0
        Hint = #1055#1086#1089#1084#1086#1090#1088#1077#1090#1100' '#1076#1077#1090#1072#1083#1080' '#1079#1072#1076#1072#1095#1080
        Caption = 'ToolButton2'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton3: TToolButton
        Left = 77
        Top = 0
        Hint = #1055#1077#1088#1077#1089#1095#1080#1090#1072#1090#1100' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1077' '#1087#1088#1086#1077#1082#1090#1072
        Caption = 'ToolButton3'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton3Click
      end
    end
    object DBGrid1: TDBGrid
      Left = 0
      Top = 26
      Width = 969
      Height = 249
      Align = alCustom
      DataSource = DataSource1
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Font.Quality = fqAntialiased
      ParentFont = False
      PopupMenu = Tasks_MainForm.PopupMenu1
      TabOrder = 1
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      OnCellClick = DBGrid1CellClick
      OnDrawColumnCell = DBGrid1DrawColumnCell
      OnEditButtonClick = DBGrid1EditButtonClick
      Columns = <
        item
          Alignment = taCenter
          ButtonStyle = cbsEllipsis
          Expanded = False
          FieldName = 'task_id'
          Title.Alignment = taCenter
          Title.Caption = 'ID '#1079#1072#1076#1072#1095#1080
          Width = 55
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'order_in_project'
          Title.Alignment = taCenter
          Title.Caption = #1053#1086#1084#1077#1088' '#1087'/'#1087
          Width = 60
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'task'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          Font.Quality = fqAntialiased
          Title.Caption = #1047#1072#1076#1072#1095#1072
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'task_percent'
          Title.Caption = #1055#1088#1086#1094#1077#1085#1090' '#1075#1086#1090#1086#1074#1085#1086#1089#1090#1080
          Visible = True
        end
        item
          ButtonStyle = cbsEllipsis
          Expanded = False
          FieldName = 'ud_weight_in_project'
          Title.Caption = #1059#1076#1077#1083#1100#1085#1099#1081' '#1074#1077#1089' '#1079#1072#1076#1072#1095#1080
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'task_complete'
          ImeMode = imAlpha
          Title.Caption = #1054#1090#1084#1077#1090#1082#1072' '#1086' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1080
          Visible = True
        end>
    end
  end
  object CheckBox2: TCheckBox
    Left = 543
    Top = 47
    Width = 144
    Height = 42
    Caption = #1040#1074#1090#1086#1088#1072#1089#1095#1077#1090' '#1074#1077#1089#1086#1074' '#1079#1072#1076#1072#1095' '#1074' '#1087#1088#1086#1077#1082#1090#1077
    TabOrder = 15
    WordWrap = True
  end
  object edShortPrName: TEdit
    Left = 328
    Top = 45
    Width = 121
    Height = 21
    TabOrder = 16
    OnChange = edShortPrNameChange
  end
  object fdqTasksInProj: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    SQL.Strings = (
      
        'SELECT t.task_id, t.parent, order_in_project, t.task, t.task_per' +
        'cent, '
      't.task_complete,t.ud_weight_in_project'
      '  FROM tasks t'
      'order by 3,4 ;')
    Left = 446
    Top = 232
  end
  object DataSource1: TDataSource
    DataSet = fdqTasksInProj
    Enabled = False
    Left = 310
    Top = 288
  end
  object FDQuery1: TFDQuery
    Connection = Tasks_MainForm.FDConnection1
    Left = 152
    Top = 48
  end
  object fdqProjDet: TFDQuery
    Left = 152
    Top = 104
  end
  object FDCommand1: TFDCommand
    Connection = Tasks_MainForm.FDConnection1
    Left = 550
    Top = 288
  end
end
