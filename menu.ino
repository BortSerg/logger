void PosPointer()
{
  if (value > old_value)
  {
    pos_pointer += 10;
    if ((value == 6 || value == 11 || value == 16) && pos_pointer > 56)
    {
      pos_pointer = 16;
    }
  }

  if (value < old_value)
  {
    pos_pointer -= 10;
    if ((value == 5 || value == 10 || value == 15) && pos_pointer < 16)
    {
      pos_pointer = 56;
    }
    if (value == 1 && pos_pointer < 16)
    {
      pos_pointer = 16;
    }
  }
}

void InitDisplay()
{
  myOLED.begin();
  myOLED.setFont(SmallFont);
  myOLED.setBrightness(255);
  myOLED.clrScr();
}

void DrawMenuList(byte pos)
{
  myOLED.clrScr();
  myOLED.print(F("SETTINGS"), CENTER, 0);
  myOLED.print(F(">"), 0, pos);
  limit_value = 17;
  if (value < 6)
  {
    myOLED.print(F("1.  PGA Bypass"), 10, 16);
    myOLED.print(F("2.  PGA gain"), 10, 26);
    myOLED.print(F("3.  MUX Ch"), 10, 36);
    myOLED.print(F("4.  BSC"), 10, 46);
    myOLED.print(F("5.  TempSens"), 10, 56);
  }

  if (value >= 6 && value < 11)
  {
    myOLED.print(F("6.  Conversion"), 10, 16);
    myOLED.print(F("7.  Operating"), 10, 26);
    myOLED.print(F("8.  SPS"), 10, 36);
    myOLED.print(F("9.  IDAC current"), 10, 46);
    myOLED.print(F("10. PWS"), 10, 56);
  }

  if (value >= 11 && value < 16)
  {
    myOLED.print(F("11.  FIR"), 10, 16);
    myOLED.print(F("12.  VREF"), 10, 26);
    myOLED.print(F("13.  DRYM"), 10, 36);
    myOLED.print(F("14.  IDAC2 routing"), 10, 46);
    myOLED.print(F("15.  IDAC1 routing"), 10, 56);
  }

  if (value >= 16)
  {
    myOLED.print(F("16.  RESET"), 10, 16);
    myOLED.print(F("17.  BACK"), 10, 26);
  }

myOLED.update();
}

void DrawSubMenu(byte number_sub_menu, byte pos)
{
  myOLED.clrScr();
  myOLED.print(F("SETTINGS"), CENTER, 0);
  myOLED.print(F(">"), 0, pos);

  switch (number_sub_menu)
  {
  case 1:
    limit_value = 3;
    myOLED.print(F("1.  ByPass ON"), 10, 16);
    myOLED.print(F("2.  ByPass OFF"), 10, 26);
    myOLED.print(F("3.  Back"), 10, 36);
    break;

  case 2:
    limit_value = 9;
    if (value < 6)
    {
      myOLED.print(F("1.  Gain 1"), 10, 16);
      myOLED.print(F("2.  Gain 2"), 10, 26);
      myOLED.print(F("3.  Gain 4"), 10, 36);
      myOLED.print(F("4.  Gain 8"), 10, 46);
      myOLED.print(F("5.  Gain 16"), 10, 56);
    }
    if (value >= 6)
    {
      myOLED.print(F("6.  Gain 32"), 10, 16);
      myOLED.print(F("7.  Gain 64"), 10, 26);
      myOLED.print(F("8.  Gain 128"), 10, 36);
      myOLED.print(F("9.  Back"), 10, 46);
    }
    break;

  case 3:
    limit_value = 18;
    if (value < 6)
    {
      myOLED.print(F("1.  MUX_AIN0_AIN1"), 10, 16);
      myOLED.print(F("2.  MUX_AIN0_AIN2"), 10, 26);
      myOLED.print(F("3.  MUX_AIN0_AIN3"), 10, 36);
      myOLED.print(F("4.  MUX_AIN1_AIN2"), 10, 46);
      myOLED.print(F("5.  MUX_AIN1_AIN3"), 10, 56);
    }
    if (value >= 6 && value < 11)
    {
      myOLED.print(F("6.  MUX_AIN2_AIN3"), 10, 16);
      myOLED.print(F("7.  MUX_AIN1_AIN0"), 10, 26);
      myOLED.print(F("8.  MUX_AIN3_AIN2"), 10, 36);
      myOLED.print(F("9.  MUX_AIN0_AVSS"), 10, 46);
      myOLED.print(F("10. MUX_AIN1_AVSS"), 10, 56);
    }
    if (value >= 11 && value < 16)
    {
      myOLED.print(F("11. MUX_AIN2_AIN3"), 10, 16);
      myOLED.print(F("12. MUX_AIN1_AIN0"), 10, 26);
      myOLED.print(F("13. MUX_AIN3_AIN2"), 10, 36);
      myOLED.print(F("14. MUX_AIN0_AVSS"), 10, 46);
      myOLED.print(F("15. MUX_AIN1_AVSS"), 10, 56);
    }
    if (value >= 16 && value < 19)
    {
      myOLED.print(F("16. MUX_AIN2_AVSS"), 10, 16);
      myOLED.print(F("17. MUX_AIN3_AVSS"), 10, 26);
      myOLED.print(F("18. Back"), 10, 36);
    }
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
    if (value < 6)
    {
      myOLED.print(F("1.  20 SPS"), 10, 16);
      myOLED.print(F("2.  45 SPS"), 10, 26);
      myOLED.print(F("3.  90 SPS"), 10, 36);
      myOLED.print(F("4.  175 SPS"), 10, 46);
      myOLED.print(F("5.  330 SPS"), 10, 56);
    }
    if (value >= 6)
    {
      myOLED.print(F("6.  600 SPS"), 10, 16);
      myOLED.print(F("7.  1000 SPS"), 10, 26);
      myOLED.print(F("8.  Back"), 10, 36);
    }
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
