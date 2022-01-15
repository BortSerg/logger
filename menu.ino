void DrawMainScreen()
{
	myOLED.clrScr();
	myOLED.print(F("ADS1220 Logger"), CENTER, 0);
	myOLED.print(F("ADC value  "), LEFT, 16);
	myOLED.print(F("Voltage "), 0, 26);
	myOLED.printNumF(ADS.ConvertToVoltage(ADS.ReadContinuous()), 2, 50, 26);
	myOLED.print(F("Current "), 0, 46);
	myOLED.printNumF((ADS.ConvertToVoltage(ADS.ReadContinuous())/0.1), 2, 50, 46);
	myOLED.update();
}

void DrawMainMenu(byte pos)
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
		myOLED.print(F("5.  Temp Sensor"), 10, 56);
	}

	if (value >= 6 && value < 11)
	{
		myOLED.print(F("6.  Conversion"), 10, 16);
		myOLED.print(F("7.  Operating"), 10, 26);
		myOLED.print(F("8.  SPS"), 10, 36);
		myOLED.print(F("9.  IDAC current"), 10, 46);
		myOLED.print(F("10. PSW"), 10, 56);
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

	if ((Config.POS_SETTINGS_POINTER[number_sub_menu - 1][0] < 6 && value < 6) || (Config.POS_SETTINGS_POINTER[number_sub_menu - 1][0] >= 6 && Config.POS_SETTINGS_POINTER[number_sub_menu - 1][0] < 11 && value >= 6 && value < 11) || (Config.POS_SETTINGS_POINTER[number_sub_menu - 1][0] >= 11 && Config.POS_SETTINGS_POINTER[number_sub_menu - 1][0] < 14 && value >= 11 && value < 14))
	{
		myOLED.print(F("<"), RIGHT, Config.POS_SETTINGS_POINTER[number_sub_menu - 1][1]);
	}

	switch (number_sub_menu)
	{
	case 1:
		limit_value = 3;
		myOLED.print(F("1.  ByPass OFF"), 10, 16);
		myOLED.print(F("2.  ByPass ON"), 10, 26);
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
		limit_value = 13;
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
		if (value >= 11 && value < 14)
		{
			myOLED.print(F("11. MUX_AIN2_AVSS"), 10, 16);
			myOLED.print(F("12. MUX_AIN3_AVSS"), 10, 26);
			myOLED.print(F("13. Back"), 10, 36);
		}
		break;

	case 4:
		limit_value = 3;
		myOLED.print(F("1.  BCS OFF"), 10, 16);
		myOLED.print(F("2.  BCS ON "), 10, 26);
		myOLED.print(F("3.  Back"), 10, 36);
		break;

	case 5:
		limit_value = 3;
		myOLED.print(F("1.  TS OFF"), 10, 16);
		myOLED.print(F("2.  TS ON"), 10, 26);
		myOLED.print(F("3.  Back"), 10, 36);
		break;

	case 6:
		limit_value = 3;
		myOLED.print(F("1.  Single short"), 10, 16);
		myOLED.print(F("2.  Continuous"), 10, 26);
		myOLED.print(F("3.  Back"), 10, 36);
		break;

	case 7:
		limit_value = 4;
		myOLED.print(F("1.  Normal"), 10, 16);
		myOLED.print(F("2.  Duty cycle"), 10, 26);
		myOLED.print(F("3.  Turbo"), 10, 36);
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
		limit_value = 9;
		if (value < 6)
		{
			myOLED.print(F("1.  IDAC OFF"), 10, 16);
			myOLED.print(F("2.  10uA"), 10, 26);
			myOLED.print(F("3.  50uA"), 10, 36);
			myOLED.print(F("4.  100uA"), 10, 46);
			myOLED.print(F("5.  250uA"), 10, 56);
		}
		if (value >= 6)
		{
			myOLED.print(F("6.  500uA"), 10, 16);
			myOLED.print(F("7.  1000uA"), 10, 26);
			myOLED.print(F("8.  1500uA"), 10, 36);
			myOLED.print(F("9.  Back"), 10, 46);
		}
		break;

	case 10:
		limit_value = 3;
		myOLED.print(F("1.  PSW OPEN"), 10, 16);
		myOLED.print(F("2.  PSW AUTO"), 10, 26);
		myOLED.print(F("3.  Back"), 10, 36);
		break;

	case 11:
		limit_value = 5;
		myOLED.print(F("1.  FIR OFF"), 10, 16);
		myOLED.print(F("2.  50/60 Hz"), 10, 26);
		myOLED.print(F("3.  50 Hz"), 10, 36);
		myOLED.print(F("4.  60 Hz"), 10, 46);
		myOLED.print(F("5.  Back"), 10, 56);
		break;

	case 12:
		limit_value = 5;
		myOLED.print(F("1.  Internal"), 10, 16);
		myOLED.print(F("2.  REFP0 - REFN0"), 10, 26);
		myOLED.print(F("3.  AN0 - AN3"), 10, 36);
		myOLED.print(F("4.  Analog"), 10, 46);
		myOLED.print(F("5.  Back"), 10, 56);
		break;

	case 13:
		limit_value = 3;
		myOLED.print(F("1.  DRDY ONLY"), 10, 16);
		myOLED.print(F("2.  DRDY/DOUT "), 10, 26);
		myOLED.print(F("3.  Back"), 10, 36);
		break;

	case 14:
		limit_value = 8;
		if (value < 6)
		{
			myOLED.print(F("1.  IDAC2 OFF"), 10, 16);
			myOLED.print(F("2.  AIN0 - REFP1"), 10, 26);
			myOLED.print(F("3.  AIN1"), 10, 36);
			myOLED.print(F("4.  AIN2"), 10, 46);
			myOLED.print(F("5.  AIN3 - REFN1"), 10, 56);
		}
		if (value >= 6)
		{
			myOLED.print(F("6.  REFP0"), 10, 16);
			myOLED.print(F("7.  REFN0"), 10, 26);
			myOLED.print(F("8.  Back"), 10, 36);
		}
		break;

	case 15:
		limit_value = 8;
		if (value < 6)
		{
			myOLED.print(F("1.  IDAC1 OFF"), 10, 16);
			myOLED.print(F("2.  AIN0 - REFP1"), 10, 26);
			myOLED.print(F("3.  AIN1"), 10, 36);
			myOLED.print(F("4.  AIN2"), 10, 46);
			myOLED.print(F("5.  AIN3 - REFN1"), 10, 56);
		}
		if (value >= 6)
		{
			myOLED.print(F("6.  REFP0"), 10, 16);
			myOLED.print(F("7.  REFN0"), 10, 26);
			myOLED.print(F("8.  Back"), 10, 36);
		}
		break;

	case 16:
	{
		Serial.println("Restore default settings!");
		Config.FIRST_CHECK_BYTE = 0x50;
		RestoreSettings();

		String s = "Restoring";

		for (byte i = 0; i < 5; i++)
		{
			myOLED.clrScr();
			myOLED.print(s, 10, 6);
			s += ".";
			myOLED.update();
			delay(200);
		}
		BackToMainScreen();
	}
	break;

	case 17:
		BackToMainScreen();
		break;
	}
	myOLED.update();
}
