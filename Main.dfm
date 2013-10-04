object ShittyGameEngine: TShittyGameEngine
  Left = 33
  Top = 332
  Width = 1032
  Height = 802
  Caption = 'ShittyGameEngine'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  OnMouseUp = FormMouseUp
  OnMouseWheel = FormMouseWheel
  OnMouseWheelDown = FormMouseWheelDown
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 12
  object FPSTimer: TTimer
    OnTimer = FPSTimerTimer
    Left = 8
    Top = 8
  end
  object ShittyGameEngineEvents: TApplicationEvents
    OnIdle = ShittyGameEngineEventsIdle
    Left = 600
    Top = 8
  end
end
