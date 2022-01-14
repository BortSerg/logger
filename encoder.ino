void BackToMainMenu()
{
	display_number = 1;

	if (set_settings_flag == true) // если параметр изменился - записать в массив. false только при выборе пункта back
	{
		Serial.println("Set Settings array");
		Config.POS_SETTINGS_POINTER[number_sub_menu - 1][0] = value;
		Config.POS_SETTINGS_POINTER[number_sub_menu - 1][1] = pos_pointer;

		if (number_sub_menu < 4)
		{
			Config.ADS_SETTINGS_BYTE[config_address_reg0] = ADS.ReadConfig(config_address_reg0);
		}
		if (number_sub_menu >= 4 && number_sub_menu < 9)
		{
			Config.ADS_SETTINGS_BYTE[config_address_reg1] = ADS.ReadConfig(config_address_reg1);
		}
		if (number_sub_menu >= 9 && number_sub_menu < 13)
		{
			Config.ADS_SETTINGS_BYTE[config_address_reg2] = ADS.ReadConfig(config_address_reg2);
		}
		if (number_sub_menu >= 13)
		{
			Config.ADS_SETTINGS_BYTE[config_address_reg3] = ADS.ReadConfig(config_address_reg3);
		}
		save_Config();
	}

	pos_pointer = old_pos_pointer;
	value = number_sub_menu;
	old_value = value; // для избежания смещения позиции указателя
	set_settings_flag = true;
	DrawMainMenu(pos_pointer); // отрисовка главного меню без изменения положения энкодера

	delay(200);
}

void BackToMainScreen()
{
	display_number = 0;
	pos_pointer = 16;
	number_sub_menu = 0;
	ADS.Start(); // запуск вычислений
}

void SwitchClick(byte condition) // обработка нажатий на энкодер
{
	if (condition == LOW)
	{
		delay(200);

		switch (display_number)
		{
		case 0:					// обработка входа в меню
			ADS.PowerDown();	// ADS1220 отправить в сон
			value = 1;			// сброс позиции указателя вменю
			old_value += value; //имитация вращения энкодера имитация вращения энкодера для начала прорисовки меню
			display_number = 1;
			break;

		case 1:							   // обработка нажатий в меню для входа в подменю
			old_pos_pointer = pos_pointer; // запоминание позиции указателя на экране до входа в подменю
			pos_pointer = 16;			   // сброс позиции указателя

			number_sub_menu = value; // номер подменю = номеру пункта в основном меню
			value = 1;				 // сброс значений энкодера для отсчета с первого пункта
			old_value += value;		 // имитация вращения энкодера для начала прорисовки меню

			display_number = 2;
			break;

		case 2:
			switch (number_sub_menu)
			{
			case 1: // подменю 1 PGA Bypass
				switch (value)
				{
				case 1:
					ADS.PGA(PGA_BYPASS_OFF);
					BackToMainMenu();
					break;
				case 2:
					ADS.PGA(PGA_BYPASS_ON);
					BackToMainMenu();
					break;
				case 3:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 2: // подменю 2 PGA gain
				switch (value)
				{
				case 1:
					ADS.Gain(GAIN_1);
					BackToMainMenu();
					break;
				case 2:
					ADS.Gain(GAIN_2);
					BackToMainMenu();
					break;
				case 3:
					ADS.Gain(GAIN_4);
					BackToMainMenu();
					break;
				case 4:
					ADS.Gain(GAIN_8);
					BackToMainMenu();
					break;
				case 5:
					ADS.Gain(GAIN_16);
					BackToMainMenu();
					break;
				case 6:
					ADS.Gain(GAIN_32);
					BackToMainMenu();
					break;
				case 7:
					ADS.Gain(GAIN_64);

					BackToMainMenu();
					break;
				case 8:
					ADS.Gain(GAIN_128);
					BackToMainMenu();
					break;
				case 9:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 3: // подменю 3 MUX Ch
				switch (value)
				{
				case 1:
					ADS.MuxChanel(MUX_AIN0_AIN1);
					BackToMainMenu();
					break;
				case 2:
					ADS.MuxChanel(MUX_AIN0_AIN2);
					BackToMainMenu();
					break;
				case 3:
					ADS.MuxChanel(MUX_AIN0_AIN3);
					BackToMainMenu();
					break;
				case 4:
					ADS.MuxChanel(MUX_AIN1_AIN2);
					BackToMainMenu();
					break;
				case 5:
					ADS.MuxChanel(MUX_AIN1_AIN3);
					BackToMainMenu();
					break;
				case 6:
					ADS.MuxChanel(MUX_AIN2_AIN3);
					BackToMainMenu();
					break;
				case 7:
					ADS.MuxChanel(MUX_AIN1_AIN0);
					BackToMainMenu();
					break;
				case 8:
					ADS.MuxChanel(MUX_AIN3_AIN2);
					BackToMainMenu();
					break;
				case 9:
					ADS.MuxChanel(MUX_AIN0_AVSS);
					BackToMainMenu();
					break;
				case 10:
					ADS.MuxChanel(MUX_AIN1_AVSS);
					BackToMainMenu();
					break;
				case 11:
					ADS.MuxChanel(MUX_AIN2_AVSS);
					BackToMainMenu();
					break;
				case 12:
					ADS.MuxChanel(MUX_AIN3_AVSS);
					BackToMainMenu();
					break;
				case 13:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 4: // подменю 4 BSC
				switch (value)
				{
				case 1:
					ADS.BCS(BCS_OFF);
					BackToMainMenu();
					break;
				case 2:
					ADS.BCS(BCS_ON);
					BackToMainMenu();
					break;
				case 3:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 5: // подменю 5 Temp Sensor
				switch (value)
				{
				case 1:
					ADS.TemperatureSensor(TS_OFF);
					BackToMainMenu();
					break;
				case 2:
					ADS.TemperatureSensor(TS_ON);
					BackToMainMenu();
				case 3:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 6: // подменю 6 Conversion mode
				switch (value)
				{
				case 1:
					ADS.ConversionMode(SINGLE_SHORT_MODE);
					BackToMainMenu();
					break;
				case 2:
					ADS.ConversionMode(CONTINUOUS_MODE);
					BackToMainMenu();
					break;
				case 3:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 7: // подменю 7 Operating mode
				switch (value)
				{
				case 1:
					ADS.OperatingMode(NORMAL_MODE);
					BackToMainMenu();
					break;

				case 2:
					ADS.OperatingMode(DUTY_CYCLE_MODE);
					BackToMainMenu();
					break;
				case 3:
					ADS.OperatingMode(TURBO_MODE);
					BackToMainMenu();
					break;
				case 4:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 8: // подменю 8 SPS
				switch (value)
				{
				case 1:
					ADS.DataRate(DR_20SPS);
					BackToMainMenu();
					break;
				case 2:
					ADS.DataRate(DR_45SPS);
					BackToMainMenu();
					break;
				case 3:
					ADS.DataRate(DR_90SPS);
					BackToMainMenu();
					break;
				case 4:
					ADS.DataRate(DR_175SPS);
					BackToMainMenu();
					break;
				case 5:
					ADS.DataRate(DR_330SPS);
					BackToMainMenu();
					break;
				case 6:
					ADS.DataRate(DR_600SPS);
					BackToMainMenu();
					break;
				case 7:
					ADS.DataRate(DR_1000SPS);
					BackToMainMenu();
					break;
				case 8:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 9: // подменю 9 IDAC current
				switch (value)
				{
				case 1:
					ADS.IDAC(IDAC_OFF);
					BackToMainMenu();
					break;
				case 2:
					ADS.IDAC(IDAC_10uA);
					BackToMainMenu();
					break;
				case 3:
					ADS.IDAC(IDAC_50uA);
					BackToMainMenu();
					break;
				case 4:
					ADS.IDAC(IDAC_100uA);
					BackToMainMenu();
					break;
				case 5:
					ADS.IDAC(IDAC_250uA);
					BackToMainMenu();
					break;
				case 6:
					ADS.IDAC(IDAC_500uA);
					BackToMainMenu();
					break;
				case 7:
					ADS.IDAC(IDAC_1000uA);
					BackToMainMenu();
					break;
				case 8:
					ADS.IDAC(IDAC_1500uA);
					BackToMainMenu();
					break;
				case 9:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 10: // подменю 10 PWS
				switch (value)
				{
				case 1:
					ADS.PSW(PSW_OPEN);
					BackToMainMenu();
					break;
				case 2:
					ADS.PSW(PSW_AUTO);
					BackToMainMenu();
					break;
				case 3:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 11: // подменю 11 FIR
				switch (value)
				{
				case 1:
					ADS.FIR(FIR_OFF);
					BackToMainMenu();
					break;
				case 2:
					ADS.FIR(FIR_50_60);
					BackToMainMenu();
					break;
				case 3:
					ADS.FIR(FIR_50);
					BackToMainMenu();
					break;
				case 4:
					ADS.FIR(FIR_60);
					BackToMainMenu();
					break;
				case 5:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 12: // подменю 12 VREF
				switch (value)
				{
				case 1:
					ADS.VREF(VREF_INTERNAL);
					BackToMainMenu();
					break;
				case 2:
					ADS.VREF(VREF_REFP0_REFN0);
					BackToMainMenu();
					break;
				case 3:
					ADS.VREF(VREF_AN0_AN3);
					BackToMainMenu();
					break;
				case 4:
					ADS.VREF(VREF_ANALOG);
					BackToMainMenu();
					break;
				case 5:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 13: // подменю 13 DRYM
				switch (value)
				{
				case 1:
					ADS.DRDYM(DRDYM_DRDY_ONLY);
					BackToMainMenu();
					break;
				case 2:
					ADS.DRDYM(DRDYM_DRDY_DOUT);
					BackToMainMenu();
					break;
				case 3:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 14: // подменю 14 IDAC2 routing
				switch (value)
				{
				case 1:
					ADS.I2MUX(IDAC2_OFF);
					BackToMainMenu();
					break;
				case 2:
					ADS.I2MUX(IDAC2_AIN0_REFP1);
					BackToMainMenu();
					break;
				case 3:
					ADS.I2MUX(IDAC2_AIN1);
					BackToMainMenu();
					break;
				case 4:
					ADS.I2MUX(IDAC2_AIN2);
					BackToMainMenu();
					break;
				case 5:
					ADS.I2MUX(IDAC2_AIN3_REFN1);
					BackToMainMenu();
					break;
				case 6:
					ADS.I2MUX(IDAC2_REFP0);
					BackToMainMenu();
					break;
				case 7:
					ADS.I2MUX(IDAC2_OFF);
					BackToMainMenu();
					break;
				case 8:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;

			case 15: // подменю 15 IDAC1 routing
				switch (value)
				{
				case 1:
					ADS.I1MUX(IDAC1_OFF);
					BackToMainMenu();
					break;
				case 2:
					ADS.I1MUX(IDAC1_AIN0_REFP1);
					BackToMainMenu();
					break;
				case 3:
					ADS.I1MUX(IDAC1_AIN1);
					BackToMainMenu();
					break;
				case 4:
					ADS.I1MUX(IDAC1_AIN2);
					BackToMainMenu();
					break;
				case 5:
					ADS.I1MUX(IDAC1_AIN3_REFN1);
					BackToMainMenu();
					break;
				case 6:
					ADS.I1MUX(IDAC1_REFP0);
					BackToMainMenu();
					break;
				case 7:
					ADS.I1MUX(IDAC1_OFF);
					BackToMainMenu();
					break;
				case 8:
					set_settings_flag = false;
					BackToMainMenu();
					break;
				}
				break;
			}
			break;
		}
	}
}
void PosPointer() // передвижение  по меню указателя
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

void ConditionEncoder(byte limit) // обработка поворотов экнокдера
{
	// если в состояние 11 пришли не из 11
	// и 2 раза детектировалось движение
	// в одну и ту же сторону, то соответствующим
	// образом изменяем значение переменной

	if ((encA) && (encB) && (!prev11))
	{
		if ((clockwise1) && (clockwise2))
		{
			value++;
		}
		if ((!clockwise1) && (!clockwise2))
		{
			value--;
		}
		prev11 = true;
		if (value > limit)
		{
			value = limit;
		}
		if (value < 1)
		{
			value = 1;
		}
		Serial.println(value);
	}

	// детектирование направления первого перехода (от 11)

	else if ((!encA) && (encB) && (prev11))
	{
		clockwise1 = true;
		prev11 = false;
	}
	else if ((encA) && (!encB) && (prev11))
	{
		clockwise1 = false;
		prev11 = false;
	}

	// детектирование направления второго перехода (от 00)

	else if ((!encA) && (encB) && (!prev11))
	{
		clockwise2 = false;
	}
	else if ((encA) && (!encB) && (!prev11))
	{
		clockwise2 = true;
	}
}
