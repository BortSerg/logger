void BackInMenu()
{
	sub_menu_on = false;
	menu_on = true;
	pos_pointer = 16;
	value = 1;
	old_value += value;
	delay(200);
}

void SwitchClick(byte condition) // обработка нажатий на энкодер
{
	if (condition == LOW && menu_on == false && sub_menu_on == false) // обработка входа в меню
	{
		value = 1; // сброс позиции указателя вменю

		old_value += value; //имитация вращения энкодера

		menu_on = true;
		main_screen_on = false;

		delay(200);
		condition = !condition;
	}

	if (condition == LOW && menu_on == true && sub_menu_on == false) // обработка из меню для входа в подменю
	{
		pos_pointer = 16; // сброс позиции указателя

		number_sub_menu = value; // номер подменю = номеру пункта в основном меню
		value = 1;					 // сброс значений энкодера для отсчета с первого пункта
		old_value += value;		 //имитация вращения энкодера

		menu_on = false;
		sub_menu_on = true;

		delay(200);
		condition = !condition;
	}

	if (condition == LOW && menu_on == false && sub_menu_on == true) // обработка выбраного значения в подменю
	{
		condition = !condition;

		switch (number_sub_menu)
		{
		case 1: // подменю 1 PGA Bypass
			switch (value)
			{
			case 1:
			{
				ADS.PGA(PGA_BYPASS_OFF);
				BackInMenu();
			}
			break;
			case 2:
				ADS.PGA(PGA_BYPASS_ON);
				BackInMenu();
				break;
			case 3:
				BackInMenu();
				break;
			}
			break;

		case 2: // подменю 2 PGA gain
			switch (value)
			{
			case 1:
				ADS.Gain(GAIN_1);
				BackInMenu();
				break;
			case 2:
				ADS.Gain(GAIN_2);
				BackInMenu();
				break;
			case 3:
				ADS.Gain(GAIN_8);
				BackInMenu();
				break;
			case 4:
				ADS.Gain(GAIN_8);
				BackInMenu();
				break;
			case 5:
				ADS.Gain(GAIN_16);
				BackInMenu();
				break;
			case 6:
				ADS.Gain(GAIN_32);
				BackInMenu();
				break;
			case 7:
				ADS.Gain(GAIN_64);
				BackInMenu();
				break;
			case 8:
				ADS.Gain(GAIN_128);
				BackInMenu();
				break;
			case 9:
				BackInMenu();
				break;
			}
			break;

		case 3: // подменю 3 MUX Ch
			switch (value)
			{
			case 1:
				ADS.MuxChanel(MUX_AIN0_AIN1);
				BackInMenu();
				break;
			case 2:
				ADS.MuxChanel(MUX_AIN0_AIN2);
				BackInMenu();
				break;
			case 3:
				ADS.MuxChanel(MUX_AIN0_AIN3);
				BackInMenu();
				break;
			case 4:
				ADS.MuxChanel(MUX_AIN1_AIN2);
				BackInMenu();
				break;
			case 5:
				ADS.MuxChanel(MUX_AIN1_AIN3);
				BackInMenu();
				break;
			case 6:
				ADS.MuxChanel(MUX_AIN2_AIN3);
				BackInMenu();
				break;
			case 7:
				ADS.MuxChanel(MUX_AIN1_AIN0);
				BackInMenu();
				break;
			case 8:
				ADS.MuxChanel(MUX_AIN3_AIN2);
				BackInMenu();
				break;
			case 9:
				ADS.MuxChanel(MUX_AIN0_AVSS);
				BackInMenu();
				break;
			case 10:
				ADS.MuxChanel(MUX_AIN1_AVSS);
				BackInMenu();
				break;
			case 11:
				ADS.MuxChanel(MUX_AIN2_AVSS);
				BackInMenu();
				break;
			case 12:
				ADS.MuxChanel(MUX_AIN3_AVSS);
				BackInMenu();
				break;
			case 13:
				BackInMenu();
				break;
			}
			break;

		case 4: // подменю 4 BSC
			switch (value)
			{
			case 1:
				ADS.BCS(BCS_OFF);
				BackInMenu();
				break;
			case 2:
				ADS.BCS(BCS_ON);
				BackInMenu();
				break;
			case 3:
				BackInMenu();
				break;
			}
			break;

		case 5: // подменю 5 Conversion
			switch (value)
			{
			case 1:
				ADS.TemperatureSensor(TS_OFF);
				BackInMenu();
				break;
			case 2:
				ADS.TemperatureSensor(TS_ON);
				BackInMenu();
			case 3:
				BackInMenu();
				break;
			}
			break;

		case 6: // подменю 6 Operating
			switch (value)
			{
			case 1:
				ADS.ConversionMode(SINGLE_SHORT_MODE);
				BackInMenu();
				break;
			case 2:
				ADS.ConversionMode(CONTINUOUS_MODE);
				BackInMenu();
				break;
			case 3:
				BackInMenu();
				break;
			}
			break;

		case 7: // подменю 7 SPS
			switch (value)
			{
			case 1:
				ADS.OperatingMode(NORMAL_MODE);
				BackInMenu();
				break;

			case 2:
				ADS.OperatingMode(DUTY_CYCLE_MODE);
				BackInMenu();
				break;
			case 3:
				ADS.OperatingMode(TURBO_MODE);
				BackInMenu();
				break;
			case 4:
				BackInMenu();
				break;
			}
			break;

		case 8: // подменю 8 SPS
			switch (value)
			{
			case 1:
				ADS.DataRate(DR_20SPS);
				BackInMenu();
				break;
			case 2:
				ADS.DataRate(DR_45SPS);
				BackInMenu();
				break;
			case 3:
				ADS.DataRate(DR_90SPS);
				BackInMenu();
				break;
			case 4:
				ADS.DataRate(DR_175SPS);
				BackInMenu();
				break;
			case 5:
				ADS.DataRate(DR_330SPS);
				BackInMenu();
				break;
			case 6:
				ADS.DataRate(DR_600SPS);
				BackInMenu();
				break;
			case 7:
				ADS.DataRate(DR_1000SPS);
				BackInMenu();
				break;
			case 8:
				BackInMenu();
				break;
			}
			break;

		case 9: // подменю 9 IDAC current
			switch (value)
			{
			case 1:
				ADS.IDAC(IDAC_OFF);
				BackInMenu();
				break;
			case 2:
				ADS.IDAC(IDAC_10uA);
				BackInMenu();
				break;
			case 3:
				ADS.IDAC(IDAC_50uA);
				BackInMenu();
				break;
			case 4:
				ADS.IDAC(IDAC_100uA);
				BackInMenu();
				break;
			case 5:
				ADS.IDAC(IDAC_250uA);
				BackInMenu();
				break;
			case 6:
				ADS.IDAC(IDAC_500uA);
				BackInMenu();
				break;
			case 7:
				ADS.IDAC(IDAC_1000uA);
				BackInMenu();
				break;
			case 8:
				ADS.IDAC(IDAC_1500uA);
				BackInMenu();
				break;
			case 9:
				BackInMenu();
				break;
			}
			break;

		case 10: // подменю 10 PWS
			switch (value)
			{
			case 1:
				ADS.PSW(PSW_OPEN);
				BackInMenu();
				break;
			case 2:
				ADS.PSW(PSW_AUTO);
				BackInMenu();
				break;
			case 3:
				BackInMenu();
				break;
			}
			break;

		case 11: // подменю 11 FIR
			switch (value)
			{
			case 1:
				ADS.FIR(FIR_OFF);
				BackInMenu();
				break;
			case 2:
				ADS.FIR(FIR_50_60);
				BackInMenu();
				break;
			case 3:
				ADS.FIR(FIR_50);
				BackInMenu();
				break;
			case 4:
				ADS.FIR(FIR_60);
				BackInMenu();
				break;
			case 5:
				BackInMenu();
				break;
			}
			break;

		case 12: // подменю 12 VREF
			switch (value)
			{
			case 1:
				ADS.VREF(VREF_INTERNAL);
				BackInMenu();
				break;
			case 2:
				ADS.VREF(VREF_REFP0_REFN0);
				BackInMenu();
				break;
			case 3:
				ADS.VREF(VREF_AN0_AN3);
				BackInMenu();
				break;
			case 4:
				ADS.VREF(VREF_ANALOG);
				BackInMenu();
				break;
			case 5:
				BackInMenu();
				break;
			}
			break;

		case 13: // подменю 13 DRYM
			switch (value)
			{
			case 1:
				ADS.DRDYM(DRDYM_DRDY_ONLY);
				BackInMenu();
				break;
			case 2:
				ADS.DRDYM(DRDYM_DRDY_DOUT);
				BackInMenu();
				break;
			case 3:
				BackInMenu();
				break;
			}
			break;

		case 14: // подменю 14 IDAC2 routing
			switch (value)
			{
			case 1:
				ADS.I2MUX(IDAC2_OFF);
				BackInMenu();
				break;
			case 2:
				ADS.I2MUX(IDAC2_AIN0_REFP1);
				BackInMenu();
				break;
			case 3:
				ADS.I2MUX(IDAC2_AIN1);
				BackInMenu();
				break;
			case 4:
				ADS.I2MUX(IDAC2_AIN2);
				BackInMenu();
				break;
			case 5:
				ADS.I2MUX(IDAC2_AIN3_REFN1);
				BackInMenu();
				break;
			case 6:
				ADS.I2MUX(IDAC2_REFP0);
				BackInMenu();
				break;
			case 7:
				ADS.I2MUX(IDAC2_OFF);
				BackInMenu();
				break;
			case 8:
				BackInMenu();
				break;
			}
			break;

		case 15: // подменю 15 IDAC1 routing
			switch (value)
			{
			case 1:
				ADS.I1MUX(IDAC1_OFF);
				BackInMenu();
				break;
			case 2:
				ADS.I1MUX(IDAC1_AIN0_REFP1);
				BackInMenu();
				break;
			case 3:
				ADS.I1MUX(IDAC1_AIN1);
				BackInMenu();
				break;
			case 4:
				ADS.I1MUX(IDAC1_AIN2);
				BackInMenu();
				break;
			case 5:
				ADS.I1MUX(IDAC1_AIN3_REFN1);
				BackInMenu();
				break;
			case 6:
				ADS.I1MUX(IDAC1_REFP0);
				BackInMenu();
				break;
			case 7:
				ADS.I1MUX(IDAC1_OFF);
				BackInMenu();
				break;
			case 8:
				BackInMenu();
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
