void PosPointerMainMenu()
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

void PosPointerSubMenu()
{
  if (value > old_value)
  {
    pos_pointer_sub += 10;
  }
  if (value < old_value)
  {
    pos_pointer_sub -= 10;
  }
}

void InitDisplay()
{
  myOLED.begin();
  myOLED.setFont(SmallFont);
  myOLED.setBrightness(255);
  myOLED.clrScr();
}

void DrawMenuList(byte count, byte pos)
{
  myOLED.clrScr();
  myOLED.print(F("SETTINGS "), CENTER, 0);
  myOLED.print(F(">"), 0, pos);

  switch (count)
  {
  case 0:
    myOLED.print(F("1.  ByPass"), 10, 16);
    myOLED.print(F("2.  PGA"), 10, 26);
    myOLED.print(F("3.  Gain"), 10, 36);
    myOLED.print(F("4.  MUX Ch"), 10, 46);
    myOLED.print(F("5.  BSC"), 10, 56);
    break;

  case 1:
    myOLED.print(F("6.  TempSens"), 10, 16);
    myOLED.print(F("7.  Conversion"), 10, 26);
    myOLED.print(F("8.  Operating"), 10, 36);
    myOLED.print(F("9.  SPS"), 10, 46);
    myOLED.print(F("10. IDAC current"), 10, 56);
    break;

  case 2:
    myOLED.print(F("11.  PWS"), 10, 16);
    myOLED.print(F("12.  FIR"), 10, 26);
    myOLED.print(F("13.  VREF"), 10, 36);
    myOLED.print(F("14.  DRYM"), 10, 46);
    myOLED.print(F("15.  IDAC2 routing"), 10, 56);
    break;

  case 3:
    myOLED.print(F("16.  IDAC1 routing"), 10, 16);
    myOLED.print(F("17.  RESET"), 10, 26);
    myOLED.print(F("18.  BACK"), 10, 36);
    break;
  }
  myOLED.update();
}

void DrawSubMenu(byte count, byte pos)
{
  myOLED.clrScr();
  myOLED.print(F("SETTINGS"), CENTER, 0);
  myOLED.print(F(">"), 0, pos);
  switch (count)
  {
  case 1:
    limit_value = 3;
    myOLED.print(F("1.  ByPass ON"), 10, 16);
    myOLED.print(F("2.  ByPass OFF"), 10, 26);
    myOLED.print(F("3.  Back"), 10, 36);
    break;

  case 2:

    limit_value = 9;

    myOLED.print(F("1.  Gain 1"), 10, 16);
    myOLED.print(F("2.  Gain 2"), 10, 26);
    myOLED.print(F("3.  Gain 4"), 10, 36);
    myOLED.print(F("4.  Gain 8"), 10, 46);
    myOLED.print(F("5.  Gain 16"), 10, 56);

    myOLED.print(F("6.  Gain 32"), 10, 16);
    myOLED.print(F("7.  Gain 64"), 10, 26);
    myOLED.print(F("8.  Gain 128"), 10, 36);
    myOLED.print(F("9.  Back"), 10, 46);
    break;

  case 3:
    limit_value = 18;

    myOLED.print(F("1.  MUX_AIN0_AIN1"), 10, 16);
    myOLED.print(F("2.  MUX_AIN0_AIN2"), 10, 26);
    myOLED.print(F("3.  MUX_AIN0_AIN3"), 10, 36);
    myOLED.print(F("4.  MUX_AIN1_AIN2"), 10, 46);
    myOLED.print(F("5.  MUX_AIN1_AIN3"), 10, 56);

    myOLED.print(F("6.  MUX_AIN2_AIN3"), 10, 16);
    myOLED.print(F("7.  MUX_AIN1_AIN0"), 10, 26);
    myOLED.print(F("8.  MUX_AIN3_AIN2"), 10, 36);
    myOLED.print(F("9.  MUX_AIN0_AVSS"), 10, 46);
    myOLED.print(F("10. MUX_AIN1_AVSS"), 10, 56);

    myOLED.print(F("11. MUX_AIN2_AIN3"), 10, 16);
    myOLED.print(F("12. MUX_AIN1_AIN0"), 10, 26);
    myOLED.print(F("13. MUX_AIN3_AIN2"), 10, 36);
    myOLED.print(F("14. MUX_AIN0_AVSS"), 10, 46);
    myOLED.print(F("15. MUX_AIN1_AVSS"), 10, 56);

    myOLED.print(F("16. MUX_AIN2_AVSS"), 10, 16);
    myOLED.print(F("17. MUX_AIN3_AVSS"), 10, 26);
    myOLED.print(F("18. Back"), 10, 36);
    break;

  case 4:
    limit_value = 3;

    myOLED.print(F("1.  BCS_OFF"), 10, 16);
    myOLED.print(F("2.  BCS_ON "), 10, 26);
    myOLED.print(F("3.  Back"), 10, 36);
    break;

  case 5:
    limit_value = 3;

    myOLED.print(F("1.  TS OFF"), 10, 16);
    myOLED.print(F("2.  TSS ON"), 10, 26);
    myOLED.print(F("3.  Back"), 10, 36);

    break;

  case 6:
    limit_value = 3;

    myOLED.print(F("1.  Single short mode"), 10, 16);
    myOLED.print(F("2.  Continuous mode"), 10, 26);
    myOLED.print(F("3.  Back"), 10, 36);

    break;

  case 7:
    limit_value = 4;

    myOLED.print(F("1.  Normal_Mode"), 10, 16);
    myOLED.print(F("2.  Duty cycle mode"), 10, 26);
    myOLED.print(F("3.  Turbo mode"), 10, 36);
    myOLED.print(F("4.  Back"), 10, 46);

    break;

  case 8:
    limit_value = 8;

    myOLED.print(F("1.  20 SPS"), 10, 16);
    myOLED.print(F("2.  45 SPS"), 10, 26);
    myOLED.print(F("3.  90 SPS"), 10, 36);
    myOLED.print(F("4.  175 SPS"), 10, 46);
    myOLED.print(F("5.  330 SPS"), 10, 46);

 
    myOLED.print(F("6.  600 SPS"), 10, 16);
    myOLED.print(F("7.  1000 SPS"), 10, 26);
    myOLED.print(F("8.  Back"), 10, 36);
  
  break;

case 9:
  break;

case 10:

  break;
case 11:

  break;
case 12:

  break;
case 13:

  break;
case 14:

  break;
case 15:

  break;
case 16:

  break;
case 17:

  break;
case 18:

  break;
  
}
myOLED.update();
}

