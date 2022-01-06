void PosPointer()
{
  if (value > old_value)
  {
    if ((menu_list_count == 3) && (pos_pointer > 26))
    {
      pos_pointer = 26;
    }

    if (pos_pointer > 46)
    {
      pos_pointer = 16;
      if (menu_list_count > 3)
        menu_list_count = 3;
      else
        menu_list_count += 1;
    }
    else
      pos_pointer += 10;
  }

  if (value < old_value)
  {
    if ((menu_list_count == 0) && (pos_pointer < 26))
    {
      pos_pointer = 26;
    }
    if (pos_pointer < 26)
    {
      pos_pointer = 56;
      if (menu_list_count < 0)
        menu_list_count = 0;
      else
        menu_list_count -= 1;
    }
    else
      pos_pointer -= 10;
  }
}
void InitDisplay()
{
  myOLED.begin();
  myOLED.setFont(SmallFont);
  myOLED.setBrightness(255);
}

void DrawMenuList0(byte pos)
{
  myOLED.clrScr();
  myOLED.print("SETTINGS ", CENTER, 0);
  myOLED.print(">", 0, pos);
  myOLED.print("1.  ByPass", 10, 16);
  myOLED.print("2.  PGA", 10, 26);
  myOLED.print("3.  Gain", 10, 36);
  myOLED.print("4.  MUX Ch", 10, 46);
  myOLED.print("5.  BSC", 10, 56);
  myOLED.update();
}

void DrawMenuList1(byte pos)
{
  myOLED.clrScr();
  myOLED.print("SETTINGS ", CENTER, 0);
  myOLED.print(">", 0, pos);
  myOLED.print("6.  TempSens", 10, 16);
  myOLED.print("7.  Conversion", 10, 26);
  myOLED.print("8.  Operating", 10, 36);
  myOLED.print("9.  SPS", 10, 46);
  myOLED.print("10. IDAC current", 10, 56);
  myOLED.update();
}

void DrawMenuList2(byte pos)
{
  myOLED.clrScr();
  myOLED.print("SETTINGS ", CENTER, 0);
  myOLED.print(">", 0, pos);
  myOLED.print("11.  PWS", 10, 16);
  myOLED.print("12.  FIR", 10, 26);
  myOLED.print("13.  VREF", 10, 36);
  myOLED.print("14.  DRYM", 10, 46);
  myOLED.print("15.  IDAC2 routing", 10, 56);
  myOLED.update();
}

void DrawMenuList3(byte pos)
{
  myOLED.clrScr();
  myOLED.print("SETTINGS ", CENTER, 0);
  myOLED.print(">", 0, pos);
  myOLED.print("16.  IDAC1 routing", 10, 16);
  myOLED.print("17.  RESET", 10, 26);
  myOLED.print("18.  BACK", 10, 36);
  myOLED.update();
}
